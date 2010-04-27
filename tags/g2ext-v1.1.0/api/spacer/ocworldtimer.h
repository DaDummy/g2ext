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

#ifndef __API_SPACER_OCWORLDTIMER_H__
#define __API_SPACER_OCWORLDTIMER_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifndef _G2EXT_COMPILE_SPACER
#error Cannot use spacer headers on non spacer dll (_G2EXT_COMPILE_SPACER not defined)
#endif

#include "api/spacer/ztypes.h"

/** Insert description. */
class oCWorldTimer
{
private:
	char m_data[8];
public:
	//.text:005DA3B0 ; public: int __thiscall oCWorldTimer::GetDay(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	int GetDay(void)
	{
		XCALL(0x005DA3B0) // spacer
	};

	//.text:005DA460 ; public: float __thiscall oCWorldTimer::GetFullTime(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	float GetFullTime(void)
	{
		XCALL(0x005DA460) // spacer
	};

	//.text:005DA3D0 ; public: void __thiscall oCWorldTimer::GetTime(int &, int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetTime(int & p1, int & p2)
	{
		XCALL(0x005DA3D0) // spacer
	};

	//.text:005DA4A0 ; public: class zSTRING __thiscall oCWorldTimer::GetTimeString(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING GetTimeString(void)
	{
		XCALL(0x005DA4A0) // spacer
	};

	//.text:005DA9C0 ; public: int __thiscall oCWorldTimer::IsDay(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	int IsDay(void)
	{
		XCALL(0x005DA9C0) // spacer
	};

	//.text:005DA850 ; public: int __thiscall oCWorldTimer::IsLater(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int IsLater(int p1, int p2)
	{
		XCALL(0x005DA850) // spacer
	};

	//.text:005DA890 ; public: int __thiscall oCWorldTimer::IsLaterEqual(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int IsLaterEqual(int p1, int p2)
	{
		XCALL(0x005DA890) // spacer
	};

	//.text:005DAA40 ; public: int __thiscall oCWorldTimer::IsNight(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	int IsNight(void)
	{
		XCALL(0x005DAA40) // spacer
	};

	//.text:005DA8D0 ; public: int __thiscall oCWorldTimer::IsTimeBetween(int, int, int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int IsTimeBetween(int p1, int p2, int p3, int p4)
	{
		XCALL(0x005DA8D0) // spacer
	};

	//.text:005DA3C0 ; public: void __thiscall oCWorldTimer::SetDay(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetDay(int p1)
	{
		XCALL(0x005DA3C0) // spacer
	};

	//.text:005DA470 ; public: void __thiscall oCWorldTimer::SetFullTime(float)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetFullTime(float p1)
	{
		XCALL(0x005DA470) // spacer
	};

	//.text:005DA420 ; public: void __thiscall oCWorldTimer::SetTime(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetTime(int p1, int p2)
	{
		XCALL(0x005DA420) // spacer
	};

	//.text:005DA360 ; public: void __thiscall oCWorldTimer::Timer(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Timer(void)
	{
		XCALL(0x005DA360) // spacer
	};

	//.text:005DA340 ; public: __thiscall oCWorldTimer::oCWorldTimer(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCWorldTimer(void)
	{
		XCALL(0x005DA340) // spacer
	};
};

#undef __G2EXT_API_HEADER

#endif // __API_SPACER_OCWORLDTIMER_H__
