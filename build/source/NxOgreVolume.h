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

                                                                                       

#ifndef NXOGRE_VOLUME_H
#define NXOGRE_VOLUME_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgreRigidBody.h"
#include "NxOgreString.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. Volume
    desc.
        Volumes (or also known as Triggers) are RigidBodies in space that can be passed through.
        In an event of another RigidBody passing through this, a callback is called.
*/
class NxOgrePublicClass Volume : public RigidBody
{
  
  NXOGRE_GC_FRIEND_NEW5
  NXOGRE_GC_FRIEND_DELETE
  
  public:

  /*! function. isVolumeBased
      desc.
          Returns true if this class is a Volume or inherits from it.
      return.
          **true** -- It is an Volume or Volume based class.
  */
  bool  isVolumeBased() const;

  /*! function. getRigidBodyType
      desc.
          Get the the type of RigidBody.
      return.
          Classes::_Volume
  */
  virtual  unsigned int  getRigidBodyType() const;
  
  /*! function. setGlobalPose
      desc.
          Methods for setting a dynamic Volume's pose in the world. 
  */
  void  setGlobalPose(const Matrix44&);
 
  /*! function. setGlobalPosition
      desc.
          Sets a dynamic Volume's position in the world.
   */
  void  setGlobalPosition (const Vec3&);
  
  /*! function. setGlobalOrientation
      desc.
          Sets a dynamic Volume's orientation in the world.
  */
  void  setGlobalOrientation(const Matrix33&);
 
  /*! function. setGlobalOrientationQuat
      desc.
          Sets a dynamic Volume's orientation in the world.
  */
  void  setGlobalOrientationQuat(const Quat&);
 
  /*! function. getGlobalPose
      desc.
          Retrieves the Volumes world space transform.
  */
  Matrix44  getGlobalPose() const;

  /*! function. getGlobalPosition
      desc.
          Retrieves the Volumes world space position.
  */
  Vec3  getGlobalPosition() const;

  /*! function. getGlobalOrientation
      desc.
          Retrieves the Volumes world space orientation.
  */
  Matrix33  getGlobalOrientation() const;
  
  /*! function.
      dsec.
          Retrieves the Volumes world space orientation.
  */
  Quat  getGlobalOrientationQuat() const;
  
  /*! function. getVolumeCallback
      desc.
          Get the callback
  */
  Callback*  getVolumeCallback();
  
  /*! function. setVolumeCallback
      desc.
          Set the callback
  */
  void  setVolumeCallback(Callback*);
  
  /*! function. removeVolumeCallback
      desc.
          Remove the callback, and replace it with a Null one (Do not delete this).
  */
  void  removeVolumeCallback();

  protected: // Functions
  
  /* Classes that inherit from Volume should use this constructor.
  */
  Volume(Scene*, Callback*);
  
  /*! function. createTrigger.0
      desc.
          Become a Trigger RigidBody (Volume) based on the arguments.
      note.
          User classes that inherit Volume should call this.
      args.
           const Matrix44& __pose__ -- Pose of where the Dynamic RigidBody should be.
           Enums::VolumeCollisionType _colType__ -- Collision types (composed with the @|@ (or) operator) of the types of Collisions to report.
           Shape& __shapes__ -- The multiple shapes for the RigidBody to use. Cannot be empty.
      !protected
  */
  void  createTrigger(const Matrix44& pose, Enums::VolumeCollisionType, const ShapeDescription&);
  
  /*! function. createTrigger.1
      desc.
          Become a Trigger RigidBody (Volume) based on the arguments.
      note.
          User classes that inherit Volume should call this.
      args.
           const Matrix44& __pose__ -- Pose of where the Dynamic RigidBody should be.
           Enums::VolumeCollisionType _colType__ -- Collision types (composed with the @|@ (or) operator) of the types of Collisions to report.
           Shape& __shapes__ -- The multiple shapes for the RigidBody to use. Cannot be empty.
      !protected
  */
  void  createTrigger(const Matrix44& pose, Enums::VolumeCollisionType, const ShapeDescriptions&);

  /* Private do not use.
     Use Scene::createVolume
  */
  Volume(const ShapeDescription&, const Matrix44& pose, Enums::VolumeCollisionType type, Scene*, Callback*);
  
  /* Private do not use.
     Use Scene::createVolume
  */
  Volume(const ShapeDescriptions&, const Matrix44& pose, Enums::VolumeCollisionType type, Scene*, Callback*);
  
  /* Private do not use.
     Use Scene::destroyVolume
  */
  virtual  ~Volume();
  

  protected: // Variables
  
  Callback*  mVolumeCallback;
  
}; // class Volume

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
