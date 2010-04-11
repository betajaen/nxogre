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

String Vec2::to_s() const
{
 std::ostringstream ss;
 ss << x << " " << y;
 return ss.str();
}

std::vector<Real> Vec2::to_a() const
{
 std::vector<Real> a;
 a.push_back(x);
 a.push_back(y);
 return a;
}

                                                                                       

} // namespace NxOgre

                                                                                       
