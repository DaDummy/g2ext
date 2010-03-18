/*////////////////////////////////////////////////////////////////////////////

This file is part of the G2Ext SDK headers.

//////////////////////////////////////////////////////////////////////////////

The G2Ext SDK headers

Copyright � 2009, 2010 by Paindevs and Patrick Vogel

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

#ifndef __API_G2_ZCWORLD_H__
#define __API_G2_ZCWORLD_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"

class zCVob;

/** Insert description. */
class zCWorld// : public zCObject
{
private:
	char m_data[1024];
public:
	//.text:00624810 ; public: class zCTree<class zCVob> * __thiscall zCWorld::AddVob(class zCVob *)
	/** Insert description. 
	* @usable Ingame only
	*/
	void* AddVob(zCVob* pA) 
	{ 
		XCALL(0x00624810) 
	};

	//.text:007800C0 ; public: virtual void __thiscall oCWorld::RemoveVob(class zCVob *)
	/** Insert description. 
	* @usable Ingame only
	*/
	void RemoveVob(zCVob* pA) 
	{ 
		XCALL(0x007800C0) 
	};

	//.text:007806C0 ; public: virtual void __thiscall oCWorld::SearchVobListByName(class zSTRING const &, class zCArray<class zCVob *> &)
	/** Insert description.
	* @usable Ingam only.
	*/
	void SearchVobListByName(const zSTRING& name, zCArray<zCVob*>& resultList)
	{
		XCALL(0x007806C0);
	};
};

#undef __G2EXT_API_HEADER

#endif // __API_G2_ZCWORLD_H__