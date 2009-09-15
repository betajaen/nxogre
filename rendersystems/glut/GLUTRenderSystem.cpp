/** File: GLUTRenderSystem.cpp
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

                                                                                       

#include "GLUTRenderSystem.h"
#include "NxOgre.h"
#include "GLUTBody.h"
#include "GLUTBodyPrototype.h"

                                                                                       


GLUTRenderSystem::GLUTRenderSystem(NxOgre::Scene* scene, NxOgre::Enums::Priority priority)
: mScene(scene)
{
 NxOgre::TimeController::getSingleton()->addTimeListener(this, priority);
}

GLUTRenderSystem::~GLUTRenderSystem(void)
{
 mBodies.destroyAll();
}

GLUTBody* GLUTRenderSystem::createBody(NxOgre::Shape* shape, NxOgre::Vec3 position, GLUTShape glut_shape, Size3 size, Colour colour, bool shadows, const NxOgre::RigidBodyDescription& description)
{
 // Create a GLUTPrototype using the NxOgre_New macro, all NxOgre classes and classes that
 // use PointerClass should use NxOgre_New and NxOgre_Delete.
 GLUTBodyPrototype* prototype = NxOgre_New(GLUTBodyPrototype)();

 // Send the physics stuff from the description into the prototype. This is quite important.
 NxOgre::Functions::PrototypeFunctions::RigidBodyDescriptionToRigidBodyPrototype(description, prototype);
 
 // We want a dynamic rigid body, that jumps around in the fields with other dynamic rigid bodies.
 prototype->mType = NxOgre::Enums::RigidBodyType_Dynamic;

 // Copy the position over to the prototype.
 prototype->mGlobalPose.identity();
 prototype->mGlobalPose.set(position);

 // Add the shape to the list of shapes in the prototype.
 prototype->mShapes.insert(shape);

 // And our bits.
 prototype->mWidth = size.x;
 prototype->mHeight = size.y;
 prototype->mDepth = size.z;
 prototype->mColourRed = colour.x;
 prototype->mColourGreen = colour.y;
 prototype->mColourBlue = colour.z;
 prototype->mShadows = shadows;
 prototype->mVisualShape = glut_shape;

 // Create the body using again the NxOgre_New macro. Passing on the prototype we just created and a copy
 // of the scene pointer. we are using.
 GLUTBody* body = NxOgre_New(GLUTBody)(prototype, mScene);

 // Make a local copy of the body pointer, for rendering and deleting.
 mBodies.insert(body);

 // Since the GLUTBody and NxOgre no longer needs the prototype, and we don't either. It's time to clean up.
 NxOgre_Delete(prototype);

 // And we are done.
 return body;
}

bool GLUTRenderSystem::advance(float deltaTime, const ::NxOgre::Enums::Priority&)
{
 NxOgre::Array<GLUTBody*>::Iterator it = mBodies.getIterator();
 for (GLUTBody* body = it.begin();body = it.next();)
  body->render();
 return true;
}

                                                                                       
