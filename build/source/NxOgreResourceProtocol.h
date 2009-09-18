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
