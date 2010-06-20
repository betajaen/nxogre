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

                                                                                       

#ifndef NXOGRE_CONVEX_H
#define NXOGRE_CONVEX_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"


#include "NxOgreShape.h"
#include "NxOgreShapeDescription.h"
#include "NxOgreShapeFunctions.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. Convex
    desc.
         A convex is a convex point cloud (with optional triangles) that is used from a Mesh file. 
         
         Convex shapes can be used in Actors, KinematicActors, StaticGeometries and Volumes for
         collisions and testing against them.
    see. Shape
*/
class NxOgrePublicClass Convex : public Shape
{
  
  
  NXOGRE_GC_FRIEND_NEW3
  NXOGRE_GC_FRIEND_DELETE
  
  public: // Functions

  unsigned int  getShapeType() const;

  /*! function. getShapeFunctionType
      desc.
           Get the shape type based upon the Classes::ShapeFunctionType enum.
      return.
           **ShapeFunctionType** -- This type of shape as a ShapeFunctionType enum.
  */
  Enums::ShapeFunctionType  getShapeFunctionType() const;
  
  /*! function. getMesh
      desc.
           Get the mesh
      note.
           MeshManager owns this pointer. Do not delete it.
      return.
           **Mesh** * -- The mesh shared by the Convex.
  */
  Mesh*  getMesh();
  
  /*! function. saveToDescription
      desc.
          Save to a ConvexDescription
  */
  void saveToDescription(ConvexDescription& description);
  
  /*! function. to_s
      desc.
          Returns the pointer and name as string.
  */
  String to_s() const;
  
  protected:
  
  /*
  */
  Convex(NxConvexShape*, Mesh*, bool isDirty = false);
  
  /*
  */
 ~Convex();
  
  protected:
  
  NxConvexShape*  mConvexShape;
  
  Mesh*  mMesh;
  
}; // class Convex

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
