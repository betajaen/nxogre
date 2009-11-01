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
#include "GLUTBodyDescription.h"

                                                                                       


GLUTRenderSystem::GLUTRenderSystem(void)
{
}

GLUTRenderSystem::~GLUTRenderSystem(void)
{
 mBodies.clear();
}

GLUTBody* GLUTRenderSystem::createGLUTBody(const NxOgre::ShapeDescription& shape, const NxOgre::Matrix44& pose, NxOgre::Scene* scene, const NxOgre::RigidBodyDescription& description)
{
 
 GLUTBodyDescription glut_description;
 description.clone(glut_description); // Copy our RigidBodyDescription properties into our GLUTBodyDescription.

 // Set up our visualisation properties of the other half of the GLUTBodyDescription.
 glut_description.mWidth = 1.0f;
 glut_description.mHeight = 1.0f;
 glut_description.mDepth = 1.0f;
 glut_description.mColourRed = 1.0f;
 glut_description.mColourGreen = 0.5f;;
 glut_description.mColourBlue = 1.0f;
 glut_description.mShadows = true;
 glut_description.mVisualShape = GLUT_Box;

 // Create the body using again the NxOgre_New macro.
 // Passing on;
 //   - The Shape
 //   - Where we want it to be.
 //   - GLUTBodyDescription
 //   - And Scene.
 GLUTBody* body = NxOgre_New(GLUTBody)(shape, pose, glut_description, scene);

 // We own the body, so make a good note of it in mBodies.
 NxOgre::StringHash hash = body->getNameHash();
 mBodies.insert(hash, body);

 // And we are done.
 return body;
}

void GLUTRenderSystem::drawBodies()
{
 for (GLUTBodies::iterator_t body = mBodies.iterator(); body != body.end(); ++body)
  body->render();
}

GLUTRenderSystem::GLUTBodyIterator GLUTRenderSystem::getBodies()
{
 return GLUTBodyIterator(mBodies);
}

                                                                                       
