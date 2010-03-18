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

#ifndef __API_G2_OCSPELL_H__
#define __API_G2_OCSPELL_H__

#include "api/g2/ztypes.h"

namespace g2
{
/** Insert description. */
class oCSpell
{
private:
	char m_data[1024];
public:
	//
	/** Insert description. 
	* @usable Ingame only
	*/
	void Spell_Cast()									{ XCALL(0x004767A0) };

	//
	/** Insert description. 
	* @usable Ingame only
	*/
	void StartCastEffect(zCVob* pA, const zVEC3& pB)	{ XCALL(0x00476E60) };
};

#endif //__API_G2_OCSPELL_H__