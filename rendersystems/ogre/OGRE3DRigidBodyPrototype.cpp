/** File: OGRE3DRigidBodyPrototype.cpp
    Created on: 9-Nov-08
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

                                                                                       

#include "OGRE3DRigidBodyPrototype.h"

                                                                                       

OGRE3DRigidBodyPrototype::OGRE3DRigidBodyPrototype(void)
{
 reset();
}

OGRE3DRigidBodyPrototype::~OGRE3DRigidBodyPrototype(void)
{
 // Nothing to do in here.
}

void OGRE3DRigidBodyPrototype::reset(void)
{
 // Reset the physics bits.
 RigidBodyPrototype::reset();

 // Reset the visual bits.
 mSceneManager   = NULL;
 mNode           = NULL;
 mEntity         = NULL;
 mRenderPriority = NxOgre::Enums::Priority_Medium;

}

bool OGRE3DRigidBodyPrototype::valid(void)
{
 // Check to see if the physics bits are valid.
 if (!RigidBodyPrototype::valid())
  return false;

 // If there is an entity; there must be a node.
 if (mEntity && mNode == 0)
  return false;

 // Can't have an entity and a meshname.
 if (mEntity && mMeshName.size())
  return false;

 // Must have a scene manager.
 if (mSceneManager == NULL)
  return false;

 // If we reached here then everything is okay.
 return true;
}

                                                                                       
