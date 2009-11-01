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
#include "NxOgreCompartment.h"

#include "NxOgreScene.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Compartment::Compartment(const CompartmentDescription& description, Scene* scene) : mCompartment(0), mScene(scene)
{
 NxCompartmentDesc desc;
 desc.deviceCode         = NxDeviceCode(unsigned int(description.mDeviceCode));
 desc.flags              = description.mFlags;
 desc.gridHashCellSize   = description.mGridHashCellSize;
 desc.gridHashTablePower = description.mGridHashTablePower;
 desc.threadMask         = description.mThreadMask;
 desc.timeScale          = description.mTimeScale;
 desc.type               = NxCompartmentType(unsigned int(description.mType));
 
 mCompartment = mScene->getScene()->createCompartment(desc);
 
}

Compartment::~Compartment(void)
{
 // Compartments cannot be released manually.
}

NxCompartment* Compartment::getCompartment()
{
 return mCompartment;
}

Enums::CompartmentType Compartment::getType() const
{
 return (Enums::CompartmentType) (unsigned int) mCompartment->getType();
}

unsigned int Compartment::getDeviceCode() const
{
 return (Enums::DeviceCode) (unsigned int) mCompartment->getDeviceCode();
}

Real Compartment::getGridHashCellSize() const
{
 return mCompartment->getGridHashCellSize();
}

unsigned int Compartment::getGridHashTablePower() const
{
 return mCompartment->gridHashTablePower();
}

Real Compartment::getTimeScale() const
{
 return mCompartment->getTimeScale();
}

void Compartment::setTimeScale(Real time_scale)
{
 mCompartment->setTimeScale(time_scale);
}

void Compartment::setTiming(Real maxTimeStep, unsigned int max_iterator, Enums::TimeStepMethod method)
{
 mCompartment->setTiming(maxTimeStep, max_iterator, NxTimeStepMethod(unsigned int(method)));
}

void Compartment::getTiming(Real& maxTimeStep, unsigned int& max_iterator, Enums::TimeStepMethod& method, unsigned int& num_time_steps) const
{
 NxTimeStepMethod m;
 mCompartment->getTiming(maxTimeStep, max_iterator, m, &num_time_steps);
 method = (Enums::TimeStepMethod) (unsigned int)  m;
}

bool Compartment::checkResults(bool block)
{
 return mCompartment->checkResults(block);
}

bool Compartment::fetchResults(bool block)
{
 return mCompartment->fetchResults(block);
}

void Compartment::setFlags(unsigned int flags)
{
 mCompartment->setFlags(flags);
}

unsigned int Compartment::getFlags() const
{
 return mCompartment->getFlags();
}

                                                                                       

} // namespace NxOgre

                                                                                       
