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

#ifndef __API_G2_CGAMEMANAGER_H__
#define __API_G2_CGAMEMANAGER_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"
#include "api/g2/ocgame.h"

/** Insert description. */
class CGameManager
{
public:
	//.text:00425780 ; public: int __thiscall CGameManager::ExitGame(void)
	/** This method closes Gothic. 
	* @usable Ingame only
	*/
	int ExitGame(void)
	{
		XCALL(0x00425780);
	};

	//.text:00425790 ; public: int __thiscall CGameManager::ExitSession(void)
	/** This method closes the current game session.
	* @usable Ingame only
	*/
	int ExitSession(void)
	{
		XCALL(0x00425790);
	};

	//.text:0042B1B0 ; public: class oCGame * __thiscall CGameManager::GetGame(void)
	/** This method returns the current oCGame instance.
	* @returns Current oCGame instance.
	* @usable Ingame only
	*/
	oCGame* GetGame(void)
	{
		XCALL(0x0042B1B0);
	};

	//.text:00429280 ; public: int __thiscall CGameManager::GetPlaytimeSeconds(void)
	/** This method returns the total playtime in seconds.
	* @returns Total playtime in seconds
	* @usable Ingame only
	*/
	int GetPlaytimeSeconds(void)
	{
		XCALL(0x00429280);
	};

	//.text:0042B7E0 ; public: int __thiscall CGameManager::IntroduceChapter(class zSTRING, class zSTRING, class zSTRING, class zSTRING, int)
	/** This method shows a "chapter introduction" screen.
	* @param Title Determines the chapter title
	* @param Subtitle Determines the subtitle
	* @param Texture Determines the background texture
	* @param Sound Determines which sound will be played when the introduction screen is being executed
	* @param WaitTime Determines how long the introduction screen will be shown
	* @usable Ingame only
	*/
	int IntroduceChapter(zSTRING Title, zSTRING Subtitle, zSTRING Texture, zSTRING Sound, int WaitTime)
	{
		XCALL(0x0042B7E0);
	};

	//.text:0042B200 ; public: int __thiscall CGameManager::IsGameRunning(void)
	/** This method determines whether the a game session is running or not.
	* @usable Ingame only
	*/
	int IsGameRunning(void)
	{
		XCALL(0x0042B200);
	};

	//.text:0042B1C0 ; public: int __thiscall CGameManager::IsIntroActive(void)
	/** This method determines whether the intro videos are active or not.
	* @usable Ingame only
	*/
	int IsIntroActive(void)
	{
		XCALL(0x0042B1C0);
	};

	//.text:0042B940 ; public: int __thiscall CGameManager::PlayVideo(class zSTRING)
	/** This method plays a Bink video.
	* @param Filename Filename of the video (relative to data\videos\)
	* @usable Ingame only
	*/
	int PlayVideo(zSTRING Filename)
	{
		XCALL(0x0042B940);
	};

	//.text:0042BB10 ; public: int __thiscall CGameManager::PlayVideoEx(class zSTRING, short, int)
	/** This method plays a Bink video.
	* @param Filename Filename of the video (relative to data\videos\)
	* @param ScreenBlend Determines whether the "BLACK_SCREEN" should be played after playing the video (does not execute with ExitSession is true)
	* @param ExitSession Determines whether the game should be ended after playing the video.
	* @usable Ingame only
	*/
	int PlayVideoEx(zSTRING Filename, zBOOL ScreenBlend, zBOOL ExitSession)
	{
		XCALL(0x0042BB10);
	};

	/** This method returns the current CGameManager instance
	* @usable Ingame only
	*/
	inline static CGameManager*		GetGameManager(){ return *(CGameManager**)0x008C2958; };
};

#undef __G2EXT_API_HEADER

#endif //__API_G2_CGAMEMANAGER_H__