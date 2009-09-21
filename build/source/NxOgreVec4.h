/** File: NxOgreVec4.h
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

#ifndef NXOGRE_VEC4_H
#define NXOGRE_VEC4_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreMath.h"

                                                                                       

namespace NxOgre
{

                                                                                       

class NxOgrePublicClass Vec4
{
 public:
  
  enum
  {
   Size = 4
  };
  
  Vec4();

  Vec4(const Vec4& other);
  
  Vec4(const Real& W, const Real& X, const Real& Y, const Real& Z);
  
  void set(const Real& W,const Real& X, const Real& Y, const Real& Z);
  
  void set(const Vec4& other);
  
  Real* ptr();

  const Real* ptr() const;

  Real normalise();

  Vec4 mid(const Vec4& other) const;
  
  Real magnitudeSquared() const;

  Real magnitude() const;

  void min(const Vec4& other);

  void max(const Vec4& other);

  void fill(const Real& value);

  void zero();

  bool isZero() const;

  Vec4 lerp(const Vec4& other, const Real& alpha) const;

  Vec4 operator=(const Vec4& other);

  bool operator<(const Vec4& other) const;

  bool operator>(const Vec4& other) const;

  bool operator==(const Vec4& other) const;

  bool operator!=(const Vec4& other) const;

  Vec4 operator+(const Vec4& other);

  Vec4 operator+(const Vec4& other) const;

  void operator+=(const Vec4& other);

  Vec4 operator-(const Vec4& other) const;

  Vec4 operator-(const Vec4& other);

  void operator-=(const Vec4& other);

  Vec4 operator*(const Vec4& other);

  void operator*=(const Vec4& other);

  Vec4 operator*(const Real& s);

  void operator*=(const Real& s);

  friend Vec4 operator*(const Real& s, const Vec4& vector)
  {
   return Vec4(vector.w * s, vector.x * s, vector.y * s, vector.z * s);
  }

  void operator/=(const Vec4& other);

  Vec4 operator/(const Vec4& other);

  void operator/=(const Real& s);

  Vec4 operator/(const Real& s);

  Vec4 operator+() const;

  Vec4 operator-() const;

  Real& operator[](const size_t i);
  
  const Real& operator[](const size_t i) const;

  Real w, x, y, z;

  static const Vec4 ZERO;
};

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
