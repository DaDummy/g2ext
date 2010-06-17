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

#ifndef __ZCOLOR_INL_INCLUDED__
#define __ZCOLOR_INL_INCLUDED__

#ifndef INLINE
#ifdef _MSC_VER
#if (_MSC_VER >= 1200)
#define INLINE __forceinline
#else
#define INLINE __inline
#endif
#endif
#endif

///////////////////////////////////////////////////////////////////////////////
//
// zCOLOR
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// -- constructors

INLINE zCOLOR::zCOLOR() 
{ 
	this->Clear(); 
};

INLINE zCOLOR::zCOLOR(zBYTE _r, zBYTE _g, zBYTE _b) 
{ 
	b = _b; 
	g = _g; 
	r = _r; 
	a = 255; 
}; 

INLINE zCOLOR::zCOLOR(zBYTE _r, zBYTE _g, zBYTE _b, zBYTE _a) 
{ 
	b = _b; 
	g = _g; 
	r = _r; 
	a = _a; 
};

INLINE zCOLOR::zCOLOR(zDWORD _color)
{
	color = _color;	
}; 

///////////////////////////////////////////////////////////////////////////////
// -- functions
INLINE void zCOLOR::Clear() 
{ 
	b = 0; 
	g = 0; 
	r = 0; 
	a = 255; 
};

INLINE void zCOLOR::SetRGBA(BYTE _r, BYTE _g, BYTE _b, BYTE _a) 
{ 
	r = _r; 
	g = _g; 
	b = _b; 
	a = _a; 
};

INLINE void zCOLOR::SetBGRA(BYTE _b, BYTE _g, BYTE _r, BYTE _a) 
{ 
	r = _r; 
	g = _g; 
	b = _b; 
	a = _a; 
};

INLINE void zCOLOR::SetR(BYTE _c) { r = _c; };
INLINE void zCOLOR::SetG(BYTE _c) { g = _c; };
INLINE void zCOLOR::SetB(BYTE _c) { b = _c; };
INLINE void zCOLOR::SetA(BYTE _c) { a = _c; };

INLINE BYTE zCOLOR::GetR(void) { return r; };
INLINE BYTE zCOLOR::GetG(void) { return g; };
INLINE BYTE zCOLOR::GetB(void) { return b; };
INLINE BYTE zCOLOR::GetA(void) { return a; };

#endif //__ZCOLOR_INL_INCLUDED__