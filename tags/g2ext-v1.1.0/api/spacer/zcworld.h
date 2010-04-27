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

#ifndef __API_SPACER_ZCWORLD_H__
#define __API_SPACER_ZCWORLD_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifndef _G2EXT_COMPILE_SPACER
#error Cannot use spacer headers on non spacer dll (_G2EXT_COMPILE_SPACER not defined)
#endif

#include "api/spacer/ztypes.h"
#include "api/spacer/macros.h"

#include "api/spacer/zcbsptree.h"

class zCVob;
class zCVertex;
class zCCSPlayer;
class zCWayNet;
class zCWorldPerFrameCallback;
class zCSkyControler;
class zCZone;
class zCSession;
class zCViewProgressBar;

#define zCWorld_DIMENSION 3
#define VOB_HASHTABLE_SIZE 2048

enum zTWorldLoadMode         
{   
	zWLD_LOAD_GAME_STARTUP,         
	zWLD_LOAD_GAME_SAVED_DYN,       
	zWLD_LOAD_GAME_SAVED_STAT,      
	zWLD_LOAD_EDITOR_COMPILED,      
	zWLD_LOAD_EDITOR_UNCOMPILED,    
	zWLD_LOAD_MERGE 
};

enum zTWorldSaveMode         
{   
	zWLD_SAVE_GAME_SAVED_DYN,       
	zWLD_SAVE_EDITOR_COMPILED,      
	zWLD_SAVE_EDITOR_UNCOMPILED,    
	zWLD_SAVE_COMPILED_ONLY         
};

enum zTWorldLoadMergeMode    
{   
	zWLD_LOAD_MERGE_ADD,                    
	zWLD_LOAD_MERGE_REPLACE_ROOT_VISUAL 
};

enum zTStaticWorldLightMode 
{   
	zWLD_LIGHT_VERTLIGHT_ONLY,
	zWLD_LIGHT_VERTLIGHT_LIGHTMAPS_LOW_QUAL,
	zWLD_LIGHT_VERTLIGHT_LIGHTMAPS_MID_QUAL,
	zWLD_LIGHT_VERTLIGHT_LIGHTMAPS_HI_QUAL
};

/** Insert description. */
class zCWorld : public zCObject
{
private:
	zCTree<zCVob>			globalVobTree;

	int						foundHit;
	zCVob*					foundVob;  
	zCPolygon*				foundPoly;
	zVEC3					foundIntersection;
	zVEC3					foundPolyNormal;   
	zCVertex*				foundVertex;
	zCSession*				ownerSession;
	zCCSPlayer*				csPlayer;

	zSTRING					m_strlevelName;              
	int						compiled;
	int						compiledEditorMode;
	int						traceRayIgnoreVobFlag;              
	int						m_bIsInventoryWorld;        
	zTWld_RenderMode		worldRenderMode;
	zCWayNet*				wayNet;
	zTFrameCtr				masterFrameCtr;        
	float					vobFarClipZ;              
	float					vobFarClipZScalability;

	zCArray<zCVob*>			traceRayVobList;
	zCArray<zCVob*>			traceRayTempIgnoreVobList;

	int						renderingFirstTime;
	int						showWaynet;       
	int						showTraceRayLines;        
	zCViewProgressBar*  	progressBar;
	DWORD					unarchiveFileLen;
	DWORD					unarchiveStartPosVobtree;
	int						numVobsInWorld;

	zCArray<zCWorldPerFrameCallback*> perFrameCallbackList;

	zCSkyControler*			skyControlerIndoor;
	zCSkyControler*			skyControlerOutdoor;
	zCSkyControler*			activeSkyControler;

	zCArray<zCZone*>		zoneGlobalList;
	zCArraySort<zCZone*>	zoneActiveList;
	zCArraySort<zCZone*>	zoneLastClassList;

	//zCVobBBox3DSorter<zCZone> zoneBoxSorter
	/*0x0118*/          int zoneBoxSorter_vtbl;     // Method table
	//zCArray<zTBoxSortHandle *>        handles;
	/*0x011C*/          int zoneBoxSorter_handles_array;         //zTBoxSortHandle**
	/*0x0120*/          int zoneBoxSorter_handles_numAlloc;      //int
	/*0x0124*/          int zoneBoxSorter_handles_numInArray;    //int
	//zCArraySort<zTNode*> nodeList[zCWorld_DIMENSION];
	//0
	/*0x0128*/          int zoneBoxSorter_nodeList0_array;         //zTNode**
	/*0x012C*/          int zoneBoxSorter_nodeList0_numAlloc;      //int             
	/*0x0130*/          int zoneBoxSorter_nodeList0_numInArray;    //int             
	/*0x0134*/          int zoneBoxSorter_nodeList0_compare;       //int    (*Compare)(const void* ele1,const void* ele2)
	//1                                                
	/*0x0138*/          int zoneBoxSorter_nodeList1_array;         //zTNode**
	/*0x013C*/          int zoneBoxSorter_nodeList1_numAlloc;      //int             
	/*0x0140*/          int zoneBoxSorter_nodeList1_numInArray;    //int             
	/*0x0144*/          int zoneBoxSorter_nodeList1_compare;       //int    (*Compare)(const void* ele1,const void* ele2)
	//2                                                
	/*0x0148*/          int zoneBoxSorter_nodeList2_array;         //zTNode**
	/*0x014C*/          int zoneBoxSorter_nodeList2_numAlloc;      //int             
	/*0x0150*/          int zoneBoxSorter_nodeList2_numInArray;    //int             
	/*0x0154*/          int zoneBoxSorter_nodeList2_compare;       //int    (*Compare)(const void* ele1,const void* ele2)
	/*0x0158*/          int zoneBoxSorter_sorted;                  //zBOOL

	//zCVobBBox3DSorter<zCZone>::zTBoxSortHandle    zoneActiveHandle;
	/*0x015C*/			int zoneActiveHandle_vtbl;                  //Pointer to method table
	/*0x0160*/			int zoneActiveHandle_mySorter;              //zCBBox3DSorterBase*
	zTBBox3D bbox3D;

	/*0x017C*/			int zoneActiveHandle_indexBegin [zCWorld_DIMENSION]; //int
	/*0x0188*/			int zoneActiveHandle_indexEnd   [zCWorld_DIMENSION]; //int

	//zCArray<VOB*> activeList;
	/*0x0194*/				int zoneActiveHandle_activeList_array;         //VOB **
	/*0x0198*/				int zoneActiveHandle_activeList_numAlloc;      //int             
	/*0x019C*/				int zoneActiveHandle_activeList_numInArray;    //int             

	int						addZonesToWorld;
	int						showZonesDebugInfo;

	zCCBspTree*				cbspTree;
	zCBspTree				bspTree;

	zCArray<zCVob*>			activeVobList;
	zCArray<zCVob*>			walkList;
	zCArray<zCVob*>			vobHashTable[VOB_HASHTABLE_SIZE];

	zSTRING					worldFilename;
	zSTRING					worldName;

	zCListSort<zCVob>*		voblist;
	zCListSort<oCNpc>*		voblist_npcs;
	zCListSort<oCItem>*		voblist_items;

public:
	//.text:007AF6A0 ; public: class zCTree<class zCVob> * __thiscall zCWorld::AddVob(class zCVob *)
	/** Insert description. 
	* @usable Ingame only
	*/
	zCTree<zCVob>* AddVob(zCVob* pA) 
	{ 
		XCALL(0x007AF6A0) 
	};

	//.text:007AFA00 ; public: virtual void __thiscall oCWorld::RemoveVob(class zCVob *)
	/** Insert description. 
	* @usable Ingame only
	*/
	void RemoveVob(zCVob* pA) 
	{ 
		XCALL(0x007AFA00) 
	};

	//.text:007AEF80 ; public: virtual void __thiscall oCWorld::SearchVobListByName(class zSTRING const &, class zCArray<class zCVob *> &)
	/** Insert description.
	* @usable Ingame only.
	*/
	void SearchVobListByName(const zSTRING& name, zCArray<zCVob*>& resultList)
	{
		XCALL(0x007AEF80);
	};
};

#undef __G2EXT_API_HEADER

#endif // __API_SPACER_ZCWORLD_H__