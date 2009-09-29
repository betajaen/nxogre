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
#include "NxOgreTime.h"

#if NxOgrePlatform == NxOgrePlatformWindows
#define WIN32_LEAN_AND_MEAN 
#include <windows.h>
#endif

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Functions
{

                                                                                       

float time()
{
 static __int64 s = 0;
 static __int64 f = 0;
 
 if (s == 0)
 {
  QueryPerformanceCounter( (LARGE_INTEGER*) &s);
  QueryPerformanceFrequency( (LARGE_INTEGER*) &f);
  return 0.0f;
 }
 
 __int64 c = 0;
 QueryPerformanceCounter( (LARGE_INTEGER*) &c);
 return (float) ( (c - s) / double(f) );
}

                                                                                       

} // namespace Functions

                                                                                       

} // namespace NxOgre

                                                                                       
