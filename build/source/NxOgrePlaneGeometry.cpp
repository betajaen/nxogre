/** File: NxOgrePlaneGeometry.cpp
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
#include "NxOgrePlaneGeometry.h"
#include "NxOgreShapeBlueprint.h"
#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

PlaneGeometry::PlaneGeometry(Real distance, Vec3 normal)
: Shape(new ShapeBlueprint())
{
 mBlueprint->mSize.w = distance;
 mBlueprint->mSize.x = normal.x;
 mBlueprint->mSize.y = normal.y;
 mBlueprint->mSize.z = normal.z;
}

PlaneGeometry::~PlaneGeometry(void)
{
}

NxShapeDesc* PlaneGeometry::create()
{
 NxPlaneShapeDesc* plane = new NxPlaneShapeDesc();
 
 createAbstract(plane);
 
 plane->d = mBlueprint->mSize.w;
 plane->normal.x = mBlueprint->mSize.x;
 plane->normal.y = mBlueprint->mSize.y;
 plane->normal.z = mBlueprint->mSize.z;
 
 return plane;
}

void PlaneGeometry::assign(NxShape* plane)
{
 assignAbstract(plane);
 mPlaneShape = plane->isPlane();
}

Enums::ShapeFunctionType PlaneGeometry::getShapeFunctionType() const
{
 return Enums::ShapeFunctionType_Plane;
}

                                                                                       

} // namespace NxOgre

                                                                                       
