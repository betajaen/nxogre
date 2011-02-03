/** 
    
    This file is part of NxOgre.
    
    Copyright(c) 2011 Robin Southern, http://github.com/betajaen/nxogre/
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files(the "Software"), to deal
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

#include "NxOgreRequired.h"

namespace NxOgre
{

class NXOGRE_CLASS Vec3
{
  
  public:

  // --------------------------------------------------

  #ifdef NXOGRE_USES_4BYTE_ALIGNMENT
   Real x,y,z,w;
  #else
   Real x,y,z;
  #endif

   static const Vec3 ZERO;
   static const Vec3 UNIT_SCALE;
   static const Vec3 UNIT_X;
   static const Vec3 UNIT_Y;
   static const Vec3 UNIT_Z;
   static const Vec3 NEGATIVE_UNIT_X;
   static const Vec3 NEGATIVE_UNIT_Y;
   static const Vec3 NEGATIVE_UNIT_Z;

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Vec3()
  {
   zero();
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Vec3(const Vec3& v)
  {
   set(v);
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Vec3(const Real& X, const Real& Y, const Real& Z)
  {
#ifdef NXOGRE_USES_4BYTE_ALIGNMENT
   w = Real(0.);
#endif
   x = X;
   y = Y;
   z = Z;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE void zero()
  {
#ifdef NXOGRE_USES_4BYTE_ALIGNMENT
   w = Real(0.);
#endif
   x = Real(0.);
   y = Real(0.);
   z = Real(0.);
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE bool isZero() const
  {
   return x == Real(0.) && y == Real(0.) && z == Real(0.);
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE bool isNearlyZero() const
  {
   return squaredMagnitude() < NXOGRE_REAL_EPSILON;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE void set(const Vec3& v)
  {
   x = v.x;
   y = v.y;
   z = v.z;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE void set(const Real& X, const Real& Y, const Real& Z)
  {
   x = X;
   y = Y;
   z = Z;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE void setX(const Real& X)
  {
   x = X;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Real getX() const
  {
   return x;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE void setY(const Real& Y)
  {
   y = Y;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Real getY() const
  {
   return y;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE void setZ(const Real& Z)
  {
   z = Z;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Real getZ() const
  {
   return z;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Real& operator [] (const size_t& index)
  {
#ifdef NXOGRE_USES_4BYTE_ALIGNMENT
   NXOGRE_ASSERT(index < 4);
#else
   NXOGRE_ASSERT(index < 3);
#endif
   return *(&x+index);
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Real* ptr()
  {
   return &x;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE const Real* ptr() const
  {
   return &x;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE operator Real*()
  {
   return &x;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE operator const Real*() const
  {
   return &x;
  }

  // --------------------------------------------------

  // Set x,y,z to modulus of x,y,z 
  NXOGRE_FORCE_INLINE void ABSOLUTE()
  {
   x = Math::abs(x);
   y = Math::abs(y);
   z = Math::abs(z);
  }

  // --------------------------------------------------

  // Return a copy of the modulus of x,y,z 
  NXOGRE_FORCE_INLINE Vec3 absolute() const
  {
   return Vec3(
               Math::abs(x),
               Math::abs(y),
               Math::abs(z)
              );
  }

  // --------------------------------------------------

  // Lerp of x,y,z from b according to t
  NXOGRE_FORCE_INLINE void LERP(const Vec3& b, const Real& t)
  {
   x = Math::lerp(x, b.x, t);
   y = Math::lerp(y, b.y, t);
   z = Math::lerp(z, b.z, t);
  }

  // --------------------------------------------------

  // Return a copy of lerp of x,y,z from b according to t
  NXOGRE_FORCE_INLINE Vec3 lerp(const Vec3& b, const Real& t) const
  {
   return Vec3(
     Math::lerp(x, b.x, t),
     Math::lerp(y, b.y, t),
     Math::lerp(z, b.z, t)
   );
  }

  // --------------------------------------------------

  // Dot product
  NXOGRE_FORCE_INLINE Real dot(const Vec3& v) const
  {
   return x * v.x + y * v.y + z * v.z;
  }

  // --------------------------------------------------

  // Cross product (self x V)
  NXOGRE_FORCE_INLINE Vec3 cross(const Vec3& v) const
  {
   return Vec3(
       y * v.z - z * v.y,
       z * v.x - x * v.z,
       x * v.y - y * v.x
   );
  }

  // --------------------------------------------------

  // Become the cross product (self x V)
  NXOGRE_FORCE_INLINE void CROSS(const Vec3& v)
  {
   set(cross(v));
  }

  // --------------------------------------------------

  // Normalise self
  NXOGRE_FORCE_INLINE Real NORMALISE()
  {
   Real n = magnitude();
   if (n > NXOGRE_REAL_EPSILON)
   {
    Real invN = Real(1.0) / n;
    x *= invN;
    y *= invN;
    z *= invN;
   }
   return n;
  }

  // --------------------------------------------------

  // Return a copy of normalised self
  NXOGRE_FORCE_INLINE Vec3 normalise()
  {
   Vec3 v(*this);
   v.NORMALISE();
   return v;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Vec3& operator=(const Vec3& v)
  {
   x = v.x;
   y = v.y;
   z = v.z;
   return *this;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Vec3& operator+=(const Vec3& v)
  {
   x += v.x;
   y += v.y;
   z += v.z;
   return *this;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Vec3& operator-=(const Vec3& v)
  {
   x -= v.x;
   y -= v.y;
   z -= v.z;
   return *this;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Vec3& operator*=(const Real& s)
  {
   x *= s;
   y *= s;
   z *= s;
   return *this;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Vec3& operator/=(const Real& s)
  {
   x /= s;
   y /= s;
   z /= s;
   return *this;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Real distance(const Vec3& v) const
  {
   return Vec3(x-v.x,  y-v.y,  z-v.z).magnitude();
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Real squaredDistance(const Vec3& v) const
  {
   return Vec3(x-v.x,  y-v.y,  z-v.z).squaredMagnitude();
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Real squaredMagnitude() const
  {
   return dot(*this);
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Real magnitude() const
  {
   return Math::sqrt(dot(*this));
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE bool operator==(const Vec3& v) const
  {
   return ( (x==v.x) && (y==v.y) && (z==v.z) );
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE bool operator!=(const Vec3& v) const
  {
   return ( (x!=v.x) && (y!=v.y) && (z!=v.z) );
  }

  // --------------------------------------------------

  template<typename T> NXOGRE_FORCE_INLINE T to() const
  {
   T v;
   v.x = x;
   v.y = y;
   v.z = z;
   return v;
  }

  // --------------------------------------------------

  template<typename T> NXOGRE_FORCE_INLINE void to(T& v) const
  {
   v.x = x;
   v.y = y;
   v.z = z;
   return v;
  }

  // --------------------------------------------------

  template<typename T> NXOGRE_FORCE_INLINE void set(const T& v)
  {
   x = v.x;
   y = v.y;
   z = v.z;
  }

  // --------------------------------------------------

  template<typename T> static NXOGRE_FORCE_INLINE Vec3 from(const T& v)
  {
   return Vec3(v.x, v.y, v.z);
  }

  // --------------------------------------------------

}; // Vec3 

// --------------------------------------------------

// Va + Vb
NXOGRE_FORCE_INLINE Vec3 operator+(const Vec3& a, const Vec3& b)
{
 return Vec3(a.x+b.x, a.y+b.y, a.z+b.z);
}

// --------------------------------------------------


// Va - Vb
NXOGRE_FORCE_INLINE Vec3 operator-(const Vec3& a, const Vec3& b)
{
 return Vec3(a.x-b.x, a.y-b.y, a.z-b.z);
}

// --------------------------------------------------


// Va * Vb
NXOGRE_FORCE_INLINE Vec3 operator*(const Vec3& a, const Vec3& b)
{
 return Vec3(a.x*b.x, a.y*b.y, a.z*b.z);
}

// --------------------------------------------------

// Va / Vb
NXOGRE_FORCE_INLINE Vec3 operator/(const Vec3& a, const Vec3& b)
{
 return Vec3(a.x/b.x, a.y/b.y, a.z/b.z);
}

// --------------------------------------------------

// V * s
NXOGRE_FORCE_INLINE Vec3 operator*(const Vec3& v, const Real& s)
{
 return Vec3(v.x*s,  v.y*s,  v.z*s);
}

// --------------------------------------------------

// V / s
NXOGRE_FORCE_INLINE Vec3 operator/(const Vec3& v, const Real& s)
{
 NXOGRE_ASSERT(s != Real(0.0));
 Real invS = (Real(1.0) / s);
 return Vec3(v.x*s,  v.y*s,  v.z*s);
}

// --------------------------------------------------

// -V
NXOGRE_FORCE_INLINE Vec3 operator-(const Vec3& v)
{
 return Vec3(-v.x, -v.y, -v.z);
}

// --------------------------------------------------

} // namespace NxOgre

#endif
