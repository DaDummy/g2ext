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

	CSimpleIni* pIni = new CSimpleIni(true, true, false);

	for(bFindRes = ((hFind = FindFirstFile(L"*.ini", &fFileData)) != NULL); bFindRes; bFindRes = FindNextFile(hFind, &fFileData))
	{
		static int i = 0;

		if(wcscmp(L"gothic.ini", wcstolower(fFileData.cFileName)) && wcscmp(L"g2ext.ini", wcstolower(fFileData.cFileName)))
		{
			PMOD pMod = new MOD();
			
			if(pIni->LoadFile(fFileData.cFileName) < SI_OK)
			{			
				continue;
			};

			wcscpy_s(pMod->wcIni, 256, fFileData.cFileName);
			wcscpy_s(pMod->wcInfoTitle, 128, pIni->GetValue(L"INFO", L"Title", L"???"));
			wcscpy_s(pMod->wcInfoVersion, 128, pIni->GetValue(L"INFO", L"Version", L""));
			wcscpy_s(pMod->wcInfoAuthors, 128, pIni->GetValue(L"INFO", L"Authors", L""));
			wcscpy_s(pMod->wcInfoWebpage, 128, pIni->GetValue(L"INFO", L"Webpage", L""));
			wcscpy_s(pMod->wcInfoDescription, 512, pIni->GetValue(L"INFO", L"Description", L""));
			wcscpy_s(pMod->wcInfoIcon, 128, pIni->GetValue(L"INFO", L"Icon", L""));
			wcscpy_s(pMod->wcFilesVDF, 128, pIni->GetValue(L"FILES", L"VDF", L""));
			wcscpy_s(pMod->wcSettingsPlayer, 128, pIni->GetValue(L"SETTINGS", L"Player", L"PC_Hero"));
			wcscpy_s(pMod->wcSettingsZEN, 128, pIni->GetValue(L"SETTINGS", L"ZEN", L"NewWorld/NewWorld.zen"));
			wcscpy_s(pMod->wcG2ExtDLL, 128, pIni->GetValue(L"G2EXT", L"DLL", L""));
			wcscpy_s(pMod->wcG2ExtPLUGINS, 256, pIni->GetValue(L"G2EXT", L"PLUGINS", L""));

			this->m_vMods.push_back(pMod);

			this->InsertItemIntoListView(pMod->wcInfoTitle, pMod->wcInfoVersion, pMod->wcInfoAuthors);

			pIni->Reset();

			i++;
		};
	};

	if(!this->m_vMods.empty())
	{
		this->m_pSelectedMod = this->m_vMods[0];
	}
	else
	{
		this->m_pSelectedMod = NULL;
	};

	G2EXT_DELETE(pIni);
};