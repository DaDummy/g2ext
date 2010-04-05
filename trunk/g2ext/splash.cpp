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

#include "common/osheader.h"
#include "splash.h"
#include "core.h"
#include "resource.h"

#include "common/version.h"

//////////////////////////////////////////////////////////

HWND hDlg;
HBITMAP hSplash;
HFONT hFont;

INT_PTR __stdcall DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) 
{
	return false; 
}; 

DWORD __stdcall SplashThreadProc(void* param)
{
	CCoreIngame* pCore = CCoreIngame::GetInstance();

	if(pCore->m_bUseCustomSplashScreen)
	{
		hSplash = pCore->m_hSplashBitmap;
	}
	else
	{
		hSplash = (HBITMAP)LoadImageW(GetModuleHandle(L"g2ext.dll"), 
			MAKEINTRESOURCE(IDB_SPLASH), 
			IMAGE_BITMAP, 
			0, 
			0, 
			LR_COPYFROMRESOURCE);		
	};

	hDlg = CreateDialog((HINSTANCE)GetModuleHandle(L"g2ext.dll"), MAKEINTRESOURCE(IDD_SPLASH), NULL, (DLGPROC)DialogProc);

	hFont = CreateFont(12, 0, 0, 0, FW_BOLD, false, false, false, ANSI_CHARSET, OUT_OUTLINE_PRECIS, 0, ANTIALIASED_QUALITY, FF_DONTCARE, L"Verdana");

	ShowWindow(hDlg, SW_SHOW);

	BITMAP bm;
	GetObject(hSplash, sizeof(BITMAP), (LPSTR)&bm);
	
	SetWindowPos(hDlg, NULL, (GetSystemMetrics(SM_CXSCREEN)/2-bm.bmWidth/2), (GetSystemMetrics(SM_CYSCREEN)/2-bm.bmHeight/2), bm.bmWidth, bm.bmHeight, 0);

	UpdateWindow(hDlg);

	MSG msg;
	HDC hDC = GetDC(hDlg);
	HDC hBitmapDC = CreateCompatibleDC(hDC);
	SelectObject(hBitmapDC, hSplash);
	 
	while(GetMessage(&msg, 0, 0, 0))
    {
		DispatchMessage(&msg);
		SelectObject(hBitmapDC, hSplash);
		BitBlt(hDC, 0, 0, 640, 300, hBitmapDC, 0, 0, SRCCOPY);
		SelectObject(hBitmapDC, hFont);
		SetTextColor(hBitmapDC, RGB(255, 255, 255));
		SetBkMode(hBitmapDC, TRANSPARENT);
		RECT rect;
		SetRect(&rect, 10, 10, 100, 100);
		
		if(pCore->m_bSplashShowVersionInfo)
		{
			DrawText(hBitmapDC, G2EXT_VERSIONW, -1, &rect, DT_NOCLIP);
		};

		SetRect(&rect, 10, 178, 100, 100);
		DrawText(hBitmapDC, L"Debug build", -1, &rect, DT_NOCLIP);

		UpdateWindow(hDlg);	
	};

	ShowWindow(hDlg, SW_HIDE);

	return 1;
};