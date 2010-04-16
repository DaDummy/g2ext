/*////////////////////////////////////////////////////////////////////////////

This file is part of the G2Ext SDK examples.

//////////////////////////////////////////////////////////////////////////////

Copyright © 2009, 2010 by Paindevs and Patrick Vogel

All Rights reserved.

THE WORK (AS DEFINED BELOW) IS PROVIDED
UNDER THE TERMS OF THIS CREATIVE COMMONS
PUBLIC LICENSE ("CCPL" OR "LICENSE").
THE WORK IS PROTECTED BY COPYRIGHT AND/OR
OTHER APPLICABLE LAW. ANY USE OF THE WORK
OTHER THAN AS AUTHORIZED UNDER THIS LICENSE
OR COPYRIGHT LAW IS PROHIBITED.

BY EXERCISING ANY RIGHTS TO THE WORK PROVIDED
HERE, YOU ACCEPT AND AGREE TO BE BOUND BY THE
TERMS OF THIS LICENSE. TO THE EXTENT THIS
LICENSE MAY BE CONSIDERED TO BE A CONTRACT,
THE LICENSOR GRANTS YOU THE RIGHTS CONTAINED
HERE IN CONSIDERATION OF YOUR ACCEPTANCE OF
SUCH TERMS AND CONDITIONS.

Full license at http://creativecommons.org/licenses/by-nc/3.0/legalcode

//////////////////////////////////////////////////////////////////////////////

The examples can be freely used as base or help for your own mod.

/////////////////////////////////////////////////////////////////////////////*/

#include "api/g2ext.h" // main G2Ext include
#include "mod.h"

HRESULT G2EXT_API G2Ext_ModVersion(int& nMajor, int& nMinor, G2EXT_DLL_TYPE& tType) 
{ 
	nMajor = G2EXT_MAJOR_VERSION; 
	nMinor = G2EXT_MINOR_VERSION; 
	tType = G2EXT_DLL_MOD; 
	return S_OK; 
};

HRESULT G2EXT_API G2Ext_ModPrepare(ICoreOutgame* pCore) 
{
	return S_OK;
};

HRESULT G2EXT_API G2Ext_ModInit(ICoreIngame* pCore) 
{
	pCore->RegisterCallback(L"MOD_ON_REGISTER_EXTERNALS", &Mod_OnRegisterExternals, G2EXT_CB_ON_REGISTER_EXTERNALS);
	return S_OK;
};