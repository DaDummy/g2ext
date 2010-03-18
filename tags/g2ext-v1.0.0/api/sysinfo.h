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

#ifndef __G2EXT_SYSINFO_H__
#define __G2EXT_SYSINFO_H__

#include "common/osheader.h"
#include "api/interface.h"

/** Insert description. */
enum SYSINFO_CPU_MANF
{
	CPU_MANF_INTEL	= 0x8086,
	CPU_MANF_AMD	= 0x1022,
	CPU_MANF_VIA	= 0x1106,
	CPU_MANF_CYRIX	= 0x1078
};

/** Insert description. */
enum SYSINFO_GPU_MANF
{
	GPU_MANF_INTEL	= 0x8086,
	GPU_MANF_ATI	= 0x1002,
	GPU_MANF_NVIDIA	= 0x10DE,
	GPU_MANF_VIA	= 0x1106,
	GPU_MANF_3DFX	= 0x121A,
	GPU_MANF_S3		= 0x5333
};

/** Insert description. */
typedef struct _SYSINFO_VIDEO
{
	wchar_t				wcModel[100];
	wchar_t				wcDriver[100];

	DWORD				dwMemTotal;
	DWORD				dwMemAdapter;
	DWORD				dwMemShared;

	DWORD				dwVendorid;
	DWORD				dwDeviceid;
	DWORD				dwSubsysid;
	DWORD				dwRevision;

	HMONITOR			hMonitor;
	wchar_t				wcDeviceName[32];
} SYSINFO_VIDEO, *PSYSINFO_VIDEO;

/** Insert description. */
typedef struct _SYSINFO_CPU
{
	wchar_t				wcModel[49];
	DWORD				dwSpeed;
	SYSINFO_CPU_MANF	manfManufacturer;

	DWORD				dwL1;
	DWORD				dwL2;
	DWORD				dwL3;

	bool				bFPU;
	bool				bMMX;
	bool				bMMXExt;
	bool				b3DNow;
	bool				b3DNow2;
	bool				bHTT;
	bool				bNX;
	bool				bSSE;
	bool				bSSE2;
	bool				bSSE3;
	bool				bSSSE3;  // Intel/VIA Nano
	bool				bSSE4_1; // Intel
	bool				bSSE4_2; // Intel
	bool				bSSE4a;  // AMD
	bool				bEST;    // Intel
	bool				bIA64;   // Intel Itanium
} SYSINFO_CPU, *PSYSINFO_CPU;

/** Insert description. */
G2EXT_BEGIN_INTERFACE_DECLARATION(ISysInfo)
	bool GetIs64BitOS(void) = NULL;
	bool GetCPUSupportsFPU(void) = NULL;
	bool GetCPUSupportsMMX(void) = NULL;
	bool GetCPUSupportsMMXExt(void) = NULL;
	bool GetCPUSupports3DNow(void) = NULL;
	bool GetCPUSupports3DNow2(void) = NULL;
	bool GetCPUSupportsHyperThreading(void) = NULL;
	bool GetCPUSupportsNXBit(void) = NULL;
	bool GetCPUSupportsSSE(void) = NULL;
	bool GetCPUSupportsSSE2(void) = NULL;
	bool GetCPUSupportsSSE3(void) = NULL;
	bool GetCPUSupportsSSSE3(void) = NULL;
	bool GetCPUSupportsSSE4_1(void) = NULL;
	bool GetCPUSupportsSSE4_2(void) = NULL;
	bool GetCPUSupportsSSE4a(void) = NULL;
	DWORD GetCPUCacheSizeL1(void) = NULL;
	DWORD GetCPUCacheSizeL2(void) = NULL;
	DWORD GetCPUCacheSizeL3(void) = NULL;
	DWORD GetTotalPhysicalSystemMemory(void) = NULL;
	DWORD GetTotalSystemSwapMemory(void) = NULL;
	LPCWSTR GetOSNameString(void) = NULL;
	DWORD GetCPUCount(void) = NULL;
	SYSINFO_CPU GetCPUInfo(void) = NULL;
	SYSINFO_CPU_MANF GetCPUManufacturer(void) = NULL;
	DWORD GetGPUCount(void) = NULL;
	SYSINFO_VIDEO* GetGPUInfo(DWORD dwID = 0) = NULL;
	SYSINFO_GPU_MANF GetGPUManufacturer(DWORD dwID = 0) = NULL;
G2EXT_END_INTERFACE_DECLARATION(ISysInfo)

#endif  //__G2EXT_SYSINFO_H__