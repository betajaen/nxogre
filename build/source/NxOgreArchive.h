/** File: NxOgreArchive.h
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
