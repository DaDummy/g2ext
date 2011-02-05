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

#ifndef __API_G2_OCNPCINVENTORY_H__
#define __API_G2_OCNPCINVENTORY_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/g2/ztypes.h"
#include "api/g2/zstring.h"

class oCNpc;
class oCItem;
class oCItemContainer;

/** Insert description. */
class oCNpcInventory
{
public:
	oCItemContainer* inv; // FIXME!?
	oCNpc*			owner;
	zBOOL			packAbility;
	//zCListSort<oCItem> {
	int				inventory_Compare;
	int				inventory_data;
	int				inventory_next;
	//}
	zSTRING			packString;
	int				maxSlots;

public:
	//.text:0070E040 ; public: virtual int __thiscall oCNpcInventory::HandleEvent(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int HandleEvent(int pA) { XCALL(0x0070e040) };

	//.text:0070D1A0 ; public: virtual int __thiscall oCNpcInventory::IsEmpty(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int IsEmpty(int pA, int pB) { XCALL(0x0070d1a0) };

	//.text:0070C450 ; public: class oCItem * __thiscall oCNpcInventory::GetItem(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem* GetItem(int pA) { XCALL(0x0070c450) };

	//.text:0070C730 ; public: virtual class oCItem * __thiscall oCNpcInventory::Insert(class oCItem *)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem* Insert(oCItem* pA) { XCALL(0x0070C730) };

	//.text:0070CA80 ; public: virtual class oCItem * __thiscall oCNpcInventory::IsIn(class oCItem *, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem* IsIn(oCItem* pA, int pB) { XCALL(0x0070ca80) };

	//.text:0070CAC0 ; public: virtual class oCItem * __thiscall oCNpcInventory::IsIn(class zSTRING const &, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem* IsIn(zSTRING const& pA, int pB) { XCALL(0x0070cac0) };

	//.text:0070CAF0 ; public: virtual class oCItem * __thiscall oCNpcInventory::IsIn(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem* IsIn(int pA,int pB) { XCALL(0x0070caf0) };

	//.text:0070CE20 ; public: virtual class oCItem * __thiscall oCNpcInventory::Remove(class oCItem *, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem* Remove(oCItem* pA, int pB) { XCALL(0x0070ce20) };

	//.text:0070D080 ; public: virtual class oCItem * __thiscall oCNpcInventory::Remove(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem* Remove(int pA,int pB) { XCALL(0x0070d080) };

	//.text:0070D170 ; public: virtual class oCItem * __thiscall oCNpcInventory::Remove(class zSTRING const &, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem* Remove(zSTRING const& pA, int pB) { XCALL(0x0070d170) };

	//.text:0070CC70 ; public: virtual class oCItem * __thiscall oCNpcInventory::RemoveByPtr(class oCItem *, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem* RemoveByPtr(oCItem* pA, int pB) { XCALL(0x0070cc70) };

	//.text:0070C330 ; public: class oCNpc * __thiscall oCNpcInventory::GetOwner(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCNpc* GetOwner() { XCALL(0x0070c330) };

	//.text:0070F4D0 ; public: int __thiscall oCNpcInventory::CanCarry(class oCItem *)
	/** Insert description. 
	* @usable Ingame only
	*/
	int CanCarry(oCItem* pA) { XCALL(0x0070f4d0) };

	//.text:0070F390 ; public: void __thiscall oCNpcInventory::CheckForEquippedItems(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void CheckForEquippedItems(int pA) { XCALL(0x0070f390) };

	//.text:0070BDB0 ; public: void __thiscall oCNpcInventory::ClearInventory(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void ClearInventory() { XCALL(0x0070bdb0) };

	//.text:0070C450 ; public: class oCItem * __thiscall oCNpcInventory::GetItem(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int GetAmount(int pA) { XCALL(0x0070c970) };

	//.text:0070C690 ; public: int __thiscall oCNpcInventory::GetCategory(class oCItem *)
	/** Insert description. 
	* @usable Ingame only
	*/
	int GetCategory(oCItem* pA) { XCALL(0x0070c690) };

	//.text:0070C340 ; public: int __thiscall oCNpcInventory::GetNumItemsInCategory(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	int GetNumItemsInCategory() { XCALL(0x0070c340) };

	//.text:0070DE00 ; public: int __thiscall oCNpcInventory::HandleTrade(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int HandleTrade(int pA) { XCALL(0x0070de00) };

	//.text:00710020 ; public: void __thiscall oCNpcInventory::PackAllItems(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void PackAllItems(int pA) { XCALL(0x00710020) };

	//.text:00710040 ; public: void __thiscall oCNpcInventory::PackItemsInCategory(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void PackItemsInCategory(int pA) { XCALL(0x00710040) };

	//.text:0070F600 ; public: void __thiscall oCNpcInventory::SetPackAbility(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetPackAbility(int pA) { XCALL(0x0070f600) };

	//.text:0070C320 ; public: void __thiscall oCNpcInventory::SetOwner(class oCNpc *)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetOwner(class oCNpc *) { XCALL(0x000070C320) };

	//.text:00710030 ; public: void __thiscall oCNpcInventory::UnpackAllItems(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void UnpackAllItems() { XCALL(0x00710030) };

	//.text:0070F620 ; public: void __thiscall oCNpcInventory::UnpackCategory(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void UnpackCategory() { XCALL(0x0070f620) };

	//.text:00710A20 ; public: void __thiscall oCNpcInventory::UnpackItemsInCategory(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void UnpackItemsInCategory() { XCALL(0x00710a20) };

	//.text:0070BAF0 ; public: __thiscall oCNpcInventory::oCNpcInventory(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCNpcInventory() { XCALL(0x0070baf0) };

	//.text:0070BC00 ; public: virtual __thiscall oCNpcInventory::~oCNpcInventory(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	~oCNpcInventory() { XCALL(0x0070bc00) };

	//.text:0070C2F0 ; public: virtual void __thiscall oCNpcInventory::Close(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Close() { XCALL(0x0070c2f0) };

	//.text:0070BF10 ; public: virtual void __thiscall oCNpcInventory::Open(int, int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Open(int pA, int pB, int pC) { XCALL(0x0070bf10) };

	//.text:0070CBE0 ; public: virtual void __thiscall oCNpcInventory::Remove(class oCItem *)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Remove(oCItem* pA) { XCALL(0x0070cbe0) };
};

#undef __G2EXT_API_HEADER

#endif  //__API_G2_OCNPCINVENTORY_H__