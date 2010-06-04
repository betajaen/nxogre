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
#include "NxOgreMachine.h"
#include "NxOgreWheelMachinePart.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Machine::Machine() : ActorMachinePart()
{
}

Machine::~Machine()
{
}

void Machine::simulate(float user_deltaTime)
{
 ActorMachinePart::simulate(user_deltaTime);
 
 for (mMachinePartIterator = mMachineParts.elements(); mMachinePartIterator != mMachinePartIterator.end(); mMachinePartIterator++)
  mMachinePartIterator->simulate(user_deltaTime);
 
}

void Machine::render(float user_deltaTime)
{
 ActorMachinePart::render(user_deltaTime);
 
 for (mMachinePartIterator = mMachineParts.elements(); mMachinePartIterator != mMachinePartIterator.end(); mMachinePartIterator++)
  mMachinePartIterator->render(user_deltaTime);
 
}



WheelMachinePart* Machine::createWheelMachinePart(Wheel* wheel, PointRenderable* point_renderable)
{
 WheelMachinePart* part = GC::safe_new2<WheelMachinePart>(wheel, point_renderable, NXOGRE_GC_THIS);
 mMachineParts.push_back(part);
 return part;
}

void Machine::addMachinePart(MachinePart* part)
{
 mMachineParts.push_back(part);
}

void Machine::removeMachinePart(MachinePart* part)
{
 mMachineParts.remove(mMachineParts.index(part));
}

Machine::MachinePartIterator Machine::getMachineParts()
{
 return mMachineParts.elements();
}


String Machine::to_s() const
{
 return String("Machine");
}

                                                                                       

} // namespace NxOgre

                                                                                       
