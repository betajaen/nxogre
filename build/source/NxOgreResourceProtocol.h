/** File: NxOgreResourceProtocol.h
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

#ifndef NXOGRE_RESOURCEPROTOCOL_H
#define NXOGRE_RESOURCEPROTOCOL_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass ResourceProtocol
{
  public: // Functions
  
  /** \brief Text
  */
  virtual                                    ~ResourceProtocol(void);
  
  /** \brief Open an archive based on a uniform resource identifier.
      \example
       <code>
        ResourceSystem::getSingleton->openArchive("media1", "zip://media1.zip");
       </code>
  */
  virtual              Archive*               openArchive(const String& name, const UniformResourceIdentifier&) = 0;
  
  /** \brief Close an archive, and close any resources in that archive.
  */
  virtual              void                   closeArchive(Archive*) = 0;
  
  /** \brief Text
  */
  virtual              String           getProtocol(void) = 0;
  
  /** \brief Text
  */
  virtual              unsigned long          getProtocolHash(void) const = 0;
  
  /** \brief Is there only one archive by default?
  */
  virtual              bool                   isSingleArchive(void) const = 0;
  
  /** \brief Does the resources use filenames?
  */
  virtual              bool                   usesNamelessResources(void) const = 0;
  
  /** \brief Initialise the resource system; create any default archives, etc.
      \note  This is called when the protocol is added to the ResourceSystem
  */
  virtual              void                   initialise(void) = 0;
  
}; // class ResourceProtocol

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
