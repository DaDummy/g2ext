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

#ifndef __ZMATH_H_INCLUDED__
#define __ZMATH_H_INCLUDED__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "common/osheader.h"

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
	/** Insert description. 
	*/
	zVEC2();

	/** Insert description. 
	*/
	zVEC2( float _x, float _y );

	/** Insert description. 
	*/
	zVEC2( const float* pf );

	/** Insert description. 
	*/
	zVEC2( const zVEC2& v );

	// -- functions
	/** Insert description. 
	*/
	void Clear();

	/** Insert description. 
	*/
	void Set( float _x, float _y );

	// -- casts
	/** Insert description. 
	*/
	operator float* ();

	/** Insert description. 
	*/
	operator const float* ();

	// -- assignment operators
	/** Insert description. 
	*/
	zVEC2& operator += ( const zVEC2 & v );

	/** Insert description. 
	*/
	zVEC2& operator -= ( const zVEC2 & v );

	/** Insert description. 
	*/
	zVEC2& operator *= ( float f );

	/** Insert description. 
	*/
	zVEC2& operator /= ( float f );

	// -- unary operators
	/** Insert description. 
	*/
	zVEC2  operator + () const;

	/** Insert description. 
	*/
	zVEC2  operator - () const;

	// -- binary operators
	/** Insert description. 
	*/
	zVEC2  operator + ( const zVEC2& v ) const;

	/** Insert description. 
	*/
	zVEC2  operator - ( const zVEC2& v ) const;

	/** Insert description. 
	*/
	zVEC2  operator * ( float f ) const;

	/** Insert description. 
	*/
	zVEC2  operator / ( float f ) const;

	// -- logical operators
	/** Insert description. 
	*/
	bool operator == ( const zVEC2& v ) const;
	/** Insert description. 
	*/
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
	/** Insert description. 
	*/
	zVEC3();

	/** Insert description. 
	*/
	zVEC3( float _x, float _y, float _z );

	/** Insert description. 
	*/
	zVEC3( const float* pf );

	/** Insert description. 
	*/
	zVEC3( const zVEC3& v );

	// -- functions
	/** Insert description. 
	*/
	inline void Clear();

	/** Insert description. 
	*/
	inline void Set( float _x, float _y, float _z );

	// -- casts
	/** Insert description. 
	*/
	operator float* ();

	/** Insert description. 
	*/
	operator const float* ();

	// -- assignment operators
	/** Insert description. 
	*/
	zVEC3& operator += ( const zVEC3 & v );

	/** Insert description. 
	*/
	zVEC3& operator -= ( const zVEC3 & v );

	/** Insert description. 
	*/
	zVEC3& operator *= ( float f );

	/** Insert description. 
	*/
	zVEC3& operator /= ( float f );

	// -- unary operators
	/** Insert description. 
	*/
	zVEC3  operator + () const;

	/** Insert description. 
	*/
	zVEC3  operator - () const;

	// -- binary operators
	/** Insert description. 
	*/
	zVEC3  operator + ( const zVEC3& v ) const;

	/** Insert description. 
	*/
	zVEC3  operator - ( const zVEC3& v ) const;

	/** Insert description. 
	*/
	zVEC3  operator * ( float f ) const;

	/** Insert description. 
	*/
	zVEC3  operator / ( float f ) const;

	// -- logical operators
	/** Insert description. 
	*/
	bool operator == ( const zVEC3& v ) const;
	/** Insert description. 
	*/
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
	/** Insert description. 
	*/
	zVEC4();

	/** Insert description. 
	*/
	zVEC4( float _x, float _y, float _z, float _w );

	/** Insert description. 
	*/
	zVEC4( const float* pf );

	/** Insert description. 
	*/
	zVEC4( const zVEC4& v );

	// -- functions
	/** Insert description. 
	*/
	inline void Clear();

	/** Insert description. 
	*/
	inline void Set( float _x, float _y, float _z, float _w );

	// -- casts
	/** Insert description. 
	*/
	operator float* ();

	/** Insert description. 
	*/
	operator const float* ();

	// -- assignment operators
	/** Insert description. 
	*/
	zVEC4& operator += ( const zVEC4 & v );

	/** Insert description. 
	*/
	zVEC4& operator -= ( const zVEC4 & v );

	/** Insert description. 
	*/
	zVEC4& operator *= ( float f );

	/** Insert description. 
	*/
	zVEC4& operator /= ( float f );

	// -- unary operators
	/** Insert description. 
	*/
	zVEC4  operator + () const;

	/** Insert description. 
	*/
	zVEC4  operator - () const;

	// -- binary operators
	/** Insert description. 
	*/
	zVEC4  operator + ( const zVEC4& v ) const;

	/** Insert description. 
	*/
	zVEC4  operator - ( const zVEC4& v ) const;

	/** Insert description. 
	*/
	zVEC4  operator * ( float f ) const;

	/** Insert description. 
	*/
	zVEC4  operator / ( float f ) const;

	// -- logical operators
	/** Insert description. 
	*/
	bool operator == ( const zVEC4& v ) const;
	/** Insert description. 
	*/
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

	/** Insert description. 
	*/
	zMAT3() {};

	/** Insert description. 
	*/
	zMAT3( const zMAT3 & _m );

	/** Insert description. 
	*/
	zMAT3(float f11, float f12, float f13, float f14,
		float f21, float f22, float f23, float f24,
		float f31, float f32, float f33, float f34);

	//  -- assignment operators
	/** Insert description. 
	*/
	zMAT3& operator *= ( const zMAT3 & _m );

	/** Insert description. 
	*/
	zMAT3& operator /= ( const zMAT3 & _m );

	/** Insert description. 
	*/
	zMAT3& operator += ( const zMAT3 & _m );

	/** Insert description. 
	*/
	zMAT3& operator -= ( const zMAT3 & _m );

	/** Insert description. 
	*/
	zMAT3& operator *= ( float f );
	/** Insert description. 
	*/
	zMAT3& operator /= ( float f );

	// -- unary operators
	/** Insert description. 
	*/
	zMAT3  operator + () const;

	/** Insert description. 
	*/
	zMAT3  operator - () const;

	// -- binary operators
	/** Insert description. 
	*/
	zMAT3 operator * ( const zMAT3 & _m );

	/** Insert description. 
	*/
	zMAT3 operator / ( const zMAT3 & _m );

	/** Insert description. 
	*/
	zMAT3 operator + ( const zMAT3 & _m );

	/** Insert description. 
	*/
	zMAT3 operator - ( const zMAT3 & _m );

	/** Insert description. 
	*/
	zMAT3 operator * ( float f );

	/** Insert description. 
	*/
	zMAT3 operator / ( float f );

	// -- logical operators
	/** Insert description. 
	*/
	bool operator == ( const zMAT3 & _m ) const;

	/** Insert description. 
	*/
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

	/** Insert description. 
	*/
	zMAT4() {};

	/** Insert description. 
	*/
	zMAT4( const zMAT4 & _m );

	/** Insert description. 
	*/
	zMAT4( float f11, float f12, float f13, float f14,
		float f21, float f22, float f23, float f24,
		float f31, float f32, float f33, float f34,
		float f41, float f42, float f43, float f44 );

	//  -- assignment operators
	/** Insert description. 
	*/
	zMAT4& operator *= ( const zMAT4 & _m );

	/** Insert description. 
	*/
	zMAT4& operator /= ( const zMAT4 & _m );

	/** Insert description. 
	*/
	zMAT4& operator += ( const zMAT4 & _m );

	/** Insert description. 
	*/
	zMAT4& operator -= ( const zMAT4 & _m );

	/** Insert description. 
	*/
	zMAT4& operator *= ( float f );

	/** Insert description. 
	*/
	zMAT4& operator /= ( float f );

	// -- unary operators
	/** Insert description. 
	*/
	zMAT4  operator + () const;
	/** Insert description. 
	*/
	zMAT4  operator - () const;

	// -- binary operators
	/** Insert description. 
	*/
	zMAT4 operator * ( const zMAT4 & _m );

	/** Insert description. 
	*/
	zMAT4 operator / ( const zMAT4 & _m );

	/** Insert description. 
	*/
	zMAT4 operator + ( const zMAT4 & _m );

	/** Insert description. 
	*/
	zMAT4 operator - ( const zMAT4 & _m );

	/** Insert description. 
	*/
	zMAT4 operator * ( float f );

	/** Insert description. 
	*/
	zMAT4 operator / ( float f );

	// -- logical operators
	/** Insert description. 
	*/
	bool operator == ( const zMAT4 & _m ) const;

	/** Insert description. 
	*/
	bool operator != ( const zMAT4 & _m ) const;
};

/** Insert description. */
struct zTBBox3D 
{
	zVEC3 min;
	zVEC3 max;
};

/** Insert description. */
struct zTBSphere3D 
{
	zVEC3 center;
	float radius;
};

/** Insert description. */
struct zCQuat
{
	float w, x, y, z;
};

#include "api/g2/zmath.inl"

#undef __G2EXT_API_HEADER

#endif // __ZMATH_H_INCLUDED__