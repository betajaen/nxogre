/** File: NxOgreScene.cpp
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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreScene.h"

#include "NxOgreScenePrototype.h"
#include "NxOgreSceneTimer.h"
#include "NxOgrePrototypeFunctions.h"
#include "NxOgreReason.h"
#include "NxOgreRigidBodyPrototype.h"
#include "NxOgreActor.h"
#include "NxOgreSceneGeometry.h"
#include "NxOgreKinematicActor.h"
#include "NxOgreKinematicController.h"
#include "NxOgreTimeController.h"
#include "NxOgreMaterial.h"
#include "NxOgreMaterialPrototype.h"
#include "NxOgreVolume.h"
#include "NxOgreSphericalJoint.h"
#include "NxOgreFixedJoint.h"
#include "NxOgreRevoluteJoint.h"
#include "NxOgrePhysXCallback.h"
#include "NxOgreRay.h"
#include "NxOgrePhysXRaycastReport.h"
#include "NxOgreFunctions.h"
#include "NxOgreRaycastHit.h"
#include "NxOgreAccumulativeSceneTimer.h"
#include "NxOgreFixedSceneTimer.h"
#include "NxOgreMachine.h"
#include "NxOgreMachinePart.h"
#include "NxOgreCloth.h"
#include "NxOgreClothDescription.h"
#include "NxOgreSoftBody.h"
#include "NxOgreSoftBodyDescription.h"
#include "NxOgreCompartment.h"
#include "NxOgreCompartmentDescription.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Scene::Scene(ScenePrototype* prototype, NxPhysicsSDK* sdk)
: mScene(0),
  mSDK(sdk),
  mActors(Classes::_Actor),
  mSceneGeometries(Classes::_SceneGeometry),
  mPhysXCallback(0),
  mSceneTimer(0)
{

 mPhysXCallback = NxOgre_New(PhysXCallback)(this);

 mName = prototype->mName;

 NxSceneDesc scene_description;
 Functions::PrototypeFunctions::ScenePrototypeToNxSceneDesc(prototype, scene_description);
 mProcessingPriority = prototype->mProcessingPriority;
 mFetchingPriority = prototype->mFetchingPriority;
 mProcessing = false;

 scene_description.userTriggerReport = mPhysXCallback;
 scene_description.userContactReport = mPhysXCallback;
  
 scene_description.timeStepMethod = NX_TIMESTEP_FIXED; // temp.
 scene_description.maxTimestep = 1.0f/60.0f;
 
 mScene = mSDK->createScene(scene_description);
 
 if (mScene == 0)
 {
  SharedStringStream message(SharedStringStream::_LARGE); 
 
  if (mName.length())
   message << "An error occured whilst creating the Scene named '" << mName << "'\nThe reason(s) and cause(s) could be:\n\n";
  else
   message << "An error occured whilst creating a Scene.\nThe reason(s) and cause(s) could be:\n\n";
   
  if (mSDK == 0)
   message << " - NxPhysicsSDK is not created.\n";
  
  message << Reason::whyAsStream(scene_description).get();
  
  // Hey there! Got an assertion that points to here?
  // Check your SceneDescription/SceneProtoype properties to see if they are valid or not.
  NxOgre_ThrowAssertion(0, message.get());
  return;
 }
  
  Material* material = NxOgre_New(Material)(mScene->getMaterialFromIndex(0), this);
  mMaterials.insert(material);
  
  TimeController::getSingleton()->mListeners[mProcessingPriority].insert(this);
  TimeController::getSingleton()->mListeners[mFetchingPriority].insert(this);
  
  
  mSceneTimer = new FixedSceneTimer(this); // temp.
  
  mMachineIterator = mMachines.getIterator();
  
}

Scene::~Scene(void)
{

 TimeController::getSingleton()->mListeners[mProcessingPriority].remove(this);
 TimeController::getSingleton()->mListeners[mFetchingPriority].remove(this);

 if (mSDK && mScene)
 {
  mActors.destroyAll();
  mSceneGeometries.destroyAll();
  mKinematicActors.destroyAll();
  mKinematicControllers.destroyAll();
  mVolumes.destroyAll();
  mMaterials.destroyAll();
  mCloths.destroyAll();
  mSoftBodies.destroyAll();
  NxOgre_Delete(mSceneTimer);
  mSDK->releaseScene(*mScene);
  NxOgre_Delete(mPhysXCallback);
 }
}

void Scene::setName(const char* name)
{
 mName = name;
}

const char* Scene::getName(void) const
{
 return mName.c_str();
}

unsigned int Scene::getNbActors(void) const
{
 return mActors.size();
}

ArrayIterator<Actor*> Scene::getActors(void)
{
 return mActors.getIterator();
}

Actor* Scene::createActor(Shapes shapes, const Matrix44& pose, const RigidBodyDescription& description)
{
 RigidBodyPrototype* prototype = NxOgre_New(RigidBodyPrototype)();
 Functions::PrototypeFunctions::RigidBodyDescriptionToRigidBodyPrototype(description, prototype);
 prototype->mShapes = shapes;
 prototype->mType = Enums::RigidBodyType_Dynamic;
 prototype->mGlobalPose = pose;
 Actor* actor = NxOgre_New(Actor)(prototype, this);
 NxOgre_Delete(prototype);
 mActors.insert(actor);
 return actor;
}

  
Actor* Scene::createActor(Shape* shape, const Matrix44& pose, const RigidBodyDescription& description)
{
 RigidBodyPrototype* prototype = NxOgre_New(RigidBodyPrototype)();
 Functions::PrototypeFunctions::RigidBodyDescriptionToRigidBodyPrototype(description, prototype);
 prototype->mShapes.insert(shape);
 prototype->mType = Enums::RigidBodyType_Dynamic;
 prototype->mGlobalPose = pose;
 Actor* actor = NxOgre_New(Actor)(prototype, this);
 NxOgre_Delete(prototype);
 mActors.insert(actor);
 return actor;
}

SceneGeometry* Scene::createSceneGeometry(Shapes shapes, const Matrix44& pose, const RigidBodyDescription& description)
{
 RigidBodyPrototype* prototype = NxOgre_New(RigidBodyPrototype)();
 Functions::PrototypeFunctions::RigidBodyDescriptionToRigidBodyPrototype(description, prototype);
 prototype->mShapes = shapes;
 prototype->mType = Enums::RigidBodyType_Geometry;
 prototype->mGlobalPose = pose;
 SceneGeometry* scene_geometry = NxOgre_New(SceneGeometry)(prototype, this);
 NxOgre_Delete(prototype);
 mSceneGeometries.insert(scene_geometry);
 return scene_geometry;
}

SceneGeometry* Scene::createSceneGeometry(Shape* shape, const Matrix44& pose, const RigidBodyDescription& description)
{
 RigidBodyPrototype* prototype = NxOgre_New(RigidBodyPrototype)();
 Functions::PrototypeFunctions::RigidBodyDescriptionToRigidBodyPrototype(description, prototype);
 prototype->mShapes.insert(shape);
 prototype->mType = Enums::RigidBodyType_Geometry;
 prototype->mGlobalPose = pose;
 SceneGeometry* scene_geometry = NxOgre_New(SceneGeometry)(prototype, this);
 NxOgre_Delete(prototype);
 mSceneGeometries.insert(scene_geometry);
 return scene_geometry;
}


bool Scene::advance(float user_deltaTime, const Enums::Priority& p)
{
 
 if (p == mProcessingPriority && mSceneTimer->getTimerMode() > 0 )
 {
  for (Machine* machine = mMachineIterator.begin();machine = mMachineIterator.next();)
   machine->simulate(user_deltaTime);
  
  mCanRender = false;
  
  mSceneTimer->simulate(user_deltaTime);
  
  return true;
 }
 
 if (p == mFetchingPriority && mSceneTimer->getTimerMode() == Enums::TimerMode_Simulating)
 {
  
  mSceneTimer->fetchResults();
  
  mCanRender = true;
  
  return true;
 }
 
 return true;
}

NxScene* Scene::getScene(void)
{
 return mScene;
}

bool Scene::isProcessing(void) const
{
 return !mScene->isWritable();
}

Material* Scene::createMaterial(const MaterialDescription& description)
{
 NxOgre::MaterialPrototype* prototype = NxOgre_New(MaterialPrototype)();
 Functions::PrototypeFunctions::MaterialDescriptionToMaterialPrototype(description, prototype);
 Material* material = createMaterial(prototype);
 NxOgre_Delete(prototype);
 return material;
}

Material* Scene::createMaterial(MaterialPrototype* prototype)
{
 Material* material = NxOgre_New(Material)(prototype, this);
 mMaterials.insert(material);
 return material;
}

void Scene::destroyMaterial(Material* material)
{
 mMaterials.remove(material);
 NxOgre_Delete(material);
}

Material* Scene::getMaterial(const MaterialIdentifier& identifier)
{
 Array<Material*>::Iterator it = mMaterials.getIterator();
 for (Material* material = it.begin(); material = it.next();)
  if (material->getIdentifier() == identifier)
   return material;
 return 0;
}

KinematicActor* Scene::createKinematicActor(Shape* shape, const Matrix44& pose, const RigidBodyDescription& description)
{
 RigidBodyPrototype* prototype = NxOgre_New(RigidBodyPrototype)();
 Functions::PrototypeFunctions::RigidBodyDescriptionToRigidBodyPrototype(description, prototype);
 prototype->mShapes.insert(shape);
 prototype->mGlobalPose = pose;
 prototype->mType = Enums::RigidBodyType_Kinematic;
 KinematicActor* kactor = NxOgre_New(KinematicActor)(prototype, this);
 NxOgre_Delete(prototype);
 mKinematicActors.insert(kactor);
 return kactor;
}

KinematicActor* Scene::createKinematicActor(Shapes shapes, const Matrix44& pose, const RigidBodyDescription& description)
{
 RigidBodyPrototype* prototype = NxOgre_New(RigidBodyPrototype)();
 Functions::PrototypeFunctions::RigidBodyDescriptionToRigidBodyPrototype(description, prototype);
 prototype->mShapes = shapes;
 prototype->mGlobalPose = pose;
 prototype->mType = Enums::RigidBodyType_Kinematic;
 KinematicActor* kactor = NxOgre_New(KinematicActor)(prototype, this);
 NxOgre_Delete(prototype);
 mKinematicActors.insert(kactor);
 return kactor;
}

KinematicController* Scene::createKinematicController(const Vec3& size, const Vec3& globalPosition)
{
 KinematicController* controller = NxOgre_New(KinematicController)(size, globalPosition, this);
 mKinematicControllers.insert(controller);
 return controller;
}

Volume* Scene::createVolume(Shape* shape, const Matrix44& pose, Callback* callback, Enums::VolumeCollisionType vct)
{
 RigidBodyPrototype* prototype = NxOgre_New(RigidBodyPrototype)();
 prototype->mShapes.insert(shape);
 prototype->mGlobalPose = pose;
 prototype->mType = Enums::RigidBodyType_Volume;
 prototype->mVolumeCollisionType = vct;
 Volume* volume = NxOgre_New(Volume)(prototype, this, callback);
 NxOgre_Delete(prototype);
 mVolumes.insert(volume);
 return volume;
}

Volume* Scene::createVolume(Shapes shapes, const Matrix44& pose, Callback* callback, Enums::VolumeCollisionType vct)
{
 RigidBodyPrototype* prototype = NxOgre_New(RigidBodyPrototype)();
 prototype->mShapes = shapes;
 prototype->mGlobalPose = pose;
 prototype->mType = Enums::RigidBodyType_Volume;
 prototype->mVolumeCollisionType = vct;
 Volume* volume = NxOgre_New(Volume)(prototype, this, callback);
 NxOgre_Delete(prototype);
 mVolumes.insert(volume);
 return volume;
}

void Scene::destroyJoint(Joint* joint)
{
 mJoints.remove(joint);
 NxOgre_Delete(joint);
}

SphericalJoint* Scene::createSphericalJoint(RigidBody* first, const SphericalJointDescription& desc)
{
 SphericalJoint* joint = new SphericalJoint(first, 0, desc);
 mJoints.insert(joint);
 return joint;
}

SphericalJoint* Scene::createSphericalJoint(RigidBody* first, RigidBody* second, const SphericalJointDescription& desc)
{
 SphericalJoint* joint = new SphericalJoint(first, second, desc);
 mJoints.insert(joint);
 return joint;
}

FixedJoint* Scene::createFixedJoint(RigidBody* first, const FixedJointDescription& desc)
{
 FixedJoint* joint = new FixedJoint(first, 0, desc);
 mJoints.insert(joint);
 return joint;
}

FixedJoint* Scene::createFixedJoint(RigidBody* first, RigidBody* second, const FixedJointDescription& desc)
{
 FixedJoint* joint = new FixedJoint(first, second, desc);
 mJoints.insert(joint);
 return joint;
}

RevoluteJoint* Scene::createRevoluteJoint(RigidBody* first, const RevoluteJointDescription& desc)
{
 RevoluteJoint* joint = new RevoluteJoint(first, 0, desc);
 mJoints.insert(joint);
 return joint;
}

RevoluteJoint* Scene::createRevoluteJoint(RigidBody* first, RigidBody* second, const RevoluteJointDescription& desc)
{
 RevoluteJoint* joint = new RevoluteJoint(first, second, desc);
 mJoints.insert(joint);
 return joint;
}

Compartment* Scene::createCompartment(const CompartmentDescription& description)
{
 Compartment* compartment = new Compartment(description, this);
 mCompartments.insert(compartment);
 mCompartmentsPair.insert(CompartmentArrayPair(compartment->getCompartment(), compartment));
 return compartment;
}

void Scene::setGravity(const Vec3& vec)
{
 mScene->setGravity(Functions::XYZ<Vec3, NxVec3>(vec));
}

Vec3 Scene::getGravity(void) const
{
 NxVec3 g;
 mScene->getGravity(g);
 return Vec3(g);
}

void Scene::lockQueries()
{
 mScene->lockQueries();
}

void Scene::unlockQueries()
{
 mScene->unlockQueries();
}

bool Scene::raycastAnyBounds(const Ray& ray, Enums::ShapesType type, unsigned int groups, Real maxDistance) const
{
 NxRay inRay;
 Functions::XYZ<Vec3, NxVec3>(ray.mDirection, inRay.dir);
 Functions::XYZ<Vec3, NxVec3>(ray.mOrigin, inRay.orig);

 return mScene->raycastAnyBounds(inRay, NxShapesType(int(type)), groups, maxDistance, 0);
}

bool Scene::raycastAnyBounds(const Ray& ray, Enums::ShapesType type, int4 groupsMask, Real maxDistance) const
{
 NxRay inRay;
 Functions::XYZ<Vec3, NxVec3>(ray.mDirection, inRay.dir);
 Functions::XYZ<Vec3, NxVec3>(ray.mOrigin, inRay.orig);
 NxGroupsMask mask;

 mask.bits0 = groupsMask.w;
 mask.bits1 = groupsMask.x;
 mask.bits2 = groupsMask.y;
 mask.bits3 = groupsMask.z;

 return mScene->raycastAnyBounds(inRay, NxShapesType(int(type)), -1, maxDistance, &mask);
}

bool Scene::raycastAnyShape(const Ray& ray, Enums::ShapesType type, unsigned int groups, Real maxDistance, RaycastCache cache) const
{
 NxRay inRay;
 Functions::XYZ<Vec3, NxVec3>(ray.mDirection, inRay.dir);
 Functions::XYZ<Vec3, NxVec3>(ray.mOrigin, inRay.orig);

 return mScene->raycastAnyShape(inRay, NxShapesType(int(type)), groups, maxDistance, 0, cache);
}

unsigned int Scene::raycastAllBounds(const Ray& ray, Callback* callback,  Enums::ShapesType type, unsigned int group, Real maxDistance, unsigned int hintFlags) const
{
 NxRay inRay;
 Functions::XYZ<Vec3, NxVec3>(ray.mDirection, inRay.dir);
 Functions::XYZ<Vec3, NxVec3>(ray.mOrigin, inRay.orig);

 PhysXRaycastReport report(callback);
 return mScene->raycastAllBounds(inRay, report, NxShapesType(int(type)), group, maxDistance, hintFlags);
}

unsigned int Scene::raycastAllBounds(const Ray& ray, Callback* callback, Enums::ShapesType type, int4 groupsMask, Real maxDistance, unsigned int hintFlags) const
{
 NxRay inRay;
 Functions::XYZ<Vec3, NxVec3>(ray.mDirection, inRay.dir);
 Functions::XYZ<Vec3, NxVec3>(ray.mOrigin, inRay.orig);
 NxGroupsMask mask;

 mask.bits0 = groupsMask.w;
 mask.bits1 = groupsMask.x;
 mask.bits2 = groupsMask.y;
 mask.bits3 = groupsMask.z;

 PhysXRaycastReport report(callback);
 return mScene->raycastAllBounds(inRay, report, NxShapesType(int(type)), -1, maxDistance, hintFlags, &mask);
}

RaycastHit Scene::raycastClosestBounds(const Ray& ray, Enums::ShapesType type, unsigned int group, Real maxDistance, unsigned int hintFlags) const
{

 NxRay inRay;
 Functions::XYZ<Vec3, NxVec3>(ray.mDirection, inRay.dir);
 Functions::XYZ<Vec3, NxVec3>(ray.mOrigin, inRay.orig);
 
 NxRaycastHit hit;
 NxShape* nxShape = mScene->raycastClosestBounds(inRay, NxShapesType(int(type)), hit, group, maxDistance, hintFlags, 0);
 
 RaycastHit out;
 
 out.mDistance = hit.distance;
 out.mFaceID = hit.faceID;
 out.mFlags = hit.flags;
 out.mInternalFaceID = hit.internalFaceID;
 out.mMaterialIndex = hit.materialIndex;
 out.mU = hit.u;
 out.mV = hit.v;
 Functions::XYZ<NxVec3, Vec3>(hit.worldImpact, out.mWorldImpact);
 Functions::XYZ<NxVec3, Vec3>(hit.worldNormal, out.mWorldNormal);
 
 if (nxShape && nxShape->userData && size_t(nxShape->userData) != 'CCTS')
 {
  PhysXPointer* shapePointer = pointer_cast(nxShape->userData);
  out.mShape = shapePointer->get<Shape>();
  out.mRigidBody = shapePointer->getParent<RigidBody>();
 }
 else
 {
  out.mShape = 0;
  out.mRigidBody = 0;
 }
 
 return out;
}

RaycastHit Scene::raycastClosestShape(const Ray& ray, Enums::ShapesType type, unsigned int group, Real maxDistance, unsigned int hintFlags, RaycastCache cache) const
{
 
 NxRay inRay;
 Functions::XYZ<Vec3, NxVec3>(ray.mDirection, inRay.dir);
 Functions::XYZ<Vec3, NxVec3>(ray.mOrigin, inRay.orig);
 
 NxRaycastHit hit;
 NxShape* nxShape = mScene->raycastClosestShape(inRay, NxShapesType(int(type)), hit, group, maxDistance, hintFlags, 0, cache);
 
 RaycastHit out;

 out.mDistance = hit.distance;
 out.mFaceID = hit.faceID;
 out.mFlags = hit.flags;
 out.mInternalFaceID = hit.internalFaceID;
 out.mMaterialIndex = hit.materialIndex;
 out.mU = hit.u;
 out.mV = hit.v;
 Functions::XYZ<NxVec3, Vec3>(hit.worldImpact, out.mWorldImpact);
 Functions::XYZ<NxVec3, Vec3>(hit.worldNormal, out.mWorldNormal);
 
 if (nxShape && nxShape->userData && size_t(nxShape->userData) != 'CCTS')
 {
  PhysXPointer* shapePointer = pointer_cast(nxShape->userData);
  out.mShape = shapePointer->get<Shape>();
  out.mRigidBody = shapePointer->getParent<RigidBody>();
 }
 else
 {
  out.mShape = 0;
  out.mRigidBody = 0;
 }
 
 return out;
}

TimeStep& Scene::getTimeStep(void)
{
 return mTimeStep;
}

void Scene::registerMachine(Machine* machine)
{
 mMachines.insert(machine);
}

void Scene::unregisterMachine(Machine* machine)
{
 mMachines.remove(machine);
}

Cloth* Scene::createCloth(const ClothDescription& description, Renderable* renderable, Enums::Priority rp)
{
 Cloth* cloth = NxOgre_New(Cloth)(description, renderable, rp, this);
 mCloths.insert(cloth);
 return cloth;
}

void Scene::destroyCloth(Cloth* cloth)
{
 mCloths.remove(cloth);
 NxOgre_Delete(cloth);
}

SoftBody* Scene::createSoftBody(const SoftBodyDescription& description, Renderable* renderable, Enums::Priority rp)
{
 SoftBody* cloth = NxOgre_New(SoftBody)(description, renderable, rp, this);
 mSoftBodies.insert(cloth);
 return cloth;
}

void Scene::destroySoftBody(SoftBody* cloth)
{
 mSoftBodies.remove(cloth);
 NxOgre_Delete(cloth);
}

Compartment* Scene::findCompartment(NxCompartment* lookup)
{
 for (unsigned int i = 0; i < mCompartmentsPair.size(); i++)
 {
  if (mCompartmentsPair[i].mOriginal = lookup)
   return mCompartmentsPair[i].mRepresentative;
 }
 return 0;
}

void Scene::setActorFlags(RigidBody* a, RigidBody* b, unsigned int contact_flags)
{
 mScene->setActorPairFlags(*a->getNxActor(), *b->getNxActor(), contact_flags);
}

                                                                                       

} // namespace NxOgre

                                                                                       
