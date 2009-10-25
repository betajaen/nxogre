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

unsigned int Convex::getShapeType() const
{
 return Classes::_Convex;
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

                                                                                       
