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

#include "common/osheader.h"
#include "ex_ieeefloat.h"
#include "softfloat.h"
#include "api/g2/zcparser.h"

int externals::fmk(void)
{
	int par1 = 0;
	zCParser::GetParser()->GetParameter(par1);
	zCParser::GetParser()->SetReturn((int)int32_to_float32(par1));
	return false;
};

int externals::ftoi(void)
{
	int par1 = 0;
	zCParser::GetParser()->GetParameter(par1);
	zCParser::GetParser()->SetReturn((int)float32_to_int32(par1));
	return false;
};

int externals::fadd(void) 
{
	int par1 = 0;
	zCParser::GetParser()->GetParameter(par1);
	int par2 = 0;
	zCParser::GetParser()->GetParameter(par2);
	zCParser::GetParser()->SetReturn((int)float32_add(par1,par2));
	return false;
};

int externals::fsub(void) 
{
	int par1 = 0;
	zCParser::GetParser()->GetParameter(par1);
	int par2 = 0;
	zCParser::GetParser()->GetParameter(par2);
	zCParser::GetParser()->SetReturn((int)float32_sub(par1,par2));
	return false;
};

int externals::fmul(void) 
{
	int par1 = 0;
	zCParser::GetParser()->GetParameter(par1);
	int par2 = 0;
	zCParser::GetParser()->GetParameter(par2);
	zCParser::GetParser()->SetReturn((int)float32_mul(par1,par2));
	return false;
};

int externals::fdiv(void) 
{
	int par1 = 0;
	zCParser::GetParser()->GetParameter(par1);
	int par2 = 0;
	zCParser::GetParser()->GetParameter(par2);
	zCParser::GetParser()->SetReturn((int)float32_div(par1,par2));
	return false;
};

int externals::frem(void) 
{
	int par1 = 0;
	zCParser::GetParser()->GetParameter(par1);
	int par2 = 0;
	zCParser::GetParser()->GetParameter(par2);
	zCParser::GetParser()->SetReturn((int)float32_rem(par1,par2));
	return false;
};

int externals::fsqrt(void) 
{
	int par1 = 0;
	zCParser::GetParser()->GetParameter(par1);
	zCParser::GetParser()->SetReturn((int)float32_sqrt(par1));


	return false;
};

int externals::frnd(void) 
{
	int par1 = 0;
	zCParser::GetParser()->GetParameter(par1);
	zCParser::GetParser()->SetReturn((int)float32_round_to_int(par1));
	return false;
};

int externals::feq(void) 
{
	int par1 = 0;
	zCParser::GetParser()->GetParameter(par1);
	int par2 = 0;
	zCParser::GetParser()->GetParameter(par2);
	zCParser::GetParser()->SetReturn((int)float32_eq(par1,par2));
	return false;
};

int externals::fle(void) 
{
	int par1 = 0;
	zCParser::GetParser()->GetParameter(par1);
	int par2 = 0;
	zCParser::GetParser()->GetParameter(par2);
	zCParser::GetParser()->SetReturn((int)float32_le(par1,par2));
	return false;
};

int externals::flt(void) 
{
	int par1 = 0;
	zCParser::GetParser()->GetParameter(par1);
	int par2 = 0;
	zCParser::GetParser()->GetParameter(par2);
	zCParser::GetParser()->SetReturn((int)float32_lt(par1,par2));
	return false;
};