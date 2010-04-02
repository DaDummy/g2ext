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

#ifndef __API_SPACER_ZTIMER_H__
#define __API_SPACER_ZTIMER_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifndef _G2EXT_COMPILE_SPACER
#error Cannot use spacer headers on non spacer dll (_G2EXT_COMPILE_SPACER not defined)
#endif

#include "api/spacer/ztypes.h"
#include "api/spacer/macros.h"

/** Insert description. */
class zCTimer
{
public:
	//.text:007C1E10 ; public: void __thiscall zCTimer::SetMotionFactor(float)
	void SetMotionFactor(float p1)
	{
		XCALL(0x007C1E10);
	};

	//.data:0099B3D4 ; class zCTimer ztimer
	static zCTimer* GetTimer()
	{
		return (zCTimer*)0x00B18DF8;
	};
};

#undef __G2EXT_API_HEADER

#endif  //__API_SPACER_ZTIMER_H__
