/** File: NxOgreConvex.cpp
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
#include "NxOgreConvex.h"
#include "NxOgreMesh.h"
#include "NxOgreShapeBlueprint.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Convex::Convex(Mesh* mesh, ShapeBlueprint* blueprint)
: Shape(blueprint)
{
 mBlueprint->mMesh = mesh;
}

Convex::~Convex(void)
{
}

Mesh* Convex::getMesh(void)
{
 if (mBlueprint)
  return mBlueprint->mMesh;
 return mMesh;
}

NxShapeDesc* Convex::create()
{
 NxConvexShapeDesc* convex = new NxConvexShapeDesc();
 Shape::createAbstract(convex);
 
 convex->meshData = mBlueprint->mMesh->getAsConvex();
 convex->meshFlags = mBlueprint->mMeshFlags;
 
 return convex;
}

void Convex::assign(NxShape* convex)
{
 assignAbstract(convex);
 mMesh = mBlueprint->mMesh;
 mConvexShape = convex->isConvexMesh();
}

Enums::ShapeFunctionType Convex::getShapeFunctionType() const
{
 return Enums::ShapeFunctionType_Convex;
}

                                                                                       

} // namespace NxOgre

                                                                                       
