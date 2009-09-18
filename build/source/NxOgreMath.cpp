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
#include "NxOgreMath.h"

#include "math.h"
#include "NxMath.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Functions
{

                                                                                       

namespace Math
{

                                                                                       

NxOgrePublicFunction Real sin(Real a)
{
 return ::sinf(a);
}

NxOgrePublicFunction Real cos(Real a)
{
 return ::cosf(a);
}

NxOgrePublicFunction Real tan(Real a)
{
 return ::tanf(a);
}

#if NxOgreFloatingPointAccuracy == NxOgreFloatingPointFloat
NxOgrePublicFunction DoubleReal sin(DoubleReal a)
{
 return ::sin(a);
}

#endif

#if NxOgreFloatingPointAccuracy == NxOgreFloatingPointFloat
NxOgrePublicFunction DoubleReal cos(DoubleReal a)
{
 return ::cos(a);
}

#endif

#if NxOgreFloatingPointAccuracy == NxOgreFloatingPointFloat
NxOgrePublicFunction DoubleReal tan(DoubleReal a)
{
 return ::tanf(a);
}

#endif


NxOgrePublicFunction Real sqrt(Real val)
{
 return ::sqrt(val);
}

#if NxOgreFloatingPointAccuracy == NxOgreFloatingPointFloat
NxOgrePublicFunction DoubleReal sqrtDouble(DoubleReal val)
{
 return ::sqrt(val);
}
#endif

NxOgrePublicFunction Real random(Real a, Real b)
{
 return NxMath::rand(a, b);
}

NxOgrePublicFunction int random(int a, int b)
{
 return NxMath::rand(a, b);
}

Real          abs(Real val)
{
 return fabsf(val);
}

#if NxOgreFloatingPointAccuracy == NxOgreFloatingPointFloat
DoubleReal    abs(DoubleReal val)
{
 return fabs(val);
}
#endif

                                                                                       

} // namespace Math

                                                                                       

} // namespace Functions

                                                                                       

} // namespace NxOgre

                                                                                       
