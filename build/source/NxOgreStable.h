/** File: NxOgreStable.h
    Created on: 1-Nov-08
    Author: Robin Southern "betajaen"
    SVN-Meta: $Id$

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

#ifndef NXOGRE_STABLE_H
#define NXOGRE_STABLE_H

                                                                                       

#include "NxOgreConfiguration.h"

#ifndef NXOGRE_HAS_CONFIGURATION
# error Could not find NxOgreConfiguration.h
#endif

#include "limits.h"
#include "float.h"
#include <stdlib.h>

                                                                                       

#define NxOgreVersionMajor 1
#define NxOgreVersionMinor 5
#define NxOgreVersionRelease 6
#define NxOgreCodeName "Git"

                                                                                       

#ifndef NxOgreCompiler
#  define NxOgreCompiler NxOgreCompilerUnknown
#endif

#ifndef NxOgrePlatform
#  define NxOgreCompiler NxOgrePlatformUnknown
#endif

#ifndef NxOgreArchitecture
#  define  NxOgreArchitecture NxOgreArchitecture32Bit
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
      Actor* a = NxOgre_New(Actor)(arg0, arg1, ...);
     </code>
*/
#define  NxOgre_New(NXOGRE_CLASS)  new NXOGRE_CLASS

/** \brief Global new operator/function for every user class (and classes that do not inherit PointerClass) which
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

/** \brief Throw a very critical error and assert.
*/
#define NxOgre_ThrowAssertion(COND, MESSAGE)  {if(COND){::NxOgre::ErrorStream::getSingleton()->throwAssertion(MESSAGE, __FILE__, __LINE__);}assert(COND);}

/** \brief Throw a critical (but do not assert) error.
*/
#define NxOgre_ThrowError(MESSAGE)            ::NxOgre::ErrorStream::getSingleton()->throwError(MESSAGE, __FILE__, __LINE__)

/** \brief Throw a non-critical error.
*/
#define NxOgre_ThrowWarning(MESSAGE)          ::NxOgre::ErrorStream::getSingleton()->throwWarning(MESSAGE, __FILE__, __LINE__)

/** \brief Throw a non-error.
*/
#define NxOgre_ThrowNotice(MESSAGE)           ::NxOgre::ErrorStream::getSingleton()->throwNotice(MESSAGE, __FILE__, __LINE__)

/** \brief Compiler macro to cause a compiler error if the expression is false.
*/
#define NxOgre_CompileAssertion(exp, reason)  extern char __Assertion##reason__[ size_t((exp) ? 1 : -1) ]

#define NxOgre_PreprocessorToStringBase(x) #x
#define NxOgre_Stringify(x) NxOgre_PreprocessorToStringBase(x)

                                                                                       

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
typedef unsigned short RefT;

} // namespace NxOgre

                                                                                       

#endif
