/** File: GLUTBodyPrototype.cpp
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

                                                                                       

#include "GLUTBodyPrototype.h"

                                                                                       

GLUTBodyPrototype::GLUTBodyPrototype(void)
{
 reset();
}

GLUTBodyPrototype::~GLUTBodyPrototype(void)
{
 // Nothing to do in here.
}

void GLUTBodyPrototype::reset(void)
{
 // Reset the physics bits.
 RigidBodyPrototype::reset();

 // Reset the visual bits.
 mVisualShape = GLUT_Box;
 mWidth = 1;
 mHeight = 1;
 mDepth = 1;
 mColourRed = 1;
 mColourGreen = 1;
 mColourBlue = 1;
 mShadows = true;
}

bool GLUTBodyPrototype::valid(void)
{
 // Check to see if the physics bits are valid.
 if (!RigidBodyPrototype::valid())
  return false;

 // Type must be Box, Sphere, Capsule or Plane.
 if (!(mVisualShape >= GLUT_Box && mVisualShape <= GLUT_Plane))
  return false;

 // Sizes must be positive reals.
 if (mWidth < 0 || mHeight < 0 || mDepth < 0)
  return false;

 // Colour values must be <= 1
 if (mColourRed > 1 || mColourGreen > 1 || mColourBlue > 1)
  return false;

 // Colour values must be >= 0
 if (mColourRed < 0 || mColourGreen < 0 || mColourBlue < 0)
  return false;

 // If we reached here then everything is okay.
 return true;
}

                                                                                       
