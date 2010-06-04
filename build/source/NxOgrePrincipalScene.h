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

                                                                                       

#ifndef NXOGRE_PRINCIPAL_SCENE_H
#define NXOGRE_PRINCIPAL_SCENE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreScene.h"

#include "NxOgreActor.h"
#include "NxOgreSceneGeometry.h"
#include "NxOgreKinematicActor.h"
#include "NxOgreVolume.h"
#include "NxOgreShape.h"
#include "NxOgreFluid.h"
#include "NxOgreMaterial.h"


#include "NxOgreRigidBodyDescription.h"
#include "NxOgreMaterialDescription.h"
#include "NxOgreJointDescription.h"
#include "NxOgreSphericalJointDescription.h"
#include "NxOgreRevoluteJointDescription.h"
#include "NxOgreD6JointDescription.h"
#include "NxOgreClothDescription.h"
#include "NxOgreCompartmentDescription.h"
#include "NxOgreCompartment.h"
#include "NxOgreFluidDescription.h"

#include "NxOgreTimeListener.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. PrincipalScene
    desc.
        Scene's hold RigidBodies, Cloths, Fluids and so on. There can be upto 32 of them.
*/
class NxOgrePublicClass PrincipalScene : public Scene
{
  

  typedef  vector<RigidBody*>           PrincipalDynamics;
  typedef  vector_iterator<RigidBody*>  PrincipalDynamicIterator;
  
  public: // Functions
  
  /** \internal Use World::createScene()
  */
  PrincipalScene(const SceneDescription&, NxPhysicsSDK*);
  
  /** \internal Use World::destroyScene()
  */
 ~PrincipalScene();
  
  /*! function. getType
      desc.
          Get type of scene.
  */
  Enums::SceneType getType() const;
  
  /*! function. Add a dynamic rigidbody from all auxiliary scenes.
  */
  void                       addPrincipalDynamic(RigidBody*);
  
  /*! function. Remove a dynamic rigidbody from all auxiliary scenes.
  */
  void                       removePrincipalDynamic(RigidBody*);
  
  /*! function. Get an iterator to the current principal dynamics.
  */
  PrincipalDynamicIterator   getPrincipalDynamics();

  protected: // Variables
  
  PrincipalDynamics          mPrincipalDynamics;
  
}; // class Scene

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
