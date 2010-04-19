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

#ifndef __API_G2_OCITEM_H__
#define __API_G2_OCITEM_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"
#include "api/g2/zcobject.h"
#include "api/g2/ocvob.h"
#include "api/g2/zcvob.h"

class oCNpc;
class zCView;
class zCWorld;

/** Insert description. */
class oCItem : public oCVob
{
public:
	int		idx;
	zSTRING name;
	zSTRING nameID;
	int		hp;
	int		hp_max;
	int     mainflags;
	int		flags;
	int		weight;
	int     value;

	// -- weapons		
	int     damageType;
	int     damageTotal;
	int     damage[8];

	// -- armor 
	int     wear;
	int     protection[8];

	// -- food
	int     nutrition;

	// -- use attributes
	int     cond_atr[3];
	int     cond_value[3];

	// -- attributes that will be changed on equip
	int     change_atr[3];
	int     change_value[3];

	// -- parser functions
	int     magic;
	int     on_equip;
	int     on_unequip;	
	int     on_state[4];			

	// -- owner									
	int		owner;			//	owner: npc instance
	int		ownerGuild;		//	owner: guild
	int		disguiseGuild;

	// -- visual
	zSTRING	visual;

	// -- change of mesh on equip
	zSTRING visual_change;	//	ASC file
	zSTRING effect;			//  Effect instance

	int		visual_skin;

	zSTRING	scemeName;
	int		material;	
	int		munition;		//	Instance of ammunition

	int 	spell;			
	int		range;			

	int		mag_circle;

	zSTRING	description;
	zSTRING	text[6];
	int		count[6];

	// -- inventory presentation
	int	    inv_zbias;								//  far plane (how far the item goes into the room by the z-axis)
	int		inv_rotx;								//  rotation around x-axis (in degrees)
	int 	inv_roty;								//  rotation around y-axis (in degrees)
	int 	inv_rotz;								//  rotation around z-axis (in degrees)
	int 	inv_animate;							//  rotate the item

private:
	char _data[28];

public:
	//.text:00712360 ; public: void __thiscall oCItem::CopyDamage(class oCItem *)
	/** Insert description. 
	* @usable Ingame only
	*/
	void CopyDamage(oCItem* p1)
	{
		XCALL(0x00712360 );
	};

	//.text:00712160 ; public: zINT __thiscall oCItem::GetCount(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT GetCount(zINT p1)
	{
		XCALL(0x00712160);
	};

	//.text:00712520 ; public: unsigned long __thiscall oCItem::GetDamageTypes(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zDWORD GetDamageTypes(void)
	{
		XCALL(0x00712520);
	};

	//.text:007120E0 ; public: class zSTRING & __thiscall oCItem::GetDescription(void)
	/** This method returns the description text of the item.
	* @return Description text.
	* @usable Ingame only
	*/
	zSTRING& GetDescription(void)
	{	
		XCALL(0x007120E0);
	};

	//.text:007127E0 ; public: zINT __thiscall oCItem::GetDisguiseGuild(void)
	/** This method returns the disguise guild of the item.
	* @return Disguise guild. 
	* @usable Ingame only
	*/
	zINT GetDisguiseGuild(void)
	{
		XCALL(0x007127E0);
	};

	//.text:00712B30 ; public: class zSTRING __thiscall oCItem::GetEffectName(void)
	/** This method returns the effect name of the item.
	* @return Effect name. 
	* @usable Ingame only
	*/
	zSTRING GetEffectName(void)
	{
		XCALL(0x00712B30);
	};

	//.text:00712500 ; public: zINT __thiscall oCItem::GetFullDamage(void)
	/** This method returns the full damage of the item.
	* @return Full damage. 
	* @usable Ingame only
	*/
	zINT GetFullDamage(void)
	{
		XCALL(0x00712500);
	};

	//.text:00712340 ; public: zINT __thiscall oCItem::GetFullProtection(void)
	/** This method returns the full protection of the item.
	* @return Full protection. 
	* @usable Ingame only
	*/
	zINT GetFullProtection(void)
	{
		XCALL(0x00712340);
	};

	//.text:00711420 ; public: virtual zINT __thiscall oCItem::GetInstance(void)
	/** This method returns the instance of the item.
	* @return Item instance. 
	* @usable Ingame only
	*/
	zINT GetInstance(void)
	{
		XCALL(0x00711420);
	};

	//.text:00713D30 ; public: virtual class zSTRING __thiscall oCItem::GetInstanceName(void)
	/** This method returns the instance name of the item.
	* @return Item instance name. 
	* @usable Ingame only
	*/
	zSTRING GetInstanceName(void)
	{
		XCALL(0x00713D30);
	};

	//.text:00712880 ; public: class zSTRING __thiscall oCItem::GetName(int)
	/** This method returns the instance name of the item.
	* @param  Item instance.
	* @return Item instance name. 
	* @usable Ingame only
	*/
	zSTRING GetName(zINT instance)
	{
		XCALL(0x00712880);
	};

	//.text:00698E50 ; public: class zSTRING __thiscall oCItem::GetSchemeName(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING GetSchemeName(void)
	{
		XCALL(0x00698E50);
	};

	//.text:00713CC0 ; public: virtual zINT __thiscall oCItem::GetScriptInstance(class zSTRING &, zINT &)
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING GetScriptInstance(zSTRING & p1, zINT p2)
	{
		XCALL(0x00713CC0);
	};

	//.text:00712B80 ; public: zINT __thiscall oCItem::GetStateEffectFunc(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT GetStateEffectFunc(zINT p1)
	{
		XCALL(0x00712B80);
	};

	//.text:007128D0 ; public: class zSTRING __thiscall oCItem::GetStatus(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT GetStatus(void)
	{
		XCALL(0x007128D0);
	};

	//.text:007120F0 ; public: class zSTRING & __thiscall oCItem::GetText(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING & GetText(zINT p1)
	{
		XCALL(0x007120F0);
	};

	//.text:00712650 ; public: zINT __thiscall oCItem::GetValue(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT GetValue(void)
	{
		XCALL(0x00712650);
	};

	//.text:00712A40 ; public: class zSTRING __thiscall oCItem::GetVisualChange(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING GetVisualChange(void)
	{
		XCALL(0x00712A40);
	};

	//.text:007126B0 ; public: zINT __thiscall oCItem::GetWeight(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT GetWeight(void)
	{
		XCALL(0x007126B0);
	};

	//.text:00711970 ; public: virtual void __thiscall oCItem::Init(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Init(void)
	{
		XCALL(0x00711970);
	};

	//.text:00712550 ; public: zINT __thiscall oCItem::IsDeadly(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT IsDeadly(void)
	{
		XCALL(0x00712550);
	};

	//.text:007127C0 ; public: virtual zINT __thiscall oCItem::IsOwnedByGuild(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT IsOwnedByGuild(zINT p1)
	{
		XCALL(0x007127C0);
	};

	//.text:007127A0 ; public: virtual zINT __thiscall oCItem::IsOwnedByNpc(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT IsOwnedByNpc(zINT p1)
	{
		XCALL(0x007127A0);
	};

	//.text:007125A0 ; public: zINT __thiscall oCItem::MultiSlot(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT MultiSlot(void)
	{
		XCALL(0x007125A0);
	};

	//.text:00712C00 ; public: void __thiscall oCItem::RemoveEffect(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void RemoveEffect(void)
	{
		XCALL(0x00712C00);
	};

	// -- .text:00714020 ; public: virtual zINT __fastcall oCItem::Render(struct zTRenderContext &)

	//.text:007133C0 ; public: void __thiscall oCItem::RenderItem(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void RenderItem(zINT p1, zINT p2)
	{
		XCALL(0x007133C0);
	};

	// -- .text:00713AC0 ; zINT __stdcall oCItem__RenderItem(int, int, float)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT RenderItem(zINT p1, zINT p2, zFLOAT p3)
	{
		XCALL(0x00713AC0);
	};

	// -- .text:00713800 ; zINT __stdcall oCItem__RenderItemPlaceCamera(int, float)
	/** Insert description. 
	* @usable Ingame only
	*/
	void RenderItemPlaceCamera(zINT p1, zFLOAT p2)
	{
		XCALL(0x00713800);
	};

	// -- .text:00712F10 ; zINT __stdcall oCItem__RotateForInventory(float)
	/** Insert description. 
	* @usable Ingame only
	*/
	void RotateForInventory(zFLOAT p1)
	{
		XCALL(0x00712F10);
	};

	//.text:007132E0 ; public: void __thiscall oCItem::RotateInInventory(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void RotateInInventory(void)
	{
		XCALL(0x007132E0);
	};

	//.text:00713CF0 ; public: virtual zINT __thiscall oCItem::SetByScriptInstance(class zSTRING const *, zINT)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual zINT SetByScriptInstance(const zSTRING* p1, zINT p2)
	{
		XCALL(0x00712710);
	};

	//.text:00712710 ; public: void __thiscall oCItem::SetFlag(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetFlag(zINT p1)
	{
		XCALL(0x00712710);
	};

	//.text:00711270 ; public: static void __cdecl oCItem::SetLightingSwell(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	static void SetLightingSwell(zINT p1)
	{
		XCALL(0x00711270);
	};

	//.text:00711910 ; public: virtual void __thiscall oCItem::SetVisual(class zCVisual *)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual zINT SetVisual(zCVisual* p1)
	{
		XCALL(0x00711910);
	};

	//.text:00712BA0 ; public: class oCItem * __thiscall oCItem::SplitItem(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem* SplitItem(zINT p1)
	{
		XCALL(0x00712BA0);
	};

	//.text:00712610 ; public: zINT __thiscall oCItem::SplitSlot(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT SplitSlot(void)
	{
		XCALL(0x00712610);
	};

	//.text:00712730 ; public: zINT __thiscall oCItem::TwoHanded(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT TwoHanded(void)
	{
		XCALL(0x00712730);
	};

	//.text:00712A30 ; public: void __thiscall oCItem::UseItem(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void UseItem(void)
	{
		XCALL(0x00712A30);
	};

	//.text:007115D0 ; public: __thiscall oCItem::oCItem(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem(zINT p1, zINT p2)
	{
		XCALL(0x007115D0);
	};

	//.text:00711290 ; public: __thiscall oCItem::oCItem(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem(void)
	{
		XCALL(0x00711290);
	};

	//.text:00711470 ; public: __thiscall oCItem::oCItem(class zSTRING &, zINT)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem(zSTRING & p1, zINT p2)
	{
		XCALL(0x00711470);
	};
};

/** Insert description. */
class oCItemContainer
{
protected:
	int		_vtbl;
public:
	void*	contents;
	oCNpc*	npc;
	zSTRING titleText;
	int		invMode;
	int		selectedItem;
	int		offset;
	int		maxSlotsCol;
	int		imaxSlotsColScr;
	int		maxSlotsRow;
	int		maxSlotsRowScr;
	int		maxSlots;
	int     marginTop;
	int     marginLeft;
	zBOOL   frame;
	zBOOL   right;
	zBOOL   ownList;
	zBOOL   prepared;
	zBOOL   passive;
	int     TransferCount;
	zCView* viewTitle;
	zCView* viewBack;
	zCView* viewItem;
	zCView* viewItemActive;
	zCView* viewItemHightlighted;
	zCView* viewItemActiveHighlighted;
	zCView* viewItemInfo;
	zCView* viewItemInfoItem;
	zCView* textView;
	zCView* viewArrowAtTop;
	zCView* viewArrowAtBottom;
	zCWorld*rndWorld;
	int     posx;
	int     posy;
	zBOOL   m_bManipulateItemsDisabled;
	zBOOL   m_bCanTransferMoreThanOneItem;

public:
	//.text:00709230 ; public: virtual void __thiscall oCItemContainer::Activate(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual void Activate(void)
	{
		XCALL(0x00709230);
	};

	//.text:007050F0 ; public: virtual zINT __thiscall oCItemContainer::CanManipulateItems(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual zINT CanManipulateItems(void)
	{
		XCALL(0x007050F0);
	};

	//.text:00705120 ; public: virtual zINT __thiscall oCItemContainer::CanTransferMoreThanOneItem(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual zINT CanTransferMoreThanOneItem(void)
	{
		XCALL(0x00705120);
	};

	//.text:00708F30 ; public: virtual void __thiscall oCItemContainer::Close(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual void Close(void)
	{
		XCALL(0x00708F30);
	};

	//.text:00704B90 ; public: static void __cdecl oCItemContainer::Container_Draw(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	static void Container_Draw(void)
	{
		XCALL(0x00704B90);
	};

	//.text:00704B80 ; public: static void __cdecl oCItemContainer::Container_PrepareDraw(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	static void Container_PrepareDraw(void)
	{
		XCALL(0x00704B80);
	};

	//.text:00704AA0 ; public: static class oCItem * __cdecl oCItemContainer::CreateCurrencyItem(short)
	/** Insert description. 
	* @usable Ingame only
	*/
	static oCItem* CreateCurrencyItem(int pA)
	{
		XCALL(0x00704AA0);
	};

	//.text:00709290 ; public: virtual void __thiscall oCItemContainer::Deactivate(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual void Deactivate(void)
	{
		XCALL(0x00709290);
	};

	//.text:00705100 ; public: virtual void __thiscall oCItemContainer::DisableTransferMoreThanOneItem(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void DisableTransferMoreThanOneItem(int pA)
	{
		XCALL(0x00705100);
	};

	//.text:00708540 ; public: virtual class zCListSort<class oCItem> * __thiscall oCItemContainer::GetContents(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	/*
	virtual zCListSort<class oCItem>* GetContents(void)
	{
		XCALL(0x00708540);
	};
	*/

	//.text:00704A00 ; public: static zINT __cdecl oCItemContainer::GetCurrencyInstance(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	static zINT GetCurrencyInstance(void)
	{
		XCALL(0x00704A00);
	};

	//.text:00704810 ; public: static class zSTRING __cdecl oCItemContainer::GetCurrencyInstanceName(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	static zSTRING & GetCurrencyInstanceName(void)
	{
		XCALL(0x00704810);
	};

	//.text:00704610 ; public: static short __cdecl oCItemContainer::GetInvMaxColumns(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	static short GetInvMaxColumns(void)
	{
		XCALL(0x00704610);
	};

	//.text:00704660 ; public: static short __cdecl oCItemContainer::GetInvMaxRows(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	static short GetInvMaxRows(void)
	{
		XCALL(0x00704660);
	};

	//.text:007045E0 ; public: static zINT __cdecl oCItemContainer::GetInvSplitScreen(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	static zINT GetInvSplitScreen(void)
	{
		XCALL(0x007045E0);
	};

	//.text:007050A0 ; public: virtual zINT __thiscall oCItemContainer::GetMode(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT GetMode(void)
	{
		XCALL(0x007050A0);
	};

	//.text:00704F10 ; public: virtual class zSTRING __thiscall oCItemContainer::GetName(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual zSTRING GetName(void)
	{
		XCALL(0x00704F10);
	};

	//.text:007092C0 ; public: virtual class oCItem * __thiscall oCItemContainer::GetSelectedItem(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual oCItem* GetSelectedItem(void)
	{
		XCALL(0x007092C0);
	};

	//.text:007092F0 ; public: virtual zINT __thiscall oCItemContainer::GetSelectedItemCount(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual zINT GetSelectedItemCount(void)
	{
		XCALL(0x007092F0);
	};

	//.text:00706A70 ; public: virtual void __thiscall oCItemContainer::GetSize(zINT &, zINT &)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual void GetSize(zINT & p1, zINT & p2)
	{
		XCALL(0x00706A70);
	};

	//.text:00705130 ; public: virtual short __thiscall oCItemContainer::GetTransferCount(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual short GetTransferCount(void)
	{
		XCALL(0x00705130);
	};

	//.text:007046F0 ; public: static zFLOAT __cdecl oCItemContainer::GetValueMultiplier(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	static zFLOAT GetValueMultiplier(void)
	{
		XCALL(0x007046F0);
	};

	//.text:00705150 ; public: virtual void __thiscall oCItemContainer::IncTransferCount(short)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual void IncTransferCount(int p1)
	{
		XCALL(0x00705150);
	};

	//.text:00709360 ; public: virtual class oCItem * __thiscall oCItemContainer::Insert(class oCItem *)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual oCItem* Insert(oCItem* p1)
	{
		XCALL(0x00709360);
	};

	//.text:007050D0 ; public: virtual zINT __thiscall oCItemContainer::IsActive(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual zINT IsActive(void)
	{
		XCALL(0x007050D0);
	};

	//.text:00709E10 ; public: virtual zINT __thiscall oCItemContainer::IsEmpty(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual zINT IsEmpty(void)
	{
		XCALL(0x00709E10);
	};

	//.text:00709200 ; public: virtual zINT __thiscall oCItemContainer::IsOpen(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual zINT IsOpen(void)
	{
		XCALL(0x00709200);
	};

	//.text:00708F20 ; public: virtual zINT __thiscall oCItemContainer::IsPassive(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual zINT IsPassive(void)
	{
		XCALL(0x00708F20);
	};

	//.text:00709E40 ; public: virtual zINT __thiscall oCItemContainer::IsSplitScreen(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual zINT IsSplitScreen(void)
	{
		XCALL(0x00709E40);
	};

	//.text:00708550 ; public: virtual void __thiscall oCItemContainer::Open(zINT, zINT, zINT)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual void Open(zINT p1, zINT p2, zINT p3)
	{
		XCALL(0x00709E40);
	};

	//.text:007086D0 ; public: virtual void __thiscall oCItemContainer::OpenPassive(zINT, zINT, zINT)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual void OpenPassive(zINT p1, zINT p2, zINT p3)
	{
		XCALL(0x007086D0);
	};

	//.text:00709430 ; public: virtual void __thiscall oCItemContainer::Remove(class oCItem *)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual void Remove(oCItem* p1)
	{
		XCALL(0x00709430);
	};

	//.text:007094E0 ; public: virtual class oCItem * __thiscall oCItemContainer::Remove(class oCItem *, zINT)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual void Remove(oCItem* p1, zINT p2)
	{
		XCALL(0x007094E0);
	};

	//.text:007094D0 ; public: virtual class oCItem * __thiscall oCItemContainer::RemoveByPtr(class oCItem *, zINT)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual void RemoveByPtr(oCItem* p1, zINT p2)
	{
		XCALL(0x007094D0);
	};

	//.text:00704B50 ; public: static void __cdecl oCItemContainer::RemoveCurrencyItem(class oCItem *)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual void RemoveByPtr(oCItem* p1)
	{
		XCALL(0x00704B50);
	};

	//.text:007084F0 ; public: virtual void __thiscall oCItemContainer::SetContents(class zCListSort<class oCItem> *)
	/** Insert description. 
	* @usable Ingame only
	*/
	/*
	void SetContents(zCListSort<class oCItem> * p1)
	{
		XCALL(0x007084F0);
	};
	*/

	//.text:007050B0 ; public: virtual void __thiscall oCItemContainer::SetMode(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual void SetMode(int p1)
	{
		XCALL(0x007050B0);
	};

	//.text:00704F60 ; public: virtual void __thiscall oCItemContainer::SetName(class zSTRING &)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual void SetName(zSTRING & p1)
	{
		XCALL(0x00704F60);
	};

	//.text:00705140 ; public: virtual void __thiscall oCItemContainer::SetTransferCount(short)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetTransferCount(int p1)
	{
		XCALL(0x00705140);
	};

	//.text:007046B0 ; public: static short __cdecl oCItemContainer::TransferCountToAmount(short)
	/** Insert description. 
	* @usable Ingame only
	*/
	static short  TransferCountToAmount(int p1)
	{
		XCALL(0x007046B0);
	};

	//.text:00709F40 ; zINT __thiscall oCItemContainer__TransferItem(void **, zINT, zINT)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT TransferItem(void ** p1, zINT p2, zINT p3)
	{
		XCALL(0x00709F40);
	};

	//.text:00704D00 ; public: __thiscall oCItemContainer::oCItemContainer(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItemContainer(void)
	{
		XCALL(0x00704D00);
	};
};

#undef __G2EXT_API_HEADER

#endif // __API_G2_OCITEM_H__