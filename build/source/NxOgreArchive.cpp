/** File: NxOgreArchive.cpp
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
#include "NxOgreArchive.h"
#include "NxOgreFunctions.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Archive::Archive(String name, const UniformResourceIdentifier& uri, ResourceProtocol* protocol)
: mName(name), mURI(uri), mProtocol(protocol)
{
 mNameHash = NxOgre::Functions::generateHash(mName.c_str(), NxOgre::Enums::HashAlgorithm_DJB2);
}

Archive::~Archive(void)
{
}

String Archive::getName()
{
 return mName;
}

unsigned long Archive::getNameHash()
{
 return mNameHash;
}

ResourceProtocol* Archive::getProtocol() const
{
 return mProtocol;
}

UniformResourceIdentifier Archive::getURI()
{
 return mURI;
}

                                                                                       

} // namespace NxOgre

                                                                                       
