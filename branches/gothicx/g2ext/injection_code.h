/*////////////////////////////////////////////////////////////////////////

This file is part of the G2Ext source code.

//////////////////////////////////////////////////////////////////////////

G2Ext is a fan-made engine SDK for Gothic II TNotR (v2.6).
Copyright (C) 2009, 2010 by Paindevs and Patrick Vogel

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

////////////////////////////////////////////////////////////////////////*/

#ifndef __G2EXT_INJECTION_CODE_H__
#define __G2EXT_INJECTION_CODE_H__

#include "common/osheader.h"
#include "getcode.h"

/** naming scheme
 * inj_			general injection prefix
 * inj_basic_	basic injection
 * inj_t_		injection template
 * inj_t_hook_	hook template
 * inj_ev_		(internal) event
 */
GETCODE_DECLARE(inj_t_jmp_code);
GETCODE_DECLARE(inj_t_call_code);
GETCODE_DECLARE(inj_basic_init_code);

#endif //__G2EXT_INJECTION_CODE_H__