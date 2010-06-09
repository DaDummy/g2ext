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
#include "libinject.h"

//////////////////////////////////////////////////////////////////////////

bool CCoreIngame::CreateHook(LPCWSTR lpwName, void* pDestination, void* pCallBack, bool bRegisterAccess, UINT uParamCount)
{
	if(lpwName == L"")
	{	
		G2EXT_LOG_WARNING(L"Hook: No name given.");
		return false;
	};

	if(pDestination == NULL)
	{	
		G2EXT_LOGF_WARNING(L"Hook '%s': Destination address equals zero.", lpwName);
		return false;
	};

	if(pCallBack == NULL)
	{	
		G2EXT_LOGF_WARNING(L"Hook '%s': Callback address equals zero.", lpwName);
		return false;
	};

	if(this->m_hmHooks.find(lpwName) != this->m_hmHooks.end())
	{
		G2EXT_LOGF_WARNING(L"Hook '%s': Hook with that name already existing!", lpwName);	
		return false;
	};

	UINT nHookHandle = 0;

	if((nHookHandle = libInject::CreateHook(pDestination, pCallBack, bRegisterAccess, uParamCount)) == 0)
	{
		G2EXT_LOGF_WARNING(L"Hook '%s': Could not attach hook!", lpwName);	
		return false;
	};

	this->m_hmHooks.insert(std::make_pair<LPCWSTR, UINT>(lpwName, nHookHandle));

	G2EXT_LOGF_DEBUG(L"Hook '%s': Attached hook to 0x%X with callback to 0x%X", lpwName, pDestination, pCallBack);

	return true;
};

//////////////////////////////////////////////////////////////////////////

bool CCoreIngame::CreateConditionalHook_C(LPCWSTR lpwName, void* pDestination, void* pCallBack, void* pConditionVar, bool bRegisterAccess, UINT uParamCount)
{
	if(lpwName == L"")
	{	
		G2EXT_LOG_WARNING(L"Hook: No name given.");
		return false;
	};

	if(pDestination == NULL)
	{	
		G2EXT_LOGF_WARNING(L"Hook '%s': Destination address equals zero.", lpwName);
		return false;
	};

	if(pCallBack == NULL)
	{	
		G2EXT_LOGF_WARNING(L"Hook '%s': Callback address equals zero.", lpwName);
		return false;
	};

	if(this->m_hmHooks.find(lpwName) != this->m_hmHooks.end())
	{
		G2EXT_LOGF_WARNING(L"Hook '%s': Hook with that name already existing!", lpwName);	
		return false;
	};

	UINT nHookHandle = 0;

	if((nHookHandle = libInject::ConditionalHook_C(pDestination, pCallBack, pConditionVar, bRegisterAccess, uParamCount)) == 0)
	{
		G2EXT_LOGF_WARNING(L"Hook '%s': Could not attach hook!", lpwName);	
		return false;
	};

	this->m_hmHooks.insert(std::make_pair<LPCWSTR, UINT>(lpwName, nHookHandle));

	G2EXT_LOGF_DEBUG(L"Hook '%s': Attached hook to 0x%X with callback to 0x%X", lpwName, pDestination, pCallBack);

	return true;
};

//////////////////////////////////////////////////////////////////////////

bool CCoreIngame::CreateConditionalHook_C_N(LPCWSTR lpwName, void* pDestination, void* pCallBack, void* pConditionVar, bool bRegisterAccess, UINT uParamCount)
{
	if(lpwName == L"")
	{	
		G2EXT_LOG_WARNING(L"Hook: No name given.");
		return false;
	};

	if(pDestination == NULL)
	{	
		G2EXT_LOGF_WARNING(L"Hook '%s': Destination address equals zero.", lpwName);
		return false;
	};

	if(pCallBack == NULL)
	{	
		G2EXT_LOGF_WARNING(L"Hook '%s': Callback address equals zero.", lpwName);
		return false;
	};

	if(this->m_hmHooks.find(lpwName) != this->m_hmHooks.end())
	{
		G2EXT_LOGF_WARNING(L"Hook '%s': Hook with that name already existing!", lpwName);	
		return false;
	};

	UINT nHookHandle = 0;

	if((nHookHandle = libInject::ConditionalHook_C_N(pDestination, pCallBack, pConditionVar, bRegisterAccess, uParamCount)) == 0)
	{
		G2EXT_LOGF_WARNING(L"Hook '%s': Could not attach hook!", lpwName);	
		return false;
	};

	this->m_hmHooks.insert(std::make_pair<LPCWSTR, UINT>(lpwName, nHookHandle));

	G2EXT_LOGF_DEBUG(L"Hook '%s': Attached hook to 0x%X with callback to 0x%X", lpwName, pDestination, pCallBack);

	return true;
};

//////////////////////////////////////////////////////////////////////////

bool CCoreIngame::CreateConditionalHook_R(LPCWSTR lpwName, void* pDestination, void* pCallBack, REGISTER eRegister, int nConditionVar, bool bRegisterAccess, UINT uParamCount)
{
	if(lpwName == L"")
	{	
		G2EXT_LOG_WARNING(L"Hook: No name given.");
		return false;
	};

	if(pDestination == NULL)
	{	
		G2EXT_LOGF_WARNING(L"Hook '%s': Destination address equals zero.", lpwName);
		return false;
	};

	if(pCallBack == NULL)
	{	
		G2EXT_LOGF_WARNING(L"Hook '%s': Callback address equals zero.", lpwName);
		return false;
	};

	if(this->m_hmHooks.find(lpwName) != this->m_hmHooks.end())
	{
		G2EXT_LOGF_WARNING(L"Hook '%s': Hook with that name already existing!", lpwName);	
		return false;
	};

	UINT nHookHandle = 0;

	if((nHookHandle = libInject::ConditionalHook_R(pDestination, pCallBack, static_cast<eRegs>(eRegister), nConditionVar, bRegisterAccess, uParamCount)) == 0)
	{
		G2EXT_LOGF_WARNING(L"Hook '%s': Could not attach hook!", lpwName);	
		return false;
	};

	this->m_hmHooks.insert(std::make_pair<LPCWSTR, UINT>(lpwName, nHookHandle));

	G2EXT_LOGF_DEBUG(L"Hook '%s': Attached hook to 0x%X with callback to 0x%X", lpwName, pDestination, pCallBack);

	return true;
};

//////////////////////////////////////////////////////////////////////////

bool CCoreIngame::ReplaceFunction(LPCWSTR lpwName, void* pDestination, void* pNewFunc)
{
	if(lpwName == L"")
	{	
		G2EXT_LOG_WARNING(L"Hook: No name given.");
		return false;
	};

	if(pDestination == NULL)
	{	
		G2EXT_LOGF_WARNING(L"Hook '%s': Destination address equals zero.", lpwName);
		return false;
	};

	if(pNewFunc == NULL)
	{	
		G2EXT_LOGF_WARNING(L"Hook '%s': Callback address equals zero.", lpwName);
		return false;
	};

	if(this->m_hmHooks.find(lpwName) != this->m_hmHooks.end())
	{
		G2EXT_LOGF_WARNING(L"Hook '%s': Hook with that name already existing!", lpwName);	
		return false;
	};

	UINT nHookHandle = 0;

	if((nHookHandle = libInject::ReplaceFunction(pDestination, pNewFunc)) == 0)
	{
		G2EXT_LOGF_WARNING(L"Hook '%s': Could not replace function!", lpwName);	
		return false;
	};

	this->m_hmHooks.insert(std::make_pair<LPCWSTR, UINT>(lpwName, nHookHandle));

	G2EXT_LOGF_DEBUG(L"Hook '%s': Replaced function 0x%X with 0x%X", lpwName, pDestination, pNewFunc);

	return true;
};

//////////////////////////////////////////////////////////////////////////

bool CCoreIngame::RedirectCall(LPCWSTR lpwName, void* pDestination, void* pNewFunc)
{
	if(lpwName == L"")
	{	
		G2EXT_LOG_WARNING(L"Hook: No name given.");
		return false;
	};

	if(pDestination == NULL)
	{	
		G2EXT_LOGF_WARNING(L"Hook '%s': Destination address equals zero.", lpwName);
		return false;
	};

	if(pNewFunc == NULL)
	{	
		G2EXT_LOGF_WARNING(L"Hook '%s': Callback address equals zero.", lpwName);
		return false;
	};

	if(this->m_hmHooks.find(lpwName) != this->m_hmHooks.end())
	{
		G2EXT_LOGF_WARNING(L"Hook '%s': Hook with that name already existing!", lpwName);	
		return false;
	};

	UINT nHookHandle = 0;

	if((nHookHandle = libInject::RedirectCall(pDestination, pNewFunc)) == 0)
	{
		G2EXT_LOGF_WARNING(L"Hook '%s': Could not replace function!", lpwName);	
		return false;
	};

	this->m_hmHooks.insert(std::make_pair<LPCWSTR, UINT>(lpwName, nHookHandle));

	G2EXT_LOGF_DEBUG(L"Hook '%s': Replaced call 0x%X with 0x%X", lpwName, pDestination, pNewFunc);

	return true;
};

void CCoreIngame::RemoveHook(LPCWSTR lpwName)
{
	hmHook::const_iterator it = this->m_hmHooks.find(lpwName);
	if(it != this->m_hmHooks.end())
		libInject::PerformRollback(it->second);
};

bool CCoreIngame::PatchSecuredMem(void* pDestination, const void* pBuffer, size_t szLength)
{
	G2EXT_LOGF_DEBUG(L"Patching memory block 0x%X (len: %u). Overwriting with: %s\0", pDestination, szLength, pBuffer);
	return libInject::PatchSecuredMem(pDestination, pBuffer, szLength);
};

bool CCoreIngame::EraseSecuredMem(void* pDestination, size_t szLength, int nValue)
{
	G2EXT_LOGF_DEBUG(L"Erasing memory block 0x%X (len: %u). Overwriting with value: 0x%X\0", pDestination, szLength, nValue);
	return libInject::EraseSecuredMem(pDestination, szLength, nValue);
};