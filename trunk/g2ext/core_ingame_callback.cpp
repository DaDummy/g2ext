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
#include "libinject.h"
#include "console.h"

#include "api/g2/zcparser.h"
#include "api/g2/zcview.h"

//////////////////////////////////////////////////////////////////////////

LPCWSTR GetCallbackNameByID(G2EXT_CALLBACKTYPE cbType)
{
	switch(cbType)
	{
	case G2EXT_CB_ON_PAUSE:						return L"G2EXT_CB_ON_PAUSE"; break;
	case G2EXT_CB_ON_UNPAUSE:					return L"G2EXT_CB_ON_UNPAUSE"; break;
	case G2EXT_CB_ON_OPEN_LOADSCREEN:			return L"G2EXT_CB_ON_OPEN_LOADSCREEN"; break;
	case G2EXT_CB_ON_OPEN_SAVESCREEN:			return L"G2EXT_CB_ON_OPEN_SAVESCREEN"; break;
	case G2EXT_CB_ON_CLOSE_LOADSCREEN:			return L"G2EXT_CB_ON_CLOSE_LOADSCREEN"; break;
	case G2EXT_CB_ON_CLOSE_SAVESCREEN:			return L"G2EXT_CB_ON_CLOSE_SAVESCREEN"; break;
	case G2EXT_CB_ON_INGAME:					return L"G2EXT_CB_ON_INGAME"; break;
	case G2EXT_CB_ON_RENDER:					return L"G2EXT_CB_ON_RENDER"; break;
	case G2EXT_CB_ON_REGISTER_EXTERNALS:		return L"G2EXT_CB_ON_REGISTER_EXTERNALS"; break;
	case G2EXT_CB_ON_REGISTER_MENU_EXTERNALS:	return L"G2EXT_CB_ON_REGISTER_MENU_EXTERNALS"; break;
	case G2EXT_CB_ON_INIT_HUD:					return L"G2EXT_CB_ON_INIT_HUD"; break;
	case G2EXT_CB_ON_INPUT:						return L"G2EXT_CB_ON_INPUT"; break;
	case G2EXT_CB_ON_DONE:						return L"G2EXT_CB_ON_DONE"; break;
	case G2EXT_CB_ON_LOAD_WORLD:				return L"G2EXT_CB_ON_LOAD_WORLD"; break;
	case G2EXT_CB_ON_REGISTER_CLASSES:			return L"G2EXT_CB_ON_REGISTER_CLASSES"; break;
	};

	return L"(unknown cb type)";
};

bool CCoreIngame::DisableCallback(G2EXT_CALLBACKTYPE cbType, LPCWSTR lpwName)
{
	hmCallback::const_iterator it = this->m_hmCallbacks[cbType].find(lpwName);
	if(it != this->m_hmCallbacks[cbType].end())
	{
		G2EXT_LOGF_DEBUG(L"Callback '%s' of type '%s' disabled.", lpwName, GetCallbackNameByID(cbType));

		it->second->m_bActive = false;
		return true;
	};

	G2EXT_LOGF_WARNING(L"DisableCallback: Callback '%s' of type '%s' does not exist.", lpwName, GetCallbackNameByID(cbType));

	return false;
};

bool CCoreIngame::DisableAllCallbacks(void)
{
	for(UINT i = 0; i < G2EXT_CB_MAX; i++)
	{
		for each(std::pair<LPCWSTR, PCALLBACKINFO> p in this->m_hmCallbacks[i])
		{
			p.second->m_bActive = false;
		};
	};

	G2EXT_LOGF_DEBUG(L"Disabled all callbacks");

	return true;
};

bool CCoreIngame::DisableAllCallbacksOfType(G2EXT_CALLBACKTYPE cbType) 
{
	for each(std::pair<LPCWSTR, PCALLBACKINFO> p in this->m_hmCallbacks[cbType])
	{
		p.second->m_bActive = false;
	};

	G2EXT_LOGF_DEBUG(L"Disabled all Callback of type '%s'.", GetCallbackNameByID(cbType));

	return true;
};

//////////////////////////////////////////////////////////////////////////

bool CCoreIngame::EnableCallback(G2EXT_CALLBACKTYPE cbType, LPCWSTR lpwName)
{
	hmCallback::const_iterator it = this->m_hmCallbacks[cbType].find(lpwName);
	if(it != this->m_hmCallbacks[cbType].end())
	{
		G2EXT_LOGF_DEBUG(L"Callback '%s' of type '%s' enabled.", lpwName, GetCallbackNameByID(cbType));

		it->second->m_bActive = true;
		return true;
	};

	G2EXT_LOGF_WARNING(L"EnableCallback: Callback '%s' of type '%s' does not exist.", lpwName, GetCallbackNameByID(cbType));

	return false;
};

bool CCoreIngame::EnableAllCallbacks(void)
{
	for(UINT i = 0; i < G2EXT_CB_MAX; i++)
	{
		for each(std::pair<LPCWSTR, PCALLBACKINFO> p in this->m_hmCallbacks[i])
		{
			p.second->m_bActive = true;
		};
	};

	G2EXT_LOGF_DEBUG(L"Enabled all callbacks");

	return true;
};

bool CCoreIngame::EnableAllCallbacksOfType(G2EXT_CALLBACKTYPE cbType)
{
	for each(std::pair<LPCWSTR, PCALLBACKINFO> p in this->m_hmCallbacks[cbType])
	{
		p.second->m_bActive = true;
	};

	G2EXT_LOGF_WARNING(L"Enabled all Callback of type '%s'.", GetCallbackNameByID(cbType));

	return true;
};

//////////////////////////////////////////////////////////////////////////

bool CCoreIngame::IsCallbackEnabled(G2EXT_CALLBACKTYPE cbType, LPCWSTR lpwName)
{
	hmCallback::const_iterator it = this->m_hmCallbacks[cbType].find(lpwName);
	if(it != this->m_hmCallbacks[cbType].end())
	{
		G2EXT_LOGF_DEBUG(L"Status of callback '%s' of type '%s': %d", lpwName, GetCallbackNameByID(cbType), it->second->m_bActive);

		return it->second->m_bActive;
	};

	G2EXT_LOGF_DEBUG(L"IsCallbackEnabled: Callback '%s' of type '%s' does not exist.", lpwName, GetCallbackNameByID(cbType));

	return false;
};

//////////////////////////////////////////////////////////////////////////

void CCoreIngame::CallCallback(G2EXT_CALLBACKTYPE cbType, UINT uKey)
{
	for each(std::pair<LPCWSTR, PCALLBACKINFO> p in this->m_hmCallbacks[cbType])
	{
		if(p.second->m_bActive)
		{
			switch(cbType)
			{
			case G2EXT_CB_ON_REGISTER_EXTERNALS:
				{
					void(__stdcall * f)(zCParser*) = static_cast<void(__stdcall*)(zCParser*)>(p.second->m_pCallback);
					f(zCParser::GetParser());
				} break;

			case G2EXT_CB_ON_INIT_HUD:
				{
					void(__stdcall * f)(zCView*) = static_cast<void(__stdcall*)(zCView*)>(p.second->m_pCallback);
					f(zCView::GetScreen());
				} break;

			case G2EXT_CB_ON_INPUT:
				{
					void(__stdcall * f)(unsigned int) = static_cast<void(__stdcall*)(unsigned int)>(p.second->m_pCallback);
					f(uKey); 
				} break;

			default:
				{
					void(__stdcall * f)() = static_cast<void(__stdcall*)()>(p.second->m_pCallback);
					f();
				} break;
			};
		};
	};
};

//////////////////////////////////////////////////////////////////////////

bool CCoreIngame::RegisterCallback(LPCWSTR lpwName, void* pCallback, G2EXT_CALLBACKTYPE cbType, bool bActive)
{
	G2EXT_LOGF_DEBUG(L"Registering callback '%s' @ 0x%X of type '%s' (active = %d)", lpwName, pCallback, GetCallbackNameByID(cbType), bActive);

	hmCallback::const_iterator it = this->m_hmCallbacks[cbType].find(lpwName);
	if(it == this->m_hmCallbacks[cbType].end())
	{
		this->m_hmCallbacks[cbType].insert(std::make_pair<LPCWSTR, PCALLBACKINFO>(lpwName, new CALLBACKINFO(lpwName, pCallback, cbType, bActive)));
		return true;
	};

	G2EXT_LOGF_WARNING(L"RegisterCallback: A callback with the name '%s' of type '%s' already exists!", lpwName, GetCallbackNameByID(cbType));

	return false;
};

bool CCoreIngame::UnRegisterCallback(G2EXT_CALLBACKTYPE cbType, LPCWSTR lpwName)
{
	G2EXT_LOGF_DEBUG(L"Unregistering callback '%s' of type '%s'", lpwName, GetCallbackNameByID(cbType));

	hmCallback::const_iterator it = this->m_hmCallbacks[cbType].find(lpwName);
	if(it != this->m_hmCallbacks[cbType].end())
	{
		this->m_hmCallbacks[cbType].erase(it);
		return true;
	};

	G2EXT_LOGF_WARNING(L"UnRegisterCallback: Callback '%s' of type '%s' does not exist.", lpwName, GetCallbackNameByID(cbType));

	return false;
};