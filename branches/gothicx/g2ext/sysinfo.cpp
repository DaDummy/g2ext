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

// - http://softpixel.com/~cwright/programming/simd/cpuid.php
// - http://msdn.microsoft.com/en-us/library/hskdteyh(VS.80).aspx
// - http://www.amd.com/us-en/assets/content_type/white_papers_and_tech_docs/25481.pdf
// - http://www.intel.com/Assets/PDF/appnote/241618.pdf

#include "sysinfo.h"
#include "log.h"

#include "dx9sdk/inc/d3d9.h"
#pragma comment(lib, "d3d9.lib")

#pragma warning(disable:4700)

__inline bool CSysInfo::CPUID(PSYSINFO_CPUID _info, const UINT32 _function)
{
	__try
	{
		__asm
		{
			mov edx, _info
			mov eax, _function
			push edi
			push ebx
			mov  edi, edx
			cpuid
			mov DWORD PTR [edi], eax
			mov DWORD PTR [edi+4], ebx
			mov DWORD PTR [edi+8], ecx
			mov DWORD PTR [edi+12], edx
			pop ebx
			pop edi
		};
	}
	__except(0)
	{
		return false;
	};

	return true;
};

void CSysInfo::Init()
{
	if(FAILED(this->GatherCPUInfos()))		G2EXT_LOG_WARNING(L"Could not gather CPU informations!");
	if(FAILED(this->GatherGPUInfos()))		G2EXT_LOG_WARNING(L"Could not gather graphics device informations!");
	if(FAILED(this->GatherMemoryInfos()))	G2EXT_LOG_WARNING(L"Could not gather system memory informations!");
	if(FAILED(this->GatherOSInfos()))		G2EXT_LOG_WARNING(L"Could not gather OS informations!");
};

void CSysInfo::Release()
{
	// --
};

HRESULT CSysInfo::GatherCPUInfos()
{
	SYSTEM_INFO si = {0};
	GetSystemInfo(&si);

	SYSINFO_CPUID cpuidinfo = {0};

	ZeroMemory(&this->siCPUInfos, sizeof(SYSINFO_CPU));

	if((this->dwCPUCount = si.dwNumberOfProcessors) == 0)
		return E_FAIL; // -- this should never happen

	if(!CSysInfo::CPUID(&cpuidinfo, 0x00000000))
		return E_FAIL;

	char vendor[13] = {0};
	*(int*)&vendor[0] = cpuidinfo.ebx;
	*(int*)&vendor[4] = cpuidinfo.edx;
	*(int*)&vendor[8] = cpuidinfo.ecx;

	if(strcmp(vendor, "GenuineIntel") == NULL)
		this->siCPUInfos.manfManufacturer = CPU_MANF_INTEL;
	else
		if(strcmp(vendor, "AuthenticAMD") == NULL)
			this->siCPUInfos.manfManufacturer = CPU_MANF_AMD;
		else
			if(strcmp(vendor, "Geode by NSC") == NULL)
				this->siCPUInfos.manfManufacturer = CPU_MANF_AMD;
			else
				if(strcmp(vendor, "CentaurHauls") == NULL)
					this->siCPUInfos.manfManufacturer = CPU_MANF_VIA;
				else
					if(strcmp(vendor, "CyrixInstead") == NULL)
						this->siCPUInfos.manfManufacturer = CPU_MANF_CYRIX;

	CSysInfo::CPUID(&cpuidinfo, 0x80000000);

	if(cpuidinfo.eax >= 0x80000004)
	{
		char model[49] = {0};

		CSysInfo::CPUID(&cpuidinfo, 0x80000002);
		*(int*)&model[0]	= cpuidinfo.eax;
		*(int*)&model[4]	= cpuidinfo.ebx;
		*(int*)&model[8]	= cpuidinfo.ecx;
		*(int*)&model[12]	= cpuidinfo.edx;
		CSysInfo::CPUID(&cpuidinfo, 0x80000003);
		*(int*)&model[16]	= cpuidinfo.eax;
		*(int*)&model[20]	= cpuidinfo.ebx;
		*(int*)&model[24]	= cpuidinfo.ecx;
		*(int*)&model[28]	= cpuidinfo.edx;
		CSysInfo::CPUID(&cpuidinfo, 0x80000004);
		*(int*)&model[32]	= cpuidinfo.eax;
		*(int*)&model[36]	= cpuidinfo.ebx;
		*(int*)&model[40]	= cpuidinfo.ecx;
		*(int*)&model[44]	= cpuidinfo.edx;

		model[48] = 0; // -- null termination

		for(int j = (int)strlen(model)-1; j >= 0; --j)
		{
			if(model[j] == ' ')
			{
				model[j] = '\0';
			}
			else
			{
				break;
			};
		};

		ZeroMemory(&this->siCPUInfos.wcModel, 49);
		wcscpy_s((LPWSTR)this->siCPUInfos.wcModel, 48, strtowcs(model));
	};

	// -- CPU L1 Cache Size
	CSysInfo::CPUID(&cpuidinfo, 0x80000005);
	this->siCPUInfos.dwL1 = (cpuidinfo.ecx>>24);

	// -- CPU L2 Cache Size
	CSysInfo::CPUID(&cpuidinfo, 0x80000006);
	this->siCPUInfos.dwL2 = (cpuidinfo.ecx>>16);

	// -- CPU L3 Cache Size
	CSysInfo::CPUID(&cpuidinfo, 0x80000006);
	this->siCPUInfos.dwL3 = (cpuidinfo.edx>>18);

	// -- CPU FPU
	CSysInfo::CPUID(&cpuidinfo, 0x00000001);
	this->siCPUInfos.bFPU = ((cpuidinfo.edx & (1<<0)) != 0) ? true : false;

	// -- CPU MMX
	CSysInfo::CPUID(&cpuidinfo, 0x00000001);
	this->siCPUInfos.bMMX = ((cpuidinfo.edx & (1<<23)) != 0) ? true : false;

	// -- CPU SSE
	CSysInfo::CPUID(&cpuidinfo, 0x00000001);
	this->siCPUInfos.bSSE = ((cpuidinfo.edx & (1<<25)) != 0) ? true : false;

	// -- CPU SSE2
	CSysInfo::CPUID(&cpuidinfo, 0x00000001);
	this->siCPUInfos.bSSE2 = ((cpuidinfo.edx & (1<<26)) != 0) ? true : false;

	// -- CPU HTT
	CSysInfo::CPUID(&cpuidinfo, 0x00000001);
	this->siCPUInfos.bHTT = ((cpuidinfo.edx & (1<<28)) != 0) ? true : false;

	// -- CPU NX BIT
	CSysInfo::CPUID(&cpuidinfo, 0x80000001);
	this->siCPUInfos.bNX = ((cpuidinfo.edx & (1<<20)) != 0) ? true : false;

	// -- AMD specific extensions
	if(this->siCPUInfos.manfManufacturer == CPU_MANF_AMD)
	{
		// -- CPU MMXEXT
		CSysInfo::CPUID(&cpuidinfo, 0x80000001);
		this->siCPUInfos.bMMXExt = ((cpuidinfo.edx & (1<<22)) != 0) ? true : false;

		// -- CPU 3DNOW!
		CSysInfo::CPUID(&cpuidinfo, 0x80000001);
		this->siCPUInfos.b3DNow = ((cpuidinfo.edx & (1<<30)) != 0) ? true : false;

		// -- CPU 3DNOW!2
		CSysInfo::CPUID(&cpuidinfo, 0x80000001);
		this->siCPUInfos.b3DNow2 = ((cpuidinfo.edx & (1<<31)) != 0) ? true : false;

		// -- CPU SSE3
		CSysInfo::CPUID(&cpuidinfo, 0x00000001);
		this->siCPUInfos.bSSE3 = ((cpuidinfo.ecx & (1<<0)) != 0) ? true : false;

		// -- CPU SSE4a
		CSysInfo::CPUID(&cpuidinfo, 0x00000001);
		this->siCPUInfos.bSSE4a = ((cpuidinfo.ecx & (1<<6)) != 0) ? true : false;
	};

	// -- Intel specific extensions
	if(this->siCPUInfos.manfManufacturer == CPU_MANF_INTEL)
	{
		// -- CPU EST (Enhanced Intel(R) SpeedStep(R) Technology)
		CSysInfo::CPUID(&cpuidinfo, 0x80000001);
		this->siCPUInfos.bEST = ((cpuidinfo.ecx & (1<<7)) != 0) ? true : false;

		// -- CPU IA64 (64bit Intel(R) Itanium(R))
		CSysInfo::CPUID(&cpuidinfo, 0x00000001);
		this->siCPUInfos.bIA64 = ((cpuidinfo.edx & (1<<30)) != 0) ? true : false;

		// -- CPU SSSE3
		CSysInfo::CPUID(&cpuidinfo, 0x80000001);
		this->siCPUInfos.bSSSE3 = ((cpuidinfo.ecx & (1<<9)) != 0) ? true : false;

		// -- CPU SSE 4.1
		CSysInfo::CPUID(&cpuidinfo, 0x00000001);
		this->siCPUInfos.bSSE4_1 = ((cpuidinfo.ecx & (1<<19)) != 0) ? true : false;

		// -- CPU SSE 4.2
		CSysInfo::CPUID(&cpuidinfo, 0x00000001);
		this->siCPUInfos.bSSE4_2 = ((cpuidinfo.ecx & (1<<20)) != 0) ? true : false;	
	};

	// -- CPU Speed

	HKEY hKey = NULL;

	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0\\", 0, KEY_QUERY_VALUE, &hKey) != ERROR_SUCCESS)
		return E_FAIL;

	DWORD dwLen = 4;
	if(RegQueryValueEx(hKey, L"~MHz", NULL, NULL, (LPBYTE)&this->siCPUInfos.dwSpeed, &dwLen) != ERROR_SUCCESS)
	{
		RegCloseKey(hKey);
		return E_FAIL;
	};

	RegCloseKey(hKey);

	return S_OK;
};

HRESULT CSysInfo::GatherOSInfos()
{
	OSVERSIONINFOEX osvi = {0};
	SYSTEM_INFO si = {0};

	GetSystemInfo(&si);

	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

	GetVersionEx((OSVERSIONINFO*)&osvi);

	if((osvi.dwMajorVersion == 5) && (osvi.dwMinorVersion == 0)) // Win 2000
	{
		if(osvi.wSuiteMask && VER_NT_SERVER)
		{	
			this->lpwOSName = L"Windows 2000 Server";
		}
		else 
		{	
			this->lpwOSName = L"Windows 2000";
		};
	}
	else
	if((osvi.dwMajorVersion == 5) && (osvi.dwMinorVersion == 1)) // Win XP
	{
		if(osvi.wSuiteMask && VER_SUITE_PERSONAL)
		{		
			this->lpwOSName = L"Windows XP Home Edition";
		}
		else
		{
			this->lpwOSName = L"Windows XP Professional";
		};
	}
	else
	if((osvi.dwMajorVersion == 5) && (osvi.dwMinorVersion == 2)) // Win 2003/XP x64
	{
		if((osvi.wProductType == VER_NT_WORKSTATION) && (osvi.dwPlatformId == PROCESSOR_ARCHITECTURE_AMD64))
		{
			this->lpwOSName = L"Windows XP x64 Edition";
			this->bIs64BitOS = true;
		}
		else 
		if(si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
		{
			this->lpwOSName = L"Windows Server 2003";
			this->bIs64BitOS = true;
		}
		else
		{		
			this->lpwOSName = L"Windows Server 2003";
		};
	}
	else
	if((osvi.dwMajorVersion == 6) && (osvi.dwMinorVersion == 0)) // Win Vista/Server 2008
	{
		if(osvi.wProductType == VER_NT_SERVER)
		{
			if(si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
			{
				this->lpwOSName = L"Windows Server 2008";
				this->bIs64BitOS = true;
			}
			else
			{
				this->lpwOSName = L"Windows Server 2008";
			};
		}
		else 
		if(si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
		{
			this->lpwOSName = L"Windows Vista";
			this->bIs64BitOS = true;
		}
		else
		{		
			this->lpwOSName = L"Windows Vista";
		};
	}	
	else
	if((osvi.dwMajorVersion == 6) && (osvi.dwMinorVersion == 1)) // Win 7/Server 2008 R1
	{
		if(osvi.wProductType == VER_NT_SERVER)
		{		
			if(si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
			{
				this->lpwOSName = L"Windows Server 2008 R2";
				this->bIs64BitOS = true;
			}
			else
			{
				this->lpwOSName = L"Windows Server 2008 R2";
			};
		}
		else
		{
			if(si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
			{
				this->lpwOSName = L"Windows 7";
				this->bIs64BitOS = true;
			}
			else
			{
				this->lpwOSName = L"Windows 7";
			};
		};
	}
	else
	{
		this->lpwOSName = L"Unknown OS";
	};

	return S_OK;
};

HRESULT CSysInfo::GatherGPUInfos()
{
	IDirect3D9* pD3D9 = NULL;
	pD3D9 = Direct3DCreate9(D3D_SDK_VERSION);
	if(pD3D9)
	{
		if((this->dwGPUCount = pD3D9->GetAdapterCount()) == 0)
			return E_FAIL; // should never happen

		this->pGPUInfos = new SYSINFO_VIDEO[this->dwGPUCount];

		for(UINT i = 0; i < this->dwGPUCount; i++)
		{
			ZeroMemory(&this->pGPUInfos[i], sizeof(SYSINFO_VIDEO));

			D3DADAPTER_IDENTIFIER9 id;
			ZeroMemory(&id, sizeof(D3DADAPTER_IDENTIFIER9));
			pD3D9->GetAdapterIdentifier(i, 0, &id);

			this->pGPUInfos[i].dwDeviceid = id.DeviceId;
			this->pGPUInfos[i].dwVendorid = id.VendorId;
			this->pGPUInfos[i].dwSubsysid = id.SubSysId;
			this->pGPUInfos[i].dwRevision = id.Revision;

			wcscpy_s(this->pGPUInfos[i].wcDriver, 100, strtowcs(id.Driver));
			wcscpy_s(this->pGPUInfos[i].wcModel, 100, strtowcs(id.Description));

			this->pGPUInfos[i].hMonitor = pD3D9->GetAdapterMonitor(i);

			MONITORINFOEX mi;
			mi.cbSize = sizeof(MONITORINFOEX);
			GetMonitorInfo(this->pGPUInfos[i].hMonitor, &mi);
			wcscpy_s(this->pGPUInfos[i].wcDeviceName, 32, mi.szDevice);

			// TODO: Graphics Device Memory infos
		};
	}
	else
	{
		return E_FAIL;
	};

	return S_OK;
};

HRESULT CSysInfo::GatherMemoryInfos()
{
	MEMORYSTATUS ms = {0};
	GlobalMemoryStatus(&ms);

	this->dwPhysicalMemory = (ms.dwTotalPhys / 1048576L);
	this->dwSwapMemory = (ms.dwTotalPageFile / 1048576L);

	return S_OK;
};

PSYSINFO_VIDEO CSysInfo::GetGPUInfo(DWORD dwID)
{
	if(dwID > this->dwGPUCount)
	{
		return NULL;
	};

	return &this->pGPUInfos[dwID];

};

SYSINFO_GPU_MANF CSysInfo::GetGPUManufacturer(DWORD dwID)
{
	return (SYSINFO_GPU_MANF)0x0000;
};