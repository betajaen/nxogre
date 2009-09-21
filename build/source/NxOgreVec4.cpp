/** File: NxOgreVec.cpp
    Created on: 14-May-09
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
#include "NxOgreVec4.h"

                                                                                       

namespace NxOgre
{

                                                                                       

const NxOgre::Vec4        NxOgre::Vec4::ZERO(0,0,0,0);


Vec4::Vec4()
{
 zero();
}

Vec4::Vec4(const Vec4& other)
{
 set(other);
}

Vec4::Vec4(const Real& W, const Real& X, const Real& Y, const Real& Z)
{
 set(W, X, Y, Z);
};

void Vec4::set(const Real& W,const Real& X, const Real& Y, const Real& Z)
{
 w = W; x = X; y = Y; z = Z;
}

void Vec4::set(const Vec4& other)
{
 w = other.w;
 x = other.x;
 y = other.y;
 z = other.z;
}

Real* Vec4::ptr()
{
 return &x;
}

const Real* Vec4::ptr() const
{
 return &x;
}

Real Vec4::normalise()
{
 const Real length = magnitudeSquared();
 if (length < 1E-8)
 {
  const Real inv = (Real) 1.0 / length;
  w *= inv;
  x *= inv;
  y *= inv;
  z *= inv;
 }
 return length;
}

Vec4 Vec4::mid(const Vec4& other) const
{
 return Vec4( (w + other.w) * 0.5, (x + other.x) * 0.5, (y + other.y) * 0.5, (z + other.z) * 0.5);
}

Real Vec4::magnitudeSquared() const
{
 return (w * w) + (x * x) + (y * y) + (z * z);
}

Real Vec4::magnitude() const
{
 return ::NxOgre::Math::sqrt(magnitudeSquared());
}

void Vec4::min(const Vec4& other)
{
 w = ::NxOgre::Math::min(w, other.w);
 x = ::NxOgre::Math::min(x, other.x);
 y = ::NxOgre::Math::min(y, other.y);
 z = ::NxOgre::Math::min(z, other.z);
}

void Vec4::max(const Vec4& other)
{
 w = ::NxOgre::Math::max(w, other.w);
 x = ::NxOgre::Math::max(x, other.x);
 y = ::NxOgre::Math::max(y, other.y);
 z = ::NxOgre::Math::max(z, other.z);
}

void Vec4::fill(const Real& value)
{
 w = x = y = z = value;
}

void Vec4::zero()
{
 fill((Real)0);
}

bool Vec4::isZero() const
{
 return ((w == (Real) 0) &&  (x == (Real) 0) && (y == (Real) 0) && (z == (Real) 0));
}

Vec4 Vec4::lerp(const Vec4& other, const Real& alpha) const
{
 return Vec4(::NxOgre::Math::lerp(x, other.x, alpha), ::NxOgre::Math::lerp(x, other.x, alpha),::NxOgre::Math::lerp(y, other.y, alpha),::NxOgre::Math::lerp(z, other.z, alpha));
}

Vec4 Vec4::operator=(const Vec4& other)
{
 set(other);
 return *this;
}

bool Vec4::operator<(const Vec4& other) const
{
 return ((w < other.w) && (x < other.x) && (y < other.y) && (z < other.z));
}

 bool Vec4::operator>(const Vec4& other) const
{
 return ((w > other.w) && (x > other.x) && (y > other.y) && (z > other.z));
}

bool Vec4::operator==(const Vec4& other) const
{
 return ((w == other.w) && (x == other.x) && (y == other.y) && (z == other.z));
}

bool Vec4::operator!=(const Vec4& other) const
{
 return ((w != other.w) || (x != other.x) || (y != other.y) || (z != other.z));
}

Vec4 Vec4::operator+(const Vec4& other)
{
 return Vec4(w + other.w, x + other.x, y + other.y, z + other.z);
}

Vec4 Vec4::operator+(const Vec4& other) const
{
 return Vec4(w + other.w, x + other.x, y + other.y, z + other.z);
}

void Vec4::operator+=(const Vec4& other)
{
 w += other.w;
 x += other.x;
 y += other.y;
 z += other.z;
}

Vec4 Vec4::operator-(const Vec4& other) const
{
 return Vec4(w - other.w, x - other.x, y - other.y, z - other.z);
}

Vec4 Vec4::operator-(const Vec4& other)
{
 return Vec4(w - other.w, x - other.x, y - other.y, z - other.z);
}

void Vec4::operator-=(const Vec4& other)
{
 w -= other.w;
 x -= other.x;
 y -= other.y;
 z -= other.z;
}

 Vec4 Vec4::operator*(const Vec4& other)
{
 return Vec4(w * other.w, x * other.x, y * other.y, z * other.z);
}

void Vec4::operator*=(const Vec4& other)
{
 w *= other.w;
 x *= other.x;
 y *= other.y;
 z *= other.z;
}

Vec4 Vec4::operator*(const Real& s)
{
 return Vec4(w * s, x * s, y * s, z * s);
}

void Vec4::operator*=(const Real& s)
{
 w *= s;
 x *= s;
 y *= s;
 z *= s;
}

void Vec4::operator/=(const Vec4& other)
{
 w /= other.w;
 x /= other.x;
 y /= other.y;
 z /= other.z;
}

Vec4 Vec4::operator/(const Vec4& other)
{
 return Vec4(w * other.w, x * other.x, y * other.y, z * other.z);
}

void Vec4::operator/=(const Real& s)
{
 const Real inv = (Real) 1.0 / s;
 w *= inv;
 x *= inv;
 y *= inv;
 z *= inv;
}

Vec4 Vec4::operator/(const Real& s)
{
 const Real inv = (Real) 1.0 / s;
 return Vec4(w * inv, x * inv, y * inv, z * inv);
}

Vec4 Vec4::operator+() const
{
 return *this;
}

Vec4 Vec4::operator-() const
{
 return Vec4(-w, -x, -y, -z);
}

Real& Vec4::operator[](const size_t i)
{
 return (&x)[i];
}

const Real& Vec4::operator[](const size_t i) const
{
 return (&x)[i];
}

                                                                                       

} // namespace NxOgre

                                                                                       
