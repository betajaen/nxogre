/** 
    
    This file is part of NxOgre.
    
    Copyright (c) 2009 Robin Southern, http://www.nxogre.org
    
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

                                                                                       

#ifndef NXOGRE_RENDERABLE_H
#define NXOGRE_RENDERABLE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief Renderable is an abstract class with functions to pass onto a RenderSystem to add vertices and indexes to a Scene.
    \warning DO NOT CREATE THIS CLASS MANUALLY. Use a RenderSystem implementation of this class instead.
*/
class NxOgrePublicClass Renderable
{
  
  
  public: // Functions
  
  /**
  */
  Renderable(int);
  
  /**
  */
  virtual ~Renderable();
  
  /** \brief Draw some PhysXMeshData.
  */
  virtual void drawSoftBodySimple(MeshRenderable*, const Bounds3&) = 0;
  
  /** \brief Draw some PhysXMeshData with texture coordinates.
  */
  virtual void drawCloth(MeshRenderable*, const Bounds3&) = 0;
   
  /** \brief Draw some PhysXMeshData with texture coordinates.
  */
  virtual void drawClothFast(MeshRenderable*, const Bounds3&) = 0;
  
  /** \brief Draw some VisualDebuggerData.
  */
  virtual void drawVisualDebugger(VisualDebuggerMeshData*) = 0;

  /** \brief Draw a Fluid
  */
  virtual void drawFluid(PhysXParticleData*, const Bounds3&) = 0;

  /** \brief Get the RenderableType.
  */
  int getType() const;
  
  protected:
  
   int mType;
  
}; // class Renderable

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
