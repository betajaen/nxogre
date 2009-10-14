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

#include "NxOgrePointerClass.h"
#include "NxOgreShape.h"
#include "NxOgreShapeBlueprint.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. Box
    desc.
        A Box is a cubiod shape that can be used in Actors, KinematicActors, StaticGeometries and Volumes for
        collisions and testing against them.
        
    see. Shape
*/ 
class NxOgrePublicClass Box : public PointerClass<Classes::_Box>, public Shape
{
  
  friend class RigidBodyPrototype;
  
  public: // Functions
  
  using ::NxOgre::PointerClass<Classes::_Box>::operator new;

  using ::NxOgre::PointerClass<Classes::_Box>::operator delete;

  using ::NxOgre::PointerClass<Classes::_Box>::getClassType;

  /*! constructor. Box
      desc.
           Box constructor with width, height, depth size argument as a Vec3.
      note.
           The Box class's dimensions are full diameter of the box, and not the radius as it is in PhysX.
      args.
           const Vec3& __dimensions__ -- Dimensions of the Box.
           ShapeBlueprint* __blueprint__ -- Blueprint of the Shape.
  */
  Box(const Vec3& dimensions, ShapeBlueprint* blueprint = new ShapeBlueprint());
  
  /*! constructor. Box
      desc.
           Box constructor with width, height, depth size argument as seperate Real components
      note.
           The Box class's dimensions are full diameter of the box, and not the radius as it is in PhysX.
      args.
           Real __x__ -- X/Width dimension of the Box.
           Real __y__ -- Y/Height dimension of the Box.
           Real __z__ -- Z/Depth dimension of the Box.
           ShapeBlueprint* __blueprint__ -- Blueprint of the Shape.
  */
  Box(Real w, Real h, Real d, ShapeBlueprint* blueprint = new ShapeBlueprint());
  
  /*! constructor. Box
      desc.
           Box constructor with width, height, depth size argument as a single Real component.
      note.
           The Box class's dimensions are full diameter of the box, and not the radius as it is in PhysX.
      args.
           Real __whd__ -- Width, Height and Depth size of the Box.
           ShapeBlueprint* __blueprint__ -- Blueprint of the Shape.
  */
  Box(Real whd, ShapeBlueprint* blueprint = new ShapeBlueprint());
  
  
  /*! destructor. Box
      desc.
           As with all Shapes, deleting the Box should be left to the class that is responsible for it.
      note.
           Deleting the Box whilst it is attached to a RigidBody will probably cause a nasty crash.
  */
 ~Box(void);

  /*! function. getShapeFunctionType
      desc.
           Get the shape type based upon the Classes::ShapeFunctionType enum.
      return.
           **ShapeFunctionType** -- This type of shape as a ShapeFunctionType enum.
  */
  Enums::ShapeFunctionType            getShapeFunctionType() const;
  
  /*! function. getSize
      desc.
           Get the size of the box
      return.
           **Vec3** -- The size of the box.
  */
  Vec3                    getSize() const;
  
  /*! function. setSize
      desc.
           Set the size of the shape
      args.
           const Vec3& __size__ -- New size of the box.
  */
  void                    setSize(const Vec3& size);
  

  /*! function. setSize
      desc.
           Set the size of the shape from seperate Real components.
      args.
           Real __w__ -- New width of the box.
           Real __h__ -- New height of the box.
           Real __d__ -- New depth of the box.
  */
  void                    setSize(Real w, Real h, Real d);

  /*! function. getWorldOBB
      desc.
           Get the box represented as world space OBB.
      note.
           This function only works when the box is attached.
      return. **SimpleBox** -- World space OBB when attached or SimpleBox with default values.
  */
                      SimpleBox               getWorldOBB(void);
  
  protected:
  
  /* Create a NxShapeDesc (NxBoxDesc) of the current Box's configuration.
  */
                      NxShapeDesc*            create();
  
  /* Set the box to a NxShape
  */
                      void                    assign(NxShape*);
  
  protected:
  
                      NxBoxShape*             mBoxShape;
  
}; // class Box

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
