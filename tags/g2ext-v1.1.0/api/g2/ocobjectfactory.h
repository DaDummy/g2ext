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

#ifndef __API_G2_OCOBJECTFACTORY_H__
#define __API_G2_OCOBJECTFACTORY_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include <api/g2/ztypes.h>
#include <api/g2/macros.h>

#include <api/g2/ocnpc.h>
#include <api/g2/ocitem.h>
#include <api/g2/zcworld.h>

/** Insert description. */
class oCObjectFactory
{
public:
	//.text:0076FDE0 ; public: virtual class oCItem * __thiscall oCObjectFactory::CreateItem(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem* CreateItem(zINT p1)
	{
		XCALL(0x0076FDE0);
	};

	//.text:0076FD20 ; public: virtual class oCNpc * __thiscall oCObjectFactory::CreateNpc(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCNpc* CreateNpc(zINT p1)
	{
		XCALL(0x0076FD20);
	};

	//.text:0076FCA0 ; public: virtual class zCWorld * __thiscall oCObjectFactory::CreateWorld(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zCWorld* CreateWorld(void)
	{
		XCALL(0x0076FCA0);
	};

	/** This method returns the current oCObjectFactory instance
	* @usable Ingame only
	*/
	inline static oCObjectFactory* GetFactory(void) { return *(oCObjectFactory**)0x008D8DF0; };
};

#undef __G2EXT_API_HEADER

#endif // __API_G2_OCOBJECTFACTORY_H__