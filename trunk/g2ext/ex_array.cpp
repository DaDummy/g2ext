/*////////////////////////////////////////////////////////////////////////

This file is part of the G2Ext source code.

//////////////////////////////////////////////////////////////////////////

G2Ext is a fan-made engine SDK for Gothic II TNotR (v2.6).
Copyright (C) 2009, 2010 by Paindevs and Patrick Vogel

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

////////////////////////////////////////////////////////////////////////*/

#include "ex_array.h"

map<uint32_t, ex_int_array>	ex_int_array::s_arrays		= map<uint32_t, ex_int_array>();
int							ex_int_array::s_lastHandle	= 0;

int externals::iadim(void)
{
	zCParser* p = zCParser::GetParser();

	int count = 0;
	p->GetParameter(count);

	if (count > 0)
	{
		vector<uint32_t> dimensions(count);

		for (int i = 0; i < count; i++)
			p->GetParameter((int)dimensions[i]);

		p->SetReturn(ex_int_array::create(dimensions));
	}
	else
	{
		p->SetReturn(-1);
	}

	return false;
};

int externals::iaredim(void)
{
	zCParser* p = zCParser::GetParser();

	int hArray = 0;
	p->GetParameter(hArray);

	ex_int_array* arr = ex_int_array::get(hArray);

	if (arr == NULL)
	{
		p->SetReturn(-1);
		return false;
	}

	vector<uint32_t> dimensions(arr->getDimensionCount());

	for (size_t i = 0; i < arr->getDimensionCount(); i++)
		p->GetParameter((int)dimensions[i]);

	p->SetReturn(arr->redim(dimensions));

	return false;
};

int externals::iafree(void)
{
	zCParser* p = zCParser::GetParser();

	int hArray = 0;
	p->GetParameter(hArray);

	ex_int_array::free(hArray);

	p->SetReturn(0);
	return false;
};

int externals::iaget(void)
{
	zCParser* p = zCParser::GetParser();

	int hArray = 0;
	p->GetParameter(hArray);

	ex_int_array* arr = ex_int_array::get(hArray);

	if (arr == NULL)
	{
		p->SetReturn(-1);
		return false;
	}

	vector<uint32_t> coords(arr->getDimensionCount());

	for (size_t i = 0; i < arr->getDimensionCount(); i++)
		p->GetParameter((int)coords[i]);

	p->SetReturn(arr->getElement(coords));

	return false;
};

int externals::iaset(void)
{
	zCParser* p = zCParser::GetParser();

	int hArray = 0;
	p->GetParameter(hArray);

	ex_int_array* arr = ex_int_array::get(hArray);

	if (arr == NULL)
	{
		p->SetReturn(-1);
		return false;
	}

	vector<uint32_t> coords(arr->getDimensionCount());

	for (size_t i = 0; i < arr->getDimensionCount(); i++)
		p->GetParameter((int)coords[i]);

	int val = 0;

	p->GetParameter(val);

	p->SetReturn(arr->setElement(coords, val));

	return false;
};


bool ex_int_array::redim(const vector<uint32_t>& dimensions)
{
	// number of dimensions can't be changed - check
	if (dimensions.size() != m_dimensions.size())
		return false;

	// only the first dimension is allowed to be changed - check
	for (size_t i = 1; i < m_dimensions.size(); i++)
	{
		if (m_dimensions[i] != dimensions[i])
			return false;
	}

	size_t size = 1;

	for each(uint32_t dim in m_dimensions)
		size *= dim;

	m_data.resize(size);

	return true;
};

int  ex_int_array::getElement(const vector<uint32_t>& coords) const
{
	int pos = calcIdx(coords);

	if (pos < 0)
		return 0;

	return m_data[pos];
}

bool ex_int_array::setElement(const vector<uint32_t>& coords, int val)
{
	int pos = calcIdx(coords);

	if (pos < 0)
		return false;
	
	m_data[pos] = val;

	return true;
};

size_t ex_int_array::getDimensionCount() const
{
	return m_dimensions.size();
};

int ex_int_array::calcIdx(const vector<uint32_t>& coords) const
{
	int res = 0;

	if (m_dimensions[0] <= coords[0])
		return -1;
	else
		res = coords[0];

	if (m_dimensions.size() > 1)
	{
		//Theory: res = (((v1) * s2 + v2) * s3 + v3) * s4 + v4;

		// begin with second element as first was already set
		for (size_t i = 1; i < m_dimensions.size(); i++)
		{
			if (m_dimensions[i] <= coords[i])
				return -1;

			res *= m_dimensions[i];
			res += coords[i];
		}
	}

	return res;
};
