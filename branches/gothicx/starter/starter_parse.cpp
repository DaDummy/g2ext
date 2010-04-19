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

#include "starter.h"
#include "utils.h"

#include "SimpleIni.h"

void CStarter::SearchAndParseMods(void)
{
	WIN32_FIND_DATA	fFileData = {0};
	HANDLE hFind = NULL;
	BOOL bFindRes = 1;

	CSimpleIni* pIni = new CSimpleIni(true, false, false);

	for(bFindRes = ((hFind = FindFirstFile(L"*.ini", &fFileData)) != NULL); bFindRes; bFindRes = FindNextFile(hFind, &fFileData))
	{
		// This is permanent - no need to call it multiple times
		wcstolower(fFileData.cFileName);

		if(wcscmp(L"gothic.ini", fFileData.cFileName) && wcscmp(L"g2ext.ini", fFileData.cFileName))
		{
			PMOD pMod = new MOD();
			
			if(pIni->LoadFile(fFileData.cFileName) < SI_OK)
			{			
				continue;
			};

			pMod->wcIni				= fFileData.cFileName;
			pMod->wcInfoTitle		= pIni->GetValue(L"INFO", L"Title", L"???");
			pMod->wcInfoVersion		= pIni->GetValue(L"INFO", L"Version", L"");
			pMod->wcInfoAuthors		= pIni->GetValue(L"INFO", L"Authors", L"");
			pMod->wcInfoWebpage		= pIni->GetValue(L"INFO", L"Webpage", L"");
			pMod->wcInfoDescription	= pIni->GetValue(L"INFO", L"Description", L"");
			pMod->wcInfoIcon		= pIni->GetValue(L"INFO", L"Icon", L"");
			pMod->wcFilesVDF		= pIni->GetValue(L"FILES", L"VDF", L"");
			pMod->wcSettingsPlayer	= pIni->GetValue(L"SETTINGS", L"Player", L"PC_Hero");
			pMod->wcSettingsZEN		= pIni->GetValue(L"SETTINGS", L"ZEN", L"NewWorld/NewWorld.zen");
			pMod->wcG2ExtDLL		= pIni->GetValue(L"G2EXT", L"DLL", L"");
			pMod->wcG2ExtPLUGINS	= pIni->GetValue(L"G2EXT", L"PLUGINS", L"");
			pMod->wcG2ExtSpacerDLL	= pIni->GetValue(L"G2EXT_SPACER", L"DLL", L"");

			this->m_vMods.push_back(pMod);

			this->InsertItemIntoListView(pMod->wcInfoTitle.c_str(), pMod->wcInfoVersion.c_str(), pMod->wcInfoAuthors.c_str());

			pIni->Reset();
		};
	};

	FindClose(hFind);

	if(!this->m_vMods.empty())
	{
		this->m_pSelectedMod = this->m_vMods[0];
	}
	else
	{
		this->m_pSelectedMod = NULL;
	};

	delete pIni;
};