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
#include "console.h"
#include "stats.h"
#include "utils.h"

#include "api/g2/zcinput.h"

CCoreIngame* pCore = CCoreIngame::GetInstance();

//////////////////////////////////////////////////////////////////////////

void __stdcall CCoreIngame::GothicOnInput(UINT& uKey)
{
	static bool bFPSWasVisible = false;

	if((G2EXT_PARAM_NO_G2EXT_CONSOLE & CCoreIngame::GetInstance()->m_pModInfo->dwFlags) != G2EXT_PARAM_NO_G2EXT_CONSOLE)
	{
		if(uKey == KEY_GRAVE)
		{
			if(pCore->m_pConsole->IsVisible())
			{
				pCore->m_pConsole->Hide();
				pCore->m_pConsole->SetFocus(false);
				bFPSWasVisible = pCore->m_pStatistics->IsVisible();
				if(bFPSWasVisible)
				{
					pCore->m_pStatistics->Show();
				};
			}
			else
			{
				pCore->m_pConsole->Show();
				pCore->m_pConsole->SetFocus(true);
				bFPSWasVisible = pCore->m_pStatistics->IsVisible();
				if(bFPSWasVisible)
				{			
					pCore->m_pStatistics->Hide();
				};
			};
		};
	};

	if(uKey == KEY_F12)
	{
		if(pCore->m_pStatistics->IsVisible())
		{
			pCore->m_pStatistics->Hide();
		}
		else
		{
			pCore->m_pStatistics->Show();
		};			
	};

	G2EXT_DEBUG ( if(uKey == KEY_F11) { exit(0); }; ) // -- Kill key for faster debugging as the known "-nomenu" doesn't exist any more
};

void __stdcall CCoreIngame::GothicOnRender(void)
{
	pCore->m_pStatistics->Tick();

	if((G2EXT_PARAM_NO_G2EXT_CONSOLE & CCoreIngame::GetInstance()->m_pModInfo->dwFlags) != G2EXT_PARAM_NO_G2EXT_CONSOLE)
	{
		pCore->m_pConsole->Tick();
	};
};

void __stdcall CCoreIngame::GothicOnDone(void)
{
	pCore->m_bInGame = false;
	pCore->m_pStatistics->Stop();

	pCore->m_pConsole->Hide();

	pCore->Release();

	exit(0); // fast exit
};

void __stdcall CCoreIngame::GothicOnPause(void)
{
	pCore->m_bIsPaused = true;
};

void __stdcall CCoreIngame::GothicOnUnPause(void)
{
	pCore->m_bIsPaused = false;
};

void __stdcall CCoreIngame::GothicOnIngame(void)
{
	pCore->m_bInGame = true;

	if(pCore->m_bIsFirstRun)
	{
		G2EXT_LOG_DEBUG(L"Initializing statistics...")

		pCore->m_pStatistics->Init();
		pCore->m_pStatistics->Start();

		G2EXT_LOG_DEBUG(L"Initializing console...")

		pCore->m_pConsole->Init();
		pCore->m_pConsole->Hide();

		pCore->m_bIsFirstRun = false;
	}
	else
	{
		pCore->m_pStatistics->Reset();
		pCore->m_pStatistics->Start();
	};

	pCore->m_pStatistics->Show();
};

void __stdcall CCoreIngame::GothicOnLoadWorld(void)
{

};

void __stdcall CCoreIngame::GothicOnOpenLoadscreen()
{
	if(pCore->m_bInGame)
	{
		pCore->m_pStatistics->Stop();
	};

	pCore->m_bInMenu = false;
	pCore->m_bInLoadScreen = true;
	pCore->m_bInGame = false;
};

void __stdcall CCoreIngame::GothicOnCloseLoadscreen()
{
	pCore->m_bInLoadScreen = false;
	pCore->m_bInGame = true;
};