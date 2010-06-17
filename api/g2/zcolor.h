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

#ifndef __ZCOLOR_H_INCLUDED__
#define __ZCOLOR_H_INCLUDED__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "common/osheader.h"


/** ZenGin color type 
* @note: The ZenGin uses a BGRA colour type! (Don't mix it up with RGBA!)
*
*/
class zCOLOR
{
public:
	union {
		struct {
			BYTE	b;
			BYTE	g;
			BYTE	r;
			BYTE	a;
		};
		DWORD color;
	};

	// -- constructors

	/** Insert description. 
	*/
	zCOLOR();

	/** Insert description. 
	*/
	zCOLOR(zBYTE _r, zBYTE _g, zBYTE _b); // RGB

	/** Insert description. 
	*/
	zCOLOR(zBYTE _r, zBYTE _g, zBYTE _b, zBYTE _a); // RGBA

	/** Insert description. 
	*/
	zCOLOR(zDWORD _color); // BGRA

	// -- functions

	/** Insert description. 
	*/
	void Clear();

	/** Insert description. 
	*/
	void SetRGBA(BYTE _r, BYTE _g, BYTE _b, BYTE _a);

	/** Insert description. 
	*/
	void SetBGRA(BYTE _b, BYTE _g, BYTE _r, BYTE _a);

	/** Insert description. 
	*/
	void SetR(BYTE _c);

	/** Insert description. 
	*/
	void SetG(BYTE _c);

	/** Insert description. 
	*/
	void SetB(BYTE _c);

	/** Insert description. 
	*/
	void SetA(BYTE _c);

	/** Insert description. 
	*/
	BYTE GetR(void);

	/** Insert description. 
	*/
	BYTE GetG(void);

	/** Insert description. 
	*/
	BYTE GetB(void);

	/** Insert description. 
	*/
	BYTE GetA(void);
};

#include "api/g2/zcolor.inl"

#undef __G2EXT_API_HEADER

#endif // __ZMATH_H_INCLUDED__