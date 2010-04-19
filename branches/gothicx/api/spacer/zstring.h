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

#ifndef __API_SPACER_ZSTRING_H__
#define __API_SPACER_ZSTRING_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifndef _G2EXT_COMPILE_SPACER
#error Cannot use spacer headers on non spacer dll (_G2EXT_COMPILE_SPACER not defined)
#endif

#include "api/spacer/ztypes.h"
#include "api/spacer/macros.h"

/** Gothic string class: zSTRING */
class zSTRING
{
private:
	char data[20];
public:
	//.text:0040E6D0 ; public: __thiscall zSTRING::zSTRING(void)
	/** Constructor
	* @usable Ingame only
	*/
	zSTRING()
	{
		XCALL(0x0040E6D0); //spacer
	};

	//.text:004010C0 ; public: __thiscall zSTRING::zSTRING(char const *)
	/** Constructor
	* @param  lpStr text
	* @usable Ingame only
	*/
	zSTRING(const char* lpStr)
	{
		XCALL(0x004010C0); //spacer
	};

	//.text:00444690 ; public: __thiscall zSTRING::zSTRING(class zSTRING const &)
	/** Constructor
	* @param  zstr text
	* @usable Ingame only
	*/
	zSTRING(const class zSTRING & zstr)
	{
		XCALL(0x00444690); //spacer
	};

	//.text:007FF1F0 ; public: __thiscall zSTRING::zSTRING(class zSTRING const *)
	/** Constructor
	* @param  zstr text
	* @usable Ingame only
	*/
	zSTRING(const class zSTRING* zstr)
	{
		XCALL(0x007FF1F0); //spacer
	};

	//.text:00424B40 ; public: __thiscall zSTRING::zSTRING(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING(int str)
	{
		XCALL(0x00424B40); //spacer
	};

	//.text:006A6830 ; public: __thiscall zSTRING::zSTRING(char)
	/** Insert description. 
	* @usable Ingame only
		*/
	zSTRING(char str)
	{
		XCALL(0x006A6830); //spacer
	};

	//.text:004ED7C0 ; public: class zSTRING & __thiscall zSTRING::operator+=(char const *)
	/** += operator for LPCSTRs
	* @usable Ingame only
	*/
	zSTRING & operator+=(LPCSTR p1)
	{
		XCALL(0x004ED7C0); //spacer
	};

	//.text:0053A7C0 ; public: class zSTRING & __thiscall zSTRING::operator=(char const *)
	/** = operator for LPCSTRs
	* @usable Ingame only
	*/
	zSTRING & operator=(LPCSTR p1)
	{
		XCALL(0x0053A7C0); //spacer
	};

	//.text:0053A660 ; public: class zSTRING & __thiscall zSTRING::operator=(class zSTRING const &)
	/** = operator for zSTRINGs
	* @usable Ingame only
	*/
	zSTRING & operator=(const zSTRING & p1)
	{
		XCALL(0x0053A660); //spacer
	};

	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING & operator+(const zSTRING & p1)
	{
		this->Insert(this->Length(), p1);
		return *this;
	};

	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING & operator+(const char* p1)
	{
		this->Insert(this->Length(), zSTRING(p1));
		return *this;
	};

	//.text:007281A0 ; public: void __thiscall zSTRING::Clear(void)
	/** This method clears the zSTRING
	* @usable Ingame only
	*/
	void Clear(void)
	{
		XCALL(0x007281A0); //spacer
	};

	//.text:00625BF0 ; public: int __thiscall zSTRING::Delete(unsigned int, unsigned long)
	/** This method deletes a string in a specific range from the zSTRING
	* @param p1 marker begin
	* @param p2 marker end
	* @usable Ingame only
	*/
	void Delete(unsigned int pos1, unsigned long pos2)
	{
		XCALL(0x00625BF0); //spacer
	};

	//.text:00625AE0 ; public: int __thiscall zSTRING::DeleteRight(unsigned int)
	/** This method deletes a string from the end of the zSTRING in reverse order
	* @param pos characters to delete
	* @usable Ingame only
	*/
	void DeleteRight(unsigned int pos)
	{
		XCALL(0x00625AE0); //spacer
	};

	//.text:00625550 ; public: int __thiscall zSTRING::Insert(unsigned int, class zSTRING const &)
	/** This method inserts a zSTRING into a zSTRING on a specific position 
	* @param pos
	* @param p2
	* @usable Ingame only
	*/
	int Insert(unsigned int pos, const zSTRING & p2)
	{
		XCALL(0x00625550); //spacer
	};

	//.text:004E7200 ; public: bool __thiscall zSTRING::IsEmpty(void)const
	/** This method returns whether the zSTRING is empty or not
	* @return true when zSTRING is empty - false when not
	* @usable Ingame only
	*/
	bool IsEmpty(void)
	{
		XCALL(0x004E7200); //spacer	
	};

	//.text:00728270 ; public: int __thiscall zSTRING::Length(void)const
	/** This method returns the length of the zSTRING
	* @return length of zSTRING
	* @usable Ingame only
	*/
	int Length(void)
	{
		XCALL(0x00728270); //spacer	
	};

	//.text:00624B40 ; public: class zSTRING & __thiscall zSTRING::Lower(void)
	/** Lowers all characters
	* @usable Ingame only
	*/
	zSTRING & Lower(void)
	{
		XCALL(0x00624B40); //spacer	
	};

	//.text:006257F0 ; public: int __thiscall zSTRING::Overwrite(unsigned int, class zSTRING const &)
	/** This method overwrites a specific section of the zSTRING
	* @param pos position of overwrite
	* @param p2 string to overwrite with
	* @usable Ingame only
	*/
	int Overwrite(unsigned int pos, const zSTRING & p2)
	{
		XCALL(0x006257F0); //spacer	
	};

	//.text:0053A900 ; public: int __thiscall zSTRING::Search(char const *, unsigned int)const
	/** This method searches a string in the zSTRING
	* @param  Search keyword
	* @param  Position to start the search from
	* @return Position of searched string. 0 if the string has not been found.
	* @usable Ingame only
	*/
	int Search(char const * p1, unsigned int p2 = 1)
	{
		XCALL(0x0053A900); //spacer	
	};

	//.text:0043EE00 ; public: int __thiscall zSTRING::Search(class zSTRING const &, unsigned int)const
	/** This method searches a string in the zSTRING
	* @param  Search keyword
	* @param  Position to start the search from
	* @return Position of searched string. 0 if the string has not been found.
	*/
	int Search(class zSTRING const & p1, unsigned int p2 = 1)
	{
		XCALL(0x0043EE00); //spacer	
	};

	//.text:00626B70 ; public: int __thiscall zSTRING::SearchRev(class zSTRING const &, unsigned int)const
	/** This method searches a string in the zSTRING from the end of the string as start (reverse search)
	* @param  Search keyword
	* @param  Position to start the search from
	* @return Position of searched string. 0 if the string has not been found.
	*/
	int SearchRev(class zSTRING const & p1, unsigned int p2)
	{
		XCALL(0x00626B70); //spacer		
	};

	//.text:00624C50 ; public: class zSTRING & __thiscall zSTRING::Upper(void)
	/** This method makes the whole string upper case.
	* @usable Ingame only
	*/
	zSTRING & Upper(void)
	{
		XCALL(0x00624C50); //spacer		
	};

	//.text:00624D60 ; public: class zSTRING & __thiscall zSTRING::UpperFirstLowerRest(void)
	/** This method makes the first letter of the string upper case and the rest lower case
	* @usable Ingame only
	*/
	zSTRING & UpperFirstLowerRest(void)
	{
		XCALL(0x00624D60); //spacer	
	};

	//.text:00411CA0 ; public: char * __thiscall zSTRING::ToChar(void)const
	/** This method converts the zSTRING to a char*
	* @return char* format string
	* @usable Ingame only
	*/
	const char* ToChar(void)
	{
		XCALL(0x00411CA0); //spacer	
	};

	//.text:004653F0 ; public: float __thiscall zSTRING::ToFloat(void)const
	/** This method converts the zSTRING to a float
	* @return float value
	* @usable Ingame only
	*/
	float ToFloat(void)
	{
		XCALL(0x004653F0); //spacer	
	};

	//.text:0053A880 ; public: long __thiscall zSTRING::ToInt(void)const
	/** This method converts the zSTRING to an integer
	* @return int value
	* @usable Ingame only
	*/
	long ToInt(void)
	{
		XCALL(0x0053A880); //spacer	
	};
};

#undef __G2EXT_API_HEADER

#endif // __API_SPACER_ZSTRING_H__