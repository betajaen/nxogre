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

#ifndef NXOGRE_QUAT_H
#define NXOGRE_QUAT_H

#include "NxOgreRequired.h"

namespace NxOgre
{

class NXOGRE_CLASS Quat
{
  
  public:

  // --------------------------------------------------

   Real w, x,y,z;

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Quat()
  {
   identity();
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Quat(const Quat& q)
  {
   set(q);
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Quat(const Real& W, const Real& X, const Real& Y, const Real& Z)
  {
   w = W;
   x = X;
   y = Y;
   z = Z;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE void identity()
  {
   w = Real(1.);
   x = Real(1.);
   y = Real(1.);
   z = Real(1.);
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE bool isIdentity() const
  {
   return w == Real(1.0) && x == Real(0.) && y == Real(0.) && z == Real(0.);
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE void set(const Quat& q)
  {
   w = q.w;
   x = q.x;
   y = q.y;
   z = q.z;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE void set(const Real& W, const Real& X, const Real& Y, const Real& Z)
  {
   w = W;
   x = X;
   y = Y;
   z = Z;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE void setW(const Real& W)
  {
   w = W;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Real getW() const
  {
   return w;
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
   NXOGRE_ASSERT(index < 4);
   return *(&w+index);
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Real* ptr()
  {
   return &w;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE const Real* ptr() const
  {
   return &w;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE operator Real*()
  {
   return &w;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE operator const Real*() const
  {
   return &w;
  }

  // --------------------------------------------------

  void setEuler(const Real& pitch, const Real& yaw, const Real& roll)
  {
   
   Real halfYaw = Real(yaw) * Real(0.5);
   Real halfPitch = Real(pitch) * Real(0.5);
   Real halfRoll = Real(roll) * Real(0.5);
   Real cosYaw = Math::cos(halfYaw);
   Real sinYaw = Math::sin(halfYaw);
   Real cosPitch = Math::cos(halfPitch);
   Real sinPitch = Math::sin(halfPitch);
   Real cosRoll = Math::cos(halfRoll);
   Real sinRoll = Math::sin(halfRoll);
   
   w = cosRoll * sinPitch * cosYaw + sinRoll * cosPitch * sinYaw;
   x = cosRoll * cosPitch * sinYaw - sinRoll * sinPitch * cosYaw;
   y = sinRoll * cosPitch * cosYaw - cosRoll * sinPitch * sinYaw;
   z = cosRoll * cosPitch * cosYaw + sinRoll * sinPitch * sinYaw;
   
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Quat& operator+=(const Quat& q)
  {
   w += q.w;
   x += q.x;
   y += q.y;
   z += q.z;
   return *this;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Quat& operator-=(const Quat& q)
  {
   w -= q.w;
   x -= q.x;
   y -= q.y;
   z -= q.z;
   return *this;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Quat& operator*=(const Real& s)
  {
   w *= s;
   x *= s;
   y *= s;
   z *= s;
   return *this;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Quat& operator*=(const Quat& q)
  {
   w = w * q.w - x * q.x - y * q.y - z * q.z;
   x = w * q.x + x * q.w + y * q.z - z * q.y;
   y = w * q.y + y * q.w + z * q.x - x * q.z;
   z = w * q.z + z * q.w + x * q.y - y * q.x;
   return *this;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Quat operator*(const Real& s)
  {
   return Quat(w*s, x*s, y*s, z*s);
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Quat operator/(const Real& s)
  {
   NXOGRE_ASSERT(s != Real(0.));
   return Quat(w/s, x/s, y/s, z/s);
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Real dot(const Quat& q) const
  {
   return w*q.w + x*q.x + y*q.y + z*q.z;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Real magnitudeSquared() const
  {
   return dot(*this);
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Real magnitude() const
  {
   return Math::sqrt(dot(*this));
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Quat normalise() const
  {
   Quat q(*this);
   q.NORMALISE();
   return q;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE void NORMALISE()
  {
   Real l = magnitude();
   w = w / l;
   x = x / l;
   y = y / l;
   z = z / l;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Quat inverse() const
  {
   return Quat(w, -x, -y, -z);
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE void INVERSE()
  {
   x = -x;
   y = -y;
   z = -z;
  }


}; // Quat 

// --------------------------------------------------

NXOGRE_FORCE_INLINE Quat operator-(const Quat& q)
{
 return Quat(-q.w, -q.x, -q.y, -q.z);
}

// --------------------------------------------------

NXOGRE_FORCE_INLINE Quat operator*(const Quat& a, const Quat& b)
{
 return Quat(
  a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z,
  a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,
  a.w * b.y + a.y * b.w + a.z * b.x - a.x * b.z,
  a.w * b.z + a.z * b.w + a.x * b.y - a.y * b.x
  ); 
}

// --------------------------------------------------


} // namespace NxOgre


#endif