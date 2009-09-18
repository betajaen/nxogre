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
