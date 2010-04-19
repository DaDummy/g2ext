/*////////////////////////////////////////////////////////////////////////////

This file is part of the G2Ext SDK headers.

//////////////////////////////////////////////////////////////////////////////

The G2Ext SDK headers

Copyright � 2009, 2010 by Paindevs and Patrick Vogel

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

#ifndef __ZCPAR_SYMBOL_H_INCLUDED__
#define __ZCPAR_SYMBOL_H_INCLUDED__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"

/** Insert description. */
class zCPar_Symbol
{
public:
	//.text:007A2F30 ; public: int __thiscall zCPar_Symbol::GetOffset(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void* GetOffset()
	{
		XCALL(0x007A2F30);
	};

	//.text:007A1DC0 ; public: void * __thiscall zCPar_Symbol::GetInstanceAdr(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void* GetInstanceAdr()
	{
		XCALL(0x007A1DC0);
	};

public:
	zSTRING			name;
	zCPar_Symbol*	next;

	union
	{
		void*		data_ptr;
		int*		data_pint;
		float*		data_pfloat;
		zSTRING*	data_pstring;
		int			data_int;
		float		data_float;
	} content;

	int offset;

	int bitfield; 
	int filenr; 
	int line;
	int line_anz;
	int pos_beg;
	int pos_anz;

	zCPar_Symbol* parent;
};

#undef __G2EXT_API_HEADER

#endif //__ZCPAR_SYMBOL_H_INCLUDED__