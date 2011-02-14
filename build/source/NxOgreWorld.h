/** 
    
    This file is part of NxOgre.
    
    Copyright(c) 2011 Robin Southern, http://github.com/betajaen/nxogre/
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files(the "Software"), to deal
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

#ifndef NXOGRE_WORLD_H
#define NXOGRE_WORLD_H

#include "NxOgreRequired.h"

class NxPhysicsSDK;
class NxPhysicsSDKDesc;

namespace NxOgre
{

class PhysXAllocator;
class PhysXOutputStream;

namespace Enums
{
 
 /*! enum. PhysXAssertionPolicy
     desc.
          What do when there is an assertion from PhysX
     enums.
          PhysXAssertionPolicy_Continue -- Continue
          PhysXAssertionPolicy_Ignore -- Ignore and don't report this assert from now on
          PhysXAssertionPolicy_Breakpoint -- Breakpoint
          PhysXAssertionPolicy_Exception -- Throw a exception
 */
 enum PhysXAssertionPolicy
 {
  PhysXAssertionPolicy_Continue = 0,
  PhysXAssertionPolicy_Ignore = 1,
  PhysXAssertionPolicy_Breakpoint = 2,
  PhysXAssertionPolicy_Exception = 3,
 };
 
};

/* class. WorldDescription
   desc.
       Description class for a new World.
*/
class NXOGRE_CLASS WorldDescription
{
  
 public:

  // --------------------------------------------------

  struct Reason
  {
   bool assertion_policy : 1;
   bool cooker_thread_mask : 1;
   bool hardware_page_size : 1;
   bool hardware_maximum_convex : 1;
   bool hardware_maximum_page : 1;
   bool no_hardware : 1;
   bool per_scene_batching : 1;
   bool gpu_heap_size : 1;
   bool mesh_cache_size : 1;
   int UNUSED : 23;
  };

  // --------------------------------------------------

  /* constructor. WorldDescription
     desc.
         Sets the WorldDescription to the default values.
  */
  NXOGRE_FORCE_INLINE WorldDescription()
  {
   reset();
  }

  // --------------------------------------------------
  
  /* function. isValid
     desc.
         Reset the description to the default values.
  */
  NXOGRE_FORCE_INLINE void reset()
  {
   mAssertionPolicy = Enums::PhysXAssertionPolicy_Continue;
   mCookerThreadMask = 0;
   mHardwareMaximumConvex = 2048;
   mHardwareMaximumPage = 256;
   mNoHardware = true;
   mPerSceneBatching = true;
   mGPUHeapSize = 32;
   mMeshCacheSize = 0xffffffff;
   mHardwarePageSize = 65536;
  }
  
  // --------------------------------------------------
  
  /*! function. to_s
      desc.
          to string
  */
  String to_s() const;
  
  // --------------------------------------------------
  
  /* function. isValid
     desc.
         Is the description valid or not?
     see.
         WorldDescription::isValid()
  */
  NXOGRE_FORCE_INLINE bool isValid() const
  {
   if ( mHardwarePageSize != 65536 )
    return false;
   if ( mHardwareMaximumConvex & (mHardwareMaximumConvex - 1) )
    return false;
   if ( mHardwareMaximumPage & (mHardwareMaximumPage - 1) )
    return false;
   if ( mGPUHeapSize & (mGPUHeapSize - 1) )
    return false;
   if ( (mMeshCacheSize != 0xffffffff) && (mMeshCacheSize & (mMeshCacheSize - 1)) )
    return false;
   if ( (mMeshCacheSize != 0xffffffff) && (mMeshCacheSize >= mGPUHeapSize) && (mMeshCacheSize != 0) )
    return false;
   return true;
  }
  
  // --------------------------------------------------

  /* function. wrong
     desc.
         Is the description valid or not?
     see.
         WorldDescription::wrong()
  */
  NXOGRE_FORCE_INLINE Reason wrong() const
  {
   Reason r = {0,0,0, 0,0,0, 0,0,0, 0};

   if ( mHardwarePageSize != 65536 )
    r.hardware_page_size = true;
   if ( mHardwareMaximumConvex & (mHardwareMaximumConvex - 1) )
    r.hardware_maximum_convex = true;
   if ( mHardwareMaximumPage & (mHardwareMaximumPage - 1) )
    r.hardware_maximum_page = true;
   if ( mGPUHeapSize & (mGPUHeapSize - 1) )
    r.gpu_heap_size = true;
   if ( (mMeshCacheSize != 0xffffffff) && (mMeshCacheSize & (mMeshCacheSize - 1)) )
    r.mesh_cache_size = true;
   if ( (mMeshCacheSize != 0xffffffff) && (mMeshCacheSize >= mGPUHeapSize) && (mMeshCacheSize != 0) )
    r.mesh_cache_size = true;
   return r;
  }
  
  // --------------------------------------------------

  /*! function. to_physx_desc
      desc.
          Converts this description into a NxPhysicsSDKDesc.
  */
  NxPhysicsSDKDesc to_physx_desc() const;

  // --------------------------------------------------

  /*! variable. mAssertionResponse
      desc.
          What to do when there is an assertion from PhysX.
      default.
          Enums::PhysXAssertion_Continue
  */
  Enums::PhysXAssertionPolicy mAssertionPolicy;

  // --------------------------------------------------

  /*! variable. mCookerThreadMask
      desc.
          Thread affinity mask for the background cooker thread.
      default.
          0
  */
  uint mCookerThreadMask;

  // --------------------------------------------------

  /*! variable. mHardwareMaximumConvex
      desc.
          Maximum number of convex meshes that would be resident on hardware.
      default.
          2048
      condition.
          mHardwareMaximumConvex must be a power of 2
  */
  uint mHardwareMaximumConvex;

  // --------------------------------------------------

  /*! variable. mHardwarePageSize
      desc.
          Size of hardware mesh pages
      default.
          65536
      condition.
          A value of 65536 is only accepted.
  */
  uint mHardwarePageSize;
  
  // --------------------------------------------------

  /*! variable. mHardwareMaximumPage
      desc.
          Maximum number of hardware pages supported on the hardware.
      default.
          256
      condition.
          mHardwareMaximumPage must be a power of 2
  */
  uint mHardwareMaximumPage;

  // --------------------------------------------------

  /*! variable. mNoHardware
      desc.
          Disable simulation on a PPU or GPU completely.
      default.
          true
  */
  bool mNoHardware;

  // --------------------------------------------------

  /*! variable. mPerSceneBatching
      desc.
          Enable or Disable per Scene batching.
          
          Performance for GPU-optimized applications can often be improved
          with this flag, but some legacy applications may perform better with it unset.
      default.
          true
  */
  bool mPerSceneBatching;

  // --------------------------------------------------

  /*! variable. mGPUHeapSize
      desc.
          Sets the amount of GPU memory which will be reserved for the SDK. 
      condition.
          The valid value must be power of 2, and measured in megabytes.
      default.
          32 (MB)
  */
  uint mGPUHeapSize;

  // --------------------------------------------------
  
  /*! variable. mMeshCacheSize
      desc.
          Amount of SDK GPU heap memory used by the mesh cache for fluids. 
      condition.
          The valid value must be power of 2, smaller than the GPU heap size and
          measured in megabytes.
      note.
          A value of 0xffffffff sets the mesh cache size to 1/8 of the GPU heap size.
      default.
          0xffffffff
  */
  uint mMeshCacheSize;

  // --------------------------------------------------

};

// --------------------------------------------------

class NXOGRE_CLASS World : public AllocatedClass::BigClass
{
  
 public:
  
  // --------------------------------------------------

  /*! function. createWorld
      desc.
          Creates the World, PhysX and essential classes.
      note.
          The World constructor is protected due to World being a Singleton,
          so all requests to create and destroy World go through the createWorld
          and destroyWorld functions, so secondary requests can fail gracefully.
      args.
          WorldDescription - Description to PhysX and World, default: WorldDescription::reset()
  */
  static World* createWorld(const WorldDescription& description = WorldDescription());

  // --------------------------------------------------

  /*! function. destroyWorld
      desc.
          Destroys World, PhysX, and all created NxOgre classes.
      note.
          The World constructor is protected due to World being a Singleton,
          so all requests to create and destroy World go through the createWorld
          and destroyWorld functions, so secondary requests can fail gracefully.
  */
  static void destroyWorld();

  // --------------------------------------------------

  /*! function. getSingleton
      desc.
          Returns a pointer to the current World.
      note.
          If world has not been created yet or has been destroyed; then
          a NULL pointer is returned.
  */
  NXOGRE_FORCE_INLINE static World* getSingleton()
  {
   return SINGLETON;
  }
  
  // --------------------------------------------------
  
  /*! function. setPhysXAssertionPolicy
      desc.
          Set assertion policy when PhysX encounters an error.
  */
  void setPhysXAssertionPolicy(Enums::PhysXAssertionPolicy);
  
  // --------------------------------------------------
  
  /*! function. GetPhysXAssertionPolicy
      desc.
          Get assertion policy when PhysX encounters an error.
  */
  Enums::PhysXAssertionPolicy getPhysXAssertionPolicy() const;
  
  // --------------------------------------------------
  
  /*! function. saveToDescription
      desc.
          Get the description of the world of when it was created.
  */
  WorldDescription saveToDescription() const;
  
  // --------------------------------------------------
  
  /*! function. advance
      desc.
          Advance time
      note.
          This is a legacy function, for more accurate Scene control, you
          should call Scene::advance(deltaTime) per Scene as needed.
  */
  void advance(Real deltaTime);
  
 protected:

  // --------------------------------------------------

  World(const WorldDescription& description);

  // --------------------------------------------------

  ~World();

  // --------------------------------------------------

  void loadFromDescription(const WorldDescription&);

  // --------------------------------------------------

 protected:
  
  static World*               SINGLETON;
  
  NxPhysicsSDK*               mSDK;
  
  WorldDescription            mDescription;
  
  PhysXAllocator*             mPhysXAllocator;
  
  PhysXOutputStream*          mPhysXOutputStream;
  
  vector<class Scene*>::type  mScenes;
  
};

// --------------------------------------------------

/* function. to_s (WorldDescription::Reason)
   desc.
       Converts a WorldDescription::Reason struct into a readable string with the name
       of each member variable that are true which separated by a new line.
   example.
       WorldDescription::Reason r;
       r.assertion_response = true;
       r.cooker_thread_mask = true;
       to_s(r)   =>    "Assertion Response\n"
                       "Cooker Thread Mask"
*/
String to_s(const WorldDescription::Reason&);

// --------------------------------------------------

} // namespace NxOgre



#if NXOGRE_C_API == 1

extern "C"
{
 
 struct NXC_WorldDescription
 {
  int assertion_policy;
  unsigned int cooker_thread_mask;
  unsigned int hardware_maximum_convex;
  unsigned int hardware_page_size;
  unsigned int hardware_maximum_page;
  int no_hardware;
  int per_scene_batching;
  unsigned int gpu_heap_size;
  unsigned int mesh_cache_size;
 };
 
 NXOGRE_C_FUNCTION void* NXC_WorldCreate(NXC_WorldDescription* d)
 {
  NxOgre::WorldDescription desc;
  desc.mAssertionPolicy = (NxOgre::Enums::PhysXAssertionPolicy) d->assertion_policy;
  desc.mCookerThreadMask = d->cooker_thread_mask;
  desc.mGPUHeapSize = d->gpu_heap_size;
  desc.mHardwareMaximumConvex = d->hardware_maximum_convex;
  desc.mHardwareMaximumPage = d->hardware_maximum_page;
  desc.mHardwarePageSize = d->hardware_page_size;
  desc.mMeshCacheSize = d->mesh_cache_size;
  desc.mNoHardware = d->no_hardware;
  desc.mPerSceneBatching = d->per_scene_batching;
  return NxOgre::World::createWorld(desc);
 }
 
 NXOGRE_C_FUNCTION void NXC_WorldDestroy()
 {
  NxOgre::World::destroyWorld();
 }

 NXOGRE_C_FUNCTION NXC_WorldDescription* NXC_WorldDescriptionNew()
 {
  NXC_WorldDescription* desc = new NXC_WorldDescription();
  desc->assertion_policy = NxOgre::Enums::PhysXAssertionPolicy_Continue;
  desc->cooker_thread_mask = 0;
  desc->gpu_heap_size = 32;
  desc->hardware_maximum_convex = 2048;
  desc->hardware_maximum_page = 256;
  desc->hardware_page_size = 65536;
  desc->mesh_cache_size = 0xffffffff;
  desc->no_hardware = true;
  desc->per_scene_batching = true;
  return desc;
 }

 NXOGRE_C_FUNCTION void NXC_WorldDescriptionReset(NXC_WorldDescription* desc)
 {
  std::cout << "Reseting\n";
  desc->assertion_policy = NxOgre::Enums::PhysXAssertionPolicy_Continue;
  desc->cooker_thread_mask = 0;
  desc->gpu_heap_size = 32;
  desc->hardware_maximum_convex = 2048;
  desc->hardware_maximum_page = 256;
  desc->hardware_page_size = 65536;
  desc->mesh_cache_size = 0xffffffff;
  desc->no_hardware = true;
  desc->per_scene_batching = true;
 }

 NXOGRE_C_FUNCTION void NXC_WorldDescriptionDelete(NXC_WorldDescription* desc)
 {
  if (desc)
   delete desc;
 }
 
 NXOGRE_C_FUNCTION void NXC_WorldAdvance(NxOgre::World* world, float time)
 {
  world->advance(time);
 }

 NXOGRE_C_FUNCTION NxOgre::World* NXC_WorldSingleton()
 {
  return NxOgre::World::getSingleton();
 }
 
 NXOGRE_C_FUNCTION void NXC_WorldSetAssertionPolicy(NxOgre::World* world, int policy)
 {
  world->setPhysXAssertionPolicy((NxOgre::Enums::PhysXAssertionPolicy) policy);
 }
 
 NXOGRE_C_FUNCTION int NXC_WorldGetAssertionPolicy(NxOgre::World* world)
 {
  return world->getPhysXAssertionPolicy();
 }
 
}

#endif

#endif
