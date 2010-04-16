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

#ifndef __G2EXT_CONSOLE_H__
#define __G2EXT_CONSOLE_H__

#include "common/osheader.h"
#include "singleton.h"

#include "api/console.h"
#include "api/g2/zcinputcallback.h"

#include <deque>
#include <vector>
#include <string>

class zCView;
class zCConsole;

class CConsole : public IConsole, public TSingleton<CConsole>, public zCInputCallback
{
friend class CCoreIngame;
private:
	std::string											m_sInput;
	std::deque<std::pair<std::string, zCOLOR>>			m_lEntries;
	std::vector<std::string>							m_vCommandoDescr;
	std::deque<std::string>								m_lCommandos;
	zCView*												m_pScreen;
	zCConsole*											m_pConsole;
	int													m_nMaxEntries;
	int													m_nLinePosition;
	int													m_nFontHeight;
	bool												m_bVisible;
	bool												m_bHooksSet;
	std::string											m_sBackgroundImage;
	std::string											m_sFont;
	bool												m_nTransparencyEnabled;
	int													m_nTransparency;
	int													m_nHeight;				// -- in lines
	zCOLOR												m_zDefaultTextColor;
	zCOLOR												m_zDefaultInputColor;
	zCOLOR												m_zDefaultResultColor;
private:
	static int 				ConsoleEval(zSTRING& c, zSTRING& r);
	static void __stdcall	ConsoleRegister(zSTRING*& c, zSTRING*& help);
	static void __stdcall	ConsoleRegister1(zSTRING*& c, zSTRING*& help, int& u);
private:
	void _OpenGameConsole();
public:
	CConsole(void);

	void Init(void);
	void Reset(void);
	void Tick(void);

	void Print(const char* out);
	void Print(const char* out, zCOLOR col);

	void Show(void);
	void Hide(void);
	bool IsVisible(void) { return this->m_bVisible; };

	void SetFocus(bool b);
	int  HandleEvent(int key);
};

#endif  //__G2EXT_CONSOLE_H__