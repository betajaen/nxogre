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
#include "NxOgreMeshStats.h"

                                                                                       

namespace NxOgre
{

                                                                                       

MeshStats::MeshStats()
: mNbVertices(0),
  mNbIndices(0),
  mNbParentIndices(0),
  mNbTextureCoords(0),
  mNbTetrahedra(0)
{
}

MeshStats::MeshStats(unsigned int nbVertices, unsigned int nbIndices, unsigned int nbParentIndices, unsigned int nbTextureCoords, unsigned int nbTetrahedra)
: mNbVertices(nbVertices),
  mNbIndices(nbIndices),
  mNbParentIndices(nbParentIndices),
  mNbTextureCoords(nbTextureCoords),
  mNbTetrahedra(nbTetrahedra)
{
}

unsigned int MeshStats::getNbVertices() const
{
 return mNbVertices;
}

unsigned int MeshStats::getNbIndices() const
{
 return mNbIndices;
}

unsigned int MeshStats::getNbParentIndices() const
{
 return mNbParentIndices;
}

unsigned int MeshStats::getNbTextureCoords() const
{
 return mNbTextureCoords;
}

unsigned int MeshStats::getNbTetrahedra() const
{
 return mNbTetrahedra;
}

void MeshStats::clear()
{
 mNbVertices = 0;
 mNbIndices = 0;
 mNbParentIndices = 0;
 mNbTextureCoords = 0;
 mNbTetrahedra = 0;
}

                                                                                       

} // namespace NxOgre

                                                                                       
