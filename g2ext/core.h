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

#ifndef __G2EXT_CORE_H__
#define __G2EXT_CORE_H__

#include "api/core.h"
#include "singleton.h"

#ifdef _G2EXT_COMPILE_SPACER
#include "api/spacer/zCVob.h"
#include "api/spacer/oCNpc.h"
#include "api/spacer/oCItem.h"
#else //_G2EXT_COMPILE_SPACER
#include "api/g2/zCVob.h"
#include "api/g2/oCNpc.h"
#include "api/g2/oCItem.h"
#endif //_G2EXT_COMPILE_SPACER

#include "common/version.h"

#include "log.h"

#include <hash_map>
#include <vector>

//////////////////////////////////////////////////////////////////////////

class IConsole;
class IStatistics;
class ICoreIngame;
class ICoreOutgame;
class ILog;

class zCParser;
class zCConsole;
class CInjection;
class CConsole;
class CStatistics;

//////////////////////////////////////////////////////////////////////////

//#define G2EXT_MAX_HOOK_NAME_LENGTH		64
#define G2EXT_MAX_CALLBACK_NAME_LENGTH	64
#define G2EXT_MAX_CALLBACK_COUNT		(G2EXT_CB_MAX+1)

//////////////////////////////////////////////////////////////////////////

/*
#ifndef G2EXT_HOOKINFO_DEFINED
#define G2EXT_HOOKINFO_DEFINED

typedef struct _HOOKINFO
{
	wchar_t			wcName[G2EXT_MAX_HOOK_NAME_LENGTH];
	int				nHookHandle;

	void Clear()
	{
		ZeroMemory(this->wcName, sizeof(_HOOKINFO));
	};

	_HOOKINFO(LPCWSTR lpwName, int nHandle)
	{
		wcscpy_s(this->wcName, G2EXT_MAX_HOOK_NAME_LENGTH, lpwName);
		this->nHookHandle = nHandle;
	};

	_HOOKINFO()
	{
		this->Clear();
	};

	~_HOOKINFO()
	{
		this->Clear();
	};
} HOOKINFO, *PHOOKINFO;

#endif  //G2EXT_HOOKINFO_DEFINED
*/

#ifndef G2EXT_CALLBACKINFO_DEFINED
#define G2EXT_CALLBACKINFO_DEFINED

typedef struct _CALLBACKINFO
{
	wchar_t				m_wcName[G2EXT_MAX_CALLBACK_NAME_LENGTH];
	void*				m_pCallback;
	bool				m_bActive;
	G2EXT_CALLBACKTYPE	m_cbType;

	void Clear()
	{
		ZeroMemory(this->m_wcName, sizeof(_CALLBACKINFO));
	};

	_CALLBACKINFO(LPCWSTR lpwName, void* pCallback, G2EXT_CALLBACKTYPE cbType = G2EXT_CB_ON_RENDER, bool bActive = false)
	{
		wcscpy_s(this->m_wcName, G2EXT_MAX_CALLBACK_NAME_LENGTH, lpwName);
		this->m_pCallback	= pCallback;
		this->m_bActive		= bActive;
		this->m_cbType		= cbType;
	};

	_CALLBACKINFO()
	{
		this->Clear();
	};

	~_CALLBACKINFO()
	{
		this->Clear();
	};
} CALLBACKINFO, *PCALLBACKINFO;

#endif  //G2EXT_CALLBACKINFO_DEFINED

//////////////////////////////////////////////////////////////////////////

#ifndef G2EXT_PLUGIN_DEFINED
#define G2EXT_PLUGIN_DEFINED

/** internal use only */
typedef struct _PLUGIN
{
	size_t							szSize;
	LPCWSTR							lpwPluginDLL;
	HMODULE							hModule;
	G2EXT_PLUGIN_INIT_FUNC			PluginInit;
	G2EXT_PLUGIN_VERSIONCHK_FUNC	PluginCheckVersion;

	_PLUGIN()
	{
		ZeroMemory(this, sizeof(_PLUGIN));
		this->szSize = sizeof(_PLUGIN);
	};

	~_PLUGIN()
	{
		ZeroMemory(this, sizeof(_PLUGIN));
	};

	HRESULT Load(LPCWSTR lpwName)
	{
		if((this->lpwPluginDLL = lpwName) == NULL)
		{
			G2EXT_LOG_WARNING(L"Plugin file name empty!");
			return E_FAIL;
		};

		if((this->hModule = LoadLibrary(lpwName)) == NULL)
		{
			G2EXT_LOG_WARNING(L"LoadLibrary failed.");
			return E_FAIL;
		};

		if((this->PluginCheckVersion = reinterpret_cast<G2EXT_PLUGIN_VERSIONCHK_FUNC>(GetProcAddress(this->hModule, "G2Ext_PluginCheckVersion"))) == NULL)
		{
			G2EXT_LOG_WARNING(L"G2Ext_PluginCheckVersion not found!");
			return E_FAIL;
		};

		int				nVersionMajor = 0;
		int				nVersionMinor = 0;
		G2EXT_DLL_TYPE	extDllType	  = G2EXT_DLL_PLUGIN;

		this->PluginCheckVersion(nVersionMajor, nVersionMinor, extDllType);

		if(nVersionMajor < G2EXT_MAJOR_VERSION || nVersionMinor < G2EXT_MINOR_VERSION)
		{
			G2EXT_LOGF_WARNING(L"Plugin version mismatch! G2Ext: %i.%i Plugin: %i.%i", G2EXT_MAJOR_VERSION, G2EXT_MINOR_VERSION, nVersionMajor, nVersionMinor);
			return E_FAIL;
		};

#ifdef _G2EXT_COMPILE_SPACER
		if(extDllType != G2EXT_DLL_SPACER_PLUGIN)
		{
			G2EXT_LOG_WARNING(L"Non Spacer plugin!");
			return E_FAIL;
		};
#else //_G2EXT_COMPILE_SPACER
		if(extDllType != G2EXT_DLL_PLUGIN)
		{
			G2EXT_LOG_WARNING(L"Non Gothic plugin!");
			return E_FAIL;
		};
#endif //_G2EXT_COMPILE_SPACER

		if((this->PluginInit = reinterpret_cast<G2EXT_PLUGIN_INIT_FUNC>(GetProcAddress(this->hModule, "G2Ext_PluginInit"))) == NULL)
		{
			G2EXT_LOG_WARNING(L"G2Ext_PluginInit not found!");
			return E_FAIL;
		};

		return S_OK;
	};

} PLUGIN, *PPLUGIN;

#endif  //G2EXT_PLUGIN_DEFINED

//////////////////////////////////////////////////////////////////////////

typedef stdext::hash_map<LPCWSTR, UINT>			 hmHook;
typedef stdext::hash_map<LPCWSTR, PCALLBACKINFO> hmCallback;
typedef stdext::hash_map<LPCWSTR, PPLUGIN>		 hmPlugin;

//////////////////////////////////////////////////////////////////////////

class CCoreIngame : public TSingleton<CCoreIngame>, public ICoreIngame
{
friend DWORD __stdcall SplashThreadProc(void* param);
private:
	hmCallback				m_hmCallbacks[G2EXT_CB_MAX];
	hmPlugin				m_hmPlugins;
	hmHook					m_hmHooks;
	std::vector<UINT>		m_vBannedKeys;
	hmKey					m_hmRedirectKeys;
	bool					m_bInGame;
	bool					m_bInMenu;
	bool					m_bInLoadScreen;
	bool					m_bIsFirstRun;
	bool					m_bIsPaused;
	/*
	hmItem					m_hmItems;
	hmNpc					m_hmNpcs;
	vVob					m_vVobs;
	vVob					m_vMobs;
	*/
private: // mod
	PMODINFO				m_pModInfo;
	HMODULE					m_pModHandle;
	bool					m_bUseCustomSplashScreen;
	HBITMAP					m_hSplashBitmap;
	bool					m_bSplashShowVersionInfo;
private: // instances
	CConsole*				m_pConsole;
	CStatistics*			m_pStatistics;
	CLog*					m_pLog;
private: // mod funcs
	G2EXT_MOD_INIT_FUNC		ModInit;
private:
	bool					InitCallbackSystem(void);
	void					InitHookSystem(void);
	void					AttachCallbackHooks(void);
	void					LoadModDll(LPCWSTR lpwFileName);
	void					LoadPlugins(LPCWSTR lpwPlugins);
public: // interface
	bool 					DisableCallback(G2EXT_CALLBACKTYPE cbType, LPCWSTR lpwName);
	bool 					DisableAllCallbacks(void);
	bool 					DisableAllCallbacksOfType(G2EXT_CALLBACKTYPE cbType);
	bool 					EnableCallback(G2EXT_CALLBACKTYPE cbType, LPCWSTR lpwName);
	bool 					EnableAllCallbacks(void);
	bool 					EnableAllCallbacksOfType(G2EXT_CALLBACKTYPE cbType);
	bool 					IsCallbackEnabled(G2EXT_CALLBACKTYPE cbType, LPCWSTR lpwName);
	bool					RegisterCallback(LPCWSTR lpwName, void* pCallback, G2EXT_CALLBACKTYPE cbType, bool bActive = true);
	bool					UnRegisterCallback(G2EXT_CALLBACKTYPE cbType, LPCWSTR lpwName);

	bool 					CreateHook(LPCWSTR lpwName, void* pDestination, void* pCallBack, bool bWantRegisterAccess = false, UINT uParamCount = 0);
	bool					CreateConditionalHook_C(LPCWSTR lpwName, void* pDestination, void* pCallBack, void* pConditionVar, bool bWantRegisterAccess = false, UINT uParamCount = 0);
	bool					CreateConditionalHook_C_N(LPCWSTR lpwName, void* pDestination, void* pCallBack, void* pConditionVar, bool bWantRegisterAccess = false, UINT uParamCount = 0);
	bool					CreateConditionalHook_R(LPCWSTR lpwName, void* pDestination, void* pCallBack, REGISTER eRegister, int nConditionVar, bool bWantRegisterAccess = false, UINT uParamCount = 0);
	bool					ReplaceFunction(LPCWSTR lpwName, void* pDestination, void* pNewFunc);
	bool					RedirectCall(LPCWSTR lpwName, void* pDestination, void* pNewFunc);
	void					RemoveHook(LPCWSTR lpwName);
	bool					PatchSecuredMem(void* pDestination, const void* lpBuffer, size_t szLength);
	bool					EraseSecuredMem(void* pDestination, size_t szLength, int nValue);

	void					SetSplashScreen(HBITMAP hBitmap, bool bShowVersion = true);

	bool					BanKey(unsigned int uKey);
	bool					UnBanKey(unsigned int uKey);			
	bool					RemapKey(unsigned int uOrigKey, unsigned int uRedirectKey);
	bool					UnRemapKey(unsigned int uOrigKey);

	ILog*					GetLog(void)		{ return reinterpret_cast<ILog*>(this->m_pLog);					};
	IConsole*				GetConsole(void)	{ return reinterpret_cast<IConsole*>(this->m_pConsole);			};
	IStatistics*			GetStatistics(void)	{ return reinterpret_cast<IStatistics*>(this->m_pStatistics);	};

	/*
	vVob*					GetVobList(void)	{ return &this->m_hm_vobs;	};
	vVob*					GetMobList(void)	{ return &this->m_hm_mobs;	};
	hmItem*					GetItemList(void)	{ return &this->m_hm_items; };
	hmNpc*					GetNpcList(void)	{ return &this->m_hm_npcs;	};
	*/
public: // internal
	void					CheckForBannedKey(UINT& uKey);
	void					CallCallback(G2EXT_CALLBACKTYPE cbType, UINT uKey = 0);
	static void	__stdcall	GothicOnInput(UINT& uKey);
	static void	__stdcall	GothicOnRender(void);
	static void	__stdcall	GothicOnDone(void);
	static void __stdcall	GothicOnPause(void);
	static void __stdcall	GothicOnIngame(void);
	static void __stdcall	GothicOnUnPause(void);
	static void __stdcall	GothicOnLoadWorld(void);
	static void __stdcall	GothicOnOpenLoadscreen(void);
	static void __stdcall	GothicOnCloseLoadscreen(void);
public: // internal
	CCoreIngame();
	~CCoreIngame();

	__forceinline bool		GetFlag(DWORD dwFlag)	{ return ((this->m_pModInfo->dwFlags & dwFlag) == dwFlag) ? true : false; };
	__forceinline void		SetFlag(DWORD dwFlag)	{ this->m_pModInfo->dwFlags |= dwFlag; };
	__forceinline void		UnSetFlag(DWORD dwFlag) { this->m_pModInfo->dwFlags = this->m_pModInfo->dwFlags & ~dwFlag; };
	void					Init(PMODINFO pModInfo);
	void					Release(void);
	void					PrepareForReload(void);
	void					Reload(void);
public: // callbacks

	//////////////////////////////////////////////////////////////////////////

	#define G2EXT_MAKE_CALLBACK(name, type) static void __stdcall name(void) { G2EXT_LOGF_DEBUG(L"Callback called: %S", DEFTOSTR(name)); CCoreIngame::GetInstance()->CallCallback(type); };
	#define G2EXT_MAKE_CALLBACKN(name, type) static void __stdcall name(void) { CCoreIngame::GetInstance()->CallCallback(type); }; // -- fix for OnRender excess flood
	#define G2EXT_MAKE_CALLBACKP(name, type) static void __stdcall name(UINT par1) { G2EXT_LOGF_DEBUG(L"Callback called: %S", DEFTOSTR(name)); CCoreIngame::GetInstance()->CallCallback(type, par1); };

	//////////////////////////////////////////////////////////////////////////

	G2EXT_MAKE_CALLBACK(OnPause, G2EXT_CB_ON_PAUSE);
	G2EXT_MAKE_CALLBACK(OnUnPause, G2EXT_CB_ON_UNPAUSE);
	G2EXT_MAKE_CALLBACK(OnOpenLoadscreen, G2EXT_CB_ON_OPEN_LOADSCREEN);
	G2EXT_MAKE_CALLBACK(OnCloseLoadscreen, G2EXT_CB_ON_CLOSE_LOADSCREEN);
	G2EXT_MAKE_CALLBACK(OnOpenSavescreen, G2EXT_CB_ON_OPEN_SAVESCREEN);
	G2EXT_MAKE_CALLBACK(OnCloseSavescreen, G2EXT_CB_ON_CLOSE_SAVESCREEN);
	G2EXT_MAKE_CALLBACK(OnIngame, G2EXT_CB_ON_INGAME);
	G2EXT_MAKE_CALLBACKN(OnRender, G2EXT_CB_ON_RENDER);
	G2EXT_MAKE_CALLBACK(OnRegisterExternals, G2EXT_CB_ON_REGISTER_EXTERNALS);
	G2EXT_MAKE_CALLBACK(OnRegisterMenuExternals, G2EXT_CB_ON_REGISTER_MENU_EXTERNALS);
	G2EXT_MAKE_CALLBACK(OnRegisterExternalClass, G2EXT_CB_ON_REGISTER_CLASSES);
	G2EXT_MAKE_CALLBACK(OnInitHUD, G2EXT_CB_ON_INIT_HUD);
	G2EXT_MAKE_CALLBACKP(OnInput, G2EXT_CB_ON_INPUT); // 1 param
	G2EXT_MAKE_CALLBACK(OnExit, G2EXT_CB_ON_DONE);
	G2EXT_MAKE_CALLBACK(OnLoadWorld, G2EXT_CB_ON_LOAD_WORLD);
};

//////////////////////////////////////////////////////////////////////////

class CCoreOutgame : public ICoreOutgame
{
private: // mod
	PMODINFO				m_pModInfo;
	HMODULE					m_pModHandle;
	HANDLE					m_hProcess;
	std::list<CInjection*>	m_lstInjections;
	LPCWSTR					m_lpwCMD;
private:
	CLog*					m_pLog;
private: // mod funcs
	G2EXT_MOD_INIT_FUNC			ModInit;
	G2EXT_MOD_PREPARE_FUNC		ModPrepare;
	G2EXT_MOD_VERSIONCHK_FUNC	ModCheckVersion;
public: // interface
	ILog*					GetLog(void) { return NULL; };
	void					GetCmdLine(LPWSTR& lpwCMD, size_t& szLen) { lpwCMD = (LPWSTR)this->m_lpwCMD; szLen = wcslen(this->m_lpwCMD); };
	void					SetCmdLine(LPCWSTR lpwCMD) { this->m_lpwCMD = lpwCMD; };
	HANDLE					GetProcessHandle(void) { return NULL; };
	HANDLE					GetMainThreadHandle(void) { return NULL; };
	HMODULE					GetModModuleHandle(void) { return NULL; };
public: // internal
	HRESULT					Init(PMODINFO pModInfo);
	void					Release(void);
	HRESULT					Run(void);
	bool					LoadModDll(LPCWSTR lpwFileName);

	bool					CreateJumpInjection(const char* lpName, ptr_t lpCodePtr, size_t sCodeLength, ptr_t lpTarget);
	bool					CreateCallInjection(const char* lpName, ptr_t lpCodePtr, size_t sCodeLength, ptr_t lpTarget);
	CInjection*				NewInjection(const char* lpName);
};

#endif //__G2EXT_CORE_H__