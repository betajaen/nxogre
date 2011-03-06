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
#include "NxOgreShape.h"
#include "NxOgreRigidBodyFunctions.h"
#include "NxOgreWorld.h"

#include "NxActor.h"
#include "NxController.h"
#include "ControllerManager.h"

#if NxOgrePlatform == NxOgrePlatformWindows
#  pragma comment(lib, "NxCharacter.lib")
#endif

                                                                                       

namespace NxOgre
{

                                                                                       


CharacterController::CharacterController(Scene* scene)
: RigidBody(scene),
  mController(0),
  mActiveGroups(0),
  mMinDistance(0.001f),
  mCollisionFlags(0),
  mSharpness(1.0),
  mStepOffset(0)
{
}

CharacterController::CharacterController(const SimpleShape& shape, const Vec3& globalPosition, const CharacterControllerDescription& description, Scene* scene)
: RigidBody(scene),
  mController(0),
  mActiveGroups(0),
  mMinDistance(0.001f),
  mCollisionFlags(0),
  mPreviousCollisionFlags(0),
  mSharpness(1.0),
  mStepOffset(0)
{
 mName = description.mName;
 mNameHash = Strings::hash(mName);
 mController = _createCharacterController(globalPosition, mScene, shape, description);
}

CharacterController::~CharacterController()
{
 _destroyCharacterController(mController);
 mController = 0;
}

void CharacterController::createCharacterController(const Vec3& globalPos, const SimpleShape& shape, const CharacterControllerDescription& description)
{
 mStepOffset = description.mStepOffset;
 mSkinWidth = description.mSkinWidth;
 mController = _createCharacterController(globalPos, mScene, shape, description);
}

Real CharacterController::getSkinWidth() const
{
 return mSkinWidth;
}

Real CharacterController::getStepOffset() const
{
 return mStepOffset;
}

void CharacterController::setMovingActiveGroups(unsigned int groups)
{
 mActiveGroups = groups;
}

unsigned int CharacterController::getMovingActiveGroups()
{
 return mActiveGroups;
}

void CharacterController::setMinimalMoveDistance(Real minDist)
{
 mMinDistance = minDist;
}

Real CharacterController::getMinimalMoveDistance() const
{
 return mMinDistance;
}

void CharacterController::setMovingSharpness(Real sharpness)
{
 mSharpness = sharpness;
}

Real CharacterController::getMovingSharpness() const
{
 return mSharpness;
}

unsigned int CharacterController::getLastCollisionFlags() const
{
 return mCollisionFlags;
}

bool CharacterController::hasCollidedDown() const
{
 return mCollisionFlags & NXCC_COLLISION_DOWN;
}

bool CharacterController::hasCollidedSides() const
{
 return mCollisionFlags & NXCC_COLLISION_SIDES;
}

bool CharacterController::hasCollidedUp() const
{
 return mCollisionFlags & NXCC_COLLISION_UP;
}

bool CharacterController::hasPreviouslyCollidedDown() const
{
 return mPreviousCollisionFlags & NXCC_COLLISION_DOWN;
}

bool CharacterController::hasPreviouslyCollidedSides() const
{
 return mPreviousCollisionFlags & NXCC_COLLISION_SIDES;
}

bool CharacterController::hasPreviouslyCollidedUp() const
{
 return mPreviousCollisionFlags & NXCC_COLLISION_UP;
}

void CharacterController::move(const Vec3& displacement)
{
 mPreviousCollisionFlags = mCollisionFlags;
 mController->move(displacement.as<NxVec3>(), mActiveGroups, mMinDistance, mCollisionFlags, mSharpness);
}

bool CharacterController::isCharacterControllerBased() const
{
 return true;
}

unsigned int CharacterController::getRigidBodyType() const
{
 return Classes::_CharacterController;
}

void CharacterController::setPosition(const Vec3& globalPosition)
{
 mController->setPosition(globalPosition.as<NxExtendedVec3>());
}

Vec3 CharacterController::getPosition() const
{
 return Vec3(mActor->getGlobalPosition());
}

void CharacterController::setStepOffset(Real offset)
{
 mController->setStepOffset(offset);
}

void CharacterController::setCollisionsEnabled(bool collisionEnabled)
{
 mController->setCollision(collisionEnabled);
}

void CharacterController::setInteractionFlag(Enums::CharacterControllerInteractionFlag flag)
{
 mController->setInteraction( (NxCCTInteractionFlag) (int) flag);
}

Enums::CharacterControllerInteractionFlag CharacterController::getInteraction() const
{
 return (Enums::CharacterControllerInteractionFlag) (int) mController->getInteraction();
}

void  CharacterController::reportSceneChanged()
{
 mController->reportSceneChanged();
}

bool  CharacterController::isBoxShaped() const
{
 return mController->getType() == NX_CONTROLLER_BOX;
}

bool  CharacterController::isCapsuleShaped() const
{
 return mController->getType() == NX_CONTROLLER_CAPSULE;
}

String CharacterController::to_s() const
{
 return NxOgre::to_s((void*)this, (mName.length() ? String("'" + mName + "'") : String("CharacterController") ));
}

void CharacterController::_setShapeGroup(GroupIdentifier group_id)
{
 mController->getActor()->getShapes()[0]->setGroup(group_id);
}

                                                                                       

} // namespace NxOgre

                                                                                       
#endif