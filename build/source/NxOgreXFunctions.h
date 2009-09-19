/** File: NxOgreXFunctions.h
    Created on: 18-Mar-09
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

#ifndef NXOGRE_XFUNCTIONS_H
#define NXOGRE_XFUNCTIONS_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Functions
{

                                                                                       

namespace XFunctions
{

                                                                                       

/** \brief Is the resource a NxOgre X-file.
    \note Resource cannot be sucessional.
*/
inline bool isX(Resource*);


/** \brief Is the resource a NxOgre X-file.
    \note Resource cannot be sucessional.
*/
inline SharedStringStream whyIsNotX(Resource*);


/** \brief Get the type of resource or Enums::MeshType_Unknown of a NxOgre X-file.
    \note Resource cannot be sucessional, it is assumed that the mesh has been run through the isNXS function.
*/
inline Enums::XType getXType(Resource*);

                                                                                       

}

                                                                                       

}

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
