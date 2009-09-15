/** File: NxOgreMatrix.h
    Created on: 15-Sept-09
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

#ifndef NXOGRE_MATRIX_H
#define NXOGRE_MATRIX_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreMatrix.h"
#include "NxOgreVec.h"
#include "NxOgreQuat.h"

#include "string.h"

                                                                                       

namespace NxOgre_Namespace
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

 inline void identity();

 inline void translationIdentity();

 inline void scaleIdentity();

 inline void rotationIdentity();

 inline void zero();

 inline Real* ptr();

 inline const Real* ptr() const;
 
 void columnMajor(Real* f_16);
 
 Vec3 operator*(const Vec3& other) const;
 
 protected:
 
 union
 {
  Real M[16];
  Real m[4][4];
 } m;
 
};

                                                                                       

} // namespace NxOgre_Namespace

                                                                                       

#endif
