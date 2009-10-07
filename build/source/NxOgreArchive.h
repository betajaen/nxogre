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

                                                                                       

#ifndef NXOGRE_ARCHIVE_H
#define NXOGRE_ARCHIVE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreResource.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. Archive
   
        An archive is a collection of resources in one place.

        p. It may be implemented as a directory, zip file or even a website.
*/
class NxOgrePublicClass Archive
{
  
  public: // Functions
  
  typedef ptr_vector<Resource>                Resources;
  typedef ptr_vector<Resource>::iterator_t ResourcesIterator;

  /*! constructor. Archive
      desc.
           Archive Constructor which used by inherited classes of Archive.
      note.
           Use *ResourceSystem::openArchive*.
      
  */
  Archive(const String& name, const Path&, ResourceProtocol*);
  
  /*! destructor. Archive
      desc. Required virtual constructor.
      !virtual
  */
  virtual ~Archive(void);
  
  /*! function. open
      desc.
          Open a new Resource based on an ArchiveResourceIdentifier, and Resource access permissions.
      args.
       const Path& __relativePath__ -- Relative Path to the Resource, Relative to the Archive.
       NxOgre::Enums::ResourceAccess __access__ -- Access permissions
      return.
       **Resource** * -- Resource if opened sucessfully, or *NULL* on failure
      !virtual
  */
  virtual Resource* open(const Path& relativePath, NxOgre::Enums::ResourceAccess access);
  
  /*! function. close
      desc.
           Close a Resource from this Archive.
      args.
        Resource* __resource__ -- Resource to close
  */
  virtual void  close(Resource* resource);
  
  /*! function. getOpenResources
      desc.
           Get open resources
      return.
           **ResourcesIterator** -- Iterator to the current resources of the archive.
  */
  ResourcesIterator getOpenResources();
  
  /*! function. getName
      desc.
           Get the name of the Archive.
      return.
           **String** -- Name of the Archive
  */
  String getName();
  
  /*! function. getNameHash
      desc.
           Get the hash of the name of the Archive.
      return.
           **StringHash** -- Hash of the name of the Archive
  */
  StringHash getNameHash();
  
  /*! function. getProtocol
      desc.
           Get the **ResourceProtocol** of this Archive
      return.
           **ResourceProtocol** -- The ResourceProtocol pointer
  */
  ResourceProtocol* getProtocol() const;
  
  /*! function. getPath
      desc.
           Get the path of the Archive.
      return.
           **Path** -- Pat of the Archive
  */
  Path getPath() const;
  
  protected: // Variables
  
  void _addResource(Resource*);
  
  void _removeResource(Resource*);

  /** \brief Name of the Resource
  */
  String mName;
  
  /** \brief Name of the Resource as a hash.
  */
  StringHash mNameHash;
  
  /** \brief Archive's path.
  */
  Path mPath;
  
  /** \brief Parent ResourceProtocol
  */
  ResourceProtocol* mProtocol;
  
  /** \brief Current Resources that are in use by the archive
  */
  Resources mResources;
  
}; // class Archive

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
