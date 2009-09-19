/** File: NxOgreFunctions.h
    Created on: 4-Nov-08
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

#ifndef NXOGRE_FUNCTIONS_H
#define NXOGRE_FUNCTIONS_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Functions
{

                                                                                       

/** \brief Just like strlen
*/
unsigned int getCStringLength(const char*);

/** \brief Convert any vector3 class to another, assuming both classes have public member variables x y z
*/
template<typename from, typename to>
to  NxOgreForceInline XYZ(const from& _from)
{
 to _to;
 _to.x = _from.x;
 _to.y = _from.y;
 _to.z = _from.z;
 return _to;
}

/** \brief Convert any vector3 class to another, assuming both classes have public member variables x y z
*/
template<typename from, typename to>
void  NxOgreForceInline XYZ(const from& _from, to& _to)
{
 _to.x = _from.x;
 _to.y = _from.y;
 _to.z = _from.z;
}

/** \brief Convert any vector4 class to another, assuming both classes have public member variables w x y z
*/
template<typename from, typename to>
to  NxOgreForceInline WXYZ(const from& _from)
{
 to _to;
 _to.w = _from.w;
 _to.x = _from.x;
 _to.y = _from.y;
 _to.z = _from.z;
 return _to;
}

/** \brief Convert any vector4 class to another, assuming both classes have public member variables w x y z
*/
template<typename from, typename to>
void  NxOgreForceInline WXYZ(const from& _from, to& _to)
{
 _to.w = _from.w;
 _to.x = _from.x;
 _to.y = _from.y;
 _to.z = _from.z;
}

/** \brief Turn a const char* into a hash
*/
unsigned long generateHash(const char*, Enums::HashAlgorithm);


template<typename T> void fill(T* start, T* end, T value)
{
 for (;start != end; ++start)
  (*start) = value;
}

                                                                                       

} // namespace Functions

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
