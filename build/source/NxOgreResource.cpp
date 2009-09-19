/** File: NxOgreResource.cpp
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
#include "NxOgreResource.h"

                                                                                       

const char ::NxOgre::Resource::NULL_BYTE = 0;

                                                                                       

namespace NxOgre
{

                                                                                       

Resource::Resource(const ArchiveResourceIdentifier& ari, Archive* archive)
: mArchive(archive), mArchiveResourceIdentifier(ari)
{
}

Resource::~Resource(void)
{
}

Archive* Resource::getArchive()
{
 return mArchive;
}

ArchiveResourceIdentifier Resource::getArchiveResourceIdentifier()
{
 return mArchiveResourceIdentifier;
}

bool Resource::hasTouched() const
{
 return mNbWriteOperations != 0;
}

unsigned int Resource::getNbReadOperations() const
{
 return mNbReadOperations;
}

unsigned int Resource::getNbWriteOperations() const
{
 return mNbWriteOperations;
}


                                                                                       

} // namespace NxOgre

                                                                                       
