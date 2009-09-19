/** File: NxOgreMeshStats.cpp
    Created on: 1-Jun-09
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

unsigned int MeshStats::getNbVertices(void) const
{
 return mNbVertices;
}

unsigned int MeshStats::getNbIndices(void) const
{
 return mNbIndices;
}

unsigned int MeshStats::getNbParentIndices(void) const
{
 return mNbParentIndices;
}

unsigned int MeshStats::getNbTextureCoords(void) const
{
 return mNbTextureCoords;
}

unsigned int MeshStats::getNbTetrahedra(void) const
{
 return mNbTetrahedra;
}


                                                                                       

} // namespace NxOgre

                                                                                       
