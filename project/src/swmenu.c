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
//        swmenu  -      SW handle generic menus
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
#include "swtext.h"
#include "swsound.h"
#include "swsymbol.h"
#include "swtitle.h"

#include "32x.h"
#include "hw_32x.h"

void drawmenu(int x, int y, unsigned char currentmenuitemindex, const char** menuitems, unsigned char menuitemscount)
{
	int originalY = y;
	int i;
	for (i = 0; i < menuitemscount; i++)
	{
		swposcur(x, y++);
		swputs(menuitems[i]);
	}

	Vid_DispSymbol((8 * x) - 20, SCR_HGHT - (156 + (currentmenuitemindex * 8)), symbol_plane[0][0], 1);
}


int displaymenu(int x, int y, const char** menuitems, unsigned char menuitemscount)
{
	int currentindex = 0;
	int selectionmade = FALSE;
	while (!selectionmade)
	{
		swtitln();
		swsndupdate();

		clrprmpt();
		drawmenu(5, 20, currentindex, menuitems, menuitemscount);

		Vid_GetKey();

		Vid_Update();

		if (keysdown[KEY_UP] && currentindex)
		{
			currentindex--;
		}
		else if (keysdown[KEY_DOWN] && currentindex < menuitemscount - 1)
		{
			currentindex++;
		}
		else if (keysdown[KEY_ACCEPT])
		{
			selectionmade = TRUE;
		}
		else if (keysdown[KEY_BACK])
		{
			selectionmade = TRUE;
			currentindex = -1;
		}

		if (ctlbreak()) {
			swend(NULL, NO);
		}
	}

	return currentindex;
}



//---------------------------------------------------------------------------
//
// $Log$
// Revision ?.?  2022/10/01 19:25:28  pw
// Added menu system to make selections on keyboard-less platforms
//
//---------------------------------------------------------------------------
