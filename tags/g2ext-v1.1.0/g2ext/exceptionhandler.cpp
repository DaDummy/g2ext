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

#define  WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <eh.h>
#include "BugTrap.h"
#include "exceptionhandler.h"
#include "log.h"

CExceptionHandler::CExceptionHandler()
{
	BT_ReadVersionInfo(GetModuleHandle(NULL));
	BT_SetTerminate();
	BT_SetDialogMessage(BTDM_INTRO1, L"G2Ext has crashed and must be terminated.");
	BT_SetFlags(BTF_DETAILEDMODE | BTF_INTERCEPTSUEF | BTF_SHOWADVANCEDUI);
	BT_SetSupportURL(L"http://g2ext.paindevs.com/");
	BT_SetPreErrHandler((BT_ErrHandler)CExceptionHandler::Exception, NULL);
};

void CExceptionHandler::Exception(INT_PTR param)
{
	// If you see this message, Murphy's law just loved you :]
	G2EXT_LOG_WARNING(L"I never had a slice of bread,")
	G2EXT_LOG_WARNING(L"Particularly large and wide,")
	G2EXT_LOG_WARNING(L"That did not fall upon the floor,")
	G2EXT_LOG_WARNING(L"And always on the buttered side.")
};