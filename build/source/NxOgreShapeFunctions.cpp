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
#include "NxOgreCommon.h"
#include "NxOgreShapeFunctions.h"

#include "NxOgreShape.h"
#include "NxOgreBox.h"
#include "NxOgreCapsule.h"
#include "NxOgreConvex.h"
#include "NxOgreHeightFieldGeometry.h"
#include "NxOgrePlaneGeometry.h"
#include "NxOgreSphere.h"
#include "NxOgreTriangleGeometry.h"
#include "NxOgreWheel.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Functions
{

                                                                                       

namespace ShapeFunctions
{

                                                                                       

Shape* createNull(NxShape* shape)
{
 return 0;
}

Shape* createPlane(NxShape* shape)
{
 return NXOGRE_NEW_NXOGRE PlaneGeometry(shape->isPlane());
}

Shape* createBox(NxShape* shape)
{
 return NXOGRE_NEW_NXOGRE Box(shape->isBox());
}

Shape* createCapsule(NxShape* shape)
{
 return NXOGRE_NEW_NXOGRE Capsule(shape->isCapsule());
}

Shape* createSphere(NxShape* shape)
{
 return NXOGRE_NEW_NXOGRE Sphere(shape->isSphere());
}

Shape* createWheel(NxShape* shape)
{
 return NXOGRE_NEW_NXOGRE Wheel(shape->isWheel());
}

Shape* createConvex(NxShape* shape)
{
 return NXOGRE_NEW_NXOGRE Convex(shape->isConvexMesh(), static_cast<Mesh*>(shape->userData));
}

Shape* createHeightField(NxShape* shape)
{
 return NXOGRE_NEW_NXOGRE HeightFieldGeometry(shape->isHeightField(), static_cast<HeightField*>(shape->userData));
}

Shape* createTriangleMesh(NxShape* shape)
{
 return NXOGRE_NEW_NXOGRE TriangleGeometry(shape->isTriangleMesh(), static_cast<Mesh*>(shape->userData));
}

typedef Shape* (*ShapeFunction)(NxShape*);

ShapeFunction mFunctions[NX_SHAPE_COUNT];

struct ShapeBinder
{
 
 ShapeBinder()
 {
  mFunctions[NX_SHAPE_PLANE]       = &createPlane;
  mFunctions[NX_SHAPE_SPHERE]      = &createSphere;
  mFunctions[NX_SHAPE_BOX]         = &createBox;
  mFunctions[NX_SHAPE_CAPSULE]     = &createCapsule;
  mFunctions[NX_SHAPE_WHEEL]       = &createWheel;
  mFunctions[NX_SHAPE_CONVEX]      = &createConvex;
  mFunctions[NX_SHAPE_HEIGHTFIELD] = &createHeightField;
  mFunctions[NX_SHAPE_MESH]        = &createTriangleMesh;
  mFunctions[NX_SHAPE_RAW_MESH]    = &createNull;
  mFunctions[NX_SHAPE_COMPOUND]    = &createNull;
 }
 
} gShapeBinder;


Shape* createShape(NxShape* physx_shape, RigidBody* rigid_body)
{
 Shape* shape = mFunctions[int(physx_shape->getType())] (physx_shape);
 shape->setId((int) physx_shape->userData);
 physx_shape->userData = NXOGRE_NEW_NXOGRE PhysXPointer(shape, shape->getShapeType(), rigid_body);
 return shape;
}

void NxOgrePublicFunction NxShapeArrayToBuffer(NxShape* nx_shape, unsigned int nb_nx_shapes, Buffer<Shape*>& shapes)
{
 while(nb_nx_shapes--)
  shapes.append(pointer_representive_cast<Shape>(nx_shape[nb_nx_shapes].userData));
}

                                                                                       

} // namespace Shape

                                                                                       

} // namespace Functions

                                                                                       

} // namespace NxOgre

                                                                                       
