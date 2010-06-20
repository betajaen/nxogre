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

                                                                                       

/*! class. SceneGeometry
    desc.
        Non-movable, non-deletable large actors storing meshes, heightfields or primitives
        making up the solid world of your choice such as buildings, parks, benches and
        landmasses.
*/
class NxOgrePublicClass SceneGeometry : public RigidBody
{
  
  NXOGRE_GC_FRIEND_DELETE
  NXOGRE_GC_FRIEND_NEW4
  
  public: // Functions
  
  /*! function. isSceneGeometryBased
      desc.
          Returns true if this class is SceneGeometry or inherits from it.
      return.
          **true** -- It is an SceneGeometry or SceneGeometry based class.
  */
  bool  isSceneGeometryBased() const;

  /*! function. createStatic.0
      desc.
          Become a Static RigidBody (SceneGeometry) based on the arguments.
      note.
          User classes that inherit should *not* call this. Call CharacterController::createStatic() instead.
      args.
           const Matrix44& __pose__ -- Pose of where the Dynamic RigidBody should be.
           const RigidBodyDescription& __description__ -- Additional properties of the RigidBody.
           Scene* __scene__ -- Which scene the RigidBody to exist in. Cannot be NULL.
           const ShapeDescription& __shape__ -- The Single shape for the RigidBody to use. Cannot be NULL.
      !protected
  */
  void  createStatic(const Matrix44& matrix_pose, const RigidBodyDescription&, const ShapeDescription& shape);
  
  /*! function. createStatic.1
      desc.
          Become a Static RigidBody (SceneGeometry) based on the arguments.
      note.
          User classes that inherit should *not* call this. Call CharacterController::createStatic() instead.
      args.
           const Matrix44& __pose__ -- Pose of where the Dynamic RigidBody should be.
           const RigidBodyDescription& __description__ -- Additional properties of the RigidBody.
           Scene* __scene__ -- Which scene the RigidBody to exist in. Cannot be NULL.
           Shape& __shapes__ -- The multiple shapes for the RigidBody to use. Cannot be empty.
      !protected
  */
  void  createStatic(const Matrix44& matrix_pose, const RigidBodyDescription&, const ShapeDescriptions& shapes);

  /** \brief 
  */
  virtual  unsigned int  getRigidBodyType() const;

  /** \brief Assigns the actor to a user defined group of rigid bodies. 
  */
  void                   setGroup(GroupIdentifier actorGroup); 

  /** \brief Retrieves the value set with setGroup(). 
  */
  GroupIdentifier        getGroup() const;

  /** \brief Sets the solver iteration count for the body. 
  */
  void                   setSolverIterationCount(unsigned int iterCount);

  /** \brief Retrieves the solver iteration count.
  */
  unsigned int           getSolverIterationCount() const; 

  /** \brief Retrieves the force threshold for contact reports. 
  */
  Real                   getContactReportThreshold() const;

  /** \brief Sets the force threshold for contact reports. 
  */
  void                   setContactReportThreshold(Real threshold);
  
  /** \brief Retrieves the actor's contact report flags. 
  */
  unsigned int           getContactReportFlags() const;
 
  /** \brief Sets the actor's contact report flags.
  */
  void                   setContactReportFlags(unsigned int flags);

  /** \brief Retrieves the actors world space transform.
  */
  Matrix44               getGlobalPose() const;

  /** \brief Retrieves the actors world space position.
  */
  Vec3                  getGlobalPosition() const;

  /** \brief Retrieves the actors world space orientation.
  */
  Matrix33               getGlobalOrientation() const;
  
  /** \brief Retrieves the actors world space orientation.
  */
  Quat                  getGlobalOrientationQuat() const;

  /** \brief Returns the number of shapes assigned to the actor.
  */
  unsigned int           getNbShapes() const;

  /** \internal Use Scene::destroySceneGeometry
  */
  virtual                                    ~SceneGeometry();

  protected:

  /*! function. createStatic.0
      desc.
          Become a Static RigidBody (SceneGeometry) based on the arguments.
      note.
          User classes that inherit Actor should call this.
      args.
           const Matrix44& __pose__ -- Pose of where the Dynamic RigidBody should be.
           const RigidBodyDescription& __description__ -- Additional properties of the RigidBody.
           Scene* __scene__ -- Which scene the RigidBody to exist in. Cannot be NULL.
           const ShapeDescription& __shape__ -- The Single shape for the RigidBody to use. Cannot be NULL.
      !protected
  */
  void  createStatic(const Matrix44& matrix_pose, const RigidBodyDescription&, Scene* scene, const ShapeDescription& shape);
  
  /*! function. createStatic.1
      desc.
          Become a Static RigidBody (SceneGeometry) based on the arguments.
      note.
          User classes that inherit Actor should call this.
      args.
           const Matrix44& __pose__ -- Pose of where the Dynamic RigidBody should be.
           const RigidBodyDescription& __description__ -- Additional properties of the RigidBody.
           Scene* __scene__ -- Which scene the RigidBody to exist in. Cannot be NULL.
           Shape& __shapes__ -- The multiple shapes for the RigidBody to use. Cannot be empty.
      !protected
  */
  void  createStatic(const Matrix44& matrix_pose, const RigidBodyDescription&, Scene* scene, const ShapeDescriptions& shapes);


  /** \internal Classes that inherit from SceneGeometry should use this constructor.
  */
  SceneGeometry(Scene*);
  
  /** \internal Use Scene::createActor
  */
  SceneGeometry(const ShapeDescription&, const Matrix44& pose, const RigidBodyDescription&, Scene*);
  
  /** \internal Use Scene::createActor
  */
  SceneGeometry(const ShapeDescriptions&, const Matrix44& pose, const RigidBodyDescription&, Scene*);
  


}; // class SceneGeometry

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
