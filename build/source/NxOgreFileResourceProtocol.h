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

                                                                                       

#ifndef NXOGRE_MSWINDOWSFILERESOURCEPROTOCOL_H
#define NXOGRE_MSWINDOWSFILERESOURCEPROTOCOL_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreResourceProtocol.h"


                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. FileResourceProtocol
    desc.
         Uses Files as Resources and Directories as Archives. Platform independent.
    example.
         // Open or create an archive (which will be named media) from the following path, then open the file named "mesh.nxs"
         // and represent it as a Resource.
         Resource* resource = ResourceSystem::getSingleton()->open("file://c:/Program Files/myGame/media/mesh.nxs");
*/
class NxOgrePublicClass FileResourceProtocol : public ResourceProtocol
{
  
  public: // Functions
  
  /*! constructor. FileResourceProtocol
  */
  FileResourceProtocol();
  
  /*! destructor. FileResourceProtocol
  */
 ~FileResourceProtocol();
  
  /*! function. getProtocol
      desc.
          Get the protocol "file"
      return.
          **String** -- The protocol, which will be "file".
  */
  String  getProtocol() const;
  
  /*! function. getProtocolHash
      desc.
          Get the protocol hash of "file"
      return.
          **String** -- Always "file" run through a hash function.
  */
  StringHash  getProtocolHash() const;
  
  /*! function. isSingleArchive
      desc.
          Is there only one archive by default?
      return.
          **bool** -- Always returns false.
  */
  bool  isSingleArchive() const;
  
  /*! function. usesNamelessResource
      desc.
          Does the resources use filenames?
      return
          **bool** -- Always returns true.
  */
  bool usesNamelessResources() const;
  
  /*! function. calculateArchiveName
      desc.
           Calculates the archive name given by a path
            
           The process of getting the name is;
           # Is Relative Path? Has No Directories?  => @current_directory@
           # Has Directories? => @path.directory(0)@
           # Has No Directories? Has Drive => @path.drive()@
           # Otherwise => @file_archive_<random_hex_string>@
      args.
       const Path& __path__ -- Path to calculate the archive name from
      return.
       **String** -- The archive name.
  */
  String  calculateArchiveName(const Path&);
  
  protected: // Functions
  
  /*! function. openArchive
      desc.
          Open an archive, and parse the contents. An archive being a single folder.
      example.
        ResourceSystem::getSingleton()->openArchive("media", "file://C:/Program Files/myGame/media/");
      args.
       const String& archive_name -- Name of the archive; usually given by FileResourceProtocol::calculateArchiveName
       const Path& path -- Directory path of the archive to represent.
      return.
        **Archive** * -- The opened archive.
  */
  Archive*  openArchive(const String& archive_name, const Path& path);
  
  /*! function. closeArchive
      desc.
          Close an archive.
      args.
          Archive* __archive__ -- Archive to close.
  */
  void  closeArchive(Archive*);

  /*! function. initialise
      desc.
          Required initialise function
  */
  void  initialise(void);
  
  protected: // Variables
  
  String                 mProtocolName;
  
  StringHash             mProtocolHash;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
