/** File: NxOgreVec.h
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

#ifndef NXOGRE_VEC_H
#define NXOGRE_VEC_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreMath.h"
#include "NxOgreMatrix.h"

                                                                                       

namespace NxOgre_Namespace
{

                                                                                       

class Vec2;
class Vec3;
class Vec4;
class Quat;
class Matrix33;
class Matrix44;

class NxOgrePublicClass Vec2
{
 public:
    
  enum
  {
   Size = 2
  };

  inline Vec2();

  inline Vec2(const Vec2& other);
  
  inline Vec2(const Real& X, const Real& Y);
  
  inline void set(const Real& X, const Real& Y);
  
  inline void set(const Vec2& other);
  
  inline Real* ptr();

  inline const Real* ptr() const;

  inline Real normalise();

  inline Vec2 mid(const Vec2& other) const;
  
  inline Real dot(const Vec2& other) const;

  inline Real cross(const Vec2& other);

  inline Real magnitudeSquared() const;

  inline Real magnitude() const;

  inline void min(const Vec2& other);

  inline void max(const Vec2& other);

  inline void fill(const Real& value);

  inline void zero();

  inline bool isZero() const;

  inline Vec2 lerp(const Vec2& other, const Real& alpha) const;

  inline Vec2 operator=(const Vec2& other);

  inline bool operator<=(const Vec2& other) const;

  inline bool operator>=(const Vec2& other) const;

  inline bool operator<(const Vec2& other) const;

  inline bool operator>(const Vec2& other) const;

  inline bool operator==(const Vec2& other) const;

  inline bool operator!=(const Vec2& other) const;

  inline Vec2 operator+(const Vec2& other);

  inline Vec2 operator+(const Vec2& other) const;

  inline void operator+=(const Vec2& other);

  inline Vec2 operator-(const Vec2& other);

  inline Vec2 operator-(const Vec2& other) const;

  inline void operator-=(const Vec2& other);

  inline Vec2 operator*(const Vec2& other);

  inline void operator*=(const Vec2& other);

  inline Vec2 operator*(const Real& s);

  inline void operator*=(const Real& s);

  inline friend Vec2 operator*(const Real& s, const Vec2& vector)
  {
   return Vec2(vector.x * s, vector.y * s);
  }

  inline void operator/=(const Vec2& other);

  inline Vec2 operator/(const Vec2& other);

  inline void operator/=(const Real& s);

  inline Vec2 operator/(const Real& s);

  inline Vec2 operator+() const;

  inline Vec2 operator-() const;

  inline Real& operator[](const size_t i);
  
  inline const Real& operator[](const size_t i) const;

  Real x, y;

  static const Vec2 ZERO;

};

// ---------------------------------------------------------------------------------------------

class NxOgrePublicClass Vec3
{
 public:
  
  enum
  {
   Size = 3
  };

  inline Vec3();

  inline Vec3(const Vec3& other);

  template<typename xyz_vector_class>
  inline Vec3(const xyz_vector_class& other)
  {
   set(other.x, other.y, other.z);
  }

  inline Vec3(const Matrix44& other);

  template<typename xyz_vector_class>
  inline Vec3 operator=(const xyz_vector_class& other)
  {
   set(other.x, other.y, other.z);
   return *this;
  }

  
  inline Vec3(const Real& X, const Real& Y, const Real& Z);
  
  inline void set(const Real& X, const Real& Y, const Real& Z);
  
  inline void set(const Vec3& other);
  
  inline Real* ptr();

  inline const Real* ptr() const;

  inline Real normalise();

  inline Vec3 mid(const Vec3& other) const;
  
  inline Real dot(const Vec3& other) const;

  inline Vec3 cross(const Vec3& other);

  inline Real distance(const Vec3& other) const;

  inline Real distanceSquared(const Vec3& other) const;

  inline Real magnitudeSquared() const;

  inline Real magnitude() const;

  inline void min(const Vec3& other);

  inline void max(const Vec3& other);

  inline void fill(const Real& value);

  inline void zero();

  inline bool isZero() const;

  inline Vec3 lerp(const Vec3& other, const Real& alpha) const;

  inline Vec3 operator=(const Vec3& other);

  inline bool operator<(const Vec3& other) const;

  inline bool operator<=(const Vec3& other) const;

  inline bool operator>=(const Vec3& other) const;

  inline bool operator>(const Vec3& other) const;

  inline bool operator==(const Vec3& other) const;

  inline bool operator!=(const Vec3& other) const;

  inline Vec3 operator+(const Vec3& other);

  inline Vec3 operator+(const Vec3& other) const;

  inline Matrix44 operator+(const Quat& other);

  inline void operator+=(const Vec3& other);

  inline Vec3 operator-(const Vec3& other);

  inline Vec3 operator-(const Vec3& other) const;

  inline void operator-=(const Vec3& other);

  inline Vec3 operator*(const Vec3& other);

  inline void operator*=(const Vec3& other);

  inline Vec3 operator*(const Real& s);

  inline void operator*=(const Real& s);

  inline Vec3 operator*(const Quat& quat);

  friend Vec3 Vec3::operator*(const Real& s, const Vec3& vector)
  {
   return Vec3(vector.x * s, vector.y * s, vector.z * s);
  }

  friend Vec3 Vec3::operator*(const Vec3& vector, const Real& s)
  {
   return Vec3(vector.x * s, vector.y * s, vector.z * s);
  }

  inline void operator/=(const Vec3& other);

  inline Vec3 operator/(const Vec3& other);

  inline void operator/=(const Real& s);

  inline Vec3 operator/(const Real& s);

  inline Vec3 operator+() const;

  inline Vec3 operator-() const;

  inline Real& operator[](const size_t i);
  
  inline const Real& operator[](const size_t i) const;

  template<class user_xyz_vector_type>
  inline user_xyz_vector_type as() const
  {
   user_xyz_vector_type v;
   v.x = x;
   v.y = y;
   v.z = z;
   return v;
  }

  static const Vec3 ZERO;

  Real x, y, z;
};

// ---------------------------------------------------------------------------------------------

class NxOgrePublicClass Vec4
{
 public:
  
  enum
  {
   Size = 4
  };
  
  inline Vec4();

  inline Vec4(const Vec4& other);
  
  inline Vec4(const Real& W, const Real& X, const Real& Y, const Real& Z);
  
  inline void set(const Real& W,const Real& X, const Real& Y, const Real& Z);
  
  inline void set(const Vec4& other);
  
  inline Real* ptr();

  inline const Real* ptr() const;

  inline Real normalise();

  inline Vec4 mid(const Vec4& other) const;
  
  inline Real magnitudeSquared() const;

  inline Real magnitude() const;

  inline void min(const Vec4& other);

  inline void max(const Vec4& other);

  inline void fill(const Real& value);

  inline void zero();

  inline bool isZero() const;

  inline Vec4 lerp(const Vec4& other, const Real& alpha) const;

  inline Vec4 operator=(const Vec4& other);

  inline bool operator<(const Vec4& other) const;

  inline bool operator>(const Vec4& other) const;

  inline bool operator==(const Vec4& other) const;

  inline bool operator!=(const Vec4& other) const;

  inline Vec4 operator+(const Vec4& other);

  inline Vec4 operator+(const Vec4& other) const;

  inline void operator+=(const Vec4& other);

  inline Vec4 operator-(const Vec4& other) const;

  inline Vec4 operator-(const Vec4& other);

  inline void operator-=(const Vec4& other);

  inline Vec4 operator*(const Vec4& other);

  inline void operator*=(const Vec4& other);

  inline Vec4 operator*(const Real& s);

  inline void operator*=(const Real& s);

  inline friend Vec4 operator*(const Real& s, const Vec4& vector)
  {
   return Vec4(vector.w * s, vector.x * s, vector.y * s, vector.z * s);
  }

  inline void operator/=(const Vec4& other);

  inline Vec4 operator/(const Vec4& other);

  inline void operator/=(const Real& s);

  inline Vec4 operator/(const Real& s);

  inline Vec4 operator+() const;

  inline Vec4 operator-() const;

  inline Real& operator[](const size_t i);
  
  inline const Real& operator[](const size_t i) const;

  Real w, x, y, z;

  static const Vec4 ZERO;
};

// ---------------------------------------------------------------------------------------------

                                                                                       

} // namespace NxOgre_Namespace

                                                                                       

#endif
