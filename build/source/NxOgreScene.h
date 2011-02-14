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

#ifndef NXOGRE_SCENE_H
#define NXOGRE_SCENE_H

#include "NxOgreRequired.h"

class NxScene;
class NxSceneDesc;

namespace NxOgre
{

/* class. SceneDescription
   desc.
       Description class for a new Scene.
*/
class NXOGRE_CLASS SceneDescription
{
  
 public:

  // --------------------------------------------------

  struct Reason
  {
   bool assertion_policy : 1;
  };

  // --------------------------------------------------

  /* constructor. SceneDescription
     desc.
         Sets the SceneDescription to the default values.
  */
  NXOGRE_FORCE_INLINE SceneDescription()
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
  }

  // --------------------------------------------------

  /* function. isValid
     desc.
         Is the description valid or not?
     see.
         WorldDescription::isValid()
  */
  NXOGRE_FORCE_INLINE bool isValid() const
  {
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
   Reason r = {0};

   return r;
  }
  
  // --------------------------------------------------

  /*! function. to_physx_desc
      desc.
          Converts this description into a NxPhysicsSDKDesc.
  */
  NxSceneDesc to_physx_desc() const;

  // --------------------------------------------------

  /*! variable. mCookerThreadMask
      desc.
          Thread affinity mask for the background cooker thread.
      default.
          0
  */
  uint mCookerThreadMask;

  // --------------------------------------------------

};

// --------------------------------------------------

class NXOGRE_CLASS Scene : public AllocatedClass::BigClass
{
  
 public:
  
  // --------------------------------------------------

  /*! function. loadFromDescription
      desc.
          Load Scene from Description
  */
  void loadFromDescription(const SceneDescription& desc);
  
  // --------------------------------------------------
  
  /*! function. saveToDescription
      desc.
          Get the description of the world of when it was created.
  */
  SceneDescription saveToDescription() const;
  
  // --------------------------------------------------
  
  /*! function. advance
      desc.
          Advance time
  */
  void advance(Real deltaTime);
  
 protected:

  // --------------------------------------------------

  Scene(const SceneDescription& description, class World* parent);

  // --------------------------------------------------

 ~Scene();

  // --------------------------------------------------

 protected:
  
  class World*                mParent;
  
  NxScene*                    mScene;
  
};

// --------------------------------------------------

/* function. to_s (SceneDescription::Reason)
   desc.
       Converts a SceneDescription::Reason struct into a readable string with the name
       of each member variable that are true which separated by a new line.
   example.
       SceneDescription::Reason r;
       r.assertion_response = true;
       r.cooker_thread_mask = true;
       to_s(r)   =>    "Assertion Response\n"
                       "Cooker Thread Mask"
*/
String to_s(const SceneDescription::Reason&);

// --------------------------------------------------

} // namespace NxOgre

#endif
