//////////////////////////////////////////////////////////////////////////////
// 
// The G2Ext SDK headers are being published under the 
// Mozilla Public License Version 1.1 (the "License"); you may not use this 
// file except in compliance with the License.
// You may obtain a copy of the License at http://www.mozilla.org/MPL/
// 
// Software distributed under the License is distributed on an "AS IS"
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
// License for the specific language governing rights and limitations
// under the License.
// 
// Developed by Christoffer Anselm and Patrick Vogel
// All rights reserved.
//
// G2Ext SDK headers © 2009 by Paindevs and Patrick Vogel
//
///////////////////////////////////////////////////////////////////////////////

#ifndef __API_G2_ZCMODEL_H__
#define __API_G2_ZCMODEL_H__

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"

/** Insert description. */
class zCModel
{
public:
	//
	/** This method closes the loadscreen.
	* @usable Ingame only
	*/
	void StartAni(int a, int b)					{ XCALL(0x0057B070); };

	//
	/** This method closes the loadscreen.
	* @usable Ingame only
	*/
	void StartAni(const zSTRING& pA, int pB)	{ XCALL(0x0057AF70); };

	//
	/** This method closes the loadscreen.
	* @usable Ingame only
	*/
	void StopAni(int a)							{ XCALL(0x0057ABE0); };

	//
	/** This method closes the loadscreen.
	* @usable Ingame only
	*/
	void FadeOutAni(int pA)						{ XCALL(0x0057EF50); };

	//
	/** This method closes the loadscreen.
	* @usable Ingame only
	*/
	void FadeOutAnisLayerRange(int a, int b)	{ XCALL(0x0057F1F0); };

	//
	/** This method closes the loadscreen.
	* @usable Ingame only
	*/
	void StopAnisLayerRange(int pA, int pB)		{ XCALL(0x0057F240); };
};

#endif  //__API_G2_ZCMODEL_H__