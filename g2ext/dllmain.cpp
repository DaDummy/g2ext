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

#include "common/osheader.h"

#include "core.h"
#include "log.h"
#include "exceptionhandler.h"
#include "utils.h"

#define GOTHIC2_EXE L"Gothic2.exe"
#define GOTHIC2_EXE_CRC 0x2BCD7E30
#define SPACER2_EXE L"Spacer2.exe"
#define SPACER2_EXE_CRC 0xB1B45718

//////////////////////////////////////////////////////////////////////////

HRESULT __stdcall G2Ext_Init(PMODINFO pModInfo) // outgame -- exported per exports.def
{
	bool				bDebug = false;
	bool				bMoveBack = false;
	CCoreOutgame*		pCoreOutgame = NULL;
	std::wstring		wsCmdLine;
	std::wstring		wsModINI;

	if(pModInfo)
	{
#ifndef _G2EXT_COMPILE_SPACER
		if((pModInfo->dwFlags & G2EXT_PARAM_SPACER) == G2EXT_PARAM_SPACER)
		{
			MessageBox(NULL, L"G2EXT_PARAM_SPACER set!", L"G2Ext_Init", MB_ICONERROR | MB_OK);
			exit(0);
		};
#else
		if((pModInfo->dwFlags & G2EXT_PARAM_SPACER) != G2EXT_PARAM_SPACER)
		{
			MessageBox(NULL, L"G2EXT_PARAM_SPACER not set!", L"G2Ext_Init", MB_ICONERROR | MB_OK);
			exit(0);
		};
#endif

		if(std::wstring(pModInfo->lpwCMD).find(L"--xdebug", 0) != std::wstring::npos)
		{
			pModInfo->dwFlags |= G2EXT_PARAM_DEBUG;
			bDebug = true;
		};
	}
	else
	{
		MessageBox(NULL, L"pModInfo == NULL", L"G2Ext_Init", MB_ICONERROR | MB_OK);
		exit(0);
	};

	CLog::GetInstance()->Open(L"g2ext_outgame.log", bDebug);

	new CExceptionHandler();

	if((pModInfo->szSize != sizeof(MODINFO)) || pModInfo->lpwModIni == L"" || pModInfo->lpwDLL == L"")
	{
		G2EXT_LOG_CRITICAL(L"Bad MODINFO!");
		return E_FAIL;	
	};

	pCoreOutgame = new CCoreOutgame();
	
	if(FAILED(pCoreOutgame->Init(pModInfo)))
	{
		G2EXT_LOG_ERROR(L"Outgame core init failed!");
		return E_FAIL;
	};

#ifdef _G2EXT_COMPILE_SPACER
	// -- check Gothic2.exe
	if(!FileExists(SPACER2_EXE))
	{
		G2EXT_LOG_ERROR(L"Gothic2.exe not found!");
		return E_FAIL;
	};

	if(FileCRC32(SPACER2_EXE) != SPACER2_EXE_CRC)
	{
		G2EXT_LOG_ERROR(L"Verification failed! Please use Spacer II v2.6a (mdk update)!\nhttp://worldofgothic.de/dl/download_99.htm");
		return E_FAIL;
	};
#else //_G2EXT_COMPILE_SPACER
	// -- check Gothic2.exe
	if(!FileExists(GOTHIC2_EXE))
	{
		G2EXT_LOG_ERROR(L"Gothic2.exe not found!");
		return E_FAIL;
	};

	if(FileCRC32(GOTHIC2_EXE) != GOTHIC2_EXE_CRC)
	{
		G2EXT_LOG_ERROR(L"Verification failed! Please use Gothic II TNotR v2.6_fix (report version)!\nhttp://worldofgothic.de/dl/download_278.htm");
		return E_FAIL;
	};
#endif //_G2EXT_COMPILE_SPACER

	// -- run Gothic II
	wsModINI	= pModInfo->lpwModIni;

#ifdef _G2EXT_COMPILE_SPACER
	if(pModInfo->lpwCMD == NULL)
	{
		pModInfo->lpwCMD = L"Gothic2.exe";
	};
#else //_G2EXT_COMPILE_SPACER
	if(pModInfo->lpwCMD == NULL)
	{
		pModInfo->lpwCMD = L"Spacer2.exe";
	};
#endif //_G2EXT_COMPILE_SPACER

	if(wsModINI.find(L" ") == std::wstring::npos)
	{
		wsCmdLine = cwcs(pModInfo->lpwCMD, L" -game:", pModInfo->lpwModIni);
	}
	else
	{
		wsCmdLine = cwcs(pModInfo->lpwCMD, L"\" -game:", pModInfo->lpwModIni, L"\"");
	};

	pCoreOutgame->SetCmdLine(wsCmdLine.c_str());

	if(FileExists(cwcs(L"..\\", pModInfo->lpwDMP)))
	{
		WritePrivateProfileString(L"INTERNAL", L"gameAbnormalExit", L"0", L"Gothic.ini");
		WritePrivateProfileString(NULL, NULL, NULL, L"Gothic.ini");
	};

	DeleteFile(L"..\\VDFS.DMP");
	RenameFile(cwcs(L"..\\", pModInfo->lpwDMP), L"..\\VDFS.DMP");

	if (pModInfo->lpwVDF != NULL && wcslen(pModInfo->lpwVDF) != 0 && FileExists(cwcs(L"..\\Data\\modvdf\\", pModInfo->lpwVDF)))
	{
		G2EXT_LOG_DEBUG(cwcs(L"Moving ..\\Data\\modvdf\\", pModInfo->lpwVDF, L" to ..\\Data\\", pModInfo->lpwVDF, L"..."));

		if (!RenameFile(cwcs(L"..\\Data\\modvdf\\", pModInfo->lpwVDF), cwcs(L"..\\Data\\", pModInfo->lpwVDF)))
		{
			G2EXT_LOG_WARNING(L"Moving of vdf failed.");
		}
		else
		{
			G2EXT_LOG_DEBUG(L"done.");
			bMoveBack = true;
		};
	};

	HRESULT hResult = S_OK;
	if(FAILED(pCoreOutgame->Run()))
	{
		G2EXT_LOG_ERROR(L"CCoreOutgame::Run failed!");
		hResult = E_FAIL;
	};

	if (bMoveBack)
	{
		if (!FileExists(cwcs(L"..\\Data\\modvdf\\", pModInfo->lpwVDF)) && FileExists(cwcs(L"..\\Data\\", pModInfo->lpwVDF)))
		{
			G2EXT_LOG_DEBUG(cwcs(L"Moving ..\\Data\\", pModInfo->lpwVDF, L" back to ..\\Data\\modvdf\\", pModInfo->lpwVDF, L"..."));

			if (!RenameFile(cwcs(L"..\\Data\\", pModInfo->lpwVDF), cwcs(L"..\\Data\\modvdf\\", pModInfo->lpwVDF)))
			{
				G2EXT_LOG_WARNING(L"Moving back of vdf failed.");
			};
		};
	};

	if(GetPrivateProfileInt(L"INTERNAL", L"gameAbnormalExit", 1, L"Gothic.ini") == 0)
	{
		RenameFile(cwcs(L"..\\", pModInfo->lpwDMP), L"..\\VDFS.DMP");
	};

	return hResult;
};

//////////////////////////////////////////////////////////////////////////

HRESULT __stdcall G2Ext_Run(PMODINFO pModInfo) // ingame -- exported per exports.def
{
	bool bDebug = (bool)((G2EXT_PARAM_DEBUG & pModInfo->dwFlags) == G2EXT_PARAM_DEBUG);

	CLog::GetInstance()->Open(L"g2ext_ingame.log", bDebug);

	if((pModInfo->szSize != sizeof(MODINFO)) || pModInfo->lpwModIni == L"" || pModInfo->lpwDLL == L"")
	{
		G2EXT_LOG_CRITICAL(L"Bad MODINFO!");
		return E_FAIL;	
	};

	new CExceptionHandler();

	// -- check for "instant start" param
	if(std::wstring(pModInfo->lpwCMD).find(L"--xnomenu", 0) != std::wstring::npos)
	{
		pModInfo->dwFlags |= G2EXT_PARAM_NO_START_MENU;
		//G2EXT_LOG_DEBUG(L"FLAG: G2EXT_PARAM_NO_START_MENU");
	};

	// -- check for "vdfs check suppression" param
	if(std::wstring(pModInfo->lpwCMD).find(L"--xvdfs", 0) != std::wstring::npos)
	{
		pModInfo->dwFlags |= G2EXT_PARAM_NO_VDFS_CHECK;
		//G2EXT_LOG_DEBUG(L"FLAG: G2EXT_PARAM_NO_VDFS_CHECK");
	};

	// -- check for classic console param
	if(std::wstring(pModInfo->lpwCMD).find(L"--xg2con", 0) != std::wstring::npos)
	{
		pModInfo->dwFlags |= G2EXT_PARAM_NO_G2EXT_CONSOLE;
		//G2EXT_LOG_DEBUG(L"FLAG: G2EXT_PARAM_NO_G2EXT_CONSOLE");
	};

	// -- check for "no console" param
	if(std::wstring(pModInfo->lpwCMD).find(L"--xnoconsole", 0) != std::wstring::npos)
	{
		pModInfo->dwFlags |= G2EXT_PARAM_NO_CONSOLE;
		//G2EXT_LOG_DEBUG(L"FLAG: G2EXT_PARAM_NO_CONSOLE");
	};

	// -- check for "show fps" param
	if(std::wstring(pModInfo->lpwCMD).find(L"--xfps", 0) != std::wstring::npos)
	{
		pModInfo->dwFlags |= G2EXT_PARAM_SHOW_FPS;
		//G2EXT_LOG_DEBUG(L"FLAG: G2EXT_PARAM_SHOW_FPS");
	};

	CCoreIngame::GetInstance()->Init(pModInfo);

	return S_OK;
};

//////////////////////////////////////////////////////////////////////////