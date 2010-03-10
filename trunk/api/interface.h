/*////////////////////////////////////////////////////////////////////////////

This file is part of the G2Ext SDK headers.

//////////////////////////////////////////////////////////////////////////////

The G2Ext SDK headers are being published under the 
Mozilla Public License Version 1.1 (the "License"); 
you may not use this file except in compliance with the License.
You may obtain a copy of the License at http://www.mozilla.org/MPL/

Software distributed under the License is distributed on an "AS IS"
basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
License for the specific language governing rights and limitations
under the License.

G2Ext SDK headers © 2009, 2010 by Paindevs and Patrick Vogel

/////////////////////////////////////////////////////////////////////////////*/

#ifndef __API_G2EXT_INTERFACE_H__
#define __API_G2EXT_INTERFACE_H__

#ifndef Interface
#define Interface struct
#endif

#ifndef implements
#define implements public
#endif

#define G2EXT_BEGIN_INTERFACE_DECLARATION(name) __interface actual_##name {

#define G2EXT_DECLARE_BASED_INTERFACE(name, base)	\
	__interface actual_##name						\
	: public actual_##base {

#define G2EXT_INTERFACE_MEMBER(name) virtual name = NULL;

#define G2EXT_END_INTERFACE_DECLARATION(name) };	\
	Interface name : public actual_##name {			\
public:												\
	virtual ~name() {}								\
};

#endif //__API_G2EXT_INTERFACE_H__