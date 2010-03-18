/////////////////////////////////////////////////////////
// G2Ext © 2009 by PainDevs
// Developed by Christoffer Anselm and Patrick Vogel
// All rights reserved.
//

#ifndef __EX_ARRAY_H_INCLUDED__
#define __EX_ARRAY_H_INCLUDED__

#include "common/osheader.h"

#include "api/g2/zcparser.h"

#include <vector>
#include <map>

using namespace std;

namespace externals
{
	int iadim(void);
	int iaredim(void);
	int iafree(void);
	int iaget(void);
	int iaset(void);
};

class ex_int_array
{
public:
	ex_int_array(const vector<uint32_t>& dimensions)
		: m_dimensions(dimensions), m_data(0)
	{
		redim(dimensions);
	};

	bool redim(const vector<uint32_t>& dimensions);

	int  getElement(const vector<uint32_t>& coords) const;
	bool setElement(const vector<uint32_t>& coords, int val);

	size_t getDimensionCount() const;

private:
	int calcIdx(const vector<uint32_t>& coords) const;

	vector<uint32_t>	m_dimensions;
	vector<int>			m_data;

public:
	static int create(const vector<uint32_t>& dimensions)
	{
		// check for invalid dimensions
		for (size_t i = 0; i < dimensions.size(); i++)
		{
			if (dimensions[i] < 0)
				return -1;
		}

		// generate new handle
		s_lastHandle++;

		// if overflow than reset to 0
		if (s_lastHandle < 0)
			s_lastHandle = 0;

		// check if array with current handle exists
		map<uint32_t, ex_int_array>::iterator it = s_arrays.find(s_lastHandle);

		// if so search for an available handle
		while (it != s_arrays.end() && it->first == s_lastHandle)
		{
			s_lastHandle++;
			it++;
		}

		if (it == s_arrays.end())
			s_lastHandle++;

		if (s_lastHandle < 0)
			return -1;

		s_arrays.insert(pair<uint32_t, ex_int_array>(s_lastHandle, ex_int_array(dimensions)));

		return s_lastHandle;
	};

	static ex_int_array* get(int hArray)
	{
		map<uint32_t, ex_int_array>::iterator it = s_arrays.find(hArray);

		if (it != s_arrays.end())
			return &it->second;
		else
			return NULL;
	};

	static void free(int hArray)
	{
		s_arrays.erase(hArray);
	};

private:
	static map<uint32_t, ex_int_array>	s_arrays;
	// don't need to init last handle value - every starting value will be fine
	static int							s_lastHandle;
};


#endif __EX_ARRAY_H_INCLUDED__