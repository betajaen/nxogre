/** File: NxOgreMemoryResourceProtocol.cpp
    Created on: 17-Nov-08
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
#include "NxOgreMemoryResourceProtocol.h"
#include "NxOgreFunctions.h"
#include "NxOgreArchive.h"
#include "NxOgreResource.h"
#include "NxOgreMemoryResource.h"
#include "NxOgreResourceSystem.h"
#include "NxOgreMemoryArchive.h"

                                                                                       

namespace NxOgre
{

                                                                                       

MemoryResourceProtocol::MemoryResourceProtocol(void) : mHasInit(false)
{
}

MemoryResourceProtocol::~MemoryResourceProtocol(void)
{
}

Archive* MemoryResourceProtocol::openArchive(const String&, const UniformResourceIdentifier&)
{
 if (mHasInit)
 {
  NxOgre_ThrowError("User tried to create an archive in a SingleArchive with MemoryResourceProtocol");
  return 0;
 }
 
 return new MemoryArchive("memory", UniformResourceIdentifier("memory://"), this);
}

void MemoryResourceProtocol::closeArchive(Archive* archive)
{
}

String MemoryResourceProtocol::getProtocol(void)
{
 return "memory";
}

unsigned long MemoryResourceProtocol::getProtocolHash(void) const
{
 return Functions::generateHash("memory", Enums::HashAlgorithm_DJB2);
}

bool MemoryResourceProtocol::isSingleArchive(void) const
{
 return true;
}

bool MemoryResourceProtocol::usesNamelessResources(void) const
{
 return true;
}

void MemoryResourceProtocol::initialise(void)
{
 // Create the single "memory" archive.
 NxOgre::ResourceSystem::getSingleton()->openArchive("memory", "memory://");
 mHasInit = true;
}

                                                                                       

} // namespace NxOgre

                                                                                       
