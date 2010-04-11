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

                                                                                       

#ifndef NXOGRE_VEC4_H
#define NXOGRE_VEC4_H

                                                                                       

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

  inline String to_s() const;

  inline std::vector<Real> to_a() const;

  Real x, y, z, w;

  static const Vec4 ZERO;
};

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
