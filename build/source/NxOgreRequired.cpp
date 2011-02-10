/** 
    
    This file is part of NxOgre.
    
    Copyright(c) 2011 Robin Southern, http://github.com/betajaen/nxogre/
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files(the "Software"), to deal
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

#include "NxOgreRequired.h"

namespace NxOgre
{

 const Real Math::TWO_PI = Real(6.283185307179586476923);
 const Real Math::PI = (Math::TWO_PI * Real(0.5));
 const Real Math::HALF_PI = (Math::TWO_PI * Real(0.25));
 const Real Math::RADIANS_PER_DEGREE = (Math::TWO_PI / Real(360));
 const Real Math::DEGREES_PER_RADIAN = (Real(360) / Math::TWO_PI);

#if NXOGRE_PLATFORM == NXOGRE_PLATFORM_WINDOWS
 NxOgre::GC::WindowsMemoryAllocator NxOgre::GC::WindowsMemoryAllocator::Allocator = NxOgre::GC::WindowsMemoryAllocator();
 NxOgre::GC::WindowsMemoryTracker NxOgre::GC::WindowsMemoryTracker::Tracker = NxOgre::GC::WindowsMemoryTracker();
#endif

}
