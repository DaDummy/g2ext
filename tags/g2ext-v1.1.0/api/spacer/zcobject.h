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

#ifndef __API_SPACER_ZCOBJECT_H__
#define __API_SPACER_ZCOBJECT_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifndef _G2EXT_COMPILE_SPACER
#error Cannot use spacer headers on non spacer dll (_G2EXT_COMPILE_SPACER not defined)
#endif

#include "api/spacer/ztypes.h"
#include "api/spacer/macros.h"

class zCArchiver;

/** ZenGin object base class. */
class zCObject
{
protected:
	int		refCtr;
	int		hashIndex;
	int		hashNext;
	zSTRING objectName;
public:    
	//.text:00442E20 ; public: virtual void __thiscall zCObject::Archive(class zCArchiver &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Archive(zCArchiver & pA)
	{
		XCALL(0x00442E20); // spacer
	};

	//.text:00734190 ; public: class zCObject * __thiscall zCObject::CreateCopy(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zCObject* CreateCopy(void)
	{
		XCALL(0x00734190); // spacer
	};

	//.text:00734DC0 ; public: class zSTRING const & __thiscall zCObject::GetObjectName(void)const
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING & GetObjectName(void)
	{
		XCALL(0x00734DC0); // spacer
	};

	//.text:00431A70 ; public: int __thiscall zCObject::Release(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	int Release(void)
	{
		XCALL(0x00431A70); // spacer
	};

	//.text:00734DD0 ; public: int __thiscall zCObject::SetObjectName(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	int SetObjectName(zSTRING & pA)
	{
		XCALL(0x00734DD0); // spacer
	};

	//.text:00442E30 ; public: virtual void __thiscall zCObject::Unarchive(class zCArchiver &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Unarchive(zCArchiver & pA)
	{
		XCALL(0x00442E30); // spacer
	};	
};

#undef __G2EXT_API_HEADER

#endif //__API_SPACER_ZCOBJECT_H__