/** File: NxOgreMeshStats.h
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

#ifndef NXOGRE_MESHSTATS_H
#define NXOGRE_MESHSTATS_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass MeshStats
{
 public:
   
   MeshStats();
   
   MeshStats(unsigned int nbVertices, unsigned int nbIndices = 0, unsigned int nbParentIndices = 0, unsigned int nbTextureCoords = 0, unsigned int nbTetrahedra = 0);
   
   unsigned int getNbVertices(void) const;
   
   unsigned int getNbIndices(void) const;
   
   unsigned int getNbParentIndices(void) const;
   
   unsigned int getNbTextureCoords(void) const;
   
   unsigned int getNbTetrahedra(void) const;

  protected:
   
   unsigned int mNbVertices;
   
   unsigned int mNbIndices;
   
   unsigned int mNbParentIndices;
   
   unsigned int mNbTextureCoords;
   
   unsigned int mNbTetrahedra;

}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
