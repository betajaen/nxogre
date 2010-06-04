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

                                                                                       

#ifndef NXOGRE_PHYSXUSERENTIYREPORT_H
#define NXOGRE_PHYSXUSERENTIYREPORT_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreEntityReport.h"

#ifdef NXOGRE_SDK
# include "NxPhysics.h"
#endif


                                                                                       

namespace NxOgre
{

                                                                                       

#ifdef NXOGRE_SDK

/** \brief
*/
template <typename T>
class NxOgrePublicClass PhysXUserEntityReport : public GenericBasedAllocatable, public NxUserEntityReport<T>
{
  
  public: // Functions
  
  /** \brief Text
  */
                                              PhysXUserEntityReport(EntityReport<T>* entityReport)
  : mEntityReport(entityReport)
  {
  }
  
  /** \brief Text
  */
                                             ~PhysXUserEntityReport()
  {
  }
  
  /** \brief Text
  */
  bool                                        onEvent(unsigned int tSize, T* t)
  {
   const_buffer<T> buffer(t, t + tSize);
   return mEntityReport->onEvent(buffer);
  }
  
  
  protected: // Variables
  
  EntityReport<T>*                            mEntityReport;
  
  
}; // class ClassName

/*! class. PhysXUserDataCallbackReport
    desc.
         Coverts a mass of PhysX classes into NxOgre ones via the userData property, then calls a function
         in a class with them as an argument.
*/
template <typename T, typename T2, typename C>
class NxOgrePublicClass PhysXUserDataCallbackReport : public NxUserEntityReport<T>
{
  
  public: // Functions
  
  typedef bool (C::*CallbackFunction)(const buffer<T2*>&);
  
  /** \brief Text
  */
  explicit PhysXUserDataCallbackReport(CallbackFunction func, C* c) 
  : mFunction(func), mCallback(c)
  {
  }
  
  /** \brief Text
  */
 ~PhysXUserDataCallbackReport()
  {
  }
  
  /** \brief Text
  */
  bool onEvent(unsigned int tSize, T* t)
  {
   buffer<T2*> buffer;//(t, t + tSize);
   for (unsigned int i=0;i < tSize;i++)
    buffer.push_back(pointer_representive_cast<T2>(t[i]->userData));
   return (mCallback->*mFunction)(buffer);
  }
  
  
  protected: // Variables
  
  CallbackFunction  mFunction;
  C*                mCallback;
  
}; // class

#endif



                                                                                       

} // namespace PhysXEntityReport

                                                                                       

#endif
