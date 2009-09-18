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

                                                                                       
