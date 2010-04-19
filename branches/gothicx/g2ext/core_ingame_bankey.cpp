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

#include "core.h"
#include "log.h"

// TODO: Use other method for bankey...

bool CCoreIngame::BanKey(unsigned int uKey)
{
	// ALL BANABLE EXCEPT:
	// Space key
	// Movement keys (WASD; Key UP/DOWN/LEFT/RIGHT; ENTF; PAGE DOWN; CTRL L; CTRL R; ALT)
	// Camera keys (F, Numpad 0)
	// ESC

	for each(unsigned int uBanKey in this->m_vBannedKeys)
	{
		if (uBanKey == uKey) return false;
	};

	//G2EXT_LOGF_DEBUG(L"Banned key: 0x%X", uKey);

	this->m_vBannedKeys.push_back(uKey);

	return true;
};

bool CCoreIngame::UnBanKey(unsigned int uKey)
{
	if(!this->m_vBannedKeys.empty())
		for(std::vector<unsigned int>::iterator it = this->m_vBannedKeys.begin(); it != this->m_vBannedKeys.end(); it++)
		{
			if(*it == uKey)
			{
				this->m_vBannedKeys.erase(it);
				G2EXT_LOGF_DEBUG(L"Unbanned key: 0x%X", uKey);
				return true;
			};
		};

	return false;
};

void CCoreIngame::CheckForBannedKey(unsigned int & uKey)
{
	if(!this->m_hmRedirectKeys.empty())
		for(hmKey::iterator it = this->m_hmRedirectKeys.begin(); it != this->m_hmRedirectKeys.end(); it++)
		{
			if(it->first == uKey)
			{
				G2EXT_LOGF_DEBUG(L"Redirect: orig key: 0x%X redirect key: 0x%X", uKey);
				uKey = (unsigned int)it->second;
				return;
			};
		};

	for each(unsigned int uBanKey in this->m_vBannedKeys)
	{
		if (uBanKey == uKey)
		{
			G2EXT_LOGF_DEBUG(L"Banned key detected: 0x%X", uKey);
			uKey = (unsigned int)0x00;
			return;
		};
	};
};

bool CCoreIngame::RemapKey(unsigned int uOrigKey, unsigned int uRedirectKey)
{
	hmKey::const_iterator it = this->m_hmRedirectKeys.find(uOrigKey);

	if (it != this->m_hmRedirectKeys.end())
		return false;

	this->m_hmRedirectKeys.insert(std::make_pair<unsigned int, unsigned int>(uOrigKey, uRedirectKey));

	return true;
};

bool CCoreIngame::UnRemapKey(unsigned int uOrigKey)
{
	hmKey::const_iterator it = this->m_hmRedirectKeys.find(uOrigKey);

	if (it != this->m_hmRedirectKeys.end())
	{
		this->m_hmRedirectKeys.erase(it);
		return true;
	};

	return false;
};
