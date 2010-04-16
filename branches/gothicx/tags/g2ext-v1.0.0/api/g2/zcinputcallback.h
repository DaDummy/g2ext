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

#ifndef __API_G2_INPUTCALLBACK_H__
#define __API_G2_INPUTCALLBACK_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"

/** Insert description. */
class zCInputCallback
{
public:
	//.text:007A53F0 ; public: __thiscall zCInputCallback::zCInputCallback(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zCInputCallback::zCInputCallback(void)
	{
		XCALL(0x007A53F0);
	};

	//.text:007A5560 ; public: int __thiscall zCInputCallback::GetEnableHandleEvent(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	int zCInputCallback::GetEnableHandleEvent(void)
	{
		XCALL(0x007A5560);
	};

	//.text:0043D4E0 ; public: virtual int __thiscall zCInputCallback::HandleEvent(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual int zCInputCallback::HandleEvent(int key)
	{
		XCALL(0x0043D4E0);
	};

	//.text:007A54E0 ; public: void __thiscall zCInputCallback::SetEnableHandleEvent(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void zCInputCallback::SetEnableHandleEvent(int pA)
	{
		XCALL(0x007A54E0);
	};

	//.text:007A5470 ; public: void __thiscall zCInputCallback::SetHandleEventTop(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void zCInputCallback::SetHandleEventTop(void)
	{
		XCALL(0x007A5470);
	};

	//.text:007A55C0 ; public: static void __cdecl zCInputCallback::GetInput(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	static void zCInputCallback::GetInput(void)
	{
		XCALL(0x007A55C0);
	};

	//.text:007A5590 ; public: static int __cdecl zCInputCallback::DoEvents(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	static int zCInputCallback::DoEvents(int pA)
	{
		XCALL(0x007A5590);
	};
};

#undef __G2EXT_API_HEADER

#endif  //__API_G2_INPUTCALLBACK_H__