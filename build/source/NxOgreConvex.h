/** File: NxOgreConvex.h
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

#ifndef NXOGRE_CONVEX_H
#define NXOGRE_CONVEX_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgrePointerClass.h"
#include "NxOgreShape.h"
#include "NxOgreShapeBlueprint.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief  
*/ 
class NxOgrePublicClass Convex : public PointerClass<Classes::_Convex>, public Shape
{
  
  friend class RigidBodyPrototype;
  
  public: // Functions
  
  using ::NxOgre::PointerClass<Classes::_Convex>::operator new;

  using ::NxOgre::PointerClass<Classes::_Convex>::operator delete;

  using ::NxOgre::PointerClass<Classes::_Convex>::getClassType;

  /** \brief Convex
  */
                                              Convex(Mesh*, ShapeBlueprint* box_blueprint = new ShapeBlueprint());
  
  /** \brief Convex
  */
                                             ~Convex(void);

  /** \brief Get the shape type based upon the Classes::xxxx enum.
  */
                   Enums::ShapeFunctionType   getShapeFunctionType() const;
  
  /** \brief Get the mesh currently used by this Convex shape
  */ 
                      Mesh*                   getMesh(void);
  
  protected:
  
  /** \internal DO NOT USE.
  */
                      NxShapeDesc*            create();

  /** \internal DO NOT USE.
  */
                      void                    assign(NxShape*);

  protected:

                      NxConvexShape*          mConvexShape;

                      Mesh*                   mMesh;
  
}; // class Convex

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
