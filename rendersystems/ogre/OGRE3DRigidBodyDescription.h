/** File: OGRE3DRigidBodyDescription.h
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

#ifndef OGRE3D_BODYDESCRIPTION_H
#define OGRE3D_BODYDESCRIPTION_H

                                                                                       

#include "NxOgre.h"
#include "NxOgreRigidBodyDescription.h"
#include "OGRE3DCommon.h"

                                                                                       


/** \brief A OGRE3DBodyDescription is basically a RigidBodyDescription containg all the
           physics data collision model and global pose of an RigidBody; but now with some data
           that describes how the rigid body looks on the screen. Using a extension of a RigidBody
           is one way of doing this, in some cases your implementation of NxOgre may require
           something more specific or different, either way - you will need a RigidBodyDescription.
           It's just how much you use it is important.
    \example
      <code>
        OGRE3DRigidBodyDescription description;
        description.mMass = 100.0f; 
        description.mMeshName = "ogrehead.mesh";
        
        OGRE3DBody* body = mOgreRenderSystem->createBody(..., description);
      </code>
*/
class OGRE3DExportClass OGRE3DRigidBodyDescription : public NxOgre::RigidBodyDescription
{
  public:
  
  /** \brief OGRE3DPrototype constructor
  */
                                              OGRE3DRigidBodyDescription(void);
  
  /** \brief OGRE3DPrototype destructor
  */
                                             ~OGRE3DRigidBodyDescription(void);
  
  /** \brief Reset the RigidBodyPrototype and OGRE3D bits to it's default state.
  */
                        void                  reset(void);
  
  /** \brief Does the prototype's variables are in the range of acceptable values?
  */
                        bool                  valid(void);
  
  /** \brief SceneNode to use, or NULL to create.
  */
  Ogre::SceneNode*                            mNode;
  
  /** \brief What to do the Node when the Body is destroyed.
      \default OGRE3DSceneNodeDestructorBehaviour_Destroy
  */
  OGRE3DSceneNodeDestructorBehaviour          mSceneNodeDestructorBehaviour;

  /** \brief Drawing priority
  */
  NxOgre::Enums::Priority                     mRenderPriority;
};

                                                                                       

#endif

/*


*/