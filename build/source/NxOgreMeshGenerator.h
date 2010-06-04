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

                                                                                       

#ifndef NXOGRE_MESHGENERATOR_H
#define NXOGRE_MESHGENERATOR_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief  
*/ 
class NxOgrePublicClass MeshGenerator
{
  
 public:
  
  
  /*. function. makePlane
      desc.
           Create a plane mesh based on size as load it into the ResourceSysetm as mesh_name
      args.
          size -- Size of the plane
          density -- Number of vertices per row/column
          type -- Type of mesh
          saveTo -- Path to save to, default: MEMORY_PATH
          mesh_name -- mesh_name, default: BLANK_STRING (No mesh name)
     note.
         If the mesh type is cloth, then the appropriate texture coordinates will be generated too.
  */
  static Mesh* makePlane(const Vec2& size, float density, Enums::MeshType, const Path& saveTo = MEMORY_PATH, const String& mesh_name = BLANK_STRING);
  
  
  /** \brief Create box mesh based on size as load it into the ResourceSystem as mesh_name
      \param size      Size of the box
      \param type      Type of mesh
      \param saveTo    Path to save to, default: MEMORY_PATH
      \param mesh_name mesh_name, default: BLANK_STRING (No mesh name)
  */
  static Mesh*  makeBox(const Vec3& size, Enums::MeshType type, const Path& saveTo = MEMORY_PATH, const String& mesh_name = BLANK_STRING);
  
 private:
  
  /** \internal DO NOT USE
  */
  MeshGenerator();
  
  /** \internal DO NOT USE
  */
 ~MeshGenerator();
  
}; // class MeshGenerator

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
