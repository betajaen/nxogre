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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreMatrix.h"
#include "NxOgreVec3.h"
#include "NxOgreQuat.h"
#include "NxOgreMath.h"

                                                                                       

namespace NxOgre
{

#if NxOgreFloatingPointAccuracy == NxOgreFloatingPointDouble

const Matrix33 Matrix33::ZERO(0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0);

const Matrix33 Matrix33::IDENTITY(1.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,1.0);

const Matrix44 Matrix44::ZERO(0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0)

const Matrix44 Matrix44::IDENTITY(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0)

#else

const Matrix33 Matrix33::ZERO(0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);

const Matrix33 Matrix33::IDENTITY(1.0f,0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,1.0f);

const Matrix44 Matrix44::ZERO(0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);

const Matrix44 Matrix44::IDENTITY(1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,0.0f,1.0f);

#endif

                                                                                       

Matrix33::Matrix33()
{
}

Matrix33::Matrix33(const Real& _00, const Real& _01, const Real& _02,
                const Real& _10, const Real& _11, const Real& _12,
                const Real& _20, const Real& _21, const Real& _22)
{
 set(_00, _01, _02, _10, _11, _12, _20, _21, _22);
}

Matrix33::Matrix33(const Real mem[Rows][Cols])
{
 set(mem);
}

Matrix33::Matrix33(const Matrix33& other)
{
 set(other.m.m);
}

Matrix33::Matrix33(const Quat& quat)
{
 set(quat.w, quat.x, quat.y, quat.z);
}

Matrix33 Matrix33::operator=(const Matrix33& other)
{
 set(other.m.m);
 return *this;
}

void Matrix33::set(const Matrix33& other)
{
 set(other.m.m);
}

void Matrix33::set(const Real mem[Rows][Cols])
{
 memcpy(m.m, mem, sizeof(Real) * Size);
}

void Matrix33::set(const Quat& quat)
{
 set(quat.w, quat.x, quat.y, quat.z);
}

// This function was adopted from the OGRE3D Library, Matrix3 class from http://www.ogre3d.org
void Matrix33::set(const Real& w, const Real& x, const Real& y, const Real& z)
{
 Real fTx  = Real(2.0)*x;
 Real fTy  = Real(2.0)*y;
 Real fTz  = Real(2.0)*z;
 Real fTwx = fTx*w;
 Real fTwy = fTy*w;
 Real fTwz = fTz*w;
 Real fTxx = fTx*x;
 Real fTxy = fTy*x;
 Real fTxz = fTz*x;
 Real fTyy = fTy*y;
 Real fTyz = fTz*y;
 Real fTzz = fTz*z;

 m.m[0][0] = Real(1.0)-(fTyy+fTzz);
 m.m[0][1] = fTxy-fTwz;
 m.m[0][2] = fTxz+fTwy;
 m.m[1][0] = fTxy+fTwz;
 m.m[1][1] = Real(1.0)-(fTxx+fTzz);
 m.m[1][2] = fTyz-fTwx;
 m.m[2][0] = fTxz-fTwy;
 m.m[2][1] = fTyz+fTwx;
 m.m[2][2] = Real(1.0)-(fTxx+fTyy);
}

void Matrix33::set(const Real& _00, const Real& _01, const Real& _02,
                   const Real& _10, const Real& _11, const Real& _12,
                   const Real& _20, const Real& _21, const Real& _22)
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

Real* Matrix33::operator[](size_t row) const
{
 return (Real*) m.m[row];
}

void Matrix33::identity()
{
 m.m[0][0] = Real(1.0);
 m.m[0][1] = Real(0.0);
 m.m[0][2] = Real(0.0);

 m.m[1][0] = Real(0.0);
 m.m[1][1] = Real(1.0);
 m.m[1][2] = Real(0.0);

 m.m[2][0] = Real(0.0);
 m.m[2][1] = Real(0.0);
 m.m[2][2] = Real(1.0);
}

void Matrix33::zero()
{
 m.m[0][0] = Real(0.0);
 m.m[0][1] = Real(0.0);
 m.m[0][2] = Real(0.0);

 m.m[1][0] = Real(0.0);
 m.m[1][1] = Real(0.0);
 m.m[1][2] = Real(0.0);

 m.m[2][0] = Real(0.0);
 m.m[2][1] = Real(0.0);
 m.m[2][2] = Real(0.0);
}

Real* Matrix33::ptr()
{
 return (Real*) m.M;
}

const Real* Matrix33::ptr() const
{
 return (Real*) m.M;
}

inline String Matrix33::to_s() const
{
 std::ostringstream s;
 
 s << m.m[0][0] << ", " << m.m[0][1] << ", " << m.m[0][2] << ", "
   << m.m[1][0] << ", " << m.m[1][1] << ", " << m.m[1][2] << ", "
   << m.m[2][0] << ", " << m.m[2][1] << ", " << m.m[2][2];
 
 return s.str();
}


Matrix44::Matrix44()
{
}

Matrix44::Matrix44(const Real& _00, const Real& _01, const Real& _02, const Real& _03,
                   const Real& _10, const Real& _11, const Real& _12, const Real& _13,
                   const Real& _20, const Real& _21, const Real& _22, const Real& _23,
                   const Real& _30, const Real& _31, const Real& _32, const Real& _33
                  )
{
 set(_00, _01, _02, _03, _10, _11, _12, _13, _20, _21, _22, _23, _30, _31, _32, _33);
}

Matrix44::Matrix44(const Real mem[Rows][Cols])
{
 set(mem);
}

Matrix44::Matrix44(const Matrix44& other)
{
 set(other.m.m);
}

Matrix44::Matrix44(const Vec3& translation_component)
{
 rotationIdentity();
 set(translation_component.x, translation_component.y, translation_component.z);
}

Matrix44::Matrix44(const Quat& rotation_asquaternion_component)
{
 translationIdentity();
 set(rotation_asquaternion_component.w, rotation_asquaternion_component.x, rotation_asquaternion_component.y, rotation_asquaternion_component.z);
}

Matrix44::Matrix44(const Vec3& translation_component, const Quat& rotation_asquaternion_component)
{
 scaleIdentity();
 set(translation_component.x, translation_component.y, translation_component.z);
 set(rotation_asquaternion_component.w, rotation_asquaternion_component.x, rotation_asquaternion_component.y, rotation_asquaternion_component.z);

}

Matrix44 Matrix44::operator=(const Matrix44& other)
{
 set(other.m.m);
 return *this;
}

void Matrix44::set(const Matrix44& other)
{
 set(other.m.m);
}

void Matrix44::set(const Real mem[Rows][Cols])
{
 memcpy(m.m, mem, sizeof(Real) * Size);
}

void Matrix44::set(const Quat& quat)
{
 set(quat.w, quat.x, quat.y, quat.z);
}

void Matrix44::set(const Radian& angle, Enums::Axis axis)
{
 float Cos = NxOgre::Math::cos(angle.rad());
 float Sin = NxOgre::Math::sin(angle.rad());
 
 rotationIdentity();
 
 if (axis == Enums::X)
 {
  m.m[1][1] = m.m[2][2] = Cos;
  m.m[1][2] = -Sin;
  m.m[1][2] = Sin;
 }
 else if (axis == Enums::Y)
 {
  m.m[0][0] = m.m[2][2] = Cos;
  m.m[0][2] = -Sin;
  m.m[2][0] = Sin;
 }
 else if (axis == Enums::Z)
 {
  m.m[0][0] = m.m[1][1] = Cos;
  m.m[0][1] = -Sin;
  m.m[1][0] = Sin;
 }
}

// This function was adopted from the OGRE3D Library, Matrix3 class from http://www.ogre3d.org
void Matrix44::set(const Real& w, const Real& x, const Real& y, const Real& z)
{
 Real fTx  = Real(2.0)*x;
 Real fTy  = Real(2.0)*y;
 Real fTz  = Real(2.0)*z;
 Real fTwx = fTx*w;
 Real fTwy = fTy*w;
 Real fTwz = fTz*w;
 Real fTxx = fTx*x;
 Real fTxy = fTy*x;
 Real fTxz = fTz*x;
 Real fTyy = fTy*y;
 Real fTyz = fTz*y;
 Real fTzz = fTz*z;
 
 m.m[0][0] = Real(1.0)-(fTyy+fTzz);
 m.m[0][1] = fTxy-fTwz;
 m.m[0][2] = fTxz+fTwy;
 m.m[1][0] = fTxy+fTwz;
 m.m[1][1] = Real(1.0)-(fTxx+fTzz);
 m.m[1][2] = fTyz-fTwx;
 m.m[2][0] = fTxz-fTwy;
 m.m[2][1] = fTyz+fTwx;
 m.m[2][2] = Real(1.0)-(fTxx+fTyy);
}

void Matrix44::set(const Vec3& vec)
{
 set(vec.x, vec.y, vec.z);
}

void Matrix44::set(const Real& trans_x, const Real& trans_y, const Real& trans_z)
{
 m.m[0][3] = trans_x;
 m.m[1][3] = trans_y;
 m.m[2][3] = trans_z;
}

void Matrix44::get(Real& trans_x, Real& trans_y, Real& trans_z) const
{
 trans_x = m.m[0][3];
 trans_y = m.m[1][3];
 trans_z = m.m[2][3];
}

void Matrix44::set(const Real& _00, const Real& _01, const Real& _02, const Real& _03,
                   const Real& _10, const Real& _11, const Real& _12, const Real& _13,
                   const Real& _20, const Real& _21, const Real& _22, const Real& _23,
                   const Real& _30, const Real& _31, const Real& _32, const Real& _33
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

Real* Matrix44::operator[](size_t row) const
{
 return (Real*) m.m[row];
}

Matrix44::operator Vec3()
{
 return Vec3(m.m[0][3], m.m[1][3], m.m[2][3]);
}

Matrix44::operator Vec3() const
{
 return Vec3(m.m[0][3], m.m[1][3], m.m[2][3]);
}

void Matrix44::identity()
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

void Matrix44::translationIdentity()
{
 m.m[0][3] = 0;
 m.m[1][3] = 0;
 m.m[2][3] = 0;
 m.m[3][0] = 0;
 m.m[3][1] = 0;
 m.m[3][2] = 0;
 m.m[3][3] = 1;
}

void Matrix44::scaleIdentity()
{
 m.m[3][0] = 0;
 m.m[3][1] = 0;
 m.m[3][2] = 0;
 m.m[3][3] = 1;
}

void Matrix44::rotationIdentity()
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

void Matrix44::zero()
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

Real* Matrix44::ptr()
{
 return (Real*) m.M;
}

const Real* Matrix44::ptr() const
{
 return (Real*) m.M;
}

void Matrix44::columnMajor(Real* f_16)
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
 f_16[3]  = f_16[7] = f_16[11] = Real(0.0);
 f_16[15] = Real(1.0);
}

Vec3 Matrix44::operator*(const Vec3& other) const
{
 Real fInvW = 1.0 / (m.m[3][0] * other.x + m.m[3][1] * other.y + m.m[3][2] * other.z + m.m[3][3]);
 return Vec3(
       (m.m[0][0] * other.x + m.m[0][1] * other.y + m.m[0][2] * other.z + m.m[0][3]) * fInvW,
       (m.m[1][0] * other.x + m.m[1][1] * other.y + m.m[1][2] * other.z + m.m[1][3]) * fInvW,
       (m.m[2][0] * other.x + m.m[2][1] * other.y + m.m[2][2] * other.z + m.m[2][3]) * fInvW
       );
}

inline String Matrix44::to_s() const
{
 std::ostringstream s;
 
 s << m.m[0][0] << ", " << m.m[0][1] << ", " << m.m[0][2] << ", "<< m.m[0][3] << ", "
   << m.m[1][0] << ", " << m.m[1][1] << ", " << m.m[1][2] << ", "<< m.m[1][3] << ", "
   << m.m[2][0] << ", " << m.m[2][1] << ", " << m.m[2][2] << ", "<< m.m[2][3] << ", "
   << m.m[3][0] << ", " << m.m[3][1] << ", " << m.m[3][2] << ", "<< m.m[3][3];
 
 return s.str();
}

                                                                                       

} // namespace NxOgre

                                                                                       
