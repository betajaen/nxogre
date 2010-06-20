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

                                                                                       

#ifndef NXOGRE_SPHERE_H
#define NXOGRE_SPHERE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgreShape.h"
#include "NxOgreShapeDescription.h"
#include "NxOgreShapeFunctions.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. Sphere
*/ 
class NxOgrePublicClass Sphere : public Shape
{
  
  NXOGRE_GC_FRIEND_NEW2
  NXOGRE_GC_FRIEND_DELETE
  
  public: // Functions

  /*! function. getShapeFunctionType
      desc.
          Get the shape type based upon the Classes::xxxx enum.
  */
  Enums::ShapeFunctionType  getShapeFunctionType() const;
  
  /*! function. getShapeType
      desc.
          Get the shape type based upon the Classes::xxxx enum.
  */
  unsigned int getShapeType() const;
  
  /*! function. getShapeType
      desc.
          Get the sphere radius.
  */
   void setRadius(Real radius);
  
  /*! function. getRadius
      desc.
          Get the sphere radius.
  */
  Real getRadius() const;
  
  /*! function. getWorldSphere
      desc.
          Get the shape type based upon the Classes::xxxx enum.
  */
  SimpleSphere getWorldSphere() const;
  
  /*! function. saveToDescription
      desc.
          Save to a SphereDescription
  */
  void saveToDescription(SphereDescription& description);
  
  protected:
  
  /** \brief Sphere
  */
  Sphere(NxSphereShape*, bool isDirty = false);
  
  /** \brief Sphere
  */
 ~Sphere();
  
  protected:

  NxSphereShape*          mSphereShape;
}; // class Sphere

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
