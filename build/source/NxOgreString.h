/** File: NxOgreSharedString.h
    Created on: 4-Nov-08
    Author: Robin Southern "betajaen"
    

    (c) Copyright, 2008-2009 by Robin Southern, http://www.nxogre.org

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

#ifndef NXOGRE_STRING_H
#define NXOGRE_STRING_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgrePointerClass.h"
#include "NxOgreMemory.h"
#include <stdio.h>

                                                                                       

namespace NxOgre_Namespace
{

                                                                                       

typedef std::string String;

typedef std::stringstream StringStream;

typedef size_t StringHash;

static const String BLANK_STRING = String();

namespace Functions
{
 
 static const boost::hash<std::string> StringHash;
 
}

                                                                                       

} // namespace NXOGRE_NAMESPACE

                                                                                       

#endif
