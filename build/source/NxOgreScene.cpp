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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreScene.h"

#include "NxOgreWorld.h"
#include "NxOgreSceneDescription.h"
#include "NxOgreSceneTimer.h"
#include "NxOgreTimeListenerGroup.h"
#include "NxOgrePrototypeFunctions.h"
#include "NxOgreReason.h"
#include "NxOgreRigidBodyDescription.h"
#include "NxOgreActor.h"
#include "NxOgreSceneGeometry.h"
#include "NxOgreKinematicActor.h"
#include "NxOgreMaterial.h"
#include "NxOgreVolume.h"
#include "NxOgreSphericalJoint.h"
#include "NxOgreFixedJoint.h"
#include "NxOgreRevoluteJoint.h"
#include "NxOgreD6Joint.h"
#include "NxOgrePhysXCallback.h"
#include "NxOgreRay.h"
#include "NxOgrePhysXRaycastReport.h"
#include "NxOgreFunctions.h"
#include "NxOgreRaycastHit.h"
#include "NxOgreFixedSceneTimer.h"
#include "NxOgreMachine.h"
#include "NxOgreMachinePart.h"
#include "NxOgreCloth.h"
#include "NxOgreClothDescription.h"
#include "NxOgreSoftBody.h"
#include "NxOgreSoftBodyDescription.h"
#include "NxOgreForceFieldLinearKernel.h"
#include "NxOgreForceFieldKernel.h"
#include "NxOgreForceField.h"
#include "NxOgreCompartment.h"
#include "NxOgreCompartmentDescription.h"
#include "NxOgreFluid.h"
#include "NxOgreFluidDescription.h"
#include "NxOgreSweepQuery.h"
#include "NxOgreSimple.h"
#include "NxOgreShapeFunctions.h"
#include "NxOgreCallback.h"
#include "NxOgrePhysXUserEntityReport.h"

#include "NxPhysics.h"

#if NxOgreHasCharacterController == 1
#include "NxOgreCharacterController.h"
#include "NxOgreCharacterControllerDescription.h"
#endif

                                                                                       

namespace NxOgre
{

                                                                                       

Scene::Scene(const SceneDescription& description, NxPhysicsSDK* sdk)
: mScene(0),
  mSDK(sdk),
  mPhysXCallback(0),
  mSceneTimer(0),
  mSleepCallback(0),
  mNbSimulates(0),
  mNbRenders(0)
{

 mPhysXCallback = GC::safe_new1<PhysXCallback>(this, NXOGRE_GC_THIS);
 mSimulateWaitingListenerGroup = GC::safe_new2<TimeListenerGroup>(Enums::Priority_Low, Enums::SceneFunction_Simulate, NXOGRE_GC_THIS);
 mRenderWaitingListenerGroup = GC::safe_new2<TimeListenerGroup>(Enums::Priority_Low, Enums::SceneFunction_Render, NXOGRE_GC_THIS);

 mName = description.mName;
 mNameHash = Strings::hash(mName);

 NxSceneDesc scene_description;
 description.to_nxscene(&scene_description);
 mProcessingPriority = description.mProcessingPriority;
 mFetchingPriority = description.mFetchingPriority;
 mProcessing = false;

 scene_description.userTriggerReport = mPhysXCallback;
 scene_description.userContactReport = mPhysXCallback;
 scene_description.userNotify = mPhysXCallback;
 
 mSleepCallback = World::getSingleton()->getNullCallback();
 
 NxOgre_ThrowExceptionIfNull(mSDK, NX_MEMORY_PhysicsSDK);
 
 mScene = mSDK->createScene(scene_description);
 
 if (mScene == 0)
 {
  // Hey there! Got an exception that points to here?
  // Check your log or read the exception. It tell you what is wrong with your SceneDescription
  NxOgre_ThrowException(DescriptionInvalidException, Reason::Exceptionise(scene_description, mSDK == 0, mName), Classes::_World);
  return;
 }

  Material* material = GC::safe_new2<Material>(mScene->getMaterialFromIndex(0), this, NXOGRE_GC_THIS);
  mMaterials.insert(material->getNameHash(), material);
  mIndexedMaterials.insert(0, material);
  
  mSceneTimer = GC::safe_new2<FixedSceneTimer>(this, description.mMaxTimeStep, NXOGRE_GC_THIS); // temp.

}

Scene::~Scene()
{
 
 GC::safe_delete(mSimulateWaitingListenerGroup, NXOGRE_GC_THIS);
 GC::safe_delete(mRenderWaitingListenerGroup, NXOGRE_GC_THIS);

 if (mSDK && mScene)
 {
  mActors.remove_all();
  mSceneGeometries.remove_all();
  mKinematicActors.remove_all();
  mVolumes.remove_all();
  mMaterials.remove_all();
#if NxOgreHasFluids == 1
  mFluids.remove_all();
#endif
#if NxOgreHasCharacterController == 1
  mCharacterControllers.remove_all();
#endif
  mMachines.remove_all();
  mCloths.remove_all();
  mSoftBodies.remove_all();
  GC::safe_delete(mSceneTimer, NXOGRE_GC_THIS);
  mSDK->releaseScene(*mScene);
  GC::safe_delete(mPhysXCallback, NXOGRE_GC_THIS);
 }

}

String Scene::getName() const
{
 return mName;
}

StringHash Scene::getNameHash() const
{
 return mNameHash;
}

unsigned int Scene::getNbRigidBodies() const
{
 return mScene->getNbActors();
}

unsigned int Scene::getNbActors() const
{
 return mActors.size();
}

Scene::ActorIterator Scene::getActors()
{
 return mActors.elements();
}

Actor* Scene::createActor(const ShapeDescriptions& shapes, const Matrix44& pose, const RigidBodyDescription& description)
{
 Actor* actor = GC::safe_new4<Actor>(shapes, pose, description, this);
 StringHash hash = actor->getNameHash();
 mActors.insert(hash, actor);
 return actor;
}


Actor* Scene::createActor(const ShapeDescription& shape, const Matrix44& pose, const RigidBodyDescription& description)
{
 Actor* actor = GC::safe_new4<Actor>(shape, pose, description, this);
 StringHash hash = actor->getNameHash();
 mActors.insert(hash, actor);
 return actor;
}

bool Scene::destroyActor(Actor* actor)
{

 if (actor == 0)
  return false;

 if (actor->isDynamic() == false)
  return false;

 mActors.remove(actor->getNameHash(), actor);

 return true;
}

SceneGeometry* Scene::createSceneGeometry(const ShapeDescriptions& shapes, const Matrix44& pose, const RigidBodyDescription& description)
{
 SceneGeometry* sg = GC::safe_new4<SceneGeometry>(shapes, pose, description, this, NXOGRE_GC_THIS);
 StringHash hash = sg->getNameHash();
 mSceneGeometries.insert(hash, sg);
 return sg;
}

SceneGeometry* Scene::createSceneGeometry(const ShapeDescription& shape, const Matrix44& pose, const RigidBodyDescription& description)
{
 SceneGeometry* sg = GC::safe_new4<SceneGeometry>(shape, pose, description, this, NXOGRE_GC_THIS);
 StringHash hash = sg->getNameHash();
 mSceneGeometries.insert(hash, sg);
 return sg;
}

void Scene::simulate(float deltaTime)
{
 
 mNbSimulates++;
 
 // Machines first.
 for (mMachineIterator = mMachines.elements(); mMachineIterator != mMachineIterator.end(); mMachineIterator++)
  mMachineIterator->simulate(deltaTime);

 // Then any listeners.
 for (mListenerIterator = mSimulateListenerGroups.elements(); mListenerIterator != mListenerIterator.end(); mListenerIterator++)
  mListenerIterator->advance(deltaTime, mSimulateWaitingListenerGroup);
 
 // Any listeners that got behind.
 if (mSimulateWaitingListenerGroup->empty() == false)
 {
  mSimulateWaitingListenerGroup->advance(deltaTime, 0);
  mSimulateWaitingListenerGroup->remove_all();
 }
 
 mCanRender = false;
 
 // And ready to simulate.....
 mSceneTimer->simulate(deltaTime);
}

bool Scene::canRender() const
{
 return mSceneTimer->hasResults();
}

void Scene::render(float deltaTime)
{
 
 mNbRenders++;
 
 // ...okay we are back.
 mSceneTimer->fetchResults();
 
 mCanRender = true;
 
 // Render the machines first.
 for (mMachineIterator = mMachines.elements(); mMachineIterator != mMachineIterator.end(); mMachineIterator++)
  mMachineIterator->render(deltaTime);
 
 // Then any listeners
 for (mListenerIterator = mRenderListenerGroups.elements(); mListenerIterator != mListenerIterator.end(); mListenerIterator++)
  mListenerIterator->advance(deltaTime, mRenderWaitingListenerGroup);
 
 
 // If there are any WaitingListeners, run them again.
 if (mRenderWaitingListenerGroup->empty() == false)
 {
  mRenderWaitingListenerGroup->advance(deltaTime, 0);
  mRenderWaitingListenerGroup->remove_all();
 }
 
}

void Scene::addSimulateListener(TimeListener* listener, Enums::Priority priority)
{
 
 if (mSimulateListenerGroups.has(priority) == false)
  mSimulateListenerGroups.insert(priority, GC::safe_new2<TimeListenerGroup>(priority, Enums::SceneFunction_Simulate, NXOGRE_GC_THIS));
  
 mSimulateListenerGroups.at(priority)->push_back(listener);

}

void Scene::removeSimulateListener(TimeListener* listener, Enums::Priority priority)
{
 
 if (mSimulateListenerGroups.has(priority) == false)
  return;
 
 mSimulateListenerGroups.at(priority)->remove(listener);
 
}

void Scene::addRenderListener(TimeListener* listener, Enums::Priority priority)
{
 
 if (mRenderListenerGroups.has(priority) == false)
  mRenderListenerGroups.insert(priority, GC::safe_new2<TimeListenerGroup>(priority, Enums::SceneFunction_Render, NXOGRE_GC_THIS));
  
 mRenderListenerGroups.at(priority)->push_back(listener);
 
}

void Scene::removeRenderListener(TimeListener* listener, Enums::Priority priority)
{
 
 if (mRenderListenerGroups.has(priority) == false)
  return;
 
 mRenderListenerGroups.at(priority)->remove(listener);
 
}

NxScene* Scene::getScene()
{
 return mScene;
}

bool Scene::isProcessing() const
{
 return !mScene->isWritable();
}

Material* Scene::createMaterial(const MaterialDescription& description)
{
 Material* material = GC::safe_new2<Material>(description, this, NXOGRE_GC_THIS);
 mMaterials.insert(material->getNameHash(), material);
 mIndexedMaterials.insert(material->getIdentifier(), material);
 return material;
}


void Scene::destroyMaterial(Material* material)
{
 mIndexedMaterials.remove(material->getIdentifier());
 mMaterials.remove(material->getNameHash(), material);
}

Material* Scene::getMaterial(const MaterialIdentifier& identifier)
{
 return mIndexedMaterials.at(identifier);
}

KinematicActor* Scene::createKinematicActor(const ShapeDescription& shape, const Matrix44& pose, const RigidBodyDescription& description)
{
 KinematicActor* ka = GC::safe_new4<KinematicActor>(shape, pose, description, this, NXOGRE_GC_THIS);
 StringHash hash = ka->getNameHash();
 mKinematicActors.insert(hash, ka);
 return ka;
}

KinematicActor* Scene::createKinematicActor(const ShapeDescriptions& shapes, const Matrix44& pose, const RigidBodyDescription& description)
{
 KinematicActor* ka = GC::safe_new4<KinematicActor>(shapes, pose, description, this, NXOGRE_GC_THIS);
 StringHash hash = ka->getNameHash();
 mKinematicActors.insert(hash, ka);
 return ka;
}

Volume* Scene::createVolume(const ShapeDescription& shape, const Matrix44& pose, Callback* callback, Enums::VolumeCollisionType vct)
{
 Volume* vol = GC::safe_new5<Volume>(shape, pose, vct, this, callback, NXOGRE_GC_THIS);
 mVolumes.push_back(vol);
 return vol;
}

Volume* Scene::createVolume(const ShapeDescriptions& shapes, const Matrix44& pose, Callback* callback, Enums::VolumeCollisionType vct)
{
 Volume* vol = GC::safe_new5<Volume>(shapes, pose, vct, this, callback, NXOGRE_GC_THIS);
 mVolumes.push_back(vol);
 return vol;
}

void Scene::destroyJoint(Joint* joint)
{
 mJoints.remove(mJoints.index(joint));
}

SphericalJoint* Scene::createSphericalJoint(RigidBody* first, const SphericalJointDescription& desc)
{
 RigidBody* second = 0;
 SphericalJoint* joint = GC::safe_new3<SphericalJoint>(first, second, desc, NXOGRE_GC_THIS);
 mJoints.push_back(joint);
 return joint;
}

SphericalJoint* Scene::createSphericalJoint(RigidBody* first, RigidBody* second, const SphericalJointDescription& desc)
{
 SphericalJoint* joint = GC::safe_new3<SphericalJoint>(first, second, desc, NXOGRE_GC_THIS);
 mJoints.push_back(joint);
 return joint;
}

FixedJoint* Scene::createFixedJoint(RigidBody* first, const FixedJointDescription& desc)
{
 RigidBody* second = 0;
 FixedJoint* joint = GC::safe_new3<FixedJoint>(first, second, desc, NXOGRE_GC_THIS);
 mJoints.push_back(joint);
 return joint;
}

FixedJoint* Scene::createFixedJoint(RigidBody* first, RigidBody* second, const FixedJointDescription& desc)
{
 FixedJoint* joint = GC::safe_new3<FixedJoint>(first, second, desc, NXOGRE_GC_THIS);
 mJoints.push_back(joint);
 return joint;
}

RevoluteJoint* Scene::createRevoluteJoint(RigidBody* first, const RevoluteJointDescription& desc)
{
 RigidBody* second = 0;
 RevoluteJoint* joint = GC::safe_new3<RevoluteJoint>(first, second, desc, NXOGRE_GC_THIS);
 mJoints.push_back(joint);
 return joint;
}

RevoluteJoint* Scene::createRevoluteJoint(RigidBody* first, RigidBody* second, const RevoluteJointDescription& desc)
{
 RevoluteJoint* joint = GC::safe_new3<RevoluteJoint>(first, second, desc, NXOGRE_GC_THIS);
 mJoints.push_back(joint);
 return joint;
}

D6Joint* Scene::createD6Joint(RigidBody* first, const D6JointDescription& desc)
{
 RigidBody* second = 0;
 D6Joint* joint = GC::safe_new3<D6Joint>(first, second, desc, NXOGRE_GC_THIS);
 mJoints.push_back(joint);
 return joint;
}

D6Joint* Scene::createD6Joint(RigidBody* first, RigidBody* second, const D6JointDescription& desc)
{
 D6Joint* joint = GC::safe_new3<D6Joint>(first, second, desc, NXOGRE_GC_THIS);
 mJoints.push_back(joint);
 return joint;
}

Compartment* Scene::createCompartment(const CompartmentDescription& description)
{
 Compartment* compartment = GC::safe_new2<Compartment>(description, this, NXOGRE_GC_THIS);
 mCompartments.push_back(compartment);
 mCompartmentPairs[compartment->getCompartment()] = compartment;
 return compartment;
}

void Scene::setGravity(const Vec3& vec)
{
 mScene->setGravity(vec.as<NxVec3>());
}

Vec3 Scene::getGravity() const
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
 inRay.dir = ray.mDirection.as<NxVec3>();
 inRay.orig = ray.mOrigin.as<NxVec3>();
 return mScene->raycastAnyBounds(inRay, NxShapesType(int(type)), groups, maxDistance, 0);
}

bool Scene::raycastAnyBounds(const Ray& ray, Enums::ShapesType type, int4 groupsMask, Real maxDistance) const
{
 NxRay inRay;
 inRay.dir = ray.mDirection.as<NxVec3>();
 inRay.orig = ray.mOrigin.as<NxVec3>();
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
 inRay.dir = ray.mDirection.as<NxVec3>();
 inRay.orig = ray.mOrigin.as<NxVec3>();

 return mScene->raycastAnyShape(inRay, NxShapesType(int(type)), groups, maxDistance, 0, cache);
}

unsigned int Scene::raycastAllBounds(const Ray& ray, Callback* callback,  Enums::ShapesType type, unsigned int group, Real maxDistance, unsigned int hintFlags) const
{
 NxRay inRay;
 inRay.dir = ray.mDirection.as<NxVec3>();
 inRay.orig = ray.mOrigin.as<NxVec3>();

 PhysXRaycastReport report(callback);
 return mScene->raycastAllBounds(inRay, report, NxShapesType(int(type)), group, maxDistance, hintFlags);
}

unsigned int Scene::raycastAllBounds(const Ray& ray, Callback* callback, Enums::ShapesType type, int4 groupsMask, Real maxDistance, unsigned int hintFlags) const
{
 NxRay inRay;
 inRay.dir = ray.mDirection.as<NxVec3>();
 inRay.orig = ray.mOrigin.as<NxVec3>();
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
 inRay.dir = ray.mDirection.as<NxVec3>();
 inRay.orig = ray.mOrigin.as<NxVec3>();

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
 out.mWorldImpact.from<NxVec3>(hit.worldImpact);
 out.mWorldNormal.from<NxVec3>(hit.worldNormal);
 out.mRigidBody = 0;
 out.mShape = 0;

 if (nxShape == 0)
  return out; 

 if (nxShape->getActor().userData == 0)
  return out;
 
 RigidBody* rbody = pointer_representive_cast<RigidBody>(nxShape->getActor().userData);
 
#if NxOgreHasCharacterController == 1
 
 if (rbody->isCharacterControllerBased())
 {
  out.mRigidBody = rbody;
  out.mShape = rbody->getShape(0);
 }
 else
 {
  out.mRigidBody = rbody;
  out.mShape = pointer_representive_cast<Shape>(nxShape->userData);
 }
 
#else
 
 PhysXPointer* shapePointer = pointer_cast(nxShape->userData);
 out.mShape = shapePointer->get<Shape>();
 out.mRigidBody = shapePointer->getParent<RigidBody>();
 
#endif

 return out;
}

RaycastHit Scene::raycastClosestShape(const Ray& ray, Enums::ShapesType type, unsigned int group, Real maxDistance, unsigned int hintFlags, RaycastCache cache) const
{

 NxRay inRay;
 inRay.dir = ray.mDirection.as<NxVec3>();
 inRay.orig = ray.mOrigin.as<NxVec3>();

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
 out.mWorldImpact.from<NxVec3>(hit.worldImpact);
 out.mWorldNormal.from<NxVec3>(hit.worldNormal);
 out.mRigidBody = 0;
 out.mShape = 0;

 if (nxShape == 0)
  return out; 

 if (nxShape->getActor().userData == 0)
  return out;
 
 RigidBody* rbody = pointer_representive_cast<RigidBody>(nxShape->getActor().userData);
 
#if NxOgreHasCharacterController == 1
 
 if (rbody->isCharacterControllerBased())
 {
  out.mRigidBody = rbody;
  out.mShape = rbody->getShape(0);
 }
 else
 {
  out.mRigidBody = rbody;
  out.mShape = pointer_representive_cast<Shape>(nxShape->userData);
 }
 
#else
 
 PhysXPointer* shapePointer = pointer_cast(nxShape->userData);
 out.mShape = shapePointer->get<Shape>();
 out.mRigidBody = shapePointer->getParent<RigidBody>();
 
#endif

 return out;
}

const TimeStep& Scene::getTimeStep()
{
 return mSceneTimer->getTimeStep();
}

void Scene::registerMachine(Machine* machine)
{
 mMachines.push_back(machine);
}

void Scene::unregisterMachine(Machine* machine)
{
 mMachines.remove(mMachines.index(machine));
}

Cloth* Scene::createCloth(const ClothDescription& description, Renderable* renderable, Enums::Priority rp)
{
 Cloth* cloth = GC::safe_new4<Cloth>(description, renderable, rp, this, NXOGRE_GC_THIS);
 mCloths.push_back(cloth);
 return cloth;
}

void Scene::destroyCloth(Cloth* cloth)
{
 mCloths.remove(mCloths.index(cloth));
}

SoftBody* Scene::createSoftBody(const SoftBodyDescription& description, Renderable* renderable, Enums::Priority rp)
{
 SoftBody* cloth = GC::safe_new4<SoftBody>(description, renderable, rp, this, NXOGRE_GC_THIS);
 mSoftBodies.push_back(cloth);
 return cloth;
}

void Scene::destroySoftBody(SoftBody* cloth)
{
 mSoftBodies.remove(mSoftBodies.index(cloth));
}

#if NxOgreHasFluids == 1
Fluid* Scene::createFluid(const FluidDescription& description, Renderable* renderable, Enums::Priority rp)
{
 Fluid* fluid = GC::safe_new4<Fluid>(description, renderable, rp, this, NXOGRE_GC_THIS);
 StringHash hash = fluid->getNameHash();
 mFluids.insert(hash, fluid);
 return fluid;
}

void Scene::destroyFluid(NxOgre::Fluid* fluid)
{
 if (fluid == 0)
  return;

 mFluids.remove(fluid->getNameHash(), fluid);
}
#endif

void Scene::setActorFlags(RigidBody* a, RigidBody* b, unsigned int contact_flags)
{
 mScene->setActorPairFlags(*a->getNxActor(), *b->getNxActor(), contact_flags);
}

Compartment* Scene::getCompartment(NxCompartment* compartment)
{
 std::map<NxCompartment*, Compartment*>::iterator it = mCompartmentPairs.find(compartment);
 if (it == mCompartmentPairs.end())
  return 0;
 return (*it).second;
}

unsigned int Scene::linearCapsuleSweep(const SimpleCapsule& capsule, const Vec3& motion, unsigned int sweep_flags, unsigned int maxShapes, SweepQueryHits& hits, unsigned int activeGroups)
{

 NxSweepQueryHit* query_hits = (NxSweepQueryHit*) malloc(sizeof(NxSweepQueryHit) * maxShapes);
 NxCapsule physx_capsule = capsule.to_capsule();

 unsigned int count = mScene->linearCapsuleSweep(physx_capsule, motion.as<NxVec3>(), sweep_flags, 0, maxShapes, query_hits, 0, activeGroups, 0);
 Functions::SweepFunctions::NxSweepQueryHitsToBuffer(query_hits, count, hits);
 free(query_hits);
 return count;
}

unsigned int Scene::linearOBBSweep(const SimpleBox& box, const Vec3& motion, unsigned int sweep_flags, unsigned int maxShapes, SweepQueryHits& hits, unsigned int activeGroups)
{

 NxSweepQueryHit* query_hits = (NxSweepQueryHit*) malloc(sizeof(NxSweepQueryHit) * maxShapes);
 NxBox physx_box = box.to_box();

 unsigned int count = mScene->linearOBBSweep(physx_box, motion.as<NxVec3>(), sweep_flags, 0, maxShapes, query_hits, 0, activeGroups, 0);
 Functions::SweepFunctions::NxSweepQueryHitsToBuffer(query_hits, count, hits);
 free(query_hits);
 return count;
}

unsigned int Scene::overlapSphereShape(const SimpleSphere& sphere, Enums::ShapesType type, unsigned int maxShapes, buffer<Shape*> shapes, unsigned int activeGroups, bool accurateCollision)
{

 NxShape* physx_shapes = (NxShape*) malloc(sizeof(NxShape*) * maxShapes);

 NxSphere physx_sphere = sphere.to_sphere();

 unsigned int count = mScene->overlapSphereShapes(physx_sphere, (NxShapesType) (int) type, maxShapes, &physx_shapes, 0, activeGroups, 0, accurateCollision);
 Functions::ShapeFunctions::NxShapeArrayToBuffer(physx_shapes, count, shapes);
 free(physx_shapes);
 return count;

}


unsigned int Scene::overlapSphereShape(const SimpleSphere& sphere, Enums::ShapesType type, Callback* callback, unsigned int activeGroups, bool accurateCollision)
{
 NxSphere physx_sphere = sphere.to_sphere();

 PhysXUserDataCallbackReport<NxShape*, Shape, Callback> cb(&Callback::onOverlap, callback);

 unsigned int count = mScene->overlapSphereShapes(physx_sphere, (NxShapesType) (int) type, 0, 0, &cb, activeGroups, 0, accurateCollision);

 //NXOGRE_DELETE(cb);

 return count;
}

SweepCache* Scene::createSweepCache()
{
 return GC::safe_new1<SweepCache>(mScene->createSweepCache(), NXOGRE_GC_THIS);
}

void Scene::destroySweepCache(SweepCache* cache)
{
 if (cache)
  mScene->releaseSweepCache(cache->getCache());
 GC::safe_delete(cache, NXOGRE_GC_THIS);
}

void Scene::setDominanceGroupPair(GroupIdentifier a, GroupIdentifier b, Real dominance0, Real domaince1)
{
 NxConstraintDominance constraint(dominance0, domaince1);
 mScene->setDominanceGroupPair(a, b, constraint);
}

void Scene::setDominanceGroupPair(GroupIdentifier a, GroupIdentifier b, const ConstraintDominance& constraint)
{
 NxConstraintDominance physx_constraint(constraint.first, constraint.second);
 mScene->setDominanceGroupPair(a, b, physx_constraint);
}

ConstraintDominance Scene::getDominanceGroupPair(GroupIdentifier a, GroupIdentifier b)
{
 NxConstraintDominance constraint = mScene->getDominanceGroupPair(a, b);
 return ConstraintDominance(constraint.dominance0, constraint.dominance1);
}

#if NxOgreHasCharacterController == 1

CharacterController* Scene::createCharacterController(const SimpleShape& shape, const Vec3& globalPosition, const CharacterControllerDescription& description)
{
 CharacterController* controller = GC::safe_new4<CharacterController>(shape, globalPosition, description, this, NXOGRE_GC_THIS);
 mCharacterControllers.insert(controller->getNameHash(), controller);
 return controller;
}

void Scene::destroyCharacterController(CharacterController* controller)
{
 
 if (controller == 0)
  return;
 
 mCharacterControllers.remove(controller->getNameHash(), controller);
 
}

#endif

ForceField* Scene::createForceField(const ForceFieldDescription& desc, ForceFieldKernel* kernel)
{
 ForceField* ff = GC::safe_new3<ForceField>(desc, kernel, this, NXOGRE_GC_THIS);
 StringHash hash = ff->getNameHash();
 mForceFields.insert(hash, ff);
 return ff;
}

bool Scene::destroyForceField(ForceField* ff)
{
 if (ff == 0)
  return false;
 mForceFields.remove(ff->getNameHash(), ff);
 GC::safe_delete(ff, NXOGRE_GC_THIS);
 return true;
}

ForceFieldKernel* Scene::createForceFieldLinearKernel(const ForceFieldLinearKernelDescription& description)
{
 ForceFieldKernel* kernel = GC::safe_new2<ForceFieldLinearKernel>(description, this, NXOGRE_GC_THIS);
 StringHash hash = kernel->getNameHash();
 mForceFieldKernels.insert(hash, kernel);
 return kernel;
}

bool Scene::destroyForceFieldLinearKernel(ForceFieldLinearKernel* kernel)
{
 if (kernel == 0)
  return false;

 if (kernel->getNbReferences() == 0)
  return false;

 mForceFieldKernels.remove(kernel->getNameHash(), kernel);
 GC::safe_delete(kernel, NXOGRE_GC_THIS);

 return true;
}

void Scene::setSleepCallback(Callback* callback)
{
 mSleepCallback = callback;
}

void Scene::removeSleepCallback()
{
 mSleepCallback = World::getSingleton()->getNullCallback();
}

bool Scene::hasSleepCallback() const
{
 return mSleepCallback != NULL || mSleepCallback != World::getSingleton()->getNullCallback();
}

void Scene::setGroupCollisionFlag(GroupIdentifier first, GroupIdentifier second, bool collide)
{
 mScene->setGroupCollisionFlag(first, second, collide);
}

void Scene::getGroupCollisionFlag(GroupIdentifier first, GroupIdentifier second) const
{
 mScene->getGroupCollisionFlag(first, second);
}


std::string Scene::to_s() const
{
 return NxOgre::to_s((void*)this, (mName.length() ? String("'" + mName + "'") : String("Scene") ));
}

unsigned int Scene::getNbSimulates() const
{
 return mNbSimulates;
}

unsigned int Scene::getNbRenders() const
{
 return mNbRenders;
}

void Scene::setFilterOps(NxOgre::Enums::FilterOp op0,NxOgre::Enums::FilterOp op1,NxOgre::Enums::FilterOp op2)
{
 mScene->setFilterOps(NxFilterOp(int(op0)), NxFilterOp(int(op1)), NxFilterOp(int(op2)));
}

void Scene::setFilterBool(bool flag)
{
 mScene->setFilterBool(flag);
}

void Scene::setFilterConstant0(const GroupsMask& mask)
{
 mScene->setFilterConstant0(mask.as<NxGroupsMask>());
}

void Scene::setFilterConstant1(const GroupsMask& mask)
{
 mScene->setFilterConstant0(mask.as<NxGroupsMask>());
}

void Scene::getFilterOps(NxOgre::Enums::FilterOp& op0,NxOgre::Enums::FilterOp& op1,NxOgre::Enums::FilterOp& op2) const
{
 NxFilterOp o0, o1, o2;
 mScene->getFilterOps(o0, o1, o2);
 op0 = static_cast<Enums::FilterOp>(o0);
 op1 = static_cast<Enums::FilterOp>(o1);
 op2 = static_cast<Enums::FilterOp>(o2);
}

bool Scene::getFilterBool() const
{
 return mScene->getFilterBool();
}

GroupsMask Scene::getFilterConstant0() const
{ 
 GroupsMask ret;
 return ret;
}

GroupsMask Scene::setFilterConstant1() const
{
 GroupsMask ret;
 return ret;
}

                                                                                       

} // namespace NxOgre

                                                                                       
