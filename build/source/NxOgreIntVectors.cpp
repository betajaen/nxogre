/** 
    
    This file is part of NxOgre.
    
    Copyright (c) 2009 Robin Southern, http://www.nxogre.org
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
    
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

                                                                                       
