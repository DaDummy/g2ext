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

#ifndef __API_SPACER_OCNPCINVENTORY_H__
#define __API_SPACER_OCNPCINVENTORY_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifndef _G2EXT_COMPILE_SPACER
#error Cannot use spacer headers on non spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/spacer/ztypes.h"
#include "api/spacer/zstring.h"

class oCNpc;
class oCItem;

/** Insert description. */
class oCNpcInventory
{
public:
	oCItemContainer		inv;
	oCNpc*				owner;
	zBOOL				packAbility;
	zCListSort<oCItem> inventory;
	zSTRING				packString;
	int					maxSlots;
public:
	//.text:00567C60 ; public: virtual int __thiscall oCNpcInventory::HandleEvent(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int HandleEvent(int pA) { XCALL(0x00567C60) };

	//.text:00566DC0 ; public: virtual int __thiscall oCNpcInventory::IsEmpty(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int IsEmpty(int pA, int pB) { XCALL(0x00566DC0) };

	//.text:00566350 ; public: virtual class oCItem * __thiscall oCNpcInventory::Insert(class oCItem *)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem* Insert(oCItem* pA) { XCALL(0x00566350) };

	//.text:005666A0 ; public: virtual class oCItem * __thiscall oCNpcInventory::IsIn(class oCItem *, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem* IsIn(oCItem* pA, int pB) { XCALL(0x005666A0) };

	//.text:005666E0 ; public: virtual class oCItem * __thiscall oCNpcInventory::IsIn(class zSTRING const &, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem* IsIn(zSTRING const& pA, int pB) { XCALL(0x005666E0) };

	//.text:00566710 ; public: virtual class oCItem * __thiscall oCNpcInventory::IsIn(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem* IsIn(int pA,int pB) { XCALL(0x00566710) };

	//.text:00566A40 ; public: virtual class oCItem * __thiscall oCNpcInventory::Remove(class oCItem *, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem* Remove(oCItem* pA, int pB) { XCALL(0x00566A40) };

	//.text:00566CA0 ; public: virtual class oCItem * __thiscall oCNpcInventory::Remove(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem* Remove(int pA,int pB) { XCALL(0x00566CA0) };

	//.text:00566D90 ; public: virtual class oCItem * __thiscall oCNpcInventory::Remove(class zSTRING const &, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem* Remove(zSTRING const& pA, int pB) { XCALL(0x00566D90) };

	//.text:00566890 ; public: virtual class oCItem * __thiscall oCNpcInventory::RemoveByPtr(class oCItem *, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem* RemoveByPtr(oCItem* pA, int pB) { XCALL(0x00566890) };

	//.text:00565F50 ; public: class oCNpc * __thiscall oCNpcInventory::GetOwner(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCNpc* GetOwner() { XCALL(0x00565F50) };

	//.text:005690F0 ; public: int __thiscall oCNpcInventory::CanCarry(class oCItem *)
	/** Insert description. 
	* @usable Ingame only
	*/
	int CanCarry(oCItem* pA) { XCALL(0x005690F0) };

	//.text:00568FB0 ; public: void __thiscall oCNpcInventory::CheckForEquippedItems(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void CheckForEquippedItems(int pA) { XCALL(0x00568FB0) };

	//.text:005659D0 ; public: void __thiscall oCNpcInventory::ClearInventory(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void ClearInventory() { XCALL(0x005659D0) };

	//.text:00566070 ; public: class oCItem * __thiscall oCNpcInventory::GetItem(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int GetItem(int pA) { XCALL(0x00566070) };

	//.text:005662B0 ; public: int __thiscall oCNpcInventory::GetCategory(class oCItem *)
	/** Insert description. 
	* @usable Ingame only
	*/
	int GetCategory(oCItem* pA) { XCALL(0x005662B0) };

	//.text:00565F60 ; public: int __thiscall oCNpcInventory::GetNumItemsInCategory(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	int GetNumItemsInCategory() { XCALL(0x00565F60) };

	//.text:00567A20 ; public: int __thiscall oCNpcInventory::HandleTrade(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int HandleTrade(int pA) { XCALL(0x00567A20) };

	//.text:00569C40 ; public: void __thiscall oCNpcInventory::PackAllItems(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void PackAllItems(int pA) { XCALL(0x00569C40) };

	//.text:00569C60 ; public: void __thiscall oCNpcInventory::PackItemsInCategory(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void PackItemsInCategory(int pA) { XCALL(0x00569C60) };

	//.text:00569220 ; public: void __thiscall oCNpcInventory::SetPackAbility(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetPackAbility(int pA) { XCALL(0x00569220) };

	//.text:00565F40 ; public: void __thiscall oCNpcInventory::SetOwner(class oCNpc *)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetOwner(class oCNpc *) { XCALL(0x00565F40) };

	//.text:00569C50 ; public: void __thiscall oCNpcInventory::UnpackAllItems(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void UnpackAllItems() { XCALL(0x00569C50) };

	//.text:00569240 ; public: void __thiscall oCNpcInventory::UnpackCategory(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void UnpackCategory() { XCALL(0x00569240) };

	//.text:0056A640 ; public: void __thiscall oCNpcInventory::UnpackItemsInCategory(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void UnpackItemsInCategory() { XCALL(0x0056A640) };

	//.text:00565710 ; public: __thiscall oCNpcInventory::oCNpcInventory(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCNpcInventory() { XCALL(0x00565710) };

	//.text:00565F10 ; public: virtual void __thiscall oCNpcInventory::Close(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Close() { XCALL(0x00565F10) };

	//.text:00565B30 ; public: virtual void __thiscall oCNpcInventory::Open(int, int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Open(int pA, int pB, int pC) { XCALL(0x00565B30) };

	//.text:00566800 ; public: virtual void __thiscall oCNpcInventory::Remove(class oCItem *)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Remove(oCItem* pA) { XCALL(0x00566800) };
};

#undef __G2EXT_API_HEADER

#endif  //__API_SPACER_OCNPCINVENTORY_H__