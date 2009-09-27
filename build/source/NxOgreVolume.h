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

#include "NxOgrePointerClass.h"
#include "NxOgreRigidBody.h"
#include "NxOgreString.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass Volume : public PointerClass<Classes::_Volume>, public RigidBody
{
  
  friend class Scene;
  friend class Functions::ArrayFunctions<Volume*>::Write;
  template<class T> friend inline void Functions::safe_delete(T*);
  
  public:
  
   using ::NxOgre::PointerClass<Classes::_Volume>::operator new;
   using ::NxOgre::PointerClass<Classes::_Volume>::operator delete;
   using ::NxOgre::PointerClass<Classes::_Volume>::getClassType;
  
  /** \brief Methods for setting a dynamic Volume's pose in the world. 
  */
                                      void                   setGlobalPose(const Matrix44&);
 
  /** \brief Sets a dynamic Volume's position in the world.
   */
                                      void                   setGlobalPosition (const Vec3&);
  
  /** \brief Sets a dynamic Volume's orientation in the world.
  */
                                      void                   setGlobalOrientation(const Matrix33&);
 
  /** \brief Sets a dynamic Volume's orientation in the world.
  */
                                      void                   setGlobalOrientationQuat(const Quat&);
 
  /** \brief Retrieves the Volumes world space transform.
  */
                                      Matrix44               getGlobalPose(void) const;

  /** \brief Retrieves the Volumes world space position.
  */
                                      Vec3                   getGlobalPosition(void) const;

  /** \brief Retrieves the Volumes world space orientation.
  */
                                      Matrix33               getGlobalOrientation(void) const;
  
  /** \brief Retrieves the Volumes world space orientation.
  */
                                      Quat                   getGlobalOrientationQuat(void) const;

  /** \brief Creates a new shape and adds it to the list of shapes of this Volume. 
  */
                                      void                   createShape(Shape*);
  
  /** \brief Deletes the specified shape.
  */
                                      void                   releaseShape(Shape*);
  
  /** \brief Returns the number of shapes assigned to the Volume.
  */
                                      unsigned int           getNbShapes(void) const;
  
  /** \brief Get the callback
  */
                                      Callback*              getVolumeCallback();
  
  /** \brief Set the callback
  */
                                      void                   setVolumeCallback(Callback*);
  
  /** \brief Remove the callback, and replace it with a Null one.
  */
                                      void                   removeVolumeCallback();

  protected: // Functions
  
  /** \internal Classes that inherit from Volume should use this constructor.
  */
                                                             Volume(Scene*, Callback*);
  
  /** \internal Use Scene::createVolume
  */
                                                             Volume(Shape*, const Matrix44& pose, Enums::VolumeCollisionType type, Scene*, Callback*);
  
  /** \internal Use Scene::createActor
  */
                                                             Volume(Shapes&, const Matrix44& pose, Enums::VolumeCollisionType type, Scene*, Callback*);
  
  /** \internal Use Scene::destroyVolume
  */
  virtual                                                   ~Volume(void);
  

  protected: // Variables
  
  /** \brief Volume's parent Scene
  */
                       Scene*                mScene;
  
                       Shapes                mShapes;
  
                       Callback*             mVolumeCallback;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
