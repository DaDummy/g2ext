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

#ifndef __API_G2EXT_CORE_H__
#define __API_G2EXT_CORE_H__

#include "common/osheader.h"

#include "api/interface.h"

#include <vector>
#include <hash_map>

//////////////////////////////////////////////////////////////////////////

class ICoreIngame;
class ICoreOutgame;
class IConsole;
class IStatistics;
class ILog;

class oCItem;
class oCNpc;
class zCVob;

//////////////////////////////////////////////////////////////////////////

#ifndef G2EXT_PARAMFLAGS_DEFINED
#define G2EXT_PARAMFLAGS_DEFINED

/** internal use only */
typedef enum
{
	G2EXT_PARAM_NO_VDFS_CHECK				= 0x00000001,
	G2EXT_PARAM_NO_INJECTION				= 0x00000002,
	G2EXT_PARAM_NO_START_MENU				= 0x00000004,
	G2EXT_PARAM_DEBUG						= 0x00000008,
	G2EXT_PARAM_NO_G2EXT_CONSOLE			= 0x00000010,
	G2EXT_PARAM_NO_CONSOLE					= 0x00000020,
	G2EXT_PARAM_SPACER						= 0x00000040,
	G2EXT_PARAM_SHOW_FPS					= 0x00000080,
	G2EXT_PARAM_RESERVED09					= 0x00000100, // reserved
	G2EXT_PARAM_RESERVED10					= 0x00000200, // reserved
	G2EXT_PARAM_RESERVED11					= 0x00000400, // reserved
	G2EXT_PARAM_RESERVED12					= 0x00000800, // reserved
	G2EXT_PARAM_RESERVED13					= 0x00001000, // reserved
	G2EXT_PARAM_RESERVED14					= 0x00002000, // reserved
	G2EXT_PARAM_RESERVED15					= 0x00004000, // reserved
	G2EXT_PARAM_RESERVED16					= 0x00008000, // reserved
	G2EXT_PARAM_RESERVED17					= 0x00010000, // reserved
	G2EXT_PARAM_RESERVED18					= 0x00020000, // reserved
	G2EXT_PARAM_RESERVED19					= 0x00040000, // reserved
	G2EXT_PARAM_RESERVED20					= 0x00080000, // reserved
	G2EXT_PARAM_RESERVED21					= 0x00100000, // reserved
	G2EXT_PARAM_RESERVED22					= 0x00200000, // reserved
	G2EXT_PARAM_RESERVED23					= 0x00400000, // reserved
	G2EXT_PARAM_RESERVED24					= 0x00800000, // reserved
	G2EXT_PARAM_RESERVED25					= 0x01000000, // reserved
	G2EXT_PARAM_RESERVED26					= 0x02000000, // reserved
	G2EXT_PARAM_RESERVED27					= 0x04000000, // reserved
	G2EXT_PARAM_RESERVED28					= 0x08000000, // reserved
	G2EXT_PARAM_RESERVED29					= 0x10000000, // reserved
	G2EXT_PARAM_RESERVED30					= 0x20000000, // reserved
	G2EXT_PARAM_RESERVED31					= 0x40000000, // reserved
	G2EXT_PARAM_FORCEINT					= 0x7FFFFFFF
};

#endif  //G2EXT_PARAMFLAGS_DEFINED

//////////////////////////////////////////////////////////////////////////

#ifndef G2EXT_CALLBACKTYPE_DEFINED
#define G2EXT_CALLBACKTYPE_DEFINED

/** This enum determines the callback type */
typedef enum 
{
	G2EXT_CB_ON_PAUSE,						// void(__stdcall* pFunc)()				-- bound on	oCGame::Pause(int)												-- 0x006C8AD0
	G2EXT_CB_ON_UNPAUSE,					// void(__stdcall* pFunc)()				-- bound on	oCGame::Unpause(void)											-- 0x006C8D50
	G2EXT_CB_ON_OPEN_LOADSCREEN,			// void(__stdcall* pFunc)()				-- bound on	oCGame::OpenLoadscreen(bool, class zSTRING)						-- 0x006C2690
	G2EXT_CB_ON_OPEN_SAVESCREEN,			// void(__stdcall* pFunc)()				-- bound on	oCGame::OpenSavescreen(bool)									-- 0x006C2250
	G2EXT_CB_ON_CLOSE_LOADSCREEN,			// void(__stdcall* pFunc)()				-- bound on	oCGame::CloseLoadscreen(void)									-- 0x006C2BD0
	G2EXT_CB_ON_CLOSE_SAVESCREEN,			// void(__stdcall* pFunc)()				-- bound on	oCGame::CloseSavescreen(void)									-- 0x006C2630
	G2EXT_CB_ON_INGAME,						// void(__stdcall* pFunc)()				-- bound on	oCGame::EnterWorld(class oCNpc *, int, class zSTRING const &)	-- 0x006C96F0
	G2EXT_CB_ON_RENDER,						// void(__stdcall* pFunc)()				-- bound on	oCGame::Render(void)											-- 0x006C86A0
	G2EXT_CB_ON_REGISTER_EXTERNALS,			// void(__stdcall* pFunc)(zCParser*)	-- bound on oCGame::DefineExternals_Ulfi(class zCParser *)					-- 0x006D4780
	G2EXT_CB_ON_REGISTER_MENU_EXTERNALS,	// void(__stdcall* pFunc)(zCParser*)	-- bound on	DefineMenuScriptFunctions()										-- 0x0042C1D0
	G2EXT_CB_ON_INIT_HUD,					// void(__stdcall* pFunc)(zCView*)		-- bound on oCGame::Init(void)												-- 0x006C1440
	G2EXT_CB_ON_INPUT,						// void(__stdcall* pFunc)(unsigned int) -- bound on oCGame::HandleEvent(int)										-- 0x006FC170
	G2EXT_CB_ON_DONE,						// void(__stdcall* pFunc)()				-- bound on oCGame::Done(void)												-- 0x006C0D80
	G2EXT_CB_ON_LOAD_WORLD,					// void(__stdcall* pFunc)()				-- bound on	oCGame::LoadWorld(int, class zSTRING const &)					-- 0x006C90B0
	G2EXT_CB_ON_REGISTER_CLASSES,			// void(__stdcall* pFunc)(zCParser*)	-- bound on	oCNpc::InitStatics(void)										-- 0x0075E4D0
	G2EXT_CB_MAX = G2EXT_CB_ON_REGISTER_CLASSES,
	G2EXT_CB_FORCEINT = 0x7FFFFFFF
} G2EXT_CALLBACKTYPE;

#endif  //G2EXT_CALLBACKTYPE_DEFINED

/** Thus enum determines the dll type */
typedef enum 
{
	G2EXT_DLL_MOD,				// mod dll
	G2EXT_DLL_SPACER,			// spacer mod dll - not implemented yet
	G2EXT_DLL_PLUGIN,			// gothic plugin - not implemented yet
	G2EXT_DLL_SPACER_PLUGIN,	// spacer plugin - not implemented yet
	G2EXT_DLL_FORCEINT = 0x7FFFFFFF
} G2EXT_DLL_TYPE;

//////////////////////////////////////////////////////////////////////////

#ifndef G2EXT_REGISTERS_DEFINED
#define G2EXT_REGISTERS_DEFINED

/** Insert description */
typedef struct _REGISTERS
{
	int*	EIP;
	int		EDI,
			ESI,
			EBP,
			ESP,
			EBX,
			EDX,
			ECX,
			EAX;
} REGISTERS;

/** Insert description */
typedef enum _REGISTER
{
	G2EXT_REG_EAX = 0,
	G2EXT_REG_ECX = 1,
	G2EXT_REG_EDX = 2,
	G2EXT_REG_EBX = 3,
	G2EXT_REG_ESP = 4,
	G2EXT_REG_EBP = 5,
	G2EXT_REG_ESI = 6,
	G2EXT_REG_EDI = 7,
	G2EXT_REG_MAX = 8,
	G2EXT_REG_FORCEINT = 0x7FFFFFFF
} REGISTER;

#endif  //G2EXT_REGISTER_DEFINED

//////////////////////////////////////////////////////////////////////////

#ifndef G2EXT_MODINFO_DEFINED
#define G2EXT_MODINFO_DEFINED

/** internal use only */
typedef struct _MODINFO 
{
	size_t		szSize;
	LPCWSTR		lpwModIni;
	LPCWSTR		lpwDLL;
	LPCWSTR		lpwPlugins;
	LPCWSTR		lpwVDF;
	LPCWSTR		lpwDMP;
	LPCWSTR		lpwCMD;
	DWORD		dwFlags;
	void*		lpIntShared; // -- internal
	void*		lpModShared; // -- internal
	LPCWSTR		lpwSpacerDLL;

	_MODINFO()
	{
		ZeroMemory(this, sizeof(_MODINFO));
		this->szSize = sizeof(_MODINFO);
	};

	~_MODINFO()
	{
		ZeroMemory(this, sizeof(_MODINFO));
	};
} MODINFO, *PMODINFO;

#endif  //G2EXT_MODINFO_DEFINED

//////////////////////////////////////////////////////////////////////////

typedef HRESULT (__stdcall *G2EXT_SYSTEM_INIT_FUNC)			(PMODINFO);
typedef HRESULT (__stdcall *G2EXT_SYSTEM_RUN_FUNC)			(PMODINFO);
typedef HRESULT (__stdcall *G2EXT_MOD_INIT_FUNC)			(ICoreIngame*);
typedef HRESULT (__stdcall *G2EXT_MOD_PREPARE_FUNC)			(ICoreOutgame*);
typedef HRESULT (__stdcall *G2EXT_MOD_VERSIONCHK_FUNC)		(int&, int&, G2EXT_DLL_TYPE&);

typedef HRESULT (__stdcall *G2EXT_PLUGIN_INIT_FUNC)			(ICoreIngame*);
typedef HRESULT (__stdcall *G2EXT_PLUGIN_VERSIONCHK_FUNC)	(int&, int&, G2EXT_DLL_TYPE&);

#define G2EXT_SYSTEM_INIT_FUNC_NAME		"G2Ext_Init"
#define G2EXT_SYSTEM_RUN_FUNC_NAME		"G2Ext_Run"
#define G2EXT_MOD_INIT_FUNC_NAME		"G2Ext_ModInit"
#define G2EXT_MOD_PREPARE_FUNC_NAME		"G2Ext_ModPrepare"
#define G2EXT_MOD_VERSIONCHK_FUNC_NAME	"G2Ext_ModVersion"

#define G2EXT_PLUGIN_INIT_FUNC_NAME		"G2Ext_PluginInit"
#define G2EXT_PLUGIN_PREPARE_FUNC_NAME	"G2Ext_PluginPrepare"

typedef stdext::hash_map<UINT, UINT>					hmKey;
typedef stdext::hash_map<UINT, oCItem>					hmItem;
typedef stdext::hash_map<UINT, oCNpc>					hmNpc;
typedef std::vector<zCVob>								vVob;
typedef std::vector<zCVob>								vMob;

//////////////////////////////////////////////////////////////////////////

/** G2Ext ingame core */
G2EXT_BEGIN_INTERFACE_DECLARATION(ICoreIngame)
{
	/** Places a function hook.
	*	@usable	Ingame only
	*
	*   @anchor INTOPS @attention
	*           Callbacks @b with @b parameters must always be declared as follows:
	*           - with @b stdcall calling convention
	*           - the parameters must be declared as @b references
	*   @attention @n
	*           Before the callback's execution, the following operations are performed:
	*           - The registers EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI will be saved
	*           - The parameters of the hooked function are put as references onto the stack
	*           - The register EAX gets overwritten with the callback address
	*   @attention @n
	*           After the callback's execution, the following operations are performed:
	*           - The registers EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI will be recovered
	*
	*	@param	lpName				The name of the hook to be created. (must be unique, the "g2ext_" prefix is reserved)
	*   @param  lpDestination		The function to be hooked.
	*   @param  lpCallBack			The callback function.
	*   @param  bWantRegisterAccess	Gives access to the saved registers over a g2ext::registers_c-struct.
	*   @param  nParamCount			The target function's parameter count.
	*   @return true if successful, false otherwise.
	*
	*           @b Sample:
	*   @code
	*           int sampleclass::samplefunc(char* text, int& a, int b)
	*           {
	*               //does something...
	*           };
	*
	*           static __stdcall void foo::cbfunc(char** text, int** a, int& b)
	*           {
	*           };
	*
	*           void foo()
	*           {
	*               g2ext_core_i->CreateHook("test", &samplefunc, &cbfunc, false, 3);
	*           };
	*   @endcode
	*
	*           @b Sample (with register access):
	*   @code
	*           int sampleclass::samplefunc(char* text, int& a, int b)
	*           {
	*               //does something...
	*           };
	*
	*           static __stdcall void foo::cbfunc(g2ext::registers_c& Register, char** text, int** a, int& b)
	*           {
	*               static foo MyClass;
	*               //Makes this to MyClass
	*               Register.ECX = &MyClass;
	*           };
	*
	*           void foo()
	*           {
	*               g2ext_core_i->Hook_CreateHook("test", &samplefunc, &cbfunc, true, 3);
	*           };
	*   @endcode
	**/
	virtual bool CreateHook(LPCWSTR lpwName, void* pDestination, void* pCallBack, bool bWantRegisterAccess = false, UINT uParamCount = 0) = NULL;
	
	/**
	*   @brief  Places a conditional function hook.
	*
	*   @remarks
	*           The callback function is called only, if the following condition is fulfilled:
	*           - @a Caller == @a ConditionVar
	*
	*   @attention
	*           Look at @ref INTOPS "this".
	*
	*   @param  Destination The function to be hooked.
	*   @param  CallBack The callback function.
	*   @param  ConditionVar The calling condition value.
	*   @param  WantRegisterAccess Gives access to the saved registers over a sRegs-struct.
	*   @param  ParamCount The target function's parameter count.
	*   @return a operation handle.
	*
	*           @b Sample:
	*   @code
	*           int sampleclass::samplefunc(char* text, int& a, int b)
	*           {
	*               //does something...
	*           };
	*
	*           void sampleclass::caller()
	*           {
	*               int a = 1;
	*               this->samplefunc("test", a, 0);
	*           };
	*
	*           static __stdcall void foo::cbfunc(char** text, int** a, int& b)
	*           {
	*           };
	*
	*           void foo()
	*           {
	*               ConditionalHook_C(&samplefunc, &cbfunc, &caller, false, 3);
	*           };
	*   @endcode
	*
	*   @sa CreateHook, ConditionalHook_C_N
	**/
	virtual bool CreateConditionalHook_C(LPCWSTR lpwName, void* pDestination, void* pCallBack, void* pConditionVar, bool bRegisterAccess, UINT uParamCount) = NULL;

	/**
	*   @brief  Places a conditional function hook.
	*
	*   @remarks
	*           Same as #ConditionalHook_C, with the following condition:
	*           - @a Caller != @a ConditionVar
	*
	*   @sa CreateHook, ConditionalHook_C
	**/
	virtual bool CreateConditionalHook_C_N(LPCWSTR lpwName, void* pDestination, void* pCallBack, void* pConditionVar, bool bRegisterAccess, UINT uParamCount) = NULL;

	/**
	*   @brief  Places a conditional function hook.
	*
	*   @remarks
	*           The callback function is called only, if the following condition is fulfilled:
	*           - @a Register == @a ConditionVar
	*
	*   @attention
	*           Look at @ref INTOPS "this".
	*
	*   @param  Destination The function to be hooked.
	*   @param  CallBack The callback function.
	*   @param  Register The register to compare with.
	*   @param  ConditionVar The calling condition value.
	*   @param  WantRegisterAccess Gives access to the saved registers over a sRegs-struct.
	*   @param  ParamCount The target function's parameter count.
	*   @return a operation handle.
	*
	*           @b Sample (Register ECX):
	*   @code
	*           int sampleclass::samplefunc(char* text, int& a, int b)
	*           {
	*               //does something...
	*           };
	*
	*           static __stdcall void foo::cbfunc(char** text, int** a, int& b)
	*           {
	*           };
	*
	*           void foo()
	*           {
	*               sampleclass* bar = new sampleclass;
	*               ConditionalHook_R(&samplefunc, &cbfunc, ER_ECX, bar, false, 3);
	*               bar->samplefunc("test", a, 0);
	*           };
	*   @endcode
	*
	*   @sa CreateHook
	**/
	virtual bool CreateConditionalHook_R(LPCWSTR lpwName, void* pDestination, void* pCallBack, REGISTER eRegister, int nConditionVar, bool bWantRegisterAccess = false, UINT uParamCount = 0) = NULL;

	/** Replaces a function by your own.
	*	@usable	Ingame only
	*
	*   @attention
	*           The function to replace with must be declared just like the original function.
	*
	*	@param	lpName			The name of the hook to be created. (must be unique, the "g2ext_" prefix is reserved)
	*   @param  lpDestination	The function to replace.
	*   @param  lpNewFunc		The function to replace with.
	*   @return true if successful, false otherwise.
	*
	*           @b Sample:
	*   @code
	*           int __cdecl sampleclass::samplefunc(char* text, int& a, int b)
	*           {
	*               //does something...
	*           };
	*
	*           static __cdecl int foo::NewFunc(char* text, int& a, int b)
	*           {
	*               //does something else...
	*           };
	*
	*           void foo()
	*           {
	*               g2ext_core_i->Hook_ReplaceFunction("test", &samplefunc, &NewFunc);
	*           };
	*   @endcode
	**/
	virtual bool ReplaceFunction(LPCWSTR lpwName, void* pDestination, void* pNewFunc) = NULL;

	/** Redirects a function call.
	*	@usable	Ingame only
	*
	*   @attention
	*           The function to replace with must be declared just like the original function.
	*
	*	@param	lpName			The name of the hook to be created. (must be unique, the "g2ext_" prefix is reserved)
	*   @param  lpDestination	The call to redirect.
	*   @param  lpNewFunc		The function to redirect to.
	*   @return true if successful, false otherwise.
	*
	*           @b Sample:
	*   @code
	*           int __cdecl sampleclass::samplefunc(char* text, int& a, int b)
	*           {
	*               //does something...
	*           };
	*
	*           static __cdecl int foo::NewFunc(char* text, int& a, int b)
	*           {
	*               //does something else...
	*           };
	*
	*           // some assembler code
	*           0x452475    inc edx
	*           0x452476    call 0x402416 (sampleclass::samplefunc)
	*
	*           void foo()
	*           {
	*               g2ext_core_i->Hook_RedirectCall("test", (void*)0x452476, &NewFunc);
	*           };
	*   @endcode
	**/
	virtual bool RedirectCall(LPCWSTR lpwName, void* pDestination, void* pNewFunc) = NULL;

	/** This method removes a hook
	*	@usable	Ingame only
	*	@param	lpName	The name of the hook to be removed. (must be unique, the "g2ext_" prefix is reserved)
	**/
	virtual void RemoveHook(LPCWSTR lpwName) = NULL;

	/**	This method overwrites secured memory (e.g. program code)
	*	@usable	Ingame only
	*	@param	Destination Pointer to destination
	*	@param  Buffer		Pointer to data buffer (new data)
	*	@param  Length		Size of memory to overwrite
	*   @return true if success
	**/
	virtual bool PatchSecuredMem(void* pDestination, const void* pBuffer, size_t szLength) = NULL;

	/** This method overwrites secured memory (e.g. program code) with specified value
	*	@usable	Ingame only
	*	@param	Destination Pointer to destination
	*	@param  Length		Size of memory to overwrite
	*	@param  Value		Value to insert
	*   @return true if success
	**/
	virtual bool EraseSecuredMem(void* pDestination, size_t szLength, int nValue) = NULL;

	/** This method disables a callback
	*	@usable	Ingame only
	*	@param	cbType		Callback type
	*	@param  lpName		Callback name
	*   @return true if success
	**/
	virtual bool DisableCallback(G2EXT_CALLBACKTYPE cbType, LPCWSTR lpwName) = NULL;

	/** This method disables all callbacks
	*	@usable	Ingame only
	*	@param	cbType		Callback type
	*	@param  lpName		Callback name
	*   @return true if success
	**/
	virtual bool DisableAllCallbacks(void) = NULL;

	/** This method disables all callbacks of a type
	*	@usable	Ingame only
	*	@param	cbType		Callback type
	*   @return true if success
	**/
	virtual bool DisableAllCallbacksOfType(G2EXT_CALLBACKTYPE cbType) = NULL;

	/** This method enables a callback
	*	@usable	Ingame only
	*	@param	cbType		Callback type
	*	@param  lpName		Callback name
	*   @return true if success
	**/
	virtual bool EnableCallback(G2EXT_CALLBACKTYPE cbType, LPCWSTR lpwName) = NULL;

	/** This method enables all callbacks
	*	@usable	Ingame only
	*	@param	cbType		Callback type
	*	@param  lpName		Callback name
	*   @return true if success
	**/
	virtual bool EnableAllCallbacks(void) = NULL;

	/** This method enables all callbacks of a type
	*	@usable	Ingame only
	*	@param	cbType		Callback type
	*   @return true if success
	**/
	virtual bool EnableAllCallbacksOfType(G2EXT_CALLBACKTYPE cbType) = NULL;

	/** This method returns whether a callback is enabled or not
	*	@usable	Ingame only
	*	@param	cbType		Callback type
	*	@param  lpName		Callback name
	*   @return true when callback is enabled
	**/
	virtual bool IsCallbackEnabled(G2EXT_CALLBACKTYPE cbType, LPCWSTR lpwName) = NULL;

	/** This method registers a callback
	*	@usable	Ingame only
	*	@param	lpName		Callback name
	*	@param  pcbFunc		Callback function
	*	@param  cbType		Callback type
	*	@param  bActive		Is callback active
	*   @return true when callback has been successfully registered
	**/
	virtual bool RegisterCallback(LPCWSTR lpwName, void* pcbFunc, G2EXT_CALLBACKTYPE cbType, bool bActive = true) = NULL;

	/** This method unregisters a callback
	*	@usable	Ingame only
	*	@param	cbType		Callback type
	*	@param  pcbFunc		Callback function
	*   @return true when callback has been successfully removed from the lists
	**/
	virtual bool UnRegisterCallback(G2EXT_CALLBACKTYPE cbType, LPCWSTR lpwName) = NULL;

	/** This method sets the splash screen, that will be shown at startup
	*	@usable	G2Ext_ModInit only
	*	@param	hBitmap			Splash screen bitmap handle
	*	@param  bShowVersion	Determines whether to show version info or not
	**/
	virtual void SetSplashScreen(HBITMAP hBitmap, bool bShowVersion = true) = NULL;

	/** Disables ("bans") specified key.
	* @note Does not work with movement keys, like W; A; S; D; UP; DOWN; LEFT; RIGHT; ENTF; PAGE DOWN; CTRL L; CTRL R; ALT;
	* @usable Ingame only
	* @param uKey key to ban
	*/
	virtual bool BanKey(unsigned int uKey) = NULL;

	/** Removes "ban" from key (e.g enables it again).
	* @usable Ingame only
	* @param uKey key to unban
	*/
	virtual bool UnBanKey(unsigned int uKey) = NULL;

	/** Maps specified key to another.
	* @usable Ingame only
	* @param uOrigKey Original key
	* @param uRedirectKey Key the key down/up event will be sent to
	* 
	*/
	virtual bool RemapKey(unsigned int uOrigKey, unsigned int uRedirectKey) = NULL;

	/** Removes key mapping.
	* @usable Ingame only
	* @param uOrigKey Original key
	*/
	virtual bool UnRemapKey(unsigned int uOrigKey) = NULL;

	/** This method returns the g2ext log object.
	* @usable	Always
	* @note	The log object is the preferred way of printing debug output.
	*/
	virtual ILog*		 GetLog(void) = NULL;

	/** This method returns the current console class instance.
	* @usable	Ingame only
	*/
	virtual IConsole*	 GetConsole(void) = NULL;

	/** This method returns the current statistics class instance.
	* @usable	Ingame only
	*/
	virtual IStatistics* GetStatistics(void) = NULL;
} G2EXT_END_INTERFACE_DECLARATION(ICoreIngame);

//////////////////////////////////////////////////////////////////////////

/** Outgame core of G2Ext. */
G2EXT_BEGIN_INTERFACE_DECLARATION(ICoreOutgame)
{
	/** This method returns the g2ext log object.
	* @usable	Always
	* @note	The log object is the preferred way of printing debug output.
	*/
	virtual ILog*	GetLog(void) = NULL;

	/** This method reads the command line parameters
	* @param	lpDest		Destination string
	* @param	sDestLen	Destination string length/size
	* @usable	Outgame only
	*/
	virtual void	GetCmdLine(LPWSTR& lpwDest, size_t& szLen) = NULL;

	/** This method sets the command line parameters
	* @param	lpSrc		New CMD parameter list
	* @usable	Outgame only
	*/
	virtual void	SetCmdLine(LPCWSTR lpwSrc) = NULL;

	/** This method returns the process handle of Gothic
	* @return	Process handle
	* @usable	Outgame only
	*/
	virtual HANDLE	GetProcessHandle(void) = NULL;

	/** This method returns the ModDLL handle
	* @return	ModDLL handle
	* @usable	Outgame only
	*/
	virtual HMODULE	GetModModuleHandle(void) = NULL;
} G2EXT_END_INTERFACE_DECLARATION(ICoreOutgame);

//////////////////////////////////////////////////////////////////////////

#endif  //__API_G2EXT_CORE_H__