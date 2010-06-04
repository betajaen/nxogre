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


                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. FileResourceProtocol
    desc.
         Uses Files as Resources and Directories as Archives. Platform independent.
    example.
         // Open or create an archive (which will be named media) from the following path, then open the file named "mesh.nxs"
         // and represent it as a Resource.
         Resource* resource = ResourceSystem::getSingleton()->open("file://c:/Program Files/myGame/media/mesh.nxs");
*/
class NxOgrePublicClass FileResourceProtocol : public ResourceProtocol
{
  
  public: // Functions
  
  /*! constructor. FileResourceProtocol
  */
  FileResourceProtocol();
  
  /*! destructor. FileResourceProtocol
  */
 ~FileResourceProtocol();
  
  /*! function. getProtocol
      desc.
          Get the protocol "file"
      return.
          **String** -- The protocol, which will be "file".
  */
  String  getProtocol() const;
  
  /*! function. getProtocolHash
      desc.
          Get the protocol hash of "file"
      return.
          **String** -- Always "file" run through a hash function.
  */
  StringHash  getProtocolHash() const;
  
  /*! function. usesNamelessResource
      desc.
          Does the resources not use filenames?
      return
          **bool** -- Always returns false.
  */
  bool usesNamelessResources() const;
    
  protected: // Functions
  
  /*! function. open
  */
  Resource*  open(const Path&, Enums::ResourceAccess);
  
  /*! function. closeArchive
  */
  void  close(Resource*);

  /*! function. initialise
      desc.
          Required initialise function
  */
  void  initialise();
  
  protected: // Variables
  
  String                 mProtocolName;
  
  StringHash             mProtocolHash;
  
}; // class FileResourceProtocol

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
