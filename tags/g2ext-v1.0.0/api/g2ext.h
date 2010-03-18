/*////////////////////////////////////////////////////////////////////////////

This file is part of the G2Ext SDK headers.

//////////////////////////////////////////////////////////////////////////////

The G2Ext SDK headers

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

/////////////////////////////////////////////////////////////////////////////*/

#ifndef __API_G2EXT_H__
#define __API_G2EXT_H__

#include "common/osheader.h"
#include "common/version.h"

#include "api/log.h"
#include "api/core.h"
#include "api/stats.h"

#define G2EXT_DECLARE_MOD __declspec(dllexport) HRESULT G2EXT_API G2Ext_ModVersion(int& nMajor, int& nMinor, G2EXT_DLL_TYPE& tType) { nMajor = G2EXT_MAJOR_VERSION; nMinor = G2EXT_MINOR_VERSION; tType = G2EXT_DLL_MOD; return S_OK; };
//#define G2EXT_DECLARE_PLUGIN __declspec(dllexport) HRESULT G2EXT_API G2Ext_ModVersion(int& nMajor, int& nMinor, G2EXT_DLL_TYPE& tType) { nMajor = G2EXT_MAJOR_VERSION; nMinor = G2EXT_MINOR_VERSION; tType = G2EXT_DLL_PLUGIN; return S_OK; };
//#define G2EXT_DECLARE_SPACER_PLUGIN __declspec(dllexport) HRESULT G2EXT_API G2Ext_ModVersion(int& nMajor, int& nMinor, G2EXT_DLL_TYPE& tType) { nMajor = G2EXT_MAJOR_VERSION; nMinor = G2EXT_MINOR_VERSION; tType = G2EXT_DLL_SPACER; return S_OK; };

#endif  //__API_G2EXT_H__