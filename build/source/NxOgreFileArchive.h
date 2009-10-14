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

                                                                                       

#ifndef NXOGRE_MSWINDOWSFILEARCHIVE_H
#define NXOGRE_MSWINDOWSFILEARCHIVE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreFileResource.h"
#include "NxOgreArchive.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. FileArchive
    desc.
        A FileArchive represents a directory or drive as an Archive.
*/
class NxOgrePublicClass FileArchive : public PointerClass<Classes::_FileArchive>, public Archive
{
  
  public: // Functions
  
  /*! constructor. FileArchive
      desc.
          Do not create manually. Use ResourceSystem::openArchive instead.
      args.
          const String& __name__ -- Archive name.
          const Path& __path__ -- Path to the Archive.
          ResourceProtocol* __protocol__ -- ResourceProtocol, must be a FileResourceProtocol.
  */
                                              FileArchive(const String& name, const Path& path, ResourceProtocol* protocol);
  
  /*! destructor. FileArchive
  */
                                             ~FileArchive(void);
  
  /*! function. open
      desc.
           Open a resource. Similar function to ResourceSystem::open.
      args.
          const Path& __path__ -- Relative path to the file to open, Protocol must be the same protocol as this Archive is.
          Enums::ResourceAccess __access__ -- Resource access.
  */
                 Resource*                    open(const Path&, Enums::ResourceAccess access);
  
  /*! function. close
      desc.
           Close a resource.
      args.
           Resource* __resource__ -- Resource to close. Resource must be created by this archive.
  */
                 void                         close(Resource* resource);
  
  
}; // class FileArchive

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
