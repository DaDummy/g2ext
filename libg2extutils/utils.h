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

#ifndef __LIBG2EXTUTILS_UTILS_H__
#define __LIBG2EXTUTILS_UTILS_H__

#include "common/osheader.h"
#include <string>

//////////////////////////////////////////////////////////////////////////

#define cstr( ... ) _cstr( __VA_ARGS__, NULL )
#define cwcs( ... ) _cwcs( __VA_ARGS__, NULL )

LPCSTR  _cstr( LPCSTR str1, ... );
LPCWSTR _cwcs( LPCWSTR str1, ... );

char DXIKeyToChar(UINT uKey);

bool FileExists(LPCWSTR lpwFileName);
bool RenameFile(LPCWSTR lpwSource, LPCWSTR lpwDestination);

UINT FileCRC32(LPCWSTR lpwFileName);

LPCWSTR swprintf_r(LPCWSTR format, ...);
LPCSTR sprintf_r(LPCSTR format, ...);

LPCWSTR strtowcs(LPCSTR str);
LPCSTR wcstostr(LPCWSTR wcs);

wchar_t* strtopwcs(LPCSTR str);
char* wcstopstr(LPCWSTR str);

wchar_t* cwctowc(LPCWSTR cwc);
char* cctoc(LPCSTR cc);

char* substr(const char* str, size_t begin, size_t len);
wchar_t* subwcs(const wchar_t* str, size_t begin, size_t len);

const wchar_t* wcstoupper(wchar_t* str);
const wchar_t* wcstolower(wchar_t* str);

const char* strtoupper(char* str);
const char* strtolower(char* str);

//////////////////////////////////////////////////////////////////////////

#define G2EXT_DELETE( obj ) if (obj != NULL){delete obj;obj = NULL;}
#define G2EXT_DELETE_VIEW( obj ) if (obj != NULL){obj->ClrPrintwin(); delete obj;obj = NULL;}

#ifdef _DEBUG
#define G2EXT_DEBUG( action ) action
#define G2EXT_DEBUG_ELSE( action ) else { action }
#define G2EXT_NDEBUG( action )
#define G2EXT_NDEBUG_ELSE( action )
#define G2EXT_DEBUGVAR( var, val_debug, val_release ) var = val_debug 
#elif _RELEASE_W_DEBUG
#define G2EXT_DEBUG( action ) action
#define G2EXT_DEBUG_ELSE( action ) else { action }
#define G2EXT_NDEBUG( action ) action
#define G2EXT_NDEBUG_ELSE( action )
#define G2EXT_DEBUGVAR( var, val_debug, val_release ) var = val_debug 
#else //_DEBUG
#define G2EXT_DEBUG( action )
#define G2EXT_DEBUG_ELSE( action )
#define G2EXT_NDEBUG( action ) action
#define G2EXT_NDEBUG_ELSE( action ) else { action }
#define G2EXT_DEBUGVAR( var, val_debug, val_release ) var = val_release 
#endif //_DEBUG

#define G2EXT_TOGGLE_BOOL( var ) { if(var) var = false; else var = true; }

//////////////////////////////////////////////////////////////////////////

#endif //__LIBG2EXTUTILS_UTILS_H__