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

#ifndef __G2EXT_STARTER_H__
#define __G2EXT_STARTER_H__

#include "api/core.h"

#include "singleton.h"

#include <wchar.h>

#include <vector>
#include <map>
#include <string>

using namespace std;

#ifndef G2EXT_MOD_DEFINED
#define G2EXT_MOD_DEFINED

/** internal use only */
typedef struct _MOD 
{
	size_t		szSize;

	wstring		wcIni;
	wstring		wcInfoTitle;
	wstring		wcInfoVersion;
	wstring		wcInfoAuthors;
	wstring		wcInfoWebpage;
	wstring		wcInfoDescription;
	wstring		wcInfoIcon;

	wstring		wcFilesVDF;

	wstring		wcSettingsPlayer;
	wstring		wcSettingsZEN;

	wstring		wcG2ExtDLL;
	wstring		wcG2ExtPLUGINS;

	_MOD()
	{
		this->szSize = sizeof(_MOD);
	};
} MOD, *PMOD;

#endif  //G2EXT_MOD_DEFINED

class CStarter : public TSingleton<CStarter>
{
private:
	std::vector<PMOD>		m_vMods;
	std::map<UINT, HWND>	m_mControls; 
	PMOD					m_pSelectedMod;
	HWND					m_hWnd;
	HFONT					m_hFont;
	HBITMAP					m_hLogo;
	HMENU					m_hMenu;
	HINSTANCE				m_hInstance;
private:
	void SearchAndParseMods(void);

	void InitUI(void);
	HWND InitWindow(LPCWSTR lpwCaption, int x, int y, int cx, int cy);
	void SetControlsEnabled(bool bEnabled);

	void InsertItemIntoListView(LPCWSTR lpwTitle, LPCWSTR lpwVersion, LPCWSTR lpwTeam);
	LPWSTR MakeCMD(LPCWSTR lpcExecuteable, bool bAppendExecuteable);

	static LRESULT __stdcall WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
public:
	void Init(void);
	void Release(void);

	void GetSelectedMod();

	void LaunchTool(LPCWSTR lpwPath);

	void LaunchSpacer(void);
public:
	static DWORD __stdcall GothicThreadProc(void* dwParam);
	static DWORD __stdcall SpacerThreadProc(void* dwParam);
};

#endif  //__G2EXT_STARTER_H__