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
#endif

                                                                                       

namespace NxOgre
{

                                                                                       

Timer::Timer()
: mStart(0.0f),
  mFrequency(0.0f)
{
 reset();
}

Timer::~Timer()
{
}

float Timer::now()
{
 __int64 now = 0;
 QueryPerformanceCounter( (LARGE_INTEGER*) &now);
 return (float) ( float(now - mStart) / float(mFrequency));
}

double Timer::nowDouble()
{
 __int64 now = 0;
 QueryPerformanceCounter( (LARGE_INTEGER*) &now);
 return (double) ( double(now - mStart) / double(mFrequency));
}

float Timer::nowReset()
{
 __int64 now = 0;
 QueryPerformanceCounter( (LARGE_INTEGER*) &now);
 float t = (float) ( float(now - mStart) / float(mFrequency));
 reset();
 return t;
}

double Timer::nowResetDouble()
{
 __int64 now = 0;
 QueryPerformanceCounter( (LARGE_INTEGER*) &now);
 float t = (double) ( double(now - mStart) / double(mFrequency));
 reset();
 return t;
}

void Timer::reset()
{
 QueryPerformanceCounter( (LARGE_INTEGER*) &mStart);
 QueryPerformanceFrequency( (LARGE_INTEGER*) &mFrequency);
}

                                                                                       

} // namespace NxOgre

                                                                                       
