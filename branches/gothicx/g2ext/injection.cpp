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

#include "injection.h"

CInjection::CInjection ( HANDLE p_hProcess, std::string p_sName )
{
	this->m_hProcess	= p_hProcess;
	this->m_lpDest	= NULL;
	this->m_lpTmp		= NULL;
	this->m_szLen		= 0;
	this->m_bOwnDest	= false;
	this->m_bFinished	= false;
	this->m_sName     = p_sName;
}

CInjection::~CInjection ( )
{
	if ( this->m_bFinished )
	{
		this->m_lpDest	= NULL;
		this->m_bOwnDest	= false;
		this->m_bFinished	= false;
	}

	if ( this->m_lpTmp != NULL )
	{
		free( (void*)this->m_lpTmp );
		this->m_lpTmp = NULL;
	}

	this->m_hProcess	= NULL;
	this->m_szLen		= 0;
}

bool CInjection::Finish( ptr_t p_lpDest, DWORD p_flProtect )
{
	if ( this->m_bFinished )
	{
		if ( this->m_lpDest == p_lpDest || p_lpDest == NULL )
			return true;
		else
			return false;
	}

	this->m_lpDest	= p_lpDest;
	this->m_bOwnDest	= false;
	
	if ( this->m_lpDest == NULL )
	{
		this->m_lpDest = (ptr_t)VirtualAllocEx( this->m_hProcess, NULL, this->m_szLen, MEM_RESERVE | MEM_COMMIT, p_flProtect );

		if ( this->m_lpDest == NULL )
			return false;

		this->m_bOwnDest	= true;
	}

	this->m_bFinished	= true;

	return true;
}

bool CInjection::Write ( )
{
	DWORD	dwOldProt;
	size_t	sNumBytesWritten;

	if ( !this->m_bFinished )
	{
		if ( this->m_szLen == 0 )
			return true;
		else
			return false;
	}

	if ( this->m_lpTmp == NULL || this->m_szLen == 0 )
		return false;

	if ( !VirtualProtectEx( this->m_hProcess, (void*)this->m_lpDest, this->m_szLen, PAGE_READWRITE, &dwOldProt ) )
		return false;

	if ( !WriteProcessMemory( this->m_hProcess, (void*)this->m_lpDest, (void*)this->m_lpTmp, this->m_szLen, (SIZE_T *)&sNumBytesWritten ) )
		sNumBytesWritten = 0; // make sure we return false later on

	if ( !VirtualProtectEx( this->m_hProcess, (void*)this->m_lpDest, this->m_szLen, dwOldProt, &dwOldProt ) )
		return false;

	return ( this->m_szLen == sNumBytesWritten );
}

uint32_t CInjection::Add( ptr_t p_lpSrc, size_t p_sLen )
{
	if ( this->m_bFinished )
		return G2EXT_INVALID_OFFSET;

	if ( p_lpSrc == NULL )
		return G2EXT_INVALID_OFFSET;
	
	if ( this->m_lpTmp == NULL )
	{
		this->m_lpTmp	= (ptr_t)malloc( this->m_szLen + p_sLen );

		if ( this->m_lpTmp == NULL )
			return G2EXT_INVALID_OFFSET;
	}
	else
	{
		ptr_t l_lpTmp = (ptr_t)realloc( (void*)this->m_lpTmp, this->m_szLen + p_sLen );

		if ( l_lpTmp == NULL )
			return G2EXT_INVALID_OFFSET;

		this->m_lpTmp = l_lpTmp;
	}

	uint32_t iOffset = (uint32_t)this->m_szLen;

	this->m_szLen = this->m_szLen + p_sLen;

	if ( memcpy_s( (void*)(this->m_lpTmp + iOffset), p_sLen, (void*)p_lpSrc, p_sLen ) != 0 )
		return G2EXT_INVALID_OFFSET;

	return iOffset;
}
uint32_t CInjection::Add( std::string p_sString )
{
	return this->Add( (ptr_t)p_sString.c_str(), (p_sString.length() + 1) * sizeof(char) );
}
uint32_t CInjection::Add( std::wstring p_wsString )
{
	return this->Add( wcstostr( p_wsString.c_str() ) );
}
uint32_t CInjection::Add( uint32_t p_dword )
{
	return this->Add( (ptr_t)&p_dword, sizeof(uint32_t) );
}
uint32_t CInjection::Add( uint16_t p_word )
{
	return this->Add( (ptr_t)&p_word, sizeof(uint16_t) );
}
uint32_t CInjection::Add( uint8_t p_byte )
{
	return this->Add( (ptr_t)&p_byte, sizeof(uint8_t) );
}

ptr_t CInjection::GetDest ( )
{
	return this->m_lpDest;
}

size_t CInjection::GetLength( )
{
	return this->m_szLen;
}

ptr_t CInjection::GetTmp( )
{
	return this->m_lpTmp;
}

std::string CInjection::GetName( )
{
	return this->m_sName;
}

bool CInjection::SnrPTR( ptr_t p_ptrOffset, ptr_t p_ptrOldValue, ptr_t p_ptrNewValue, ptr_t* p_ptrRealOffset )
{
	while ( p_ptrOffset <= this->m_szLen - sizeof(ptr_t) )
	{
		if ( *(ptr_t*)(this->m_lpTmp + p_ptrOffset) == p_ptrOldValue )
		{
			if ( p_ptrRealOffset != NULL )
				*p_ptrRealOffset = p_ptrOffset;

			*(ptr_t*)(this->m_lpTmp + p_ptrOffset) = p_ptrNewValue;

			return true;
		}

		p_ptrOffset++;
	}

	return false;
}
