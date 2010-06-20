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

                                                                                       

#ifndef NXOGRE_VEC3_H
#define NXOGRE_VEC3_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreString.h"
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

  inline Vec3(const String&);

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

  inline bool isNegative() const;

  void clamp(const Vec3& min, const Vec3& max);

  inline Vec3 lerp(const Vec3& other, const Real& alpha) const;

  inline friend Vec3 operator * ( const Real fScalar, const Vec3& rkVector )
  {
      return Vec3(
          fScalar * rkVector.x,
          fScalar * rkVector.y,
          fScalar * rkVector.z);
  }

  inline friend Vec3 operator * (  const Vec3& rkVector, const Real fScalar )
  {
      return Vec3(
          fScalar * rkVector.x,
          fScalar * rkVector.y,
          fScalar * rkVector.z);
  }

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

  inline Vec3 operator*=(const Quat& other);

  inline Vec3 operator*(const Real& s);

  inline void operator*=(const Real& s);

  inline Vec3 operator*(const Quat& quat);

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

  template<class user_xyz_vector_type>
  inline void from(const user_xyz_vector_type& vec)
  {
   x = vec.x;
   y = vec.y;
   z = vec.z;
  }

  inline String to_s() const;

  inline NxOgrePublicFunction friend std::ostream& operator << (std::ostream& o, const Vec3& v)
  {
   o << v.to_s();
   return o;
  }

  inline std::vector<Real> to_a() const;

  static Vec3 random(float x0, float x1, float y0, float y1, float z0, float z1);

  static const Vec3 ZERO;

  static const Vec3 UNIT_X;

  static const Vec3 UNIT_Y;

  static const Vec3 UNIT_Z;

  static const Vec3 NEGATIVE_UNIT_X;

  static const Vec3 NEGATIVE_UNIT_Y;

  static const Vec3 NEGATIVE_UNIT_Z;

  Real x, y, z;

};

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
