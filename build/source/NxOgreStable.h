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

                                                                                       

#ifndef NXOGRE_STABLE_H
#define NXOGRE_STABLE_H

                                                                                       

#include "NxOgreAutoConfiguration.h"
#include "NxOgreConfiguration.h"

#ifndef NXOGRE_HAS_CONFIGURATION
# error Could not find NxOgreConfiguration.h
#endif

#include "limits.h"
#include "float.h"
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <list>

                                                                                       

#define NxOgreVersionMajor 1
#define NxOgreVersionMinor 6
#define NxOgreVersionRelease 0
#define NxOgreCodeName "Detritus"
#define NxOgreBranch "detritus"

                                                                                       

#ifndef NxOgreCompiler
#  define NxOgreCompiler NxOgreCompilerUnknown
#endif

#ifndef NxOgrePlatform
#  define NxOgreCompiler NxOgrePlatformUnknown
#endif

#ifndef NxOgreArchitecture
#  define NxOgreArchitecture NxOgreArchitecture32Bit
#endif

#ifndef NxOgrePublicClass
#  define NxOgrePublicClass
#endif

#ifndef NxOgrePublicFunction
#  define NxOgrePublicFunction
#endif

#ifndef NxOgreForceInline
#  define NxOgreForceInline
#endif

                                                                                       

/** \brief Global new operator/function for every NxOgre class that requires to be a pointer.
    \example
     <code>
      Actor* a = NxOgre_New (arg0, arg1, ...);
     </code>
*/
#define  NxOgre_New new

/** \brief Global new operator/function for every user class (and classes that do not inherit Allocatable) which
           wishes to be tracked and allocated by the NxOgre Memory class.
    \note  Unless you want to inherit from NxOgre::PointerClass (and use NxOgre_New) the allocator
           will allocate it as "_UserClass".
    \example
     <code>
      class myClass
      {
       ...
      };
      ...
      myClass* myclass_ptr = NxOgre_NewT(myClass)(arg0, arg1, ...);
     </code>
*/
#define  NxOgre_NewT(USER_CLASS) new (::NxOgre::Memory::allocate(sizeof(USER_CLASS), ::NxOgre::Classes::_UserClass, __FILE__, __LINE__)) USER_CLASS

/** \brief Global delete operator/function for every NxOgre class that requires to be deleted.
    \example
     <code>
      NxOgre_Delete(a);
     </code>
*/
#define NxOgre_Delete(PTR) {if(PTR){delete PTR;PTR=0;}}

/** \brief Global delete operator/function for a user's class which has been previously created via NxOgre_NewT
    \example
     <code>
       NxOgre_DeleteT(myClass, myclass_ptr);
     </code>
*/
#define NxOgre_DeleteT(TYPE, PTR) {if(PTR){PTR->~TYPE();::NxOgre::Memory::unallocate(PTR);PTR=0}}

/** \brief NxOgre's version of "malloc"; always used by NxOgre and PhysX, and can be used by the user if needed.
    \example
      <code>
       int* i = (int*) NxOgre_Allocate(sizeof(int), NxOgre::Classes::_int);
      </code>
*/
#if NxOgreMemoryDebugger == 1
#  define NxOgre_Allocate(SIZE, CLASSES_TYPE) ::NxOgre::Memory::allocate(SIZE, CLASSES_TYPE, __FILE__, __LINE__);
#else
#  define NxOgre_Allocate(SIZE, CLASSES_TYPE) ::NxOgre::Memory::allocate(SIZE);
#endif

/** \brief NxOgre's version of "free"; always used by NxOgre and PhysX, and can be used by the user if needed.
    \example
      <code>
      NxOgre_Unallocate(i);
      </code>
*/
#define NxOgre_Unallocate(PTR) {if(PTR){::NxOgre::Memory::unallocate(PTR);PTR=0;}}

/** \brief NxOgre's version of "realloc"; always used by NxOgre and PhysX, and can be used by the user if needed.
    \example
      <code>
       i = NxOgre_Reallocate(i, sizeof(int) * 2);
      </code>
*/
#define NxOgre_Reallocate(PTR, NEW_SIZE)      ::NxOgre::Memory::reallocate(PTR, NEW_SIZE)

#define NxOgre_ExceptionNoClassType 0

#define NxOgre_ThrowException(EXCEPTION, DESCRIPTION, CLASS_TYPE) throw EXCEPTION(__FILE__, __LINE__, DESCRIPTION, CLASS_TYPE);

#define NxOgre_ThrowExceptionIfNull(PTR, CLASS_TYPE) if(PTR == 0){throw ::NxOgre::NullPointerException(__FILE__, __LINE__, CLASS_TYPE);}

#define NxOgre_ThrowWarning(DESCRIPTION, CLASS_TYPE) ::NxOgre::ErrorStream::getSingleton()->addWarning(Warning(__FILE__, __LINE__, DESCRIPTION, CLASS_TYPE));

#define NxOgre_ThrowNotice(DESCRIPTION) ::NxOgre::ErrorStream::getSingleton()->addNotice(Notice(__FILE__, __LINE__, DESCRIPTION));

#define NxOgre_CompileAssertion(exp, reason)  extern char NxOgreCompilerAssertion__##reason__[ size_t((exp) ? 1 : -1) ]

#define NxOgre_PreprocessorToStringBase(x) #x

#define NxOgre_Stringify(x) NxOgre_PreprocessorToStringBase(x)

#ifdef NXOGRE_SDK
// All classes that use the TinyClassAllocatable, must use this macro when the class is defined.
#  define NxOgreTinyClassRestriction(CLASS) extern char NxOgreCompileAssert[size_t(sizeof(CLASS) == 16 ? 1 : -1)];
#else
#  define NxOgreTinyClassRestriction(CLASS)
#endif

                                                                                       

#define NxOgreIntTypeMax INT_MAX
#define NxOgreIntTypeMin (-INT_MAX)
#define NxOgreFloatTypeMax FLT_MAX
#define NxOgreFloatTypeMin (-FLT_MAX)
#define NxOgreDoubleTypeMax DBL_MAX
#define NxOgreDoubleTypeMin (-DBL_MAX)

#if (NxOgreFloatingPointAccuracy == NxOgreFloatingPointFloat)
#  define NxOgreRealType float
#  define NxOgreRealMax NxOgreFloatTypeMax
#  define NxOgreRealMin NxOgreFloatTypeMin
#elif (NxOgreFloatingPointAccuracy == NxOgreFloatingPointDouble)
#  define NxOgreRealType double
#  define NxOgreRealMax NxOgreDoubleTypeMax
#  define NxOgreRealMin NxOgreDoubleTypeMin
#else
#  error Floating point accuracy not specified
#endif

                                                                                       

namespace NxOgre
{

/** \brief All floating-types are called "Real" in NxOgre; this allows single or double precision of every
           class using a real number by changing the NxOgreFloatingPointAccuracy macro.
*/
typedef NxOgreRealType Real;


#if (NxOgreFloatingPointAccuracy == NxOgreFloatingPointFloat)
/** \brief A much more accurate Real used with Character controller and other high-precision classes.
    \note  Some classes will disappear or remove functions if Real is a double.
*/
typedef double DoubleReal;
#endif

/** \brief References type for Containers.
*/
typedef unsigned int RefT;

} // namespace NxOgre

                                                                                       

/*! page. README
  h1. NxOgre
  
  NxOgre likes cake.
  
*/

#endif
