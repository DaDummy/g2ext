/*////////////////////////////////////////////////////////////////////////////

This file is part of the G2Ext SDK examples.

//////////////////////////////////////////////////////////////////////////////

The G2Ext SDK headers are being published under the 
Mozilla Public License Version 1.1 (the "License"); 
you may not use this file except in compliance with the License.
You may obtain a copy of the License at http://www.mozilla.org/MPL/

Software distributed under the License is distributed on an "AS IS"
basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
License for the specific language governing rights and limitations
under the License.

G2Ext SDK examples © 2009 by Paindevs and Patrick Vogel

//////////////////////////////////////////////////////////////////////////////

The examples can be freely used as base or help for your own mod.

/////////////////////////////////////////////////////////////////////////////*/

#include "common/osheader.h" // OS header
#include "api/g2ext.h"		 // main G2Ext include

HRESULT G2EXT_API G2Ext_ModVersion(int& nMajor, int& nMinor, G2EXT_DLL_TYPE& tType) 
{ 
	nMajor = G2EXT_MAJOR_VERSION; 
	nMinor = G2EXT_MINOR_VERSION; 
	tType = G2EXT_DLL_MOD; 
	return S_OK; 
};

HRESULT G2EXT_API G2Ext_ModPrepare(ICoreOutgame* pCore) 
{
	MessageBox(NULL, L"G2Ext_ModPrepare", NULL, NULL);
	return S_OK;
};

HRESULT G2EXT_API G2Ext_ModInit(ICoreIngame* pCore) 
{
	MessageBox(NULL, L"G2Ext_ModInit", NULL, NULL);
	return S_OK;
};