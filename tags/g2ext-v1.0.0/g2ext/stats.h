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

#ifndef __G2EXT_STATISTICS_H__
#define __G2EXT_STATISTICS_H__

#include "common/osheader.h"
#include "singleton.h"
#include "psapi.h"

#include "api/stats.h"
#include "api/g2/macros.h"

class zCView;

typedef struct _RENDERERSTATISTICS
{
	int nTextureMemoryUsed;
	int nTextureMemoryFetched;
	int nTexturesFetched;
	int nTexturesUsed;
	int nLightmapsUsed;
	int nPolys;
	int nTris;
	int nAlphaPolys;
	int nAlphaPolyBatches;
} RENDERERSTATISTICS;

class CRendererStatistics
{
public:
	//.text:00652AB0 ; public: virtual void __thiscall zCRnd_D3D::GetStatistics(struct zTRnd_Stats &)	
	void GetStatistics(RENDERERSTATISTICS& stats)	
	{
		XCALL(0x00652AB0);
	};

	static CRendererStatistics* GetInstance()
	{
		return *(CRendererStatistics**)0x00982F08;
	};
};

class CStatistics : public IStatistics, public TSingleton<CStatistics>
{
private:

	DWORD		m_dwFPS;
	DWORD		m_dwMinFPS;
	DWORD		m_dwMaxFPS;
	DWORD		m_dwAvgFPS;
	DWORD		m_dwFrames;
	DWORD		m_dwAlphaPolys;
	DWORD		m_dwPolys;
	DWORD		m_dwTris;
	DWORD		m_dwCpuUsage;
	DWORD		m_dwTotalMemoryUsage;
	DWORD		m_tElapsedTime;
private:	
	bool		m_bEnabled;
	bool		m_bVisible;
	zCView*		m_pScreen;

	HANDLE					m_hProcess;
	PROCESS_MEMORY_COUNTERS m_sProcessMemoryCounters;
	MEMORYSTATUS			m_sMemStatus;

	FILETIME m_ftPrevSysKernel;
	FILETIME m_ftPrevSysUser;

	FILETIME m_ftPrevProcKernel;
	FILETIME m_ftPrevProcUser;
	
	volatile LONG m_lRunCount;
public:
	CStatistics(void);

	void	Init(void);

	void	Tick(void);
	void	Reset(void);

	void	Start(void)				{ this->m_bEnabled = true; };
	void	Stop(void)				{ this->m_bEnabled = false; };
	bool	IsActive(void)			{ return this->m_bEnabled; };

	void	Show(void);
	void	Hide(void);
	bool	IsVisible(void)			{ return this->m_bVisible; };

	DWORD	GetFPS(void)			{ return this->m_dwFPS; };
	DWORD	GetMinFPS(void)			{ return this->m_dwMinFPS; };
	DWORD	GetMaxFPS(void)			{ return this->m_dwMaxFPS; };
	DWORD	GetAverageFPS(void)		{ return this->m_dwAvgFPS; };
	DWORD	GetFrameCount(void)		{ return this->m_dwFrames; };
	DWORD	GetAlphaPolyCount(void)	{ return this->m_dwAlphaPolys; };
	DWORD	GetPolyCount(void)		{ return this->m_dwPolys; };
	DWORD	GetTriangleCount(void)	{ return this->m_dwTris; };
	DWORD	GetElapsedTime(void)	{ return this->m_tElapsedTime; };

	DWORD	GetProcessorLoad(void)			{ return this->m_dwCpuUsage; };
	DWORD	GetUsedMemorySize(void)			{ return this->m_dwTotalMemoryUsage/1024; };

	DWORD	GetGlobalMemoryLoad(void)			{ return this->m_sMemStatus.dwMemoryLoad; };
	DWORD	GetGlobalPhysicalMemorySize(void)	{ return this->m_sMemStatus.dwTotalPhys/1024; };
	DWORD	GetGlobalPageFileSize(void)			{ return this->m_sMemStatus.dwTotalPageFile/1024; };
	DWORD	GetGlobalUsedPhysicalMemory(void)	{ return (this->m_sMemStatus.dwTotalPhys - this->m_sMemStatus.dwAvailPhys)/1024; };
	DWORD	GetGlobalUsedPageFile(void)			{ return (this->m_sMemStatus.dwTotalPageFile - this->m_sMemStatus.dwAvailPageFile)/1024; };
private:
	__inline ULONGLONG SubtractTimes(const FILETIME& ftA, const FILETIME& ftB)
	{
		LARGE_INTEGER a, b;
		a.LowPart = ftA.dwLowDateTime;
		a.HighPart = ftA.dwHighDateTime;

		b.LowPart = ftB.dwLowDateTime;
		b.HighPart = ftB.dwHighDateTime;

		return a.QuadPart - b.QuadPart;
	};
};

#endif  //__G2EXT_STATISTICS_H__