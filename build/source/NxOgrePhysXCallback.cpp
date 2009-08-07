/** File: NxOgrePhysXCallback.cpp
    Created on: 31-Jan-09
    Author: Robin Southern "betajaen"
    Last-Modified-For: PhysX 2.8.1
    SVN: $Id$

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
#include "NxOgrePhysXCallback.h"
#include "NxOgreCallback.h"

#include "NxOgreVolume.h"
#include "NxOgreShape.h"
#include "NxOgreBox.h"
#include "NxOgreRigidBodyFunctions.h"
#include "NxOgreRigidBody.h"

                                                                                       

namespace NxOgre_Namespace
{

                                                                                       

PhysXTriggerCallback::PhysXTriggerCallback(Scene* scene) : mScene(scene)
{
}

PhysXTriggerCallback::~PhysXTriggerCallback()
{
}

void PhysXTriggerCallback::onTrigger(NxShape& triggerShape, NxShape& physxCollisionShape, NxTriggerFlag status)
{

 if (!triggerShape.getActor().userData && !physxCollisionShape.getActor().userData)
  return;
 
 PhysXPointer* ptrV = pointer_cast(triggerShape.userData);
 PhysXPointer* ptrC = pointer_cast(physxCollisionShape.userData);
 RigidBody* rbody = ptrV->getParent<RigidBody>();
 
 Volume* volume = static_cast<Volume*>(rbody);
 volume->getCallback()->onVolumeEvent(volume, ptrV->get<Shape>(), ptrC->getParent<RigidBody>(), ptrC->get<Shape>(), status);
 
}

                                                                                       

} // namespace NxOgre_Namespace

                                                                                       
