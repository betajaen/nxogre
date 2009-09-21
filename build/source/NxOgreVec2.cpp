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
#include "NxOgreVec2.h"

                                                                                       

namespace NxOgre
{

const NxOgre::Vec2        NxOgre::Vec2::ZERO(0,0);

Vec2::Vec2()
{
 zero();
}

Vec2::Vec2(const Vec2& other)
{
 set(other);
}

Vec2::Vec2(const Real& X, const Real& Y)
{
 set(X, Y);
};

void Vec2::set(const Real& X, const Real& Y)
{
 x = X; y = Y;
}

void Vec2::set(const Vec2& other)
{
 x = other.x;
 y = other.y;
}

Real* Vec2::ptr()
{
 return &x;
}

const Real* Vec2::ptr() const
{
 return &x;
}

Real Vec2::normalise()
{
 const Real length = magnitudeSquared();
 if (length < 1E-8)
 {
  const Real inv = (Real) 1.0 / length;
  x *= inv;
  y *= inv;
 }
 return length;
}

Vec2 Vec2::mid(const Vec2& other) const
{
 return Vec2((x + other.x) * 0.5, (y + other.y) * 0.5);
}

Real Vec2::dot(const Vec2& other) const
{
 return (x * other.x) + (y * other.y);
}

Real Vec2::cross(const Vec2& other)
{
 return (x * other.y) - (y * other.x);
}

Real Vec2::magnitudeSquared() const
{
 return (x * x) + (y * y);
}

Real Vec2::magnitude() const
{
 return ::NxOgre::Math::sqrt(magnitudeSquared());
}

void Vec2::min(const Vec2& other)
{
 x = ::NxOgre::Math::min(x, other.x);
 y = ::NxOgre::Math::min(y, other.y);
}

void Vec2::max(const Vec2& other)
{
 x = ::NxOgre::Math::max(x, other.x);
 y = ::NxOgre::Math::max(y, other.y);
}

void Vec2::fill(const Real& value)
{
 x = y = value;
}

void Vec2::zero()
{
 fill((Real)0);
}

bool Vec2::isZero() const
{
 return ((x == (Real) 0) && (y == (Real) 0));
}

Vec2 Vec2::lerp(const Vec2& other, const Real& alpha) const
{
 return Vec2(::NxOgre::Math::lerp(x, other.x, alpha),::NxOgre::Math::lerp(y, other.y, alpha));
}

Vec2 Vec2::operator=(const Vec2& other)
{
 set(other);
 return *this;
}

bool Vec2::operator<=(const Vec2& other) const
{
 return ((x <= other.x) && (y <= other.y));
}

bool Vec2::operator>=(const Vec2& other) const
{
 return ((x >= other.x) && (y >= other.y));
}

bool Vec2::operator<(const Vec2& other) const
{
 return ((x < other.x) && (y < other.y));
}

bool Vec2::operator>(const Vec2& other) const
{
 return ((x > other.x) && (y > other.y));
}

bool Vec2::operator==(const Vec2& other) const
{
 return ((x == other.x) && (y == other.y));
}

bool Vec2::operator!=(const Vec2& other) const
{
 return ((x != other.x) || (y != other.y));
}

Vec2 Vec2::operator+(const Vec2& other)
{
 return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator+(const Vec2& other) const
{
 return Vec2(x + other.x, y + other.y);
}

void Vec2::operator+=(const Vec2& other)
{
 x += other.x;
 y += other.y;
}

Vec2 Vec2::operator-(const Vec2& other)
{
 return Vec2(x - other.x, y - other.y);
}

Vec2 Vec2::operator-(const Vec2& other) const
{
 return Vec2(x - other.x, y - other.y);
}

void Vec2::operator-=(const Vec2& other)
{
 x -= other.x;
 y -= other.y;
}

Vec2 Vec2::operator*(const Vec2& other)
{
 return Vec2(x * other.x, y * other.y);
}

void Vec2::operator*=(const Vec2& other)
{
 x *= other.x;
 y *= other.y;
}

Vec2 Vec2::operator*(const Real& s)
{
 return Vec2(x * s, y * s);
}

void Vec2::operator*=(const Real& s)
{
 x *= s;
 y *= s;
}

void Vec2::operator/=(const Vec2& other)
{
 x /= other.x;
 y /= other.y;
}

Vec2 Vec2::operator/(const Vec2& other)
{
 return Vec2(x * other.x, y * other.y);
}

void Vec2::operator/=(const Real& s)
{
 const Real inv = (Real) 1.0 / s;
 x *= inv;
 y *= inv;
}

Vec2 Vec2::operator/(const Real& s)
{
 const Real inv = (Real) 1.0 / s;
 return Vec2(x * inv, y * inv);
}

Vec2 Vec2::operator+() const
{
 return *this;
}

Vec2 Vec2::operator-() const
{
 return Vec2(-x, -y);
}

Real& Vec2::operator[](const size_t i)
{
 return (&x)[i];
}

const Real& Vec2::operator[](const size_t i) const
{
 return (&x)[i];
}

                                                                                       

} // namespace NxOgre

                                                                                       
