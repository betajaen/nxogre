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
#include "NxOgreVec3.h"
#include "NxOgreMath.h"

                                                                                       

namespace NxOgre
{

                                                                                       

const Vec3        Vec3::ZERO(0, 0, 0);

const Vec3        Vec3::UNIT_X(1, 0, 0);

const Vec3        Vec3::UNIT_Y(0, 1, 0);

const Vec3        Vec3::UNIT_Z(0, 0, 1);

const Vec3        Vec3::NEGATIVE_UNIT_X(-1, 0, 0);

const Vec3        Vec3::NEGATIVE_UNIT_Y( 0,-1, 0);

const Vec3        Vec3::NEGATIVE_UNIT_Z( 0, 0,-1);

const Vec3        Vec3::POSITIVE_1_1_1(1,1,1);

const Vec3        Vec3::NEGATIVE_1_1_1(-1,-1,-1);

Vec3::Vec3()
{
 zero();
}

Vec3::Vec3(const Vec3& other)
{
 set(other);
}

Vec3::Vec3(const Matrix44& other)
{
other.get(x,y,z);
}

Vec3::Vec3(const Real& X, const Real& Y, const Real& Z)
{
 set(X, Y, Z);
};

Vec3::Vec3(const String& str)
{
 std::stringstream s;
 s << Strings::replace_copy(str, ',', ' ');
 s >> x >> y >> z;
}

void Vec3::set(const Real& X, const Real& Y, const Real& Z)
{
 x = X;
 y = Y;
 z = Z;
}

void Vec3::set(const Vec3& other)
{
 x = other.x;
 y = other.y;
 z = other.z;
}

Real* Vec3::ptr()
{
 return &x;
}

const Real* Vec3::ptr() const
{
 return &x;
}

Enums::Axis Vec3::axis() const
{
 if (x != 0)
  return Enums::X;
 else if (y != 0)
  return Enums::Y;
 else if (z != 0)
  return Enums::Z;
 return Enums::NoAxis;
}

Vec3 Vec3::used() const
{
 Vec3 out;
 out.x = x != 0.0f ? 1.0f : 0.0f;
 out.y = y != 0.0f ? 1.0f : 0.0f;
 out.z = z != 0.0f ? 1.0f : 0.0f;
 return out;
}

Real Vec3::normalise()
{
 Real length = magnitude();
 if (length)
 {
  Real inv = (Real) 1.0 / length;
  x *= inv;
  y *= inv;
  z *= inv;
 }
 return length;
}

Vec3 Vec3::normaliseCopy() const
{
 Vec3 copy(x,y,z);
 copy.normalise();
 return copy;
}

Vec3 Vec3::mid(const Vec3& other) const
{
 return Vec3((x + other.x) * 0.5, (y + other.y) * 0.5, (z + other.z) * 0.5);
}

Real Vec3::dot(const Vec3& other) const
{
 return (x * other.x) + (y * other.y) + (z * other.z);
}

Vec3 Vec3::cross(const Vec3& other)
{
 return Vec3(
  y * other.z - z * other.y,
  z * other.x - x * other.z,
  x * other.y - y * other.x
 );
}

Real Vec3::distance(const Vec3& other) const
{
 return Vec3(x - other.x, y - other.y, z - other.z).magnitude();
}

Real Vec3::distanceSquared(const Vec3& other) const
{
 return Vec3(x - other.x, y - other.y, z - other.z).magnitudeSquared();
}

Real Vec3::magnitudeSquared() const
{
 return (x * x) + (y * y) + (z * z);
}

Real Vec3::magnitude() const
{
return NxOgre::Math::sqrt(magnitudeSquared());
}

void Vec3::min(const Vec3& other)
{
 x = ::NxOgre::Math::min(x, other.x);
 y = ::NxOgre::Math::min(y, other.y);
 z = ::NxOgre::Math::min(z, other.z);
}

void Vec3::max(const Vec3& other)
{
 x = ::NxOgre::Math::max(x, other.x);
 y = ::NxOgre::Math::max(y, other.y);
 z = ::NxOgre::Math::max(z, other.z);
}

void Vec3::fill(const Real& value)
{
 x = y = z = value;
}

void Vec3::zero()
{
 fill((Real)0);
}

bool Vec3::isZero() const
{
 return (x == (Real) 0) && (y == (Real) 0) && (z == (Real) 0) ;
}

bool Vec3::isNegative() const
{
 return (x <= (Real) 0) || (y <= (Real) 0) || (z <= (Real) 0) ;
}

Vec3 Vec3::lerp(const Vec3& other, const Real& alpha) const
{
 return Vec3(::NxOgre::Math::lerp(x, other.x, alpha),::NxOgre::Math::lerp(y, other.y, alpha),::NxOgre::Math::lerp(z, other.z, alpha));
}

Vec3 Vec3::operator=(const Vec3& other)
{
 set(other);
 return *this;
}

bool Vec3::operator<(const Vec3& other) const
{
 return ((x < other.x) && (y < other.y) && (z < other.z));
}

bool Vec3::operator<=(const Vec3& other) const
{
 return ((x <= other.x) && (y <= other.y) && (z <= other.z));
}

bool Vec3::operator>=(const Vec3& other) const
{
 return ((x >= other.x) && (y >= other.y) && (z >= other.z));
}

bool Vec3::operator>(const Vec3& other) const
{
 return ((x > other.x) && (y > other.y) && (z > other.z));
}

bool Vec3::operator==(const Vec3& other) const
{
 return ((x == other.x) && (y == other.y) && (z == other.z));
}

bool Vec3::operator!=(const Vec3& other) const
{
 return ((x != other.x) || (y != other.y) || (z != other.z));
}

Vec3 Vec3::operator+(const Vec3& other)
{
 return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::operator+(const Vec3& other) const
{
 return Vec3(x + other.x, y + other.y, z + other.z);
}

Matrix44 Vec3::operator+(const Quat& other)
{
 return Matrix44(*this, other);
}

void Vec3::operator+=(const Vec3& other)
{
 x += other.x;
 y += other.y;
 z += other.z;
}

Vec3 Vec3::operator-(const Vec3& other)
{
 return Vec3(x - other.x, y - other.y, z - other.z);
}

Vec3 Vec3::operator-(const Vec3& other) const
{
 return Vec3(x - other.x, y - other.y, z - other.z);
}

void Vec3::operator-=(const Vec3& other)
{
 x -= other.x;
 y -= other.y;
 z -= other.z;
}

Vec3 Vec3::operator*(const Vec3& other)
{
 return Vec3(x * other.x, y * other.y, z * other.z);
}

void Vec3::operator*=(const Vec3& other)
{
 x *= other.x;
 y *= other.y;
 z *= other.z;
}

Vec3 Vec3::operator*(const Real& s)
{
 return Vec3(x * s, y * s, z * s);
}

void Vec3::operator*=(const Real& s)
{
 x *= s;
 y *= s;
 z *= s;
}

Vec3 Vec3::operator*=(const Quat& other)
{
 return Vec3(*this) * other;
}

// This function was adopted from the OGRE3D Library, Quaternion class from http://www.ogre3d.org
Vec3 Vec3::operator*(const Quat& quat)
{
 Vec3 uv, uuv, qvec(quat.x, quat.y, quat.z);
 uv = qvec.cross(*this);
 uuv = qvec.cross(uv);
 uv *= (2.0f * quat.w);
 uuv *= 2.0f;
 return *this + uv + uuv;
}


void Vec3::operator/=(const Vec3& other)
{
 x /= other.x;
 y /= other.y;
 z /= other.z;
}

Vec3 Vec3::operator/(const Vec3& other)
{
 return Vec3(x * other.x, y * other.y, z * other.z);
}

void Vec3::operator/=(const Real& s)
{
 const Real inv = (Real) 1.0 / s;
 x *= inv;
 y *= inv;
 z *= inv;
}

Vec3 Vec3::operator/(const Real& s)
{
 const Real inv = (Real) 1.0 / s;
 return Vec3(x * inv, y * inv, z * inv);
}

Vec3 Vec3::operator+() const
{
 return *this;
}

Vec3 Vec3::operator-() const
{
 return Vec3(-x, -y, -z);
}

Real& Vec3::operator[](const size_t i)
{
 return (&x)[i];
}

const Real& Vec3::operator[](const size_t i) const
{
 return (&x)[i];
}

Vec3 Vec3::random(float x0, float x1, float y0, float y1, float z0, float z1)
{
 return Vec3(Math::random(x0,x1), Math::random(y0,y1), Math::random(z0,z1));
}

String Vec3::to_s() const
{
 std::ostringstream ss;
 ss << x << " " << y << " " << z;
 return ss.str();
}

std::vector<Real> Vec3::to_a() const
{
 std::vector<Real> a;
 a.push_back(x);
 a.push_back(y);
 a.push_back(z);
 return a;
}

void Vec3::clamp(const Vec3& min, const Vec3& max)
{
 
 if (x < min.x)
  x = min.x;
 else if (x > max.x)
  x = max.x;

 
 if (y < min.y)
  y = min.y;
 else if (y > max.y)
  y = max.y;

 
 if (z < min.z)
  z = min.z;
 else if (z > max.z)
  z = max.z;

}

                                                                                       

} // namespace NxOgre

                                                                                       
