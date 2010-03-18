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

#include "core.h"
#include "log.h"
#include "console.h"
#include "stats.h"
#include "splash.h"
#include "utils.h"

#include "api/g2/zcinput.h"
#include "api/g2/ocnpc.h"
#include "api/g2/zcparser.h"

#include "common/version.h"

#pragma warning(disable:4244)
#pragma warning(disable:4996)

CCoreIngame::CCoreIngame()
{
	// --
};

CCoreIngame::~CCoreIngame()
{
	this->Release();
};

void CCoreIngame::Init(PMODINFO pModInfo)
{
	this->m_pModInfo = pModInfo;
	this->m_pModHandle	= NULL;

	G2EXT_LOG_NONE(L"G2Ext :: ingame log");
	G2EXT_LOG_NONE(G2EXT_VERSIONW);
	G2EXT_LOG_DIVIDE();

	G2EXT_LOGF_DEBUG(L"CMD: %s", pModInfo->lpwCMD)

	this->m_pStatistics		= CStatistics::GetInstance();
	this->m_pConsole		= CConsole::GetInstance();
	this->m_pLog			= CLog::GetInstance();

	this->m_bInGame			= false;
	this->m_bInLoadScreen	= false;
	this->m_bInMenu			= true;
	this->m_bIsPaused		= true;
	this->m_bIsFirstRun		= true;

	this->m_bUseCustomSplashScreen = false;
	this->m_bSplashShowVersionInfo = true;

	CLog::GetInstance()->zERROR_Hijack();

	this->AttachCallbackHooks();

	this->LoadModDll(this->m_pModInfo->lpwDLL);

	G2EXT_LOG_DEBUG(L"Calling G2Ext_ModInit function.");

	this->ModInit(this);

	G2EXT_LOG_DEBUG(L"Mod initialized.");

	G2EXT_LOG_NONE(L"Searching plugins...");

	this->LoadPlugins(this->m_pModInfo->lpwPlugins);

	G2EXT_LOG_DEBUG(L"Initializing plugins.");

	for each(std::pair<LPCWSTR, PPLUGIN> p in this->m_hmPlugins)
	{
		G2EXT_LOGF_NONE(L"Initializing '%s'.", p.first);
		p.second->PluginInit(static_cast<ICoreIngame*>(this));
	};

	G2EXT_LOG_DEBUG(L"Plugins initialized.");
};

void CCoreIngame::Release(void)
{
	if(this->m_pModHandle)
	{
		FreeModule(this->m_pModHandle);
		this->m_pModHandle = NULL;
	};

	this->ModInit = NULL;
};

void CCoreIngame::LoadModDll(LPCWSTR lpwFileName)
{
	if(lpwFileName == L"")
	{
		G2EXT_LOG_CRITICAL(L"assertion failed: lpwFileName == 0");
	};
	
	G2EXT_LOGF_NONE(L"Loading mod: \"%s\"", lpwFileName);

	if((this->m_pModHandle = LoadLibrary(lpwFileName)) == NULL)
	{
		G2EXT_LOGF_CRITICAL(L"Unable to load mod: \"%s\"", lpwFileName);
	};

	if((this->ModInit = reinterpret_cast<G2EXT_MOD_INIT_FUNC>(GetProcAddress(this->m_pModHandle, "G2Ext_ModInit"))) == NULL)
	{
		G2EXT_LOG_CRITICAL(L"Init function not found.");
	};
};

void CCoreIngame::LoadPlugins(LPCWSTR lpwPlugins)
{
	if(lpwPlugins == NULL)
		return;

	wchar_t* wcTemp = new wchar_t[wcslen(lpwPlugins)+1];
	wcscpy_s(wcTemp, wcslen(lpwPlugins)+1, lpwPlugins);
	wcTemp = wcstok(wcTemp, L" ");

	int nPluginCount = 0;

	while(wcTemp != NULL)
	{
		nPluginCount++;

		PPLUGIN pPlugin = new PLUGIN();

		_wchdir(L"plugins");

		if(SUCCEEDED(pPlugin->Load(wcTemp)))
		{
			_wchdir(L"..");

			this->m_hmPlugins.insert(std::make_pair<LPCWSTR, PPLUGIN>(wcTemp, pPlugin));
			G2EXT_LOGF_INFO(L"Loaded plugin '%s'.", wcTemp);
		}
		else
		{
			_wchdir(L"..");

			G2EXT_DELETE(pPlugin);
			G2EXT_LOGF_WARNING(L"Could not load plugin '%s'. Ignoring plugin.", wcTemp);
		};

		wcTemp = wcstok(NULL, L" ");
	};

	if(nPluginCount == 0)
	{
		G2EXT_LOG_NONE(L"No plugins found.");
	};
};
void CCoreIngame::SetSplashScreen(HBITMAP hBitmap, bool bShowVersion)
{
	this->m_bUseCustomSplashScreen = true;
	this->m_bSplashShowVersionInfo = bShowVersion;
	this->m_hSplashBitmap = hBitmap;
};

//////////////////////////////////////////////////////////////////////////

void CCoreIngame::AttachCallbackHooks(void)
{
	G2EXT_LOG_NONE(L"Attaching callback hooks.");

	this->CreateHook(L"G2EXT_CALLBACK_PAUSE", (void*)0x006C8AD0, &CCoreIngame::OnPause);									// -- bound on oCGame::Pause(int) -- 0x006C8AD0
	this->CreateHook(L"G2EXT_CALLBACK_UNPAUSE", (void*)0x006C8D50, &CCoreIngame::OnUnPause);								// -- bound on oCGame::Unpause(void)-- 0x006C8D50
	this->CreateHook(L"G2EXT_CALLBACK_OPEN_LOADSCREEN", (void*)0x006C2690, &CCoreIngame::OnOpenLoadscreen);					// -- bound on oCGame::OpenLoadscreen(bool, class zSTRING) -- 0x006C2690
	this->CreateHook(L"G2EXT_CALLBACK_OPEN_SAVESCREEN", (void*)0x006C2250, &CCoreIngame::OnOpenSavescreen);					// -- bound on oCGame::OpenSavescreen(bool) -- 0x006C2250
	this->CreateHook(L"G2EXT_CALLBACK_CLOSE_LOADSCREEN", (void*)0x006C2BD0, &CCoreIngame::OnCloseLoadscreen);				// -- bound on oCGame::CloseLoadscreen(void) -- 0x006C2BD0
	this->CreateHook(L"G2EXT_CALLBACK_CLOSE_SAVESCREEN", (void*)0x006C2630, &CCoreIngame::OnCloseSavescreen);				// -- bound on oCGame::CloseSavescreen(void) -- 0x006C2630
	this->CreateHook(L"G2EXT_CALLBACK_ENTER_WORLD", (void*)0x006C96F0, &CCoreIngame::OnIngame);								// -- bound on oCGame::EnterWorld(class oCNpc *, int, class zSTRING const &) -- 0x006C96F0
	this->CreateHook(L"G2EXT_CALLBACK_RENDER", (void*)0x004816C0, &CCoreIngame::OnRender);									// -- bound on void __cdecl oCarsten_PerFrame() -- 0x004816C0
	this->CreateHook(L"G2EXT_CALLBACK_REGISTER_EXTERNALS", (void*)0x006D4780, &CCoreIngame::OnRegisterExternals);			// -- bound on oCGame::DefineExternals_Ulfi(class zCParser *) -- 0x006D4780
	//this->CreateHook(L"G2EXT_CALLBACK_REGISTER_MENU_EXTERNALS", (void*)0x0042C1D0, &CCoreIngame::OnRegisterMenuExternals);	// -- bound on DefineMenuScriptFunctions() -- 0x0042C1D0
	//this->CreateHook(L"G2EXT_CALLBACK_REGISTER_CLASSES", (void*)0x0075E4D0, &CCoreIngame::OnRegisterExternalClass);			// -- bound on oCNpc::InitStatics(void) -- 0x0075E4D0
	this->CreateHook(L"G2EXT_CALLBACK_INIT_HUD", (void*)0x006C1440, &CCoreIngame::OnInitHUD);								// -- bound on oCGame::Init(void) -- 0x006C1440
	this->CreateHook(L"G2EXT_CALLBACK_INPUT", (void*)0x006FC170, &CCoreIngame::OnInput, false, 1);							// -- bound on oCGame::HandleEvent(int) -- 0x006FC170
	this->CreateHook(L"G2EXT_CALLBACK_DONE", (void*)0x004254E0, &CCoreIngame::OnExit);										// -- bound on CGameManager::Done(void) -- 0x004254E0
	this->CreateHook(L"G2EXT_CALLBACK_LOAD_WORLD", (void*)0x006C90B0, &CCoreIngame::OnLoadWorld);							// -- bound on oCGame::LoadWorld(int, class zSTRING const &) -- 0x006C90B0

	this->CreateHook(L"G2EXT_CONSOLE_REGISTER", (void*)0x00782AE0, &CConsole::ConsoleRegister, false, 2);
	this->CreateHook(L"G2EXT_CONSOLE_REGISTER1", (void*)0x007829C0, &CConsole::ConsoleRegister1, false, 3);

	G2EXT_LOG_NONE(L"Attaching hacks.");

	if((G2EXT_PARAM_NO_G2EXT_CONSOLE & this->m_pModInfo->dwFlags) != G2EXT_PARAM_NO_G2EXT_CONSOLE)
	{
		this->EraseSecuredMem((void*)0x0047EC65, 5, 0x90);		// -- HACK: Suppress marvin mode
		this->EraseSecuredMem((void*)0x00895634, 1, '\n');		// -- HACK: Disable devmode
		this->EraseSecuredMem((void*)0x0047099F, 125, 0x90);	// ''
	};

	this->EraseSecuredMem((void*)0x008B28F4, 1, 0); // -- HACK: Erase pause text in menus
	this->ReplaceFunction(L"G2EXT_REPLACE_SPLASH", (void*)0x00426660, &SplashThreadProc); // -- HACK: Replace Splash Screen

	// -- HACK: Instant start (skip menu, but no exiting on key down ESC event)
	if((G2EXT_PARAM_NO_START_MENU & this->m_pModInfo->dwFlags) == G2EXT_PARAM_NO_START_MENU)
	{
		this->EraseSecuredMem((void*)0x00429471, 4, 0x90);
	};

	// -- HACK: Suppress VDFS consistency check
	if((G2EXT_PARAM_NO_VDFS_CHECK & this->m_pModInfo->dwFlags) == G2EXT_PARAM_NO_VDFS_CHECK)
	{
		this->EraseSecuredMem((void*)0x0047099F, 125, 0x90);
	};

	// -- Set new window caption
	*((char**)0x0089D9AC) = G2EXT_VERSIONA;

	G2EXT_LOG_NONE(L"Registering internal callbacks.");

	this->RegisterCallback(L"G2EXT_INT_ON_RENDER", &CCoreIngame::GothicOnRender, G2EXT_CB_ON_RENDER);
	this->RegisterCallback(L"G2EXT_INT_ON_DONE", &CCoreIngame::GothicOnDone, G2EXT_CB_ON_DONE);
	this->RegisterCallback(L"G2EXT_INT_ON_PAUSE", &CCoreIngame::GothicOnPause, G2EXT_CB_ON_PAUSE);
	this->RegisterCallback(L"G2EXT_INT_ON_UNPAUSE", &CCoreIngame::GothicOnUnPause, G2EXT_CB_ON_UNPAUSE);
	this->RegisterCallback(L"G2EXT_INT_ON_INGAME", &CCoreIngame::GothicOnIngame, G2EXT_CB_ON_INGAME);
	this->RegisterCallback(L"G2EXT_INT_ON_INPUT", &CCoreIngame::GothicOnInput, G2EXT_CB_ON_INPUT);
};	

//////////////////////////////////////////////////////////////////////////