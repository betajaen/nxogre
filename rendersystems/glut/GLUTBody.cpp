/** File: GLUTBody.cpp
    Created on: 10-Nov-08
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

                                                                                       

#include "GLUTBody.h"
#include "GLUTBodyDescription.h"
#include <GL/glut.h>

                                                                                       

GLUTBody::GLUTBody(NxOgre::Shape* shape, const NxOgre::Matrix44& globalPose, const GLUTBodyDescription& description, NxOgre::Scene* scene)
: Actor(scene) // Take notice of the constructor we are using, it's designed for classes that inherit from Actor.
{
 
 // Implement the prototype (it's being casted back into a RigidBodyPrototype) so it's treated
 // as a normal RigidBody. 
 createDynamic(globalPose, description, scene, shape);

 // Since NxOgre doesn't know or care about our GL stuff, we copy it over. This is the correct time to create
 // or turn on things related to the GLUTBody.

 mVisualShape = description.mVisualShape;
 mWidth = description.mWidth;
 mHeight = description.mHeight;
 mDepth = description.mDepth;
 mColourRed = description.mColourRed;
 mColourGreen = description.mColourGreen;
 mColourBlue = description.mColourBlue;
 mShadows = description.mShadows;

 // No cleaning up the prototype here, it's not ours to do so.
}

GLUTBody::~GLUTBody()
{
 // In here, we would clean up any rendering stuff. But there isn't anything to clean.
 // We leave the physics stuff to the Actors destructor.
}


void GLUTBody::render(void)
{
  glPushMatrix();
  float glMat[16];
  
  getGlobalPose().columnMajor(glMat);
  
  glMultMatrixf(glMat);
  glColor4f(mColourRed, mColourGreen, mColourBlue, 1.0f);

  switch (mVisualShape)
  {
   case GLUT_Box:
    glScalef(mWidth, mHeight, mDepth);
    glutSolidCube(1);
   break;

   case GLUT_Sphere:
    glutSolidSphere(mWidth, 8, 8);
   break;

   case GLUT_Capsule:

   break;
  }
  
  glPopMatrix();
}

                                                                                       
