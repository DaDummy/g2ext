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

#ifndef __API_SPACER_ZCPARSER_H__
#define __API_SPACER_ZCPARSER_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifndef _G2EXT_COMPILE_SPACER
#error Cannot use spacer headers on non spacer dll (_G2EXT_COMPILE_SPACER not defined)
#endif

#include "api/spacer/ztypes.h"
#include "api/spacer/macros.h"

#include "api/spacer/zcpar_symbol.h"

#pragma warning(disable:4731) // -- suppress C4731:"frame pointer register 'ebp' modified by inline assembly code"

class zCPar_File;
class zCPar_TreeNode;
class zCViewProgressBar;
class zCView;

typedef struct 
{
	zCPar_Symbol*	preAllocatedSymbols;
	int				nextPreAllocated;
} zCPar_SymbolTable;

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

#define zMAX_SYM_DATASTACK 2048

/** ZenGin Daedalus script parser. */
class zCParser
{
private:
	void (__cdecl * msgfunc)( zSTRING );

	zCArray<zCPar_File*>	file;
	zCPar_SymbolTable		symtab;
	zCArray<zCPar_Symbol*>  table;
	zCArraySort<int>		tablesort;

	zCPar_Symbol*			lastsym;
	zCPar_Symbol*			firstsym; 

	//zCPar_StringTable stringtab;
	zCArray<zSTRING*>		stringtab;

	//zCPar_Stack               stack;
	int stack_stack;                            //0x0048 zBYTE*  // Stackbegin
	int stack_stackptr;                         //0x004C zBYTE* or zWORD* or int*
	int stack_stacklast;                        //0x0050 zBYTE* or zWORD* or int*
	int stack_stacksize;                        //0x0054 int //Stack size in Bytes

	//zCPar_DataStack           datastack;
	int stack[zMAX_SYM_DATASTACK];				//0x0058
	int sptr;                                   //0x085C int

	zCPar_Symbol* _self;

	zSTRING fname;
	zSTRING mainfile;
	int compiled;          
	int treesave;               
	int datsave;              
	int parse_changed;
	int treeload;
	int mergemode;             
	int linkingnr;
	int linec;
	int line_start;
	int ext_parse;
	char* pc_start;
	char* pc;
	char* oldpc;
	char* pc_stop;
	char* oldpc_stop;
	int params;
	int in_funcnr;
	int in_classnr;
	int stringcount;
	zCPar_Symbol* in_func;
	zCPar_Symbol* in_class;
	int error;
	int stop_on_error;
	int errorline;
	char* prevword_index[16];
	int prevline_index[16];
	int prevword_nr;
	zSTRING  aword;     
	int _instance;           
	int instance_help;
	zCViewProgressBar* progressBar;
	zCPar_TreeNode* tree;
	zCPar_TreeNode* treenode;
	zCView* win_code;
	int debugmode;
	int curfuncnr;
	int labelcount;
	int* labelpos;

	//zCList <zSTRING>*     add_funclist;
	zCList<zSTRING*> add_funclist;
	int add_funclist_data;							//zString*
	int add_funclist_next;							//zCList<zSTRING>*

	zSTRING add_filename;                            //zSTRING                          
	int add_created;                                //zBOOL
public:
	//.text:007FA7F0 ; public: __thiscall zCParser::zCParser(int)
	/** Constructor.
	* @param  Unknown
	* @usable Ingame only
	*/
	zCParser(int pA = 100)
	{
		XCALL(0x007FA7F0); // spacer
	};

	//.text:007FCA00 ; public: void __thiscall zCParser::CreatePCode(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void CreatePCode(void)
	{
		XCALL(0x007FCA00); // spacer
	};

	//.text:007FF310 ; int __cdecl zCParser__CallFunc(int, ...)
	/** Insert description. 
	* @usable Ingame only
	* @return	A *pointer* to the returnvalue (int/float)
	*/
	void* CallFunc(int pA, ...)
	{
		XCALL(0x007FF310); // spacer
	};

	//.text:007FF2F0 ; public: void * __thiscall zCParser::CallFunc(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	* @return	A *pointer* to the returnvalue (int/float)
	*/
	void* CallFunc(const zSTRING & pA)
	{
		XCALL(0x007FF2F0); // spacer
	};

	//.text:00800D90 ; public: int __thiscall zCParser::CheckClassSize(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int CheckClassSize(int pA, int pB)
	{
		XCALL(0x00800D90); // spacer
	};

	//.text:00800D70 ; public: int __thiscall zCParser::CheckClassSize(class zSTRING &, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int CheckClassSize(zSTRING & pA, int pB)
	{
		XCALL(0x00800D70); // spacer
	};

	//.text:007FF8C0 ; public: int __thiscall zCParser::CreateInstance(int, void *)
	/** Insert description. 
	* @usable Ingame only
	*/
	int CreateInstance(int pA, void * pB)
	{
		XCALL(0x007FF8C0); // spacer
	};

	//.text:007FF840 ; public: int __thiscall zCParser::CreateInstance(class zSTRING &, void *)
	/** Insert description. 
	* @usable Ingame only
	*/
	int CreateInstance(zSTRING & pA, void * pB)
	{
		XCALL(0x007FF840); // spacer
	};

	//.text:0080CAB0 ; public: void __cdecl zCParser::DefineExternal(class zSTRING const &, int (__cdecl *)(void), int, int, ...)
	/** Insert description. 
	* @usable Ingame only
	*/
	int DefineExternal(const zSTRING & a_SymbolName, zBOOL(__cdecl*a_ExternalProc)(), int a_ReturnType, int a_ParameterType, ...)
	{
		XCALL(0x0080CAB0); // spacer			
	};

	//.text:0080CE70 ; public: void __thiscall zCParser::DefineExternalVar(class zSTRING const &, void *, int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int DefineExternalVar(const zSTRING & a_SymbolName, void* a_ExternalVar, int a_ReturnType, int a_ParameterType)
	{
		XCALL(0x0080CE70); // spacer
	};

	//.text:007FB050 ; public: int __thiscall zCParser::Error(void)		
	/** Insert description. 
	* @usable Ingame only
	*/
	zBOOL Error(void)
	{
		XCALL(0x007FB050); // spacer
	};

	//.text:007FFF30 ; public: int __thiscall zCParser::GetBaseClass(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int GetBaseClass(int instance)
	{
		XCALL(0x007FFF30); // spacer
	};

	//.text:0080D090 ; public: void __thiscall zCParser::GetParameter(float & pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetParameter(float & pA)
	{
		XCALL(0x0080D090); // spacer
	};

	//.text:0080D080 ; public: void __thiscall zCParser::GetParameter(int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetParameter(int & pA)
	{
		XCALL(0x0080D080); // spacer
	};

	//.text:0080D0D0 ; public: void __thiscall zCParser::GetParameter(class zSTRING &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetParameter(zSTRING & pA)
	{
		XCALL(0x0080D0D0); // spacer
	};

	//.text:00800050 ; public: int __thiscall zCParser::GetInstance(int, int)
	/** Gets an instance from Daedalus.
	* @usable In an external only
	* @param ClassId	return value of GetIndex(zSTRING& class)
	* @param Index		instance number (index of array only containing instances of this class)
	* @return			Daedalus instance index (you get this one when you pass an Instance as an Integer parameter)
	*/
	int GetInstance(int ClassId, int Index)
	{
		XCALL(0x00800050); // spacer
	};

	//.text:0080D210 ; public: void * __thiscall zCParser::GetInstance(void)
	/** Gets an instance from the Daedalus stack.
	* @usable In an external only
	* @return	A pointer to the object instance.
	*/
	void* GetInstance(void)
	{
		XCALL(0x0080D210); // spacer
	};

	//.text:0080D240 ; public: void * __thiscall zCParser::GetInstanceAndIndex(int &)
	/** Gets an instance from the Daedalus stack.
	* @usable in an external only
	*/
	void* GetInstanceAndIndex(int & pA)
	{
		XCALL(0x0080D240); // spacer
	};

	//.text:008008F0 ; public: class zSTRING __thiscall zCParser::GetInstanceValue(int, int, void *, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING GetInstanceValue(int pA, int pB, void * pC, int pD)
	{
		XCALL(0x008008F0); // spacer
	};

	//.text:00800800 ; public: class zSTRING __thiscall zCParser::GetInstanceValue(class zSTRING &, int, void *, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING GetInstanceValue(class zSTRING & pA, int pB, void * pC, int pD)
	{
		XCALL(0x00800800); // spacer
	};

	//.text:007FFD90 ; public: int __thiscall zCParser::GetIndex(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	int GetIndex(class zSTRING const & pA)
	{
		XCALL(0x007FFD90); // spacer
	};

	//.text:008001F0 ; public: class zCPar_Symbol * __thiscall zCParser::GetSymbol(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	zCPar_Symbol* GetSymbol(const zSTRING& pA)
	{
		XCALL(0x008001F0); // spacer
	};

	//.text:008001E0 ; public: class zCPar_Symbol * __thiscall zCParser::GetSymbol(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	zCPar_Symbol* GetSymbol(int pA)
	{
		XCALL(0x008001E0); // spacer
	};

	//.text:007F9930 ; public: static unsigned char __cdecl zCParser::GetVersion(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	static zBYTE GetVersion(void)
	{
		XCALL(0x007F9930); // spacer
	};

	//.text:007FB220 ; public: int __thiscall zCParser::LoadDat(class zSTRING &)
	/** Loads a compiled *.dat file
	* @param  File name
	* @usable Ingame only
	*/
	int LoadDat(zSTRING & zsFileName)
	{
		XCALL(0x007FB220); // spacer
	};

	//.text:007FDF70 ; public: int __thiscall zCParser::MergeFile(class zSTRING &)
	/** Insert description. 
	* @usable Ingame only
	*/
	int MergeFile(zSTRING & zsFileName)
	{
		XCALL(0x007FDF70); // spacer
	};

	//.text:007FB4C0 ; public: int __thiscall zCParser::Parse(class zSTRING)
	/** Parses a *.d or a *.src file
	* @param  File name
	* @usable Ingame only
	*/
	int Parse(zSTRING zsFileName)
	{
		XCALL(0x007FB4C0); // spacer
	};

	//.text:007FBF80 ; public: int __thiscall zCParser::ParseFile(class zSTRING &)
	/** Parses a *.d file
	* @param  File name
	* @usable Ingame only
	*/
	int ParseFile(zSTRING & zsFileName)
	{
		XCALL(0x007FBF80); // spacer
	};

	//.text:007FB740 ; public: int __thiscall zCParser::ParseSource(class zSTRING &)
	/** Parses a *.src file
	* @param  File name
	* @usable Ingame only
	*/
	int ParseSource(zSTRING & zsFileName)
	{
		XCALL(0x007FB740); // spacer
	};

	//.text:00801550 ; public: void __thiscall zCParser::Reparse(class zSTRING &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Reparse(zSTRING & pA)
	{
		XCALL(0x00801550); // spacer
	};

	//.text:007FFA20 ; public: void __thiscall zCParser::Reset(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Reset(void)
	{
		XCALL(0x007FFA20); // spacer
	};

	//.text:008032E0 ; public: int __thiscall zCParser::ResetGlobalVars(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void ResetGlobalVars(void)
	{
		XCALL(0x008032E0); // spacer
	};

	//.text:007FB060 ; public: int __thiscall zCParser::SaveDat(class zSTRING &)
	/** Saves a compiled *.dat file
	* @param  File name
	* @usable Ingame only
	*/
	int SaveDat(zSTRING & zsFileName)
	{
		XCALL(0x007FB060); // spacer
	};

	//.text:007FAB70 ; public: void __thiscall zCParser::SetMessageFunc(void (__cdecl *)(class zSTRING))
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetMessageFunc(void(__cdecl *f)(zSTRING))
	{
		XCALL(0x007FAB70); // spacer
	};

	//.text:0080D2A0 ; public: void __thiscall zCParser::SetReturn(float)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetReturn(float pA)
	{
		XCALL(0x0080D2A0); // spacer
	};

	//.text:0080D280 ; public: void __thiscall zCParser::SetReturn(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetReturn(int pA)
	{
		XCALL(0x0080D280); // spacer
	};

	//.text:0080D2C0 ; public: void __thiscall zCParser::SetReturn(void *)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetReturn(void * pA)
	{
		XCALL(0x0080D2C0); // spacer
	};

	//.text:0080D2F0 ; public: void __thiscall zCParser::SetReturn(class zSTRING &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetReturn(zSTRING & pA)
	{
		XCALL(0x0080D2F0); // spacer
	};

	//.text:007FAB80 ; public: void __thiscall zCParser::SetStopOnError(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetStopOnError(zBOOL pA)
	{
		XCALL(0x007FAB80); // spacer
	};

	/** This method returns the current zCParser instance
	* @usable Ingame only
	*/
	static zCParser* GetParser()
	{
		return (zCParser*)0x00C2A778; // spacer
	};
};

#undef __G2EXT_API_HEADER

#endif // __API_SPACER_ZCPARSER_H__

