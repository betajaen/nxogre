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

                                                                                       

#ifndef NXOGRE_MATRIX_H
#define NXOGRE_MATRIX_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreMatrix.h"
#include "NxOgreVec3.h"
#include "NxOgreQuat.h"
#include "NxOgreString.h"

                                                                                       

namespace NxOgre
{

class Quat;
class Vec3;

/** \brief Matrix33
*/
class NxOgrePublicClass Matrix33
{
 public:
 
 enum
 {
  Rows = 3,
  Cols = 3,
  Size = 9
 };
 
 inline Matrix33();
 
 inline Matrix33(const Real& _00, const Real& _01, const Real& _02,
                 const Real& _10, const Real& _11, const Real& _12,
                 const Real& _20, const Real& _21, const Real& _22);
 
 inline Matrix33(const Real mem[Rows][Cols]);
 
 inline Matrix33(const Matrix33& other);

 inline Matrix33(const Quat& quat);

 inline Matrix33 operator=(const Matrix33& other);

 inline void set(const Matrix33& other);

 inline void set(const Real mem[Rows][Cols]);

 inline void set(const Quat& quat);

 inline void set(const Real& w, const Real& x, const Real& y, const Real& z);

 inline void set(const Real& _00, const Real& _01, const Real& _02,
                 const Real& _10, const Real& _11, const Real& _12,
                 const Real& _20, const Real& _21, const Real& _22);

  
 inline Real* operator[](size_t row) const;

 inline void identity();
  
 inline void zero();

 inline Real* ptr();
 
 inline const Real* ptr() const;

 inline String to_s() const;

 inline NxOgrePublicFunction friend std::ostream& operator << (std::ostream& o, const Matrix33& m)
 {
  o << m.to_s();
  return o;
 }

 static const Matrix33 ZERO;
 
 static const Matrix33 IDENTITY;
 
 protected:
 
  union
  {
   Real M[9];
   Real m[3][3];
  } m;
  
};

/** \brief Matrix44
*/
class NxOgrePublicClass Matrix44
{
 public:
 
 enum
 {
  Rows = 4,
  Cols = 4,
  Size = 16
 };
 
 inline Matrix44();
 
 inline Matrix44(const Real& _00, const Real& _01, const Real& _02, const Real& _03,
                 const Real& _10, const Real& _11, const Real& _12, const Real& _13,
                 const Real& _20, const Real& _21, const Real& _22, const Real& _23,
                 const Real& _30, const Real& _31, const Real& _32, const Real& _33
                );
 
 inline Matrix44(const Real mem[Rows][Cols]);
 
 inline Matrix44(const Matrix44& other);
 
 inline Matrix44(const Vec3& translation_component);
 
 inline Matrix44(const Quat& rotation_asquaternion_component);
 
 inline Matrix44(const Vec3& translation_component, const Quat& rotation_asquaternion_component);

 inline Matrix44 operator=(const Matrix44& other);
 

 inline void set(const Matrix44& other);
 
 inline void set(const Real mem[Rows][Cols]);
 
 inline void set(const Quat& quat);
 
 inline void set(const Radian& angle, Enums::Axis);

 inline void set(const Real& w, const Real& x, const Real& y, const Real& z);
 
 inline void set(const Vec3& vec);
 
 inline void set(const Real& trans_x, const Real& trans_y, const Real& trans_z);
 
 void get(Real& trans_x, Real& trans_y, Real& trans_z) const;
 
 inline void set(const Real& _00, const Real& _01, const Real& _02, const Real& _03,
                 const Real& _10, const Real& _11, const Real& _12, const Real& _13,
                 const Real& _20, const Real& _21, const Real& _22, const Real& _23,
                 const Real& _30, const Real& _31, const Real& _32, const Real& _33
                );

 inline Real* operator[](size_t row) const;

 operator Vec3();

 operator Vec3() const;

 template<typename T> T translation_as() const
 {
  T t;
  t.x = m.m[0][3];
  t.y = m.m[1][3];
  t.z = m.m[2][3];
 }

 inline void identity();

 inline void translationIdentity();

 inline void scaleIdentity();

 inline void rotationIdentity();

 inline void zero();

 inline Real* ptr();

 inline const Real* ptr() const;
 
 inline String to_s() const;

 inline NxOgrePublicFunction friend std::ostream& operator << (std::ostream& o, const Matrix44& m)
 {
  o << m.to_s();
  return o;
 }

 void columnMajor(Real* f_16);
 
 Vec3 operator*(const Vec3& other) const;
 
 static const Matrix44 ZERO;
 
 static const Matrix44 IDENTITY;
 
 static const Matrix44 UNINITIALISED;
 
 protected:
 
 union
 {
  Real M[16];
  Real m[4][4];
 } m;
 
};

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
