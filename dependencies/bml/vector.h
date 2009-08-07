/** File: vector.h
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

#ifndef vector_h_52ca7bed_2eb8_4257_98a7_9d06414f54db
#define vector_h_52ca7bed_2eb8_4257_98a7_9d06414f54db

#include "bml/prototypes.h"
#include "bml/math.h"
#include "bml/matrix.h"

namespace bml
{

// ---------------------------------------------------------------------------------------------

template <typename Type> class Vector2
{
 public:
  
  typedef Vector2<Type> VectorType;
  typedef Type Type;
  enum
  {
   Size = 2
  };

  inline Vector2()
  {
   zero();
  }

  inline Vector2(const VectorType& other)
  {
   set(other);
  }
  
  inline Vector2(const Type& X, const Type& Y)
  {
   set(X, Y);
  };
  
  inline void set(const Type& X, const Type& Y)
  {
   x = X; y = Y;
  }
  
  inline void set(const VectorType& other)
  {
   x = other.x;
   y = other.y;
  }
  
  inline Type* ptr()
  {
   return &x;
  }

  inline const Type* ptr() const
  {
   return &x;
  }

  inline Type normalise()
  {
   const Type length = magnitudeSquared();
   if (length < 1E-8)
   {
    const Type inv = (Type) 1.0 / length;
    x *= inv;
    y *= inv;
   }
   return length;
  }

  inline VectorType mid(const VectorType& other) const
  {
   return VectorType((x + other.x) * 0.5, (y + other.y) * 0.5);
  }
  
  inline Type dot(const VectorType& other) const
  {
   return (x * other.x) + (y * other.y);
  }

  inline Type cross(const VectorType& other)
  {
   return (x * other.y) - (y * other.x);
  }

  inline Type magnitudeSquared() const
  {
   return (x * x) + (y * y);
  }

  inline Type magnitude() const
  {
   return ::bml::math::sqrt(magnitudeSquared());
  }

  inline void min(const VectorType& other)
  {
   x = ::bml::math::min(x, other.x);
   y = ::bml::math::min(y, other.y);
  }

  inline void max(const VectorType& other)
  {
   x = ::bml::math::max(x, other.x);
   y = ::bml::math::max(y, other.y);
  }

  inline void fill(const Type& value)
  {
   x = y = value;
  }

  inline void zero()
  {
   fill((Type)0);
  }

  inline bool isZero() const
  {
   return ((x == (Type) 0) && (y == (Type) 0));
  }

  inline VectorType lerp(const VectorType& other, const Type& alpha) const
  {
   return VectorType(::bml::math::lerp(x, other.x, alpha),::bml::math::lerp(y, other.y, alpha));
  }

  inline VectorType operator=(const VectorType& other)
  {
   set(other);
   return *this;
  }

  inline bool operator<=(const VectorType& other) const
  {
   return ((x <= other.x) && (y <= other.y));
  }

  inline bool operator>=(const VectorType& other) const
  {
   return ((x >= other.x) && (y >= other.y));
  }

  inline bool operator<(const VectorType& other) const
  {
   return ((x < other.x) && (y < other.y));
  }

  inline bool operator>(const VectorType& other) const
  {
   return ((x > other.x) && (y > other.y));
  }

  inline bool operator==(const VectorType& other) const
  {
   return ((x == other.x) && (y == other.y));
  }

  inline bool operator!=(const VectorType& other) const
  {
   return ((x != other.x) || (y != other.y));
  }

  inline VectorType operator+(const VectorType& other)
  {
   return VectorType(x + other.x, y + other.y);
  }

  inline VectorType operator+(const VectorType& other) const
  {
   return VectorType(x + other.x, y + other.y);
  }


  inline void operator+=(const VectorType& other)
  {
   x += other.x;
   y += other.y;
  }

  inline VectorType operator-(const VectorType& other)
  {
   return VectorType(x - other.x, y - other.y);
  }

  inline VectorType operator-(const VectorType& other) const
  {
   return VectorType(x - other.x, y - other.y);
  }

  inline void operator-=(const VectorType& other)
  {
   x -= other.x;
   y -= other.y;
  }

  inline VectorType operator*(const VectorType& other)
  {
   return VectorType(x * other.x, y * other.y);
  }

  inline void operator*=(const VectorType& other)
  {
   x *= other.x;
   y *= other.y;
  }

  inline VectorType operator*(const Type& s)
  {
   return VectorType(x * s, y * s);
  }

  inline void operator*=(const Type& s)
  {
   x *= s;
   y *= s;
  }

  inline friend VectorType operator*(const Type& s, const VectorType& vector)
  {
   return VectorType(vector.x * s, vector.y * s);
  }

  inline void operator/=(const VectorType& other)
  {
   x /= other.x;
   y /= other.y;
  }

  inline VectorType operator/(const VectorType& other)
  {
   return VectorType(x * other.x, y * other.y);
  }

  inline void operator/=(const Type& s)
  {
   const Type inv = (Type) 1.0 / s;
   x *= inv;
   y *= inv;
  }

  inline VectorType operator/(const Type& s)
  {
   const Type inv = (Type) 1.0 / s;
   return VectorType(x * inv, y * inv);
  }

  inline VectorType operator+() const
  {
   return *this;
  }

  inline VectorType operator-() const
  {
   return VectorType(-x, -y);
  }

  inline Type& operator[](const size_t i)
  {
   return (&x)[i];
  }
  
  inline const Type& operator[](const size_t i) const
  {
   return (&x)[i];
  }

  Type x, y;
};

// ---------------------------------------------------------------------------------------------

template <typename Type> class Vector3
{
 public:
  
  typedef Vector3<Type> VectorType;
  typedef Type Type;
  
  enum
  {
   Size = 3
  };

  inline Vector3()
  {
   zero();
  }

  inline Vector3(const VectorType& other)
  {
   set(other);
  }

  template<typename xyz_vector_class>
  inline Vector3(const xyz_vector_class& other)
  {
   set(other.x, other.y, other.z);
  }

  inline Vector3(const Matrix44T<Type>& other)
  {
   other.get(x,y,z);
  }

  template<typename xyz_vector_class>
  inline VectorType operator=(const xyz_vector_class& other)
  {
   set(other.x, other.y, other.z);
   return *this;
  }

  
  inline Vector3(const Type& X, const Type& Y, const Type& Z)
  {
   set(X, Y, Z);
  };
  
  inline void set(const Type& X, const Type& Y, const Type& Z)
  {
   x = X; y = Y; z = Z;
  }
  
  inline void set(const VectorType& other)
  {
   x = other.x;
   y = other.y;
   z = other.z;
  }
  
  inline Type* ptr()
  {
   return &x;
  }

  inline const Type* ptr() const
  {
   return &x;
  }

  inline Type normalise()
  {
   Type length = magnitude();
   if (length)
   {
    Type inv = (Type) 1.0 / length;
    x *= inv;
    y *= inv;
    z *= inv;
   }
   return length;
  }

  inline VectorType mid(const VectorType& other) const
  {
   return VectorType((x + other.x) * 0.5, (y + other.y) * 0.5, (z + other.z) * 0.5);
  }
  
  inline Type dot(const VectorType& other) const
  {
   return (x * other.x) + (y * other.y) + (z * other.z);
  }

  inline VectorType cross(const VectorType& other)
  {
   return VectorType(
    y * other.z - z * other.y,
    z * other.x - x * other.z,
    x * other.y - y * other.x
   );
  }

  inline Type distance(const VectorType& other) const
  {
   return VectorType(x - other.x, y - other.y, z - other.z).magnitude();
  }

  inline Type distanceSquared(const VectorType& other) const
  {
   return VectorType(x - other.x, y - other.y, z - other.z).magnitudeSquared();
  }

  inline Type magnitudeSquared() const
  {
   return (x * x) + (y * y) + (z * z);
  }

  inline Type magnitude() const
  {
   return ::bml::math::sqrt(magnitudeSquared());
  }

  inline void min(const VectorType& other)
  {
   x = ::bml::math::min(x, other.x);
   y = ::bml::math::min(y, other.y);
   z = ::bml::math::min(z, other.z);
  }

  inline void max(const VectorType& other)
  {
   x = ::bml::math::max(x, other.x);
   y = ::bml::math::max(y, other.y);
   z = ::bml::math::max(z, other.z);
  }

  inline void fill(const Type& value)
  {
   x = y = z = value;
  }

  inline void zero()
  {
   fill((Type)0);
  }

  inline bool isZero() const
  {
   return (x == (Type) 0) && (y == (Type) 0) && (z == (Type) 0) ;
  }

  inline VectorType lerp(const VectorType& other, const Type& alpha) const
  {
   return VectorType(::bml::math::lerp(x, other.x, alpha),::bml::math::lerp(y, other.y, alpha),::bml::math::lerp(z, other.z, alpha));
  }

  inline VectorType operator=(const VectorType& other)
  {
   set(other);
   return *this;
  }

  inline bool operator<(const VectorType& other) const
  {
   return ((x < other.x) && (y < other.y) && (z < other.z));
  }

  inline bool operator<=(const VectorType& other) const
  {
   return ((x <= other.x) && (y <= other.y) && (z <= other.z));
  }

  inline bool operator>=(const VectorType& other) const
  {
   return ((x >= other.x) && (y >= other.y) && (z >= other.z));
  }

  inline bool operator>(const VectorType& other) const
  {
   return ((x > other.x) && (y > other.y) && (z > other.z));
  }

  inline bool operator==(const VectorType& other) const
  {
   return ((x == other.x) && (y == other.y) && (z == other.z));
  }

  inline bool operator!=(const VectorType& other) const
  {
   return ((x != other.x) || (y != other.y) || (z != other.z));
  }

  inline VectorType operator+(const VectorType& other)
  {
   return VectorType(x + other.x, y + other.y, z + other.z);
  }

  inline VectorType operator+(const VectorType& other) const
  {
   return VectorType(x + other.x, y + other.y, z + other.z);
  }

  inline Matrix44T<Type> operator+(const QuaternionT<Type>& other)
  {
   return Matrix44T<Type>(*this, other);
  }


  inline void operator+=(const VectorType& other)
  {
   x += other.x;
   y += other.y;
   z += other.z;
  }

  inline VectorType operator-(const VectorType& other)
  {
   return VectorType(x - other.x, y - other.y, z - other.z);
  }

  inline VectorType operator-(const VectorType& other) const
  {
   return VectorType(x - other.x, y - other.y, z - other.z);
  }

  inline void operator-=(const VectorType& other)
  {
   x -= other.x;
   y -= other.y;
   z -= other.z;
  }

  inline VectorType operator*(const VectorType& other)
  {
   return VectorType(x * other.x, y * other.y, z * other.z);
  }

  inline void operator*=(const VectorType& other)
  {
   x *= other.x;
   y *= other.y;
   z *= other.z;
  }

  inline VectorType operator*(const Type& s)
  {
   return VectorType(x * s, y * s, z * s);
  }

  inline void operator*=(const Type& s)
  {
   x *= s;
   y *= s;
   z *= s;
  }

   // This function was adopted from the OGRE3D Library, Quaternion class from http://www.ogre3d.org
  inline VectorType operator*(const QuaternionT<Type>& quat)
  {
   VectorType uv, uuv, qvec(quat.x, quat.y, quat.z);
   uv = qvec.cross(*this);
   uuv = qvec.cross(uv);
   uv *= (2.0f * quat.w);
   uuv *= 2.0f;
   return *this + uv + uuv;
  }

  inline friend VectorType operator*(const Type& s, const VectorType& vector)
  {
   return VectorType(vector.x * s, vector.y * s, vector.z * s);
  }

  inline friend VectorType operator*(const VectorType& vector, const Type& s)
  {
   return VectorType(vector.x * s, vector.y * s, vector.z * s);
  }

  inline void operator/=(const VectorType& other)
  {
   x /= other.x;
   y /= other.y;
   z /= other.z;
  }

  inline VectorType operator/(const VectorType& other)
  {
   return VectorType(x * other.x, y * other.y, z * other.z);
  }

  inline void operator/=(const Type& s)
  {
   const Type inv = (Type) 1.0 / s;
   x *= inv;
   y *= inv;
   z *= inv;
  }

  inline VectorType operator/(const Type& s)
  {
   const Type inv = (Type) 1.0 / s;
   return VectorType(x * inv, y * inv, z * inv);
  }

  inline VectorType operator+() const
  {
   return *this;
  }

  inline VectorType operator-() const
  {
   return VectorType(-x, -y, -z);
  }

  inline Type& operator[](const size_t i)
  {
   return (&x)[i];
  }
  
  inline const Type& operator[](const size_t i) const
  {
   return (&x)[i];
  }

  template<class user_xyz_vector_type>
  inline user_xyz_vector_type as() const
  {
   user_xyz_vector_type v;
   v.x = x;
   v.y = y;
   v.z = z;
   return v;
  }

  static const VectorType ZERO;

  Type x, y, z;
};

// ---------------------------------------------------------------------------------------------

template <typename Type> class Vector4
{
 public:
  
  typedef Vector4<Type> VectorType;
  
  enum
  {
   Size = 4
  };

  inline Vector4()
  {
   zero();
  }

  inline Vector4(const VectorType& other)
  {
   set(other);
  }
  
  inline Vector4(const Type& W, const Type& X, const Type& Y, const Type& Z)
  {
   set(W, X, Y, Z);
  };
  
  inline void set(const Type& W,const Type& X, const Type& Y, const Type& Z)
  {
   w = W; x = X; y = Y; z = Z;
  }
  
  inline void set(const VectorType& other)
  {
   w = other.w;
   x = other.x;
   y = other.y;
   z = other.z;
  }
  
  inline Type* ptr()
  {
   return &x;
  }

  inline const Type* ptr() const
  {
   return &x;
  }

  inline Type normalise()
  {
   const Type length = magnitudeSquared();
   if (length < 1E-8)
   {
    const Type inv = (Type) 1.0 / length;
    w *= inv;
    x *= inv;
    y *= inv;
    z *= inv;
   }
   return length;
  }

  inline VectorType mid(const VectorType& other) const
  {
   return VectorType( (w + other.w) * 0.5, (x + other.x) * 0.5, (y + other.y) * 0.5, (z + other.z) * 0.5);
  }
  
  inline Type magnitudeSquared() const
  {
   return (w * w) + (x * x) + (y * y) + (z * z);
  }

  inline Type magnitude() const
  {
   return ::bml::math::sqrt(magnitudeSquared());
  }

  inline void min(const VectorType& other)
  {
   w = ::bml::math::min(w, other.w);
   x = ::bml::math::min(x, other.x);
   y = ::bml::math::min(y, other.y);
   z = ::bml::math::min(z, other.z);
  }

  inline void max(const VectorType& other)
  {
   w = ::bml::math::max(w, other.w);
   x = ::bml::math::max(x, other.x);
   y = ::bml::math::max(y, other.y);
   z = ::bml::math::max(z, other.z);
  }

  inline void fill(const Type& value)
  {
   w = x = y = z = value;
  }

  inline void zero()
  {
   fill((Type)0);
  }

  inline bool isZero() const
  {
   return ((w == (Type) 0) &&  (x == (Type) 0) && (y == (Type) 0) && (z == (Type) 0));
  }

  inline VectorType lerp(const VectorType& other, const Type& alpha) const
  {
   return VectorType(::bml::math::lerp(x, other.x, alpha), ::bml::math::lerp(x, other.x, alpha),::bml::math::lerp(y, other.y, alpha),::bml::math::lerp(z, other.z, alpha));
  }

  inline VectorType operator=(const VectorType& other)
  {
   set(other);
   return *this;
  }

  inline bool operator<(const VectorType& other) const
  {
   return ((w < other.w) && (x < other.x) && (y < other.y) && (z < other.z));
  }

  inline bool operator>(const VectorType& other) const
  {
   return ((w > other.w) && (x > other.x) && (y > other.y) && (z > other.z));
  }

  inline bool operator==(const VectorType& other) const
  {
   return ((w == other.w) && (x == other.x) && (y == other.y) && (z == other.z));
  }

  inline bool operator!=(const VectorType& other) const
  {
   return ((w != other.w) || (x != other.x) || (y != other.y) || (z != other.z));
  }

  inline VectorType operator+(const VectorType& other)
  {
   return VectorType(w + other.w, x + other.x, y + other.y, z + other.z);
  }

  inline VectorType operator+(const VectorType& other) const
  {
   return VectorType(w + other.w, x + other.x, y + other.y, z + other.z);
  }

  inline void operator+=(const VectorType& other)
  {
   w += other.w;
   x += other.x;
   y += other.y;
   z += other.z;
  }

  inline VectorType operator-(const VectorType& other) const
  {
   return VectorType(w - other.w, x - other.x, y - other.y, z - other.z);
  }

  inline VectorType operator-(const VectorType& other)
  {
   return VectorType(w - other.w, x - other.x, y - other.y, z - other.z);
  }

  inline void operator-=(const VectorType& other)
  {
   w -= other.w;
   x -= other.x;
   y -= other.y;
   z -= other.z;
  }

  inline VectorType operator*(const VectorType& other)
  {
   return VectorType(w * other.w, x * other.x, y * other.y, z * other.z);
  }

  inline void operator*=(const VectorType& other)
  {
   w *= other.w;
   x *= other.x;
   y *= other.y;
   z *= other.z;
  }

  inline VectorType operator*(const Type& s)
  {
   return VectorType(w * s, x * s, y * s, z * s);
  }

  inline void operator*=(const Type& s)
  {
   w *= s;
   x *= s;
   y *= s;
   z *= s;
  }

  inline friend VectorType operator*(const Type& s, const VectorType& vector)
  {
   return VectorType(vector.w * s, vector.x * s, vector.y * s, vector.z * s);
  }

  inline void operator/=(const VectorType& other)
  {
   w /= other.w;
   x /= other.x;
   y /= other.y;
   z /= other.z;
  }

  inline VectorType operator/(const VectorType& other)
  {
   return VectorType(w * other.w, x * other.x, y * other.y, z * other.z);
  }

  inline void operator/=(const Type& s)
  {
   const Type inv = (Type) 1.0 / s;
   w *= inv;
   x *= inv;
   y *= inv;
   z *= inv;
  }

  inline VectorType operator/(const Type& s)
  {
   const Type inv = (Type) 1.0 / s;
   return VectorType(w * inv, x * inv, y * inv, z * inv);
  }

  inline VectorType operator+() const
  {
   return *this;
  }

  inline VectorType operator-() const
  {
   return VectorType(-w, -x, -y, -z);
  }

  inline Type& operator[](const size_t i)
  {
   return (&x)[i];
  }
  
  inline const Type& operator[](const size_t i) const
  {
   return (&x)[i];
  }

  Type w, x, y, z;
};

// ---------------------------------------------------------------------------------------------

#if 0
  template<typename Type>
  inline Matrix44T<Type> operator+(const Vector3<Type>& vec, const QuaternionT<Type>& quat)
  {
   return Matrix44T<Type>(vec, quat);
  }
#endif

} // namespace bml

#endif
