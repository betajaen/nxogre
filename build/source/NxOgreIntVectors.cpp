/** File: NxOgreIntVectors.cpp
    Created on: 15-Apr-09
    Author: Robin Southern "betajaen"
    

    © Copyright, 2008-2009 by Robin Southern, http://www.nxogre.org

    This file is part of NxOgre.

    NxOgre is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    NxOgre is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with NxOgre.  If not, see <http://www.gnu.org/licenses/>.
*/

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreIntVectors.h"

                                                                                       

namespace NxOgre
{

                                                                                       

int2::int2(void)
: x(0), y(0)
{
}

int2::int2(int _x, int _y)
: x(_x), y(_y)
{
}

int2::~int2(void)
{
}

void int2::operator+=(const int2& other)
{
 x += other.x;
 y += other.y;
}

void int2::operator-=(const int2& other)
{
 x -= other.x;
 y -= other.y;
}

void int2::operator*=(const int2& other)
{
 x *= other.x;
 y *= other.y;
}

void int2::operator/=(const int2& other)
{
 x /= other.x;
 y /= other.y;
}

void int2::operator*=(int r)
{
 x *= r;
 y *= r;
}

int3::int3(void)
: x(0), y(0), z(0)
{
}

int3::int3(int _x, int _y, int _z)
: x(_x), y(_y), z(_z)
{
}

int3::~int3(void)
{
}

void int3::operator+=(const int3& other)
{
 x += other.x;
 y += other.y;
 z += other.z;
}

void int3::operator-=(const int3& other)
{
 x -= other.x;
 y -= other.y;
 z -= other.z;
}

void int3::operator*=(const int3& other)
{
 x *= other.x;
 y *= other.y;
 z *= other.z;
}

void int3::operator/=(const int3& other)
{
 x /= other.x;
 y /= other.y;
 z /= other.z;
}

void int3::operator*=(int r)
{
 x *= r;
 y *= r;
 z *= r;
}

int4::int4(void) : w(0), x(0), y(0), z(0)
{
}

int4::int4(int _w, int _x, int _y, int _z) : w(_w), x(_x), y(_y), z(_z)
{
}

int4::~int4(void)
{
}

void int4::operator+=(const int4& other)
{
 w += other.w;
 x += other.x;
 y += other.y;
 z += other.z;
}

void int4::operator-=(const int4& other)
{
 w -= other.w;
 x -= other.x;
 y -= other.y;
 z -= other.z;
}

void int4::operator*=(const int4& other)
{
 w *= other.w;
 x *= other.x;
 y *= other.y;
 z *= other.z;
}

void int4::operator/=(const int4& other)
{
 w /= other.w;
 x /= other.x;
 y /= other.y;
 z /= other.z;
}

void int4::operator*=(int r)
{
 w *= r;
 x *= r;
 y *= r;
 z *= r;
}

                                                                                       

} // namespace NxOgre

                                                                                       
