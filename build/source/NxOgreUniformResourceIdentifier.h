/** File: NxOgreUniformResourceIdentifier.h
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

#ifndef NXOGRE_UNIFORMRESOURCEIDENTIFIER_H
#define NXOGRE_UNIFORMRESOURCEIDENTIFIER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgrePointerClass.h"
#include "NxOgreClasses.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/* \brief A URI is a string of characters used to identify the absolute protocol and location
          of a resource used with NxOgre. In this case, the URI is represented both a string
          and a dissembled version. The protocol is defined as the string of characters to the
          left of the first colon, the location is defined as the string of characters to the
          right of the colon. In the case of NxOgre; the protocol may refer to the ResourceProtocol
          and the location may refer to the relative filename. Archives are used to hold a group of
          resources together; generally speaking it could be a folder or zip file. An archive is 
          recongised to be the first string of text after the protocol and :// delimeter to the next
          "/".
          
          "file://test.txt"
            Protocol is "file" and "location" is "//test.txt"
          
          "file://text/test.txt"
            Protocol is "file" and "location" is "//text/test.txt", but archive is "text"
          
          "file://text/"
            Protocol is "file" and "location" is "//text/" but archive is "text"
          
   \note  This class is operates like a String, and works from the same data set if copied.
   \see http://en.wikipedia.org/wiki/URI
   \example
    <code>
     URI readme_txt("file://readme.txt");
    </code>
*/
class NxOgrePublicClass UniformResourceIdentifier
{
  
  public: // Functions
  
  /** \brief Text
  */
                                              UniformResourceIdentifier(void);
  
  /** \brief Text
  */
                                              UniformResourceIdentifier(const char* resource_identifier);
  
  /** \brief Text
  */
                                              UniformResourceIdentifier(const UniformResourceIdentifier&);
  
  /** \brief Text
  */
                                             ~UniformResourceIdentifier(void);
  
  /** \brief Text
  */
                                              UniformResourceIdentifier& operator=(const UniformResourceIdentifier&);
  
  /** \brief Text
  */
                                              UniformResourceIdentifier& operator=(const char*);
  
  /** \brief Text
  */
                       void                   set(const char*);
  
  /** \brief Text
  */
                       void                   set(const UniformResourceIdentifier&);
  
  /** \brief Text
  */
                       const char*            getProtocol(void) const;
  
  /** \brief Text
  */
                       void                   setProtocol(const char*, unsigned int where = 0, unsigned int length = 0);
  
  /** \brief Text
  */
                       unsigned long          getProtocolHash(void) const;
  
  /** \brief Text
  */
                       const char*            getLocation(void) const;
  
  /** \brief Text
  */
                       void                   setLocation(const char*, unsigned int where = 0, unsigned int length = 0);
  
  /** \brief Text
  */
                       unsigned long          getLocationHash(void) const;

  protected: // Classes
  
   class URIHash : public PointerClass<Classes::_URIHash>
   {
    friend class UniformResourceIdentifier;
    
    protected:
    
    /** \internal
    */
                                              URIHash(void);
    
    /** \internal
    */
                                             ~URIHash(void);
    
                      char*                   mProtocol;
                      char*                   mLocation;
                      unsigned long           mLocationHash;
                      unsigned long           mProtocolHash;
   };
  
  protected: // Variables
  
                       URIHash*               mURI;
                       unsigned short*        mReferences;
  
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
