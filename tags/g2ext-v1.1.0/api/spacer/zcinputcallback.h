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

#ifndef __API_SPACER_INPUTCALLBACK_H__
#define __API_SPACER_INPUTCALLBACK_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifndef _G2EXT_COMPILE_SPACER
#error Cannot use spacer headers on non spacer dll (_G2EXT_COMPILE_SPACER not defined)
#endif

#include "api/spacer/ztypes.h"
#include "api/spacer/ztypes.h"

/** Insert description. */
class zCInputCallback
{
public:
	//.text:00811D10 ; public: __thiscall zCInputCallback::zCInputCallback(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zCInputCallback::zCInputCallback(void)
	{
		XCALL(0x00811D10); // spacer
	};

	//.text:00811E80 ; public: int __thiscall zCInputCallback::GetEnableHandleEvent(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	int zCInputCallback::GetEnableHandleEvent(void)
	{
		XCALL(0x00811E80); // spacer
	};

	//.text:0041F8A0 ; public: virtual int __thiscall zCInputCallback::HandleEvent(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual int zCInputCallback::HandleEvent(int key)
	{
		XCALL(0x0041F8A0); // spacer
	};

	//.text:00811E00 ; public: void __thiscall zCInputCallback::SetEnableHandleEvent(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void zCInputCallback::SetEnableHandleEvent(int pA)
	{
		XCALL(0x00811E00); // spacer
	};

	//.text:00811D90 ; public: void __thiscall zCInputCallback::SetHandleEventTop(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void zCInputCallback::SetHandleEventTop(void)
	{
		XCALL(0x00811D90); // spacer
	};

	//.text:00811EE0 ; public: static void __cdecl zCInputCallback::GetInput(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	static void zCInputCallback::GetInput(void)
	{
		XCALL(0x00811EE0);
	};

	//.text:00811EB0 ; public: static int __cdecl zCInputCallback::DoEvents(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	static int zCInputCallback::DoEvents(int pA)
	{
		XCALL(0x00811EB0);
	};
};

#undef __G2EXT_API_HEADER

#endif  //__API_SPACER_INPUTCALLBACK_H__