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

#ifndef __API_G2EXT_STATISTICS_H__
#define __API_G2EXT_STATISTICS_H__

#include "api/interface.h"

/** Insert description. */
G2EXT_BEGIN_INTERFACE_DECLARATION(IStatistics)
	/** Insert description. 
	* @usable Ingame only
	*/
	virtual void	Start(void)				= NULL;

	/** Insert description. 
	* @usable Ingame only
	*/
	virtual void	Stop(void)				= NULL;

	/** Insert description. 
	* @usable Ingame only
	*/
	virtual bool	IsActive(void)			= NULL;

	/** Insert description. 
	* @usable Ingame only
	*/
	virtual void	Show(void)				= NULL;

	/** Insert description. 
	* @usable Ingame only
	*/
	virtual void	Hide(void)				= NULL;

	/** Insert description. 
	* @usable Ingame only
	*/
	virtual bool	IsVisible(void)			= NULL;

	/** Insert description. 
	* @usable Ingame only
	*/
	virtual DWORD	GetFPS(void)			= NULL;

	/** Insert description. 
	* @usable Ingame only
	*/
	virtual DWORD	GetMinFPS(void)			= NULL;

	/** Insert description. 
	* @usable Ingame only
	*/
	virtual DWORD	GetMaxFPS(void)			= NULL;

	/** Insert description. 
	* @usable Ingame only
	*/
	virtual DWORD	GetAverageFPS(void)		= NULL;

	/** Insert description. 
	* @usable Ingame only
	*/
	virtual DWORD	GetFrameCount(void)		= NULL;

	/** Insert description. 
	* @usable Ingame only
	*/
	virtual DWORD	GetAlphaPolyCount(void)	= NULL;

	/** Insert description. 
	* @usable Ingame only
	*/
	virtual DWORD	GetPolyCount(void)		= NULL;

	/** Insert description. 
	* @usable Ingame only
	*/
	virtual DWORD	GetTriangleCount(void)	= NULL;

	/** Insert description. 
	* @usable Ingame only
	*/
	virtual DWORD	GetElapsedTime(void)	= NULL;

G2EXT_END_INTERFACE_DECLARATION(IStatistics)

#endif  //__API_G2EXT_STATISTICS_H__
