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

                                                                                       

#ifndef NXOGRE_FORCEFIELDKERNEL_H
#define NXOGRE_FORCEFIELDKERNEL_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreForceFieldKernel.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. ForceFieldKernel
*/ 
class NxOgrePublicClass ForceFieldKernel : public ForceFieldBasedAllocatable
{
  
  public: // Functions
   
   ForceFieldKernel(const String& name = String());
   
   virtual ~ForceFieldKernel();
   
   /*! function. getName
       desc.
            Get the name of the ForceFieldKernel.
       return.
            **String** -- The name, or *BLANK_STRING* if there is no name.
   */
   String  getName() const;

   /*! function. getNameHash
       desc.
            Get the hashed name of the ForceFieldKernel.
       return.
            **StringHash** -- The hash of the name, or *BLANK_HASH* if there is no name.
   */
   StringHash  getNameHash() const;
  
   /*! function. increaseReference
       desc.
            Increase the reference count of the kernel.
   */
   void increaseReference();
   
   /*! function. decreaseReference
       desc.
            Decrease the reference count of the kernel.
   */
   void decreaseReference();
   
   /*! function. getNbReferences
       desc.
            Get the number of references to this kernel. 
       note.
            Reference counting the kernel is useful for you to decide when the kernel
            should be deleted; that is if you share the kernel between many forcefields.
       return.
            **unsigned int** -- Number of references.
   */
   unsigned int getNbReferences() const;
   
  protected:
   
   String       mName;
   
   StringHash   mNameHash;
   
  private:
   
   unsigned int mNbReferences;

}; // class ForceFieldKernel

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
