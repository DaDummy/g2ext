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

#ifndef __API_SPACER_OCITEM_H__
#define __API_SPACER_OCITEM_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifndef _G2EXT_COMPILE_SPACER
#error Cannot use spacer headers on non spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/spacer/ztypes.h"
#include "api/spacer/macros.h"
#include "api/spacer/zcobject.h"
#include "api/spacer/ocvob.h"
#include "api/spacer/zcvob.h"

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
	//.text:0056BF80 ; public: void __thiscall oCItem::CopyDamage(class oCItem *)
	/** Insert description. 
	* @usable Ingame only
	*/
	void CopyDamage(oCItem* p1)
	{
		XCALL(0x0056BF80);
	};

	//.text:0056BD80 ; public: zINT __thiscall oCItem::GetCount(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT GetCount(zINT p1)
	{
		XCALL(0x0056BD80);
	};

	//.text:0056C140 ; public: unsigned long __thiscall oCItem::GetDamageTypes(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zDWORD GetDamageTypes(void)
	{
		XCALL(0x0056C140);
	};

	//.text:0056BD00 ; public: class zSTRING & __thiscall oCItem::GetDescription(void)
	/** This method returns the description text of the item.
	* @return Description text.
	* @usable Ingame only
	*/
	zSTRING& GetDescription(void)
	{	
		XCALL(0x0056BD00);
	};

	//.text:0056C400 ; public: zINT __thiscall oCItem::GetDisguiseGuild(void)
	/** This method returns the disguise guild of the item.
	* @return Disguise guild. 
	* @usable Ingame only
	*/
	zINT GetDisguiseGuild(void)
	{
		XCALL(0x0056C400);
	};

	//.text:0056C120 ; public: zINT __thiscall oCItem::GetFullDamage(void)
	/** This method returns the full damage of the item.
	* @return Full damage. 
	* @usable Ingame only
	*/
	zINT GetFullDamage(void)
	{
		XCALL(0x0056C120);
	};

	//.text:0056BF60 ; public: zINT __thiscall oCItem::GetFullProtection(void)
	/** This method returns the full protection of the item.
	* @return Full protection. 
	* @usable Ingame only
	*/
	zINT GetFullProtection(void)
	{
		XCALL(0x0056BF60);
	};

	//.text:0056B040 ; public: virtual zINT __thiscall oCItem::GetInstance(void)
	/** This method returns the instance of the item.
	* @return Item instance. 
	* @usable Ingame only
	*/
	zINT GetInstance(void)
	{
		XCALL(0x0056B040);
	};

	//.text:0056D950 ; public: virtual class zSTRING __thiscall oCItem::GetInstanceName(void)
	/** This method returns the instance name of the item.
	* @return Item instance name. 
	* @usable Ingame only
	*/
	zSTRING GetInstanceName(void)
	{
		XCALL(0x0056D950);
	};

	//.text:0056C4A0 ; public: class zSTRING __thiscall oCItem::GetName(int)
	/** This method returns the instance name of the item.
	* @param  Item instance.
	* @return Item instance name. 
	* @usable Ingame only
	*/
	zSTRING GetName(zINT instance)
	{
		XCALL(0x0056C4A0);
	};

	//.text:004418C0 ; public: class zSTRING __thiscall oCItem::GetSchemeName(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING GetSchemeName(void)
	{
		XCALL(0x004418C0);
	};

	//.text:0056D8E0 ; public: virtual zINT __thiscall oCItem::GetScriptInstance(class zSTRING &, zINT &)
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING GetScriptInstance(zSTRING & p1, zINT p2)
	{
		XCALL(0x0056D8E0);
	};

	//.text:0056C7A0 ; public: zINT __thiscall oCItem::GetStateEffectFunc(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT GetStateEffectFunc(zINT p1)
	{
		XCALL(0x0056C7A0);
	};
	//.text:0056BD10 ; public: class zSTRING & __thiscall oCItem::GetText(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING & GetText(zINT p1)
	{
		XCALL(0x0056BD10);
	};

	//.text:0056C270 ; public: zINT __thiscall oCItem::GetValue(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT GetValue(void)
	{
		XCALL(0x0056C270);
	};

	//.text:0056C660 ; public: class zSTRING __thiscall oCItem::GetVisualChange(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING GetVisualChange(void)
	{
		XCALL(0x0056C660);
	};

	//.text:0056B590 ; public: virtual void __thiscall oCItem::Init(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Init(void)
	{
		XCALL(0x0056B590);
	};

	//.text:0056C3E0 ; public: virtual zINT __thiscall oCItem::IsOwnedByGuild(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT IsOwnedByGuild(zINT p1)
	{
		XCALL(0x0056C3E0);
	};

	//.text:0056C3C0 ; public: virtual zINT __thiscall oCItem::IsOwnedByNpc(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT IsOwnedByNpc(zINT p1)
	{
		XCALL(0x0056C3C0);
	};

	//.text:0056C1C0 ; public: zINT __thiscall oCItem::MultiSlot(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT MultiSlot(void)
	{
		XCALL(0x0056C1C0);
	};

	//.text:0056C820 ; public: void __thiscall oCItem::RemoveEffect(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void RemoveEffect(void)
	{
		XCALL(0x0056C820);
	};

	// -- .text:00712F10 ; zINT __stdcall oCItem__RotateForInventory(float)
	/** Insert description. 
	* @usable Ingame only
	*/
	void RotateForInventory(zFLOAT p1)
	{
		XCALL(0x00712F10);
	};

	//.text:0056CB30 ; public: void __thiscall oCItem::RotateInInventory(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void RotateInInventory(void)
	{
		XCALL(0x0056CB30);
	};

	//.text:0056D910 ; public: virtual zINT __thiscall oCItem::SetByScriptInstance(class zSTRING const *, zINT)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual zINT SetByScriptInstance(const zSTRING* p1, zINT p2)
	{
		XCALL(0x0056D910);
	};

	//.text:0056C330 ; public: void __thiscall oCItem::SetFlag(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetFlag(zINT p1)
	{
		XCALL(0x0056C330);
	};

	//.text:0056AE90 ; public: static void __cdecl oCItem::SetLightingSwell(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	static void SetLightingSwell(zINT p1)
	{
		XCALL(0x0056AE90);
	};

	//.text:0056B530 ; public: virtual void __thiscall oCItem::SetVisual(class zCVisual *)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual zINT SetVisual(zCVisual* p1)
	{
		XCALL(0x0056B530);
	};

	//.text:0056C7C0 ; public: class oCItem * __thiscall oCItem::SplitItem(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem* SplitItem(zINT p1)
	{
		XCALL(0x0056C7C0);
	};

	//.text:0056C230 ; public: zINT __thiscall oCItem::SplitSlot(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT SplitSlot(void)
	{
		XCALL(0x0056C230);
	};

	//.text:0056AEB0 ; public: __thiscall oCItem::oCItem(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem(void)
	{
		XCALL(0x0056AEB0);
	};

	//.text:0056B090 ; public: __thiscall oCItem::oCItem(class zSTRING &, zINT)
	/** Insert description. 
	* @usable Ingame only
	*/
	oCItem(zSTRING & p1, zINT p2)
	{
		XCALL(0x0056B090);
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
};

#undef __G2EXT_API_HEADER

#endif // __API_G2_OCITEM_H__