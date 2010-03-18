/*////////////////////////////////////////////////////////////////////////

This file is part of the G2Ext source code.

//////////////////////////////////////////////////////////////////////////

G2Ext is a fan-made engine SDK for Gothic II TNotR (v2.6).
Copyright (C) 2009, 2010 by Paindevs and Patrick Vogel

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

////////////////////////////////////////////////////////////////////////*/

#ifndef __G2EXT_STARTER_DEFINED_H__
#define __G2EXT_STARTER_DEFINED_H__

#define ID_START		1000
#define ID_SPACER		1001	
#define ID_CLOSE		1002	
#define IDE_CMD			1003

#ifdef G2EXT_STARTER_DEV		
#define IDB_ZREPARSE	1004	
#define IDB_NOMENU		1005	
#define IDB_WINDOWED	1006
#define IDB_NOINJECTION	1007	
#define IDB_NOSOUND		1008	
#define IDB_NOMUSIC		1009	
#define IDB_CONVTEX		1010	
#define IDB_CONVDATA	1011	
#define IDB_CONVALL		1012	
#define IDB_VDFS		1013	
#define IDB_FPSLIMIT	1015
#define IDB_XDEBUG		1016
#define IDB_XG2CON		1017
#endif //G2EXT_STARTER_DEV

#define IDL_MODLIST		1018

#define IDG_GROUP		1800

#define ID_SETTINGS		2000
#define ID_VDFS			2001
#define ID_ZTEX			2002
#define ID_ABOUT		2003
#define ID_UPDATE		2004
#define ID_HELP			2005
#define ID_ZSPY			2006

#define IDT_TITLE		3000
#define IDT_WEB			3001
#define IDT_TEAM		3002
#define IDT_VERSION		3003

#define G2EXT_CAPTION L"G2Ext"
#define G2EXT_CAPTIONDEV L"G2Ext (dev)"

#define G2EXT_WINDOW_CLASS L"g2xst"

#endif  //__G2EXT_STARTER_DEFINED_H__