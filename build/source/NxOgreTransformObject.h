/** 
    
    This file is part of NxOgre.
    
    Copyright(c) 2011 Robin Southern, http://github.com/betajaen/nxogre/
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files(the "Software"), to deal
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

#ifndef NXOGRE_TRANSFORM_OBJECT_H
#define NXOGRE_TRANSFORM_OBJECT_H

#include "NxOgreRequired.h"
#include "NxOgreCommon.h"

namespace NxOgre
{

  // ----------------------------------------------------

  /* struct. TransformID
     desc.
         A 32-bit class; that contains the id and type of an object.
     structure.
         id --> Unique ID of the Object.
         type --> Numerical ID of the Object
     see.
         Enums::TransformObjectType
  */
  struct NXOGRE_CLASS TransformID
  {
   uint id : 26;
   uchar type : 6;
  };

  // ----------------------------------------------------

  /* class. TransformObject
     desc.
         An abstract class that represents a ever changing transform, that
         is sent through a stream or through a notification.
         
         Actors, KinematicActors, Cloth, Fluids, etc. all inherit from this.
  */
  class NXOGRE_CLASS TransformObject
  {
  
   public:
    
   /* function. getTransformID
      desc.
          Get a unique ID and type of this object.
   */
   TransformID getTransformID() const;

   /* function. getGlobalPose
      desc.
          Get the uninterpolated global pose.
      note.
          Must be implemented by the child class.
   */
   virtual Transform getGlobalPose() const = 0;

   /* function. getLinearVelocity
      desc.
          Get the current linear velocity.
      note.
          Must be implemented by the child class.
   */
   virtual Vec3 getLinearVelocity() const = 0;
   
   /* function. getAngularVelocity
      desc.
          Get the current angular velocity.
      note.
          Must be implemented by the child class.
   */
   virtual Vec3 getAngularVelocity() const = 0;

   /* function. getTransformID
      desc.
          Get an interpolated global pose, based on the current TimeStep
          on the scene.
   */
   Transform getInterpolatedGlobalPose();

   /* function. getTransformID
      desc.
          Get an interpolated global pose with a custom alpha position.
   */
   NXOGRE_FORCE_INLINE Transform getInterpolatedGlobalPose(Real alpha)
   {
    static Transform t
    t = mLastTransform;
    t.position.LERP(mCurrentTransform.position, alpha);
    //
    //t.rotation.LERP(...);
    return t;
   }
   

   /* function. getExtrapolatedGlobalPose
      desc.
          Calculate the transform could be on last known linear and angular
          velocities.
      note.
          This function should be used when the last tick isn't equal
          to the scene's tick and a transform is needed.
   */
   Transform getExtrapolatedGlobalPose(Real alpha)
   {
    static Transform t;
    t = mLastTransform;
    // extrapolation code here.
    return t;
   }

   /* function. getLastTick
      desc.
          Get the tick that this transform is last cached to.
   */
   NXOGRE_FORCE_INLINE uint getLastTick() const
   {
    return mLastTickID;
   }
   
   /* function. updateTransform
      desc.
          Transform has been updated; update ID and transforms.
   */
   void      updateTransform(size_t tick_id);

   protected:

    TransformID   mID;
    Transform     mLastTransform, mCurrentTransform;
    Vec3          mLastLinearVelocity, mLinearVelocity;
    Quat          mLastAngularVelocity, mAngularVelocity;
    uint          mLastTickID;

  }; // TransformObject 


  // --------------------------------------------------

} // namespace NxOgre

#endif
