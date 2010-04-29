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

#ifndef __API_G2_ZCVOB_H__
#define __API_G2_ZCVOB_H__

#define __G2EXT_API_HEADER

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"

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
	//.text:0061B910 ; public: float __thiscall zCVob::GetDistanceToVob(class zCVob &)
	/** Insert description. 
	* @usable Ingame only
	*/
	float GetDistanceToVob(zCVob & pA)
	{
		XCALL(0x0061B910);
	};

	//.text:0061B970 ; public: float __thiscall zCVob::GetDistanceToVobApprox(class zCVob &)
	/** Insert description. 
	* @usable Ingame only
	*/
	float GetDistanceToVobApprox(zCVob & pA)
	{
		XCALL(0x0061B970);
	};

	//.text:0061B8C0 ; public: void __thiscall zCVob::GetPositionLocal(float pA &, float pA &, float pA &)const
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetPositionLocal(float & pA, float & pB, float & pC)
	{
		XCALL(0x0061B8C0);
	};

	//.text:0061B890 ; public: void __thiscall zCVob::GetPositionWorld(float pA &, float pA &, float pA &)const
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetPositionWorld(float & pA, float & pB, float & pC)
	{
		XCALL(0x0061B890);
	};

	//.text:0052DC90 ; public: class zVEC3 __thiscall zCVob::GetPositionWorld(void)const
	/** Insert description. 
	* @usable Ingame only
	*/
	zVEC3 GetPositionWorld(void)
	{
		XCALL(0x0052DC90);
	};

	//.text:006CFFD0 ; public: enum  zTVobType __thiscall zCVob::GetVobType(void)const
	/** Insert description. 
	* @usable Ingame only
	*/
	zTVobType GetVobType(void)
	{
		XCALL(0x006CFFD0);
	};

	//.text:0061B2E0 ; int __stdcall zCVob__Move(float pA, float pA, float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	int __stdcall Move(float pA, float pB, float pC)
	{
		XCALL(0x0061B2E0);
	};

	//.text:0061B3C0 ; int __stdcall zCVob__MoveLocal(float pA, float pA, float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	int __stdcall MoveLocal(float pA, float pB, float pC)
	{
		XCALL(0x0061B3C0);
	};

	//.text:0061B350 ; public: void __thiscall zCVob::MoveWorld(float pA, float pA, float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	void MoveWorld(float pA, float pB, float pC)
	{
		XCALL(0x0061B350);
	};

	//.text:0061C090 ; public: void __thiscall zCVob::ResetXZRotationsWorld(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void ResetXZRotationsWorld(void)
	{
		XCALL(0x0061C090);
	};

	//.text:0061BE20 ; public: void __thiscall zCVob::ResetXZRotationsLocal(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void ResetXZRotationsLocal(void)
	{
		XCALL(0x0061BE20);
	};

	//.text:0061B6B0 ; int __stdcall zCVob__RotateLocalX(float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	int __stdcall RotateLocalX(float pA)
	{
		XCALL(0x0061B6B0);
	};

	//.text:0061B610 ; int __stdcall zCVob__RotateLocal(int, float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	int __stdcall RotateLocal(int pA, float pB)
	{
		XCALL(0x0061B610);
	};

	//.text:0061B720 ; int __stdcall zCVob__RotateLocalY(float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	int __stdcall RotateLocalY(float pA)
	{
		XCALL(0x0061B720);
	};

	//.text:0061B790 ; int __stdcall zCVob__RotateLocalZ(float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	int __stdcall RotateLocalZ(float pA)
	{
		XCALL(0x0061B790);
	};

	//.text:0061B520 ; int __stdcall zCVob__RotateWorld(int, float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	int __stdcall RotateWorld(int, float pA)
	{
		XCALL(0x0061B520);
	};

	//.text:0061B800 ; int __stdcall zCVob__RotateWorldX(float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	int __stdcall RotateWorldX(float pA)
	{
		XCALL(0x0061B800);
	};

	//.text:0061B830 ; int __stdcall zCVob__RotateWorldY(float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	int __stdcall RotateWorldY(float pA)
	{
		XCALL(0x0061B830);
	};

	//.text:0061B860 ; int __stdcall zCVob__RotateWorldZ(float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	int __stdcall RotateWorldZ(float pA)
	{
		XCALL(0x0061B860);
	};

	//.text:006D0000 ; public: void __thiscall zCVob::SetCollDet(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetCollDet(int enabled)
	{
		XCALL(0x0061B860);
	};

	//.text:0061CF40 ; public: void __fastcall zCVob::SetCollDetDyn(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void __fastcall SetCollDetDyn(int enabled)
	{
		XCALL(0x0061B860);
	};

	//.text:0061CE50 ; public: void __fastcall zCVob::SetCollDetStat(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void __fastcall SetCollDetStat(int enabled)
	{
		XCALL(0x0061B860);
	};

	//.text:0061BBD0 ; public: void __thiscall zCVob::SetTrafo(zMAT4 & pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetTrafo(zMAT4 & pA)
	{
		XCALL(0x0061BBD0);
	};

	//.text:0061BC80 ; public: void __thiscall zCVob::SetTrafoObjToWorld(zMAT4 & pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetTrafoObjToWorld(zMAT4 & pA)
	{
		XCALL(0x0061BC80);
	};

	//.text:0061B0C0 ; public: void __thiscall zCVob::SetNewTrafoObjToWorld(zMAT4 & pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetNewTrafoObjToWorld(zMAT4 & pA)
	{
		XCALL(0x0061B0C0);
	};

	//.text:0061C280 ; int __stdcall zCVob__SetHeadingYWorld(float pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	void __stdcall SetHeadingYWorld(float pA)
	{
		XCALL(0x0061C280);
	};

	//.text:0061C450 ; public: void __thiscall zCVob::SetHeadingYWorld(class zCVob *)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetHeadingYWorld(zCVob * pA)
	{
		XCALL(0x0061C450);
	};

	//.text:0061C1B0 ; public: void __thiscall zCVob::SetHeadingYLocal(zVEC3 & pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetHeadingYLocal(zVEC3 & pA)
	{
		XCALL(0x0061C1B0);
	};

	//.text:0061C6B0 ; public: void __thiscall zCVob::SetHeadingWorld(zVEC3 & pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetHeadingWorld(zVEC3 & pA)
	{
		XCALL(0x0061C6B0);
	};

	//.text:0061C780 ; public: void __thiscall zCVob::SetHeadingWorld(class zCVob *)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetHeadingWorld(zCVob* pA)
	{
		XCALL(0x0061C780);
	};

	//.text:0061C5E0 ; public: void __thiscall zCVob::SetHeadingLocal(zVEC3 & pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetHeadingLocal(zVEC3 & pA)
	{
		XCALL(0x0061C5E0);
	};

	//.text:0061CBC0 ; public: void __thiscall zCVob::SetHeadingAtWorld(zVEC3 & pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetHeadingAtWorld(zVEC3 & pA)
	{
		XCALL(0x0061CBC0);
	};

	//.text:0061C860 ; public: void __thiscall zCVob::SetHeadingAtLocal(zVEC3 & pA)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetHeadingAtLocal(zVEC3 & pA)
	{
		XCALL(0x0061C860);
	};

	//.text:004042B0 ; public: virtual int __thiscall zCVob::GetScriptInstance(class zSTRING * &, int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual int GetScriptInstance(zSTRING * & pA, int & pB)
	{
		XCALL(0x004042B0);
	};

	//.text:005FFDD0 ; public: void __thiscall zCVob::SetVobName(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetVobName(const zSTRING & pA)
	{
		XCALL(0x005FFDD0);
	};

	//.text:005FE950 ; public: class zSTRING const & __thiscall zCVob::GetVobPresetName(void)const
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING & GetVobPresetName(void)
	{
		XCALL(0x005FE950);
	};

	//.text:00616B20 ; public: class zCVisual * __thiscall zCVob::GetVisual(void)const
	/** Insert description. 
	* @usable Ingame only
	*/
	zCVisual* GetVisual(void)
	{
		XCALL(0x00616B20);
	};

	//.text:006CFFE0 ; public: void __thiscall zCVob::SetDrawBBox3D(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetDrawBBox3D(int pA)
	{
		XCALL(0x006CFFE0);
	};

	//.text:006742A0 ; public: class zCWorld * __thiscall zCVob::GetHomeWorld(void)const
	/** Insert description. 
	* @usable Ingame only
	*/
	zCWorld* GetHomeWorld(void)
	{
		XCALL(0x006742A0);
	};

	//.text:006024F0 ; public: virtual void __thiscall zCVob::SetVisual(class zCVisual *)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetVisual(zCVisual* pA)
	{
		XCALL(0x006024F0);
	};

	//.text:00602680 ; public: virtual void __thiscall zCVob::SetVisual(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetVisual(const zSTRING & pA)
	{
		XCALL(0x00602680);
	};

	//.text:0061BB70 ; public: void __thiscall zCVob::SetPositionWorld(class zVEC3 const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetPositionWorld(const zVEC3 & pA)
	{
		XCALL(0x0061BB70);
	};

	//.text:0061D890 ; public: int __thiscall zCVob::DetectCollision(class zMAT4 *)
	/** Insert description. 
	* @usable Ingame only
	*/
	int DetectCollision(zMAT4 * pA)
	{
		XCALL(0x0061D890);
	};
};

#undef __G2EXT_API_HEADER

#endif  //__API_G2_ZCVOB_H__