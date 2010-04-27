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

#ifndef __API_SPACER_ZCVOB_H__
#define __API_SPACER_ZCVOB_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifndef _G2EXT_COMPILE_SPACER
#error Cannot use spacer headers on non spacer dll (_G2EXT_COMPILE_SPACER not defined)
#endif

#include "api/spacer/ztypes.h"
#include "api/spacer/macros.h"

class zCWorld;
class zCVisual;

/** Insert description. */
enum zTVobType 
{	
	VOB_TYPE_VOB,
	VOB_TYPE_MOB	= 128,
	VOB_TYPE_ITEM	= 129,
	VOB_TYPE_NPC	= 130
};

/** Insert description. */
class zCVob : public zCObject
{	
public:
	int				globalVobTreeNode;         // 0x0024 zCTree<zCVob>*
	int				lastTimeDrawn;             // 0x0028 zTFrameCtr
	DWORD			lastTimeCollected;         // 0x002C zDWORD
	zCArray<void*>	vobLeafList;
	zMAT4			trafoObjToWorld;
	zTBBox3D		bbox3D;
	zTBSphere3D		bsphere3D;
	zCArray<zCVob*> touchVobList;
	int				type;                      // 0x00B0 zTVobType
	DWORD			groundShadowSizePacked;    // 0x00B4 zDWORD
	zCWorld*		homeWorld;                 // 0x00B8 zCWorld*
	void*			groundPoly;                // 0x00BC zCPolygon* // FIXME: TYPE
	void*			callback_ai;               // 0x00C0 zCAIBase* // FIXME: TYPE
	zMAT4*			trafo;                     // 0x00C4 zMATRIX4*
	zCVisual*		visual;                    // 0x00C8 zCVisual* // FIXME: TYPE
	float			visualAlpha;               // 0x00CC zREAL
	float			m_fVobFarClipZScale;       // 0x00D0 zREAL
	int				m_AniMode;                 // 0x00D4 zTAnimationMode
	float			m_aniModeStrength;         // 0x00D8 zREAL
	int				m_zBias;                   // 0x00DC int
	void*			rigidBody;                 // 0x00E0 zCRigidBody* // FIXME: TYPE
	zCOLOR			lightColorStat;            // 0x00E4 zCOLOR
	zCOLOR			lightColorDyn;             // 0x00E8 zCOLOR
	zVEC3			lightDirectionStat;		   // 0x00EC zVEC3
	zSTRING*		vobPresetName;             // 0x00F8 zSTRING*
	int				eventManager;              // 0x00FC zCEventManager* // FIXME: TYPE
	float			nextOnTimer;               // 0x0100 zREAL
	int				bitfield[5];               // 0x0104 zCVob_bitfieldX_Xxx
	void*			m_poCollisionObjectClass;  // 0x0118 zCCollisionObjectDef*
	void*			m_poCollisionObject;       // 0x011C zCCollisionObject*

public:
	//.text:007A67A0 ; public: float __thiscall zCVob::GetDistanceToVob(class zCVob &)
	/** Insert description. 
	* @usable Ingame only
	*/
	float GetDistanceToVob(zCVob & pA)
	{
		XCALL(0x007A67A0); // spacer
	};

	//.text:007A6800 ; public: float __thiscall zCVob::GetDistanceToVobApprox(class zCVob &)
	/** Insert description. 
	* @usable Ingame only
	*/
	float GetDistanceToVobApprox(zCVob & pA)
	{
		XCALL(0x007A6800); // spacer
	};

	//.text:007A6750 ; public: void __thiscall zCVob::GetPositionLocal(float pA &, float pA &, float pA &)const
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetPositionLocal(float & pA, float & pB, float & pC)
	{
		XCALL(0x007A6750); // spacer
	};

	//.text:007A6720 ; public: void __thiscall zCVob::GetPositionWorld(float pA &, float pA &, float pA &)const
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetPositionWorld(float & pA, float & pB, float & pC)
	{
		XCALL(0x007A6720); // spacer
	};

	//.text:004E72A0 ; public: class zVEC3 __thiscall zCVob::GetPositionWorld(void)const
	/** Insert description. 
	* @usable Ingame only
	*/
	zVEC3 GetPositionWorld(void)
	{
		XCALL(0x004E72A0); // spacer
	};

	//.text:0053A940 ; public: enum  zTVobType __thiscall zCVob::GetVobType(void)const
	/** Insert description. 
	* @usable Ingame only
	*/
	zTVobType GetVobType(void)
	{
		XCALL(0x0053A940); // spacer
	};

	//.text:007A6170 ; int __stdcall zCVob__Move(float pA, float pA, float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	int Move(float pA, float pB, float pC)
	{
		XCALL(0x007A6170); // spacer
	};

	//.text:007A6250 ; int __stdcall zCVob__MoveLocal(float pA, float pA, float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	int MoveLocal(float pA, float pB, float pC)
	{
		XCALL(0x007A6250); // spacer
	};

	//.text:007A61E0 ; public: void __thiscall zCVob::MoveWorld(float pA, float pA, float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	void MoveWorld(float pA, float pB, float pC)
	{
		XCALL(0x007A61E0); // spacer
	};

	//.text:007A6CB0 ; public: void __thiscall zCVob::ResetXZRotationsWorld(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void ResetXZRotationsWorld(void)
	{
		XCALL(0x007A6CB0); // spacer
	};

	//.text:007A6F20 ; public: void __thiscall zCVob::ResetXZRotationsLocal(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void ResetXZRotationsLocal(void)
	{
		XCALL(0x007A6F20); // spacer
	};

	//.text:007A6540 ; int __stdcall zCVob__RotateLocalX(float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	int RotateLocalX(float pA)
	{
		XCALL(0x007A6540); // spacer
	};

	//.text:007A64A0 ; int __stdcall zCVob__RotateLocal(int, float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	int RotateLocal(zVEC3& pA, float pB)
	{
		XCALL(0x007A64A0); // spacer
	};

	//.text:007A65B0 ; int __stdcall zCVob__RotateLocalY(float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	int RotateLocalY(float pA)
	{
		XCALL(0x007A65B0); // spacer
	};

	//.text:007A6620 ; int __stdcall zCVob__RotateLocalZ(float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	int RotateLocalZ(float pA)
	{
		XCALL(0x007A6620); // spacer
	};

	//.text:007A63B0 ; int __stdcall zCVob__RotateWorld(int, float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	int RotateWorld(zVEC3& pA, float pB)
	{
		XCALL(0x007A63B0); // spacer
	};

	//.text:007A6690 ; int __stdcall zCVob__RotateWorldX(float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	int RotateWorldX(float pA)
	{
		XCALL(0x007A6690); // spacer
	};

	//.text:007A66C0 ; int __stdcall zCVob__RotateWorldY(float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	int RotateWorldY(float pA)
	{
		XCALL(0x007A66C0); // spacer
	};

	//.text:007A66F0 ; int __stdcall zCVob__RotateWorldZ(float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	int RotateWorldZ(float pA)
	{
		XCALL(0x007A66F0); // spacer
	};

	//.text:0053A970 ; public: void __thiscall zCVob::SetCollDet(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetCollDet(int enabled)
	{
		XCALL(0x0053A970); // spacer
	};

	//.text:007A7DD0 ; public: void __fastcall zCVob::SetCollDetDyn(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void __fastcall SetCollDetDyn(int enabled)
	{
		XCALL(0x007A7DD0); // spacer
	};

	//.text:007A7CE0 ; public: void __fastcall zCVob::SetCollDetStat(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void __fastcall SetCollDetStat(int enabled)
	{
		XCALL(0x007A7CE0); // spacer
	};

	//.text:007A6A60 ; public: void __thiscall zCVob::SetTrafo(zMAT4 & pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetTrafo(zMAT4 & pA)
	{
		XCALL(0x007A6A60); // spacer
	};

	//.text:007A6B10 ; public: void __thiscall zCVob::SetTrafoObjToWorld(zMAT4 & pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetTrafoObjToWorld(zMAT4 & pA)
	{
		XCALL(0x007A6B10); // spacer
	};

	//.text:007A5F50 ; public: void __thiscall zCVob::SetNewTrafoObjToWorld(zMAT4 & pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetNewTrafoObjToWorld(zMAT4 & pA)
	{
		XCALL(0x007A5F50); // spacer
	};

	//.text:007A7110 ; int __stdcall zCVob__SetHeadingYWorld(float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetHeadingYWorld(zVEC3& pA)
	{
		XCALL(0x007A7110); // spacer
	};

	//.text:007A72E0 ; public: void __thiscall zCVob::SetHeadingYWorld(class zCVob *)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetHeadingYWorld(zCVob * pA)
	{
		XCALL(0x007A72E0); // spacer
	};

	//.text:007A7040 ; public: void __thiscall zCVob::SetHeadingYLocal(zVEC3 & pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetHeadingYLocal(zVEC3 & pA)
	{
		XCALL(0x007A7040); // spacer
	};

	//.text:007A7540 ; public: void __thiscall zCVob::SetHeadingWorld(zVEC3 & pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetHeadingWorld(zVEC3 & pA)
	{
		XCALL(0x007A7540); // spacer
	};

	//.text:007A7610 ; public: void __thiscall zCVob::SetHeadingWorld(class zCVob *)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetHeadingWorld(zCVob* pA)
	{
		XCALL(0x007A7610); // spacer
	};

	//.text:007A7470 ; public: void __thiscall zCVob::SetHeadingLocal(zVEC3 & pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetHeadingLocal(zVEC3 & pA)
	{
		XCALL(0x007A7470); // spacer
	};

	//.text:007A7A50 ; public: void __thiscall zCVob::SetHeadingAtWorld(zVEC3 & pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetHeadingAtWorld(zVEC3 & pA)
	{
		XCALL(0x007A7A50); // spacer
	};

	//.text:007A76F0 ; public: void __thiscall zCVob::SetHeadingAtLocal(zVEC3 & pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetHeadingAtLocal(zVEC3 & pA)
	{
		XCALL(0x007A76F0); // spacer
	};

	//.text:00486840 ; public: virtual int __thiscall zCVob::GetScriptInstance(class zSTRING * &, int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual int GetScriptInstance(zSTRING * & pA, int & pB)
	{
		XCALL(0x00486840); // spacer
	};

	//.text:0078ACF0 ; public: void __thiscall zCVob::SetVobName(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetVobName(const zSTRING & pA)
	{
		XCALL(0x0078ACF0); // spacer
	};

	//.text:007896E0 ; public: class zSTRING const & __thiscall zCVob::GetVobPresetName(void)const
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING & GetVobPresetName(void)
	{
		XCALL(0x007896E0); // spacer
	};

	//.text:007A1AE0 ; public: class zCVisual * __thiscall zCVob::GetVisual(void)const
	/** Insert description. 
	* @usable Ingame only
	*/
	zCVisual* GetVisual(void)
	{
		XCALL(0x007A1AE0); // spacer
	};

	//.text:0053A950 ; public: void __thiscall zCVob::SetDrawBBox3D(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetDrawBBox3D(int pA)
	{
		XCALL(0x0053A950); // spacer
	};

	//.text:004E7290 ; public: class zCWorld * __thiscall zCVob::GetHomeWorld(void)const
	/** Insert description. 
	* @usable Ingame only
	*/
	zCWorld* GetHomeWorld(void)
	{
		XCALL(0x004E7290);
	};

	//.text:0078D660 ; public: virtual void __thiscall zCVob::SetVisual(class zCVisual *)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetVisual(zCVisual* pA)
	{
		XCALL(0x0078D660);
	};

	//.text:0078D7F0 ; public: virtual void __thiscall zCVob::SetVisual(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetVisual(const zSTRING & pA)
	{
		XCALL(0x0078D7F0);
	};

	//.text:007A6A00 ; public: void __thiscall zCVob::SetPositionWorld(class zVEC3 const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetPositionWorld(const zVEC3 & pA)
	{
		XCALL(0x007A6A00);
	};

	//.text:007A8720 ; public: int __thiscall zCVob::DetectCollision(class zMAT4 *)
	/** Insert description. 
	* @usable Ingame only
	*/
	int DetectCollision(zMAT4 * pA)
	{
		XCALL(0x007A8720);
	};
};

#undef __G2EXT_API_HEADER

#endif  //__API_SPACER_ZCVOB_H__