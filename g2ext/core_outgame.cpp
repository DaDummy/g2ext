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

#include "common/version.h"

#include "core.h"
#include "sysinfo.h"
#include "log.h"
#include "injection.h"
#include "injection_code.h"

#include <map>

HRESULT CCoreOutgame::Init(PMODINFO pModInfo)
{
	this->m_lpwCMD = L" ";

	if((this->m_pModInfo = pModInfo) == NULL)
	{
		G2EXT_LOG_CRITICAL(L"Bad MODINFO");
	};

	this->m_pLog = CLog::GetInstance();

	G2EXT_LOG_NONE(L"G2Ext :: outgame log");
	G2EXT_LOG_NONE(G2EXT_VERSIONW);
	G2EXT_LOG_DIVIDE();

	CSysInfo* pSysInfo = new CSysInfo();
	pSysInfo->Init();

	for(DWORD i = 0; i < pSysInfo->GetCPUCount(); i++)
	{
		G2EXT_LOGF_NONE(L"CPU [%d]: %s", i, pSysInfo->GetCPUInfo().wcModel);
		G2EXT_LOGF_NONE(L"CPU [%d]: Speed: ~%d mhz L1: %d L2: %d L3: %d", i, pSysInfo->GetCPUInfo().dwSpeed, pSysInfo->GetCPUInfo().dwL1, pSysInfo->GetCPUInfo().dwL2, pSysInfo->GetCPUInfo().dwL3);
	};

	for(DWORD i = 0; i < pSysInfo->GetGPUCount(); i++)
	{
		G2EXT_LOGF_NONE(L"GPU [%d]: %s", i, pSysInfo->GetGPUInfo(i)->wcModel);
	};

	G2EXT_LOGF_NONE(L"MEM : Physical: %d MB Swap: %d MB", pSysInfo->GetTotalPhysicalSystemMemory(), pSysInfo->GetTotalSystemSwapMemory());
	G2EXT_LOGF_NONE(L"OS : %s", pSysInfo->GetOSNameString());

	this->m_pLog->Divider();

	return S_OK;
};

void CCoreOutgame::Release(void)
{
	if(this->m_pModHandle)
	{
		FreeModule(this->m_pModHandle);
		this->m_pModHandle = NULL;
	};

	this->m_pModInfo = NULL;
	this->m_pLog = NULL;
};

HRESULT CCoreOutgame::Run(void)
{
	PROCESS_INFORMATION	pi;
	STARTUPINFO			si;
	bool				bHasModDll = this->LoadModDll(this->m_pModInfo->lpwDLL);

	//////////////////////////////////////////////////////////////////////////

	ZeroMemory(&si, sizeof(STARTUPINFO));

	si.cb			= sizeof(STARTUPINFO);
	si.dwFlags		= STARTF_USESHOWWINDOW;
	si.wShowWindow	= SW_SHOW;

	G2EXT_LOGF_DEBUG(L"CMD: %s", this->m_lpwCMD);

	DWORD dwFlags = 0;

	if(CreateProcessW(NULL, (LPWSTR)this->m_lpwCMD, NULL, NULL, false, CREATE_SUSPENDED, NULL, NULL, &si, &pi) == 0)
	{
		G2EXT_LOG_CRITICAL(L"Execution of Gothic II failed!");
	};

	if(!bHasModDll)
	{
		G2EXT_LOG_WARNING(L"No G2Ext mod dll found! Assuming non-G2Ext mod.");

		ResumeThread(pi.hThread);

		int iStatus;

		while((GetExitCodeProcess(pi.hProcess, (LPDWORD)&iStatus) != false) && iStatus == STILL_ACTIVE)
		{
			Sleep(1000);
		};

		return S_OK;
	};

	//////////////////////////////////////////////////////////////////////////

	this->m_hProcess = pi.hProcess;

	CInjection* inj_basic_init			= this->NewInjection("inj_basic_init");
	CInjection* inj_basic_strings		= this->NewInjection("inj_basic_strings");
	CInjection* inj_basic_mod_shared	= this->NewInjection("inj_basic_mod_shared");
	CInjection* inj_basic_int_shared	= this->NewInjection("inj_basic_int_shared");

	std::map<int, ptr_t> inj_adr = inj_basic_init_code();
	std::map<int, ptr_t> inj_strings_offset;
	std::map<int, ptr_t> inj_int_shared_offset;

	if ((inj_basic_init->Add((ptr_t)inj_adr[0], ((size_t)inj_adr[1] - (size_t)inj_adr[0]))) == G2EXT_INVALID_OFFSET)
		G2EXT_LOG_CRITICAL(L"INJECTION #E-0-1");
	if ((inj_strings_offset[0] = inj_basic_strings->Add(L"g2ext.dll")) == G2EXT_INVALID_OFFSET)
		G2EXT_LOG_CRITICAL(L"INJECTION #E-0-2");
	if ((inj_strings_offset[1] = inj_basic_strings->Add(L"G2Ext_Run")) == G2EXT_INVALID_OFFSET)
		G2EXT_LOG_CRITICAL(L"INJECTION #E-0-3");
	if ((inj_strings_offset[2] = inj_basic_strings->Add((ptr_t)this->m_pModInfo->lpwDLL, (wcslen(this->m_pModInfo->lpwDLL) + 1) * sizeof(wchar_t))) == G2EXT_INVALID_OFFSET)
		G2EXT_LOG_CRITICAL(L"INJECTION #E-0-4");
	if ((inj_strings_offset[3] = inj_basic_strings->Add((ptr_t)this->m_pModInfo->lpwModIni, (wcslen(this->m_pModInfo->lpwModIni) + 1) * sizeof(wchar_t))) == G2EXT_INVALID_OFFSET)
		G2EXT_LOG_CRITICAL(L"INJECTION #E-0-5");
	if ((inj_strings_offset[4] = inj_basic_strings->Add((ptr_t)this->m_pModInfo->lpwPlugins, (wcslen(this->m_pModInfo->lpwPlugins) + 1) * sizeof(wchar_t))) == G2EXT_INVALID_OFFSET)
		G2EXT_LOG_CRITICAL(L"INJECTION #E-0-6");
	if ((inj_strings_offset[5] = inj_basic_strings->Add((ptr_t)this->m_pModInfo->lpwCMD, (wcslen(this->m_pModInfo->lpwCMD) + 1) * sizeof(wchar_t))) == G2EXT_INVALID_OFFSET)
		G2EXT_LOG_CRITICAL(L"INJECTION #E-0-7");

	//////////////////////////////////////////////////////////////////////////

	MODINFO tmp_mi;
	tmp_mi.szSize		= sizeof(tmp_mi);
	tmp_mi.lpwDLL		= (LPCWSTR)	0x11111100;
	tmp_mi.lpwModIni	= (LPCWSTR)	0x11111101;
	tmp_mi.lpwPlugins	= (LPCWSTR)	0x11111102;
	tmp_mi.lpwCMD		= (LPCWSTR)	0x11111103;
	tmp_mi.lpIntShared	= (void*)	0x111111F0;
	tmp_mi.lpModShared	= (void*)	0x111111F1;
	tmp_mi.dwFlags		= this->m_pModInfo->dwFlags;

	if((inj_int_shared_offset[0] = inj_basic_int_shared->Add((ptr_t)&tmp_mi, sizeof(tmp_mi))) == G2EXT_INVALID_OFFSET)
		G2EXT_LOG_CRITICAL(L"INJECTION #E-0-6");
	
	//////////////////////////////////////////////////////////////////////////

	if (!inj_basic_init->Finish( NULL, PAGE_EXECUTE_READ ))
		G2EXT_LOG_CRITICAL(L"INJECTION #E-1-1");
	if (!inj_basic_strings->Finish( NULL, PAGE_READONLY ))
		G2EXT_LOG_CRITICAL(L"INJECTION #E-1-2");

	if (!inj_basic_init->SnrPTR(0, 0x11111111, inj_basic_strings->GetDest() + inj_strings_offset[0], NULL))
		G2EXT_LOG_CRITICAL(L"INJECTION #E-2-1");
	if (!inj_basic_init->SnrPTR(inj_adr[2] - inj_adr[0], 0x11111111, inj_basic_strings->GetDest() + inj_strings_offset[1], NULL ))
		G2EXT_LOG_CRITICAL(L"INJECTION #E-2-2");
	if (!inj_basic_int_shared->SnrPTR(inj_int_shared_offset[0] + offsetof(MODINFO, lpwDLL), 0x11111100, inj_basic_strings->GetDest() + inj_strings_offset[2], NULL))
		G2EXT_LOG_CRITICAL(L"INJECTION #E-2-3");
	if (!inj_basic_int_shared->SnrPTR(inj_int_shared_offset[0] + offsetof(MODINFO, lpwModIni), 0x11111101, inj_basic_strings->GetDest() + inj_strings_offset[3], NULL))
		G2EXT_LOG_CRITICAL(L"INJECTION #E-2-4");
	if (!inj_basic_int_shared->SnrPTR(inj_int_shared_offset[0] + offsetof(MODINFO, lpwPlugins), 0x11111102, inj_basic_strings->GetDest() + inj_strings_offset[4], NULL))
		G2EXT_LOG_CRITICAL(L"INJECTION #E-2-5");
	if (!inj_basic_int_shared->SnrPTR(inj_int_shared_offset[0] + offsetof(MODINFO, lpwCMD), 0x11111103, inj_basic_strings->GetDest() + inj_strings_offset[5], NULL))
		G2EXT_LOG_CRITICAL(L"INJECTION #E-2-6");

	if (!this->CreateJumpInjection("inj_basic_init_jmp", 0x00502DEC, 8, inj_basic_init->GetDest()))
		this->m_pLog->Write(LOG_ERROR, L"INJECTION #E-3-1");

	G2EXT_LOG_DEBUG(L"Code prepared.");

	//////////////////////////////////////////////////////////////////////////

	if(this->ModPrepare)
	{
		G2EXT_LOG_NONE(L"Calling G2Ext_ModPrepare function...");
		this->ModPrepare(this);
	};

	//////////////////////////////////////////////////////////////////////////

	G2EXT_LOG_DEBUG(L"Finalizing injection code...");

	if(inj_basic_mod_shared->GetLength() != 0)
	{
		if (!inj_basic_mod_shared->Finish(NULL, PAGE_READWRITE))
			this->m_pLog->Write(LOG_CRITICAL, L"INJECTION #E-4-1");
	};

	if (!inj_basic_int_shared->Finish( NULL, PAGE_READWRITE ))
		this->m_pLog->Write(LOG_CRITICAL, L"INJECTION #E-4-2");

	if (!inj_basic_int_shared->SnrPTR( inj_int_shared_offset[0] + offsetof(MODINFO,lpIntShared), 0x111111F0, inj_basic_int_shared->GetDest(), NULL))
		this->m_pLog->Write(LOG_CRITICAL, L"INJECTION #E-5-1");
	if (!inj_basic_int_shared->SnrPTR( inj_int_shared_offset[0] + offsetof(MODINFO,lpModShared), 0x111111F1, inj_basic_mod_shared->GetDest(), NULL))
		this->m_pLog->Write(LOG_CRITICAL, L"INJECTION #E-5-2");
	if (!inj_basic_init->SnrPTR( inj_adr[3] - inj_adr[0], 0x11111111, inj_basic_int_shared->GetDest() + inj_int_shared_offset[0], NULL))
		this->m_pLog->Write(LOG_CRITICAL, L"INJECTION #E-5-3");

	G2EXT_LOG_DEBUG(L"done");

	G2EXT_LOG_DEBUG(L"Injecting code...");

	inj_basic_init			= NULL;
	inj_basic_strings		= NULL;
	inj_basic_mod_shared	= NULL;
	inj_basic_int_shared	= NULL;

	for each(CInjection* inj in this->m_lstInjections)
	{
		G2EXT_LOG_DEBUG(cwcs(L"Injection '", strtowcs(inj->GetName().c_str()), L"'"));

		if(!inj->Write())
		{
			G2EXT_LOGF_CRITICAL(L"INJECTION #E-6 Dest: 0x%p Tmp: 0x%p Length:%u Name:%s", inj->GetDest(), inj->GetTmp(), inj->GetLength());
		};

		delete inj;
	};

	this->m_lstInjections.clear();

	G2EXT_LOG_DEBUG(L"done");

	//////////////////////////////////////////////////////////////////////////

	ResumeThread( pi.hThread );

	int iStatus;

	while ((GetExitCodeProcess( pi.hProcess, (LPDWORD)&iStatus) != false) && iStatus == STILL_ACTIVE)
	{
		Sleep(1000);
	};

	//////////////////////////////////////////////////////////////////////////

	this->Release();

	return S_OK;
};

bool CCoreOutgame::LoadModDll(LPCWSTR lpwFileName)
{
	if((lpwFileName == L"") || (lpwFileName == NULL))
	{	
		G2EXT_LOGF_NONE(L"No mod-dll specified. Loading without G2Ext.");
		return false;
	};

	G2EXT_LOG_NONE(L"Loading mod-dll...");

	if((this->m_pModHandle = LoadLibraryA(wcstostr(lpwFileName))) == NULL)
	{
		return false;
	};

	if((this->ModCheckVersion = reinterpret_cast<G2EXT_MOD_VERSIONCHK_FUNC>(GetProcAddress(this->m_pModHandle, "G2Ext_ModVersion"))) == NULL)
	{
		G2EXT_LOG_CRITICAL(L"Could not determine version of mod.");
	};

	int				nVersionMajor = 0;
	int				nVersionMinor = 0;
	G2EXT_DLL_TYPE	extDllType	  = G2EXT_DLL_MOD;

	this->ModCheckVersion(nVersionMajor, nVersionMinor, extDllType);

	if(nVersionMajor < G2EXT_MAJOR_VERSION || nVersionMinor < G2EXT_MINOR_VERSION)
	{
		G2EXT_LOGF_CRITICAL(L"Version mismatch! G2Ext: %i.%i Mod: %i.%i", G2EXT_MAJOR_VERSION, G2EXT_MINOR_VERSION, nVersionMajor, nVersionMinor);
	};

	if(extDllType != G2EXT_DLL_MOD)
	{
		G2EXT_LOGF_CRITICAL(L"Incompatible mod type!");
	};

	G2EXT_LOG_NONE(L"Version check passed.");

	if((this->ModPrepare = reinterpret_cast<G2EXT_MOD_PREPARE_FUNC>(GetProcAddress(this->m_pModHandle, "G2Ext_ModPrepare"))) == NULL)
	{
		G2EXT_LOG_NONE(L"G2Ext_ModPrepare not found. Ignoring.");
	};

	if((this->ModInit = reinterpret_cast<G2EXT_MOD_INIT_FUNC>(GetProcAddress(this->m_pModHandle, "G2Ext_ModInit"))) == NULL)
	{
		G2EXT_LOG_CRITICAL(L"G2Ext_ModInit not found.");
	};

	return true;
};

bool CCoreOutgame::CreateJumpInjection(const char* lpName, ptr_t lpCodePtr, size_t sCodeLength, ptr_t lpTarget)
{
	CInjection*				inj;
	std::map<int, ptr_t>	inj_adr		= inj_t_jmp_code();
	size_t					sCurrLength	= inj_adr[1] - inj_adr[0];

	if (sCurrLength > sCodeLength)
		return false;

	inj = this->NewInjection(lpName);

	if (inj == NULL)
		return false;

	if (inj->Add(inj_adr[0], sCurrLength) == G2EXT_INVALID_OFFSET)
	{
		delete inj;
		return false;
	};

	while(sCurrLength < sCodeLength)
	{
		if (inj->Add( (uint8_t)0x90 ) == G2EXT_INVALID_OFFSET)
		{
			delete inj;
			return false;
		};

		sCurrLength++;
	};

	if (!inj->Finish(lpCodePtr))
	{
		delete inj;
		return false;
	};

	return inj->SnrPTR( 0, 0x11111111, lpTarget, NULL );
};

bool CCoreOutgame::CreateCallInjection( const char* lpName, ptr_t lpCodePtr, size_t sCodeLength, ptr_t lpTarget )
{
	CInjection*				inj;
	std::map<int, ptr_t>	inj_adr		= inj_t_jmp_code();
	size_t					sCurrLength	= inj_adr[1] - inj_adr[0];

	if (sCurrLength > sCodeLength)
		return false;

	inj = this->NewInjection(lpName);

	if (inj == NULL)
		return false;

	if (inj->Add(inj_adr[0], sCurrLength) == G2EXT_INVALID_OFFSET)
	{
		delete inj;
		return false;
	};

	while(sCurrLength < sCodeLength)
	{
		if(inj->Add((uint8_t)0x90) == G2EXT_INVALID_OFFSET)
		{
			delete inj;
			return false;
		}

		sCurrLength++;
	};

	if (!inj->Finish(lpCodePtr))
	{
		delete inj;
		return false;
	};

	return inj->SnrPTR(0, 0x11111111, lpTarget, NULL);
};

CInjection* CCoreOutgame::NewInjection(const char* lpName)
{
	CInjection* inj = new CInjection(m_hProcess, lpName);

	this->m_lstInjections.push_back(inj);

	return (CInjection*)inj;
};