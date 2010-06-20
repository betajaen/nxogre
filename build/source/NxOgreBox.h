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

                                                                                       

#ifndef NXOGRE_BOX_H
#define NXOGRE_BOX_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"


#include "NxOgreShape.h"
#include "NxOgreShapeDescription.h"
#include "NxOgreShapeFunctions.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. Box
    desc.
        A Box is a cubiod shape that can be used in Actors, KinematicActors, StaticGeometries and Volumes for
        collisions and testing against them.
        
    see. Shape
*/ 
class NxOgrePublicClass Box : public Shape
{
  
  NXOGRE_GC_FRIEND_NEW2
  NXOGRE_GC_FRIEND_DELETE
  
  public: // Functions
  
  unsigned int getShapeType() const;

  /*! function. getShapeFunctionType
      desc.
           Get the shape type based upon the Classes::ShapeFunctionType enum.
      return.
           **ShapeFunctionType** -- This type of shape as a ShapeFunctionType enum.
  */
  Enums::ShapeFunctionType  getShapeFunctionType() const;
  
  /*! function. getSize
      desc.
           Get the size of the box
      return.
           **Vec3** -- The size of the box.
  */
  Vec3  getSize() const;
  
  /*! function. setSize
      desc.
           Set the size of the shape
      args.
           const Vec3& __size__ -- New size of the box.
  */
  void  setSize(const Vec3& size);
  

  /*! function. setSize
      desc.
           Set the size of the shape from seperate Real components.
      args.
           Real __w__ -- New width of the box.
           Real __h__ -- New height of the box.
           Real __d__ -- New depth of the box.
  */
  void  setSize(Real w, Real h, Real d);

  /*! function. getWorldOBB
      desc.
           Get the box represented as world space OBB.
      return. **SimpleBox** -- World space OBB when attached or SimpleBox with default values.
  */
  SimpleBox  getWorldOBB();
  
  /*! function. saveToDescription
      desc.
          Save to a BoxDescription
  */
  void saveToDescription(BoxDescription& description);
    
  /*! function. to_s
      desc.
          Returns the pointer and name as string.
  */
  String to_s() const;
  
  protected:
  
  /* constructor. Box
  */
  Box(NxBoxShape*, bool isDirty = false);
  
  /* destructor. Box
  */
 ~Box();
  
  protected:
  
  /* A more specific version of the shape is kept to reduce the amount of casting required.
  */
  NxBoxShape*  mBoxShape;
  
}; // class Box

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
