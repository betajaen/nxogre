/** File: NxOgreVec2.h
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

#ifndef NXOGRE_VEC2_H
#define NXOGRE_VEC2_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreMath.h"

                                                                                       

namespace NxOgre
{

                                                                                       

class Vec3;

class NxOgrePublicClass Vec2
{
 public:
    
  enum
  {
   Size = 2
  };

  Vec2();

  Vec2(const Vec2& other);
  
  Vec2(const Real& X, const Real& Y);
  
  void set(const Real& X, const Real& Y);
  
  void set(const Vec2& other);
  
  Real* ptr();

  const Real* ptr() const;

  Real normalise();

  Vec2 mid(const Vec2& other) const;
  
  Real dot(const Vec2& other) const;

  Real cross(const Vec2& other);

  Real magnitudeSquared() const;

  Real magnitude() const;

  void min(const Vec2& other);

  void max(const Vec2& other);

  void fill(const Real& value);

  void zero();

  bool isZero() const;

  Vec2 lerp(const Vec2& other, const Real& alpha) const;

  Vec2 operator=(const Vec2& other);

  bool operator<=(const Vec2& other) const;

  bool operator>=(const Vec2& other) const;

  bool operator<(const Vec2& other) const;

  bool operator>(const Vec2& other) const;

  bool operator==(const Vec2& other) const;

  bool operator!=(const Vec2& other) const;

  Vec2 operator+(const Vec2& other);

  Vec2 operator+(const Vec2& other) const;

  void operator+=(const Vec2& other);

  Vec2 operator-(const Vec2& other);

  Vec2 operator-(const Vec2& other) const;

  void operator-=(const Vec2& other);

  Vec2 operator*(const Vec2& other);

  void operator*=(const Vec2& other);

  Vec2 operator*(const Real& s);

  void operator*=(const Real& s);

  friend Vec2 operator*(const Real& s, const Vec2& vector)
  {
   return Vec2(vector.x * s, vector.y * s);
  }

  void operator/=(const Vec2& other);

  Vec2 operator/(const Vec2& other);

  void operator/=(const Real& s);

  Vec2 operator/(const Real& s);

  Vec2 operator+() const;

  Vec2 operator-() const;

  Real& operator[](const size_t i);
  
  const Real& operator[](const size_t i) const;

  Real x, y;

  static const Vec2 ZERO;

};

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
