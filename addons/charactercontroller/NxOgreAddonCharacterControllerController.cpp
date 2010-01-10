/** File: NxOgreCharacterController.h
    Created on: 02-Dec-09
    Author: Robin Southern "betajaen"
    

    Copyright (c) 2008-2009 Robin Southern

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

#include "NxOgreAddonCharacterControllerCommon.h"
#include "NxOgreAddonCharacterController.h"

#include "NxPhysics.h"
#include "NxController.h"
#include "NxBoxController.h"
#include "NxCapsuleController.h"
#include "NxControllerManager.h"

                                                                                       

namespace NxOgre
{

class PhysXControllerCallback : public NxUserControllerHitReport
{
 public:
 
 PhysXControllerCallback(ControllerCallback* callback)
 : mCallback(callback)
 {}

 NxControllerAction  onShapeHit(const NxControllerShapeHit& hit)
 {
  ControllerShapeHit out;
  out.mController = static_cast<Controller*>(hit.controller->getUserData());
  out.mDirection.from<NxVec3>(hit.dir);
  out.mLength = hit.length;
  out.mShape = NxOgre::pointer_representive_cast<Shape>(hit.shape->userData);
  out.mWorldNormal.from<NxVec3>(hit.worldNormal);
  out.mWorldPosition.from<NxExtendedVec3>(hit.worldPos);
  
  return NxControllerAction(int(mCallback->onShape(out)));
 }

 NxControllerAction  onControllerHit(const NxControllersHit& hit)
 {
  Controller* first = static_cast<Controller*>(hit.controller->getUserData());
  Controller* second = static_cast<Controller*>(hit.controller->getUserData());

  return NxControllerAction(int(mCallback->onController(first, second)));
 }
 
 ControllerCallback* mCallback;
 
};

ControllerDescription::ControllerDescription(void)
{
 reset();
}

void  ControllerDescription::reset(void)
{
 mPosition.zero();
 mUpDirection = Enums::Y;
 mSlopeLimit = 0.707f;
 mSkinWidth = 0.1f;
 mStepOffset = 0.5f;
 mCallback = 0;
 mInteractionFlag = Enums::ControllerInteractionFlag_Include;
}

bool  ControllerDescription::valid(void)
{
 if (mSlopeLimit < 0)
  return false;
 if (mStepOffset < 0)
  return false;
 if (mSkinWidth < 0)
  return false;
 return true;
}


Controller::Controller(const ControllerDescription& desc, const Vec3& size, PointRenderable* renderable, Scene* scene, ControllerManager* manager)
: mScene(scene),
  mManager(manager->getControllerManager()),
  mRenderable(renderable),
  mCallback(0),
  mDisplayYaw(0.f)
{
 if (desc.mCallback)
  mCallback = new PhysXControllerCallback(desc.mCallback);

 NxBoxControllerDesc controller_desc;
 controller_desc.callback = mCallback;
 controller_desc.interactionFlag = NxCCTInteractionFlag(int(desc.mInteractionFlag));
 controller_desc.position = desc.mPosition.as<NxExtendedVec3>();
 controller_desc.skinWidth = desc.mSkinWidth;
 controller_desc.extents = size.as<NxVec3>() * 0.5;
 controller_desc.userData = this;
 controller_desc.slopeLimit = desc.mSlopeLimit;
 controller_desc.stepOffset = desc.mStepOffset;
 controller_desc.upDirection = NxHeightFieldAxis(int(desc.mUpDirection));
 controller_desc.userData = 0;
 
 mController = mManager->createController(scene->getScene(), controller_desc);
 
 updateRenderable();
}

Controller::Controller(const ControllerDescription& desc, const Vec2& size, PointRenderable* renderable, Scene* scene, ControllerManager* manager)
: mScene(scene),
  mManager(manager->getControllerManager()),
  mRenderable(renderable),
  mCallback(0),
  mDisplayYaw(0.f)
{
 if (desc.mCallback)
  mCallback = new PhysXControllerCallback(desc.mCallback);
 
 NxCapsuleControllerDesc controller_desc;
 controller_desc.callback = mCallback;
 controller_desc.interactionFlag = NxCCTInteractionFlag(int(desc.mInteractionFlag));
 controller_desc.position = desc.mPosition.as<NxExtendedVec3>();
 controller_desc.skinWidth = desc.mSkinWidth;
 controller_desc.radius = size.x;
 controller_desc.height = size.y;
 controller_desc.userData = this;
 controller_desc.slopeLimit = desc.mSlopeLimit;
 controller_desc.stepOffset = desc.mStepOffset;
 controller_desc.upDirection = NxHeightFieldAxis(int(desc.mUpDirection));
 controller_desc.userData = 0;
 
 mController = mManager->createController(scene->getScene(), controller_desc);
 
 updateRenderable();
}

Controller::~Controller()
{
 mManager->releaseController(*mController);
 
 if (mCallback)
  delete mCallback;
 
}

void Controller::move(const Vec3& displacement, unsigned int activeGroups, float minDistance, unsigned int& collisionFlags, Real sharpness)
{
 mController->move(displacement.as<NxVec3>(), activeGroups, minDistance, collisionFlags, sharpness);
 updateRenderable();
}

void Controller::setDisplayYaw(const float yaw)
{
 mDisplayYaw = yaw;
 updateRenderable();
}

float Controller::getDisplayYaw() const
{
 return mDisplayYaw;
}

void Controller::setPosition(const Vec3& position)
{
 mController->setPosition(position.as<NxExtendedVec3>());
 updateRenderable();
}

Vec3 Controller::getPosition() const
{
 return Vec3(mController->getPosition());
}

Vec3 Controller::getFilteredPosition()
{
 return Vec3(mController->getFilteredPosition());
}

Vec3 Controller::getDebugPosition()
{
 return Vec3(mController->getDebugPosition());
}

void Controller::setStepOffset(const float offset)
{
 mController->setStepOffset(offset);
}

void Controller::setInteraction(Enums::ControllerInteractionFlag flag)
{
 mController->setInteraction(NxCCTInteractionFlag(int(flag)));
}

Enums::ControllerInteractionFlag Controller::getInteraction()
{
 return Enums::ControllerInteractionFlag(int(mController->getInteraction()));
}

Enums::ControllerType Controller::getType()
{
 return Enums::ControllerType(int(mController->getType()));
}

PointRenderable* Controller::getRenderable()
{
 return mRenderable;
}

void Controller::setRenderable(PointRenderable* renderable)
{
 mRenderable = renderable;
}

void Controller::clearRenderable()
{
 mRenderable = 0;
}

void Controller::updateRenderable()
{
 if (mRenderable)
 {
  printf("Rendering...\n");
  mRenderable->render(Vec3(mController->getPosition()),  Quat(NxQuat(mDisplayYaw, NxVec3(0,1,0))));
 }
}

}

                                                                                       
