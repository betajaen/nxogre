/** File: OGRE3DBody.h
    Created on: 25-Nov-08
    Author: Robin Southern "betajaen"
    

    Copyright (c) 2008-2009 Robin Southern

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

#ifndef OGRE3D_BODYPROTOTYPE_H
#define OGRE3D_BODYPROTOTYPE_H

                                                                                       

#include "NxOgre.h"
#include "NxOgreRigidBodyPrototype.h"
#include "OGRE3DCommon.h"

                                                                                       


/** \brief A OGRE3DPrototype is basically a RigidBodyPrototype containg all the physics data
           collision model and global pose of an RigidBody; but now with some data that describes
           how the rigid body looks on the screen. Using a extension of a RigidBody is one way
           of doing this, in some cases your implementation of NxOgre may require something more
           specific or different in either way - you will need a RigidBodyPrototype. It's just
           how much you use it is important.
*/
class OGRE3DExportClass OGRE3DRigidBodyPrototype : public NxOgre::PointerClass<_OGRE3DBodyPrototype>, public NxOgre::RigidBodyPrototype
{
  public:

  /** \brief Required since RigidBodyPrototype is also a "PointerClass".
  */
 using ::NxOgre::PointerClass<_OGRE3DBodyPrototype>::operator new;

  /** \brief Required since RigidBodyPrototype is also a "PointerClass".
  */
 using ::NxOgre::PointerClass<_OGRE3DBodyPrototype>::operator delete;

  /** \brief OGRE3DPrototype constructor
  */
                                              OGRE3DRigidBodyPrototype(void);
  
  /** \brief OGRE3DPrototype destructor
  */
                                             ~OGRE3DRigidBodyPrototype(void);
  
  /** \brief Reset the RigidBodyPrototype and OGRE3D bits to it's default state.
  */
                        void                  reset(void);
  
  /** \brief Does the prototype's variables are in the range of acceptable values?
  */
                        bool                  valid(void);

  /** \brief SceneManager to use, or NULL to use the RenderSystems
  */
  Ogre::SceneManager*  mSceneManager;

  /** \brief SceneNode to use, or NULL to create.
  */
  Ogre::SceneNode*     mNode;
  
  /** \brief Entity to attach to SceneNode or NULL for none.
  */
  Ogre::Entity*        mEntity;
  
  /** \brief Mesh name otherwise use mEntity.
  */
  Ogre::String         mMeshName;

  /** \brief Drawing priority
  */
  NxOgre::Enums::Priority  mRenderPriority;
};

                                                                                       

#endif

/*


*/