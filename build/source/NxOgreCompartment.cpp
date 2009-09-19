/** File: NxOgreCompartment.cpp
    Created on: 11-Aug-09
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

                                                                                       
