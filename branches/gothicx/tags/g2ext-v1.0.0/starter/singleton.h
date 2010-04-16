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

#ifndef __G2EXT_SINGLETON_H__
#define __G2EXT_SINGLETON_H__

template<class T>
class TSingleton
{
protected:
	static T* m_pInstance;
public:
	virtual ~TSingleton() {};

	inline static T* GetInstance()
	{
		if(!m_pInstance)
			m_pInstance = new T();

		return m_pInstance;
	};

	static void DeleteInstance()
	{
		if(m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = NULL;
		};
	};
};

template<class T>
T* TSingleton<T>::m_pInstance = NULL;

#endif  //__G2EXT_SINGLETON_H__