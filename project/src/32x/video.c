// Emacs style mode select -*- C++ -*-
//--------------------------------------------------------------------------
//
// $Id$
//
// Copyright(C) 2001-2005 Simon Howard
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2 of the License, or (at your
// option) any later version. This program is distributed in the hope that
// it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See
// the GNU General Public License for more details. You should have
// received a copy of the GNU General Public License along with this
// program; if not, write to the Free Software Foundation, Inc., 59 Temple
// Place - Suite 330, Boston, MA 02111-1307, USA.
//
//--------------------------------------------------------------------------
//
// 32X Video Code
//
// By Simon Howard
// Conversion by Cherish
//
//-----------------------------------------------------------------------

#include "video.h"
#include "sw.h"
#include "32x.h"
#include "hw_32x.h"

extern unsigned char *vid_vram;
extern unsigned int vid_pitch;


static BOOL initted = 0;

void clearScreen_Fill8bit()
{
	MARS_VDP_FILLEN = 255;

	for (int loop = 0; loop < 140; loop++)
	{
		MARS_VDP_FILADR = MARS_FRAMEBUFFER + (loop << 8);
		MARS_VDP_FILDAT = 0;
		while (MARS_VDP_FBCTL & MARS_VDP_FEN);
	}
}

// 2x scale

void Vid_Update(void)
{
	if (!initted) 
	{
		Vid_Init();
	}
	
	Hw32xScreenFlip(1);
}


static void Vid_UnsetMode(void)
{
}

typedef unsigned short int uint16;
typedef unsigned short int u16;
typedef volatile unsigned short int vu16;

void init_linetable_8bit() 
{
	int i;
	vu16* frameBuffer16 = &MARS_FRAMEBUFFER;

	uint16 lineOffs = 0x100;

	// Set up the line table
	for (i = 0; i < 256; i++)
	{
		frameBuffer16[i] = lineOffs;
		lineOffs += 160;
	}
}


void init_linetables_8bit()
{
	init_linetable_8bit();
	Hw32xScreenFlip(1);
	init_linetable_8bit();
}

void mars_init_8bit(void)
{
	//using 256 color mode using palette
	Hw32xInit(MARS_VDP_MODE_256, 0);
	init_linetables_8bit();

	Hw32xSetPaletteColor(0, 0, 0, 0);
	Hw32xSetPaletteColor(1, 0, 255, 255);
	Hw32xSetPaletteColor(2, 255, 0, 255);
	Hw32xSetPaletteColor(3, 255, 255, 255);

	Hw32xSetBGColor8bit(0);
	Hw32xSetFGColor8bit(3);
}


static void Vid_SetMode(void)
{
	mars_init_8bit();

	int n;
	for (n = 0; n < NUM_KEYS; ++n) {
		keysdown[n] = 0;
	}
}

void Vid_Shutdown(void)
{
	if (!initted) {
		return;
	}
	
	Vid_UnsetMode();
	
	initted = 0;
}



void Vid_Init(void)
{
	if (initted) {
		return;
	}
	
	Vid_SetMode();
	
	vid_vram = (unsigned char*)&MARS_FRAMEBUFFER_VIDEO;//screenbuf->pixels;
	vid_pitch = 320;//screenbuf->pitch;

	initted = 1;

}

void Vid_Reset(void)
{
	if (!initted) {
		return;
	}

	Vid_UnsetMode();
	Vid_SetMode();
	Vid_Update();
}

u16 currentButtonState = 0;

static int getevents(void)
{
	int changed = FALSE;

	u16 buttonState = MARS_SYS_COMM8 & 0x0FFF;

	
	keysstate[KEY_PULLUP] = (buttonState & SEGA_CTRL_LEFT);
	keysstate[KEY_PULLDOWN] = (buttonState & SEGA_CTRL_RIGHT);
	//keysstate[KEY_FLIP] = (buttonState & SEGA_CTRL_LEFT);
	keysstate[KEY_BOMB] = (buttonState & SEGA_CTRL_B);
	keysstate[KEY_FIRE] = (buttonState & SEGA_CTRL_A);
	//keysstate[KEY_HOME] = (buttonState & SEGA_CTRL_B);
	keysstate[KEY_MISSILE] = (buttonState & SEGA_CTRL_C);
	//keysstate[KEY_STARBURST] = (buttonState & SEGA_CTRL_X);	
	keysstate[KEY_ACCEL] = (buttonState & SEGA_CTRL_UP);	
	keysstate[KEY_DECEL] = (buttonState & SEGA_CTRL_DOWN);	
	//keysstate[KEY_SOUND] = (buttonState & SEGA_CTRL_START);	
	keysstate[KEY_UP] = (buttonState & SEGA_CTRL_UP);
	keysstate[KEY_DOWN] = (buttonState & SEGA_CTRL_DOWN);
	keysstate[KEY_LEFT] = (buttonState & SEGA_CTRL_LEFT);
	keysstate[KEY_RIGHT] = (buttonState & SEGA_CTRL_RIGHT);
	keysstate[KEY_ACCEPT] = (buttonState & SEGA_CTRL_A);
	keysstate[KEY_BACK] = (buttonState & SEGA_CTRL_B);



	keysdown[KEY_PULLUP] = keysstate[KEY_PULLUP] && !(currentButtonState & SEGA_CTRL_LEFT);
	keysdown[KEY_PULLDOWN] = keysstate[KEY_PULLDOWN] && !(currentButtonState & SEGA_CTRL_RIGHT);
	//keysdown[KEY_FLIP] = keysstate[KEY_FLIP] && !(currentButtonState & SEGA_CTRL_LEFT);
	keysdown[KEY_BOMB] = keysstate[KEY_BOMB] && !(currentButtonState & SEGA_CTRL_B);
	keysdown[KEY_FIRE] = keysstate[KEY_FIRE] && !(currentButtonState & SEGA_CTRL_A);
	//keysdown[KEY_HOME] = keysstate[KEY_HOME] && !(currentButtonState & SEGA_CTRL_B);
	keysdown[KEY_MISSILE] = keysstate[KEY_MISSILE] && !(currentButtonState & SEGA_CTRL_C);
	//keysdown[KEY_STARBURST] = keysstate[KEY_STARBURST] && !(currentButtonState & SEGA_CTRL_X);	
	keysdown[KEY_ACCEL] = keysstate[KEY_ACCEL] && !(currentButtonState & SEGA_CTRL_UP);	
	keysdown[KEY_DECEL] = keysstate[KEY_DECEL] && !(currentButtonState & SEGA_CTRL_DOWN);	
	//keysdown[KEY_SOUND] = keysstate[KEY_SOUND] && !(currentButtonState & SEGA_CTRL_START);	

	keysdown[KEY_UP] = keysstate[KEY_UP] && !(currentButtonState & SEGA_CTRL_UP);
	keysdown[KEY_DOWN] = keysstate[KEY_DOWN] && !(currentButtonState & SEGA_CTRL_DOWN);
	keysdown[KEY_LEFT] = keysstate[KEY_LEFT] && !(currentButtonState & SEGA_CTRL_LEFT);
	keysdown[KEY_RIGHT] = keysstate[KEY_RIGHT] && !(currentButtonState & SEGA_CTRL_RIGHT);

	keysdown[KEY_ACCEPT] = keysstate[KEY_ACCEPT] && !(currentButtonState & SEGA_CTRL_A);
	keysdown[KEY_BACK] = keysstate[KEY_BACK] && !(currentButtonState & SEGA_CTRL_B);

	changed = currentButtonState != buttonState;

	currentButtonState = buttonState;

	return changed;	
}

void Vid_StartTextInput(void)
{
}

void Vid_StopTextInput(void)
{
}

int Vid_GetKey(void)
{
	return getevents();
}

int Vid_GetChar(void)
{
	return 0;
}

BOOL Vid_GetCtrlBreak(void)
{
	return FALSE;
}

const char *Vid_KeyName(int key)
{
	(void)key;
	return NULL;
}

//-----------------------------------------------------------------------
//
// $Log$
// Revision 1.8  2005/06/01 10:17:26  fraggle
// Don't #include files with drawing functions.
// Include README files for psion and gtk ports.
// Remove unnecessary include parameter.
//
// Revision 1.7  2005/04/29 19:25:29  fraggle
// Update copyright to 2005
//
// Revision 1.6  2005/04/28 14:52:55  fraggle
// Fix compilation under gcc 4.0
//
// Revision 1.5  2004/10/15 17:30:58  fraggle
// Always hide the cursor.
//
// Revision 1.4  2004/10/14 08:48:46  fraggle
// Wrap the main function in system-specific code.  Remove g_argc/g_argv.
// Fix crash when unable to initialise video subsystem.
//
// Revision 1.3  2003/03/26 13:53:29  fraggle
// Allow control via arrow keys
// Some code restructuring, system-independent video.c added
//
// Revision 1.2  2003/03/26 12:02:38  fraggle
// Apply patch from David B. Harris (ElectricElf) for right ctrl key and
// documentation
//
// Revision 1.1.1.1  2003/02/14 19:03:37  fraggle
// Initial Sourceforge CVS import
//
//
// sdh 14/2/2003: change license header to GPL
// sdh 25/04/2002: rename vga_{pitch,vram} to vid_{pitch,vram}
// sdh 26/03/2002: now using platform specific vga code for drawing stuff
//                 (#include "vid_vga.c")
//                 rename CGA_ to Vid_
// sdh 17/11/2001: buffered input for keypresses,
//                 CGA_GetLastKey->CGA_GetKey
// sdh 07/11/2001: add CGA_Reset
// sdh 21/10/2001: added cvs tags
//
//-----------------------------------------------------------------------
