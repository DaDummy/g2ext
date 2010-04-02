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

#include "log.h"

#include <stdio.h>
#include <ostream>
#include <iostream>
#include <string>
#include <sstream>
#include <wchar.h>
#include <fcntl.h>
#include <io.h>
#include <time.h>

#include "utils.h"
#include "core.h"

#pragma warning(disable:4996)

bool CLog::Open(LPCWSTR lpcFileName, bool bAllocDebugCMD, LOG_LEVEL llMinLogLevel)
{
	this->m_hConsole = NULL;
	this->m_llMin = LOG_NONE;
	this->m_lpFileName = lpcFileName;

	if(bAllocDebugCMD)
	{
		_COORD bufferSize = { 80, 1000 };
		int hCrt;
		FILE* hf;

		AllocConsole();
		this->m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTitle(L"Debug");
		SetConsoleScreenBufferSize(this->m_hConsole, bufferSize);

		hCrt	= _open_osfhandle((long) this->m_hConsole, _O_TEXT);
		hf		= _fdopen(hCrt, "w");
		*stdout	= *hf;		

		// BEGIN HACK: Pin consoles on right screen border

		int width = 0;
		int height = 0;
		RECT rect;
		if(GetWindowRect(GetConsoleWindow(), &rect))
		{
			width = rect.right - rect.left;
			height = rect.bottom - rect.top;
		};
		
		if(lpcFileName == L"g2ext_ingame.log")
		{	
			SetWindowPos(GetConsoleWindow(), NULL, (GetSystemMetrics(SM_CXSCREEN) - width - 20), (height + 40), width, height, 0);
		}
		else 
		{
			SetWindowPos(GetConsoleWindow(), NULL, (GetSystemMetrics(SM_CXSCREEN) - width - 20), (20), width, height, 0);
		};
		// END HACK
	};

	this->m_fsFile.open(lpcFileName, std::ios::out);
	if(!this->m_fsFile.is_open())
		return false;
	
	time_t	rawtime;
	tm		timeinfo;

	time (&rawtime);

	// -- secure variant of tm* timeinfo = localtime(time_t* rawtime)
	if (localtime_s(&timeinfo, &rawtime))
		return false; // -- should never happen as we get rawtime from the OS

	// -- we need 19 chars + terminating zero
	wchar_t wcTime[20];

	wcsftime(wcTime, 20, L"%Y-%m-%d %H:%M:%S", &timeinfo);

	this->m_fsFile << L"## " << wcTime << L" - " << L"G2Ext logfile created" << std::endl;
	this->m_fsFile << L"## BEGIN LOG ##" << std::endl;

	this->m_bInitialized = true;

	this->m_pCritical = new CCriticalSection();

	return true;
};

void CLog::Close(void)
{
	if(!this->m_fsFile)
		return;

	this->m_fsFile << L"## END LOG ##" << std::endl;
	this->m_fsFile.close();
};

void CLog::Write(LOG_LEVEL eLogLevel, const wchar_t* msg)
{
	if(!this->m_fsFile.is_open() || !this->m_bInitialized)
		return;

	wchar_t timebuf[12];

	time_t rawtime;
	tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime); 

	swprintf_s(timebuf, 12, L"[%02u:%02u:%02u] ", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

	this->m_pCritical->EnterCS();

	switch(eLogLevel)
	{
	case LOG_NONE:
		{
			if(LOG_NONE < this->m_llMin)
				break;

			this->m_fsFile << timebuf << msg << std::endl;

			if(this->m_hConsole != NULL)
			{
				SetConsoleTextAttribute(this->m_hConsole, 8);
				std::wcout << timebuf << msg << std::endl;
				SetConsoleTextAttribute(this->m_hConsole, 7);
			};
		} break;
	case LOG_NONE_NTS:
		{
			if(LOG_NONE_NTS < this->m_llMin)
				break;

			this->m_fsFile << L"" << msg << std::endl;

			if(this->m_hConsole != NULL)
			{
				std::wcout << L"" << msg << std::endl;
			};
		} break;
	case LOG_DEBUG:
		{
			if(LOG_DEBUG < this->m_llMin)
				break;

			this->m_fsFile << timebuf << L"debug: " << msg << std::endl;

			if(this->m_hConsole != NULL)
			{
				SetConsoleTextAttribute(this->m_hConsole, 4);
				std::wcout << timebuf << msg << std::endl;
				SetConsoleTextAttribute(this->m_hConsole, 7);
			};
		} break;
	case LOG_INFO:
		{
			if(LOG_INFO < this->m_llMin)
				break;

			this->m_fsFile << timebuf << L"info: " << msg << std::endl;

			if(this->m_hConsole != NULL)
			{
				SetConsoleTextAttribute(this->m_hConsole, 2);
				std::wcout << timebuf << msg << std::endl;
				SetConsoleTextAttribute(this->m_hConsole, 7);
			};
		} break;
	case LOG_IMPORTANT:
		{
			if(LOG_IMPORTANT < this->m_llMin)
				break;

			this->m_fsFile << timebuf << L"important: " << msg << std::endl;

			if(this->m_hConsole != NULL)
			{
				SetConsoleTextAttribute(this->m_hConsole, 11);
				std::wcout << timebuf << msg << std::endl;
				SetConsoleTextAttribute(this->m_hConsole, 7);
			};
		} break;
	case LOG_WARNING:
		{
			if(LOG_WARNING < this->m_llMin)
				break;

			this->m_fsFile << timebuf << L"# warning: " << msg << std::endl;

			if(this->m_hConsole != NULL)
			{
				SetConsoleTextAttribute(this->m_hConsole, 14);
				std::wcout << timebuf << msg << std::endl;
				SetConsoleTextAttribute(this->m_hConsole, 7);
			};
		} break;
	case LOG_ERROR:
		{
			if(LOG_ERROR < this->m_llMin)
				break;

			this->m_fsFile << timebuf << L"# error: " << msg << std::endl;

			wchar_t* buf = new wchar_t[255];
			swprintf_s(buf, 255, L"Error:\n\n%s", msg);
			MessageBoxW(0, buf, L"G2Ext", MB_OK | MB_ICONERROR | MB_APPLMODAL);
			delete [] buf;

			if(this->m_hConsole != NULL)
			{
				SetConsoleTextAttribute(this->m_hConsole, 12);
				std::wcout << timebuf << msg << std::endl;
				SetConsoleTextAttribute(this->m_hConsole, 7);
			};
		} break;
	case LOG_CRITICAL:
		{
			this->m_fsFile << timebuf << L"## critical error: " << msg << std::endl;

			wchar_t* buf = new wchar_t[255];
			swprintf_s(buf, 255, L"Critical error:\n\n%s\n\nG2Ext must be terminated.", msg);
			MessageBoxW(0, buf, L"G2Ext", MB_OK | MB_ICONERROR | MB_APPLMODAL);
			delete [] buf;

			if(this->m_hConsole != NULL)
			{
				SetConsoleTextAttribute(this->m_hConsole, 12);
				std::wcout << timebuf << msg << std::endl;
				SetConsoleTextAttribute(this->m_hConsole, 7);
			};

			this->Close();
			exit(0);
		} break;
	};

	this->m_pCritical->LeaveCS();
};

void CLog::WriteF(LOG_LEVEL eLogLevel, const wchar_t* wcFormat, ...) // -- rewritten
{
	static wchar_t wcBuf[1024] = {0};

	va_list pArg = NULL;
	va_start(pArg, wcFormat);
	vswprintf(wcBuf, 1024, wcFormat, pArg);
	va_end(pArg);

	this->Write(eLogLevel, wcBuf);
};

HANDLE CLog::GetConsoleHandle(void)
{
	return this->m_hConsole;
};

LOG_LEVEL CLog::GetMinLogLevel(void)
{
	return this->m_llMin;
};

void CLog::SetMinLogLevel(LOG_LEVEL eloglevel)
{
	this->m_llMin = eloglevel;
};

void CLog::Divider(void)
{
	this->Write(LOG_NONE_NTS, L"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
};

void CLog::zERROR_Hijack(void)
{
	CCoreIngame::GetInstance()->CreateHook(L"G2EXT_ZERROR_HIJACK", (void*)0x0044C8D0, &CLog::zERROR_Report, false, 8);
	this->m_pCritical = new CCriticalSection();
	CreateThread(NULL, NULL, CLog::zERROR_Thread, NULL, NULL, NULL);
};

//.text:0044C8D0 ; public: int __thiscall zERROR::Report(enum  zERROR_TYPE, int, class zSTRING const &, signed char, unsigned int, int, char *, char *)
void __stdcall CLog::zERROR_Report(zERROR_TYPE& eType, int& unk0, zSTRING*& zsMsg, signed char&, unsigned int&, int&, char *&, char *&)
{
	CLog::GetInstance()->m_pCritical->EnterCS();

	LOG_LEVEL ll;
	switch(eType)
	{
	case zERROR_OK:			ll = LOG_NONE; break;
	case zERROR_INFO:		ll = LOG_INFO; break;
	case zERROR_WARNING:	ll = LOG_WARNING; break;
	case zERROR_FAULT:		ll = LOG_ERROR; break;
	case zERROR_FATAL:		ll = LOG_CRITICAL; break;
	default:				ll = LOG_NONE; break;
	};

	CLog::GetInstance()->m_lstOut.push_back(std::make_pair<LOG_LEVEL, LPCWSTR>(ll, strtowcs(zsMsg->ToChar())));

	CLog::GetInstance()->m_pCritical->LeaveCS();
};

DWORD __stdcall CLog::zERROR_Thread(void* pParam)
{
	while(true)
	{
		for each(std::pair<LOG_LEVEL, LPCWSTR> l in CLog::GetInstance()->m_lstOut)
		{
			CLog::GetInstance()->Write(l.first, l.second);
		};

		CLog::GetInstance()->m_lstOut.clear();

		Sleep(25);
	};

	return 0;
};