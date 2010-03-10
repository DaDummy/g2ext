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

#ifndef __ZCPARSER_H_INCLUDED__
#define __ZCPARSER_H_INCLUDED__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"

#include "api/g2/zcpar_symbol.h"

#pragma warning(disable:4731) // -- surpress C4731:"frame pointer register 'ebp' modified by inline assembly code"

/** Insert description. */
typedef enum  
{
	zCPVOID, 
	zCPFLOAT, 
	zCPINT, 
	zCPSTRING, 
	zCPCLASS, 
	zCPFUNC,
	zCPPROTOTYPE, 
	zCPINSTANCE
} zCParser_CallType;

/** ZenGin Daedalus script parser. */
class zCParser
{
private:
	char m_data[0x2048];
public:
	//.text:0078DED0 ; public: __thiscall zCParser::zCParser(int)
	/** Constructor.
	* @param  Unknown
	* @usable Ingame only
	*/
	zCParser(int pA = 100)
	{
		XCALL(0x0078DED0);
	};

	//.text:007900E0 ; public: void __thiscall zCParser::CreatePCode(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void CreatePCode(void)
	{
		XCALL(0x007900E0);
	};

	//.text:007929F0 ; int __cdecl zCParser__CallFunc(int, ...)
	/** Insert description. 
	* @usable Ingame only
	* @return	A *pointer* to the returnvalue (int/float)
	*/
	void* CallFunc(int pA, ...)
	{
		XCALL(0x007929F0);
	};

	//.text:007929D0 ; public: void * __thiscall zCParser::CallFunc(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	* @return	A *pointer* to the returnvalue (int/float)
	*/
	void* CallFunc(const zSTRING & pA)
	{
		XCALL(0x007929D0);
	};

	//.text:00794470 ; public: int __thiscall zCParser::CheckClassSize(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int CheckClassSize(int pA, int pB)
	{
		XCALL(0x00794470);
	};

	//.text:00794450 ; public: int __thiscall zCParser::CheckClassSize(class zSTRING &, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int CheckClassSize(zSTRING & pA, int pB)
	{
		XCALL(0x00794450);
	};

	//.text:007929D0 ; public: void * __thiscall zCParser::CallFunc(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	int CreateInstance(zSTRING & pA)
	{
		XCALL(0x007929D0);
	};

	//.text:00792FA0 ; public: int __thiscall zCParser::CreateInstance(int, void *)
	/** Insert description. 
	* @usable Ingame only
	*/
	int CreateInstance(int pA, void * pB)
	{
		XCALL(0x00792FA0);
	};

	//.text:00792F20 ; public: int __thiscall zCParser::CreateInstance(class zSTRING &, void *)
	/** Insert description. 
	* @usable Ingame only
	*/
	int CreateInstance(zSTRING & pA, void * pB)
	{
		XCALL(0x00792F20);
	};

	//.text:007A0190 ; public: void __cdecl zCParser::DefineExternal(class zSTRING const &, int (__cdecl *)(void), int, int, ...)
	/** Insert description. 
	* @usable Ingame only
	*/
	int DefineExternal(const zSTRING & a_SymbolName, zBOOL(__cdecl*a_ExternalProc)(), int a_ReturnType, int a_ParameterType, ...)
	{
		XCALL(0x007A0190);			
	};

	//.text:007A0550 ; public: void __thiscall zCParser::DefineExternalVar(class zSTRING const &, void *, int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int DefineExternalVar(const zSTRING & a_SymbolName, void* a_ExternalVar, int a_ReturnType, int a_ParameterType)
	{
		XCALL(0x007A0550);
	};

	//.text:0078E730 ; public: int __thiscall zCParser::Error(void)		
	/** Insert description. 
	* @usable Ingame only
	*/
	zBOOL Error(void)
	{
		XCALL(0x0078E730);
	};

	//.text:00793610 ; public: int __thiscall zCParser::GetBaseClass(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int GetBaseClass(int instance)
	{
		XCALL(0x00793610);
	};

	/** Insert description. 
	* @usable Ingame only
	*/
	void GetParameter(float & pA)
	{
		XCALL(0x007A0770);
	};

	//.text:007A0760 ; public: void __thiscall zCParser::GetParameter(int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetParameter(int & pA)
	{
		XCALL(0x007A0760);
	};

	//.text:007A07B0 ; public: void __thiscall zCParser::GetParameter(class zSTRING &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetParameter(zSTRING & pA)
	{
		XCALL(0x007A07B0);
	};

	//.text:00793470 ; public: int __thiscall zCParser::GetIndex(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetParameter(const zSTRING & pA)
	{
		XCALL(0x00793470);
	};

	//.text:00793730 ; public: int __thiscall zCParser::GetInstance(int, int)
	/** Gets an instance from Daedalus.
	* @usable In an external only
	* @param ClassId	return value of GetIndex(zSTRING& class)
	* @param Index		instance number (index of array only containing instances of this class)
	* @return			Daedalus instance index (you get this one when you pass an Instance as an Integer parameter)
	*/
	int GetInstance(int ClassId, int Index)
	{
		XCALL(0x00793730);
	};

	//.text:007A08F0 ; public: void * __thiscall zCParser::GetInstance(void)
	/** Gets an instance from the Daedalus stack.
	 * @usable In an external only
	 * @return	A pointer to the object instance.
	 */
	void* GetInstance(void)
	{
		XCALL(0x007A08F0);
	};

	//.text:007A0920 ; public: void * __thiscall zCParser::GetInstanceAndIndex(int &)
	/** Gets an instance from the Daedalus stack.
	* @usable in an external only
	*/
	void* GetInstanceAndIndex(int & pA)
	{
		XCALL(0x007A0920);
	};

	//.text:00793FD0 ; public: class zSTRING __thiscall zCParser::GetInstanceValue(int, int, void *, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING GetInstanceValue(int pA, int pB, void * pC, int pD)
	{
		XCALL(0x00793FD0);
	};

	//.text:00793EE0 ; public: class zSTRING __thiscall zCParser::GetInstanceValue(class zSTRING &, int, void *, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING GetInstanceValue(class zSTRING & pA, int pB, void * pC, int pD)
	{
		XCALL(0x00793EE0);
	};

	//.text:00793470 ; public: int __thiscall zCParser::GetIndex(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	int GetIndex(class zSTRING const & pA)
	{
		XCALL(0x00793470);
	};

	//.text:007938D0 ; public: class zCPar_Symbol * __thiscall zCParser::GetSymbol(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	zCPar_Symbol* GetSymbol(const zSTRING& pA)
	{
		XCALL(0x007938D0);
	};

	//.text:007938C0 ; public: class zCPar_Symbol * __thiscall zCParser::GetSymbol(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	zCPar_Symbol* GetSymbol(int pA)
	{
		XCALL(0x007938C0);
	};

	//.text:0078D010 ; public: static unsigned char __cdecl zCParser::GetVersion(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	static zBYTE GetVersion(void)
	{
		XCALL(0x0078D010);
	};

	//.text:0078E900 ; public: int __thiscall zCParser::LoadDat(class zSTRING &)
	/** Loads a compiled *.dat file
	* @param  File name
	* @usable Ingame only
	*/
	int LoadDat(zSTRING & zsFileName)
	{
		XCALL(0x0078E900);
	};

	//.text:00791650 ; public: int __thiscall zCParser::MergeFile(class zSTRING &)
	/** Insert description. 
	* @usable Ingame only
	*/
	int MergeFile(zSTRING & zsFileName)
	{
		XCALL(0x00791650);
	};

	//.text:0078EBA0 ; public: int __thiscall zCParser::Parse(class zSTRING)
	/** Parses a *.d or a *.src file
	* @param  File name
	* @usable Ingame only
	*/
	int Parse(zSTRING zsFileName)
	{
		XCALL(0x0078EBA0);
	};

	//.text:0078F660 ; public: int __thiscall zCParser::ParseFile(class zSTRING &)
	/** Parses a *.d file
	* @param  File name
	* @usable Ingame only
	*/
	int ParseFile(zSTRING & zsFileName)
	{
		XCALL(0x0078F660);
	};

	//.text:0078EE20 ; public: int __thiscall zCParser::ParseSource(class zSTRING &)
	/** Parses a *.src file
	* @param  File name
	* @usable Ingame only
	*/
	int ParseSource(zSTRING & zsFileName)
	{
		XCALL(0x0078EE20);
	};

	//.text:00794C30 ; public: void __thiscall zCParser::Reparse(class zSTRING &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Reparse(zSTRING & pA)
	{
		XCALL(0x00794C30);
	};

	//.text:00793100 ; public: void __thiscall zCParser::Reset(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Reset(void)
	{
		XCALL(0x00793100);
	};

	//.text:007969C0 ; public: int __thiscall zCParser::ResetGlobalVars(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void ResetGlobalVars(void)
	{
		XCALL(0x007969C0);
	};

	//.text:0078E740 ; public: int __thiscall zCParser::SaveDat(class zSTRING &)
	/** Saves a compiled *.dat file
	* @param  File name
	* @usable Ingame only
	*/
	int SaveDat(zSTRING & zsFileName)
	{
		XCALL(0x0078E740);
	};

	//.text:0078E250 ; public: void __thiscall zCParser::SetMessageFunc(void (__cdecl *)(class zSTRING))
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetMessageFunc(void(__cdecl *f)(zSTRING))
	{
		XCALL(0x0078E250);
	};

	//.text:007A0980 ; public: void __thiscall zCParser::SetReturn(float)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetReturn(float pA)
	{
		XCALL(0x007A0980);
	};

	//.text:007A0960 ; public: void __thiscall zCParser::SetReturn(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetReturn(int pA)
	{
		XCALL(0x007A0960);
	};

	//.text:007A09A0 ; public: void __thiscall zCParser::SetReturn(void *)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetReturn(void * pA)
	{
		XCALL(0x007A09A0);
	};

	//.text:007A09D0 ; public: void __thiscall zCParser::SetReturn(class zSTRING &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetReturn(zSTRING & pA)
	{
		XCALL(0x007A09A0);
	};

	//.text:0078E260 ; public: void __thiscall zCParser::SetStopOnError(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetStopOnError(zBOOL pA)
	{
		XCALL(0x0078E260);
	};

	/** This method returns the current zCParser instance
	* @usable Ingame only
	*/
	static zCParser* GetParser()
	{
		return (zCParser*)0x00AB40C0;
	};
};

#undef __G2EXT_API_HEADER

#endif // __ZCPARSER_H_INCLUDED__

