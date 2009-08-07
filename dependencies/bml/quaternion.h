/** File: quaternion.h
    Created on: 12-May-09
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

#ifndef quaternion_h_19519663_db0f_4c2e_b21e_4f717eb78040
#define quaternion_h_19519663_db0f_4c2e_b21e_4f717eb78040

#include "bml/prototypes.h"
#include "bml/math.h"
#include "bml/vector.h"
#include "bml/matrix.h"

namespace bml
{
 
 template<typename Type> class QuaternionT
 {
  
  public:
   
   QuaternionT(void)
   {
    identity();
   }
   
   QuaternionT(const QuaternionT<Type>& other)
   {
    set(other);
   }

   QuaternionT(const Type& w_val, const Type& x_val, const Type& y_val, const Type& z_val)
   {
    setWXYZ(w_val, x_val, y_val, z_val);
   }
   
   QuaternionT(const Matrix33T<Type>& other)
   {
    set(other);
   }
   
   QuaternionT(const Matrix44T<Type>& other)
   {
    set(other);
   }
  
   template<typename wxyz_quaternion_class>
   inline QuaternionT(const wxyz_quaternion_class& other)
   {
    setWXYZ(other.w, other.x, other.y, other.z);
   }

   ~QuaternionT(void)
   {
   }
   
   template<typename wxyz_quaternion_class>
   inline QuaternionT<Type> operator=(const wxyz_quaternion_class& other)
   {
    set(other.w, other.x, other.y, other.z);
    return *this;
   }

   inline QuaternionT<Type> operator=(const Matrix33T<Type>& other)
   {
    set(other);
    return *this;
   }
   
   inline QuaternionT<Type> operator=(const Matrix44T<Type>& other)
   {
    set(other);
    return *this;
   }
   
   // This function was adopted from the OGRE3D Library, Quaternion class from http://www.ogre3d.org
   void set(const Matrix33T<Type>& kRot)
   {

     // Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes
     // article "Quaternion Calculus and Fast Animation".

     Type fTrace = kRot[0][0]+kRot[1][1]+kRot[2][2];
     Type fRoot;

     if ( fTrace > 0.0 )
     {
         // |w| > 1/2, may as well choose w > 1/2
         fRoot = ::bml::math::sqrt(fTrace + (Type) 1.0);  // 2w
         w = (Type) 0.5 * fRoot;
         fRoot = (Type) 0.5 / fRoot;  // 1/(4w)
         x = (kRot[2][1]-kRot[1][2])*fRoot;
         y = (kRot[0][2]-kRot[2][0])*fRoot;
         z = (kRot[1][0]-kRot[0][1])*fRoot;
     }
     else
     {
         // |w| <= 1/2
         static size_t s_iNext[3] = { 1, 2, 0 };
         size_t i = 0;
         if ( kRot[1][1] > kRot[0][0] )
             i = 1;
         if ( kRot[2][2] > kRot[i][i] )
             i = 2;
         size_t j = s_iNext[i];
         size_t k = s_iNext[j];

         fRoot = ::bml::math::sqrt(kRot[i][i]-kRot[j][j]-kRot[k][k] + (Type) 1.0);
         Type* apkQuat[3] = { &x, &y, &z };
         *apkQuat[i] = (Type) 0.5 * fRoot;
         fRoot = (Type) 0.5 /fRoot;
         w = (kRot[k][j]-kRot[j][k])*fRoot;
         *apkQuat[j] = (kRot[j][i]+kRot[i][j])*fRoot;
         *apkQuat[k] = (kRot[k][i]+kRot[i][k])*fRoot;
     }
   }

   // This function was adopted from the OGRE3D Library, Quaternion class from http://www.ogre3d.org
   void set(const Matrix44T<Type>& kRot)
   {

     // Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes
     // article "Quaternion Calculus and Fast Animation".

     Type fTrace = kRot[0][0]+kRot[1][1]+kRot[2][2];
     Type fRoot;

     if ( fTrace > 0.0 )
     {
         // |w| > 1/2, may as well choose w > 1/2
         fRoot = ::bml::math::sqrt(fTrace + (Type) 1.0);  // 2w
         w = (Type) 0.5 * fRoot;
         fRoot = (Type) 0.5 / fRoot;  // 1/(4w)
         x = (kRot[2][1]-kRot[1][2])*fRoot;
         y = (kRot[0][2]-kRot[2][0])*fRoot;
         z = (kRot[1][0]-kRot[0][1])*fRoot;
     }
     else
     {
         // |w| <= 1/2
         static size_t s_iNext[3] = { 1, 2, 0 };
         size_t i = 0;
         if ( kRot[1][1] > kRot[0][0] )
             i = 1;
         if ( kRot[2][2] > kRot[i][i] )
             i = 2;
         size_t j = s_iNext[i];
         size_t k = s_iNext[j];

         fRoot = ::bml::math::sqrt(kRot[i][i]-kRot[j][j]-kRot[k][k] + (Type) 1.0);
         Type* apkQuat[3] = { &x, &y, &z };
         *apkQuat[i] = (Type) 0.5 * fRoot;
         fRoot = (Type) 0.5 /fRoot;
         w = (kRot[k][j]-kRot[j][k])*fRoot;
         *apkQuat[j] = (kRot[j][i]+kRot[i][j])*fRoot;
         *apkQuat[k] = (kRot[k][i]+kRot[i][k])*fRoot;
     }
   }

   void set(const QuaternionT<Type>& other)
   {
    w = other.w;
    x = other.x;
    y = other.y;
    z = other.z;
   }

   void setXYZW(const Type& x_val, const Type& y_val, const Type& z_val, const Type& w_val)
   {
    w = w_val;
    x = x_val;
    y = y_val;
    z = z_val;
   }

   void setWXYZ(const Type& w_val, const Type& x_val, const Type& y_val, const Type& z_val)
   {
    w = w_val;
    x = x_val;
    y = y_val;
    z = z_val;
   }

   void identity()
   {
    w = (Type) 1;
    x = (Type) 0;
    y = (Type) 0;
    z = (Type) 0;
   }

   Type dot(const QuaternionT& q) const
   {
    return Type( (w * q.w) + 
                 (x * q.x) + 
                 (y * q.y) + 
                 (z * q.z)  );
   }

   Type lengthSquared()
   {
    return dot(this);
   }

   Type length()
   {
    return ::bml::math::sqrt(lengthSquared());
   }

   void normalise()
   {
    Type l = length();
    if (l < (Type) 1E-4)
     return;
    
    Type inv = (Type) 1.0 / l;
    x *= inv;
    y *= inv;
    z *= inv;
    w *= inv;
   }

   bool isNormalised(Type epsilon_tolerance = 1E-4)
   {
    return ::bml::math::nearEqual( lengthSquared(), (Type) 1, epsilon_tolerance);
   }

   void conj()
   {
    x = -x;
    y = -y;
    z = -z;
   }

   void invert()
   {
    conj();
    
    Type l = lengthSquared();
    if (l < (Type) 1E-4)
     return;
    
    Type inv = (Type) 1.0 / l;
    x *= inv;
    y *= inv;
    z *= inv;
    w *= inv;
   }

   static QuaternionT<Type> invert(const QuaternionT<Type>& original)
   {
    QuaternionT<Type> r(original);
    r.invert();
    return r;
   }

   bool nearly(const QuaternionT<Type>& a, const QuaternionT<Type>& b, const Type& tolerance = 1E-4)
   {
    return bool( ::bml::math::equal( a.w, b.w, tolerance) &&
                 ::bml::math::equal( a.x, b.x, tolerance) &&
                 ::bml::math::equal( a.y, b.y, tolerance) &&
                 ::bml::math::equal( a.z, b.z, tolerance) );
   }

   static QuaternionT<Type> lerp(const QuaternionT<Type>& a, const QuaternionT<Type>& b, const Type& alpha)
   {
    Type cosom = a.dot(b);
    
    QuaternionT<Type> q;
    
    if (cosom < (Type) 0.0)
    {
     q.w = -b.w;
     q.x = -b.x;
     q.y = -b.y;
     q.z = -b.z;
    }
    else
    {
     q = b;
    }

    Type sclp, sclq;
    sclp = (Type) 1.0 - alpha;
    sclq = alpha;

    QuaternionT<Type> result;
    result.w = sclp * a.w + sclq * q.w;
    result.x = sclp * a.x + sclq * q.x;
    result.y = sclp * a.y + sclq * q.y;
    result.z = sclp * a.z + sclq * q.z;
    return result;
   }

   static QuaternionT<Type> slerp(const QuaternionT<Type>& a, const QuaternionT<Type>& b, const Type& alpha, bool adjustSign = true)
   {
    Type cosom = a.dot(b);
    
    QuaternionT<Type> q;
    
    if (cosom < (Type) 0.0)
    {
     cosom = -cosom;
     q.w = -b.w;
     q.x = -b.x;
     q.y = -b.y;
     q.z = -b.z;
    }
    else
    {
     q = b;
    }

    Type sclp, sclq;
    if ( ((Type) 1.0 - cosom) > (Type) 1E-4)
    {
     Type omega, sinom;
     omega = ::bml::math::arccos(cosom);
     sinom = ::bml::math::sin(omega);
     sclp  = ::bml::math::sin( ( (Type) 1.0 - alpha) * omega ) / sinom;
     sclq  = ::bml::math::sin( alpha * omega) / sinom;
    }
    else
    {
     sclp = (Type) 1.0 - alpha;
     sclq = alpha;
    }

    QuaternionT<Type> result;
    result.w = sclp * a.w + sclq * q.w;
    result.x = sclp * a.x + sclq * q.x;
    result.y = sclp * a.y + sclq * q.y;
    result.z = sclp * a.z + sclq * q.z;
    return result;
   }


   Type& operator[](const size_t i)
   {
    return (&x)[i];
   }

   const Type& operator[](const size_t i) const
   {
    return (&x)[i];
   }

   static inline void multiply(QuaternionT<Type>& r, const QuaternionT<Type>& a, const QuaternionT<Type>& b)
   {
    r.x = (a.w * b.x) + (a.x * b.w) + (a.y * b.z) - (a.z * b.y);
    r.y = (a.w * b.y) + (a.y * b.w) + (a.z * b.x) - (a.x * b.z);
    r.z = (a.w * b.z) + (a.z * b.w) + (a.x * b.y) - (a.y * b.x);
    r.w = (a.w * b.w) - (a.x * b.x) - (a.y * b.y) - (a.z * b.z);
   }

   static inline void multiply(QuaternionT<Type>& r, const QuaternionT<Type>& a, const Type& s)
   {
    r.w = a.w * s;
    r.x = a.x * s;
    r.y = a.y * s;
    r.z = a.z * s;
   }

   static inline void divide(QuaternionT<Type>& r, const QuaternionT<Type>& a, const QuaternionT<Type>& b)
   {
    mult(r, a, b.invert());
   };

   static inline void divide(QuaternionT<Type>& r, const QuaternionT<Type>& a, const Type& s)
   {
    r.w = a.w / s;
    r.x = a.x / s;
    r.y = a.y / s;
    r.z = a.z / s;
   };

   static inline void add(QuaternionT<Type>& r, const QuaternionT<Type>& a, const QuaternionT<Type>& b)
   {
    r.w = a.w + b.w;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
   };

   static inline QuaternionT<Type> subtract(QuaternionT<Type>& r, const QuaternionT<Type>& a, const QuaternionT<Type>& b)
   {
    r.w = a.w + b.w;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
   };

   inline bool operator == (const QuaternionT<Type>& other) const
   {
    return (w == other.w && x == other.x && y == other.y && z == other.z);
   }

   inline bool operator != (const QuaternionT<Type>& other) const
   {
    return (w != other.w || x != other.x || y != other.y || z != other.z);
   }

   inline QuaternionT<Type> operator + ( const QuaternionT<Type>& other)
   {
    QuaternionT<Type> r;
    add(r, *this, other);
    return r;
   }
   
   inline void operator +=(const QuaternionT<Type>& other)
   {
    QuaternionT<Type> r;
    add(r, *this, other);
    set(r);
   }

   inline QuaternionT<Type> operator - ( const QuaternionT<Type>& other)
   {
    QuaternionT<Type> r;
    subtract(r, *this, other);
    return r;
   }

   inline void operator -=(const QuaternionT<Type>& other)
   {
    QuaternionT<Type> r;
    subtract(r, *this, other);
    set(r);
   }

   inline QuaternionT<Type> operator * ( const QuaternionT<Type>& other)
   {
    QuaternionT<Type> r;
    multiply(r, *this, other);
    return r;
   }

   inline void operator *= (const QuaternionT<Type>& other)
   {
    QuaternionT<Type> r;
    multiply(r, *this, other);
    set(r);
   }

   inline QuaternionT<Type> operator * (Type scalar)
   {
    QuaternionT<Type> r;
    multiply(r, *this, scalar);
    return r;
   }

   inline void operator *= (Type scalar)
   {
    QuaternionT<Type> r;
    multiply(r, *this, scalar);
    set(r);
   }

   inline QuaternionT<Type> operator / ( const QuaternionT<Type>& other)
   {
    QuaternionT<Type> r;
    divide(r, *this, other);
    return r;
   }

   inline void operator /=( const QuaternionT<Type>& other)
   {
    QuaternionT<Type> r;
    divide(r, *this, other);
    set(r);
   }

   inline QuaternionT<Type> operator / ( const Type& scalar)
   {
    QuaternionT<Type> r;
    divide(r, *this, other);
    return r;
   }

   inline void operator /=( const Type& scalar)
   {
    QuaternionT<Type> r;
    divide(r, *this, other);
    set(r);
   }

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

   Type w, x, y, z;

 };


} // namespace

#endif
