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

#ifndef __API_G2_ZCCAMERA_H__
#define __API_G2_ZCCAMERA_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"

/** Insert description. */
class zCCamera
{	
public:
	//.text:0054B660 ; int __stdcall zCCamera__AddTremor(int, float, float, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void AddTremor(const zVEC3& pos, float radius, float time, const zVEC3& amplitude) 
	{
		XCALL(0x0054B660);
	};

	//.text:0054B200 ; int __stdcall zCCamera__SetFarClipZ(float)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetFarClipZ(float z)
	{
		XCALL(0x0054B200);
	};

	//.text:0054B960 ; public: void __thiscall zCCamera::GetCamPos(class zVEC3 &)const
	/** Insert description. 
	* @usable Ingame only
	*/
	void StopTremor(zVEC3& pos)
	{
		XCALL(0x0054B960);
	};

	//.text:0054BBC0 ; public: void __thiscall zCCamera::SetRenderScreenFade(struct zCOLOR)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetRenderScreenFade(zCOLOR col)
	{
		XCALL(0x0054BBC0);
	};

	//.text:0054BC20 ; public: void __thiscall zCCamera::SetRenderCinemaScope(struct zCOLOR)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetRenderCinemaScope(zCOLOR col)
	{
		XCALL(0x0054BC20);
	};

	//.text:0054B650 ; public: void __thiscall zCCamera::StopTremor(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void StopTremor(void)
	{
		XCALL(0x0054B650);
	};

	//.text:0054A6A0 ; public: class zMAT4 const & __thiscall zCCamera::GetTransform(enum  zTCamTrafoType)
	/** Insert description. 
	* @usable Ingame only
	*/
	//static zMAT4* GetMatrix(void)
	//{
	//	return (zMAT4*)((int)(*(zCCamera**)0x008D7F94)+0x148);
	//};

	zMAT4* GetMatrix(int trafo)
	{
		XCALL(0x0054A6A0)
	}

	/** Insert description. 
	* @usable Ingame only
	*/
	static inline zCCamera* GetCamera(void)
	{
		return *(zCCamera**)0x008D7F94;
	};
};

#undef __G2EXT_API_HEADER

#endif  //__API_G2_ZCCAMERA_H__