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
#include "NxOgreQuat.h"

#include "string.h"

                                                                                       

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
 
  Matrix33();
 
  Matrix33(const Real& _00, const Real& _01, const Real& _02,
                 const Real& _10, const Real& _11, const Real& _12,
                 const Real& _20, const Real& _21, const Real& _22);
 
  Matrix33(const Real mem[Rows][Cols]);
 
  Matrix33(const Matrix33& other);

  Matrix33(const Quat& quat);

  Matrix33 operator=(const Matrix33& other);

  void set(const Matrix33& other);

  void set(const Real mem[Rows][Cols]);

  void set(const Quat& quat);

  void set(const Real& w, const Real& x, const Real& y, const Real& z);

  void set(const Real& _00, const Real& _01, const Real& _02,
                 const Real& _10, const Real& _11, const Real& _12,
                 const Real& _20, const Real& _21, const Real& _22);

  Real* operator[](size_t row) const;

  void identity();
  
  void zero();

  Real* ptr();
 
  const Real* ptr() const;
 
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
 
  Matrix44();
 
  Matrix44(const Real& _00, const Real& _01, const Real& _02, const Real& _03,
                 const Real& _10, const Real& _11, const Real& _12, const Real& _13,
                 const Real& _20, const Real& _21, const Real& _22, const Real& _23,
                 const Real& _30, const Real& _31, const Real& _32, const Real& _33
                );
 
  Matrix44(const Real mem[Rows][Cols]);
 
  Matrix44(const Matrix44& other);
 
  Matrix44(const Vec3& translation_component);
 
  Matrix44(const Quat& rotation_asquaternion_component);
 
  Matrix44(const Vec3& translation_component, const Quat& rotation_asquaternion_component);

  Matrix44 operator=(const Matrix44& other);
 
  void set(const Matrix44& other);
 
  void set(const Real mem[Rows][Cols]);
 
  void set(const Quat& quat);
 
  void set(const Real& w, const Real& x, const Real& y, const Real& z);
 
  void set(const Vec3& vec);
 
  void set(const Real& trans_x, const Real& trans_y, const Real& trans_z);
 
 void get(Real& trans_x, Real& trans_y, Real& trans_z) const;
 
  void set(const Real& _00, const Real& _01, const Real& _02, const Real& _03,
                 const Real& _10, const Real& _11, const Real& _12, const Real& _13,
                 const Real& _20, const Real& _21, const Real& _22, const Real& _23,
                 const Real& _30, const Real& _31, const Real& _32, const Real& _33
                );

  Real* operator[](size_t row) const;

 operator Vec3();

 operator Vec3() const;

  void identity();

  void translationIdentity();

  void scaleIdentity();

  void rotationIdentity();

  void zero();

  Real* ptr();

  const Real* ptr() const;
 
 void columnMajor(Real* f_16);
 
 Vec3 operator*(const Vec3& other) const;
 
 protected:
 
 union
 {
  Real M[16];
  Real m[4][4];
 } m;
 
};

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
