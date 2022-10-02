// Emacs style mode select -*- C++ -*-
//---------------------------------------------------------------------------
//
// $Id$
//
// Copyright(C) 1984-2000 David L. Clark
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
//---------------------------------------------------------------------------
//
//        swtitle  -      SW perform animation on the title screen
//
//---------------------------------------------------------------------------

#include <ctype.h>
#include <string.h>

#include "video.h"

#include "swasynio.h"
#include "swconf.h"
#include "swend.h"
#include "swground.h"
#include "swgrpha.h"
#include "swinit.h"
#include "swmain.h"
#include "swmenu.h"
#include "swtext.h"
#include "swsound.h"
#include "swsymbol.h"
#include "swtitle.h"

#define X_OFFSET ((SCR_WDTH/2)-160)

void swtitln(void)
{
	int i, h;

	sound(S_TITLE, 0, NULL);

	// clear the screen
	Vid_ClearBuf();

	swcolor(2);
	swposcur(18+X_OFFSET/8, 2);
	swputs("32X");

	swcolor(3);
	swposcur(13+X_OFFSET/8, 4);
	swputs("S O P W I T H");

	swposcur(13+X_OFFSET/8, 6);
	swputs("Version " PACKAGE_VERSION);

	swcolor(3);
	swposcur(0+X_OFFSET/8, 9);
	swputs("(c) 1984, 1985, 1987 ");

	swcolor(1);
	swputs("BMB ");
	swcolor(3);
	swputs("Compuscience");

	swcolor(3);
	swposcur(0+X_OFFSET/8, 10);
	swputs("(c) 1984-2000 David L. Clark");

	swcolor(3);
	swposcur(0+X_OFFSET/8, 11);
	swputs("(c) 2001-2022 Simon Howard, Jesse Smith");

	swcolor(3);
	swposcur(0+X_OFFSET/8, 12);
	swputs("    Distributed under the ");
	swcolor(1);
	swputs("GNU");
	swcolor(3);
	swputs(" GPL");

	swcolor(3);
	swposcur(0+X_OFFSET/8, 13);
	swputs("    32X Conversion by Cherish");

	initgrnd();
	displx = 507-X_OFFSET;
	swground();

	Vid_DispSymbol(40+X_OFFSET, 180, symbol_plane[0][0], 1);
	Vid_DispSymbol(130+X_OFFSET, 80, symbol_plane[1][7], 2);
	Vid_DispSymbol(23+X_OFFSET, ground[530] + 16, symbol_targets[3], 2);
	Vid_DispSymbol(213+X_OFFSET, ground[720] + 16, symbol_ox[0], 1);
	Vid_DispSymbol(270+X_OFFSET, 160, symbol_plane_hit[0], 2);

	for (i = 6, h=165; i; --i, h += 5) {
		Vid_PlotPixel(280+X_OFFSET, h, 3);
	}
}

void swtitlf(void)
{
	if (titleflg) {
		return;
	}

	sound(0, 0, NULL);
	swsound();
}


//
// menus
//

BOOL ctlbreak(void)
{
	return Vid_GetCtrlBreak();
}

// clear bottom of screen

void clrprmpt(void)
{
	int x, y;

	for (y = 0; y <= 43; ++y)
		for (x = 0; x < SCR_WDTH_HALF; ++x) {
			Vid_PlotDoublePixel(x, y, 0);
		}

	swposcur(0, 20);
}

static BOOL gethost(void)
{
	clrprmpt();

	swputs("Enter Remote Hostname/IP:\n");
	swgets(asynhost, sizeof(asynhost) - 3);

	return 1;
}

// network menu

static BOOL getnet(void)
{
	for (;;) {
		clrprmpt();
		swputs("Key: L - listen for connection\n");
		swputs("     C - connect to remote host\n");

		Vid_Update();

		swsndupdate();

		if (ctlbreak()) {
			swend(NULL, NO);
		}

		switch (toupper(swgetc() & 0xff)) {
		case 'L':
			asynmode = ASYN_LISTEN;
			return 1;
		case 'C':
			asynmode = ASYN_CONNECT;
			gethost();
			return 1;
		case 27:
			return 0;
		}
	}
}

// sdh: get single player skill level

static BOOL getskill(void)
{
	for (;;) {
		const char* menuitems[] = 
		{
			"novice player\n",
			"expert player\n",
		};
		int menuitemscount = sizeof(menuitems) / sizeof(menuitems[0]);
		
		int selection = displaymenu(5, 20, menuitems, menuitemscount);

		switch (selection) {
		case 0:
			playmode = PLAYMODE_NOVICE;
			return 1;
		case 1:
			playmode = PLAYMODE_SINGLE;
			return 1;
		case -1:
			return 0;
		}
	}
}

void getgamemode(void)
{
	for (;;) {

		unsigned char currentIndex = 0;
		const char* menuitems[] = 
		{
			"single player\n",
			"single player against computer\n",
			"game options\n",
		};
		int menuitemscount = sizeof(menuitems) / sizeof(menuitems[0]);
		
		int selection = displaymenu(5, 20, menuitems, menuitemscount);

		switch (selection) 
		{
		case 0:
			if (getskill()) {
				return;
			}
			break;
		case 1:
			playmode = PLAYMODE_COMPUTER;
			return;
		case 2:
			setconfig();
			break;
		}
	}
}


//---------------------------------------------------------------------------
//
// $Log$
// Revision 32X 1.0 2022/10/01 19:46:10  cherish
// converted menu screens for keyboard-less platforms
//
// Revision 1.10  2005/05/29 19:46:10  fraggle
// Fix up autotools build. Fix "make dist".
//
// Revision 1.9  2005/04/29 19:25:28  fraggle
// Update copyright to 2005
//
// Revision 1.8  2004/10/15 21:30:58  fraggle
// Improve multiplayer
//
// Revision 1.7  2004/10/15 18:06:16  fraggle
// Fix copyright notice
//
// Revision 1.6  2004/10/15 17:52:32  fraggle
// Clean up compiler warnings. Rename swmisc.c -> swtext.c as this more
// accurately describes what the file does.
//
// Revision 1.5  2004/03/29 23:58:23  fraggle
// Add a quit option to the main menu
//
// Revision 1.4  2003/06/08 03:41:42  fraggle
// Remove auxdisp buffer totally, and all associated functions
//
// Revision 1.3  2003/06/04 15:43:39  fraggle
// Fix year range in copyright
//
// Revision 1.2  2003/04/05 22:55:11  fraggle
// Remove the FOREVER macro and some unused stuff from std.h
//
// Revision 1.1.1.1  2003/02/14 19:03:22  fraggle
// Initial Sourceforge CVS import
//
//
// sdh 14/2/2003: change license header to GPL
// sdh 27/06/2002: move to new sopsym_t for symbols,
//                 remove references to symwdt, symhgt
// sdh 28/04/2002: Centering of title screen on non-320 pixel wide screens
// sdh 26/03/2002: change CGA_ to Vid_
// sdh 16/11/2001: TCPIP #define to disable TCP/IP support
// sdh 29/10/2001: moved options menu into swconf.c
// sdh 29/10/2001: harrykeys
// sdh 28/10/2001: rearranged title/menu stuff a bit
//                 added options menu
// sdh 21/10/2001: rearranged headers, added cvs tags
// sdh 19/10/2001: moved all the menus here
// sdh 19/10/2001: removed extern definitions, these are now in headers
// sdh 18/10/2001: converted all functions to ANSI-style arguments
// sdh ??/10/2001: added #define to control whether we use the classic
//                 title screen or the "network edition" one
//
// 2000-10-29      Copyright update.
// 99-01-24        1999 copyright.
// 96-12-27        New network version.
// 87-04-01        Version 7.F15
// 87-03-11        Title reformatting.
// 87-03-10        Microsoft compiler.
// 84-02-02        Development
//
//---------------------------------------------------------------------------

