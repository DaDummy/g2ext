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

#ifndef __ZTYPES_H_INCLUDED__
#define __ZTYPES_H_INCLUDED__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "common/osheader.h"

#define NULL 0
#define zNEW(x) (new x)

struct zVEC2;
struct zVEC3;
struct zVEC4;
struct zMAT3;
struct zMAT4;

typedef int				zINT;
typedef int				zBOOL;
typedef float			zFLOAT;
typedef float			zREAL;
typedef unsigned char	zBYTE; 
typedef unsigned short	zWORD;  
typedef unsigned long	zDWORD;
typedef float			zREAL;  
typedef unsigned int	zUINT32;
typedef int				zTFrameCtr;
typedef int				zTModelAniID;
typedef int				zTSoundHandle;
typedef zVEC3			zPOINT3;

// -- Main type include headers
#include "api/g2/zmath.h"
#include "api/g2/zcontainers.h"
#include "api/g2/zcolor.h"
#include "api/g2/zstring.h"
#include "api/g2/zcobject.h"

#undef __G2EXT_API_HEADER

#endif // __ZTYPES_H_INCLUDED__