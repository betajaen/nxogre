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
#include "NxOgreGroupsMask.h"

                                                                                       

namespace NxOgre
{

                                                                                       

GroupsMask::GroupsMask()
{
 zero();
}

GroupsMask::GroupsMask(int b0, int b1, int b2, int b3)
: bits0(b0), bits1(b1), bits2(b2), bits3(b3)
{
}

GroupsMask::~GroupsMask()
{
}

void GroupsMask::zero()
{
 bits0 = 0;
 bits1 = 0;
 bits2 = 0;
 bits3 = 0;
}

String GroupsMask::to_s() const
{
 std::stringstream s;
 s << bits0 << ", " << bits1 << ", " << bits2 << ", " << bits3;
 return s.str();
}

                                                                                       

} // namespace NxOgre

                                                                                       
