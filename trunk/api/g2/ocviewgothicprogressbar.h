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

#ifndef __OCVIEWGOTHICPROGRESSBAR_H_INCLUDED__
#define __OCVIEWGOTHICPROGRESSBAR_H_INCLUDED__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"

/** Insert description. */
class oCViewGothicProgressBar : public oCViewProgressBar
{
private:
	char _data[0x256];
public:
	//.text:0043D2B0 ; public: void __thiscall oCViewGothicProgressBar::Init(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Init(void)
	{
		XCALL(0x0043D2B0);
	};

	//.text:0043D2F0 ; public: void __thiscall oCViewGothicProgressBar::HandleChange(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void HandleChange(void)
	{
		XCALL(0x0043D2F0);
	};
};

#undef __G2EXT_API_HEADER

#endif  //__OCVIEWGOTHICPROGRESSBAR_H_INCLUDED__