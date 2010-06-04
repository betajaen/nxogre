/** 
    
    This file is part of NxOgre.
    
    Copyright (c) 2009 Robin Southern, http://www.nxogre.org
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
    
*/

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreResourceProtocol.h"

                                                                                       

namespace NxOgre
{

                                                                                       

ResourceProtocol::ResourceProtocol()
{
 // virtual function.
}

ResourceProtocol::~ResourceProtocol()
{
 // virtual function.
}

Resource* ResourceProtocol::open(const Path&, Enums::ResourceAccess)
{
 return 0; // virtual function.
}

void ResourceProtocol::close(Resource*)
{
 // virtual function.
}

String  ResourceProtocol::getProtocol() const
{
 return BLANK_STRING;
}

StringHash ResourceProtocol::getProtocolHash() const
{
 return BLANK_HASH;
}

bool ResourceProtocol::usesNamelessResources() const
{
 return false;
}

void ResourceProtocol::initialise()
{
 // virtual function.
}

Enums::UserDestructionPolicy ResourceProtocol::getDestructionPolicy() const
{
 return Enums::UserDestructionPolicy_Delete;
}

ResourceProtocol::ResourceIterator ResourceProtocol::getOpenedResources()
{
 return mOpenResources.elements();
}

void ResourceProtocol::addResource(Resource* resource)
{
 if (resource)
  mOpenResources.push_back(resource);
}

void ResourceProtocol::removeResource(Resource* resource)
{
 if (resource)
  mOpenResources.remove(mOpenResources.index(resource));
}

                                                                                       

} // namespace NxOgre

                                                                                       
