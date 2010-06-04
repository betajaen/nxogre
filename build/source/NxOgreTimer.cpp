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
#include "NxOgreTimer.h"

#if NxOgrePlatform == NxOgrePlatformWindows

 #define WIN32_LEAN_AND_MEAN 
 #include <windows.h>

#elif NxOgrePlatform == NxOgrePlatformLinux

 #include <sys/time.h>

#endif

                                                                                       

namespace NxOgre
{

                                                                                       

Timer::Timer()
: mStart(0),
  mFrequency(0)
{
 reset();
}

Timer::~Timer()
{
}

float Timer::now()
{

#if NxOgrePlatform == NxOgrePlatformWindows
 QueryPerformanceCounter( (LARGE_INTEGER*) &mNow);
 return (float) ( float(mNow - mStart) / float(mFrequency));
#elif NxOgrePlatform == NxOgerPlatformLinux
 gettimeofday(&mNow, &mTimezone);
 float a = (float)mStart.tv_sec + (float)mStart.tv_usec/(1000*1000);
 float b = (float)mNow.tv_sec + (float)mNow.tv_usec/(1000*1000);
 return b - a;
#endif
}

double Timer::nowDouble()
{
#if NxOgrePlatform == NxOgrePlatformWindows
 QueryPerformanceCounter( (LARGE_INTEGER*) &mNow);
 return (double) ( double(mNow - mStart) / double(mFrequency));
#elif NxOgrePlatform == NxOgerPlatformLinux
 gettimeofday(&mNow, &mTimezone);
 double a = (double)mStart.tv_sec + (double)mStart.tv_usec/(1000*1000);
 double b = (double)mNow.tv_sec + (double)mNow.tv_usec/(1000*1000);
 return b - a;
#endif
}

float Timer::nowReset()
{
#if NxOgrePlatform == NxOgrePlatformWindows
 QueryPerformanceCounter( (LARGE_INTEGER*) &mNow);
 float t = (float) ( float(mNow - mStart) / float(mFrequency));
 reset();
 return t;
#elif NxOgrePlatform == NxOgerPlatformLinux
 gettimeofday(&mNow, &mTimezone);
 float a = (float)mStart.tv_sec + (float)mStart.tv_usec/(1000*1000);
 float b = (float)mNow.tv_sec + (float)mNow.tv_usec/(1000*1000);
 reset();
 return b - a;
#endif
}

double Timer::nowResetDouble()
{
#if NxOgrePlatform == NxOgrePlatformWindows
 QueryPerformanceCounter( (LARGE_INTEGER*) &mNow);
 double t = (double) ( double(mNow - mStart) / double(mFrequency));
 reset();
 return t;
#elif NxOgrePlatform == NxOgerPlatformLinux
 gettimeofday(&mNow, &mTimezone);
 double a = (double)mStart.tv_sec + (double)mStart.tv_usec/(1000*1000);
 double b = (double)mNow.tv_sec + (double)mNow.tv_usec/(1000*1000);
 reset();
 return b - a;
#endif
}

void Timer::reset()
{

#if NxOgrePlatform == NxOgrePlatformWindows
 QueryPerformanceCounter( (LARGE_INTEGER*) &mStart);
 QueryPerformanceFrequency( (LARGE_INTEGER*) &mFrequency);
#else
 gettimeofday(&mStart, NULL);
#endif

}

                                                                                       

} // namespace NxOgre

                                                                                       
