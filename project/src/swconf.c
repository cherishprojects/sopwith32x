// Emacs style mode select -*- C++ -*-
//--------------------------------------------------------------------------
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
//--------------------------------------------------------------------------
//
// Configuration code
//
// Save game settings to a configuration file
//
//-------------------------------------------------------------------------

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "timer.h"
#include "pcsound.h"
#include "video.h"

#include "swconf.h"
#include "swend.h"
#include "swsound.h"
#include "swtext.h"
#include "swtitle.h"
#include "swmain.h"

static confoption_t confoptions[] = {
	{"conf_missiles",       CONF_BOOL, {&conf_missiles}},
	{"conf_solidground",    CONF_BOOL, {&conf_solidground}},
	{"conf_hudsplats",      CONF_BOOL, {&conf_hudsplats}},
	{"conf_wounded",        CONF_BOOL, {&conf_wounded}},
	{"conf_animals",        CONF_BOOL, {&conf_animals}},
	{"conf_harrykeys",      CONF_BOOL, {&conf_harrykeys}},
	{"conf_big_explosions", CONF_BOOL, {&conf_big_explosions}},
	{"conf_medals",         CONF_BOOL, {&conf_medals}},
	{"snd_tinnyfilter",     CONF_BOOL, {&snd_tinnyfilter}},
};

int num_confoptions = sizeof(confoptions) / sizeof(*confoptions);

static confoption_t *confoption_by_name(char *name)
{
	int i;

	for (i=0; i<num_confoptions; ++i) {
		if (!strcasecmp(name, confoptions[i].name)) {
			return &confoptions[i];
		}
	}

	return NULL;
}


struct menuitem {
	char *config_name;
	char *description;
};

static void drawmenu(char *title, struct menuitem *menu, int menuitemscount, int currentmenuitemindex)
{
	int i, y = 0;
	Vid_ClearBuf();

	swcolor(2);
	swposcur(19 - strlen(title) / 2, 2);
	swputs(title);

	swcolor(3);

	for (i=0, y=0; i < menuitemscount; ++i, ++y) {
		confoption_t *opt;
		char buf[40];

		if (strlen(menu[i].config_name) == 0) {
			continue;
		}

		if (strcasecmp(menu[i].config_name, "exit") == 0)
			swcolor(1);

		snprintf(buf, sizeof(buf), "%s",
		         menu[i].description);

		swposcur(5, 5+y);
		swputs(buf);
		swcolor(3);

		swposcur(30, 5+y);
		opt = confoption_by_name(menu[i].config_name);
		if (opt == NULL) {
			continue;
		}

		switch (opt->type) {
		case CONF_BOOL:
			swputs(*opt->value.b ? "on" : "off");
			break;
		default:
			break;
		}
	}

	Vid_DispSymbol(16, SCR_HGHT - (34 + (currentmenuitemindex * 8)), symbol_plane[0][0], 1);
}

// Present the given menu to the user. Returns zero if escape was pushed
// to exit the menu, or if a >jump item was chosen, it returns the key
// binding associated with it.
static int runmenu(char *title, struct menuitem *menu, int menuitemscount)
{
	confoption_t *opt;

	int currentmenuitemindex = 0;
	int done = FALSE;

	while (!done) {
		drawmenu(title, menu, menuitemscount, currentmenuitemindex);

		Vid_GetKey();

		Vid_Update();

		if (keysdown[KEY_UP] && currentmenuitemindex)
		{
			do
			{
				currentmenuitemindex--;
			} while (menu[currentmenuitemindex].config_name == NULL);
		}
		else if (keysdown[KEY_DOWN] && currentmenuitemindex < menuitemscount - 1)
		{
			do 
			{
				currentmenuitemindex++;
			} while (menu[currentmenuitemindex].config_name == NULL);
		}
		else if (keysdown[KEY_ACCEPT])
		{
			if (strcasecmp(menu[currentmenuitemindex].config_name, "exit") == 0)
			{
				done = TRUE;
			}
			else
			{
				opt = confoption_by_name(menu[currentmenuitemindex].config_name);
				if (opt != NULL) {
					switch (opt->type) {
					case CONF_BOOL:
						*opt->value.b = !*opt->value.b;
						break;
					default:
						break;
					}

				}

			}
		}
		else if (keysdown[KEY_BACK])
		{
			done = TRUE;
			currentmenuitemindex = -1;
		}
	}

	return currentmenuitemindex;
}

struct menuitem options_menu[] = {
	{"conf_missiles",		"Missles"},
	{"conf_solidground",    "Solid ground"},
	{"conf_hudsplats",      "HUD splats"},
	{"conf_wounded",        "Wounded planes"},
	{"conf_animals",        "Oxen and birds"},
	{"conf_big_explosions", "Big oil tank explosions"},
	{"conf_medals",         "Medals"},
	{"conf_harrykeys",      "Harry keys mode"},
	{NULL},
	{"exit",				"Exit"},
};

int options_menu_count = sizeof(options_menu) / sizeof(options_menu[0]);

void setconfig(void)
{
	runmenu("OPTIONS", options_menu, options_menu_count);
}

//-------------------------------------------------------------------------
//
// $Log$
// Revision 1.9  2005/05/29 19:46:10  fraggle
// Fix up autotools build. Fix "make dist".
//
// Revision 1.8  2005/04/29 19:25:28  fraggle
// Update copyright to 2005
//
// Revision 1.7  2005/04/29 19:00:48  fraggle
// Capitalise first letter of config descriptions
//
// Revision 1.6  2005/04/29 10:10:12  fraggle
// "Medals" feature
// By Christoph Reichenbach <creichen@gmail.com>
//
// Revision 1.5  2004/10/15 17:52:31  fraggle
// Clean up compiler warnings. Rename swmisc.c -> swtext.c as this more
// accurately describes what the file does.
//
// Revision 1.4  2003/06/08 03:41:41  fraggle
// Remove auxdisp buffer totally, and all associated functions
//
// Revision 1.3  2003/06/04 17:22:11  fraggle
// Remove "save settings" option in settings menus. Just save it anyway.
//
// Revision 1.2  2003/04/05 22:55:11  fraggle
// Remove the FOREVER macro and some unused stuff from std.h
//
// Revision 1.1.1.1  2003/02/14 19:03:10  fraggle
// Initial Sourceforge CVS import
//
//
// sdh 14/2/2003: change license header to GPL
// sdh 26/03/2002: change CGA_ to Vid_
// sdh 10/11/2001: make confoptions globally available for gtk code to use
//
//-------------------------------------------------------------------------


