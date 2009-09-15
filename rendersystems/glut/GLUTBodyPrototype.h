/** File: GLUTBody.h
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

#ifndef GLUT_BODYPROTOTYPE_H
#define GLUT_BODYPROTOTYPE_H

                                                                                       

#include "NxOgre.h"
#include "NxOgreRigidBodyPrototype.h"
#include "GLUTCommon.h"

                                                                                       


/** \brief A GLUTPrototype is basically a RigidBodyPrototype containg all the physics data
           collision model and global pose of an RigidBody; but now with some data that describes
           how the rigid body looks on the screen. Using a extension of a RigidBody is one way
           of doing this, in some cases your implementation of NxOgre may require something more
           specific or different in either way - you will need a RigidBodyPrototype. It's just
           how much you use it is important.
*/
class GLUTExportClass GLUTBodyPrototype : public NxOgre::PointerClass<_GLUTBodyPrototype>, public NxOgre::RigidBodyPrototype
{
  public:

  /** \brief Required since RigidBodyPrototype is also a "PointerClass".
  */
 using ::NxOgre::PointerClass<_GLUTBodyPrototype>::operator new;

  /** \brief Required since RigidBodyPrototype is also a "PointerClass".
  */
 using ::NxOgre::PointerClass<_GLUTBodyPrototype>::operator delete;

  /** \brief GLUTPrototype constructor
  */
                                              GLUTBodyPrototype(void);
  
  /** \brief GLUTPrototype destructor
  */
                                             ~GLUTBodyPrototype(void);
  
  /** \brief Reset the RigidBodyPrototype and GLUT bits to it's default state.
  */
                        void                  reset(void);

  /** \brief Does the prototype's variables are in the range of acceptable values?
  */
                        bool                  valid(void);

  /** \brief What the Body will look like on the screen, not how it will behave physically. Remember the collision
             model in NxOgre does not describe how things are drawn, just what parts can touch each other.
  */
  GLUTShape     mVisualShape;
  
  /** \brief Some width, or if a capsule or a sphere; Radius
  */
  float         mWidth;

  /** \brief Some Height. Not used with spheres.
  */
  float         mHeight;

  /** \brief Some depth. Not uses with spheres or capsules
  */
  float         mDepth;

  /** \brief Intensity of red (0.0 - 1.0)
  */
  float         mColourRed;

  /** \brief Intensity of green (0.0 - 1.0)
  */
  float         mColourGreen;

  /** \brief Intensity of blue (0.0 - 1.0)
  */
  float         mColourBlue;

  /** \brief Give the Body a shadow.
  */
  bool          mShadows;

};

                                                                                       

#endif

/*


*/