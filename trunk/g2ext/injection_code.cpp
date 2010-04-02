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

#include "injection_code.h"

GETCODE_BEGIN	( inj_t_jmp_code );
__asm
{
	push 0x11111111	; 0x11111111 durch Adresse von der injection ersetzen
	ret				; Jmp: injection
}
GETCODE_END;

GETCODE_BEGIN	( inj_t_call_code );
__asm
{
	call cs:0x11111111 ; 0x11111111 durch Adresse von der injection ersetzen - Call: injection
}
GETCODE_END;

#ifdef _G2EXT_COMPILE_SPACER
GETCODE_BEGIN_EX_B	( inj_basic_init_code );
GETCODE_BEGIN_EX_PTR( 2, getcode_ptr2 );
GETCODE_BEGIN_EX_PTR( 3, getcode_ptr3 );
GETCODE_BEGIN_EX_E;
__asm
{
	push 0x11111111      ; 0x11111111 durch Adresse von inj_hook_startup_s_str0 ersetzen
	mov  edx, 0x0085C978
	call edx             ; Call: LoadLibraryA(LPCSTR lpLibFileName)
getcode_ptr2:
	push 0x11111111      ; 0x11111111 durch Adresse von inj_hook_startup_s_str1 ersetzen
	push Eax
	mov  edx, 0x0085C9C6
	call edx             ; Call: GetProcAddress(HMODULE hModule,LPCSTR lpProcName)
getcode_ptr3:
	push 0x11111111      ; 0x11111111 durch Adresse von inj_hook_startup_s_mi ersetzen
	call Eax             ; Call: init(MOD_INFO* mi)
	mov  Eax, [Esp+0x1C+0x10]
	mov  Ecx, [Esp+0x1C+0x08]
	mov  Edx, 0x00502DF4
	jmp  Edx             ; Jump: back
}
GETCODE_END;
#else //_G2EXT_COMPILE_SPACER
GETCODE_BEGIN_EX_B	( inj_basic_init_code );
GETCODE_BEGIN_EX_PTR( 2, getcode_ptr2 );
GETCODE_BEGIN_EX_PTR( 3, getcode_ptr3 );
GETCODE_BEGIN_EX_E;
__asm
{
	push 0x11111111      ; 0x11111111 durch Adresse von inj_hook_startup_s_str0 ersetzen
	mov  edx, 0x007B47FE
	call edx             ; Call: LoadLibraryA(LPCSTR lpLibFileName)
getcode_ptr2:
	push 0x11111111      ; 0x11111111 durch Adresse von inj_hook_startup_s_str1 ersetzen
	push Eax
	mov  edx, 0x007B487C
	call edx             ; Call: GetProcAddress(HMODULE hModule,LPCSTR lpProcName)
getcode_ptr3:
	push 0x11111111      ; 0x11111111 durch Adresse von inj_hook_startup_s_mi ersetzen
	call Eax             ; Call: init(MOD_INFO* mi)
	mov  Eax, [Esp+0x1C+0x10]
	mov  Ecx, [Esp+0x1C+0x08]
	mov  Edx, 0x00502DF4
	jmp  Edx             ; Jump: back
}
GETCODE_END;
#endif //_G2EXT_COMPILE_SPACER