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

                                                                                       

#ifndef NXOGRE_POINTRENDERABLE_H
#define NXOGRE_POINTRENDERABLE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief A point renderable is intended to represent a pre-load visual mesh in a SceneGraph or similar rendering API. Instead
           of giving full vertex and triangle information. A PointRenderable only gives the global position and orientation
           of a single point (e.x. the center of the physics object) for the RenderSystem to transform the visual mesh to.
    \warning DO NOT CREATE THIS CLASS MANUALLY. Use a RenderSystem implementation of this class instead.
*/
class NxOgrePublicClass PointRenderable
{
  
  public: // Functions
  
  /** \brief Required virtual destructor.
  */
  virtual                                    ~PointRenderable();
  
  /** \brief Transform the visual mesh according the global position and orientation (as a quaternion).
  */
  virtual void                                render(const Vec3&, const Quat&) = 0;
  
  
}; // class PointRenderable

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
