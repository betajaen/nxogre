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
#include "NxOgreFunctions.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Functions
{

                                                                                       

CalculatedTimeStep calculateTimestep(float timestep, Enums::TimeStepMethod method, float maxTime, unsigned int nbSubSteps)
{
 
 CalculatedTimeStep cts;
 
 cts.mAccumulator = 0.0f;
 cts.mActual = timestep;
 
 if (method == Enums::TimeStepMethod_Variable || method == Enums::TimeStepMethod_Inherit)
 {
  cts.mModified = timestep;
  return cts;
 }
 
 for (unsigned int i=0; i < nbSubSteps;i++)
  if (cts.mAccumulator <= maxTime)
   break;
  else
   cts.mAccumulator -= maxTime;
 
 cts.mModified = maxTime;
 
 return cts;
}


                                                                                       

}

                                                                                       

} // namespace NxOgre

                                                                                       
