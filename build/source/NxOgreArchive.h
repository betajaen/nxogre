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

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief An archive is a collection of resources in one place. It may be implemented as a directory, zip
           file or even a website.
*/
class NxOgrePublicClass Archive
{
  
  public: // Functions
  
                                              Archive(String name, const UniformResourceIdentifier&, ResourceProtocol*);
  
  /** \brief Required virtual constructor.
  */
  virtual                                    ~Archive(void);
  
  /** \brief Open a new Resource based on an ArchiveResourceIdentifier, and Resource access permissions.
      \note  Archive* should be the original SharedPointer to this archive.
  */
  virtual        Resource*                    open(const ArchiveResourceIdentifier&, NxOgre::Enums::ResourceAccess) = 0;
  
  /** \brief Close a Resource
  */
  virtual        void                         close(Resource*) = 0;
  
  /** \brief Get the name of the Archive.
  */
                   String               getName();
  
  /** \brief Get the hash of the name of the Archive.
  */
                   unsigned long              getNameHash();
  
  /** \brief Get the ResourceProtocol associated with the Archive.
  */
                   ResourceProtocol*          getProtocol() const;
  
  /** \brief Get the UniformResourceIdentifier that identifies the Archive in the OS.
  */
                   UniformResourceIdentifier  getURI();
  
  protected: // Variables
  
  /** \brief Name of the Resource
  */
                 String                 mName;
  
  /** \brief Name of the Resource as a hash.
  */
                 unsigned long                mNameHash;
  
  /** \brief Parent ResourceProtocol
  */
                 ResourceProtocol*            mProtocol;
  
  /** \brief The UniformResourceIdentifier of this Archive; the protocol name and accessor of the archive.
  */
                 UniformResourceIdentifier    mURI;

  /** \brief Current Resources that are in use by the archive
  */
                 Array<Resource*>           mCurrentResources;
  
}; // class Archive

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
