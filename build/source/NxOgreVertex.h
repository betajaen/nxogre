/** File: NxOgreVertex.h
    Created on: 6-Dec-08
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

#ifndef NXOGRE_VERTEX_H
#define NXOGRE_VERTEX_H

                                                                                       

#include "NxOgreStable.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief A vertex is a single point in space made from two coordinates.
*/
struct NxOgrePublicClass Vertex2
{
  float x, y;
}; // class ClassName


/** \brief A vertex is a single point in space made from three coordinates.
*/
struct NxOgrePublicClass Vertex3
{
  float x, y, z;
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
