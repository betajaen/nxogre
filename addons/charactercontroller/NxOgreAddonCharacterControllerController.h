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

#ifndef NXOGREADDONCHARACTERCONTROLLER_CHARACTER_H
#define NXOGREADDONCHARACTERCONTROLLER_CHARACTER_H

#include "NxOgreAddonCharacterControllerCommon.h"

                                                                                       

namespace NxOgre
{

struct NxOgreCCExportClass ControllerShapeHit
{
 Controller* mController;
 Shape*      mShape;
 Vec3        mWorldPosition;
 Vec3        mWorldNormal;
 Vec3        mDirection;
 Real        mLength;
};

class NxOgreCCExportClass ControllerCallback
{
 public:
  
  virtual Enums::ControllerAction onShape(const ControllerShapeHit&) {return Enums::ControllerAction_None;}
  
  virtual Enums::ControllerAction onController(Controller* controller, Controller* other) {return Enums::ControllerAction_None;}
  
};

class NxOgreCCExportClass ControllerDescription
{
  
 public:
  
  ControllerDescription(void);
  
  void  reset(void);
  
  bool  valid(void);
  
  Vec3                              mPosition;
  
  Enums::Axis                       mUpDirection;
  
  Real                              mSlopeLimit;
  
  Real                              mSkinWidth;
  
  Real                              mStepOffset;
  
  ControllerCallback*               mCallback;
  
  Enums::ControllerInteractionFlag  mInteractionFlag;
  
};

class NxOgreCCExportClass Controller
{
 
 public:
  
  friend class ControllerManager;
  friend class Functions::ArrayFunctions<Controller*>::Write;

  void   move(const Vec3& displacement, unsigned int activeGroups, float minDistance, unsigned int& collisionFlags, Real sharpness=1.0f);
  
  // Set the display yaw, as radians. Is used purely for the PointRenderable and not taken into
  // account when "moved".
  void   setDisplayYaw(const float);
  
  // Get the display yaw.
  float  getDisplayYaw() const;
  
  void   setPosition(const Vec3&);
  
  Vec3   getPosition() const;
  
  Vec3   getFilteredPosition();
  
  Vec3   getDebugPosition();
  
  void   setStepOffset(const float offset);
  
  void   setInteraction(Enums::ControllerInteractionFlag);
  
  Enums::ControllerInteractionFlag getInteraction();
  
  Enums::ControllerType getType();
  
  PointRenderable* getRenderable();
  
  // Note: this will not delete the existing renderable before replaced.
  // use the appropriate destroy function to do so.
  void setRenderable(PointRenderable*);
  
  // Note: This will just release the renderable from use, but not actually delete it from memory.
  // use the appropriate destroy function to do so.

  void clearRenderable();
  
  // Update's the point renderable.
  // This is automatically called on a move or a teleport.
  void updateRenderable();
  
 protected:
  
  Controller(const ControllerDescription&, const Vec3&, PointRenderable*, Scene*, ControllerManager*);
  
  Controller(const ControllerDescription&, const Vec2&, PointRenderable*, Scene*, ControllerManager*);
  
 ~Controller();
  
 protected:
  
  Scene*              mScene;
  
  NxController*       mController;
  
  float               mDisplayYaw;
  
  PointRenderable*    mRenderable;
  
  NxControllerManager*  mManager;

  PhysXControllerCallback*   mCallback;
};

}

                                                                                       

#endif
