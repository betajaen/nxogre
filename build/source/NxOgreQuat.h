/** File: NxOgreQuat.h
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

#ifndef NXOGRE_QUAT_H
#define NXOGRE_QUAT_H

                                                                                       

#include "NxOgreStable.h"

                                                                                       

namespace NxOgre
{

                                                                                       

class Matrix33;
class Matrix44;


class NxOgrePublicClass Quat
{
 
 public:
  
 Quat(void);
 
 Quat(const Quat& other);

 Quat(const Real& w_val, const Real& x_val, const Real& y_val, const Real& z_val);
  
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

 Real w, x, y, z;

};


                                                                                       

} // namespace NxOgre

                                                                                       

#endif
