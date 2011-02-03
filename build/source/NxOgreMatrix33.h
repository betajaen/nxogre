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

#ifndef NXOGRE_MATRIX33_H
#define NXOGRE_MATRIX33_H

#include "NxOgreRequired.h"

namespace NxOgre
{


class NXOGRE_CLASS Matrix33
{
  
  public:

  // --------------------------------------------------

  Real m[3][3];

  static const Matrix33 ZERO;
  static const Matrix33 IDENTITY;

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Matrix33()
  {
   // Uninitialised for performanced reasons.
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Matrix33(const Real r[3][3])
  {
   memcpy(m, r, 9 * sizeof(Real));
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Matrix33(const Matrix33& m33)
  {
   memcpy(m, m33.m, 9 * sizeof(Real));
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Matrix33(  
                                 Real m00, Real m01, Real m02,
                                 Real m10, Real m11, Real m12,
                                 Real m20, Real m21, Real m22)
  {
   m[0][0] = m00;
   m[0][1] = m01;
   m[0][2] = m02;
   m[1][0] = m10;
   m[1][1] = m11;
   m[1][2] = m12;
   m[2][0] = m20;
   m[2][1] = m21;
   m[2][2] = m22;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Matrix33& operator=(const Matrix33& m33)
  {
   memcpy(m, m33.m, 9 * sizeof(Real));
   return *this;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE Real* operator[] (size_t row) const
  {
   return (Real*) m[row];
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE bool operator==(const Matrix33& m33)
  {
   if (m[0][0] != m33.m[0][0]) return false;
   if (m[0][1] != m33.m[0][1]) return false;
   if (m[0][2] != m33.m[0][2]) return false;
   if (m[1][0] != m33.m[1][0]) return false;
   if (m[1][1] != m33.m[1][1]) return false;
   if (m[1][2] != m33.m[1][2]) return false;
   if (m[2][0] != m33.m[2][0]) return false;
   if (m[2][1] != m33.m[2][1]) return false;
   if (m[2][2] != m33.m[2][2]) return false;
   return true;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE bool operator!=(const Matrix33& m33)
  {
   if (m[0][0] == m33.m[0][0]) return false;
   if (m[0][1] == m33.m[0][1]) return false;
   if (m[0][2] == m33.m[0][2]) return false;
   if (m[1][0] == m33.m[1][0]) return false;
   if (m[1][1] == m33.m[1][1]) return false;
   if (m[1][2] == m33.m[1][2]) return false;
   if (m[2][0] == m33.m[2][0]) return false;
   if (m[2][1] == m33.m[2][1]) return false;
   if (m[2][2] == m33.m[2][2]) return false;
   return true;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE void set(  Real m00, Real m01, Real m02,
                                 Real m10, Real m11, Real m12,
                                 Real m20, Real m21, Real m22)
  {
   m[0][0] = m00;
   m[0][1] = m01;
   m[0][2] = m02;
   m[1][0] = m10;
   m[1][1] = m11;
   m[1][2] = m12;
   m[2][0] = m20;
   m[2][1] = m21;
   m[2][2] = m22;
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE void setRotation(const Quat& q)
  {
   
   Real x = q.x+q.x;
   Real y = q.y+q.y;
   Real z = q.z+q.z;
   Real wx = x*q.w;
   Real wy = y*q.w;
   Real wz = z*q.w;
   Real xx = x*q.x;
   Real xy = y*q.x;
   Real xz = z*q.x;
   Real yy = y*q.y;
   Real yz = z*q.y;
   Real zz = z*q.z;
   
   m[0][0] = 1.0f-(yy+zz);
   m[0][1] = xy-wz;
   m[0][2] = xz+wy;
   m[1][0] = xy+wz;
   m[1][1] = 1.0f-(xx+zz);
   m[1][2] = yz-wx;
   m[2][0] = xz-wy;
   m[2][1] = yz+wx;
   m[2][2] = 1.0f-(xx+yy);
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE void zero()
  {
   m[0][0] = Real(0.);
   m[0][1] = Real(0.);
   m[0][2] = Real(0.);
   m[1][0] = Real(0.);
   m[1][1] = Real(0.);
   m[1][2] = Real(0.);
   m[2][0] = Real(0.);
   m[2][1] = Real(0.);
   m[2][2] = Real(0.);
  }

  // --------------------------------------------------

  NXOGRE_FORCE_INLINE void identity()
  {
   m[0][0] = Real(1.);
   m[0][1] = Real(0.);
   m[0][2] = Real(0.);
   m[1][0] = Real(0.);
   m[1][1] = Real(1.);
   m[1][2] = Real(0.);
   m[2][0] = Real(0.);
   m[2][1] = Real(0.);
   m[2][2] = Real(1.);
  }

  // --------------------------------------------------

  template<typename T> NXOGRE_FORCE_INLINE T to() const
  {
   T q;
   q.w = w;
   q.x = x;
   q.y = y;
   q.z = z;
   return v;
  }

  // --------------------------------------------------

  template<typename T> NXOGRE_FORCE_INLINE void to(T& q) const
  {
   q.w = w;
   q.x = x;
   q.y = y;
   q.z = z;
   return v;
  }

  // --------------------------------------------------

  template<typename T> NXOGRE_FORCE_INLINE void set(const T& q)
  {
   w = q.w;
   x = q.x;
   y = q.y;
   z = q.z;
  }

  // --------------------------------------------------

  template<typename T> static NXOGRE_FORCE_INLINE Vec3 from(const T& q)
  {
   return Quat(q.w, q.x, q.y, q.z);
  }


}; // Matrix33 

// --------------------------------------------------

} // namespace NxOgre

#endif
