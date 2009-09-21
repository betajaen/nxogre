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
#include "NxOgreVec3.h"

                                                                                       

namespace NxOgre
{

                                                                                       

const NxOgre::Vec3        NxOgre::Vec3::ZERO(0,0,0);

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

                                                                                       

} // namespace NxOgre

                                                                                       
