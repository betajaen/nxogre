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

                                                                                       

#ifndef NXOGRE_PHYSXMESHDATA_H
#define NXOGRE_PHYSXMESHDATA_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"


                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass PhysXMeshData : public GenericBasedAllocatable
{
  
  public: // Functions
  
  /** \brief Text
  */
                                              PhysXMeshData(Mesh*, size_t modifier = 2);
  
  /** \brief Text
  */
                                             ~PhysXMeshData(void);
  
  /** \internal Do not use in User App.
  */
                     NxMeshData               getMeshData();
  
  /** \brief Get the vertices as three floats. Use getNbVertices() as a count. Vertices size will be 3 * getNbVertices().
  */
                     float*                   getVertices();
  
  /** \brief Get the vertices as three floats. Use getNbVertices() as a count. Normals size will be 3 * getNbVertices().
  */                 
                     float*                   getNormals();
  
  /** \brief Get the indexes as 32 bit integers. Use getNbIndices() as a count.
  */                 
                     unsigned int*            getIndices();
  
  /** \brief Get the current number of vertices, normals and texture coordinates.
  */
                     unsigned int             getNbVertices();
   
  /** \brief Get the current indices
  */
                     unsigned int             getNbIndices();
   
  /** \brief Get the current parent indices
  */
                     unsigned int             getNbParentIndices();
  
  protected:

                     void                     _configure(size_t verts, size_t indices, size_t parent_indices);
  
                     Buffer<float>            mVertices;
  
                     Buffer<float>            mNormals;
  
                     Buffer<unsigned int>     mIndices;
  
                     Buffer<unsigned int>     mParentIndices;
  
                     unsigned int*            mNbVertices;
  
                     unsigned int*            mNbIndices;
  
                     unsigned int*            mNbParentIndices;
  
}; // class PhysXMeshData


                                                                                       

} // namespace NxOgre

                                                                                       

#endif
