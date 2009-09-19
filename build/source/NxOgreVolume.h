/** File: NxOgreVolume.h
    Created on: 30-Jan-09
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
                                                             Volume(RigidBodyPrototype*, Scene*, Callback*);
  
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
