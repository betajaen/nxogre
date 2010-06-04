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

                                                                                       

#ifndef NXOGRE_QUAT_H
#define NXOGRE_QUAT_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreRadian.h"

                                                                                       

namespace NxOgre
{

                                                                                       

class Matrix33;
class Matrix44;
class Vec3;

class NxOgrePublicClass Quat
{
 
 public:
  
 Quat();
 
 Quat(const Quat& other);

 Quat(const Real& w_val, const Real& x_val, const Real& y_val, const Real& z_val);
  
 Quat(const Radian& rad, const Vec3&);

 Quat(const Matrix33& other);
  
 Quat(const Matrix44& other);
 
 template<typename wxyz_quaternion_class>
 Quat(const wxyz_quaternion_class& quat)
 {
  setWXYZ(quat.w, quat.x, quat.y, quat.z);
 }

 template<typename wxyz_quaternion_class>
 Quat operator=(const wxyz_quaternion_class& other)
 {
  set(other.w, other.x, other.y, other.z);
  return *this;
 }

 inline Quat operator=(const Matrix33& other);
 
 inline Quat operator=(const Matrix44& other);
 
 void set(const Matrix33& kRot);

 void set(const Matrix44& kRot);

 void set(const Quat& other);

 void setXYZW(const Real& x_val, const Real& y_val, const Real& z_val, const Real& w_val);

 void setWXYZ(const Real& w_val, const Real& x_val, const Real& y_val, const Real& z_val);

 void identity();

 Real dot(Quat& q);

 Real dot(const Quat& q) const;

 Real lengthSquared();

 Real length();

 void normalise();

 bool isNormalised(Real epsilon_tolerance = 1E-4);

 void conj();

 void invert();
 
 void fromAngleAxis(const Radian& rad, const Vec3& axis);
 
 static Quat invert(const Quat& original);

 bool nearly(const Quat& a, const Quat& b, const Real& tolerance = 1E-4);

 static Quat lerp(const Quat& a, const Quat& b, const Real& alpha);

 static Quat slerp(const Quat& a, const Quat& b, const Real& alpha, bool adjustSign = true);

 Real& operator[](const size_t i);

 const Real& operator[](const size_t i) const;

 static inline void multiply(Quat& r, const Quat& a, const Quat& b);

 static inline void multiply(Quat& r, const Quat& a, const Real& s);

 static inline void divide(Quat& r, const Quat& a, const Quat& b);

 static inline void divide(Quat& r, const Quat& a, const Real& s);

 static inline void add(Quat& r, const Quat& a, const Quat& b);

 static inline void subtract(Quat& r, const Quat& a, const Quat& b);

 inline bool operator == (const Quat& other) const;

 inline bool operator != (const Quat& other) const;

 inline Quat operator + ( const Quat& other);
 
 inline void operator +=(const Quat& other);

 inline Quat operator - ( const Quat& other);

 inline void operator -=(const Quat& other);

 inline Quat operator * ( const Quat& other);

 inline void operator *= (const Quat& other);

 inline Quat operator * (Real scalar);

 inline void operator *= (Real scalar);

 inline Quat operator / ( const Quat& other);

 inline void operator /=( const Quat& other);

 inline Quat operator / ( const Real& scalar);

 inline void operator /=( const Real& scalar);

 inline Quat operator-() const;

 template<class user_wxyz_vector_type>
 inline user_wxyz_vector_type as() const
 {
  user_wxyz_vector_type q;
  q.w = w;
  q.x = x;
  q.y = y;
  q.z = z;
  return q;
 }

 static const Quat IDENTITY;

 Real w, x, y, z;

};


                                                                                       

} // namespace NxOgre

                                                                                       

#endif
