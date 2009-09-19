/** File: NxOgreMSWindowsFileArchive.h
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

#ifndef NXOGRE_MSWINDOWSFILEARCHIVE_H
#define NXOGRE_MSWINDOWSFILEARCHIVE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreMSWindowsFileResource.h"
#include "NxOgreArchive.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief An archive is a collection of resources in one place. It may be implemented as a directory, zip
           file or even a website.
*/
class NxOgrePublicClass MSWindowsFileArchive : public PointerClass<Classes::_MSWindowsFileArchive>, public Archive
{
  
  public: // Functions
  
  /** \brief
  */
                                              MSWindowsFileArchive(const String& name, const UniformResourceIdentifier&, ResourceProtocol*);

  /** \brief Required virtual constructor.
  */
                                             ~MSWindowsFileArchive(void);
  
  /** \brief
  */
                 Resource*                  open(const ArchiveResourceIdentifier& ari, NxOgre::Enums::ResourceAccess access);
  
  /** \brief
  */
                 void                         close(Resource*);
  
  protected:
  
  /** \internal
  */
                 String                 mPath;
  
                 Array<MSWindowsFileResource*> mResources;
  
}; // class Archive

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
