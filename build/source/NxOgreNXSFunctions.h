/** File: NxOgreNXSFunctions.h
    Created on: 28-Feb-09
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

#ifndef NXOGRE_NXSFUNCTIONS_H
#define NXOGRE_NXSFUNCTIONS_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Functions
{

                                                                                       

namespace NXSFunctions
{

                                                                                       

/** \brief Is the resource a PhysX NXS file.
    \note Resource cannot be sucessional.
*/
inline bool isNXS(Resource*);

/** \brief Get the type of resource or Enums::MeshType_Unknown of a PhysX NXS file.
    \note Resource cannot be sucessional, it is assumed that the mesh has been run through the isNXS function.
*/
inline Enums::MeshType getMeshType(Resource*);

/// /** \brief Does the PhysX NXS file have NxOgre extended data attached to it?
///     \note Resource cannot be sucessional.
/// */
/// inline bool hasExtendedMeshData(Resource*);
/// 
/// /** \brief Get the extended data from a NXS file.
///     \note Resource cannot be sucessional.
/// */
/// inline void* getExtendedMeshData(Resource*, size_t& dataLength);

                                                                                       

}

                                                                                       

}

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
