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

#ifndef __G2EXT_MTUTILS_H__
#define __G2EXT_MTUTILS_H__

class CCriticalSection
{
private:
	CRITICAL_SECTION m_csCS;
public:
	inline CCriticalSection() throw()
	{
		InitializeCriticalSection(&this->m_csCS);
	};

	inline ~CCriticalSection() throw()
	{
		DeleteCriticalSection(&this->m_csCS);
	};

	inline void EnterCS() throw()
	{
		EnterCriticalSection(&this->m_csCS);
	};

	inline void LeaveCS() throw()
	{
		LeaveCriticalSection(&this->m_csCS);
	};
};

#endif  //__G2EXT_MTUTILS_H__