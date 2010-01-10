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

#include "NxOgreSceneDescription.h"
#include "NxOgreSceneTimer.h"
#include "NxOgrePrototypeFunctions.h"
#include "NxOgreReason.h"
#include "NxOgreRigidBodyDescription.h"
#include "NxOgreActor.h"
#include "NxOgreSceneGeometry.h"
#include "NxOgreKinematicActor.h"
#include "NxOgreKinematicController.h"
#include "NxOgreTimeController.h"
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

                                                                                       

namespace NxOgre
{

                                                                                       

Scene::Scene(const SceneDescription& description, NxPhysicsSDK* sdk)
: mScene(0),
  mSDK(sdk),
  mPhysXCallback(0),
  mSceneTimer(0)
{

 mPhysXCallback = NXOGRE_NEW_NXOGRE(PhysXCallback)(this);

 mName = description.mName;
 mNameHash = Functions::StringHash(mName);
 
 NxSceneDesc scene_description;
 Functions::PrototypeFunctions::SceneDescriptionToNxSceneDesc(description, scene_description);
 mProcessingPriority = description.mProcessingPriority;
 mFetchingPriority = description.mFetchingPriority;
 mProcessing = false;

 scene_description.userTriggerReport = mPhysXCallback;
 scene_description.userContactReport = mPhysXCallback;
 
 
 NxOgre_ThrowExceptionIfNull(mSDK, NX_MEMORY_PhysicsSDK);
 
 mScene = mSDK->createScene(scene_description);
 
 if (mScene == 0)
 {
  // Hey there! Got an exception that points to here?
  // Check your log or read the exception. It tell you what is wrong with your SceneDescription
  NxOgre_ThrowException(DescriptionInvalidException, Reason::Exceptionise(scene_description, mSDK == 0, mName), Classes::_World);
  return;
 }
  
  Material* material = NXOGRE_NEW_NXOGRE(Material)(mScene->getMaterialFromIndex(0), this);
  mMaterials.insert(material->getNameHash(), material);
  mIndexedMaterials.insert(0, material);
  
  TimeController::getSingleton()->mListeners[mProcessingPriority].insert(this);
  TimeController::getSingleton()->mListeners[mFetchingPriority].insert(this);
  
  
  mSceneTimer = new FixedSceneTimer(this, description.mMaxTimeStep); // temp.
  
  mMachineIterator = mMachines.getIterator();
  
}

Scene::~Scene(void)
{
 
 TimeController::getSingleton()->mListeners[mProcessingPriority].remove(this);
 TimeController::getSingleton()->mListeners[mFetchingPriority].remove(this);
 
 //TimeController::getSingleton()->removeListener(this);
 
 if (mSDK && mScene)
 {
  mActors.clear();
  mSceneGeometries.clear();
  mKinematicActors.clear();
  mKinematicControllers.clear();
  mVolumes.clear();
  mMaterials.clear();
  mFluids.clear();
  mCloths.destroyAll();
  mSoftBodies.destroyAll();
  NXOGRE_DELETE_NXOGRE(mSceneTimer);
  mSDK->releaseScene(*mScene);
  NXOGRE_DELETE_NXOGRE(mPhysXCallback);
 }
}

String Scene::getName(void) const
{
 return mName;
}

StringHash Scene::getNameHash(void) const
{
 return mNameHash;
}

unsigned int Scene::getNbRigidBodies(void) const
{
 return mScene->getNbActors();
}

unsigned int Scene::getNbActors(void) const
{
 return mActors.size();
}

Scene::ActorIterator Scene::getActors(void)
{
 return Scene::ActorIterator(mActors);
}

Actor* Scene::createActor(const ShapeDescriptions& shapes, const Matrix44& pose, const RigidBodyDescription& description)
{
 Actor* actor = NXOGRE_NEW_NXOGRE(Actor)(shapes, pose, description, this);
 StringHash hash = actor->getNameHash();
 mActors.insert(hash, actor);
 return actor;
}

  
Actor* Scene::createActor(const ShapeDescription& shape, const Matrix44& pose, const RigidBodyDescription& description)
{
 Actor* actor = NXOGRE_NEW_NXOGRE(Actor)(shape, pose, description, this);
 StringHash hash = actor->getNameHash();
 mActors.insert(hash, actor);
 return actor;
}

bool Scene::destroyActor(NxOgre::Actor* actor)
{
 
 if (actor == 0)
  return false;
 
 if (actor->isDynamic() == false)
  return false;
 
 mActors.erase(actor);
 
 return true;
}

SceneGeometry* Scene::createSceneGeometry(const ShapeDescriptions& shapes, const Matrix44& pose, const RigidBodyDescription& description)
{
 SceneGeometry* sg = NXOGRE_NEW_NXOGRE(SceneGeometry)(shapes, pose, description, this);
 StringHash hash = sg->getNameHash();
 mSceneGeometries.insert(hash, sg);
 return sg;
}

SceneGeometry* Scene::createSceneGeometry(const ShapeDescription& shape, const Matrix44& pose, const RigidBodyDescription& description)
{
 SceneGeometry* sg = NXOGRE_NEW_NXOGRE(SceneGeometry)(shape, pose, description, this);
 StringHash hash = sg->getNameHash();
 mSceneGeometries.insert(hash, sg);
 return sg;
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
 Material* material = NXOGRE_NEW_NXOGRE Material(description, this);
 mMaterials.insert(material->getNameHash(), material);
 mIndexedMaterials.insert(material->getIdentifier(), material);
 return material;
}


void Scene::destroyMaterial(Material* material)
{
 mIndexedMaterials.erase(material->getIdentifier());
 mMaterials.erase(material->getNameHash());
}

Material* Scene::getMaterial(const MaterialIdentifier& identifier)
{
 return mIndexedMaterials.at(identifier);
}

KinematicActor* Scene::createKinematicActor(const ShapeDescription& shape, const Matrix44& pose, const RigidBodyDescription& description)
{
 KinematicActor* ka = NXOGRE_NEW_NXOGRE(KinematicActor)(shape, pose, description, this);
 StringHash hash = ka->getNameHash();
 mKinematicActors.insert(hash, ka);
 return ka;
}

KinematicActor* Scene::createKinematicActor(const ShapeDescriptions& shapes, const Matrix44& pose, const RigidBodyDescription& description)
{
 KinematicActor* ka = NXOGRE_NEW_NXOGRE(KinematicActor)(shapes, pose, description, this);
 StringHash hash = ka->getNameHash();
 mKinematicActors.insert(hash, ka);
 return ka;
}

KinematicController* Scene::createKinematicController(const Vec3& size, const Vec3& globalPosition)
{
 KinematicController* controller = NXOGRE_NEW_NXOGRE(KinematicController)(size, globalPosition, this);
 StringHash hash = controller->getNameHash();
 mKinematicControllers.insert(hash, controller);
 return controller;
}

Volume* Scene::createVolume(const ShapeDescription& shape, const Matrix44& pose, Callback* callback, Enums::VolumeCollisionType vct)
{
 Volume* vol = NXOGRE_NEW_NXOGRE(Volume)(shape, pose, vct, this, callback);
 StringHash hash = vol->getNameHash();
 mVolumes.insert(hash, vol);
 return vol;
}

Volume* Scene::createVolume(const ShapeDescriptions& shapes, const Matrix44& pose, Callback* callback, Enums::VolumeCollisionType vct)
{
 Volume* vol = NXOGRE_NEW_NXOGRE(Volume)(shapes, pose, vct, this, callback);
 StringHash hash = vol->getNameHash();
 mVolumes.insert(hash, vol);
 return vol;
}

void Scene::destroyJoint(Joint* joint)
{
 mJoints.remove(joint);
 NXOGRE_DELETE_NXOGRE(joint);
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

D6Joint* Scene::createD6Joint(RigidBody* first, const D6JointDescription& desc)
{
 D6Joint* joint = new D6Joint(first, 0, desc);
 mJoints.insert(joint);
 return joint;
}

D6Joint* Scene::createD6Joint(RigidBody* first, RigidBody* second, const D6JointDescription& desc)
{
 D6Joint* joint = new D6Joint(first, second, desc);
 mJoints.insert(joint);
 return joint;
}

Compartment* Scene::createCompartment(const CompartmentDescription& description)
{
 Compartment* compartment = new Compartment(description, this);
 mCompartments.insert(compartment);
 mCompartmentPairs[compartment->getCompartment()] = compartment;
 return compartment;
}

void Scene::setGravity(const Vec3& vec)
{
 mScene->setGravity(vec.as<NxVec3>());
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
 
 PhysXPointer* shapePointer = pointer_cast(nxShape->userData);
 out.mShape = shapePointer->get<Shape>();
 out.mRigidBody = shapePointer->getParent<RigidBody>();
 
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
 
 if (nxShape)
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

const TimeStep& Scene::getTimeStep(void)
{
 return mSceneTimer->getTimeStep();
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
 Cloth* cloth = NXOGRE_NEW_NXOGRE(Cloth)(description, renderable, rp, this);
 mCloths.insert(cloth);
 return cloth;
}

void Scene::destroyCloth(Cloth* cloth)
{
 mCloths.remove(cloth);
 NXOGRE_DELETE_NXOGRE(cloth);
}

SoftBody* Scene::createSoftBody(const SoftBodyDescription& description, Renderable* renderable, Enums::Priority rp)
{
 SoftBody* cloth = NXOGRE_NEW_NXOGRE(SoftBody)(description, renderable, rp, this);
 mSoftBodies.insert(cloth);
 return cloth;
}

void Scene::destroySoftBody(SoftBody* cloth)
{
 mSoftBodies.remove(cloth);
 NXOGRE_DELETE_NXOGRE(cloth);
}

Fluid* Scene::createFluid(const FluidDescription& description, Renderable* renderable, Enums::Priority rp)
{
 Fluid* fluid = NXOGRE_NEW_NXOGRE(Fluid)(description, renderable, rp, this);
 StringHash hash = fluid->getNameHash();
 mFluids.insert(hash, fluid);
 return fluid;
}

void Scene::destroyFluid(NxOgre::Fluid* fluid)
{
 if (fluid)
 {
  if (fluid->getNameHash() == BLANK_HASH)
   mFluids.erase(fluid);
  else
   mFluids.erase(fluid->getNameHash());
 }
}

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
 NxCapsule physx_capsule;
 Functions::SimpleCapsuleToNxCapsule(capsule, physx_capsule);

 unsigned int count = mScene->linearCapsuleSweep(physx_capsule, motion.as<NxVec3>(), sweep_flags, 0, maxShapes, query_hits, 0, activeGroups, 0);
 Functions::SweepFunctions::NxSweepQueryHitsToBuffer(query_hits, count, hits);
 free(query_hits);
 return count;
}

unsigned int Scene::linearOBBSweep(const SimpleBox& box, const Vec3& motion, unsigned int sweep_flags, unsigned int maxShapes, SweepQueryHits& hits, unsigned int activeGroups)
{
 
 NxSweepQueryHit* query_hits = (NxSweepQueryHit*) malloc(sizeof(NxSweepQueryHit) * maxShapes);
 NxBox physx_box;
 Functions::SimpleBoxToNxBox(box, physx_box);

 unsigned int count = mScene->linearOBBSweep(physx_box, motion.as<NxVec3>(), sweep_flags, 0, maxShapes, query_hits, 0, activeGroups, 0);
 Functions::SweepFunctions::NxSweepQueryHitsToBuffer(query_hits, count, hits);
 free(query_hits);
 return count;
}

unsigned int Scene::overlapSphereShape(const SimpleSphere& sphere, Enums::ShapesType type, unsigned int maxShapes, Buffer<Shape*> shapes, unsigned int activeGroups, bool accurateCollision)
{
 
 NxShape* physx_shapes = (NxShape*) malloc(sizeof(NxShape*) * maxShapes);
 
 NxSphere physx_sphere;
 Functions::SimpleSphereToNxSphere(sphere, physx_sphere);
 
 unsigned int count = mScene->overlapSphereShapes(physx_sphere, (NxShapesType) (int) type, maxShapes, &physx_shapes, 0, activeGroups, 0, accurateCollision);
 Functions::ShapeFunctions::NxShapeArrayToBuffer(physx_shapes, count, shapes);
 free(physx_shapes);
 return count;
 
}


unsigned int Scene::overlapSphereShape(const SimpleSphere& sphere, Enums::ShapesType type, Callback* callback, unsigned int activeGroups, bool accurateCollision)
{
 NxSphere physx_sphere;
 Functions::SimpleSphereToNxSphere(sphere, physx_sphere);
 
 PhysXUserDataCallbackReport<NxShape*, Shape, Callback> cb(&Callback::onOverlap, callback);
 
 unsigned int count = mScene->overlapSphereShapes(physx_sphere, (NxShapesType) (int) type, 0, 0, &cb, activeGroups, 0, accurateCollision);
 
 //NXOGRE_DELETE(cb);
 
 return count;
}

SweepCache* Scene::createSweepCache()
{
 return NXOGRE_NEW_NXOGRE(SweepCache)(mScene->createSweepCache());
}

void Scene::destroySweepCache(SweepCache* cache)
{
 mScene->releaseSweepCache(cache->getCache());
 NXOGRE_DELETE_NXOGRE(cache);
}

void Scene::setDominanceGroupPair(GroupIdentifier a, GroupIdentifier b, Real dominance0, Real domaince1)
{
 mScene->setDominanceGroupPair(a, b, NxConstraintDominance(dominance0, domaince1));
}

void Scene::setDominanceGroupPair(GroupIdentifier a, GroupIdentifier b, const ConstraintDominance& constraint)
{
 mScene->setDominanceGroupPair(a, b, NxConstraintDominance(constraint.first, constraint.second));
}

ConstraintDominance Scene::getDominanceGroupPair(GroupIdentifier a, GroupIdentifier b)
{
 NxConstraintDominance constraint = mScene->getDominanceGroupPair(a, b);
 return ConstraintDominance(constraint.dominance0, constraint.dominance1);
}

                                                                                       

} // namespace NxOgre

                                                                                       
