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

#ifndef __API_G2_ZCOBJECT_H__
#define __API_G2_ZCOBJECT_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"

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
	//.text:00401ED0 ; public: virtual void __thiscall zCObject::Archive(class zCArchiver &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Archive(zCArchiver & pA)
	{
		XCALL(0x00401ED0);
	};

	//.text:005A90A0 ; public: class zCObject * __thiscall zCObject::CreateCopy(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zCObject* CreateCopy(void)
	{
		XCALL(0x005A90A0);
	};

	//.text:005A9CD0 ; public: class zSTRING const & __thiscall zCObject::GetObjectName(void)const
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING & GetObjectName(void)
	{
		XCALL(0x005A9CD0);
	};

	//.text:0040C310 ; public: int __thiscall zCObject::Release(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	int Release(void)
	{
		XCALL(0x0040C310);
	};

	//.text:005A9CE0 ; public: int __thiscall zCObject::SetObjectName(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	int SetObjectName(zSTRING & pA)
	{
		XCALL(0x005A9CE0);
	};

	//.text:00401EE0 ; public: virtual void __thiscall zCObject::Unarchive(class zCArchiver &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Unarchive(zCArchiver & pA)
	{
		XCALL(0x00401EE0);
	};	
};

#undef __G2EXT_API_HEADER

#endif //__API_G2_ZCOBJECT_H__