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

                                                                                       

/** \brief  
*/ 
class NxOgrePublicClass Box : public PointerClass<Classes::_Box>, public Shape
{
  
  friend class RigidBodyPrototype;
  
  public: // Functions
  
  using ::NxOgre::PointerClass<Classes::_Box>::operator new;

  using ::NxOgre::PointerClass<Classes::_Box>::operator delete;

  using ::NxOgre::PointerClass<Classes::_Box>::getClassType;

  /** \brief Box constructor with width, height, depth size argument as a Vec3.
      \note  The Box class's dimensions are full diameter of the box, and not the radius
             as it is in PhysX.
  */
                                              Box(const Vec3& dimensions, ShapeBlueprint* box_blueprint = new ShapeBlueprint());
  
  /** \brief Box constructor with width, height, depth size argument as seperate float components..
      \note  The Box class's dimensions are full diameter of the box, and not the radius
             as it is in PhysX.
  */
                                              Box(Real w, Real h, Real d, ShapeBlueprint* blueprint = new ShapeBlueprint());
  
  /** \brief Box constructor with width, height, depth size argument as a single float component.
      \note  The Box class's dimensions are full diameter of the box, and not the radius
             as it is in PhysX.
  */
                                              Box(Real whd_dimensions, ShapeBlueprint* box_blueprint = new ShapeBlueprint());
  
  /** \brief Box destructor. 
      \warning Deleting the Box whilst it is attached to a shape will probably cause a nasty crash.
  */
                                             ~Box(void);

  /** \brief Get the shape type based upon the Classes::xxxx enum.
  */
          Enums::ShapeFunctionType            getShapeFunctionType() const;
  
  /** \brief Get the size of the shape
  */
                      Vec3                    getSize() const;
  
  /** \brief Set the size of the shape
  */
                      void                    setSize(const Vec3&);
  

  /** \brief Set the size of the shape
  */
                      void                    setSize(float w, float h, float d);

  /** \brief Get the box represented as world space OBB.
      \note This function only works when the box is attached.
  */
                      SimpleBox               getWorldOBB(void);
  
  protected:
  
  /** \internal DO NOT USE.
  */
                      NxShapeDesc*            create();
  
  /** \internal DO NOT USE.
  */
                      void                    assign(NxShape*);
  
  protected:
  
                      NxBoxShape*             mBoxShape;
  
}; // class Box

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
