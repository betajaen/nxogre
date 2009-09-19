/** File: NxOgreMath.cpp
    Created on: 15-Apr-09
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

                                                                                       
