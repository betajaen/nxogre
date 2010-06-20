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

                                                                                       

#include "NxOgreVersion.h"
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

                                                                                       

#define NxOgre_ExceptionNoClassType 0

#define NxOgre_ThrowException(EXCEPTION, DESCRIPTION, CLASS_TYPE) throw EXCEPTION(__FILE__, __LINE__, DESCRIPTION, CLASS_TYPE); 

#define NxOgre_ThrowExceptionIfNull(PTR, CLASS_TYPE) if(PTR == 0){throw ::NxOgre::NullPointerException(__FILE__, __LINE__, CLASS_TYPE);}

#define NxOgre_ThrowExceptionIfNotNull(PTR, DESCRIPTION, CLASS_TYPE) if(PTR != 0){throw ::NxOgre::NonNullPointerException(__FILE__, __LINE__, DESCRIPTION, CLASS_TYPE);}

#define NxOgre_ThrowWarning(DESCRIPTION, CLASS_TYPE) ::NxOgre::ErrorStream::getSingleton()->addWarning(Warning(__FILE__, __LINE__, DESCRIPTION, CLASS_TYPE));

#define NxOgre_ThrowNotice(DESCRIPTION) ::NxOgre::ErrorStream::getSingleton()->addNotice(Notice(__FILE__, __LINE__, DESCRIPTION));

#define NxOgre_CompileAssertion(exp, reason)  extern char NxOgreCompilerAssertion__##reason__[ size_t((exp) ? 1 : -1) ]

#define NxOgre_PreprocessorToStringBase(x) #x

#define NxOgre_Stringify(x) NxOgre_PreprocessorToStringBase(x)

#ifdef NXOGRE_SDK
// All classes that use the TinyClassAllocatable, must use this macro when the class is defined.
#  define NxOgreSixteenBytesRestriction(CLASS) extern char NxOgreCompileAssert[size_t(sizeof(CLASS) == 16 ? 1 : -1)];
#  define NxOgreFourBytesRestriction(CLASS) extern char NxOgreCompileAssert[size_t(sizeof(CLASS) == 4 ? 1 : -1)];
#else
#  define NxOgreSixteenBytesRestriction(CLASS)
#  define NxOgreFourBytesRestriction(CLASS)
#endif

                                                                                       

#define NxOgre_DebugPrint(MESSAGE) std::cout << MESSAGE << std::endl;

#if NXOGRE_DEBUG_CORE == 1
 #define NxOgre_DebugPrint_Core(MESSAGE) NxOgre_DebugPrint("[NxOgre/Core] " << MESSAGE)
#else
 #define NxOgre_DebugPrint_Core(MESSAGE) /* MESSAGE */
#endif

#if NXOGRE_DEBUG_RESOURCES == 1
 #define NxOgre_DebugPrint_Resources(MESSAGE) NxOgre_DebugPrint("[NxOgre/Resources] " << MESSAGE)
#else
 #define NxOgre_DebugPrint_Resources(MESSAGE) /* MESSAGE */
#endif

#if NXOGRE_DEBUG_MEMORY == 1
 #define NxOgre_DebugPrint_Memory(MESSAGE) NxOgre_DebugPrint("[NxOgre/Memory] " << MESSAGE)
#else
 #define NxOgre_DebugPrint_Memory(MESSAGE) /* MESSAGE */
#endif

#if NXOGRE_DEBUG_COOKING == 1
 #define NxOgre_DebugPrint_Cooking(MESSAGE) NxOgre_DebugPrint("[NxOgre/Cooking] " << MESSAGE)
#else
 #define NxOgre_DebugPrint_Cooking(MESSAGE) /* MESSAGE */
#endif

#if NXOGRE_DEBUG_BUFFER == 1
 #define NxOgre_DebugPrint_Buffer(MESSAGE) NxOgre_DebugPrint("[NxOgre/Buffer] " << MESSAGE)
#else
 #define NxOgre_DebugPrint_Buffer(MESSAGE) /* MESSAGE */
#endif

#if NXOGRE_DEBUG_MESHES == 1
 #define NxOgre_DebugPrint_Meshes(MESSAGE) NxOgre_DebugPrint("[NxOgre/Meshes] " << MESSAGE)
#else
 #define NxOgre_DebugPrint_Meshes(MESSAGE) /* MESSAGE */
#endif

#if NXOGRE_DEBUG_HEIGHTFIELDS == 1
 #define NxOgre_DebugPrint_HeightFields(MESSAGE) NxOgre_DebugPrint("[NxOgre/HeightFields] " << MESSAGE)
#else
 #define NxOgre_DebugPrint_HeightFields(MESSAGE) /* MESSAGE */
#endif

#if NXOGRE_DEBUG_CLOTH == 1
 #define NxOgre_DebugPrint_Cloth(MESSAGE) NxOgre_DebugPrint("[NxOgre/Cloth] " << MESSAGE)
#else
 #define NxOgre_DebugPrint_Cloth(MESSAGE) /* MESSAGE */
#endif

#if NXOGRE_DEBUG_FLATYAML == 1
 #define NxOgre_DebugPrint_FlatYAML(MESSAGE) NxOgre_DebugPrint("[NxOgre/FlatYAML] " << MESSAGE)
#else
 #define NxOgre_DebugPrint_FlatYAML(MESSAGE) /* MESSAGE */
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

h1. Compiling NxOgre from the Git repository

The Git repository is Betajaen's public copy of the working code of NxOgre. It is the most recent code published, and it being so recent hasn't been tested so much. 

If you can't live on the edge then the "latest release":http://nxogre.org/compiling_nxogre_from_a_release is for you, otherwise game on.

h2. Checklist

Before you install NxOgre go through this checklist

* "Install the PhysX SystemSoftware":http://nxogre.org/installing_the_physx_system_software
* "Install the PhysX SDK":http://nxogre.org/installing_the_physx_sdk
* "Create the environmental variable for the PhysX SDK":http://nxogre.org/environmental_variable_for_physx

h2. Installation Instructions

# Go to the latest commit on "Github":http://github.com/betajaen/nxogre/tree/master
# Click on the download link
# Then click on zip archive to download it to your computer
# Uncompress the contents of the archive to your development directory i.e. @c:/dev/@
# The folder name of NxOgre will be a bit strange ex. @betajaen-nxogre-8b032dd34625b7ebda0c343e8f98210e6a8354a5@ rename it to @NxOgre@ to have it a bit more meaning.

h2. Compile it.

Currently the Git versions has the build solutions for Visual Studio 2005 and Visual Studio 2008.

# Goto @c:/dev/NxOgre/build/msvc/@
# Double click on the solution to your IDE.
# Compile the NxOgre project

If you have any problems. 

* Make sure you've gone through all steps of all the items in the checklist. 
* Check of the "forums":http://nxogre.org/forums for anyone else having your problems.
* Make a post asking for help.

*/

#endif
