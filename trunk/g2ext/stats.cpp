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

#include "stats.h"
#include <limits.h>
#ifdef _G2EXT_COMPILE_SPACER
#include "api/spacer/zcview.h"
#else // _G2EXT_COMPILE_SPACER
#include "api/g2/zcview.h"
#endif // _G2EXT_COMPILE_SPACER

CStatistics::CStatistics(void)
{
	this->Reset();
};

void CStatistics::Init(void)
{
	this->Reset();

	static bool bFirstRun = true;

	if(bFirstRun)
	{
		this->m_pScreen = zNEW(zCView(0, 0, 8192, 8192, VIEW_ITEM));
		this->m_pScreen->SetFont(zSTRING("EXT_CONSOLE.TGA"));
		this->m_pScreen->SetFontColor(zCOLOR(150, 150, 150, 255));

		bFirstRun = false;
	};
};

void CStatistics::Reset(void)
{
	this->m_dwFPS				= 0;
	this->m_dwMinFPS			= 999;
	this->m_dwMaxFPS			= 0;
	this->m_dwAvgFPS			= 60;
	this->m_dwFrames			= 0;
	this->m_dwAlphaPolys		= 0;
	this->m_dwPolys				= 0;
	this->m_dwTris				= 0;
	this->m_tElapsedTime		= 0;
	this->m_dwTotalMemoryUsage	= 0;
	this->m_dwCpuUsage			= 0;
	this->m_bEnabled			= false;
	this->m_bVisible			= false;

	this->m_hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, false, GetCurrentProcessId());

	ZeroMemory(&this->m_sProcessMemoryCounters, sizeof(PROCESS_MEMORY_COUNTERS));
	this->m_sProcessMemoryCounters.cb = sizeof(PROCESS_MEMORY_COUNTERS);

	ZeroMemory(&this->m_ftPrevSysKernel, sizeof(FILETIME));
	ZeroMemory(&this->m_ftPrevSysUser, sizeof(FILETIME));

	ZeroMemory(&this->m_ftPrevProcKernel, sizeof(FILETIME));
	ZeroMemory(&this->m_ftPrevProcUser, sizeof(FILETIME));
};

void CStatistics::Tick(void)
{
	this->m_pScreen->ClrPrintwin();

	if(this->m_bEnabled)
	{
		static DWORD  dwFrames				= 0;
		static time_t tCurrentTime			= 0;
		static time_t tLastUpdateTime		= 0;
		static time_t tElapsedTime			= 0;
		static RENDERERSTATISTICS stats	= {0};

		CRendererStatistics::GetInstance()->GetStatistics(stats);

		static	time_t	lst_time	= GetTickCount();
		static	time_t	tctr500	= 0;
		time_t			cur_time	= GetTickCount();

		tctr500	+= (cur_time - lst_time);
		lst_time = cur_time;

		this->m_dwAlphaPolys	= stats.nAlphaPolys;
		this->m_dwPolys			= stats.nPolys;
		this->m_dwTris			= stats.nTris;

		this->m_dwFrames++;

		if(this->m_dwFrames == ULONG_MAX) // reset the counter whenever max. int is being reached
			this->m_dwFrames = 0;

		dwFrames++;
		tCurrentTime = GetTickCount();
		tElapsedTime = tCurrentTime - tLastUpdateTime;

		if(tElapsedTime >= 1000)
		{
			this->m_dwFPS = (UINT)(dwFrames * 1000.0 / tElapsedTime);
			dwFrames = 0;
			tLastUpdateTime = tCurrentTime;

			this->m_tElapsedTime++;
		};

		zCView::GetScreen()->RemoveItem(this->m_pScreen);
		
		if(this->m_bVisible)
		{
			zCView::GetScreen()->InsertItem(this->m_pScreen);

			static char xbuf0[25] = {0};
			static char xbuf1[25] = {0};
			static char xbuf2[25] = {0};
			static char xbuf3[25] = {0};
			static char xbuf4[25] = {0};
			static char xbuf5[25] = {0};
			static char xbuf6[25] = {0};
			static char xbuf7[25] = {0};

			sprintf_s(xbuf0, 25, "fps: %d",			this->m_dwFPS);
			if(this->m_tElapsedTime > 10)
			{
				sprintf_s(xbuf1, 25, "average fps: %d",	this->m_dwAvgFPS);
				sprintf_s(xbuf2, 25, "min fps: %d",		this->m_dwMinFPS);
				sprintf_s(xbuf3, 25, "max fps: %d",		this->m_dwMaxFPS);
			} 
			else
			{
				sprintf_s(xbuf1, 25, "average fps: ---");
				sprintf_s(xbuf2, 25, "min fps: ---");
				sprintf_s(xbuf3, 25, "max fps: ---");
			};
			sprintf_s(xbuf4, 25, "frames: %d",		this->m_dwFrames);
			sprintf_s(xbuf5, 25, "alpha polys: %d",	this->m_dwAlphaPolys);
			sprintf_s(xbuf6, 25, "polys: %d",		this->m_dwPolys);
			sprintf_s(xbuf7, 25, "tris: %d",		this->m_dwTris);
			if(this->m_dwFPS <= 23)
				this->m_pScreen->SetFontColor(zCOLOR(255, 0, 0, 255));
			else if(this->m_dwFPS <= 60)
				this->m_pScreen->SetFontColor(zCOLOR(255, 180, 0, 255));
			else if(this->m_dwFPS > 61)
				this->m_pScreen->SetFontColor(zCOLOR(0, 255, 0, 255));
			this->m_pScreen->Print(VIEW_VXMAX - (this->m_pScreen->FontSize(zSTRING(xbuf0)) + 100), this->m_pScreen->FontY(),   zSTRING(xbuf0));
			this->m_pScreen->SetFontColor(zCOLOR(255, 255, 255, 255));
			this->m_pScreen->Print(VIEW_VXMAX - (this->m_pScreen->FontSize(zSTRING(xbuf1)) + 100), this->m_pScreen->FontY()*2, zSTRING(xbuf1));
			this->m_pScreen->Print(VIEW_VXMAX - (this->m_pScreen->FontSize(zSTRING(xbuf2)) + 100), this->m_pScreen->FontY()*3, zSTRING(xbuf2));
			this->m_pScreen->Print(VIEW_VXMAX - (this->m_pScreen->FontSize(zSTRING(xbuf3)) + 100), this->m_pScreen->FontY()*4, zSTRING(xbuf3));
			this->m_pScreen->Print(VIEW_VXMAX - (this->m_pScreen->FontSize(zSTRING(xbuf4)) + 100), this->m_pScreen->FontY()*5, zSTRING(xbuf4));
			if(stats.nAlphaPolys > 3800)
				this->m_pScreen->SetFontColor(zCOLOR(255, 0, 0, 255));
			else if(stats.nAlphaPolys > 2000)
				this->m_pScreen->SetFontColor(zCOLOR(255, 180, 0, 255));
			else if(stats.nAlphaPolys < 1700)
				this->m_pScreen->SetFontColor(zCOLOR(0, 255, 0, 255));
			this->m_pScreen->Print(VIEW_VXMAX - (this->m_pScreen->FontSize(zSTRING(xbuf5)) + 100), this->m_pScreen->FontY()*7, zSTRING(xbuf5));
			this->m_pScreen->SetFontColor(zCOLOR(255, 255, 255, 255));
			this->m_pScreen->Print(VIEW_VXMAX - (this->m_pScreen->FontSize(zSTRING(xbuf6)) + 100), this->m_pScreen->FontY()*8, zSTRING(xbuf6));
			this->m_pScreen->Print(VIEW_VXMAX - (this->m_pScreen->FontSize(zSTRING(xbuf7)) + 100), this->m_pScreen->FontY()*9, zSTRING(xbuf7));
		};	

		// -- Poll the system usage data all ~500ms
		if (tctr500 > 2000) { tctr500 = 2000; }; // skip tick

		if(tctr500 > 500)
		{
			GetProcessMemoryInfo(this->m_hProcess, &this->m_sProcessMemoryCounters, sizeof(PROCESS_MEMORY_COUNTERS));
			this->m_dwTotalMemoryUsage = this->m_sProcessMemoryCounters.PagefileUsage;

			GlobalMemoryStatus(&this->m_sMemStatus);

			tctr500 -= 500;
		};

		// -- Get Min/Max/Avg fps
		if(this->m_tElapsedTime > 10)
		{
			if(this->m_dwFPS < this->m_dwMinFPS)
				this->m_dwMinFPS = this->m_dwFPS;

			if(this->m_dwFPS > this->m_dwMaxFPS)
				this->m_dwMaxFPS = this->m_dwFPS;

			this->m_dwAvgFPS = (unsigned int)(this->m_dwFrames / this->m_tElapsedTime);
		};
	};
};

void CStatistics::Show(void)
{
	this->m_bVisible = true;
};

void CStatistics::Hide(void)
{
	this->m_bVisible = false;
};