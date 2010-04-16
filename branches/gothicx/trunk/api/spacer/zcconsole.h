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

#ifndef __API_G2_ZCCONSOLE_H__
#define __API_G2_ZCCONSOLE_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADRE
#endif  //__G2EXT_API_HEADER

#ifndef _G2EXT_COMPILE_SPACER
#error Cannot use spacer headers on non spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/spacer/ztypes.h"
#include "api/spacer/macros.h"
#include "api/spacer/zcinputcallback.h"

class zCWorld;
class zCParser;

/** Insert description. */
class zCConsole : public zCInputCallback
{
private:
	zSTRING unk;
	zSTRING unk2;
	zSTRING result;
	char m_datab[256]; // TODO: Get size
public:
	//.text:007EED10 ; public: class zCWorld * __thiscall zCConsole::GetWorld(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zCWorld* GetWorld() { XCALL(0x007EED10); };

	//.text:007EED20 ; public: class zCParser * __thiscall zCConsole::GetParser(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zCParser* GetParser(void) { XCALL(0x007EED20); };

	//.text:007F01C0 ; public: int __thiscall zCConsole::IsVisible(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	int IsVisible(void) { XCALL(0x007F01C0); };

	//.text:007F00D0 ; public: void __thiscall zCConsole::Toggle(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Toggle(void) { XCALL(0x007F00D0); };

	//.text:007EFFE0 ; public: void __thiscall zCConsole::Hide(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Hide(void) { XCALL(0x007EFFE0); };

	//.text:007EFD90 ; public: void __thiscall zCConsole::Show(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Show(void) { XCALL(0x007EFD90); };

	//.text:007F1190 ; public: int __thiscall zCConsole::Evaluate(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	int	Evaluate(const zSTRING& in) { XCALL(0x007F1190); };

	//.text:007F0DE0 ; private: void __thiscall zCConsole::Eval(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Eval(const zSTRING& in) { XCALL(0x007F0DE0); };

	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING& GetResult(void) { return this->result; };

	//.text:007F0210 ; public: void __thiscall zCConsole::Update(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Update(void) { XCALL(0x007F0210); };

	//.text:007F18B0 ; public: void __thiscall zCConsole::AddEvalFunc(int (__cdecl *)(class zSTRING const &, class zSTRING &))
	/** Insert description. 
	* @usable Ingame only
	*/
	void AddEvalFunc(int (__cdecl *)(zSTRING& zCommand, zSTRING& zReturn)) { XCALL(0x007F18B0); };

	//.text:007EF530 ; public: int __thiscall zCConsole::AutoCompletion(class zSTRING &)
	/** Insert description. 
	* @usable Ingame only
	*/
	int AutoCompletion(zSTRING& str) { XCALL(0x007EF530); };

	//.text:007EF410 ; public: void __thiscall zCConsole::Register(class zSTRING const &, class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Register(const zSTRING& zCommand, const zSTRING& zDesc) { XCALL(0x007EF410); };

	/** This method returns the current zCConsole instance
	* @usable Ingame only
	*/
	inline static zCConsole* GetConsole() { return (zCConsole*)0x00C29F18; };
};

#undef __G2EXT_API_HEADER

#endif // __API_G2_ZCCONSOLE_H__