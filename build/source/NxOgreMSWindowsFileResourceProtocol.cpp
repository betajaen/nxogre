/** File: NxOgreMSWindowsFileResourceProtocol.cpp
    Created on: 19-Nov-08
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
#include "NxOgreMSWindowsFileResourceProtocol.h"
#include "NxOgreFunctions.h"
#include "NxOgreArchive.h"
#include "NxOgreResource.h"
#include "NxOgreMSWindowsFileArchive.h"

                                                                                       

namespace NxOgre
{

                                                                                       

MSWindowsFileResourceProtocol::MSWindowsFileResourceProtocol(void)
{
}

MSWindowsFileResourceProtocol::~MSWindowsFileResourceProtocol(void)
{
}


Archive* MSWindowsFileResourceProtocol::openArchive(const String& name, const UniformResourceIdentifier& uri)
{
 return new MSWindowsFileArchive(name, uri, this);
}

void MSWindowsFileResourceProtocol::closeArchive(Archive* archive)
{
}

String MSWindowsFileResourceProtocol::getProtocol(void)
{
 return "file";
}

unsigned long MSWindowsFileResourceProtocol::getProtocolHash(void) const
{
 return Functions::generateHash("file", Enums::HashAlgorithm_DJB2);
}

bool MSWindowsFileResourceProtocol::isSingleArchive(void) const
{
 return false;
}

bool MSWindowsFileResourceProtocol::usesNamelessResources(void) const
{
 return false;
}

void MSWindowsFileResourceProtocol::initialise(void)
{
 // No default archives, so nothing to do.
}

                                                                                       

} // namespace NxOgre

                                                                                       
