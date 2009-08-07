/** File: matrix.h
    Created on: 14-May-09
    Author: Robin Southern "betajaen"
    Version: 20080514

    © Copyright, 2009 by Robin Southern, http://www.nxogre.org

    Betajaen's Math Library is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    NxOgre is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with Betajaen's Math Library.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef matrix_h_0f788edc_b1d6_40a9_be9f_2833df164c75
#define matrix_h_0f788edc_b1d6_40a9_be9f_2833df164c75

#include "bml/prototypes.h"
#include "bml/math.h"
#include "bml/vector.h"
#include "string.h"

namespace bml
{

 /** \brief Matrix33
 */
 template<typename T> class Matrix33T
 {
  public:
  
  typedef T Type;
  typedef QuaternionT<T> QuaternionType;
  typedef Matrix33T<T> MatrixType;

  enum
  {
   Rows = 3,
   Cols = 3,
   Size = 9
  };

  inline Matrix33T()
  {
  }

  inline Matrix33T(const Type& _00, const Type& _01, const Type& _02,
                   const Type& _10, const Type& _11, const Type& _12,
                   const Type& _20, const Type& _21, const Type& _22)
  {
   set(_00, _01, _02, _10, _11, _12, _20, _21, _22);
  }

  inline Matrix33T(const Type mem[Rows][Cols])
  {
   set(mem);
  }
  
  inline Matrix33T(const Matrix33T& other)
  {
   set(other.m.m);
  }

  inline Matrix33T(const QuaternionType& quat)
  {
   set(quat.w, quat.x, quat.y, quat.z);
  }

  inline Matrix33T operator=(const Matrix33T& other)
  {
   set(other.m.m);
   return *this;
  }

  inline void set(const Matrix33T& other)
  {
   set(other.m.m);
  }

  inline void set(const Type mem[Rows][Cols])
  {
   memcpy(m.m, mem, sizeof(T) * Size);
  }

  inline void set(const QuaternionType& quat)
  {
   set(quat.w, quat.x, quat.y, quat.z);
  }

  // This function was adopted from the OGRE3D Library, Matrix3 class from http://www.ogre3d.org
  inline void set(const Type& w, const Type& x, const Type& y, const Type& z)
  {
   Type fTx  = Type(2.0)*x;
   Type fTy  = Type(2.0)*y;
   Type fTz  = Type(2.0)*z;
   Type fTwx = fTx*w;
   Type fTwy = fTy*w;
   Type fTwz = fTz*w;
   Type fTxx = fTx*x;
   Type fTxy = fTy*x;
   Type fTxz = fTz*x;
   Type fTyy = fTy*y;
   Type fTyz = fTz*y;
   Type fTzz = fTz*z;

   m.m[0][0] = Type(1.0)-(fTyy+fTzz);
   m.m[0][1] = fTxy-fTwz;
   m.m[0][2] = fTxz+fTwy;
   m.m[1][0] = fTxy+fTwz;
   m.m[1][1] = Type(1.0)-(fTxx+fTzz);
   m.m[1][2] = fTyz-fTwx;
   m.m[2][0] = fTxz-fTwy;
   m.m[2][1] = fTyz+fTwx;
   m.m[2][2] = Type(1.0)-(fTxx+fTyy);
  }

  inline void set(const Type& _00, const Type& _01, const Type& _02,
             const Type& _10, const Type& _11, const Type& _12,
             const Type& _20, const Type& _21, const Type& _22)
  {
   m.m[0][0] = _00;
   m.m[0][1] = _01;
   m.m[0][2] = _02;

   m.m[1][0] = _10;
   m.m[1][1] = _11;
   m.m[1][2] = _12;

   m.m[2][0] = _20;
   m.m[2][1] = _21;
   m.m[2][2] = _22;
  }

  inline Type* operator[](size_t row) const
  {
   return (Type*) m.m[row];
  }

  inline void identity()
  {
   m.m[0][0] = Type(1.0);
   m.m[0][1] = Type(0.0);
   m.m[0][2] = Type(0.0);

   m.m[1][0] = Type(0.0);
   m.m[1][1] = Type(1.0);
   m.m[1][2] = Type(0.0);

   m.m[2][0] = Type(0.0);
   m.m[2][1] = Type(0.0);
   m.m[2][2] = Type(1.0);
  }
  
  inline void zero()
  {
   m.m[0][0] = Type(0.0);
   m.m[0][1] = Type(0.0);
   m.m[0][2] = Type(0.0);

   m.m[1][0] = Type(0.0);
   m.m[1][1] = Type(0.0);
   m.m[1][2] = Type(0.0);

   m.m[2][0] = Type(0.0);
   m.m[2][1] = Type(0.0);
   m.m[2][2] = Type(0.0);
  }

  inline Type* ptr()
  {
   return (Type*) m.M;
  }
  
  inline const Type* ptr() const
  {
   return (Type*) m.M;
  }
  
  protected:
  
   union
   {
    Type M[9];
    Type m[3][3];
   } m;
 };

 /** \brief Matrix44
 */
 template<typename T> class Matrix44T
 {
  public:
  
  typedef T Type;
  typedef QuaternionT<T> QuaternionType;
  typedef Matrix44T<T> MatrixType;
  typedef Vector3<T> VectorType;

  enum
  {
   Rows = 4,
   Cols = 4,
   Size = 16
  };

  inline Matrix44T()
  {
  }

  inline Matrix44T(const Type& _00, const Type& _01, const Type& _02, const Type& _03,
                   const Type& _10, const Type& _11, const Type& _12, const Type& _13,
                   const Type& _20, const Type& _21, const Type& _22, const Type& _23,
                   const Type& _30, const Type& _31, const Type& _32, const Type& _33
                  )
  {
   set(_00, _01, _02, _03, _10, _11, _12, _13, _20, _21, _22, _23, _30, _31, _32, _33);
  }

  inline Matrix44T(const Type mem[Rows][Cols])
  {
   set(mem);
  }
  
  inline Matrix44T(const Matrix44T& other)
  {
   set(other.m.m);
  }

  inline Matrix44T(const VectorType& translation_component)
  {
   rotationIdentity();
   set(translation_component.x, translation_component.y, translation_component.z);
  }

  inline Matrix44T(const QuaternionType& rotation_asquaternion_component)
  {
   translationIdentity();
   set(rotation_asquaternion_component.w, rotation_asquaternion_component.x, rotation_asquaternion_component.y, rotation_asquaternion_component.z);
  }

  inline Matrix44T(const VectorType& translation_component, const QuaternionType& rotation_asquaternion_component)
  {
   scaleIdentity();
   set(translation_component.x, translation_component.y, translation_component.z);
   set(rotation_asquaternion_component.w, rotation_asquaternion_component.x, rotation_asquaternion_component.y, rotation_asquaternion_component.z);

  }

  inline Matrix44T operator=(const Matrix44T& other)
  {
   set(other.m.m);
   return *this;
  }

  inline void set(const Matrix44T& other)
  {
   set(other.m.m);
  }

  inline void set(const Type mem[Rows][Cols])
  {
   memcpy(m.m, mem, sizeof(T) * Size);
  }

  inline void set(const QuaternionType& quat)
  {
   set(quat.w, quat.x, quat.y, quat.z);
  }

  // This function was adopted from the OGRE3D Library, Matrix3 class from http://www.ogre3d.org
  inline void set(const Type& w, const Type& x, const Type& y, const Type& z)
  {
   Type fTx  = Type(2.0)*x;
   Type fTy  = Type(2.0)*y;
   Type fTz  = Type(2.0)*z;
   Type fTwx = fTx*w;
   Type fTwy = fTy*w;
   Type fTwz = fTz*w;
   Type fTxx = fTx*x;
   Type fTxy = fTy*x;
   Type fTxz = fTz*x;
   Type fTyy = fTy*y;
   Type fTyz = fTz*y;
   Type fTzz = fTz*z;

   m.m[0][0] = Type(1.0)-(fTyy+fTzz);
   m.m[0][1] = fTxy-fTwz;
   m.m[0][2] = fTxz+fTwy;
   m.m[1][0] = fTxy+fTwz;
   m.m[1][1] = Type(1.0)-(fTxx+fTzz);
   m.m[1][2] = fTyz-fTwx;
   m.m[2][0] = fTxz-fTwy;
   m.m[2][1] = fTyz+fTwx;
   m.m[2][2] = Type(1.0)-(fTxx+fTyy);
  }

  inline void set(const VectorType& vec)
  {
   set(vec.x, vec.y, vec.z);
  }


  inline void set(const Type& trans_x, const Type& trans_y, const Type& trans_z)
  {
   m.m[0][3] = trans_x;
   m.m[1][3] = trans_y;
   m.m[2][3] = trans_z;
  }

  void get(Type& trans_x, Type& trans_y, Type& trans_z) const
  {
   trans_x = m.m[0][3];
   trans_y = m.m[1][3];
   trans_z = m.m[2][3];
  }


  inline void set(const Type& _00, const Type& _01, const Type& _02, const Type& _03,
                  const Type& _10, const Type& _11, const Type& _12, const Type& _13,
                  const Type& _20, const Type& _21, const Type& _22, const Type& _23,
                  const Type& _30, const Type& _31, const Type& _32, const Type& _33
                 )
  {
   m.m[0][0] = _00;
   m.m[0][1] = _01;
   m.m[0][2] = _02;
   m.m[0][3] = _03;

   m.m[1][0] = _10;
   m.m[1][1] = _11;
   m.m[1][2] = _12;
   m.m[1][3] = _13;

   m.m[2][0] = _20;
   m.m[2][1] = _21;
   m.m[2][2] = _22;
   m.m[2][3] = _23;

   m.m[3][0] = _30;
   m.m[3][1] = _31;
   m.m[3][2] = _32;
   m.m[3][3] = _33;
  }

  inline Type* operator[](size_t row) const
  {
   return (Type*) m.m[row];
  }

  operator VectorType()
  {
   return VectorType(m.m[0][3], m.m[1][3], m.m[2][3]);
  }

  operator VectorType() const
  {
   return VectorType(m.m[0][3], m.m[1][3], m.m[2][3]);
  }

  inline void identity()
  {
   m.m[0][0] = 1;
   m.m[0][1] = 0;
   m.m[0][2] = 0;
   m.m[0][3] = 0;

   m.m[1][0] = 0;
   m.m[1][1] = 1;
   m.m[1][2] = 0;
   m.m[1][3] = 0;

   m.m[2][0] = 0;
   m.m[2][1] = 0;
   m.m[2][2] = 1;
   m.m[2][3] = 0;

   m.m[3][0] = 0;
   m.m[3][1] = 0;
   m.m[3][2] = 0;
   m.m[3][3] = 1;
  }

  inline void translationIdentity()
  {
   m.m[0][3] = 0;
   m.m[1][3] = 0;
   m.m[2][3] = 0;
   m.m[3][0] = 0;
   m.m[3][1] = 0;
   m.m[3][2] = 0;
   m.m[3][3] = 1;
  }

  inline void scaleIdentity()
  {
   m.m[3][0] = 0;
   m.m[3][1] = 0;
   m.m[3][2] = 0;
   m.m[3][3] = 1;
  }

  inline void rotationIdentity()
  {
   m.m[0][0] = 1;
   m.m[0][1] = 0;
   m.m[0][2] = 0;
   m.m[1][0] = 0;
   m.m[1][1] = 1;
   m.m[1][2] = 0;
   m.m[2][0] = 0;
   m.m[2][1] = 0;
   m.m[2][2] = 1;
   m.m[3][0] = 0;
   m.m[3][1] = 0;
   m.m[3][2] = 0;
   m.m[3][3] = 1;
  }

  inline void zero()
  {
   m.m[0][0] = 0;
   m.m[0][1] = 0;
   m.m[0][2] = 0;
   m.m[0][3] = 0;

   m.m[1][0] = 0;
   m.m[1][1] = 0;
   m.m[1][2] = 0;
   m.m[1][3] = 0;

   m.m[2][0] = 0;
   m.m[2][1] = 0;
   m.m[2][2] = 0;
   m.m[2][3] = 0;

   m.m[3][0] = 0;
   m.m[3][1] = 0;
   m.m[3][2] = 0;
   m.m[3][3] = 0;
  }

  inline Type* ptr()
  {
   return (Type*) m.M;
  }
  
  inline const Type* ptr() const
  {
   return (Type*) m.M;
  }


  void columnMajor(Type* f_16)
  {
   f_16[0]  = m.m[0][0];
   f_16[4]  = m.m[0][1];
   f_16[8]  = m.m[0][2];
   f_16[1]  = m.m[1][0];
   f_16[5]  = m.m[1][1];
   f_16[9]  = m.m[1][2];
   f_16[2]  = m.m[2][0];
   f_16[6]  = m.m[2][1];
   f_16[10] = m.m[2][2];
   f_16[12] = m.m[0][3];
   f_16[13] = m.m[1][3];
   f_16[14] = m.m[2][3];
   f_16[3]  = f_16[7] = f_16[11] = Type(0.0);
   f_16[15] = Type(1.0);
  }


  // This function was adopted from the OGRE3D Library, Matrix4 class from http://www.ogre3d.org
  VectorType operator*(const VectorType& other) const
  {
   Type fInvW = 1.0 / (m.m[3][0] * other.x + m.m[3][1] * other.y + m.m[3][2] * other.z + m.m[3][3]);
   return VectorType(
         (m.m[0][0] * other.x + m.m[0][1] * other.y + m.m[0][2] * other.z + m.m[0][3]) * fInvW,
         (m.m[1][0] * other.x + m.m[1][1] * other.y + m.m[1][2] * other.z + m.m[1][3]) * fInvW,
         (m.m[2][0] * other.x + m.m[2][1] * other.y + m.m[2][2] * other.z + m.m[2][3]) * fInvW
         );
  }
  
  protected:
  
   union
   {
    Type M[16];
    Type m[4][4];
   } m;
  
 };


};


#endif
