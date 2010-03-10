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

#ifndef __OCVIEWSTATUSBAR_H_INCLUDED__
#define __OCVIEWSTATUSBAR_H_INCLUDED__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"
#include "api/g2/zcview.h"

/** Insert description. */
class oCViewStatusBar
{
private:
	char _data[0x1024]; // FIXME/TODO: Get correct size!
public:
	//.text:0043D540 ; public: __thiscall oCViewStatusBar::oCViewStatusBar(int, int, int, int, enum  zTviewID)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCViewStatusBar(int x1, int y1, int x2, int y2, zTviewID ItemID = VIEW_ITEM)
	{
		XCALL(0x0043D540);
	};

	//.text:0043D410 ; public: __thiscall oCViewStatusBar::oCViewStatusBar(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCViewStatusBar(void)
	{
		XCALL(0x0043D410);
	};

	//.text:0043D620 ; public: void __thiscall oCViewStatusBar::Init(int, int, float)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Init(int pA, int pB, float pC)
	{
		XCALL(0x0043D620);
	};
	
	//.text:0043D7B0 ; public: void __thiscall oCViewStatusBar::SetTextures(class zSTRING const &, class zSTRING const &, class zSTRING const &, class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetTextures(zSTRING & pA, zSTRING & pB, zSTRING & pC, zSTRING & pD)
	{
		XCALL(0x0043D7B0);
	};

	//.text:0043DD90 ; int __stdcall oCViewStatusBar__SetValue(float)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetValue(float pA)
	{
		XCALL(0x0043DD90);
	};

	//.text:007A5B20 ; public: void __thiscall zCView::Init(int, int, int, int, enum  zTviewID)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Init(int pA, int pB, int pC, int pD, zTviewID pE = VIEW_ITEM)
	{
		XCALL(0x007A5B20);
	};

	//.text:007A6070 ; public: void __thiscall zCView::SetAlphaBlendFunc(enum  zTRnd_AlphaBlendFunc const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetAlphaBlendFunc(zTRnd_AlphaBlendFunc p1)
	{
		XCALL(0x007A6070);
	};

	//.text:0043DCB0 ; int __stdcall oCViewStatusBar__SetRange(float, float)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetRange(float pA, float pB)
	{
		XCALL(0x0043DCB0);
	};

	//.text:0043DBA0 ; int __stdcall oCViewStatusBar__SetMaxRange(float, float)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetMaxRange(float pA, float pB)
	{
		XCALL(0x0043DBA0);
	};

	//.text:007A75B0 ; public: void __thiscall zCView::SetPos(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetPos(int x, int y)
	{
		XCALL(0x007A75B0);
	};

	//.text:007A77A0 ; public: void __thiscall zCView::SetSize(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetSize(int x, int y)
	{
		XCALL(0x007A77A0);
	};

	//.text:007A7660 ; public: void __thiscall zCView::GetPos(int &, int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetPos(int & x, int & y)
	{
		XCALL(0x007A7660);
	};

	//.text:007A7810 ; public: void __thiscall zCView::GetSize(int &, int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetSize(int & x, int & y)
	{
		XCALL(0x007A7810);
	};
};

#undef __G2EXT_API_HEADER

#endif  //__OCVIEWSTATUSBAR_H_INCLUDED__