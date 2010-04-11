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

                                                                                       

#ifndef NXOGRE_VEC2_H
#define NXOGRE_VEC2_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreString.h"
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
  
  inline String to_s() const;

  inline std::vector<Real> to_a() const;

  Real x, y;
  
  static const Vec2 ZERO;
  
};

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
