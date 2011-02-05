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

#ifndef __ZCONTAINERS_H_INCLUDED__
#define __ZCONTAINERS_H_INCLUDED__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "common/osheader.h"

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
	/** Insert description. 
	*/
	zCArray()
	{
		this->m_array		= NULL;
		this->m_numAlloc	= 0;
		this->m_numInArray	= 0;
	};

	/** Insert description. 
	*/
	~zCArray()
	{
		this->Clear();
	};

	/** Insert description. 
	*/
	const T& operator [] (const unsigned int pos) const
	{
		if((int)pos <= this->m_numInArray)
			return this->m_array[pos];
	};

	/** Insert description. 
	*/
	T& operator [] (const unsigned int pos)
	{
		if((int)pos <= this->m_numInArray)
			return this->m_array[pos];
	};

	/** Insert description. 
	*/
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

	/** Insert description. 
	*/
	const T& GetItem(const unsigned int pos)
	{
		if((pos <= this->m_numInArray) && (pos <= this->m_numAlloc))
			return this->m_array[pos];
	};

	/** Insert description. 
	*/
	unsigned int GetSize(void)
	{
		return (unsigned int)this->m_numInArray;
	};

	/** Insert description. 
	*/
	int Search(const T& item)
	{
		for (size_t i = 0; i < GetSize(); i++)
		{
			if (m_array[i] == item)
				return i;
		}

		return -1;
	};

	/** Insert description. 
	*/
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
	/** Insert description. 
	*/
	zCList()
	{
		this->data = NULL;
		this->next = NULL;		
	};

	/** Insert description. 
	*/
	zCList(T* p)
	{
		this->data = p;
		this->next = NULL;
	};

	/** Insert description. 
	*/
	~zCList()
	{
		G2EXT_DELETE(this->next);
	};

	/** Insert description. 
	*/
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

	/** Insert description. 
	*/
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

	/** Insert description. 
	*/
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

	/** Insert description. 
	*/
	inline zCList<T>* GetNext() { return this->next; };

	/** Insert description. 
	*/
	inline T* GetData() { return this->data; };

	/** Insert description. 
	*/
	inline UINT GetSize()
	{
		zCList<T>* temp = this;
		UINT i = 0;

		while((temp = temp->next) != NULL)
		{
			if(i == idx) return temp->data;
			i++;
		};

		return i;
	};

	/** Insert description. 
	*/
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
	/** Insert description. 
	*/
	T& operator [](int idx)
	{
		return *this->Get(idx);
	};
public:
	/** Insert description. 
	*/
	zCListSort()
	{
		this->data = NULL;
		this->next = NULL;		
	};

	/** Insert description. 
	*/
	zCListSort(T* p)
	{
		this->data = p;
		this->next = NULL;
	};

	/** Insert description. 
	*/
	~zCListSort()
	{
		G2EXT_DELETE(this->next);
	};

	/** Insert description. 
	*/
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

	/** Insert description. 
	*/
	inline void Insert(T* p)
	{
		next->_Insert(p, this->compare);
	};

	/** Insert description. 
	*/
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

	/** Insert description. 
	*/
	inline zCListSort<T>* GetNext() { return this->next; };

	/** Insert description. 
	*/
	inline T* GetData() { return this->data; };

	/** Insert description. 
	*/
	inline UINT GetSize()
	{
		zCListSort<T>* temp = this;
		UINT i = 0;

		while((temp = temp->next) != NULL)
		{
			i++;
		};

		return i;
	};

	/** Insert description. 
	*/
	inline void SetData(T* p)
	{
		this->data = p;
	};

	/** Insert description. 
	*/
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

#undef __G2EXT_API_HEADER

#endif // __ZTYPES_H_INCLUDED__