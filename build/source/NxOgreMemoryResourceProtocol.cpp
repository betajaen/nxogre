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
 mSingleArchiveName = mProtocolName = "memory";
 mProtocolHash = Strings::hash(mProtocolName);
}

MemoryResourceProtocol::~MemoryResourceProtocol(void)
{
}

Archive* MemoryResourceProtocol::openArchive(const String&, const Path&)
{
 if (mHasInit)
 {
  NxOgre_ThrowException(IOException, "Archive has already been initialised", Classes::_MemoryResourceProtocol);
  return 0;
 }
 
 return new MemoryArchive(mSingleArchiveName, BLANK_STRING, this);
}

void MemoryResourceProtocol::closeArchive(Archive* archive)
{
}

String MemoryResourceProtocol::getProtocol(void)
{
 return mProtocolName;
}

StringHash MemoryResourceProtocol::getProtocolHash(void) const
{
 return mProtocolHash;
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
 // Create a the single archive.
 NxOgre::ResourceSystem::getSingleton()->openArchive(Path("memory://"), "memory");
 // Archive has been created, so no longer need to do this agian.
 mHasInit = true;
}

String MemoryResourceProtocol::calculateArchiveName(const Path&)
{
 return mProtocolName;
}

                                                                                       

} // namespace NxOgre

                                                                                       
