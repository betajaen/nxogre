/** File: NxOgreSphere.h
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

#ifndef NXOGRE_SPHERE_H
#define NXOGRE_SPHERE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgrePointerClass.h"
#include "NxOgreShape.h"
#include "NxOgreShapeBlueprint.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief  
*/ 
class NxOgrePublicClass Sphere : public PointerClass<Classes::_Sphere>, public Shape
{
  
  friend class RigidBodyPrototype;
  
  public: // Functions
  
  using ::NxOgre::PointerClass<Classes::_Sphere>::operator new;

  using ::NxOgre::PointerClass<Classes::_Sphere>::operator delete;

  using ::NxOgre::PointerClass<Classes::_Sphere>::getClassType;

  /** \brief Sphere
  */
                                              Sphere(Real radius, ShapeBlueprint* blueprint = new ShapeBlueprint());
  
  /** \brief Sphere
  */
                                             ~Sphere(void);

  /** \brief Get the shape type based upon the Classes::xxxx enum.
  */
                  Enums::ShapeFunctionType    getShapeFunctionType() const;
  
  protected:
  
  /** \internal DO NOT USE.
  */
                      NxShapeDesc*            create();

  /** \internal DO NOT USE.
  */
                      void                    assign(NxShape*);

  protected:

                      NxSphereShape*          mSphereShape;
}; // class Sphere

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
