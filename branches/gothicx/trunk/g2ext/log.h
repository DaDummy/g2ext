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

#ifndef __G2EXT_LOG_H__
#define __G2EXT_LOG_H__

#include "common/osheader.h"

#include "api/log.h"
#ifdef _G2EXT_COMPILE_SPACER
#include "api/spacer/ztypes.h"
#else //_G2EXT_COMPILE_SPACER
#include "api/g2/ztypes.h"
#endif //_G2EXT_COMPILE_SPACER
#include "mtutils.h"
#include "singleton.h"
#include <hash_map>
#include <fstream>

//////////////////////////////////////////////////////////////////////////

#ifndef LOG_LEVEL_DEFINED
#define LOG_LEVEL_DEFINED

enum LOG_LEVEL
{
	LOG_NONE		= 0,
	LOG_NONE_NTS	= 1,
	LOG_DEBUG		= 25,
	LOG_INFO		= 50,
	LOG_IMPORTANT	= 100,
	LOG_WARNING		= 150,
	LOG_ERROR		= 200,
	LOG_CRITICAL	= 255,
};

#endif //LOG_LEVEL_DEFINED

class CLog : public TSingleton<CLog>, public ILog
{
private:
	std::wfstream								m_fsFile;
	HANDLE										m_hConsole;
	LOG_LEVEL									m_llMin;
	bool										m_bInitialized;
	LPCWSTR										m_lpFileName;
	CCriticalSection*							m_pCritical;
	std::list<std::pair<LOG_LEVEL, LPCWSTR>>	m_lstOut;
public:
	void				Close(void);
	bool				Open(LPCWSTR lpcFileName, bool bAllocDebugCMD = false, LOG_LEVEL llMinLogLevel = LOG_NONE);
	void				Divider(void);
	HANDLE				GetConsoleHandle(void);
	LOG_LEVEL			GetMinLogLevel(void);
	void				Write(LOG_LEVEL eLogLevel, const wchar_t* wcMessage);
	void				WriteF(LOG_LEVEL eLogLevel, const wchar_t* wcFormat, ...);
	void				SetMinLogLevel(LOG_LEVEL eLogLevel);

	enum zERROR_TYPE
	{
		zERROR_OK,
		zERROR_INFO,
		zERROR_WARNING,
		zERROR_FAULT,
		zERROR_FATAL
	};

	void					zERROR_Hijack(void);
	//.text:0044C8D0 ; public: int __thiscall zERROR::Report(enum  zERROR_TYPE, int, class zSTRING const &, signed char, unsigned int, int, char *, char *)
	static void	 __stdcall 	zERROR_Report(zERROR_TYPE& eType, int& unk0, zSTRING*& zsMsg, signed char&, unsigned int&, int&, char *&, char *&);
	static DWORD __stdcall	zERROR_Thread(void* pParam);
};

#define G2EXT_LOG_DIVIDE() \
	CLog::GetInstance()->Divider();

#define G2EXT_LOG(ll, msg) \
	CLog::GetInstance()->Write(ll, msg);

#define G2EXT_LOGF(ll, ...) \
	CLog::GetInstance()->Write(ll, __VA_ARGS__);

#define G2EXT_LOG_NONE(msg) \
	CLog::GetInstance()->Write(LOG_NONE, msg);

#define G2EXT_LOG_INFO(msg) \
	CLog::GetInstance()->Write(LOG_INFO, msg);

#define G2EXT_LOG_WARNING(msg) \
	CLog::GetInstance()->Write(LOG_WARNING, msg);

#define G2EXT_LOG_ERROR(msg) \
	CLog::GetInstance()->Write(LOG_ERROR, msg);

#define G2EXT_LOG_CRITICAL(msg) \
	CLog::GetInstance()->Write(LOG_CRITICAL, msg);

#ifdef _DEBUG
#define G2EXT_LOG_DEBUG(msg) \
	CLog::GetInstance()->Write(LOG_DEBUG, msg); 
#else
#define G2EXT_LOG_DEBUG(msg)
#endif

#define G2EXT_LOGF_NONE(format, ...) \
	CLog::GetInstance()->WriteF(LOG_NONE, format, __VA_ARGS__);

#ifdef _DEBUG
#define G2EXT_LOGF_DEBUG(format, ...) \
	CLog::GetInstance()->WriteF(LOG_DEBUG, format, __VA_ARGS__); 
#else
#define G2EXT_LOGF_DEBUG(format, ...)
#endif

#define G2EXT_LOGF_INFO(format, ...) \
	CLog::GetInstance()->WriteF(LOG_INFO, format, __VA_ARGS__);

#define G2EXT_LOGF_WARNING(format, ...) \
	CLog::GetInstance()->WriteF(LOG_WARNING, format, __VA_ARGS__);

#define G2EXT_LOGF_ERROR(format, ...) \
	CLog::GetInstance()->WriteF(LOG_ERROR, format, __VA_ARGS__);

#define G2EXT_LOGF_CRITICAL(format, ...) \
	CLog::GetInstance()->WriteF(LOG_CRITICAL, format, __VA_ARGS__);

#endif // __G2EXT_LOG_H__