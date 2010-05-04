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

GroupsMask::GroupsMask(int bits0, int bits1, int bits2, int bits3)
: mBits0(bits0), mBits1(bits1), mBits2(bits2), mBits3(bits3)
{
}

GroupsMask::~GroupsMask()
{
}

void GroupsMask::zero()
{
 mBits0 = 0;
 mBits1 = 1;
 mBits2 = 2;
 mBits3 = 3;
}

String GroupsMask::to_s() const
{
 std::stringstream s;
 s << mBits0 << ", " << mBits1 << ", " << mBits2 << ", " << mBits3;
 return s.str();
}

                                                                                       

} // namespace NxOgre

                                                                                       
