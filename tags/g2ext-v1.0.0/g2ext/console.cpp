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

#include "console.h"

#include "core.h"
#include "stats.h"
#include "api/g2/ocgame.h"
#include "api/g2/zcview.h"
#include "api/g2/zcinput.h"
#include "api/g2/zcconsole.h"
#include "api/g2/ocworldtimer.h"
#include "common/version.h"
#include "utils.h"

#include <time.h>
#include <fstream>

#pragma warning(disable:4018) // warning C4018: '<' : signed/unsigned mismatch
#pragma warning(disable:4996) // warning C4996: '...': This function or variable may be unsafe.

CConsole::CConsole(void)
{
	this->Reset();
};

void CConsole::Reset(void)
{
	this->m_nMaxEntries				= 200;
	this->m_sBackgroundImage		= std::string("OVERLAY.TGA");
	this->m_sFont					= std::string("EXT_CONSOLE.TGA");
	this->m_nTransparencyEnabled	= false;
	this->m_nTransparency			= 255;
	this->m_nHeight					= 31;
	this->m_zDefaultTextColor		= zCOLOR(150, 150, 150, 255);
	this->m_zDefaultInputColor		= zCOLOR(0xFFFFFFFF);
	this->m_zDefaultResultColor		= zCOLOR(0xAAAAAAFF);
	this->m_sInput					= "> ";
	this->m_pConsole				= zCConsole::GetConsole();
};

void CConsole::Init(void)
{
	this->Reset();

	this->m_pScreen = zNEW(zCView(0, 0, 8192, zCView::GetScreen()->FontY()*this->m_nHeight, VIEW_ITEM));
	this->m_pScreen->SetFont(zSTRING(this->m_sFont.c_str()));
	this->m_pScreen->InsertBack(zSTRING(this->m_sBackgroundImage.c_str()));
	this->m_pScreen->SetFontColor(this->m_zDefaultTextColor);
};

void CConsole::Print(const char* out) 
{ 
	this->m_lEntries.push_front(std::make_pair<std::string, const zCOLOR>(std::string(out), this->m_zDefaultTextColor));
};

void CConsole::Print(const char* out, zCOLOR col)
{
	this->m_lEntries.push_front(std::make_pair<std::string, zCOLOR>(std::string(out), col));
};

void CConsole::SetFocus(bool b)
{
	if(b)
	{
		this->SetHandleEventTop();
		this->SetEnableHandleEvent(true);
	}
	else
	{
		this->SetEnableHandleEvent(false);
	};
};

void CConsole::Show(void) 
{ 
	this->_OpenGameConsole();
	this->m_pConsole->AddEvalFunc(ConsoleEval);
	this->m_pConsole->Register(zSTRING("clear"), zSTRING("[G2Ext] Clears the console"));
	this->m_pConsole->Register(zSTRING("cls"), zSTRING("[G2Ext] Clears the console"));
	this->m_pConsole->Register(zSTRING("macro [filename]"), zSTRING("[G2Ext] Executes macro (not functional, yet)"));
	this->m_pConsole->Register(zSTRING("macro list"), zSTRING("[G2Ext] Lists all macros (not functional, yet)"));
	this->m_pConsole->Register(zSTRING("help"), zSTRING("[G2Ext] Shows all available commandos"));
	this->m_pConsole->Register(zSTRING("give [instance] [amount]"), zSTRING("[G2Ext] Puts a specified amount of an instance into the inventory (not implemented, yet)"));
	zCConsole::GetConsole()->Toggle();
	zCConsole::GetConsole()->Hide();
	this->m_bVisible = true;
};

void CConsole::Hide(void) 
{ 
	this->m_bVisible = false;
};

void CConsole::_OpenGameConsole()
{
	XCALL(0x006D2090);
};

//////////////////////////////////////////////

int CConsole::HandleEvent(int key)
{
	static unsigned int pos = 0;
	
	char keyb = -1;
	if((keyb = DXIKeyToChar(key)) != -1)
	{
		toupper(keyb);		
		this->m_sInput.insert(this->m_sInput.end(), 1, keyb);

		// -- Auto completion
		zSTRING command = zSTRING(this->m_sInput.c_str());
		if(this->m_pConsole->AutoCompletion(command))
		{
			this->m_sInput = command.ToChar();
		};
	};

	switch(key)
	{
	case KEY_ESCAPE:
	case KEY_GRAVE:
		{
			this->Hide();
			this->SetFocus(false);
			this->m_nLinePosition = 0;
		} break;

	case KEY_DELETE:
		{
			this->m_sInput = "> ";
		} break;

	case KEY_NUMPADENTER:
	case KEY_RETURN:
		{
			// -- Execution

			this->m_sInput.erase(0,2);
			
			if(this->m_sInput.size() == 1) // "empty" string fix! (0x0D bug)
			{
				this->m_sInput = "> ";
				break;	
			};

			zSTRING commando = zSTRING(this->m_sInput.c_str());

			if(this->m_lCommandos.size() == 50)
				this->m_lCommandos.pop_back();

			this->m_lCommandos.push_front(this->m_sInput);

			this->m_nLinePosition = 0;
			pos = 0;
				
			if(!commando.IsEmpty())
			{
				const char* con = strtoupper((char*)commando.ToChar());
				if(zCConsole::GetConsole()->Evaluate(zSTRING(con)))
				{
					static char buf_in[256] = {0};
					sprintf_s(buf_in, 256, "command: \"%s\"", this->m_sInput.c_str());
					this->Print(buf_in, zCOLOR(0xFFFFFFFF));
					static char buf_res[256] = {0};
					sprintf_s(buf_res, 256, "> %s", zCConsole::GetConsole()->GetResult().ToChar()); 
					this->Print(buf_res, zCOLOR(0xAAAAAAFF));
				};
			};
			this->m_sInput = "> ";
		} break;

	case KEY_BACKSPACE:
		{
			if(this->m_sInput.length() > 2)
			{
				this->m_sInput.erase(this->m_sInput.length()-2, 2);
			};
		} break;

	case KEY_INSERT:
		{
			if(this->m_lCommandos.size() != 0)
			{
				if((unsigned int)pos < this->m_lCommandos.size())
				{
					this->m_sInput = "> ";
					this->m_sInput += this->m_lCommandos[pos];
					pos++;
				}
				else
				{
					pos = 0;
				};
			};
		} break;
	case KEY_END:
		{
			this->m_nLinePosition = 0;
		} break;
	case KEY_PGUP:
		{
			if(this->m_lEntries.size() > (unsigned int)this->m_nHeight-6+this->m_nLinePosition)
				this->m_nLinePosition++;
		} break;

	case KEY_PGDN:
		{
			if(this->m_nLinePosition != 0)
				this->m_nLinePosition--;
		} break;

	case KEY_F11:
		{
			exit(0);
		} break;
	};

	return true;
};

void CConsole::Tick(void)
{
	// FIXME/TODO: CPU load of Gothic (and global); Page file usage (swap)

	this->m_pScreen->ClrPrintwin();
	zCView::GetScreen()->RemoveItem(this->m_pScreen);

	if(this->m_bVisible)
	{
		zCView::GetScreen()->InsertItem(this->m_pScreen);
		this->m_pScreen->ClrPrintwin();
		this->m_nFontHeight = this->m_pScreen->FontY();

		this->m_pScreen->SetFontColor(zCOLOR(150, 150, 150, 255));
		this->m_pScreen->Print(150, this->m_nFontHeight, zSTRING(G2EXT_VERSIONA));

		time_t	rawtime;
		tm		timeinfo;
		time (&rawtime);
		localtime_s(&timeinfo, &rawtime);

		static char cTime[24]			= {0};
		static char cGameTime[50]		= {0};
		static char cMemInfoGame[32]	= {0};
		static char cMemInfoGlobal[50]	= {0};
		static char cMemInfoPage[50]	= {0};
		static char cMemInfoLoad[50]	= {0};
		static char cCPUInfoLoad[50]	= {0};
		strftime(cTime, 24,				"Current time: %H:%M:%S", &timeinfo);
		sprintf_s(cGameTime,		60,	"Game Time: day %i @ %s", oCGame::GetGame()->GetWorldTimer()->GetDay(), oCGame::GetGame()->GetWorldTimer()->GetTimeString().ToChar());
		sprintf_s(cMemInfoGame,		60,	"Game memory usage: %u KB", CStatistics::GetInstance()->GetUsedMemorySize());
		sprintf_s(cMemInfoGlobal,	60,	"Global physical memory usage: %u/%u KB", CStatistics::GetInstance()->GetGlobalUsedPhysicalMemory(), CStatistics::GetInstance()->GetGlobalPhysicalMemorySize());
		sprintf_s(cMemInfoPage,		60,	"Global page file usage: %u/%u KB", CStatistics::GetInstance()->GetGlobalUsedPageFile(), CStatistics::GetInstance()->GetGlobalPageFileSize());
		sprintf_s(cMemInfoLoad,		50,	"Global memory load: %u%%", CStatistics::GetInstance()->GetGlobalMemoryLoad());
		sprintf_s(cCPUInfoLoad,		50,	"Game CPU load: %u%%", CStatistics::GetInstance()->GetProcessorLoad());


		this->m_pScreen->Print(VIEW_VXMAX - 150 - this->m_pScreen->FontSize(zSTRING(cTime)), this->m_nFontHeight, zSTRING(cTime));
		this->m_pScreen->Print(VIEW_VXMAX - 150 - this->m_pScreen->FontSize(zSTRING(cGameTime)), this->m_nFontHeight*2, zSTRING(cGameTime));
		this->m_pScreen->Print(VIEW_VXMAX - 150 - this->m_pScreen->FontSize(zSTRING(cMemInfoGame)), this->m_nFontHeight*4, zSTRING(cMemInfoGame));
		this->m_pScreen->Print(VIEW_VXMAX - 150 - this->m_pScreen->FontSize(zSTRING(cCPUInfoLoad)), this->m_nFontHeight*5, zSTRING(cCPUInfoLoad));
		this->m_pScreen->Print(VIEW_VXMAX - 150 - this->m_pScreen->FontSize(zSTRING(cMemInfoLoad)), this->m_nFontHeight*6, zSTRING(cMemInfoLoad));
		this->m_pScreen->Print(VIEW_VXMAX - 150 - this->m_pScreen->FontSize(zSTRING(cMemInfoGlobal)), this->m_nFontHeight*7, zSTRING(cMemInfoGlobal));
		this->m_pScreen->Print(VIEW_VXMAX - 150 - this->m_pScreen->FontSize(zSTRING(cMemInfoPage)), this->m_nFontHeight*8, zSTRING(cMemInfoPage));
		if(this->m_lEntries.size() != 0)
		{
			int p = 0;
			for(int i = min(this->m_lEntries.size()-1, this->m_nHeight-8+this->m_nLinePosition); i > -1; i--)
			{
				if(p >= (this->m_nHeight-7))
					break;

				this->m_pScreen->SetFontColor(this->m_lEntries[i].second);
				this->m_pScreen->Print(150, ((this->m_nFontHeight*p)+(this->m_nFontHeight*3)), zSTRING(this->m_lEntries[i].first.c_str()));
				this->m_pScreen->SetFontColor(this->m_zDefaultTextColor);

				p++;
			};
		};

		this->m_pScreen->SetFontColor(this->m_zDefaultInputColor);
		this->m_pScreen->Print(150, this->m_nFontHeight*29, zSTRING(this->m_sInput.c_str()));
		this->m_pScreen->SetFontColor(this->m_zDefaultTextColor);
	};
};

int CConsole::ConsoleEval(zSTRING& c, zSTRING& r)
{
	// FIXME/TODO: Do something against the 0x0D junk...

	CConsole* pConsole = CConsole::GetInstance();

	char* con    = (char*)c.ToChar();
	char* param1 = strtok(con, "\x0D ");
	char* param2 = strtok(NULL, "\x0D ");
	char* param3 = strtok(NULL, "\x0D ");

	if(strcmp(param1, "ECHO") == 0)
	{	
		if(param2)
		{
			r = param2;
			return true;
		};
	};

	if(strcmp(param1, "HELP") == 0)
	{	
		if(!pConsole->m_vCommandoDescr.empty())
		{
			r = "listing all available commandos...";
			for(unsigned int i = 0; i < pConsole->m_vCommandoDescr.size(); i++)
			{
				pConsole->Print(pConsole->m_vCommandoDescr[i].c_str());
			};
		}
		else
		{
			r = "no commandos registered.";
		};

		return true;
	};

	if(strcmp(param1, "CLS") == 0 || strcmp(param1, "CLEAR") == 0)
	{	
		r = "done.";

		pConsole->m_nLinePosition = 0;
		pConsole->m_lEntries.clear();

		return true;
	};

	/*
	if(strcmp(param1, "MACRO") == 0) // -- Hell yesh. G2Ext supports console macros...
	{
		if(!param2 || (strlen(param2) == 1))
		{
			r = "MACRO: No file specified!";
			return true;
		};

		if(strcmp(param2, "LIST") == 0)
		{
			r = "Listing all macros...";
			return true;	
		};

		G2EXT_LOG_WARNING(L"#-0-0");

		char filename[256];
		strcat(filename, "system\\macros\\");
		strcat(filename, param2);

		G2EXT_LOG_WARNING(L"#-0-1");
		
		std::fstream fs;
		fs.open(filename);

		if(!fs.is_open())
		{
			r = "MACRO: Could not open file!";
			return true;
		};

		G2EXT_LOG_WARNING(L"#-0-2");

		while(fs.good())
		{
			G2EXT_LOG_WARNING(L"#-0-3");

			char* foo = new char[256];
			fs.getline(foo, 256);
			MessageBoxA(0, foo, 0, 0);

			G2EXT_LOG_WARNING(L"#-0-4");
			
			if(strlen(foo) > 1)
			{
				foo = (char*)strtoupper(foo);
				pConsole->m_pConsole->Evaluate(zSTRING(foo));
			};
		};
		
		fs.close();

		r = "MACRO: Done.";
		return true;
	};
	*/

	if(strcmp(param1, "WARGAMES") == 0)
	{	
		r = "sometimes it is better not to play...";

		return true;
	};

	return false;
};

//.text:00782AE0 ; public: void __thiscall zCConsole::Register(class zSTRING const &, class zSTRING const &)
void __stdcall CConsole::ConsoleRegister(zSTRING*& c, zSTRING*& help)
{
	std::string str = std::string(c->ToChar());
	str += " -- ";
	str += help->ToChar();
	CConsole::GetInstance()->m_vCommandoDescr.push_back(str);

	G2EXT_LOGF_DEBUG(L"CON: Registering '%S'", str.c_str());
};

//.text:007829C0 ; public: void __thiscall zCConsole::Register(class zSTRING const &, class zSTRING const &, int)
void __stdcall CConsole::ConsoleRegister1(zSTRING*& c, zSTRING*& help, int& u)
{
	CConsole::ConsoleRegister(c, help);
};