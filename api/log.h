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

#ifndef __API_G2EXT_LOG_H__
#define __API_G2EXT_LOG_H__

// That interface stuff does not work with varargs(WriteF(...)) and the workaround isn't ready yet
//#include "api/interface.h"

#ifndef LOG_LEVEL_DEFINED
#define LOG_LEVEL_DEFINED

/** This enumerator defines the log levels of G2Ext. */
enum LOG_LEVEL
{
	/** Log without priority. */
	LOG_NONE		= 0,
	/** Log without priority [no timestamp]. */
	LOG_NONE_NTS	= 1,
	/** Log with "debug" priority. */
	LOG_DEBUG		= 25,		
	/** Log with "info" priority. */
	LOG_INFO		= 50,		
	/** Log with "important" priority. */
	LOG_IMPORTANT	= 100,		
	/** Log with "warning" priority. */
	LOG_WARNING		= 150,		
	/** Log with "error" priority. */
	LOG_ERROR		= 200,		
	/** Log with "critical error" priority. */
	LOG_CRITICAL	= 255,
};

#endif //LOG_LEVEL_DEFINED

/** This class delivers the logging functionality of G2Ext. */
//G2EXT_BEGIN_INTERFACE_DECLARATION(ILog)
class ILog
{
public:
	/** This method logs the string you give to it to a file
	* @param	eLogLevel log level (should be self explaining)
	* @param	wcMessage message that will be logged
	* @usable	Always
	*/
	virtual void Write(LOG_LEVEL eLogLevel, LPCWSTR wcMessage) = NULL;

	/** This method formats and logs the string you give to it to a file
	 * @param	eLogLevel log level (should be self explaining)
	 * @param   wcFormat format string (use it like in [s]printf)
	 * @param   ... argument list
	 * @usable	Always
	 */
	virtual void WriteF(LOG_LEVEL eLogLevel, LPCWSTR wcFormat, ...) = NULL;

	/** This method inserts a divider into the log
	* @usable  Always
	*/
	virtual void Divider(void) = NULL;
};
// G2EXT_END_INTERFACE_DECLARATION(ILog);

#endif // __API_G2EXT_LOG_H__