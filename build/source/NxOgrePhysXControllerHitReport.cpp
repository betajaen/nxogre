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
#include "NxOgreCommon.h"

#if NxOgreHasCharacterController == 1

#include "NxOgrePhysXControllerHitReport.h"
#include "NxOgreCharacterController.h"
#include "NxOgreCharacterControllerHit.h"

#include "NxOgreCallback.h"

#include "NxController.h"
#include "NxPhysicsSDK.h"
#include "NxActor.h"

                                                                                       

namespace NxOgre
{

                                                                                       

PhysXCharacterHitReport::PhysXCharacterHitReport()
{
}

PhysXCharacterHitReport::~PhysXCharacterHitReport()
{
}


NxControllerAction  PhysXCharacterHitReport::onShapeHit(const NxControllerShapeHit& hit)
{
 CharacterControllerHit ret;
 ret.mController = pointer_representive_cast<CharacterController>(hit.controller->getActor()->userData);
 if (ret.mController->getContactCallback() == 0)
  return NX_ACTION_NONE;
 
 ret.mMotionDirection.from<NxVec3>(hit.dir);
 ret.mMotionLength = hit.length;
 ret.mHitShape = pointer_representive_cast<Shape>(hit.shape->userData);
 ret.mWorldNormal.from<NxVec3>(hit.worldNormal);
 ret.mWorldPosition.from<NxExtendedVec3>(hit.worldPos);
 
 return (NxControllerAction) (int) ret.mController->getContactCallback()->onShapeHit(ret);
}

NxControllerAction  PhysXCharacterHitReport::onControllerHit(const NxControllersHit& hit)
{
 CharacterController* a = pointer_representive_cast<CharacterController>(hit.controller->getActor()->userData);

 if (a->getContactCallback() == 0)
  return NX_ACTION_NONE;

 CharacterController* b = pointer_representive_cast<CharacterController>(hit.other->getActor()->userData);
 
 return (NxControllerAction) (int) a->getContactCallback()->onCharacterHit(a, b);
}


                                                                                       

} // namespace NxOgre

                                                                                       


#endif