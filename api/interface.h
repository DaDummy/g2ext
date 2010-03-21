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

///////////////////////////////////////////////////////////////////////////////
// ATTENTION!
//
// This file contains g2ext api-internal stuff that should not be used in mods!
//
///////////////////////////////////////////////////////////////////////////////

#ifndef __API_G2EXT_INTERFACE_H__
#define __API_G2EXT_INTERFACE_H__

#define G2EXT_BEGIN_INTERFACE_DECLARATION(name) __interface actual_##name

#define G2EXT_INTERFACE_IMPLEMENT_INTERFACE(name)	actual_##base

#define G2EXT_INTERFACE_MEMBER(name) virtual name = NULL;

#define G2EXT_END_INTERFACE_DECLARATION(name) ;		\
	class name : public actual_##name {			\
public:												\
	virtual ~name() {}								\
};

#endif //__API_G2EXT_INTERFACE_H__