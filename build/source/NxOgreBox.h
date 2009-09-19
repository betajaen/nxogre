/** File: NxOgreBox.h
    Created on: 15-Mar-09
    Author: Robin Southern "betajaen"
    

    © Copyright, 2008-2009 by Robin Southern, http://www.nxogre.org

    This file is part of NxOgre.

    NxOgre is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    NxOgre is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with NxOgre.  If not, see <http://www.gnu.org/licenses/>.
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
