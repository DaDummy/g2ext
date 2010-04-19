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

#ifndef __G2EXT_INJECTION_H__
#define __G2EXT_INJECTION_H__

#include "common/osheader.h"

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

#include "utils.h"

#define G2EXT_INVALID_OFFSET 0xFFFFFFFF

#include <wchar.h>
#include <string>
#include <locale>

#include "getcode.h"

// make whole string lower case
#define lcase( str ) { size_t str_len = str.length(); for (size_t i = 0; i < str_len ; i++) { str[i] = towlower( str[i] ); } }

class CInjection
{
private:
	HANDLE		m_hProcess;
	ptr_t		m_lpDest;
	ptr_t		m_lpTmp;
	size_t		m_szLen;
	bool		m_bOwnDest;
	bool		m_bFinished;
	std::string	m_sName;

public:
	CInjection	( HANDLE hProcess, std::string p_sName );
	~CInjection	( );

	bool		Finish		( ptr_t lpDest, DWORD flProtect = PAGE_READWRITE );
	bool		Write		( );
	uint32_t	Add			( ptr_t lpSrc, size_t sLen );
	uint32_t	Add			( std::wstring wsString );
	uint32_t	Add			( std::string sString );
	uint32_t	Add			( uint32_t dword );
	uint32_t	Add			( uint16_t word );
	uint32_t	Add			( uint8_t byte );
	ptr_t		GetDest		( );
	ptr_t		GetTmp		( );
	size_t		GetLength	( );
	std::string GetName		( );
	bool		SnrPTR		( ptr_t iStartOffset, ptr_t iOldValue, ptr_t iNewValue, ptr_t* ptrRealOffset = NULL );
};

#endif // __G2EXT_INJECTION_H__