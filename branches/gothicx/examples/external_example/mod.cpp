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
#include "api/g2/zcparser.h"
#include "mod.h"

zCParser* g_pParser;

int Mod_ExternalFunction() // func void test();
{
	MessageBox(0, L"Hello world!", 0, 0);
	return 0;
};

int Mod_ExternalFunction2() // func int test2(string);
{
	zSTRING zsParam1;

	g_pParser->GetParameter(zsParam1);

	MessageBoxA(0, zsParam1.ToChar(), 0, 0);
	
	g_pParser->SetReturn(42);

	return 0;
};

void __stdcall Mod_OnRegisterExternals(zCParser* pParser)
{
	g_pParser = pParser;
	pParser->DefineExternal(zSTRING("test"), Mod_ExternalFunction, zCPVOID, zCPVOID);
	pParser->DefineExternal(zSTRING("test2"), Mod_ExternalFunction2, zCPINT, zCPSTRING, zCPVOID);
};