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

#ifndef __API_G2_OCGAME_H__
#define __API_G2_OCGAME_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"
#include "api/g2/zcinputcallback.h"

class zCView;
class zCWorld;
class oCWorldTimer;
class zCViewProgressBar;

enum oHEROSTATUS
{
	HERO_NORMAL,
	HERO_THREATENED,
	HERO_FIGHTING
};

/** Insert description. */
class oCGame : public zCInputCallback
{
private:
	char m_data[0x18C];
public:
	//.text:006C2BD0 ; public: virtual void __thiscall oCGame::CloseLoadscreen(void)
	/** This method closes the loadscreen.
	* @usable Ingame only
	*/
	void CloseLoadscreen(void)
	{
		XCALL(0x006C2BD0);
	};

	//.text:006C2630 ; public: virtual void __thiscall oCGame::CloseSavescreen(void)
	/** This method closes the savescreen.
	* @usable Ingame only
	*/
	void CloseSavescreen(void)
	{
		XCALL(0x006C2630);
	};

	//.text:006C2D10 ; public: enum  oHEROSTATUS __thiscall oCGame::GetHeroStatus(void)
	/** This method returns the current hero status.
	* @usable Ingame only
	*/
	oHEROSTATUS GetHeroStatus(void)
	{
		XCALL(0x006C2D10);
	};

	//.text:006BFE50 ; public: virtual class zVEC3 __thiscall oCGame::GetStartPos(void)
	/** This method returns the start position of the hero (e.g. position of the world's startingpoint).
	* @usable Ingame only
	*/
	zVEC3 GetStartPos(void)
	{
		XCALL(0x006BFE50);
	};

	//.text:006C4E70 ; public: virtual void __thiscall oCGame::GetTime(int &, int &, int &)
	/** This method returns the current ingame time.
	* @param day Reference to integer variable for the day value.
	* @param hwr Reference to integer variable for the hour value. 
	* @param min Reference to integer variable for the minute value.
	* @usable Ingame only
	*/
	void GetTime(int & day, int & hwr, int & min)
	{
		XCALL(0x006C4E70);
	};

	//.text:006C2C80 ; public: class oCWorldTimer * __thiscall oCGame::GetWorldTimer(void)
	/** This method returns the current world timer instance.
	* @usable Ingame only
	*/
	oCWorldTimer* GetWorldTimer(void)
	{
		XCALL(0x006C2C80);
	};

	// zCSession::GetWorld(void)
	/** This method returns the current zCWorld instance of oCGame.
	* @usable Ingame only
	*/
	zCWorld* GetWorld(void) 
	{ 
		XCALL(0x005DECF0);
	};

	//.text:006C2C30 ; public: virtual class oCWorld * __thiscall oCGame::GetGameWorld(void)
	/** This method returns the current oCWorld instance of oCGame.
	* @usable Ingame only
	*/
	/*
	oCWorld* GetGameWorld(void)
	{
	XCALL(0x006C2C30);
	};
	*/

	//.text:006C2690 ; public: virtual void __thiscall oCGame::OpenLoadscreen(bool, class zSTRING)
	/** This method opens the loadscreen.
	* @usable Ingame only
	*/
	void OpenLoadscreen(int p1, zSTRING p2)
	{
		XCALL(0x006C2690);
	};

	//.text:006C2250 ; public: virtual void __thiscall oCGame::OpenSavescreen(bool)
	/** This method opens the savescreen.
	* @usable Ingame only
	*/
	void OpenSavescreen(int p1)
	{
		XCALL(0x006C2250);
	};

	//.text:006C8AD0 ; public: virtual void __thiscall oCGame::Pause(int)
	/** This method pauses the game. 
	* @usable Ingame only
	*/
	void Pause(int p1 = 0)
	{
		XCALL(0x006C8AD0);
	};

	//.text:006C4DE0 ; public: virtual void __thiscall oCGame::SetTime(int, int, int)
	/** This method sets the ingame time.
	* @param day Day
	* @param hwr Hour
	* @param min Minute
	* @usable Ingame only
	*/
	void SetTime(int day, int hwr, int min)
	{
		XCALL(0x006C4DE0);
	};

	//.text:006C8D50 ; public: virtual void __thiscall oCGame::Unpause(void)
	/** This method continues the game. 
	* @usable Ingame only
	*/
	void Unpause(void)
	{
		XCALL(0x006C8D50);
	};

	/** Insert description.
	* @usable Ingame only
	*/
	zCViewProgressBar* GetProgressBar(void)
	{
		return *(zCViewProgressBar**)(this+0x172);
	};

	/** This method returns the current oCGame instance
	* @usable Ingame only
	*/
	inline static oCGame* GetGame() { return *(oCGame**)0x00AB0884; };
};

#undef __G2EXT_API_HEADER

#endif // __API_G2_OCGAME_H__