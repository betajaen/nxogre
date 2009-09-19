/** File: NxOgreXXX.h
    Created on: X-XXX-XX
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

#ifndef NXOGRE_MATH_H
#define NXOGRE_MATH_H

                                                                                       

#include "NxOgreStable.h"
#include "math.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Math
{

 static const float  Pi         = 3.141592653589793f;
 static const float  HalfPi     = 1.57079632679489661923f;
 static const float  TwoPi      = 6.28318530717958647692f;
 static const float  InversePi  = 0.31830988618379067154f;
 
 static const double PiD        = 3.141592653589793f;
 static const double HalfPiD    = 1.57079632679489661923f;
 static const double TwoPiD     = 6.28318530717958647692f;
 static const double InversePiD = 0.31830988618379067154f;

template<typename T> inline T nearEqual(const T& a, const T& b, const T& tolerance)
{
 return Math::abs(a - b) <= tolerance;
}

template<typename T> inline T lerp(const T& a, const T& b, const T& alpha) 
{
 return alpha * (b - a) + a;
}

template<typename T> inline T abs(T v)
{
 return v >= (T) 0 ? v : -v;
}

template<typename T> inline T trunc(const T& v)
{
 return T( (v < (T) 0 ) ? math::ceil(v) : math::floor(v) );
}

template<typename T> inline T round(const T& v)
{
 return T( math::floor(v + (T) 0.5 ) );
}

inline float abs(float v)
{
 return ::fabsf(v);
}

inline double abs(double v)
{
 return ::fabs(v);
}

inline int abs(int v)
{
 return ::abs(v);
}

inline long abs(long v)
{
 return ::labs(v);
}

inline float ceil(float v)
{
 return ::ceilf(v);
}

inline double ceil(double v)
{
 return ::ceil(v);
}

inline float floor(float v)
{
 return ::floorf(v);
}

inline double floor(double v)
{
 return ::floor(v);
}

template<typename T>
inline T min(const T& a, const T& b)
{
 return (a > b) ? b : a;
}

template<typename T>
inline T min(const T& a, const T& b, const T& c)
{
 return min(min(a, b), c);
}

template<typename T>
inline T max(const T& a, const T& b)
{
 return (a > b) ? a : b;
}

template<typename T>
inline T max(const T& a, const T& b, const T& c)
{
 return max(max(a, b), c);
}

template<typename T>
inline T clamp(const T& val, const T& min, const T& max)
{
 if (val > max) return max;
 else if (val < min) return min;
 return val;
}

inline float sqrt(float v)
{
 return ::sqrtf(v);
}

inline double sqrt(double v)
{
 return ::sqrt(v);
}

inline float arccos( float v)
{
 if (-1.0f < v)
 {
  if (v < 1.0f)
   return acosf(v);
  else
   return 0.0f;
 }
 else
  return Pi;
}

inline double arccos( double v)
{
 if (-1.0 < v)
 {
  if (v < 1.0)
   return acos(v);
  else
   return 0.0;
 }
 else
  return PiD;
}

inline float arcsin( float v)
{
 if (-1.0f < v)
 {
  if (v < 1.0f)
   return asinf(v);
  else
   return -HalfPi;
 }
 else
  return HalfPi;
}

inline double arcsin( double v)
{
 if (-1.0 < v)
 {
  if (v < 1.0)
   return asin(v);
  else
   return -HalfPi;
 }
 else
  return HalfPi;
}

inline float arctan( float v)
{
 return ::atanf(v);
}

inline double arctan( double v)
{
 return ::atan(v);
}

inline float arctan2( float y, float x)
{
 return ::atan2f(y, x);
}

inline double arctan2( double y, double x)
{
 return ::atan2(y, x);
}

inline float sin(float v)
{
 return ::sinf(v);
}

inline double sin(double v)
{
 return ::sin(v);
}

inline float cos(float v)
{
 return ::cosf(v);
}

inline double cos(double v)
{
 return ::cos(v);
}

inline float tan(float v)
{
 return ::tanf(v);
}

inline double tan(double v)
{
 return ::tan(v);
}

inline float exp(float v)
{
 return ::expf(v);
}

inline double exp(double v)
{
 return ::exp(v);
}

inline float pow(float base, float exponent)
{
 return ::powf(base, exponent);
}

inline double pow(double base, double exponent)
{
 return ::pow(base, exponent);
}

inline void seedRandom(unsigned int seed)
{
 ::srand(seed);
}

inline float random()
{
 return float(::rand()) / float(RAND_MAX);
}

inline double randomD()
{
 return double(::rand()) / double(RAND_MAX);
}

inline float random(float x1, float x2)
{
 float r = random();
 float s = x2 - x1;
 return float(r * s + x1);
}

inline double random(double x1, double x2)
{
 double r = random();
 double s = x2 - x1;
 return double(r * s + x1);
}


                                                                                       

} // namespace Math

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
