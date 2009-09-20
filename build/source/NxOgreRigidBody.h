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

                                                                                       

#ifndef NXOGRE_RIGIDBODY_H
#define NXOGRE_RIGIDBODY_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreShape.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief A rigid body
    \important Use an inherited class such as Actor, SceneGeometry, KinematicActor or Trigger.
*/
class NxOgrePublicClass RigidBody : public PointerClass<Classes::_RigidBody>
{
  public: // Functions
  
  /** \brief Get the hashed name of the RigidBody, otherwise BLANK_HASH.
  */
                        StringHash            getNameHash() const;
  
  /** \brief Retrieves the scene which this rigid body belongs to. 
  */
                        Scene*                getScene(void); 
  
  /** \brief Returns true if the RigidBody is dynamic.
  */
                        bool                  isDynamic(void) const;
  
  /** \internal
  */
                        NxActor*              getNxActor(void);
  
  /** \brief Get the type of RigidBody
  */
  virtual               unsigned int          getType() const;
  
  /** \brief Set a callback for contact reporting.
      \note  As this contact can be shared between RigidBodies it is upto YOU to delete the callback at the appropriate time.
  */
                        void                  setContactCallback(Callback*);
  
  /** \brief Get the assigned callback for contact reporting.
  */
                        Callback*             getContactCallback();
  
  protected: // Function
  
  /** \brief Text
  */
                                              RigidBody(void);
  
  /** \brief Text
  */
  virtual                                    ~RigidBody(void);
  
               void                  createDynamic(const Matrix44& matrix_pose, const RigidBodyDescription&, Scene* scene, Shape* shape);
  
               void                  createDynamic(const Matrix44& matrix_pose, const RigidBodyDescription&, Scene* scene, Shapes& shapes);
  
               void                  createSceneGeometry(const Matrix44& matrix_pose, const RigidBodyDescription&, Scene* scene, Shape* shape);
  
               void                  createSceneGeometry(const Matrix44& matrix_pose, const RigidBodyDescription&, Scene* scene, Shapes& shapes);

               void                  createKinematicActor(const Matrix44& matrix_pose, const RigidBodyDescription&, Scene* scene, Shape* shape);
  
               void                  createKinematicActor(const Matrix44& matrix_pose, const RigidBodyDescription&, Scene* scene, Shapes& shapes);
  
               void                  createVolume(const Matrix44& pose, Enums::VolumeCollisionType, Scene*, Shape*);
               
               void                  createVolume(const Matrix44& pose, Enums::VolumeCollisionType, Scene*, Shapes&);



  /** \brief Destroy NxActor.
  */
                void                  destroy(void);
  
  protected: // Variables
  
                        NxActor*              mActor;
  
                        Scene*                mScene;
  
                        Callback*             mContactCallback;
  
                        StringHash            mNameHash;
  
                        CollisionModel        mShapes;
  
}; // class RigidBody


                                                                                       

} // namespace NxOgre

                                                                                       

#endif
