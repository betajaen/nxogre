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

                                                                                       

#ifndef NXOGRE_SCENEGEOMETRY_H
#define NXOGRE_SCENEGEOMETRY_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgreRigidBody.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass SceneGeometry : public RigidBody
{
  
  friend class Scene;
  friend class Functions::ArrayFunctions<SceneGeometry*>::Write;
  
  public:
  
  
  public: // Functions
  
  /** \brief 
  */
  virtual                             unsigned int           getRigidBodyType() const;

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
                                      void                   createShape(const ShapeDescription&);
  
  /** \brief Deletes the specified shape.
  */
                                      void                   releaseShape(Shape*);
  
  /** \brief Returns the number of shapes assigned to the actor.
  */
                                      unsigned int           getNbShapes(void) const;

  /** \internal Classes that inherit from SceneGeometry should use this constructor.
  */
                                              SceneGeometry(Scene*);
  
  /** \internal Use Scene::createActor
  */
                                              SceneGeometry(const ShapeDescription&, const Matrix44& pose, const RigidBodyDescription&, Scene*);
  
  /** \internal Use Scene::createActor
  */
                                              SceneGeometry(const ShapeDescriptions&, const Matrix44& pose, const RigidBodyDescription&, Scene*);
  
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
  
                       CollisionModel        mShapes;

}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
