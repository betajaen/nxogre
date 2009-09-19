/** File: NxOgreArchiveResourceIdentifier.h
    Created on: 15-Nov-08
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

#ifndef NXOGRE_ARCHIVERESOURCEIDENTIFIER_H
#define NXOGRE_ARCHIVERESOURCEIDENTIFIER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgrePointerClass.h"
#include "NxOgreClasses.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/* \brief Identifies a resource name and archive both at once. It uses a string to represent them both,
          concatenated together with a seperator character ":". As archives are pre-registered, a protocol
          specifing what the resource isn't needed. ResourceNames generally are filenames (a string
          with an extension), if the archive is something different then it could be an integer or
          pointer both as strings.

          Some protocols that use a single archive; take on the name of their protocol, and some that don't
          use resource names use a empty string for the resource name. "Memory" from MemoryResourceProtocol
          is an example of both of these.

    \example
          - "physx_media:mesh.nxs"
          - "cakestuff.zip:island.xhf"
          - "memory:"
          - "www.nxogre.org:test.html"
          - "collision.dat:303"
  
*/
class NxOgrePublicClass ArchiveResourceIdentifier
{
  
  public: // Functions
  
  /** \brief Text
  */
                                              ArchiveResourceIdentifier(void);
  
  /** \brief Text
  */
                                              ArchiveResourceIdentifier(const char* archive_resource_identifier);
  
  /** \brief Text
  */
                                              ArchiveResourceIdentifier(const ArchiveResourceIdentifier&);
  
  /** \brief Text
  */
                                             ~ArchiveResourceIdentifier(void);
  
  /** \brief Text
  */
                                              ArchiveResourceIdentifier& operator=(const ArchiveResourceIdentifier&);
  
  /** \brief Text
  */
                                              ArchiveResourceIdentifier& operator=(const char*);
  
  /** \brief Text
  */
                       void                   set(const char*);
  
  /** \brief Text
  */
                       void                   set(const ArchiveResourceIdentifier&);
  
  /** \brief Text
  */
                       const char*            getArchive(void) const;
  
  /** \brief Text
  */
                       void                   setArchive(const char*, unsigned int where = 0, unsigned int length = 0);
  
  /** \brief Text
  */
                       unsigned long          getArchiveHash(void) const;
  
  /** \brief Text
  */
                       const char*            getResourceName(void) const;
  
  /** \brief Text
  */
                       void                   setResourceName(const char*, unsigned int where = 0, unsigned int length = 0);
  
  /** \brief Text
  */
                       unsigned long          getResourceNameHash(void) const;
  
  protected: // Classes
  
   class ARIHash : public PointerClass<Classes::_URIHash>
   {
    friend class ArchiveResourceIdentifier;
    
    protected:
    
    /** \internal
    */
                                              ARIHash(void);
    
    /** \internal
    */
                                             ~ARIHash(void);
    
                      char*                   mArchive;
                      char*                   mResourceName;
                      unsigned long           mArchiveHash;
                      unsigned long           mResourceNameHash;
   };
  
  protected: // Variables
  
                       ARIHash*               mARI;
                       unsigned short*        mReferences;
  
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
