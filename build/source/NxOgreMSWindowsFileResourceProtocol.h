/** File: NxOgreMSWindowsFileResourceProtocol.h
    Created on: 19-Nov-08
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

#ifndef NXOGRE_MSWINDOWSFILERESOURCEPROTOCOL_H
#define NXOGRE_MSWINDOWSFILERESOURCEPROTOCOL_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreResourceProtocol.h"
#include "NxOgrePointerClass.h"
#include "NxOgreArchiveResourceIdentifier.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief MSWindows version of the FileResourceProtocol. Uses directories as archives.
    \example
    <code>
     // Create an archive using a folder and giving it a name "media".
     ResourceSystem::getSingleton()->openArchive("media", "file://c:/Program Files/myGame/media/");
     // Open an resource in the archive "media".
     ResourceSystem::getSingleton()->open("media/mesh.nxs");
    </code>
*/
class NxOgrePublicClass MSWindowsFileResourceProtocol : public PointerClass<Classes::_MSWindowsFileResourceProtocol>, public ResourceProtocol
{
  
  public: // Functions
  
  /** \brief Text
  */
                                              MSWindowsFileResourceProtocol(void);
  
  /** \brief Text
  */
                                             ~MSWindowsFileResourceProtocol(void);

  /** \brief Text
  */
                       String           getProtocol(void);
  
  /** \brief Text
  */
                       unsigned long          getProtocolHash(void) const;
  
  /** \brief Is there only one archive by default?
  */
                       bool                   isSingleArchive(void) const;
  
  /** \brief Does the resources use filenames?
  */
                       bool                   usesNamelessResources(void) const;
  
  protected: // Functions
  
  /** \brief Open an archive, and parse the contents. An archive being a single folder.
      \example
       <code>
        ResourceSystem::getSingleton()->openArchive("media", "file://C:\Program Files\myGame\media/");
       </code>
  */
                       Archive*             openArchive(const String&, const UniformResourceIdentifier&);
  
  /** \brief Close an archive.
  */
                       void                   closeArchive(Archive*);

  /** \brief Required initialise function
  */
                       void                   initialise(void);
  
  protected: // Variables
  
  
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
