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

                                                                                       

#ifndef NXOGRE_MATH_H
#define NXOGRE_MATH_H

                                                                                       

#include "NxOgreStable.h"
#include "math.h"
#include "NxOgreVec2.h"
#include "NxOgreVec3.h"
#include "NxOgreQuat.h"
#include "NxOgreMatrix.h"

                                                                                       

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

template<typename T> inline T abs(T v)
{
 return v >= (T) 0 ? v : -v;
}

template<typename T> inline T nearEqual(const T& a, const T& b, const T& tolerance)
{
 return Math::abs<T>(a - b) <= tolerance;
}

template<typename T> inline T lerp(const T& a, const T& b, const T& alpha)
{
 return alpha * (b - a) + a;
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

template<typename T> inline T trunc(const T& v)
{
 return T((v < (T) 0 ) ? Math::ceil(v) : Math::floor(v) );
}

template<typename T> inline T round(const T& v)
{
 return T(Math::floor(v + (T) 0.5 ) );
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

inline float arccos(float v)
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

inline double arccos(double v)
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

inline float arcsin(float v)
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

inline double arcsin(double v)
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

inline float arctan(float v)
{
 return ::atanf(v);
}

inline double arctan(double v)
{
 return ::atan(v);
}

inline float arctan2(float y, float x)
{
 return ::atan2f(y, x);
}

inline double arctan2(double y, double x)
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

inline Quat nlerp(float alpha, Quat& a, Quat& b, bool shortest)
{
 Quat out, t;
 float cosine = a.dot(b);
 out = a;

 if (cosine < 0.0f && shortest)
  t = -b;
 else
  t = b;

 t -= a;
 t *= alpha;
 out += t;

 out.normalise();

 return out;
}

inline void interpolate(Matrix44& a, Matrix44& b, Matrix44& out, float alpha)
{
 out.scaleIdentity();

 // Interpolate translation.
 Vec3 trans_a = a;
 Vec3 trans_b = b;
 out.set(alpha * (trans_b - trans_a) + trans_a);

 // Interpolate orientation.

 Quat orient_a = a;
 Quat orient_b = b;
 out.set(nlerp(alpha, orient_a, orient_b, true));

}

                                                                                       

} // namespace Math

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
