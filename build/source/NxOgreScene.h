/** File: NxOgreScene.h
    Created on: 6-Nov-08
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

#ifndef NXOGRE_SCENE_H
#define NXOGRE_SCENE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgrePointerClass.h"
#include "NxOgreRigidBodyDescription.h"
#include "NxOgreMaterialDescription.h"
#include "NxOgreJointDescription.h"
#include "NxOgreSphericalJointDescription.h"
#include "NxOgreRevoluteJointDescription.h"
#include "NxOgreClothDescription.h"
#include "NxOgreCompartmentDescription.h"
#include "NxOgreCompartment.h"

#include "NxOgreTimeListener.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass Scene : public PointerClass<Classes::_Scene>, public TimeListener
{
  
  friend class World;
  friend class Functions::ArrayFunctions<Scene*>::Write;
  
  public: // Functions
  
  
  /** \brief Get the name of the Scene if it has one; otherwise NULL is returned.
  */
                       const char*            getName(void) const;
  
  /** \brief Set the name of the Scene.
  */
                       void                   setName(const char*);
  
  /** \brief
  */
                       unsigned int           getNbActors(void) const;
  
  /** \brief
  */
                       ArrayIterator<Actor*>  getActors(void);

  /** \brief
  */
                       Actor*                 createActor(RigidBodyPrototype*);

  /** \brief Create an actor somewhere in the scene
  */
                       Actor*                 createActor(Shape*, const Matrix44& = Matrix44_Identity, const RigidBodyDescription& = RigidBodyDescription());
  
  /** \brief Create an actor somewhere in the scene
  */
                       Actor*                 createActor(Shapes, const Matrix44& = Matrix44_Identity, const RigidBodyDescription& = RigidBodyDescription());
  
  /** \brief
  */
                       SceneGeometry*         createSceneGeometry(Shapes, const Matrix44& = Matrix44_Identity, const RigidBodyDescription& = RigidBodyDescription());
  
  /** \brief
  */
                       SceneGeometry*         createSceneGeometry(Shape*, const Matrix44& = Matrix44_Identity, const RigidBodyDescription& = RigidBodyDescription());


  /** \brief
  */
                       KinematicActor*        createKinematicActor(Shape*, const Matrix44& = Matrix44_Identity, const RigidBodyDescription& = RigidBodyDescription());
  
  /** \brief
  */
                       KinematicActor*        createKinematicActor(Shapes, const Matrix44& = Matrix44_Identity, const RigidBodyDescription& = RigidBodyDescription());

  /** \brief Create a volume for collision detection in a shape, based on the PhysX Trigger system.
      \note  Volumes are RigidBodies can be treated as so, but can never be moved via forces.
  */
                       Volume*                createVolume(Shape*, const Matrix44&, Callback*, Enums::VolumeCollisionType = Enums::VolumeCollisionType_All);
  
  /** \brief;
  */
                       Volume*                createVolume(Shapes, const Matrix44&, Callback*, Enums::VolumeCollisionType = Enums::VolumeCollisionType_All);
  
  /** \brief
  */
                       KinematicController*   createKinematicController(const Vec3& size, const Vec3& globalPosition);

  /** \brief
  */
                       Material*              createMaterial(const MaterialDescription& = MaterialDescription());
  
  /** \brief
  */
                       Material*              createMaterial(MaterialPrototype*);
  
  /** \brief
  */
                       void                   registerMachine(Machine*);
  
  /** \brief
  */
                       void                   unregisterMachine(Machine*);
  
  /** \brief
  */
                       void                   destroyJoint(Joint*);

  /** \brief
  */
                       SphericalJoint*        createSphericalJoint(RigidBody* first, const SphericalJointDescription& = SphericalJointDescription());
  
  /** \brief
  */
                       SphericalJoint*        createSphericalJoint(RigidBody* first, RigidBody* second, const SphericalJointDescription& = SphericalJointDescription());

  /** \brief
  */
                       FixedJoint*            createFixedJoint(RigidBody* first, const FixedJointDescription& = FixedJointDescription());
  
  /** \brief
  */
                       FixedJoint*            createFixedJoint(RigidBody* first, RigidBody* second, const FixedJointDescription& = FixedJointDescription());

  /** \brief
  */
                       RevoluteJoint*         createRevoluteJoint(RigidBody* first, const RevoluteJointDescription& = RevoluteJointDescription());
  
  /** \brief
  */
                       RevoluteJoint*         createRevoluteJoint(RigidBody* first, RigidBody* second, const RevoluteJointDescription& = RevoluteJointDescription());

  /** \brief
  */
                       void                   destroyMaterial(Material*);
  
  /** \brief
  */
                       Material*              getMaterial(const MaterialIdentifier&);
  
  /** \brief
  */
                       Cloth*                 createCloth(const ClothDescription&, Renderable*, Enums::Priority render_priority = Enums::Priority_MediumLow);
  
  /** \brief
  */
                       void                   destroyCloth(Cloth*);
  
  /** \brief
  */
                       SoftBody*              createSoftBody(const SoftBodyDescription&, Renderable*, Enums::Priority render_priority = Enums::Priority_MediumLow);
  
  /** \brief
  */
                       void                   destroySoftBody(SoftBody*);

  /** \brief
  */
                       Compartment*           createCompartment(const CompartmentDescription&);

  /** \brief Find a NxOgre Compartment based upon it's PhysX pointer equilvent.
      \note This function is a little un-efficent. Try not to use it thousands of times at once in a frame if you have a huge amount of compartments.
  */
                       Compartment*           findCompartment(NxCompartment*);

  /** \brief
  */
                       void                   setGravity(const Vec3&);
  
  /** \brief
  */
                       Vec3                   getGravity(void) const;

  /** \brief Returns true if any aligned bounding box is hit by the ray, but not what the box is and where it is relation to the ray.
      \warning Make sure the ray's direction is normalised before using.
  */
                       bool                   raycastAnyBounds(const Ray&, Enums::ShapesType, unsigned int groups = INT_MAX, Real maxDistance = NxOgreRealMax) const;

  /** \brief Returns true if any aligned bounding box is hit by the ray, but not what the box is and where it is relation to the ray.
      \warning Make sure the ray's direction is normalised before using.
  */
                       bool                   raycastAnyBounds(const Ray&, Enums::ShapesType, int4 groupsMask, Real maxDistance = NxOgreRealMax) const;

  /** \brief A more accurate version of raycastAnyBounds, but again does not give what shape was hit, or the distance to the ray.
      \warning Make sure the ray's direction is normalised before using.
  */
                       bool                   raycastAnyShape(const Ray&, Enums::ShapesType, unsigned int groups = INT_MAX, Real maxDistance = NxOgreRealMax, RaycastCache = 0) const;
  
  /** \brief Call the report's hitCallback
      \warning This is not thread safe.
  */
                       unsigned int           raycastAllBounds(const Ray&, Callback*,  Enums::ShapesType, unsigned int group = INT_MAX, Real maxDistance = NxOgreRealMax, unsigned int hintFlags = -1) const;
  
  /** \brief Call the report's hitCallback
  */
                       unsigned int           raycastAllBounds(const Ray&, Callback*,  Enums::ShapesType, int4 groupsMask, Real maxDistance = NxOgreRealMax, unsigned int hintFlags = -1) const;

  /** \brief Return the closest RigidBody (and hit information), to accuracy of the bounds of the RigidBody.
  */
                       RaycastHit             raycastClosestBounds(const Ray&, Enums::ShapesType, unsigned int groups = INT_MAX, Real maxDistance = NxOgreRealMax, unsigned int hintFlags = -1) const;

  /** \brief Return the closest RigidBody, to shape accuracy, to the accuracy of the shape(s) of the RigidBody.
  */
                       RaycastHit             raycastClosestShape(const Ray&, Enums::ShapesType, unsigned int groups = INT_MAX, Real maxDistance = NxOgreRealMax, unsigned int hintFlags = -1, RaycastCache = 0) const;

  /** \brief Block all parallel raycast/overlap queries.
  */
                       void                   lockQueries();
  
  /** \brief Unlock all parallel raycast/overlap queries.
  */
                       void                   unlockQueries();


  /** \brief Required by TimeController. Advances the simulation state of this scene.
      \note Do not use manually.
  */
                       bool                   advance(float user_deltaTime, const Enums::Priority&);
  
  /** \brief Is the scene currently processing the physics for the next time step. You cannot
             adjust the scene's state whilst it is processing.
  */
                       bool                   isProcessing(void) const;
  
  /** \brief Get this timestep's debug renderable of the scene.
  */
                       DebugRenderable        getDebugRenderable(void);
  
  /** \internal
  */
                       NxScene*               getScene(void);
  
  /** \internal
  */
                       PhysXCallback*         getPhysXCallback(void);
  
  /** \brief Get the current timestep in the Scene.
  */
  
                       TimeStep&              getTimeStep(void);
  
  /** \brief
  */
                       void                   setActorFlags(RigidBody*, RigidBody*, unsigned int contact_flags);
  
  protected: // Functions
  
  /** \internal Use World::createScene()
  */
                                              Scene(ScenePrototype*, NxPhysicsSDK*);
  
  /** \internal Use World::destroyScene()
  */
                                             ~Scene(void);
  
  protected: // Variables
  
  /** \brief Name as a String. Use Scene::getName() to fetch, or Scene::setName() to set.
  */
                       String                           mName;
  
  /** \internal What Scene is associated with
  */
                       NxScene*                         mScene;
  
  /** \internal Local SDK pointer
  */
                       NxPhysicsSDK*                    mSDK;
   
  /** \internal Master actors array
  */
                       Array<Actor*>                    mActors;
  
  /** \internal Master scene geometries array
  */
                       Array<SceneGeometry*>            mSceneGeometries;
  
  /** \internal Master kinematic actors array
  */
                       Array<KinematicActor*>           mKinematicActors;
  
  /** \internal Master kinematic controllers array
  */
                       Array<KinematicController*>      mKinematicControllers;
  
  /** \internal Master volumes array
  */
                       Array<Volume*>                   mVolumes;
  
  /** \internal Master materials array
  */
                       Array<Material*>                 mMaterials;
  
  /** \internal Master joints array
  */
                       Array<Joint*>                    mJoints;
  
  /** \internal Master machines array
  */
                       Array<Machine*>                  mMachines;

  /** \internal
  */
                       Array<Machine*>::Iterator        mMachineIterator;

  /** \internal
  */
                       Array<Cloth*>                    mCloths;

  /** \internal
  */
                       Array<SoftBody*>                 mSoftBodies;

  /** \internal
  */
                       Array<Compartment*>              mCompartments;

  /** \internal
  */
                       Array<CompartmentArrayPair>      mCompartmentsPair;

  /** \internal Is Scene processing flag
  */
                       bool                             mProcessing;
  
  /** \internal Scene processing priority
  */
                       Enums::Priority                  mProcessingPriority;
  
  /** \internal Scene fetching priority
  */
                       Enums::Priority                  mFetchingPriority;
  
  /** \internal Scene user callback.
  */
                       PhysXCallback*                   mPhysXCallback;
  
  /** \internal Current SceneTimer
  */
                       SceneTimer*                      mSceneTimer;
  
  /** \internal Can the scene be rendered
  */
                       bool                             mCanRender;
  
  /** \internal
  */
                       TimeStep                         mTimeStep;
}; // class Scene

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
