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

#ifndef NXOGRE_CONFIGURATION_H
#define NXOGRE_CONFIGURATION_H

// Comment or uncomment to enable/disable features of NxOgre.

#define NXOGRE_IS_LIBRARY

// #define NXOGRE_USES_DOUBLE_PRECISION

// #define NXOGRE_USES_4BYTE_ALIGNMENT



/*
  Debug Memory

  0 - No debugging
  1 - Count allocations/reallocations/free, and save to file on end (leak acknowledgement)
  2 - Count allocations/reallocations/free, and where they originated and discard freed memory (leak detection);
  3 - Count allocations/reallocations/free, and where they originated  (leak detection, full memory history);
*/
#define NXOGRE_DEBUG_MEMORY 3

/*
  
  Assertion/Exception handling for the public API.
  
  0 - throw exception
  1 - assert
*/

#define NXOGRE_USES_ASSERT 0

/*
  Use the STL Allocator instead of the default.

  0 - Disable
  1 - Enable
*/
#define NXOGRE_USE_STLALLOCATOR 1

#endif
