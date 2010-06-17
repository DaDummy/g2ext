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

#ifndef __ZTIMER_H_INCLUDED__
#define __ZTIMER_H_INCLUDED__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"

/** Insert description. */
class zCTimer
{
private:
	float factorMotion;        //zREAL 
	float frameTimeFloat;      //zREAL [msec]
	float totalTimeFloat;      //zREAL [msec]
	float frameTimeFloatSecs;  //zREAL  [s]
	float totalTimeFloatSecs;  //zREAL  [s]
	DWORD lastTimer;           //zDWORD
	DWORD frameTime;           //zDWORD [msec]
	DWORD totalTime;           //zDWORD [msec]
	DWORD minFrameTime;        //zDWORD
	DWORD forcedMaxFrameTime;  //zDWORD
public:
	//.text:005F9680 ; public: __thiscall zCTimer::zCTimer(void)
	zCTimer(void) _XCALL(0x005F9680);

	//.text:006370B0 ; public: void __thiscall zCTimer::SetMotionFactor(float)
	void SetMotionFactor(float p1) _XCALL(0x006370B0);

	//.text:005F9920 ; public: void __thiscall zCTimer::LimitFPS(int)
	void LimitFPS(int p1) _XCALL(0x005F9920);

	//.text:005F96B0 ; public: void __thiscall zCTimer::ResetTimer(void)
	void ResetTimer(void) _XCALL(0x005F96B0);

	//.text:005F9800 ; int __stdcall zCTimer__SetFrameTime(float)
	void SetFrameTime(float p1) _XCALL(0x005F9800);

	//.text:005F9890 ; public: void __thiscall zCTimer::SetMaxFPS(unsigned long)
	void SetMaxFPS(DWORD p1) _XCALL(0x005F9890);
	
	//.data:0099B3D4 ; class zCTimer ztimer
	static zCTimer* GetTimer()
	{
		return (zCTimer*)0x0099B3D4;
	};
};

#undef __G2EXT_API_HEADER

#endif  //__ZTIMER_H_INCLUDED__
