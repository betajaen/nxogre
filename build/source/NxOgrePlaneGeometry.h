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

#include "NxOgrePointerClass.h"
#include "NxOgreShape.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief  
*/ 
class NxOgrePublicClass PlaneGeometry : public PointerClass<Classes::_PlaneGeometry>, public Shape
{
  
  friend class RigidBodyPrototype;
  
  public: // Functions
  
  using ::NxOgre::PointerClass<Classes::_PlaneGeometry>::operator new;

  using ::NxOgre::PointerClass<Classes::_PlaneGeometry>::operator delete;

  using ::NxOgre::PointerClass<Classes::_PlaneGeometry>::getClassType;

  /** \brief PlaneGeometry
  */
                                              PlaneGeometry(Real distance, Vec3 normal);
  
  /** \brief PlaneGeometry
  */
                                             ~PlaneGeometry(void);

  /** \brief Get the shape type based upon the Classes::xxxx enum.
  */
               Enums::ShapeFunctionType       getShapeFunctionType() const;
  
  
  protected:
  
  /** \internal DO NOT USE.
  */
                      NxShapeDesc*            create();
  
  /** \internal DO NOT USE.
  */
                      void                    assign(NxShape*);
  
  /** \internal
  */
                      NxPlaneShape*           mPlaneShape;
}; // class PlaneGeometry

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
