/** File: NxOgreSphere.cpp
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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreSphere.h"
#include "NxOgreShapeBlueprint.h"
#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Sphere::Sphere(Real radius, ShapeBlueprint* blueprint)
: Shape(blueprint)
{
 mBlueprint->mSize.x = radius;
}

Sphere::~Sphere(void)
{
}

NxShapeDesc* Sphere::create(void)
{
 NxSphereShapeDesc* sphere = new NxSphereShapeDesc();
 createAbstract(sphere);

 sphere->radius = mBlueprint->mSize.x;
 return sphere;
}

void Sphere::assign(NxShape* sphere)
{
 assignAbstract(sphere);
 mSphereShape = sphere->isSphere();
}

Enums::ShapeFunctionType Sphere::getShapeFunctionType() const
{
 return Enums::ShapeFunctionType_Sphere;
}

                                                                                       

} // namespace NxOgre

                                                                                       
