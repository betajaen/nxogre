/** File: OGRE3DRenderSystem.h
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

#ifndef OGRE3D_COMMON_H
#define OGRE3D_COMMON_H

                                                                                       

#include "NxOgre.h"
#include "Ogre.h"

#   ifdef OGRE3D_FOR_NXOGRE
#     define OGRE3DExportClass
#     define OGRE3DExportFunction
#   else
#     define OGRE3DExportClass
#     define OGRE3DExportFunction
#   endif

/** \brief This enum just stores an integer identifier for the OGRE3D classes. As some of these classes are
           extensions of NxOgre ones. It would be useful to use the same allocator as NxOgre does. For
           that, we need to define these classes we want to use as integers to use them in a PointerClass.
*/
enum
{
  _OGRE3DRenderSystem  = ::NxOgre::Classes::RENDERSYSTEMS_CLASSES_BEGIN + 100,
  _OGRE3DBody,
  _OGRE3DBodyPrototype,
  _OGRE3DRenderable,
  _OGRE3DPointRenderable,
  _OGRE3DKinematicBody,
};

                                                                                       

class OGRE3DRenderSystem;
class OGRE3DBody;
class OGRE3DKinematicBody;
class OGRE3DRigidBodyPrototype;
class OGRE3DRenderable;
class OGRE3DPointRenderable;

                                                                                       

inline Ogre::Matrix4 toMatrix44(NxOgre::Matrix44 m)
{
 return Ogre::Matrix4(m[0][0], m[0][1],m[0][2],m[0][3],
                      m[1][0], m[1][1],m[1][2],m[1][3],
                      m[2][0], m[2][1],m[2][2],m[2][3],
                      m[3][0], m[3][1],m[3][2],m[3][3]);
}

inline NxOgre::Matrix44 fromMatrix4(Ogre::Matrix4 m)
{
 
 return NxOgre::Matrix44(m[0][0], m[0][1], m[0][2], m[0][3],
                         m[1][0], m[1][1], m[1][2], m[1][3],
                         m[2][0], m[2][1], m[2][2], m[2][3],
                         m[3][0], m[3][1], m[3][2], m[3][3]);
 
}

                                                                                       

#endif

/*


*/