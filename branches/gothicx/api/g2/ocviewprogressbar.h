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

#ifndef __OCVIEWPROGRESSBAR_H_INCLUDED__
#define __OCVIEWPROGRESSBAR_H_INCLUDED__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"

/** Insert description. */
class oCViewProgressBar : public zCView
{
private:
	char _data[0x200];
public:
	//.text:0046F300 ; public: void __thiscall zCViewProgressBar::Draw(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Draw(void)
	{
		XCALL(0x0046F300);
	};

	//.text:0046F190 ; public: void __thiscall zCViewProgressBar::HandleChange(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void HandleChange(void)
	{
		XCALL(0x0046F190);
	};

	//.text:0046ED40 ; public: void __thiscall zCViewProgressBar::Init(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Init(void)
	{
		XCALL(0x0046ED40);
	};

	//.text:0046F400 ; public: void __thiscall zCViewProgressBar::ResetRange(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void ResetRange(void)
	{
		XCALL(0x0046ED40);
	};

	//.text:0046EEC0 ; public: void __thiscall zCViewProgressBar::SetPercent(int, class zSTRING)
	/** Insert description. 
	* @usable Ingame only
	*/
	void ResetRange(int pA, zSTRING & pB)
	{
		XCALL(0x0046EEC0);
	};

	//.text:0046F340 ; public: void __thiscall zCViewProgressBar::SetRange(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void ResetRange(int pA, int pB)
	{
		XCALL(0x0046F340);
	};
	
	//.text:0046E9D0 ; public: __thiscall zCViewProgressBar::zCViewProgressBar(int, int, int, int, enum  zTviewID)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCViewProgressBar(int x1, int y1, int x2, int y2, zTviewID ItemID = VIEW_ITEM)
	{
		XCALL(0x0046E9D0);
	};
};

#undef __G2EXT_API_HEADER

#endif  //__OCVIEWPROGRESSBAR_H_INCLUDED__