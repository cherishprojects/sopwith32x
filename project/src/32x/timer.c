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
// Timer code
//
// Abstraction layer for access to the timer
// Basically this is to keep SDL out of the main code, so we can if we
// want drop in other code to run without SDL.
//
//--------------------------------------------------------------------------

#include "sw.h"
#include "32x.h"
#include "hw_32x.h"


unsigned	frt_ovf_count = 0;
float frt_counter2msec = 0;

const int NTSC_CLOCK_SPEED = 23011360; // HZ
const int PAL_CLOCK_SPEED  = 22801467; // HZ

int getFRTCounter(void)
{
	unsigned cnt = (SH2_FRT_FRCH << 8) | SH2_FRT_FRCL;
	return (int)((frt_ovf_count << 16) | cnt);
}

int FRTCounter2Msec(int c)
{
	return (int)((float)c * frt_counter2msec);
}

int Msec2FRTCounter(int c)
{
	return (int)((float)c / frt_counter2msec);
}


typedef unsigned short u16;

void initFRTCounter()
{
	u16 NTSC;
	NTSC = (MARS_VDP_DISPMODE & MARS_NTSC_FORMAT) != 0;

	/* init hires timer system */
	SH2_FRT_TCR = 2;									/* TCR set to count at SYSCLK/128 */
	SH2_FRT_FRCH = 0;
	SH2_FRT_FRCL = 0;
	SH2_INT_IPRB = (SH2_INT_IPRB & 0xF0FF) | 0x0E00; 	/* set FRT INT to priority 14 */
	SH2_INT_VCRD = 72 << 8; 							/* set exception vector for FRT overflow */
	SH2_FRT_FTCSR = 0;									/* clear any int status */
	SH2_FRT_TIER = 3;									/* enable overflow interrupt */

														// change 128.0f to something else if SH2_FRT_TCR is changed!
	frt_counter2msec = 128.0f * 1000.0f / (NTSC ? NTSC_CLOCK_SPEED : PAL_CLOCK_SPEED);
}



// get time in milliseconds

int Timer_GetMS(void)
{
	return FRTCounter2Msec(getFRTCounter());
}

void Timer_Sleep(int usec)
{
	int start = Timer_GetMS();
	int now = start;

	while (now < start + usec)
	{
		now = Timer_GetMS();
	}
}

void Timer_Init(void)
{
	initFRTCounter();
}

//--------------------------------------------------------------------------
//
// $Log$
// Revision 1.2  2005/04/29 19:25:29  fraggle
// Update copyright to 2005
//
// Revision 1.1.1.1  2003/02/14 19:03:37  fraggle
// Initial Sourceforge CVS import
//
//
// sdh 14/2/2003: change license header to GPL
// sdh 21/10/2001: added cvs tags
//
//--------------------------------------------------------------------------
