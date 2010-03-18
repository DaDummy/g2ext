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

#ifndef __SYSINFO_H_INCLUDED__
#define __SYSINFO_H_INCLUDED__

#include "common/osheader.h"
#include "api/g2ext.h"
#include "api/sysinfo.h"
#include "utils.h"
#include "singleton.h"

typedef struct _SYSINFO_CPUID
{
	__int32 eax, ebx, ecx, edx;
} SYSINFO_CPUID, *PSYSINFO_CPUID;

class CSysInfo : public TSingleton<CSysInfo>, public ISysInfo
{
private:
	DWORD			dwCPUCount;
	SYSINFO_CPU		siCPUInfos;
	DWORD			dwGPUCount;
	SYSINFO_VIDEO*	pGPUInfos;
	DWORD			dwPhysicalMemory;
	DWORD			dwSwapMemory;
	LPCWSTR			lpwOSName;
	bool			bIs64BitOS;
private:
	HRESULT GatherCPUInfos(void);
	HRESULT GatherGPUInfos(void);
	HRESULT GatherOSInfos(void);
	HRESULT GatherMemoryInfos(void);

	static __inline bool CPUID(PSYSINFO_CPUID _info, const UINT32 _function);
public:
	void Init(void);
	void Release(void);

	bool GetIs64BitOS(void)					{ return this->bIs64BitOS; };
	bool GetCPUSupportsFPU(void)			{ return this->siCPUInfos.bFPU; };
	bool GetCPUSupportsMMX(void)			{ return this->siCPUInfos.bMMX; };
	bool GetCPUSupportsMMXExt(void)			{ return this->siCPUInfos.bMMXExt; };
	bool GetCPUSupports3DNow(void)			{ return this->siCPUInfos.b3DNow; };
	bool GetCPUSupports3DNow2(void)			{ return this->siCPUInfos.b3DNow2; };
	bool GetCPUSupportsHyperThreading(void) { return this->siCPUInfos.bHTT; };
	bool GetCPUSupportsNXBit(void)			{ return this->siCPUInfos.bNX; };
	bool GetCPUSupportsSSE(void)			{ return this->siCPUInfos.bSSE; };
	bool GetCPUSupportsSSE2(void)			{ return this->siCPUInfos.bSSE2; };
	bool GetCPUSupportsSSE3(void)			{ return this->siCPUInfos.bSSSE3; };
	bool GetCPUSupportsSSSE3(void)			{ return this->siCPUInfos.bSSE3; };
	bool GetCPUSupportsSSE4_1(void)			{ return this->siCPUInfos.bSSE4_1; };
	bool GetCPUSupportsSSE4_2(void)			{ return this->siCPUInfos.bSSE4_2; };
	bool GetCPUSupportsSSE4a(void)			{ return this->siCPUInfos.bSSE4a; };
	DWORD GetCPUCacheSizeL1(void)			{ return this->siCPUInfos.dwL1; };
	DWORD GetCPUCacheSizeL2(void)			{ return this->siCPUInfos.dwL2; };
	DWORD GetCPUCacheSizeL3(void)			{ return this->siCPUInfos.dwL3; };
	DWORD GetTotalPhysicalSystemMemory(void){ return this->dwPhysicalMemory; };
	DWORD GetTotalSystemSwapMemory(void)	{ return this->dwSwapMemory; };
	LPCWSTR GetOSNameString(void)			{ return this->lpwOSName; };

	DWORD GetCPUCount(void)					{ return this->dwCPUCount; };
	SYSINFO_CPU GetCPUInfo(void)			{ return this->siCPUInfos; };
	SYSINFO_CPU_MANF GetCPUManufacturer(void) { return this->siCPUInfos.manfManufacturer; };

	DWORD GetGPUCount(void)					{ return this->dwGPUCount-1; };
	SYSINFO_VIDEO* GetGPUInfo(DWORD dwID = 0);
	SYSINFO_GPU_MANF GetGPUManufacturer(DWORD dwID = 0);
};

#endif //__SYSINFO_H_INCLUDED__