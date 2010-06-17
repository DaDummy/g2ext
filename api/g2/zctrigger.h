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

#ifndef __ZCTRIGGER_H_INCLUDED__
#define __ZCTRIGGER_H_INCLUDED__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"
#include "api/g2/zcvob.h"

class zCSoundFX;
class zCModel;

struct zTMov_Keyframe 
{
	zPOINT3	pos;
	zCQuat	quat;
};

enum zTMoverState       
{ 
	MOVER_STATE_OPEN, 
	MOVER_STATE_OPENING, 
	MOVER_STATE_CLOSED, 
	MOVER_STATE_CLOSING
};

enum zTMoverAniType     
{ 
	MA_KEYFRAME,
	MA_MODEL_ANI, 
	MA_WAYPOINT 
};
enum zTMoverBehavior    
{ 
	MB_2STATE_TOGGLE,             
	MB_2STATE_TRIGGER_CONTROL,    
	MB_2STATE_OPEN_TIMED,         
	MB_NSTATE_LOOP,
	MB_NSTATE_SINGLE_KEYS
};

enum zTTouchBehavior
{ 
	TB_TOGGLE,
	TB_WAIT
};

enum zTPosLerpType       
{   
	PL_LINEAR, 
	PL_CURVE 
};

enum zTSpeedType     
{ 
	ST_CONST, 
	ST_SLOW_START_END, 
	ST_SLOW_START,
	ST_SLOW_END,
	ST_SEG_SLOW_START_END, 
	ST_SEG_SLOW_START, 
	ST_SEG_SLOW_END 
};

class zCTrigger : public zCVob
{
private:
	zSTRING triggerTarget;

	struct 
	{
		BYTE reactToOnTrigger: 1;
		BYTE reactToOnTouch  : 1;
		BYTE reactToOnDamage : 1;

		BYTE respondToObject : 1;
		BYTE respondToPC     : 1;
		BYTE respondToNPC    : 1;
	} filterFlags;
	struct 
	{
		BYTE startEnabled    : 1;    
		BYTE isEnabled       : 1;
		BYTE sendUntrigger   : 1;    
	} flags;

	zSTRING respondToVobName; 
	DWORD	numCanBeActivated;
	float	retriggerWaitSec; 
	float	damageThreshold;  
	float	fireDelaySec;     
	float	nextTimeTriggerable;
	zCVob*	savedOtherVob;      
	DWORD	countCanBeActivated;
public:
};

class oCTriggerScript : public zCTrigger
{
private:
	zSTRING scriptFunc;
public:
};

class oCTriggerChangeLevel : public zCTrigger
{
private:
	zSTRING levelName;
	zSTRING startVob;
public:
};

class zCMover : public zCTrigger
{
private:

	zCArray<zTMov_Keyframe>	keyframeList;
	zVEC3			actKeyPosDelta;
	float			actKeyframeF; 
	int				actKeyframe;
	int				nextKeyframe;  
	float			moveSpeedUnit;
	float			advanceDir; 
	zTMoverState	moverState;

	int				numTriggerEvents; 
	float			stayOpenTimeDest;

	zCModel*		model;
	zTSoundHandle	soundMovingHandle;
	zCSoundFX*		sfxMoving;

	float			moveSpeed;
	float			stayOpenTimeSec;
	float			touchBlockerDamage;

	int				bitfield;
	zTMoverAniType	moverAniType;
	zTMoverBehavior moverBehavior;
	zTTouchBehavior touchBehavior;
	zTPosLerpType	posLerpType;
	zTSpeedType		speedType;

	zSTRING			soundOpenStart;
	zSTRING			soundOpenEnd;
	zSTRING			soundMoving;
	zSTRING			soundCloseStart;
	zSTRING			soundCloseEnd;
	zSTRING			soundLock;
	zSTRING			soundUnlock; 
	zSTRING			soundUseLocked;
public:
};

#undef __G2EXT_API_HEADER

#endif  //__ZCTRIGGER_H_INCLUDED__