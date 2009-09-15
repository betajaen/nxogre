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

#ifndef GLUT_RENDERSYSTEM_H
#define GLUT_RENDERSYSTEM_H

                                                                                       

#include "NxOgre.h"
#include "GLUTCommon.h"
#include "NxOgreArray.h"

                                                                                       

class GLUTExportClass GLUTRenderSystem : public NxOgre::PointerClass<_GLUTRenderSystem>, public NxOgre::TimeListener
{
  public:

     /** \brief
     */
     GLUTRenderSystem(NxOgre::Scene*, NxOgre::Enums::Priority render_priority = NxOgre::Enums::Priority_Medium);

     /** \brief
     */
    ~GLUTRenderSystem(void);

     /** \brief
     */
     GLUTBody*                            createBody(NxOgre::Shape*, NxOgre::Vec3 position, GLUTShape, Size3 size, Colour colour = Colour(1,1,1), bool shadows = true, const NxOgre::RigidBodyDescription& = NxOgre::RigidBodyDescription());

     /** \brief
     */
     bool                                 advance(float deltaTime, const ::NxOgre::Enums::Priority&);

  protected:

     NxOgre::Scene*           mScene;
     NxOgre::Array<GLUTBody*> mBodies;
};

                                                                                       

#endif
