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

#include "utils.h" 

#include <boost/crc.hpp>
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <locale>
#include <fstream>
#include <list>
#include <ios>

#define CRC_BUFFER_SIZE 102400

bool FileExists(LPCWSTR lpwFileName)
{
	_stat stFileInfo;
	return _wstat(lpwFileName, &stFileInfo) == 0 ? true : false;
};

bool RenameFile(LPCWSTR lpwSource, LPCWSTR lpwDestination)
{
	return _wrename(lpwSource, lpwDestination) == 0 ? true : false;
};

char DXIKeyToChar(UINT uKey)
{
	static HKL hkLayout = GetKeyboardLayout(0);
	static UCHAR ucState[256];
	UCHAR cKey[2] = {0};

	if (GetKeyboardState(ucState) == 0)
	{
		return -1;
	};

	UINT uVKey = MapVirtualKeyEx(uKey, 1, hkLayout);
	if (ToAsciiEx(uVKey, uKey, ucState, (LPWORD)cKey, 0, hkLayout) == 1)
	{	
		return cKey[0];
	};

	return -1;
};

UINT FileCRC32(LPCWSTR lpwFileName)
{
	boost::crc_32_type btCRC;

	std::ifstream ifsStream(lpwFileName, std::ios_base::binary);

	if(!ifsStream)
		return 0;

	while(ifsStream)
	{
		char cBuf[CRC_BUFFER_SIZE];

		ifsStream.read(cBuf, CRC_BUFFER_SIZE);
		btCRC.process_bytes(cBuf, ifsStream.gcount());
	};

	return btCRC.checksum();
};

/** std::string cstr( const char* str1, ... )
* combines all strings till the first empty string or NULL is spotted
*/
LPSTR _cstr(const char* str1, ...) // ATTENTION: Buffer overflows possible!!!
{
	std::list<const char*>	lTempVal;
	size_t					templen;
	char*					retstrptr;
	size_t					retstrlen;
	void*					tmpptr;
	size_t					tmplen;
	va_list					argptr;

	if ( str1 == NULL )
		return "";

	retstrlen = strlen( str1 ) + 1;

	if ( retstrlen == 1 )
		return "";

	va_start( argptr, str1 );
	do
	{
		const char* tempval = va_arg( argptr, const char* );

		if ( tempval == NULL )
			break;

		lTempVal.push_back(tempval);

		templen		= strlen( tempval );
		retstrlen	+= templen;
	}
	while ( templen != 0 );
	va_end( argptr );

	retstrptr = (char*)malloc( retstrlen * sizeof(char) );

	if ( strcpy_s( retstrptr, retstrlen, str1 ) != 0 )
	{
		free( retstrptr );
		return "";
	}

	templen	= strlen( str1 );
	tmpptr	= (void*)((int)retstrptr + ( templen * sizeof(char) ));
	tmplen	= retstrlen - templen;

	for each (const char* tempval in lTempVal)
	{
		templen	= strlen( tempval );

		if ( strcpy_s( (char*)tmpptr, tmplen, tempval ) != 0 )
			break;

		tmpptr = (void*)((int)tmpptr + (int)( templen * sizeof(char) ));
		tmplen -= templen;
	}

	return retstrptr;
}

/** std::string cwcs( const wchar_t* str1, ... )
* combines all strings till the first empty string or NULL is spotted
*/
LPWSTR _cwcs(const wchar_t* str1, ...) // ATTENTION: Buffer overflows possible!!!
{
	std::list<const wchar_t*>	lTempVal;
	size_t						templen;
	wchar_t*					retstrptr;
	size_t						retstrlen;
	void*						tmpptr;
	size_t						tmplen;
	va_list						argptr;

	if ( str1 == NULL )
		return L"";

	retstrlen = wcslen( str1 ) + 1;

	if ( retstrlen == 1 )
		return L"";

	va_start( argptr, str1 );
	do
	{
		const wchar_t* tempval = va_arg( argptr, const wchar_t* );

		if ( tempval == NULL )
			break;

		lTempVal.push_back(tempval);

		templen		= wcslen( tempval );
		retstrlen	+= templen;
	}
	while ( templen != 0 );
	va_end( argptr );

	retstrptr = (wchar_t*)malloc( retstrlen * sizeof(wchar_t) );

	if ( wcscpy_s( retstrptr, retstrlen, str1 ) != 0 )
	{
		free( retstrptr );
		return L"";
	}

	templen	= wcslen( str1 );
	tmpptr	= (void*)((int)retstrptr + (int)( templen * sizeof(wchar_t) ));
	tmplen	= retstrlen - templen;

	for each (const wchar_t* tempval in lTempVal)
	{
		templen	= wcslen( tempval );

		if ( wcscpy_s( (wchar_t*)tmpptr, tmplen, tempval ) != 0 )
			break;

		tmpptr = (void*)((int)tmpptr + ( templen * sizeof(wchar_t) ));
		tmplen -= templen;
	}

	return retstrptr;
}

const wchar_t* swprintf_r(const wchar_t* format, ...) // ATTENTION: Not threadsave! Result of last call will be invalidated on next call!
{
	static wchar_t buffer[512] = {0};

	va_list argptr;
	va_start(argptr, format);
	vswprintf_s(buffer, 512, format, argptr);
	va_end(argptr);

	return buffer;
};

const char* sprintf_r(const char* format, ...) // ATTENTION: Not threadsave! Result of last call will be invalidated on next call!
{
	static char buffer[512] = {0};

	va_list argptr;
	va_start(argptr, format);
	vsprintf_s(buffer, 512, format, argptr);
	va_end(argptr);

	return buffer;
};

wchar_t* strtowcs(const char* str)
{
	size_t		origsize		= strlen(str)+1;
	size_t		convertedChars	= 0;
	wchar_t*	wcs				= new wchar_t[origsize];
	mbstowcs_s(&convertedChars, wcs, origsize, str, _TRUNCATE);

	return wcs;
};

char* wcstostr(const wchar_t* wcs)
{
	size_t		origsize		= wcslen(wcs)+1;
	size_t		convertedChars	= 0;
	char*		str				= new char[origsize];
	wcstombs_s(&convertedChars, str, origsize, wcs, _TRUNCATE);

	return str;
};

wchar_t* cwctowc(const wchar_t* cwc)
{
	size_t sStrLen = wcslen(cwc);
	sStrLen++;
	wchar_t* wcTmp = new wchar_t[sStrLen];
	wcscpy_s(wcTmp, sStrLen, cwc);
	return wcTmp;
};

char* cctoc(const char* cc)
{
	size_t sStrLen = strlen(cc) + 1;
	char* cTmp = new char[sStrLen];
	strcpy_s(cTmp, sStrLen, cc);
	return cTmp;
};

char* substr(const char* str, size_t begin, size_t len)
{
	if (str == 0 || strlen(str) < (begin+len)) // " || strlen(str) == 0 || strlen(str) < begin" <- the last check covers this, too
		return NULL;

	char* dest = new char[len+1];
	strncpy_s(dest, len, str+begin, len);
	dest[len] = 0;
	//strncat_s(dest, strlen(str), str + begin, len);
	return dest;
};

wchar_t* subwcs(const wchar_t* str, size_t begin, size_t len)
{
	if (str == 0 || wcslen(str) < (begin+len)) //  "|| wcslen(str) == 0 || wcslen(str) < begin" <- the last check covers this, too
		return NULL;

	wchar_t* dest = new wchar_t[len+1];
	wcsncpy_s(dest, len, str+begin, len);
	dest[len] = 0;
	//wcsncat_s(dest, wcslen(str)*sizeof(wchar_t), str + begin, len);
	return dest;
};

wchar_t* wcstolower(wchar_t* str)
{
	for(unsigned int i = 0; i < wcslen(str); i++)
	{
		str[i] = towlower(str[i]);
		//if(str[i] >= 0x0041 && str[i] <= 0x005A)
		//	str[i] += 0x0020;
	};
	return str;
};

wchar_t* wcstoupper(wchar_t* str)
{
	for(unsigned int i = 0; i < wcslen(str); i++)
	{
		str[i] = towupper(str[i]);
		//if(str[i] >= 0x061 && str[i] <= 0x007A)
		//	str[i] -= 0x0020;
	};
	return str;
};

char* strtolower(char* str)
{
	for(unsigned int i = 0; i < strlen(str); i++)
	{
		str[i] = tolower(str[i]);
		//if(str[i] >= 0x41 && str[i] <= 0x5A)
		//	str[i] += 0x20;
	};
	return str;
};

char* strtoupper(char* str)
{
	for(unsigned int i = 0; i < strlen(str); i++)
	{
		str[i] = toupper(str[i]);
		//if(str[i] >= 0x61 && str[i] <= 0x7A)
		//	str[i] -= 0x20;
	};
	return str;
};

