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

#include "NxOgreCharacterController.h"

#include "NxOgreScene.h"
#include "NxOgreErrorStream.h"
#include "NxOgreRigidBodyDescription.h"
#include "NxOgreSimple.h"

#include "NxActor.h"
#include "NxPhysics.h"
#include "NxController.h"

                                                                                       

namespace NxOgre
{

                                                                                       

CharacterController::CharacterController()
: mController(0), mScene(0), mContactCallback(0), mNameHash(BLANK_HASH)
{
}

CharacterController::~CharacterController()
{
 destroy();
}

//void CharacterController::create(const Matrix44& pose, Enums::VolumeCollisionType collision_type, Scene* scene, const ShapeDescription& shape)
//{

// mActor->userData = NXOGRE_NEW_NXOGRE PhysXPointer(this, Classes::_RigidBody);

//}

void CharacterController::destroy()
{
 /*
 if (mCharacter == 0)
  return;
 
 PhysXPointer* ptr = pointer_cast(mCharacter->userData);
 NXOGRE_DELETE_NXOGRE(ptr);
 
 //NxScene& scene = mActor->getScene();
 //scene.releaseActor(*mActor);
 */
}


Scene* CharacterController::getScene()
{
 return mScene;
}

void CharacterController::setContactCallback(Callback* callback)
{
 mContactCallback = callback;
}

Callback* CharacterController::getContactCallback()
{
 return mContactCallback;
}

StringHash CharacterController::getNameHash() const
{
 return mNameHash;
}


                                                                                       

} // namespace NxOgre

                                                                                       

#endif