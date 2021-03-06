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

#ifndef __API_SPACER_ZTYPES_H__
#define __API_SPACER_ZTYPES_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifndef _G2EXT_COMPILE_SPACER
#error Cannot use spacer headers on non spacer dll (_G2EXT_COMPILE_SPACER not defined)
#endif

#include "common/osheader.h"

#define NULL 0
#define zNEW(x) (new x)

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

struct zVEC2;
struct zVEC3;
struct zVEC4;
struct zMAT3;
struct zMAT4;

/** 2D Vector. */
struct zVEC2
{
	union
	{
		struct 
		{
			float x, y;
		};
		float f[2];
	};

	// -- constructors
	zVEC2();
	zVEC2( float _x, float _y );
	zVEC2( const float* pf );
	zVEC2( const zVEC2& v );

	// -- functions
	void Clear();
	void Set( float _x, float _y );

	// -- casts
	operator float* ();
	operator const float* ();

	// -- assignment operators
	zVEC2& operator += ( const zVEC2 & v );
	zVEC2& operator -= ( const zVEC2 & v );
	zVEC2& operator *= ( float f );
	zVEC2& operator /= ( float f );

	// -- unary operators
	zVEC2  operator + () const;
	zVEC2  operator - () const;

	// -- binary operators
	zVEC2  operator + ( const zVEC2& v ) const;
	zVEC2  operator - ( const zVEC2& v ) const;
	zVEC2  operator * ( float f ) const;
	zVEC2  operator / ( float f ) const;

	// -- logical operators
	bool operator == ( const zVEC2& v ) const;
	bool operator != ( const zVEC2& v ) const;
};

/** 3D Vector. */
struct zVEC3
{
	union
	{
		struct 
		{
			float x, y, z;
		};
		float f[3];
	};

	// -- constructors
	zVEC3();
	zVEC3( float _x, float _y, float _z );
	zVEC3( const float* pf );
	zVEC3( const zVEC3& v );

	// -- functions
	inline void Clear();
	inline void Set( float _x, float _y, float _z );

	// -- casts
	operator float* ();
	operator const float* ();

	// -- assignment operators
	zVEC3& operator += ( const zVEC3 & v );
	zVEC3& operator -= ( const zVEC3 & v );
	zVEC3& operator *= ( float f );
	zVEC3& operator /= ( float f );

	// -- unary operators
	zVEC3  operator + () const;
	zVEC3  operator - () const;

	// -- binary operators
	zVEC3  operator + ( const zVEC3& v ) const;
	zVEC3  operator - ( const zVEC3& v ) const;
	zVEC3  operator * ( float f ) const;
	zVEC3  operator / ( float f ) const;

	// -- logical operators
	bool operator == ( const zVEC3& v ) const;
	bool operator != ( const zVEC3& v ) const;
};

/** 4D Vector */
struct zVEC4
{
	union
	{
		struct 
		{
			float x, y, z, w;
		};
		float f[4];
	};

	// -- constructors
	zVEC4();
	zVEC4( float _x, float _y, float _z, float _w );
	zVEC4( const float* pf );
	zVEC4( const zVEC4& v );

	// -- functions
	inline void Clear();
	inline void Set( float _x, float _y, float _z, float _w );

	// -- casts
	operator float* ();
	operator const float* ();

	// -- assignment operators
	zVEC4& operator += ( const zVEC4 & v );
	zVEC4& operator -= ( const zVEC4 & v );
	zVEC4& operator *= ( float f );
	zVEC4& operator /= ( float f );

	// -- unary operators
	zVEC4  operator + () const;
	zVEC4  operator - () const;

	// -- binary operators
	zVEC4  operator + ( const zVEC4& v ) const;
	zVEC4  operator - ( const zVEC4& v ) const;
	zVEC4  operator * ( float f ) const;
	zVEC4  operator / ( float f ) const;

	// -- logical operators
	bool operator == ( const zVEC4& v ) const;
	bool operator != ( const zVEC4& v ) const;
};

/** 3x4 Matrix */
struct zMAT3
{
	union {
		struct {
			float	_11, _12, _13, _14;
			float	_21, _22, _23, _24;
			float	_31, _32, _33, _34;
		};
		float m[3][4];
	};

	zMAT3() {};

	zMAT3( const zMAT3 & _m );

	zMAT3(float f11, float f12, float f13, float f14,
		float f21, float f22, float f23, float f24,
		float f31, float f32, float f33, float f34);

	//  -- assignment operators
	zMAT3& operator *= ( const zMAT3 & _m );
	zMAT3& operator /= ( const zMAT3 & _m );
	zMAT3& operator += ( const zMAT3 & _m );
	zMAT3& operator -= ( const zMAT3 & _m );

	zMAT3& operator *= ( float f );
	zMAT3& operator /= ( float f );

	// -- unary operators
	zMAT3  operator + () const;
	zMAT3  operator - () const;

	// -- binary operators
	zMAT3 operator * ( const zMAT3 & _m );
	zMAT3 operator / ( const zMAT3 & _m );
	zMAT3 operator + ( const zMAT3 & _m );
	zMAT3 operator - ( const zMAT3 & _m );

	zMAT3 operator * ( float f );
	zMAT3 operator / ( float f );

	// -- logical operators
	bool operator == ( const zMAT3 & _m ) const;
	bool operator != ( const zMAT3 & _m ) const;
};

/** 4x4 Matrix */
struct zMAT4
{
	union {
		struct {
			float	_11, _12, _13, _14;
			float	_21, _22, _23, _24;
			float	_31, _32, _33, _34;
			float	_41, _42, _43, _44;
		};
		float m[4][4];
	};

	zMAT4() {};
	zMAT4( const zMAT4 & _m );
	zMAT4( float f11, float f12, float f13, float f14,
		float f21, float f22, float f23, float f24,
		float f31, float f32, float f33, float f34,
		float f41, float f42, float f43, float f44 );

	//  -- assignment operators
	zMAT4& operator *= ( const zMAT4 & _m );
	zMAT4& operator /= ( const zMAT4 & _m );
	zMAT4& operator += ( const zMAT4 & _m );
	zMAT4& operator -= ( const zMAT4 & _m );

	zMAT4& operator *= ( float f );
	zMAT4& operator /= ( float f );

	// -- unary operators
	zMAT4  operator + () const;
	zMAT4  operator - () const;

	// -- binary operators
	zMAT4 operator * ( const zMAT4 & _m );
	zMAT4 operator / ( const zMAT4 & _m );
	zMAT4 operator + ( const zMAT4 & _m );
	zMAT4 operator - ( const zMAT4 & _m );

	zMAT4 operator * ( float f );
	zMAT4 operator / ( float f );

	// -- logical operators
	bool operator == ( const zMAT4 & _m ) const;
	bool operator != ( const zMAT4 & _m ) const;
};

/** Insert description. */
struct zTBBox3D 
{
	zVEC3 bbox3D_mins;
	zVEC3 bbox3D_maxs;
};

/** Insert description. */
struct zTBSphere3D 
{
	zVEC3 bsphere3D_center;
	float bsphere3D_radius;
};

/** Array class wrapper
* @attention: The classes zCList, zCArray, zCListSort, zCArraySort, zCTree, etc. are not intended for regular usage. Please use the STL equivalents for your coding!
*/
template<class T>
class zCArray
{
protected:
	T*  m_array;
	int m_numAlloc;
	int m_numInArray;

private:
	void Reallocate(const int nSize)
	{
		if(nSize == 0)
			return;

		T* pArray = new T[this->m_numAlloc+nSize];

		if(this->m_numInArray > 0)
		{
			for(int i = 0; i < this->m_numInArray; i++)
				pArray[i] = array[i];
		};

		delete [] this->m_array;
		this->m_numAlloc += nSize;
		this->m_array     = pArray;
	};	

public:
	zCArray()
	{
		this->m_array		= NULL;
		this->m_numAlloc	= 0;
		this->m_numInArray	= 0;
	};

	// -- {dtor}
	~zCArray()
	{
		this->Clear();
	};

	const T& operator [] (const unsigned int pos) const
	{
		if((int)pos <= this->m_numInArray)
			return this->m_array[pos];
	};

	T& operator [] (const unsigned int pos)
	{
		if((int)pos <= this->m_numInArray)
			return this->m_array[pos];
	};

	void Clear()
	{
		this->m_numAlloc	= 0;
		this->m_numInArray	= 0;
		if(this->m_array != NULL)
		{
			delete[] this->m_array;
			this->m_array = NULL;
		};
	};

	/**
	* @brief Adds an element to the zCArray.
	* 
	* This method adds an element to the zCArray. If the preallocated memory of the zCArray
	* is full then this method will allocate one additional field to store the the new element.
	* This behaviour saves memory but is very inefficient when adding many elements as memory
	* is allocated on every method call when the preallocated area is full.
	*
	* This method can be interleaved with PushBackFast.
	*/
	void PushBack(const T& in)
	{
		if((this->m_numInArray + 1) > this->m_numAlloc) // -- PB throws around with memory. But we don't, so we use the allocated space and don't allocate more and more memory... (memory leak!?)
			Reallocate(1);

		this->m_array[this->m_numInArray++] = in;
	};

	/**
	* @brief Adds an element to the zCArray.
	* 
	* This method adds an element to the zCArray. If the preallocated memory of the zCArray
	* is full then this method will double the size of the preallocated memory. This might lead
	* to the worst case situation where twice as much memory than needed is used for this zCArray.
	* Use this method in often created/short lived zCArrays.
	*
	* This method can be interleaved with PushBack.
	*/
	void PushBackFast(const T& in)
	{
		if((this->m_numInArray + 1) > this->m_numAlloc) // -- Let's throw around with memory like PB does for performance's sake.
			Reallocate(this->m_numAlloc*2);

		this->m_array[this->m_numInArray++] = in;
	};

	const T& GetItem(const unsigned int pos)
	{
		if((pos =< this->m_numInArray) && (pos =< this->m_numAlloc))
			return this->m_array[pos];
	};

	unsigned int GetSize(void)
	{
		return (unsigned int)this->m_numInArray;
	};

	int Search(const T& item)
	{
		for (size_t i = 0; i < GetSize(); i++)
		{
			if (m_array[i] == item)
				return i;
		}

		return -1;
	};

	bool IsInList(const T& item)
	{
		for (size_t i = 0; i < GetSize(); i++)
		{
			if (m_array[i] == item)
				return true;
		}

		return false;
	};
};

/** List class wrapper
* @attention: The classes zCList, zCArray, zCListSort, zCArraySort, zCTree, etc. are not intended for regular usage. Please use the STL equivalents for your coding!
*/
template<class T>
class zCList
{
protected:
	T*  data;
	zCList<T>* next;
public:
	zCList()
	{
		this->data = NULL;
		this->next = NULL;		
	};

	zCList(T* p)
	{
		this->data = p;
		this->next = NULL;
	};

	~zCList()
	{
		G2EXT_DELETE(this->next);
	};

	inline bool IsInList(T* p) 
	{
		if(this->data == p)
		{
			return true;
		};

		if(!next)
		{
			return false;
		};

		return next->IsInList(p);
	};

	inline void Insert(T* p)
	{
		if(!next)
		{
			next = new zCList(p);
		}
		else
		{
			next->Insert(p);
		};
	};

	inline const T* Get(UINT idx)
	{
		zCList<T>* temp = this;
		UINT i = 0;

		while((temp = temp->next) != NULL)
		{
			if(i == idx) return temp->data;
			i++;
		};

		return NULL;
	};

	inline zCList<T>* GetNext() { return this->next; };

	inline T* GetData() { return this->data; };

	inline UINT GetSize()
	{
		UINT i = 0;

		while((temp = temp->next) != NULL)
		{
			if(i == idx) return temp->data;
			i++;
		};

		return i;
	};

	inline void SetData(T* p)
	{
		this->data = p;
	};
};

/** Sorted array class wrapper
* @attention: The classes zCList, zCArray, zCListSort, zCArraySort, zCTree, etc. are not intended for regular usage. Please use the STL equivalents for your coding!
*/
template<class T>
class zCArraySort
{
protected:
	T*				array;
	int				numAlloc;
	int				numInArray;
	int(*compare)(T *ele1,T *ele2);
};

/** Sorted list class wrapper
* @attention: The classes zCList, zCArray, zCListSort, zCArraySort, zCTree, etc. are not intended for regular usage. Please use the STL equivalents for your coding!
*/
template<class T>
class zCListSort
{
protected:
	int(*compare)(T *ele1,T *ele2);
	T*				data;
	zCListSort<T>*	next;
private:
	inline void _Insert(T* p, void* cmp) // Keep eventual compare function!
	{
		if(!next)
		{
			next = new zCListSort(p);
			next->compare = cmp;
		}
		else
		{
			next->_Insert(p, cmp);
		};
	};
public:
	zCListSort()
	{
		this->data = NULL;
		this->next = NULL;		
	};

	zCListSort(T* p)
	{
		this->data = p;
		this->next = NULL;
	};

	~zCListSort()
	{
		G2EXT_DELETE(this->next);
	};

	inline bool IsInList(T* p) 
	{
		if(this->data == p)
		{
			return true;
		};

		if(!next)
		{
			return false;
		};

		return next->IsInList(p);
	};

	inline void Insert(T* p)
	{
		next->_Insert(p, this->compare);
	};

	inline const T* Get(UINT idx)
	{
		zCListSort<T>* temp = this;
		UINT i = 0;

		while((temp = temp->next) != NULL)
		{
			if(i == idx) return temp->data;
			i++;
		};

		return NULL;
	};

	inline zCListSort<T>* GetNext() { return this->next; };

	inline T* GetData() { return this->data; };

	inline UINT GetSize()
	{
		UINT i = 0;

		while((temp = temp->next) != NULL)
		{
			if(i == idx) return temp->data;
			i++;
		};

		return i;
	};

	inline void SetData(T* p)
	{
		this->data = p;
	};

	inline void SetCompareFunction(int(*cmp)(T*, T*))
	{
		this->compare = cmp;
	};
};

/** Tree
* @attention: The classes zCList, zCArray, zCListSort, zCArraySort, zCTree, etc. are not intended for regular usage. Please use the STL equivalents for your coding!
*/
template<class T>
class zCTree
{
	zCTree<T>*	parent;
	zCTree<T>*	firstChild;
	zCTree<T>*	next;
	zCTree<T>*	prev;
	T*			data;
};

/** ZenGin color type 
* @note: The ZenGin uses a BGRA colour type! (Don't mix it up with RGBA!)
*
*/
class zCOLOR
{
public:
	union {
		struct {
			BYTE	b;
			BYTE	g;
			BYTE	r;
			BYTE	a;
		};
		DWORD color;
	};

	// -- constructors
	zCOLOR();
	zCOLOR(zBYTE _r, zBYTE _g, zBYTE _b); // RGB
	zCOLOR(zBYTE _r, zBYTE _g, zBYTE _b, zBYTE _a); // RGBA
	zCOLOR(zDWORD _color); // BGRA

	// -- functions
	void Clear();
	void SetRGBA(BYTE _r, BYTE _g, BYTE _b, BYTE _a);
	void SetBGRA(BYTE _b, BYTE _g, BYTE _r, BYTE _a);

	void SetR(BYTE _c);
	void SetG(BYTE _c);
	void SetB(BYTE _c);
	void SetA(BYTE _c);

	BYTE GetR(void);
	BYTE GetG(void);
	BYTE GetB(void);
	BYTE GetA(void);
};

#include "ztypes.inl"

#include "api/spacer/zstring.h"
#include "api/spacer/zcobject.h"

#undef __G2EXT_API_HEADER

#endif // __API_SPACER_ZTYPES_H__