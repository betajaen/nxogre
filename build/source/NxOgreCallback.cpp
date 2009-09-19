/** File: NxOgreCallback.cpp
    Created on: 22-Aug-09
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
#include "NxOgreCallback.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Callback::Callback() : mNbReferences(0)
{
}

Callback::~Callback()
{
 // virtual function.
}

void Callback::onVolumeEvent(Volume* volume, Shape* volumeShape, RigidBody* rigidBody, Shape* rigidBodyShape, unsigned int collisionEvent)
{
 // virtual function.
}

bool Callback::onHitEvent(const RaycastHit&)
{
 return false;
}

void Callback::onContact(const ContactPair&)
{
}

void Callback::increaseReference()
{
 mNbReferences++;
}

void Callback::decreaseReference()
{
 mNbReferences--;
}

unsigned int Callback::getNbReferences() const
{
 return mNbReferences;
}



                                                                                       

} // namespace NxOgre

                                                                                       
