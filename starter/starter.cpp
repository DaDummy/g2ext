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

#include "starter.h"
#include "defines.h"
#include "resource.h"
#include "utils.h"
#include "api/g2ext.h"
#include "common/version.h"

#include <windowsx.h>
#include <stdlib.h>
#include <commctrl.h>

// -- enable visual styles for XP and later
#pragma comment(linker ,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

void CStarter::Init(void)
{
	this->m_hInstance = GetModuleHandle(NULL);

#ifdef G2EXT_STARTER_DEV
	this->m_hWnd = InitWindow(G2EXT_CAPTIONDEV, 530, 520, 100, 100);
#else //G2EXT_STARTER_DEV
	this->m_hWnd = InitWindow(G2EXT_CAPTION, 530, 500, 100, 100);
#endif //G2EXT_STARTER_DEV

	this->InitUI();

	this->SearchAndParseMods();
};

void CStarter::Release(void)
{
	// --
};

HWND CStarter::InitWindow(LPCWSTR lpwCaption, int x, int y, int cx, int cy)
{
	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(WNDCLASSEX));

	wcex.cbSize			= sizeof(WNDCLASSEX);
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpszClassName	= G2EXT_WINDOW_CLASS;
	wcex.hInstance		= GetModuleHandle(NULL);
	wcex.hIcon			= LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_APPICON));
	wcex.hIconSm		= LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_APPICON));
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW);
	wcex.lpfnWndProc	= (WNDPROC)CStarter::WindowProc;
	RegisterClassEx(&wcex);

	return CreateWindowEx(NULL, G2EXT_WINDOW_CLASS, lpwCaption, WS_DLGFRAME | WS_SYSMENU | WS_VISIBLE, cx, cy, x, y, NULL, NULL, wcex.hInstance, NULL);
};

void CStarter::InitUI(void)
{
	InitCommonControls();

	// -- Init buttons
	this->m_mControls.insert(std::make_pair<UINT, HWND>(ID_START, CreateWindowEx(NULL, L"BUTTON", L"start mod", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 390, 107, 128, 22, this->m_hWnd, (HMENU)ID_START, this->m_hInstance, NULL)));
#ifdef G2EXT_STARTER_DEV
	this->m_mControls.insert(std::make_pair<UINT, HWND>(ID_SPACER, CreateWindowEx(NULL, L"BUTTON", L"start spacer", WS_TABSTOP | WS_VISIBLE | WS_CHILD, 390, 134, 128, 22, this->m_hWnd, (HMENU)ID_SPACER, this->m_hInstance, NULL)));
#endif //G2EXT_STARTER_DEV
	this->m_mControls.insert(std::make_pair<UINT, HWND>(ID_CLOSE, CreateWindowEx(NULL, L"BUTTON", L"close", WS_TABSTOP | WS_VISIBLE | WS_CHILD, 390, 445, 128, 22, this->m_hWnd, (HMENU)ID_CLOSE, this->m_hInstance, NULL)));

	// -- Group boxes
	this->m_mControls.insert(std::make_pair<UINT, HWND>(IDG_GROUP, CreateWindowEx(NULL, L"BUTTON", L"", BS_GROUPBOX | WS_VISIBLE | WS_CHILD, 6, 350, 376, 90, this->m_hWnd, (HMENU)IDG_GROUP, this->m_hInstance, NULL)));

	// -- Init edit controls
	this->m_mControls.insert(std::make_pair<UINT, HWND>(IDE_CMD, CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"", WS_TABSTOP | WS_VISIBLE | WS_CHILD, 6, 446, 376, 20, this->m_hWnd, (HMENU)IDE_CMD, this->m_hInstance, NULL)));

#ifdef G2EXT_STARTER_DEV
	// -- Init check boxes
	this->m_mControls.insert(std::make_pair<UINT, HWND>(IDB_ZREPARSE, CreateWindowEx(NULL, L"BUTTON", L"reparse scripts", BS_AUTOCHECKBOX | WS_VISIBLE | WS_CHILD, 390, 160, 128, 22, this->m_hWnd, (HMENU)IDB_ZREPARSE, this->m_hInstance, NULL)));
	this->m_mControls.insert(std::make_pair<UINT, HWND>(IDB_NOMENU, CreateWindowEx(NULL, L"BUTTON", L"no menu", BS_AUTOCHECKBOX | WS_VISIBLE | WS_CHILD, 390, 180, 128, 22, this->m_hWnd, (HMENU)IDB_NOMENU, this->m_hInstance, NULL)));
	this->m_mControls.insert(std::make_pair<UINT, HWND>(IDB_WINDOWED, CreateWindowEx(NULL, L"BUTTON", L"windowed",	BS_AUTOCHECKBOX | WS_VISIBLE | WS_CHILD, 390, 200, 128, 22, this->m_hWnd, (HMENU)IDB_WINDOWED, this->m_hInstance, NULL)));
	this->m_mControls.insert(std::make_pair<UINT, HWND>(IDB_NOINJECTION, CreateWindowEx(NULL, L"BUTTON", L"no injection", BS_AUTOCHECKBOX | WS_VISIBLE | WS_CHILD, 390, 220, 128, 22, this->m_hWnd, (HMENU)IDB_NOINJECTION,	this->m_hInstance, NULL)));
	this->m_mControls.insert(std::make_pair<UINT, HWND>(IDB_NOSOUND, CreateWindowEx(NULL, L"BUTTON", L"no sound", BS_AUTOCHECKBOX | WS_VISIBLE | WS_CHILD, 390, 240, 128, 22, this->m_hWnd, (HMENU)IDB_NOSOUND, this->m_hInstance, NULL)));
	this->m_mControls.insert(std::make_pair<UINT, HWND>(IDB_NOMUSIC, CreateWindowEx(NULL, L"BUTTON", L"no music", BS_AUTOCHECKBOX | WS_VISIBLE | WS_CHILD, 390, 260, 128, 22, this->m_hWnd, (HMENU)IDB_NOMUSIC, this->m_hInstance, NULL)));
	this->m_mControls.insert(std::make_pair<UINT, HWND>(IDB_CONVTEX, CreateWindowEx(NULL, L"BUTTON", L"convert textures",	BS_AUTOCHECKBOX | WS_VISIBLE | WS_CHILD, 390, 280, 128, 22, this->m_hWnd, (HMENU)IDB_CONVTEX, this->m_hInstance, NULL)));
	this->m_mControls.insert(std::make_pair<UINT, HWND>(IDB_CONVDATA, CreateWindowEx(NULL, L"BUTTON", L"convert data", BS_AUTOCHECKBOX | WS_VISIBLE | WS_CHILD, 390, 300, 128, 22, this->m_hWnd, (HMENU)IDB_CONVDATA, this->m_hInstance, NULL)));
	this->m_mControls.insert(std::make_pair<UINT, HWND>(IDB_CONVALL, CreateWindowEx(NULL, L"BUTTON", L"convert all", BS_AUTOCHECKBOX | WS_VISIBLE | WS_CHILD, 390, 320, 128, 22, this->m_hWnd, (HMENU)IDB_CONVALL, this->m_hInstance, NULL)));
	this->m_mControls.insert(std::make_pair<UINT, HWND>(IDB_VDFS, CreateWindowEx(NULL, L"BUTTON", L"suppr. VDFS check", BS_AUTOCHECKBOX | WS_VISIBLE | WS_CHILD, 390, 340, 128, 22, this->m_hWnd, (HMENU)IDB_VDFS, this->m_hInstance, NULL)));
	this->m_mControls.insert(std::make_pair<UINT, HWND>(IDB_FPSLIMIT, CreateWindowEx(NULL, L"BUTTON", L"fps limit: 60", BS_AUTOCHECKBOX | WS_VISIBLE | WS_CHILD, 390, 360, 128, 22, this->m_hWnd, (HMENU)IDB_FPSLIMIT, this->m_hInstance, NULL)));
	this->m_mControls.insert(std::make_pair<UINT, HWND>(IDB_XDEBUG, CreateWindowEx(NULL, L"BUTTON", L"xdebug", BS_AUTOCHECKBOX | WS_VISIBLE | WS_CHILD, 390, 380, 128, 22, this->m_hWnd, (HMENU)IDB_XDEBUG, this->m_hInstance, NULL)));
	this->m_mControls.insert(std::make_pair<UINT, HWND>(IDB_XG2CON, CreateWindowEx(NULL, L"BUTTON", L"xg2con", BS_AUTOCHECKBOX | WS_VISIBLE | WS_CHILD, 390, 400, 128, 22, this->m_hWnd, (HMENU)IDB_XG2CON, this->m_hInstance, NULL)));
#endif //G2EXT_STARTER_DEV

	this->m_mControls.insert(std::make_pair<UINT, HWND>(5000, CreateWindowEx(NULL, L"STATIC", L"Title:", WS_VISIBLE | WS_CHILD, 16, 370, 128, 14, this->m_hWnd, NULL, this->m_hInstance, NULL)));
	this->m_mControls.insert(std::make_pair<UINT, HWND>(5001, CreateWindowEx(NULL, L"STATIC", L"Version:", WS_VISIBLE | WS_CHILD, 16, 386, 128, 14, this->m_hWnd, NULL, this->m_hInstance, NULL)));
	this->m_mControls.insert(std::make_pair<UINT, HWND>(5002, CreateWindowEx(NULL, L"STATIC", L"Team:", WS_VISIBLE | WS_CHILD, 16, 402, 128, 14, this->m_hWnd, NULL, this->m_hInstance, NULL)));
	this->m_mControls.insert(std::make_pair<UINT, HWND>(5003, CreateWindowEx(NULL, L"STATIC", L"Web:", WS_VISIBLE | WS_CHILD, 16, 418, 128, 14, this->m_hWnd, NULL, this->m_hInstance, NULL)));

	this->m_mControls.insert(std::make_pair<UINT, HWND>(IDT_TITLE, CreateWindowEx(NULL, L"STATIC", L"---", WS_VISIBLE | WS_CHILD, 60, 370, 250, 14, this->m_hWnd, NULL, this->m_hInstance, NULL)));
	this->m_mControls.insert(std::make_pair<UINT, HWND>(IDT_VERSION, CreateWindowEx(NULL, L"STATIC", L"---", WS_VISIBLE | WS_CHILD, 60, 386, 250, 14, this->m_hWnd, NULL, this->m_hInstance, NULL)));
	this->m_mControls.insert(std::make_pair<UINT, HWND>(IDT_TEAM, CreateWindowEx(NULL, L"STATIC", L"---", WS_VISIBLE | WS_CHILD, 60, 402, 250, 14, this->m_hWnd, NULL, this->m_hInstance, NULL)));
	this->m_mControls.insert(std::make_pair<UINT, HWND>(IDT_WEB, CreateWindowEx(NULL, L"STATIC", L"---", WS_VISIBLE | WS_CHILD, 60, 418, 250, 14, this->m_hWnd, NULL, this->m_hInstance, NULL)));

	this->m_mControls.insert(std::make_pair<UINT, HWND>(5004, CreateWindowEx(NULL, L"STATIC", L"", SS_CENTERIMAGE | SS_REALSIZEIMAGE | SS_BITMAP | WS_CHILD | WS_VISIBLE, 0, 0, 524, 101, this->m_hWnd, NULL, this->m_hInstance, NULL)));

	this->m_mControls.insert(std::make_pair<UINT, HWND>(IDL_MODLIST, CreateWindowEx(WS_EX_CLIENTEDGE, L"SysListView32", L"", WS_CHILD | LVS_REPORT | LVS_NOSORTHEADER | LVS_SINGLESEL | LVS_SHOWSELALWAYS | WS_VISIBLE, 6, 107, 376, 242, this->m_hWnd, (HMENU)IDL_MODLIST, this->m_hInstance, NULL))); 

	this->m_hFont = CreateFont(14, 
		0, 
		0, 
		0, 
		FW_DONTCARE,
		0,
		0,
		0, 
		DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, 
		0,
		DEFAULT_PITCH | FF_DONTCARE,
		L"Tohama"); 

	for each(std::pair<UINT, HWND> p in this->m_mControls)
	{
		SendMessage(p.second, WM_SETFONT, (WPARAM)this->m_hFont, true);
	};

	//////////////////////////////////////////////////////////////////////////

	this->m_hLogo = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_LOGO));

	SendMessage(this->m_mControls[5004], STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)this->m_hLogo);

	//////////////////////////////////////////////////////////////////////////

	SendMessage(this->m_mControls[IDL_MODLIST], LVM_SETEXTENDEDLISTVIEWSTYLE, 0, (LPARAM)(LVS_EX_FULLROWSELECT));

	// -- Set columns
	LVCOLUMN lvc_0 = {0};
	LVCOLUMN lvc_1 = {0};
	LVCOLUMN lvc_2 = {0};

	lvc_0.iSubItem	= 0;
	lvc_0.pszText	= L"Title";	
	lvc_0.cx		= 156;   
	lvc_0.fmt		= LVCFMT_LEFT;
	lvc_0.mask		= LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM; 

	lvc_1.iSubItem	= 1;
	lvc_1.pszText	= L"Version";	
	lvc_1.cx		= 80;   
	lvc_1.fmt		= LVCFMT_LEFT;
	lvc_1.mask		= LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM; 

	lvc_2.iSubItem	= 2;
	lvc_2.pszText	= L"Team";	
	lvc_2.cx		= 136;   
	lvc_2.fmt		= LVCFMT_LEFT;
	lvc_2.mask		= LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM; 

	ListView_InsertColumn(this->m_mControls[IDL_MODLIST], 0, &lvc_0);
	ListView_InsertColumn(this->m_mControls[IDL_MODLIST], 1, &lvc_1);
	ListView_InsertColumn(this->m_mControls[IDL_MODLIST], 2, &lvc_2);

#ifdef G2EXT_STARTER_DEV

	HMENU hSubMenu = NULL;
	this->m_hMenu = CreateMenu();

	hSubMenu = CreatePopupMenu();
	AppendMenu(hSubMenu, MF_STRING, ID_START, L"&Start mod");
	AppendMenu(hSubMenu, MF_STRING, ID_SPACER, L"&Start spacer");
	AppendMenu(hSubMenu, MF_SEPARATOR, 0, 0);
	AppendMenu(hSubMenu, MF_STRING, ID_CLOSE, L"E&xit");
	AppendMenu(this->m_hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, L"&File");

	hSubMenu = CreatePopupMenu();
	AppendMenu(hSubMenu, MF_STRING, ID_VDFS, L"&VDFS");
	AppendMenu(hSubMenu, MF_STRING, ID_ZTEX, L"&ZTEX");
	AppendMenu(hSubMenu, MF_STRING, ID_ZSPY, L"&zSpy");
	AppendMenu(this->m_hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, L"&Tools");

	hSubMenu = CreatePopupMenu();
	AppendMenu(hSubMenu, MF_STRING, ID_ABOUT, L"&About G2Ext");
	AppendMenu(this->m_hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, L"&Help");

	SetMenu(this->m_hWnd, this->m_hMenu);	
#endif //G2EXT_STARTER_DEV
};

void CStarter::SetControlsEnabled(bool bEnabled)
{
	for each(std::pair<UINT, HWND> p in this->m_mControls)
	{
		EnableWindow(p.second, bEnabled);
	};
};

void CStarter::InsertItemIntoListView(LPCWSTR lpwTitle, LPCWSTR lpwVersion, LPCWSTR lpwTeam)
{
	static UINT i = 0;
	wchar_t wcText[3][256]	= {0};
	LVITEM lvI				= {0};

	lvI.mask = LVIF_TEXT | LVIF_PARAM | LVIF_STATE; 
	lvI.iItem = i;
	lvI.pszText = (LPWSTR)lpwTitle;
	ListView_InsertItem(this->m_mControls[IDL_MODLIST], &lvI);
	ListView_SetItemText(this->m_mControls[IDL_MODLIST], i, 1, (LPWSTR)lpwVersion);
	ListView_SetItemText(this->m_mControls[IDL_MODLIST], i, 2, (LPWSTR)lpwTeam); 

	i++;
};

void CStarter::LaunchTool(LPCWSTR lpwPath)
{
	PROCESS_INFORMATION	pi;
	STARTUPINFO			si;

	ZeroMemory(&si, sizeof(STARTUPINFO));

	si.cb			= sizeof(STARTUPINFO);
	si.dwFlags		= STARTF_USESHOWWINDOW;
	si.wShowWindow	= SW_SHOW;

	wchar_t buf [256] = {0};
	GetCurrentDirectory(256, buf);
	std::wstring dir = std::wstring(buf);
	dir.erase(dir.length()-6, 6);
	dir.append(lpwPath);
	CreateProcessW(NULL, (LPWSTR)dir.c_str(), NULL, NULL, false, NULL, NULL, NULL, &si, &pi);
};

void CStarter::GetSelectedMod()
{
	CStarter* pStarter = CStarter::GetInstance();

	int nIndex = -1;
	if((nIndex = (int)SendMessage(pStarter->m_mControls[IDL_MODLIST], LVM_GETNEXTITEM, -1, LVNI_FOCUSED)) != -1)
	{
		pStarter->m_pSelectedMod = pStarter->m_vMods[(UINT)nIndex];
	}
	else
	{
		return;
	};

	SetWindowText(pStarter->m_mControls[IDT_TITLE],	pStarter->m_pSelectedMod->wcInfoTitle.c_str());
	SetWindowText(pStarter->m_mControls[IDT_WEB], pStarter->m_pSelectedMod->wcInfoWebpage.c_str());
	SetWindowText(pStarter->m_mControls[IDT_TEAM], pStarter->m_pSelectedMod->wcInfoAuthors.c_str());
	SetWindowText(pStarter->m_mControls[IDT_VERSION], pStarter->m_pSelectedMod->wcInfoVersion.c_str());
};

LPWSTR CStarter::MakeCMD(LPCWSTR lpwExecuteable, bool bAppendExecuteable)
{
	static wchar_t wcCmdBuf[256] = {0};
	wchar_t* wcWTextBuf = new wchar_t[256]; // -- dynamic buffer
	memset(&wcCmdBuf, 0, 256);
	memset(wcWTextBuf, 0, 256);

	if(bAppendExecuteable)
	{
		wcscpy_s(wcCmdBuf, 256, lpwExecuteable);
	};

#ifdef G2EXT_STARTER_DEV
	if(Button_GetCheck(this->m_mControls[IDB_ZREPARSE]) == BST_CHECKED)		wcscat_s(wcCmdBuf, 256, L" -zreparse");
	if(Button_GetCheck(this->m_mControls[IDB_NOMENU]) == BST_CHECKED)		wcscat_s(wcCmdBuf, 256, L" --xnomenu");
	if(Button_GetCheck(this->m_mControls[IDB_WINDOWED]) == BST_CHECKED)		wcscat_s(wcCmdBuf, 256, L" -zwindow");
	if(Button_GetCheck(this->m_mControls[IDB_NOINJECTION]) == BST_CHECKED)	wcscat_s(wcCmdBuf, 256, L" --noinjection");
	if(Button_GetCheck(this->m_mControls[IDB_NOSOUND]) == BST_CHECKED)		wcscat_s(wcCmdBuf, 256, L" -znosound");
	if(Button_GetCheck(this->m_mControls[IDB_NOMUSIC]) == BST_CHECKED)		wcscat_s(wcCmdBuf, 256, L" -znomusic");
	if(Button_GetCheck(this->m_mControls[IDB_CONVTEX]) == BST_CHECKED)		wcscat_s(wcCmdBuf, 256, L" -ztexconvert");
	if(Button_GetCheck(this->m_mControls[IDB_CONVDATA]) == BST_CHECKED)		wcscat_s(wcCmdBuf, 256, L" -zautoconvertdata");
	if(Button_GetCheck(this->m_mControls[IDB_CONVALL]) == BST_CHECKED)		wcscat_s(wcCmdBuf, 256, L" -zconvertall");
	if(Button_GetCheck(this->m_mControls[IDB_VDFS]) == BST_CHECKED)			wcscat_s(wcCmdBuf, 256, L" --xvdfs");
	if(Button_GetCheck(this->m_mControls[IDB_FPSLIMIT]) == BST_CHECKED)		wcscat_s(wcCmdBuf, 256, L" -zmaxframerate:60");
	if(Button_GetCheck(this->m_mControls[IDB_XDEBUG]) == BST_CHECKED)		wcscat_s(wcCmdBuf, 256, L" --xdebug");
	if(Button_GetCheck(this->m_mControls[IDB_XG2CON]) == BST_CHECKED)		wcscat_s(wcCmdBuf, 256, L" --xg2con");
#endif //G2EXT_STARTER_DEV

	GetWindowTextW(this->m_mControls[IDE_CMD], wcWTextBuf, 256);
	wcscat_s(wcCmdBuf, 256, L" ");
	wcscat_s(wcCmdBuf, 256, wcWTextBuf);

	delete [] wcWTextBuf;

	return wcCmdBuf;
};

LRESULT __stdcall CStarter::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	CStarter* pStarter = CStarter::GetInstance();

	switch(uMsg)
	{
	case WM_KEYDOWN:
		switch (wParam) 
		{
		case VK_ESCAPE:
			exit(0);
			break;
		} break;

	case WM_COMMAND:
		switch(wParam)
		{
		case ID_CLOSE:
			exit(0);
			break;
		case ID_START:
			CreateThread(NULL, 0, CStarter::GothicThreadProc, 0, 0, NULL); 
			break;
#ifdef G2EXT_STARTER_DEV
		case ID_SPACER:
			CreateThread(NULL, 0, CStarter::SpacerThreadProc, 0, 0, NULL); 
			break;
		case ID_VDFS:
			pStarter->LaunchTool(L"_work\\tools\\VDFS\\GothicVDFS.exe");
			break;
		case ID_ZTEX:
			pStarter->LaunchTool(L"_work\\tools\\ZTEX\\GothicZTEX.exe");
			break;
		case ID_ZSPY:
			pStarter->LaunchTool(L"_work\\tools\\zSpy\\zSpy.exe");
			break;
		case ID_ABOUT:
			MessageBox(0, L"G2Ext © 2009, 2010 by Paindevs and Patrick Vogel\nDeveloped by Christoffer Anselm and Patrick Vogel\n\nhttp://g2ext.googlecode.com", L"About G2Ext...", MB_APPLMODAL);
			break;

#endif //G2EXT_STARTER_DEV
		} break;

	case WM_NOTIFY:
		switch(wParam)
		{
		case IDL_MODLIST:
			{
				if(((LPNMHDR)lParam)->code == NM_CLICK)
				{
					pStarter->GetSelectedMod();
				};

				if(((LPNMHDR)lParam)->code == NM_DBLCLK)
				{
					pStarter->GetSelectedMod();

					CreateThread(NULL, 0, CStarter::GothicThreadProc, 0, 0, NULL);
				};

				if(((LPNMHDR)lParam)->code == LVN_ITEMCHANGED)
				{
					pStarter->GetSelectedMod();
				};

				if(((LPNMHDR)lParam)->code == LVN_KEYDOWN)
				{	
					if(((LPNMLVKEYDOWN)lParam)->wVKey == VK_RETURN)
					{					
						CreateThread(NULL, 0, CStarter::GothicThreadProc, 0, 0, NULL);
					};
				};
			} break;
		} break;


	case WM_DESTROY:
		exit(0);
		break;
	};

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
};

DWORD __stdcall CStarter::GothicThreadProc(void* dwParam)
{
	CStarter* pStarter = CStarter::GetInstance();

	if(pStarter->m_pSelectedMod == NULL)
		return 0;

	pStarter->SetControlsEnabled(false);

	HMODULE hDll = LoadLibraryA("g2ext.dll");
	
	G2EXT_SYSTEM_INIT_FUNC Init = NULL;

	if((Init = (G2EXT_SYSTEM_INIT_FUNC)GetProcAddress(hDll, "G2Ext_Init")) == NULL)
	{
		return 1;
		pStarter->SetControlsEnabled(true);
	};

	PMODINFO pModInfo = new MODINFO();

	//FIXME: cwcs(subwcs(...), ...) combo is a memoryleak
	pModInfo->lpwDMP		= cwcs(subwcs(pStarter->m_pSelectedMod->wcFilesVDF.c_str(), wcslen(pStarter->m_pSelectedMod->wcFilesVDF.c_str())-4), L".mod");
	pModInfo->lpwVDF		= pStarter->m_pSelectedMod->wcFilesVDF.c_str();
	pModInfo->lpwDLL		= pStarter->m_pSelectedMod->wcG2ExtDLL.c_str();
	pModInfo->lpwSpacerDLL	= L"";
	pModInfo->lpwPlugins	= pStarter->m_pSelectedMod->wcG2ExtPLUGINS.c_str();
	pModInfo->lpwModIni		= pStarter->m_pSelectedMod->wcIni.c_str();
	pModInfo->lpwCMD		= pStarter->MakeCMD(L"Gothic2.exe", true);

	ShowWindow(pStarter->m_hWnd, SW_SHOWMINIMIZED);

	Init(pModInfo);

	ShowWindow(pStarter->m_hWnd, SW_SHOWNORMAL);

	FreeConsole(); // fix: hide G2Ext debug console

	FreeLibrary(hDll);

	//delete [] pModInfo->lpwDMP;	// causes failed assertion crash in debug compile mode...
									// seems, like we have to find another workaround for that cwcs/subwcs memory leak here :/

	G2EXT_DELETE(pModInfo);

	pStarter->SetControlsEnabled(true);

	return 0;
};

DWORD __stdcall CStarter::SpacerThreadProc(void* dwParam)
{
#ifdef G2EXT_STARTER_DEV
	CStarter* pStarter = CStarter::GetInstance();

	if(!pStarter->m_pSelectedMod->wcG2ExtSpacerDLL.empty())
	{
		if(pStarter->m_pSelectedMod == NULL)
			return 0;

		pStarter->SetControlsEnabled(false);

		HMODULE hDll = LoadLibraryA("g2ext.spacer.dll");

		G2EXT_SYSTEM_INIT_FUNC Init = NULL;

		if((Init = (G2EXT_SYSTEM_INIT_FUNC)GetProcAddress(hDll, "G2Ext_Init")) == NULL)
		{
			return 1;
			pStarter->SetControlsEnabled(true);
		};

		PMODINFO pModInfo = new MODINFO();

		//FIXME: cwcs(subwcs(...), ...) combo is a memoryleak
		pModInfo->lpwDMP		= cwcs(subwcs(pStarter->m_pSelectedMod->wcFilesVDF.c_str(), wcslen(pStarter->m_pSelectedMod->wcFilesVDF.c_str())-4), L".mod");
		pModInfo->lpwVDF		= pStarter->m_pSelectedMod->wcFilesVDF.c_str();
		pModInfo->lpwDLL		= pStarter->m_pSelectedMod->wcG2ExtDLL.c_str();
		pModInfo->lpwSpacerDLL	= pStarter->m_pSelectedMod->wcG2ExtSpacerDLL.c_str();
		pModInfo->lpwPlugins	= pStarter->m_pSelectedMod->wcG2ExtPLUGINS.c_str();
		pModInfo->lpwModIni		= pStarter->m_pSelectedMod->wcIni.c_str();
		pModInfo->lpwCMD		= pStarter->MakeCMD(L"Spacer2.exe -zmaxframerate:60", true);
		pModInfo->dwFlags		|= G2EXT_PARAM_SPACER;

		ShowWindow(pStarter->m_hWnd, SW_SHOWMINIMIZED);

		Init(pModInfo);

		ShowWindow(pStarter->m_hWnd, SW_SHOWNORMAL);

		FreeConsole(); // fix: hide G2Ext debug console

		FreeLibrary(hDll);

		//delete [] pModInfo->lpwDMP;	// causes failed assertion crash in debug compile mode...
										// seems, like we have to find another workaround for that cwcs/subwcs memory leak here :/

		G2EXT_DELETE(pModInfo);

		pStarter->SetControlsEnabled(true);
	}
	else
	{
		PROCESS_INFORMATION	pi;
		STARTUPINFO			si;
		int					iStatus;

		pStarter->SetControlsEnabled(false);

		if(!FileExists(L"spacer2.exe"))
		{
			MessageBox(0, L"Spacer2.exe not found!", L"G2Ext", MB_OK | MB_ICONERROR);
			pStarter->SetControlsEnabled(true);
			return 0;
		};

		ZeroMemory(&si, sizeof(STARTUPINFO));

		si.cb			= sizeof(STARTUPINFO);
		si.dwFlags		= STARTF_USESHOWWINDOW;
		si.wShowWindow	= SW_SHOW;

		if(CreateProcessW(NULL, pStarter->MakeCMD(L"Spacer2.exe -zmaxframerate:60", true), NULL, NULL, false, NULL, NULL, NULL, &si, &pi) == 0)
		{
			ShowWindow(pStarter->m_hWnd, SW_SHOWNORMAL);
			pStarter->SetControlsEnabled(true);
			return 0;
		};

		ShowWindow(pStarter->m_hWnd, SW_SHOWMINIMIZED);

		while ((GetExitCodeProcess(pi.hProcess, (LPDWORD)&iStatus) != false) && iStatus == STILL_ACTIVE)
		{
			Sleep(500);
		};

		ShowWindow(pStarter->m_hWnd, SW_SHOWNORMAL);
		pStarter->SetControlsEnabled(true);
	};
#endif //G2EXT_STARTER_DEV
	return 0;
};