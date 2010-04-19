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

#ifndef __G2EXT_GETCODE_H__
#define __G2EXT_GETCODE_H__

#include "common/osheader.h"

#include <map>

#define GETCODE_DECLARE( name ) \
	std::map<int, ptr_t> name( )

#define GETCODE_BEGIN_EX_PTR( idx, name ) \
	__asm{mov eax, name} \
	__asm{mov lpL, eax} \
	lpPtr[idx] = lpL

#define GETCODE_BEGIN_EX_B( name ) \
	std::map<int, ptr_t> name( ) { \
	std::map<int, ptr_t> lpPtr; \
	ptr_t lpL; \
	GETCODE_BEGIN_EX_PTR( 0, func_begin ); \
	GETCODE_BEGIN_EX_PTR( 1, func_end   )

#define GETCODE_BEGIN_EX_E \
	return lpPtr; \
func_begin:

#define GETCODE_BEGIN( name ) \
	GETCODE_BEGIN_EX_B( name ); \
	GETCODE_BEGIN_EX_E;

#define GETCODE_END \
func_end:; \
}

#endif //__G2EXT_GETCODE_H__