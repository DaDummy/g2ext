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

#ifndef __API_G2_OCWORLDTIMER_H__
#define __API_G2_OCWORLDTIMER_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#include "api/g2/ztypes.h"

/** Insert description. */
class oCWorldTimer
{
public:
	//.text:00780DD0 ; public: int __thiscall oCWorldTimer::GetDay(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	int GetDay(void)
	{
		XCALL(0x00780DD0)
	};

	//.text:00780E80 ; public: float __thiscall oCWorldTimer::GetFullTime(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	float GetFullTime(void)
	{
		XCALL(0x00780E80)
	};

	//.text:00780DF0 ; public: void __thiscall oCWorldTimer::GetTime(int &, int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetTime(int & p1, int & p2)
	{
		XCALL(0x00780DF0)
	};

	//.text:00780EC0 ; public: class zSTRING __thiscall oCWorldTimer::GetTimeString(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING GetTimeString(void)
	{
		XCALL(0x00780EC0)
	};

	//.text:00781280 ; public: int __thiscall oCWorldTimer::IsDay(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	int IsDay(void)
	{
		XCALL(0x00781280)
	};

	//.text:00781110 ; public: int __thiscall oCWorldTimer::IsLater(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int IsLater(int p1, int p2)
	{
		XCALL(0x00781110)
	};

	//.text:00781150 ; public: int __thiscall oCWorldTimer::IsLaterEqual(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int IsLaterEqual(int p1, int p2)
	{
		XCALL(0x00781150)
	};

	//.text:00781300 ; public: int __thiscall oCWorldTimer::IsNight(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	int IsNight(void)
	{
		XCALL(0x00781300)
	};

	//.text:00781190 ; public: int __thiscall oCWorldTimer::IsTimeBetween(int, int, int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int IsTimeBetween(int p1, int p2, int p3, int p4)
	{
		XCALL(0x00781190)
	};

	//.text:00780DE0 ; public: void __thiscall oCWorldTimer::SetDay(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetDay(int p1)
	{
		XCALL(0x00780DE0)
	};

	//.text:00780E90 ; public: void __thiscall oCWorldTimer::SetFullTime(float)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetFullTime(float p1)
	{
		XCALL(0x00780E90)
	};

	//.text:00780E40 ; public: void __thiscall oCWorldTimer::SetTime(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetTime(int p1, int p2)
	{
		XCALL(0x00780E40)
	};

	//.text:00780D80 ; public: void __thiscall oCWorldTimer::Timer(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Timer(void)
	{
		XCALL(0x00780D80)
	};

	//.text:00780D60 ; public: __thiscall oCWorldTimer::oCWorldTimer(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCWorldTimer(void)
	{
		XCALL(0x00780D60)
	};
};

#undef __G2EXT_API_HEADER

#endif // __API_G2_OCWORLDTIMER_H__
