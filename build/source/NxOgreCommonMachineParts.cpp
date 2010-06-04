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
#include "NxOgreCommonMachineParts.h"
#include "NxOgreMachine.h"
#include "NxOgreActor.h"

                                                                                       

namespace NxOgre
{

                                                                                       

MoverMachinePart::MoverMachinePart(Machine* parent, const Vec3& force, Enums::ForceMode mode, float interval)
: mParent(parent), mForce(force), mForceMode(mode), mInterval(interval), mNextInterval(interval)
{
}

MoverMachinePart::~MoverMachinePart()
{ // not required
}

void MoverMachinePart::simulate(float deltaTime)
{
 mNextInterval -= deltaTime;
 if (mNextInterval <= 0.0f)
 {
  mParent->mActor->addForce(mForce, mForceMode);
  mNextInterval = mInterval;
 }
}

void MoverMachinePart::render(float deltaTime)
{ // not required
}


RotatorMachinePart::RotatorMachinePart(Machine* parent, const Vec3& force, Enums::ForceMode mode, float interval)
: mParent(parent), mForce(force), mForceMode(mode), mInterval(interval), mNextInterval(interval)
{
}

RotatorMachinePart::~RotatorMachinePart()
{ // not required
}

void RotatorMachinePart::simulate(float deltaTime)
{
 mNextInterval -= deltaTime;
 if (mNextInterval <= 0.0f)
 {
  mParent->mActor->addTorque(mForce, mForceMode);
  mNextInterval = mInterval;
 }
}

void RotatorMachinePart::render(float deltaTime)
{ // not required
}

                                                                                       

} // namespace NxOgre

                                                                                       
