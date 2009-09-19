/** File: NxOgreMSWindowsFileArchive.cpp
    Created on: 20-Nov-08
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
#include "NxOgreMSWindowsFileArchive.h"
#include "NxOgreMSWindowsFileResource.h"

                                                                                       

namespace NxOgre
{

                                                                                       

MSWindowsFileArchive::MSWindowsFileArchive(const String& name, const UniformResourceIdentifier& uri, ResourceProtocol* protocol)
: Archive(name, uri, protocol)
{
}

MSWindowsFileArchive::~MSWindowsFileArchive(void)
{
 mResources.destroyAll();
}

Resource* MSWindowsFileArchive::open(const ArchiveResourceIdentifier& ari, NxOgre::Enums::ResourceAccess access)
{
 MSWindowsFileResource* resource = new MSWindowsFileResource(ari, this, access);
 resource->open();
 mResources.insert(resource);
 return resource;
}

void MSWindowsFileArchive::close(Resource* resource)
{
 MSWindowsFileResource* msfile_resource = static_cast<MSWindowsFileResource*>(resource);
 mResources.remove(msfile_resource);
 msfile_resource->close();
 NxOgre_Delete(msfile_resource);

}

                                                                                       

} // namespace NxOgre

                                                                                       
