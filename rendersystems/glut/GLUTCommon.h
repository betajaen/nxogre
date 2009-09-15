/** File: GLUTRenderSystem.h
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

#ifndef GLUT_COMMON_H
#define GLUT_COMMON_H

                                                                                       

#include "NxOgre.h"

#   ifdef GLUT_FOR_NXOGRE
#     define GLUTExportClass
#     define GLUTExportFunction
#   else
#     define GLUTExportClass
#     define GLUTExportFunction
#   endif

/** \brief This enum just stores an integer identifier for the GLUT classes. As some of these classes are
           extensions of NxOgre ones. It would be useful to use the same allocator as NxOgre does. For
           that, we need to define these classes we want to use as integers to use them in a PointerClass.
*/
enum
{
  _GLUTRenderSystem  = 78201,
  _GLUTBody          = 78202,
  _GLUTBodyPrototype = 78203,
};

/** \brief Not to be confused by the NxOgre Shape system; this what things look like on the Screen. Remember
           as far as NxOgre cares you can have a cube that behaves like a sphere, or a mountain that looks like
           a cube.
*/
enum GLUTShape
{
 GLUT_Box,
 GLUT_Sphere,
 GLUT_Capsule,
 GLUT_Plane
};

/** \brief RGB colour using three floats as intensity values from 0.0 to 1.0
*/
typedef NxOgre::Vec3 Colour;

/** \brief A typedef to represent the size of a GLUT_box as three floats.
*/
typedef NxOgre::Vec3 Size3;

/** \brief A typedef to represent the size of a GLUT_Capsule and GLUT_Plane as two floats.
*/
typedef NxOgre::Vec2 Size2;

                                                                                       

class GLUTRenderSystem;
class GLUTBody;
class GLUTBodyPrototype;

                                                                                       

#endif

/*


*/