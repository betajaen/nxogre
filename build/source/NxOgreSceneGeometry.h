/** File: NxOgreSceneGeometry.h
    Created on: 13-Nov-08
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

#ifndef NXOGRE_SCENEGEOMETRY_H
#define NXOGRE_SCENEGEOMETRY_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgrePointerClass.h"
#include "NxOgreRigidBody.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass SceneGeometry : public PointerClass<Classes::_SceneGeometry>, public RigidBody
{
  
  friend class Scene;
  friend class Functions::ArrayFunctions<SceneGeometry*>::Write;
  
  public:
  
  using ::NxOgre::PointerClass<Classes::_SceneGeometry>::operator new;

  using ::NxOgre::PointerClass<Classes::_SceneGeometry>::operator delete;

  using ::NxOgre::PointerClass<Classes::_SceneGeometry>::getClassType;
  
  public: // Functions
  
  /** \brief 
  */
  virtual                             unsigned int           getClassType() const;

  /** \brief Assigns the actor to a user defined group of rigid bodies. 
  */
                                      void                   setGroup(GroupIdentifier actorGroup); 

  /** \brief Retrieves the value set with setGroup(). 
  */
                                      GroupIdentifier        getGroup(void) const;

  /** \brief Sets the solver iteration count for the body. 
  */
                                      void                   setSolverIterationCount(unsigned int iterCount);

  /** \brief Retrieves the solver iteration count.
  */
                                      unsigned int           getSolverIterationCount(void) const; 

  /** \brief Retrieves the force threshold for contact reports. 
  */
                                      Real                   getContactReportThreshold(void) const;

  /** \brief Sets the force threshold for contact reports. 
  */
                                      void                   setContactReportThreshold(Real threshold);
  
  /** \brief Retrieves the actor's contact report flags. 
  */
                                      unsigned int           getContactReportFlags(void) const;
 
  /** \brief Sets the actor's contact report flags.
  */
                                      void                   setContactReportFlags(unsigned int flags);

  /** \brief Retrieves the actors world space transform.
  */
                                      Matrix44               getGlobalPose(void) const;

  /** \brief Retrieves the actors world space position.
  */
                                      Vec3                  getGlobalPosition(void) const;

  /** \brief Retrieves the actors world space orientation.
  */
                                      Matrix33               getGlobalOrientation(void) const;
  
  /** \brief Retrieves the actors world space orientation.
  */
                                      Quat                  getGlobalOrientationQuat(void) const;

  /** \brief Creates a new shape and adds it to the list of shapes of this actor. 
  */
                                      void                   createShape(Shape*);
  
  /** \brief Deletes the specified shape.
  */
                                      void                   releaseShape(Shape*);
  
  /** \brief Returns the number of shapes assigned to the actor.
  */
                                      unsigned int           getNbShapes(void) const;

  /** \internal Classes that inherit from SceneGeometry should use this constructor.
  */
                                              SceneGeometry(Scene*);
  
  /** \internal Use Scene::createSceneGeometry
  */
                                              SceneGeometry(RigidBodyPrototype*, Scene*);
  
  /** \internal Use Scene::destroySceneGeometry
  */
  virtual                                    ~SceneGeometry(void);

  protected: // Variables
  
  /** \brief Name of the Actor, otherwise a blank string.
  */
                       String          mName;
  
  /** \brief Actor's parent Scene
  */
                       Scene*                mScene;
  
                       Shapes               mShapes;

}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
