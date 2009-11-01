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
#include "NxOgreMeshGenerator.h"
#include "NxOgreManualMesh.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

 
MeshGenerator::MeshGenerator()
{
 assert(0);
}

MeshGenerator::~MeshGenerator()
{
 assert(0);
}

bool MeshGenerator::makePlane(const Vec2& size, float density, Enums::MeshType type, const Path& path, const String& mesh_name)
{
 
 const int numX = (int) (size.x / density) + 1;
 const int numY = (int) (size.y / density) + 1;
 
 const int nbVertices = (numX + 1) * (numY + 1);
 const int nbTriangles = numX * numY * 2;
 
 ManualMesh mesh;
 
 mesh.begin(type, nbVertices, nbTriangles);
 
 int i, j, i0, i1, i2, i3;
 
 // Vertices
 for (i = 0; i <= numY; i++)
  for (j = 0; j <= numX; j++)
   mesh.vertex(density * j, 0, density * i);
 
 // Triangles
 for (i = 0; i <= numY; i++)
  for (j = 0; j <= numX; j++)
  {
   i0 = i * (numX + 1) + j;
   i1 = i0 + 1;
   i2 = i0 + (numX + 1);
   i3 = i2 + 1;
   
   if ( (j+1) % 2)
   {
    mesh.triangle(i0, i2, i1);
    mesh.triangle(i1, i2, i3);
   }
   else
   {
    mesh.triangle(i0, i2, i3);
    mesh.triangle(i0, i3, i1);
   }
  }
 
 Mesh* cooked_mesh = mesh.end(true, path);
 
 return cooked_mesh;
}

// This function was rewritten from this excellent article from the OGRE3D.org website.
// http://www.ogre3d.org/wiki/index.php/GeneratingAMesh

Mesh* MeshGenerator::makeBox(const Vec3& size, Enums::MeshType type, const Path& path, const String& mesh_name)
{
 
 const float N = 0.577350269f; // sqrt(1/3)
 const float n = -N;
 const Vec3 R = size * 0.5;
 const Vec3 r = -R;
 
 ManualMesh mesh;
 mesh.begin(type, 8, 12);

 // 8 verts.
 mesh.vertex(r.x, R.y, r.y); // 0
 mesh.vertex(R.x, R.y, r.y); // 1
 mesh.vertex(R.x, r.y, r.y); // 2
 mesh.vertex(r.x, r.y, r.y); // 3
 mesh.vertex(r.x, R.y, R.y); // 4
 mesh.vertex(R.x, R.y, R.y); // 5
 mesh.vertex(R.x, r.y, R.y); // 6
 mesh.vertex(r.x, r.y, R.y); // 7
 
 // 8 normals.
 mesh.normal(n, N, n); // 0
 mesh.normal(N, N, n); // 1
 mesh.normal(N, n, n); // 2
 mesh.normal(n, n, n); // 3
 mesh.normal(n, N, N); // 4
 mesh.normal(N, N, N); // 5
 mesh.normal(N, n, N); // 6
 mesh.normal(n, n, N); // 7

 // 12 triangles.
 mesh.triangle(0, 2, 3); // 0
 mesh.triangle(0, 1, 2); // 1
 mesh.triangle(1, 6, 2); // 2
 mesh.triangle(1, 5, 6); // 3
 mesh.triangle(4, 6, 5); // 4
 mesh.triangle(4, 7, 6); // 5
 mesh.triangle(0, 7, 4); // 6
 mesh.triangle(0, 3, 7); // 7
 mesh.triangle(0, 5, 1); // 8
 mesh.triangle(0, 4, 5); // 9
 mesh.triangle(2, 7, 3); // 10
 mesh.triangle(2, 6, 7); // 11
 mesh.name(mesh_name);
 
 Mesh* cooked_mesh = mesh.end(true, path);
 
 return cooked_mesh;
}

                                                                                       

} // namespace NxOgre

                                                                                       
