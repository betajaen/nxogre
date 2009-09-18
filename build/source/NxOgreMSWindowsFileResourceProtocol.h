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
