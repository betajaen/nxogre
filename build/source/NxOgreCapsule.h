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

                                                                                       

#ifndef NXOGRE_CAPSULE_H
#define NXOGRE_CAPSULE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgrePointerClass.h"
#include "NxOgreShape.h"
#include "NxOgreShapeBlueprint.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. Capsule
    desc.
        A Capsule is a capsule shape that can be used in Actors, KinematicActors, StaticGeometries and Volumes for
        collisions and testing against them.
        
    see. Shape
*/ 
class NxOgrePublicClass Capsule : public PointerClass<Classes::_Capsule>, public Shape
{
  
  friend class RigidBodyPrototype;
  
  public: // Functions
  
  using ::NxOgre::PointerClass<Classes::_Capsule>::operator new;

  using ::NxOgre::PointerClass<Classes::_Capsule>::operator delete;

  using ::NxOgre::PointerClass<Classes::_Capsule>::getClassType;

  /*! constructor. Capsule
      desc.
           Capsule constructor with radius and height.
      note.
           The absolute height of the capsule is; @height + 2(radius)@.
      args.
           Real __radius__ -- Radius of the capsule
           Real __height__ -- Distance between the top and bottom hemispheres of the capsule.
           ShapeBlueprint* __blueprint__ -- Blueprint of the Shape.
  */
  Capsule(Real radius, Real height, ShapeBlueprint* box_blueprint = new ShapeBlueprint());
  
  /*! destructor. Capsule
      desc.
           As with all Shapes, deleting the Capsule should be left to the class that is responsible for it.
      note.
           Deleting the Box whilst it is attached to a shape will probably cause a nasty crash.
  */
  ~Capsule(void);
  
  /*! function. getShapeFunctionType
      desc.
           Get the shape type based upon the Classes::ShapeFunctionType enum.
      return.
           **ShapeFunctionType** -- This type of shape as a ShapeFunctionType enum.
  */
  Enums::ShapeFunctionType            getShapeFunctionType() const;
  
  /*! function. setDimensions
      desc.
           Set the radius and height of the capsule.
      args.
           Real __radius__ -- Radius of the capsule
           Real __height__ -- Distance between the top and bottom hemispheres of the capsule.
  */
  void                    setDimensions(Real radius, Real height);
  
  /*! function. setRadius
      desc.
           Set the radius of the capsule.
      args.
           Real __radius__ -- Radius of the capsule
  */
  void                    setRadius(Real radius);
  
  /*! function. setHeight
      desc.
           Set the height of the capsule.
      args.
           Real __height__ -- Distance between the top and bottom hemispheres of the capsule.
  */
  void                    setHeight(Real height);
  
  /*! function. getRadius
      desc.
           Get the radius of the capsule
      return.
           **Real** -- The radius of the capsule.
  */
  Real                    getRadius(void) const;
  
  /*! function. getHeight
      desc.
           Get the height of the capsule
      return.
           **Real** -- Distance between the top and bottom hemispheres of the capsule.
  */
  Real                    getHeight(void) const;
  
  /*! function. getWorldCapsule
      desc.
           Get the box represented as world space capsule.
      note.
           This function only works when the capsule is attached.
      return. **SimpleCapsule** -- World space capsule when attached or SimpleCapsule with default values.
  */
  SimpleCapsule           getWorldCapsule(void);

  protected:
  
  /* Create a NxShapeDesc (NxCapsuleDesc) of the current Capsule's configuration.
  */
                      NxShapeDesc*            create();

  /* Set the capsule to a NxShape
  */
                      void                    assign(NxShape*);

  protected:

                      NxCapsuleShape*         mCapsuleShape;

}; // class Capsule

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
