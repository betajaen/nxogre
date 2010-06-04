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
#include "NxOgreResource.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. ResourceProtocol
    desc.
        A ResourceProtocol is an abstract/inherited class that represents a type of way of accessing
        data outside the application. They create, destroy and maintain Resources; a handle of that
        data. ResourceProtocols are generally hidden away from the user, they are instead accessed
        through the ResourceSystem class.
*/
class NxOgrePublicClass ResourceProtocol : public ResourceAllocatable
{
  
 public: // Functions
  
  typedef vector<Resource*>           Resources;
  typedef vector_iterator<Resource*>  ResourceIterator;
  
  /*! constructor. ResourceProtocol
      desc.
          Resource Protocol constructor.
  */
  ResourceProtocol();
  
  /*! destructor.
      desc.
          Virtual Destructor.
  */
  virtual ~ResourceProtocol();
  
  /*! function. open
      desc.
          Open a resource from a path with the following access, the resource should be closed/destroyed
          by the equivalent close function.
      args.
          const Path& -- Path of the resource
          Enums::ResourceAccess -- Read/Write privileges
      return.
          Resource* -- The resource pointer or NULL if the resource could not be opened.
      note.
          You should not use this function directly. Use the ResourceSystem::open function instead.
      example.
        bc. ResourceSystem::getSingleton->open("file://C:/Program Files/Game/mesh.nxs", );
  */
  virtual Resource* open(const Path&, Enums::ResourceAccess);
  
  /*! function. close
      desc.
          Close an opened resource.
      args.
          Resource* -- The resource to close.
      note.
          You should not use this function directly. Use the ResourceSystem::close function instead.
  */
  virtual void  close(Resource*);
  
  /*! function. getProtocol
      desc.
          Get the a lowercased string of the name of the protocol; i.e. file, memory, etc.
      return.
          String -- The protocol string.
  */
  virtual String getProtocol() const;
  
  /*! function. getProtocolHash
      desc.
          Get the hash of the getProtocol function.
      return.
          StringHash -- The hash
      see.
         ResourceProtocol::getProtocol 
  */
  virtual StringHash getProtocolHash() const;
  
  /*! function. usesNamelessResources
      desc.
          Does this resource protocol use names?
      note.
          Some resource protocols may not use names for access. The MemoryProtocol is an example of
          this; Since it is not possible to allocate specific parts of the memory at the time, it cannot
          be addressed - so it cannot use names. The FileProtocol uses names (filenames) and thus
          can be addressed.
      return.
          bool -- If the resource protocol doesn't use names.
  */
  virtual bool usesNamelessResources() const;
  
  /*! function. initialise
      desc.
          Initialise the resource system; create any default archives, etc.
      note.
          This is called when the protocol is first opened by the ResourceSystem.
  */
  virtual void initialise();
  
  /*! function. getDestructionPolicy
      desc.
          When the ResourceSystem is destroyed, should this protocol be destroyed also?
      note.
          This applies to user created ResourceProtocols who may have their own memory
          allocation systems, or the ResourceProtocol may be part of a larger class.
      see.
         Enums::UserDestructionPolicy
  */
  virtual Enums::UserDestructionPolicy getDestructionPolicy() const;
  
  /*! function. getOpenedResources
      desc.
          Get a iterator to the current resources opened by this protocol
  */
  ResourceIterator getOpenedResources();
  
 protected:
  
  /*! function. addResource
      desc.
          Add a resource to opened resources.
  */
  void addResource(Resource*);
  
  /*! function. removeResource
      desc.
          Remove a resource from opened resources.
  */
  void removeResource(Resource*);
  
 protected:
  
  Resources mOpenResources;
  
}; // class ResourceProtocol

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
