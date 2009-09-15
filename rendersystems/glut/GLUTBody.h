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

#ifndef GLUT_Body_H
#define GLUT_Body_H

                                                                                       

#include "NxOgre.h"
#include "GLUTCommon.h"
#include "NxOgreRigidBodyDescription.h"

                                                                                       

/** \brief A GLUTBody is just an Actor that is "rendered" on the screen. Not only containing
           the standard physics properties and functions of an Actor. It also contains some
           information describing the object visually; what shape it is, it's dimensions and
           it's colour. Once combined that with the getPose() function from Actor. It's pretty
           easy to use all of that information to draw something on the screen. Of course in
           different types of RenderSystems available; the render information would be different.
           Ogre's for example wouldn't be as low-level, and would only contain a pointer to a node
           on a scenegraph, as well as reference to the mesh it is using.

*/
class GLUTExportClass GLUTBody : public NxOgre::PointerClass<_GLUTBody>, public NxOgre::Actor
{
  friend class GLUTRenderSystem;
  friend class ::NxOgre::Functions::ArrayFunctions<GLUTBody*>::Write;

  public:
  
   /** \brief Required since Actor is also a "PointerClass".
   */
   using ::NxOgre::PointerClass<_GLUTBody>::operator new;

    /** \brief Required since Actor is also a "PointerClass".
    */
   using ::NxOgre::PointerClass<_GLUTBody>::operator delete;

    /** \brief Draw the actor on the screen.
    */
    void           render(void);
  
  protected:
  
     /** \internal. Use GLUTRenderSystem::createBody
     */
     GLUTBody(GLUTBodyPrototype*, NxOgre::Scene*);
  
     /** \internal. Use GLUTRenderSystem::destroyBody
     */
    ~GLUTBody(void);
  
  protected:
  
     unsigned int  mVisualShape;
     float         mWidth;
     float         mHeight;
     float         mDepth;
     float         mColourRed;
     float         mColourGreen;
     float         mColourBlue;
     bool          mShadows;

};

                                                                                       

#endif

/*


*/