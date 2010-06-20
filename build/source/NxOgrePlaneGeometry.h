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

                                                                                       

#ifndef NXOGRE_PLANEGEOMETRY_H
#define NXOGRE_PLANEGEOMETRY_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"


#include "NxOgreShape.h"
#include "NxOgreShapeFunctions.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief  
*/ 
class NxOgrePublicClass PlaneGeometry : public Shape
{
  
  friend class RigidBody;  // for destroy();
  friend Shape* Functions::ShapeFunctions::createPlane(NxShape*); // for new
  
  NXOGRE_GC_FRIEND_NEW2
  NXOGRE_GC_FRIEND_DELETE
  
  public: // Functions
  
  /*! function. getShapeFunctionType
      desc.
           Get the shape type based upon the Classes::ShapeFunctionType enum.
      return.
           **ShapeFunctionType** -- This type of shape as a ShapeFunctionType enum.
  */
  Enums::ShapeFunctionType       getShapeFunctionType() const;
  
  /** \brief Get the shape type based upon the Classes::xxxx enum.
  */
  unsigned int getShapeType() const;
  
  /*! function. saveToDescription
      desc.
          Save to a PlaneGeometryDescription
  */
  void saveToDescription(PlaneGeometryDescription& description);
  
  protected:
  
  /* constructor. PlaneGeometry
  */
  PlaneGeometry(NxPlaneShape*, bool isDirty = false);
  
  /* destructor. PlaneGeometry
  */
 ~PlaneGeometry();
  
  /** \internal
  */
  NxPlaneShape*           mPlaneShape;

}; // class PlaneGeometry

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
