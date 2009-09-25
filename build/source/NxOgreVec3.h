/** File: NxOgreVec3.h
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

#ifndef NXOGRE_VEC3_H
#define NXOGRE_VEC3_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreMath.h"
#include "NxOgreMatrix.h"

                                                                                       

namespace NxOgre
{

                                                                                       

class Vec2;
class Vec3;
class Vec4;
class Quat;
class Matrix33;
class Matrix44;

class NxOgrePublicClass Vec3
{
 public:
  
  enum
  {
   Size = 3
  };

  Vec3();

  Vec3(const Vec3& other);

  template<typename xyz_vector_class>
  Vec3(const xyz_vector_class& other)
  {
   set(other.x, other.y, other.z);
  }

  Vec3(const Matrix44& other);

  template<typename xyz_vector_class>
  Vec3 operator=(const xyz_vector_class& other)
  {
   set(other.x, other.y, other.z);
   return *this;
  }

  
  Vec3(const Real& X, const Real& Y, const Real& Z);
  
  void set(const Real& X, const Real& Y, const Real& Z);
  
  void set(const Vec3& other);
  
  Real* ptr();

  const Real* ptr() const;

  Real normalise();

  Vec3 mid(const Vec3& other) const;
  
  Real dot(const Vec3& other) const;

  Vec3 cross(const Vec3& other);

  Real distance(const Vec3& other) const;

  Real distanceSquared(const Vec3& other) const;

  Real magnitudeSquared() const;

  Real magnitude() const;

  void min(const Vec3& other);

  void max(const Vec3& other);

  void fill(const Real& value);

  void zero();

  bool isZero() const;

  Vec3 lerp(const Vec3& other, const Real& alpha) const;

  Vec3 operator=(const Vec3& other);

  bool operator<(const Vec3& other) const;

  bool operator<=(const Vec3& other) const;

  bool operator>=(const Vec3& other) const;

  bool operator>(const Vec3& other) const;

  bool operator==(const Vec3& other) const;

  bool operator!=(const Vec3& other) const;

  Vec3 operator+(const Vec3& other);

  Vec3 operator+(const Vec3& other) const;

  Matrix44 operator+(const Quat& other);

  void operator+=(const Vec3& other);

  Vec3 operator-(const Vec3& other);

  Vec3 operator-(const Vec3& other) const;

  void operator-=(const Vec3& other);

  Vec3 operator*(const Vec3& other);

  void operator*=(const Vec3& other);

  Vec3 operator*(const Real& s);

  void operator*=(const Real& s);

  Vec3 operator*(const Quat& quat);

  friend Vec3 Vec3::operator*(const Real& s, const Vec3& vector)
  {
   return Vec3(vector.x * s, vector.y * s, vector.z * s);
  }

  friend Vec3 Vec3::operator*(const Vec3& vector, const Real& s)
  {
   return Vec3(vector.x * s, vector.y * s, vector.z * s);
  }

  void operator/=(const Vec3& other);

  Vec3 operator/(const Vec3& other);

  void operator/=(const Real& s);

  Vec3 operator/(const Real& s);

  Vec3 operator+() const;

  Vec3 operator-() const;

  Real& operator[](const size_t i);
  
  const Real& operator[](const size_t i) const;

  template<class user_xyz_vector_type>
  user_xyz_vector_type as() const
  {
   user_xyz_vector_type v;
   v.x = x;
   v.y = y;
   v.z = z;
   return v;
  }
  
  template<class user_xyz_vector_type>
  inline void from(const user_xyz_vector_type& vec)
  {
   x = vec.x;
   y = vec.y;
   z = vec.z;
  }
  
  static const Vec3 ZERO;

  Real x, y, z;
};


                                                                                       

} // namespace NxOgre

                                                                                       

#endif
