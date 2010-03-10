/*////////////////////////////////////////////////////////////////////////////

This file is part of the G2Ext SDK headers.

//////////////////////////////////////////////////////////////////////////////

The G2Ext SDK headers

Copyright © 2009, 2010 by Paindevs and Patrick Vogel

All Rights reserved.

THE WORK (AS DEFINED BELOW) IS PROVIDED
UNDER THE TERMS OF THIS CREATIVE COMMONS
PUBLIC LICENSE ("CCPL" OR "LICENSE").
THE WORK IS PROTECTED BY COPYRIGHT AND/OR
OTHER APPLICABLE LAW. ANY USE OF THE WORK
OTHER THAN AS AUTHORIZED UNDER THIS LICENSE
OR COPYRIGHT LAW IS PROHIBITED.

BY EXERCISING ANY RIGHTS TO THE WORK PROVIDED
HERE, YOU ACCEPT AND AGREE TO BE BOUND BY THE
TERMS OF THIS LICENSE. TO THE EXTENT THIS
LICENSE MAY BE CONSIDERED TO BE A CONTRACT,
THE LICENSOR GRANTS YOU THE RIGHTS CONTAINED
HERE IN CONSIDERATION OF YOUR ACCEPTANCE OF
SUCH TERMS AND CONDITIONS.

Full license at http://creativecommons.org/licenses/by-nc/3.0/legalcode

/////////////////////////////////////////////////////////////////////////////*/

#ifndef __API_G2_ZCOPTION_H__
#define __API_G2_ZCOPTION_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"

/** Insert description. */
class zCOption
{
public:
	//.text:00460350 ; public: __thiscall zCOption::zCOption(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zCOption(void)
	{
		XCALL(0x00460350);
	};

	//.text:00465160 ; public: void __thiscall zCOption::ChangeDir(enum  zTOptionPaths)
	/** Insert description. 
	* @usable Ingame only
	*/
	int ChangeDir(int x)
	{
		XCALL(0x00465160);
	};

	//.text:004607B0 ; public: int __thiscall zCOption::Load(class zSTRING)
	/** Insert description. 
	* @usable Ingame only
	*/
	int Load(zSTRING file)
	{
		XCALL(0x004607B0);
	};

	//.text:004616C0 ; public: int __thiscall zCOption::Save(class zSTRING)
	/** Insert description. 
	* @usable Ingame only
	*/
	int Save(zSTRING file)
	{
		XCALL(0x004616C0);
	};

	//.text:00463C20 ; public: int __thiscall zCOption::Init(class zSTRING, bool)
	/** Insert description. 
	* @usable Ingame only
	*/
	int Init(zSTRING cmd, bool extra_infos = true)
	{
		XCALL(0x00463C20);
	};

	//.text:00463250 ; public: int __thiscall zCOption::SectionExists(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	int SectionExists(const zSTRING& section)
	{
		XCALL(0x00463250);
	};

	//.text:004632B0 ; public: int __thiscall zCOption::RemoveSection(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	int RemoveSection(const zSTRING& section)
	{
		XCALL(0x004632B0);
	};

	//.text:00462950 ; public: int __thiscall zCOption::EntryExists(class zSTRING const &, char const *)
	/** Insert description. 
	* @usable Ingame only
	*/
	int EntryExists(const zSTRING& section, const char* entry)
	{
		XCALL(0x00462950);
	};

	//.text:00462A70 ; public: int __thiscall zCOption::RemoveEntry(class zSTRING const &, char const *)
	/** Insert description. 
	* @usable Ingame only
	*/
	int RemoveEntry(const zSTRING& section, const char* entry)
	{
		XCALL(0x00462A70);
	};

	//.text:00461DE0 ; public: int __thiscall zCOption::WriteBool(class zSTRING const &, char const *, int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int WriteBool(const zSTRING& section, const char* entry, zBOOL value, int p1 = 0)
	{
		XCALL(0x00461DE0);
	};

	//.text:00461E60 ; public: int __thiscall zCOption::WriteDWord(class zSTRING const &, char const *, unsigned long, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int WriteDWord(const zSTRING& section, const char* entry, DWORD value, int p1 = 0)
	{
		XCALL(0x00461E60);
	};

	//.text:00461E30 ; public: int __thiscall zCOption::WriteInt(class zSTRING const &, char const *, int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int WriteInt(const zSTRING& section, const char* entry, int value, int p1 = 0)
	{
		XCALL(0x00461E30);
	};

	//.text:004634E0 ; public: int __thiscall zCOption::WriteRaw(class zSTRING const &, char const *, void *, int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int WriteRaw(const zSTRING& section, const char* entry, void* buffer, int size, int p1 = 0)
	{
		XCALL(0x004634E0);
	};

	//.text:00461F90 ; int __stdcall zCOption__WriteReal(int, int, float, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int WriteReal(const zSTRING& section, const char* entry, float value, int p1 = 0)
	{
		XCALL(0x00461F90);
	};

	//.text:00461FD0 ; public: int __thiscall zCOption::WriteString(class zSTRING const &, char const *, class zSTRING, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int WriteString(const zSTRING& section, const char* entry, zSTRING value, int p1 = 0)
	{
		XCALL(0x00461FD0);
	};
	
	//.text:004638A0 ; public: int __thiscall zCOption::WriteBool(class zSTRING const &, class zSTRING const &, int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int WriteBool(const zSTRING& section, const zSTRING& entry, zBOOL value, int p1 = 0)
	{
		XCALL(0x004638A0);
	};

	//.text:004638E0 ; public: int __thiscall zCOption::WriteDWord(class zSTRING const &, class zSTRING const &, unsigned long, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int WriteDWord(const zSTRING& section, const zSTRING& entry, DWORD value, int p1 = 0)
	{
		XCALL(0x004638E0);
	};

	//.text:004638C0 ; public: int __thiscall zCOption::WriteInt(class zSTRING const &, class zSTRING const &, int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int WriteInt(const zSTRING& section, const zSTRING& entry, int value, int p1 = 0)
	{
		XCALL(0x004638C0);
	};

	//.text:004639E0 ; public: int __thiscall zCOption::WriteRaw(class zSTRING const &, class zSTRING const &, void *, int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int WriteRaw(const zSTRING& section, const zSTRING& entry, void* buffer, int size, int p1 = 0)
	{
		XCALL(0x004639E0);
	};

	//.text:00463900 ; public: int __thiscall zCOption::WriteReal(class zSTRING const &, class zSTRING const &, float, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int WriteReal(const zSTRING& section, const zSTRING& entry, float value, int p1 = 0)
	{
		XCALL(0x00463900);
	};

	//.text:00463930 ; public: int __thiscall zCOption::WriteString(class zSTRING const &, class zSTRING const &, class zSTRING, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int WriteString(const zSTRING& section, const zSTRING& entry, zSTRING value, int p1 = 0)
	{
		XCALL(0x00463930);
	};

	//.text:00462160 ; public: int __thiscall zCOption::ReadBool(class zSTRING const &, char const *, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	zBOOL ReadBool(const zSTRING& section, const char* entry, int default = false)
	{
		XCALL(0x00462160);
	};

	//.text:004624F0 ; public: unsigned long __thiscall zCOption::ReadDWord(class zSTRING const &, char const *, unsigned long)
	/** Insert description. 
	* @usable Ingame only
	*/
	DWORD ReadDWord(const zSTRING& section, const char* entry, DWORD default = 0)
	{
		XCALL(0x004624F0);
	};

	//.text:00462390 ; public: int __thiscall zCOption::ReadInt(class zSTRING const &, char const *, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int ReadInt(const zSTRING& section, const char* entry, int default = 0)
	{
		XCALL(0x00462390);
	};

	//.text:004636C0 ; public: int __thiscall zCOption::ReadRaw(class zSTRING const &, char const *, void * &, void *, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int ReadRaw(const zSTRING& section, const char* entry, void*& buffer, void* default = NULL, int defaultsize = 0)
	{
		XCALL(0x004636C0);
	};

	//.text:00462650 ; int __stdcall zCOption__ReadReal(int, int, float)
	/** Insert description. 
	* @usable Ingame only
	*/
	float ReadReal(const zSTRING& section, const char* entry, float default = 0.0f)
	{
		XCALL(0x00462650);
	};

	//.text:004627E0 ; public: class zSTRING __thiscall zCOption::ReadString(class zSTRING const &, char const *, char const *)
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING ReadString(const zSTRING& section, const char* entry, const char* default = "")
	{
		XCALL(0x004627E0);
	};

	//.text:00463A00 ; public: int __thiscall zCOption::ReadBool(class zSTRING const &, class zSTRING const &, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	zBOOL ReadBool(const zSTRING& section, const zSTRING& entry, int default = 0)
	{
		XCALL(0x00463A00);
	};

	//.text:00463A40 ; public: unsigned long __thiscall zCOption::ReadDWord(class zSTRING const &, class zSTRING const &, unsigned long)
	/** Insert description. 
	* @usable Ingame only
	*/
	DWORD ReadDWord(const zSTRING& section, const zSTRING& entry, DWORD default = 0)
	{
		XCALL(0x00463A40);
	};

	//.text:00463A20 ; public: int __thiscall zCOption::ReadInt(class zSTRING const &, class zSTRING const &, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int ReadInt(const zSTRING& section, const zSTRING& entry, int default = 0)
	{
		XCALL(0x00463A20);
	};

	//.text:00463AD0 ; public: int __thiscall zCOption::ReadRaw(class zSTRING const &, class zSTRING const &, void *, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int ReadRaw(const zSTRING& section, const zSTRING& entry, void* default = NULL, int defaultsize = 0)
	{
		XCALL(0x00463AD0);
	};

	//.text:00463A60 ; public: float __thiscall zCOption::ReadReal(class zSTRING const &, class zSTRING const &, float)
	/** Insert description. 
	* @usable Ingame only
	*/
	float ReadReal(const zSTRING& section, const zSTRING& entry, float default = 0.0f)
	{
		XCALL(0x00463A60);
	};

	//.text:00463A90 ; public: class zSTRING __thiscall zCOption::ReadString(class zSTRING const &, class zSTRING const &, char const *)
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING ReadReal(const zSTRING& section, const zSTRING& entry, const char* default = "")
	{
		XCALL(0x00463A90);
	};

	//.text:00465270 ; public: int __thiscall zCOption::Parm(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	int Parm(const zSTRING& param)
	{
		XCALL(0x00465270);
	};

	//.text:00465380 ; public: class zSTRING __thiscall zCOption::ParmValue(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING ParmValue(const zSTRING& param)
	{
		XCALL(0x00465380);
	};

	//.text:00465940 ; public: float __thiscall zCOption::ParmValueFloat(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	float ParmValueFloat(const zSTRING& param)
	{
		XCALL(0x00465940);
	};

	//.text:00465780 ; public: int __thiscall zCOption::ParmValueInt(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	int ParmValueInt(const zSTRING& param)
	{
		XCALL(0x00465780);
	};

	//.text:00465580 ; public: class zSTRING __thiscall zCOption::ParmValueRaw(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING ParmValueRaw(const zSTRING& param)
	{
		XCALL(0x00465580);
	};

	/** This method returns the current zCOption (game) instance
	* @usable Ingame only
	*/
	inline static zCOption* GetOptionGame() { return *(zCOption**)0x008CD98C; };

	/** Insert description. 
	* @usable Ingame only
	*/
	inline static zCOption* GetOption() { return *(zCOption**)0x008CD988; };
};

#undef __G2EXT_API_HEADER

#endif  __API_G2_ZCOPTION_H__
