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

#ifndef __API_G2_ZCRENDERER_H__
#define __API_G2_ZCRENDERER_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"
#include "dx7sdk/inc/d3d.h"
#include "dx7sdk/inc/ddraw.h"

/** Gothic's Direct3D 7 renderer class. */
class zCRenderer
{
private:
	char m_data[1024];
public:
	/** This method returns the current DirectDraw instance
	* @usable Ingame only
	*/
	inline static IDirectDraw7* GetDirectDraw(void) { return *(IDirectDraw7**)0x009FC9EC; };

	/** This method returns the current Direct3D7 instance
	* @usable Ingame only
	*/
	inline static IDirect3D7* GetDirect3D(void) { return *(IDirect3D7**)0x009FC9F0; };

	/** This method returns the current Direct3D device instance
	* @usable Ingame only
	*/
	inline static IDirect3DDevice7* GetDirect3DDevice(void) { return *(IDirect3DDevice7**)0x009FC9F4; };

	/** This method returns the current zCRenderer instance
	* @usable Ingame only
	*/
	inline static zCRenderer* GetRenderer()	{ return *(zCRenderer**)0x00982F08; };
};

#undef __G2EXT_API_HEADER

#endif //__API_G2_ZCRENDERER_H__