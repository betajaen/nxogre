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

                                                                                       

#ifndef NXOGRE_SHAPEFUNCTIONS_H
#define NXOGRE_SHAPEFUNCTIONS_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Functions
{

                                                                                       

/*! namespace. Functions_ShapeFunctions
    Internal helper functions to create NxOgre shapes based of PhysX ones. User's app should
    never need to use these.
*/
namespace ShapeFunctions
{

                                                                                       

/*! function. createShape
    desc.
        Master function that calls create__ShapeName__ based of it's internal PhysX type value, this
        function should be used directly instead of calling a specific shape function.
        
        Once the Shape has been created the userData value of the NxShape will be replaced with a PhysXPointer.
    note.
        Some mesh based shapes expect the userData property to contain the pointer to the Mesh or HeightField
        associated with that shape, this of course will be replaced by a PhysXPointer.
*/
Shape* createShape(NxShape*, RigidBody*);

/*! function. createDirtyShape
    desc.
        Master function that calls create __ShapeName__ based of it's internal PhysX type value, this
        function should be used directly instead of calling a specific shape function.
        
    note.
        This function is used to bind to NxShapes that have been created outside NxOgre, for this reason
        they are marked "dirty". The userdata is not filled thus the binding is an one-way relationship.
*/
Shape* createDirtyShape(NxShape*, RigidBody*);

/* For unknown or internal shapes.
*/
inline Shape* createNull(NxShape*);

/* NxPlaneShape to PlaneGeometry.
*/
inline Shape* createPlane(NxShape*);

/* NxBoxShape to Box.
*/
inline Shape* createBox(NxShape*);

/* NxSphereShape to Sphere.
*/
inline Shape* createSphere(NxShape*);

/* NxCapsuleShape to Capsule.
*/
inline Shape* createCapsule(NxShape*);

/* NxWheelShape to Wheel.
*/
inline Shape* createWheel(NxShape*);

/* NxConvexShape to Convex.
   Note: userData property of NxConvexShape must contain the pointer to the NxOgre Mesh, representing the NxConvexMesh.
*/
inline Shape* createConvex(NxShape*);

/* NxTriangleMeshShape to TriangleGeometry.
   Note: userData property of NxConvexShape must contain the pointer to the NxOgre Mesh, representing the NxConvexMesh.
*/
inline Shape* createHeightField(NxShape*);

/* NxTriangleMeshShape to TriangleGeometry.
   Note: userData property of NxConvexShape must contain the pointer to the NxOgre Mesh, representing the NxConvexMesh.
*/
inline Shape* createTriangleMesh(NxShape*);

void NxOgrePublicFunction NxShapeArrayToBuffer(NxShape*, unsigned int nb_nx_shapes, buffer<Shape*>&);

                                                                                       

} // namespace Shape

                                                                                       

} // namespace Functions

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
