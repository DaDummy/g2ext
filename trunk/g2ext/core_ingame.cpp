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
#include "limits.h"

#ifdef _G2EXT_COMPILE_SPACER
#include "api/spacer/zcinput.h"
#include "api/spacer/zcparser.h"
#include "api/spacer/zcworld.h"
#include "api/spacer/ocgame.h"
#include "api/spacer/ocitem.h"
#include "api/spacer/ocnpc.h"
#else //_G2EXT_COMPILE_SPACER
#include "api/g2/zcinput.h"
#include "api/g2/zcparser.h"
#include "api/g2/zcworld.h"
#include "api/g2/ocgame.h"
#include "api/g2/ocitem.h"
#include "api/g2/ocnpc.h"
#endif //_G2EXT_COMPILE_SPACER

#include "common/version.h"

#define GDHM_EMPTY_KEY L"(NULL-XYZABC)"

#pragma warning(disable:4244)
#pragma warning(disable:4996)

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

#ifndef _G2EXT_COMPILE_SPACER
	this->m_pStatistics		= CStatistics::GetInstance();
	this->m_pConsole		= CConsole::GetInstance();
#endif
	this->m_pLog			= CLog::GetInstance();

	this->m_bInGame			= false;
	this->m_bInLoadScreen	= false;
	this->m_bInMenu			= true;
	this->m_bIsPaused		= true;
	this->m_bIsFirstRun		= true;

	this->m_bUseCustomSplashScreen = false;
	this->m_bSplashShowVersionInfo = true;

	
	// Prepare all google::dense_hash_map instances
	for(UINT i = 0; i < G2EXT_CB_MAX; i++)
	{
		this->m_hmCallbacks[i].set_empty_key(GDHM_EMPTY_KEY);
	}

	this->m_hmHooks.set_empty_key(GDHM_EMPTY_KEY);
	this->m_hmPlugins.set_empty_key(GDHM_EMPTY_KEY);

#ifndef _G2EXT_COMPILE_SPACER
	if(this->IsFlagSet(G2EXT_PARAM_DEBUG))
	{
		//CLog::GetInstance()->zERROR_Hijack();
	};
#endif

	this->AttachCallbackHooks();

#ifdef _G2EXT_COMPILE_SPACER
	this->SetWindowCaption("Spacer (G2Ext)");
	this->LoadModDll(this->m_pModInfo->lpwSpacerDLL);
#else
	this->SetWindowCaption(G2EXT_VERSIONA);
	this->LoadModDll(this->m_pModInfo->lpwDLL);
#endif

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
	this->DisableAllCallbacks();

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
		G2EXT_LOG_CRITICAL(L"assertion failed: lpwFileName == \"\"");
	};
	
	G2EXT_LOGF_NONE(L"Loading mod: \"%s\"", lpwFileName);

	if((this->m_pModHandle = LoadLibraryA(wcstostr(lpwFileName))) == NULL) // LoadLibraryW causes problems - researching
	{
		G2EXT_LOGF_CRITICAL(L"Unable to load mod: \"%s\" [error:%d]", lpwFileName, GetLastError());
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

void CCoreIngame::SetWindowCaption(LPCSTR lpcCaption)
{
#ifdef _G2EXT_COMPILE_SPACER
	*((char**)0x00986A3C) = (char*)lpcCaption;
#else //_G2EXT_COMPILE_SPACER
	*((char**)0x0089D9AC) = (char*)lpcCaption;
#endif //_G2EXT_COMPILE_SPACER
};

//////////////////////////////////////////////////////////////////////////

void CCoreIngame::AttachCallbackHooks(void)
{
	G2EXT_LOG_NONE(L"Attaching callback hooks.");

#ifdef _G2EXT_COMPILE_SPACER
	//this->CreateHook(L"G2EXT_CALLBACK_PAUSE", (void*)0x00533280, &CCoreIngame::OnPause);									// -- bound on oCGame::Pause(int) -- 0x00533280
	//this->CreateHook(L"G2EXT_CALLBACK_UNPAUSE", (void*)0x00533500, &CCoreIngame::OnUnPause);								// -- bound on oCGame::Unpause(void)-- 0x00533500
	//this->CreateHook(L"G2EXT_CALLBACK_OPEN_LOADSCREEN", (void*)0x0052D300, &CCoreIngame::OnOpenLoadscreen);					// -- bound on oCGame::OpenLoadscreen(bool, class zSTRING) -- 0x0052D300
	//this->CreateHook(L"G2EXT_CALLBACK_OPEN_SAVESCREEN", (void*)0x0052D2C0, &CCoreIngame::OnOpenSavescreen);					// -- bound on oCGame::OpenSavescreen(bool) -- 0x0052D2C0
	//libinject error //this->CreateHook(L"G2EXT_CALLBACK_CLOSE_LOADSCREEN", (void*)0x0052D350, &CCoreIngame::OnCloseLoadscreen);				// -- bound on oCGame::CloseLoadscreen(void) -- 0x0052D350
	//libinject error this->CreateHook(L"G2EXT_CALLBACK_CLOSE_SAVESCREEN", (void*)0x0052D2F0, &CCoreIngame::OnCloseSavescreen);				// -- bound on oCGame::CloseSavescreen(void) -- 0x0052D2F0
	//this->CreateHook(L"G2EXT_CALLBACK_ENTER_WORLD", (void*)0x00533E10, &CCoreIngame::OnIngame);								// -- bound on oCGame::EnterWorld(class oCNpc *, int, class zSTRING const &) -- 0x00533E10
	//this->CreateHook(L"G2EXT_CALLBACK_RENDER", (void*)0x004B0850, &CCoreIngame::OnRender);									// -- bound on void __cdecl oCarsten_PerFrame() -- 0x004B0850
	//this->CreateHook(L"G2EXT_CALLBACK_REGISTER_EXTERNALS", (void*)0x0053F110, &CCoreIngame::OnRegisterExternals);			// -- bound on oCGame::DefineExternals_Ulfi(class zCParser *) -- 0x0053F110
	//this->CreateHook(L"G2EXT_CALLBACK_REGISTER_MENU_EXTERNALS", (void*)0x0042C1D0, &CCoreIngame::OnRegisterMenuExternals);	// -- bound on DefineMenuScriptFunctions() -- 0x0042C1D0
	//this->CreateHook(L"G2EXT_CALLBACK_REGISTER_CLASSES", (void*)0x0075E4D0, &CCoreIngame::OnRegisterExternalClass);			// -- bound on oCNpc::InitStatics(void) -- 0x0075E4D0
	//this->CreateHook(L"G2EXT_CALLBACK_INIT_HUD", (void*)0x0052C0D0, &CCoreIngame::OnInitHUD);								// -- bound on oCGame::Init(void) -- 0x0052C0D0
	//this->CreateHook(L"G2EXT_CALLBACK_INPUT", (void*)0x00555D90, &CCoreIngame::OnInput, false, 1);							// -- bound on oCGame::HandleEvent(int) -- 0x00555D90
	//this->CreateHook(L"G2EXT_CALLBACK_DONE", (void*)0x00489740, &CCoreIngame::OnExit);										// -- bound on CGameManager::Done(void) -- 0x00489740
	//this->CreateHook(L"G2EXT_CALLBACK_LOAD_WORLD", (void*)0x00533860, &CCoreIngame::OnLoadWorld);							// -- bound on oCGame::LoadWorld(int, class zSTRING const &) -- 0x00533860

	//this->CreateHook(L"G2EXT_CONSOLE_REGISTER", (void*)0x007EF410, &CConsole::ConsoleRegister, false, 2);
	//this->CreateHook(L"G2EXT_CONSOLE_REGISTER1", (void*)0x007EF2F0, &CConsole::ConsoleRegister1, false, 3);
#else // _G2EXT_COMPILE_SPACER
	this->CreateHook(L"G2EXT_CALLBACK_PAUSE", (void*)0x006C8AD0, &CCoreIngame::OnPause);									// -- bound on oCGame::Pause(int) -- 0x006C8AD0
	this->CreateHook(L"G2EXT_CALLBACK_UNPAUSE", (void*)0x006C8D50, &CCoreIngame::OnUnPause);								// -- bound on oCGame::Unpause(void)-- 0x006C8D50
	this->CreateHook(L"G2EXT_CALLBACK_OPEN_LOADSCREEN", (void*)0x006C2690, &CCoreIngame::OnOpenLoadscreen);					// -- bound on oCGame::OpenLoadscreen(bool, class zSTRING) -- 0x006C2690
	this->CreateHook(L"G2EXT_CALLBACK_OPEN_SAVESCREEN", (void*)0x006C2250, &CCoreIngame::OnOpenSavescreen);					// -- bound on oCGame::OpenSavescreen(bool) -- 0x006C2250
	this->CreateHook(L"G2EXT_CALLBACK_CLOSE_LOADSCREEN", (void*)0x006C2BD0, &CCoreIngame::OnCloseLoadscreen);				// -- bound on oCGame::CloseLoadscreen(void) -- 0x006C2BD0
	this->CreateHook(L"G2EXT_CALLBACK_CLOSE_SAVESCREEN", (void*)0x006C2630, &CCoreIngame::OnCloseSavescreen);				// -- bound on oCGame::CloseSavescreen(void) -- 0x006C2630
	//this->CreateHook(L"G2EXT_CALLBACK_ENTER_WORLD", (void*)0x006C96F0, &CCoreIngame::OnIngame);								// -- bound on oCGame::EnterWorld(class oCNpc *, int, class zSTRING const &) -- 0x006C96F0 // OLD ingame event point -> oCNpc::player uninitialized!!
	this->CreateHook(L"G2EXT_CALLBACK_NPC_INIT", (void*)0x006C0D00, &CCoreIngame::OnIngame);								// -- bound on oCGame::NpcInit(void) -- 0x006C0D00 // NEW ingame event point
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
#endif // _G2EXT_COMPILE_SPACER
	G2EXT_LOG_NONE(L"Attaching hacks.");
#ifdef _G2EXT_COMPILE_SPACER
	//this->ReplaceFunction(L"G2EXT_REPLACE_SPLASH", (void*)0x0048A460, &SplashThreadProc); // -- HACK: Replace Splash Screen
#else // _G2EXT_COMPILE_SPACER
	if(!CCoreIngame::GetInstance()->IsFlagSet(G2EXT_PARAM_NO_G2EXT_CONSOLE))
	{
		this->EraseSecuredMem((void*)0x0047EC65, 5, 0x90);		// -- HACK: Suppress marvin mode
		this->EraseSecuredMem((void*)0x00895634, 1, '\n');		// -- HACK: Disable devmode
		this->EraseSecuredMem((void*)0x0047099F, 125, 0x90);	// ''
	};

	this->EraseSecuredMem((void*)0x008B28F4, 1, 0); // -- HACK: Erase pause text in menus
	this->ReplaceFunction(L"G2EXT_REPLACE_SPLASH", (void*)0x00426660, &SplashThreadProc); // -- HACK: Replace Splash Screen

	// -- HACK: Instant start (skip menu, but no exiting on key down ESC event)
	if(CCoreIngame::GetInstance()->IsFlagSet(G2EXT_PARAM_NO_START_MENU))
	{
		this->EraseSecuredMem((void*)0x00429471, 4, 0x90);
	};

	// -- HACK: Suppress VDFS consistency check
	if(CCoreIngame::GetInstance()->IsFlagSet(G2EXT_PARAM_NO_VDFS_CHECK))
	{
		this->EraseSecuredMem((void*)0x0047099F, 125, 0x90);
	};
#endif // _G2EXT_COMPILE_SPACER

	G2EXT_LOG_NONE(L"Registering internal callbacks.");

	this->RegisterCallback(L"G2EXT_INT_ON_RENDER", &CCoreIngame::GothicOnRender, G2EXT_CB_ON_RENDER);
	this->RegisterCallback(L"G2EXT_INT_ON_DONE", &CCoreIngame::GothicOnDone, G2EXT_CB_ON_DONE);
	this->RegisterCallback(L"G2EXT_INT_ON_PAUSE", &CCoreIngame::GothicOnPause, G2EXT_CB_ON_PAUSE);
	this->RegisterCallback(L"G2EXT_INT_ON_UNPAUSE", &CCoreIngame::GothicOnUnPause, G2EXT_CB_ON_UNPAUSE);
	this->RegisterCallback(L"G2EXT_INT_ON_INGAME", &CCoreIngame::GothicOnIngame, G2EXT_CB_ON_INGAME);
	this->RegisterCallback(L"G2EXT_INT_ON_INPUT", &CCoreIngame::GothicOnInput, G2EXT_CB_ON_INPUT);
};	

//////////////////////////////////////////////////////////////////////////

void CCoreIngame::ClearVobList(void)
{
	this->m_lstVobs.clear();
};

void CCoreIngame::ClearMobList(void)
{
	this->m_lstMobs.clear();
};

void CCoreIngame::ClearItemList(void)
{
	this->m_lstItems.clear();
};

void CCoreIngame::ClearNpcList(void)
{
	this->m_lstNpcs.clear();
};

void CCoreIngame::ProcessVobList(void)
{
	UINT uListSize = 0;

	zCListSort<zCVob>* pVobList = oCGame::GetGame()->GetWorld()->GetVobList();
	if(pVobList != NULL)
	{
		if((uListSize = pVobList->GetSize()) != 0)
		{
			G2EXT_LOGF_DEBUG(L"Processing VOB list. [%d entries]", uListSize)

			for(UINT i = 0; i < uListSize; i++)
			{
				zCVob* v = (zCVob*)pVobList->Get(i);
				this->m_lstVobs.push_back(v);

				if(v->GetVobType() == VOB_TYPE_MOB)
				{
					this->m_lstMobs.push_back(v);
				};

				if(v->GetVobType() == VOB_TYPE_STARTPOINT)
				{
					this->m_pLevelStartpoint = v;
				};
			};
		};
	};
};

void CCoreIngame::ProcessItemList(void)
{
	UINT uListSize = 0;
	zCListSort<oCItem>* pItemList = oCGame::GetGame()->GetWorld()->GetItemList();
	if(pItemList != NULL)
	{
		if((uListSize = pItemList->GetSize()) != 0)
		{
			G2EXT_LOGF_DEBUG(L"Processing item list. [%d entries]", uListSize)

			for(UINT i = 0; i < uListSize; i++)
			{
				this->m_lstItems.push_back((oCItem*)pItemList->Get(i));
			};
		};
	};
};

void CCoreIngame::ProcessNpcList(void)
{
	UINT uListSize = 0;
	zCListSort<oCNpc>* pNpcList = oCGame::GetGame()->GetWorld()->GetNpcList();
	if(pNpcList != NULL)
	{
		if((uListSize = pNpcList->GetSize()) != 0)
		{
			G2EXT_LOGF_DEBUG(L"Processing NPC list. [%d entries]", uListSize)

			for(UINT i = 0; i < uListSize; i++)
			{
				this->m_lstNpcs.push_back((oCNpc*)pNpcList->Get(i));
			};
		};
	};
};