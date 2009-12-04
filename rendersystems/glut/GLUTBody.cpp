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
#include "GLUTBodyPrototype.h"
#include <GL/glut.h>

                                                                                       

GLUTBody::GLUTBody(GLUTBodyPrototype* prototype, NxOgre::Scene* scene)
: Actor(scene) // Take notice of the constructor we are using, it's designed for
{                                  // classes that inherit from Actor. Copying over the shapes array is
                                   // essential, since RigidBody could be a particle or a tree it doesn't
                                   // implement it's own shapes array for memory reasons, but actors do.
                                   // Hense the copying.

 // Implement the prototype (it's being casted back into a RigidBodyPrototype) so it's treated
 // as a normal RigidBody. 
 create(prototype, scene, &mShapes);

 // Since NxOgre doesn't know or care about our GL stuff, we copy it over. This is the correct time to create
 // or turn on things related to the GLUTBody.

 mVisualShape = prototype->mVisualShape;
 mWidth = prototype->mWidth;
 mHeight = prototype->mHeight;
 mDepth = prototype->mDepth;
 mColourRed = prototype->mColourRed;
 mColourGreen = prototype->mColourGreen;
 mColourBlue = prototype->mColourBlue;
 mShadows = prototype->mShadows;

 // No cleaning up the prototype here, it's not ours to do so.
}

GLUTBody::~GLUTBody()
{
 // In here, we would clean up any rendering stuff. But there isn't anything to clean.
 // We leave the physics stuff to the Actors destructor.
}


void GLUTBody::render(void)
{

  // Render actor
  glPushMatrix();
  float glMat[16];
  
  getGlobalPose().columnMajor(glMat);
  
  glMultMatrixf(glMat);
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

  // Render shadow
  glPushMatrix();
  const static float shadowMat[]={ 1,0,0,0, 0,0,0,0, 0,0,1,0, 0,0,0,1 };
  glMultMatrixf(shadowMat);
  glMultMatrixf(glMat);
  glDisable(GL_LIGHTING);
  glColor4f(0.1f, 0.2f, 0.3f, 1.0f);

  switch (mVisualShape)
  {
   case GLUT_Box:
    glScalef(mWidth, mHeight, mDepth);
    glutSolidCube(1);
   break;

   case GLUT_Sphere:
    glutSolidSphere(mWidth, 4, 4);
   break;

   case GLUT_Capsule:

   break;
  }

  glEnable(GL_LIGHTING);
  glPopMatrix();

}

                                                                                       
