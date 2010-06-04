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

                                                                                       

#ifndef NXOGRE_AUTOCONFIGURATION_H
#define NXOGRE_AUTOCONFIGURATION_H

#define NxOgreMemoryAllocatorMalloc 1
#define NxOgreMemoryAllocatorNedmalloc 2

#define NxOgreFloatingPointFloat 1
#define NxOgreFloatingPointDouble 2
#define NxOgreCompilerUnknown 0
#define NxOgreCompilerMSVC 1
#define NxOgreCompilerGNUC 2

#define NxOgrePlatformUnknown 0
#define NxOgrePlatformWindows 1
#define NxOgrePlatformLinux 2

#define NxOgreArchitecture32Bit 32
#define NxOgreArchitecture64Bit 64

#define NXOGRE_EXPORT_OPTIONS_EXPORT 1
#define NXOGRE_EXPORT_OPTIONS_IMPORT 2
#define NXOGRE_EXPORT_OPTIONS_AVOID 3

#if defined (_MSC_VER)
# define NxOgreCompiler NxOgreCompilerMSVC
#elif defined ( __GNUC__ )
# define NxOgreCompiler NxOgreCompilerGNUC
#endif

#if defined (_WIN32) || defined (__WIN32)
# define NxOgrePlatform NxOgrePlatformWindows
#elif defined (LINUX) || defined(_LINUX)
# define NxOgrePlatform NxOgrePlatformLinux
#endif

#if defined(_M_X64) || defined (_M_X64)
# define NxOgreArchitecture NxOgreArchitecture64Bit
#else
# define NxOgreArchitecture NxOgreArchitecture32Bit
#endif


// NxOgreArray.h generates this warning - a lot.
#pragma warning (disable : 4251)

// NxOgreSingleton.h and other classes that inherit generate this warning in Visual Studio.
#pragma warning (disable : 4661)

// Occurs when inheriting from a PhysX class.
#pragma warning (disable : 4275)

// Conversion from 'double' to 'float', possible loss of data
#pragma warning (disable : 4244)

// forcing value to bool 'true' or 'false' (performance warning)
#pragma warning (disable : 4800)

// 'fopen': This function or variable may be unsafe. Consider using fopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.
#pragma warning (disable : 4996)

#if (NxOgreCompiler == NxOgreCompilerMSVC)
 
 #define NxOgreForceInline __forceinline
 
 #ifdef NXOGRE_DYNAMIC_LIBRARY
 # define NXOGRE_EXPORT_OPTIONS NXOGRE_EXPORT_OPTIONS_EXPORT
 #endif

 #ifdef NXOGRE_STATIC_LIBRARY
 # define NXOGRE_EXPORT_OPTIONS NXOGRE_EXPORT_OPTIONS_AVOID
 #endif

 #ifndef NXOGRE_EXPORT_OPTIONS
 # define NXOGRE_EXPORT_OPTIONS NXOGRE_EXPORT_OPTIONS_IMPORT
 #endif

 #if (NXOGRE_EXPORT_OPTIONS == NXOGRE_EXPORT_OPTIONS_EXPORT)
 # define NxOgrePublicClass __declspec(dllexport)
 # define NxOgrePublicFunction __declspec(dllexport)
 # define NxOgrePublicTemplateClass
 #endif

 #if (NXOGRE_EXPORT_OPTIONS == NXOGRE_EXPORT_OPTIONS_IMPORT)
 # define NxOgrePublicClass __declspec(dllimport)
 # define NxOgrePublicFunction __declspec(dllimport)
 # define NxOgrePublicTemplateClass
 #endif

 #if (NXOGRE_EXPORT_OPTIONS == NXOGRE_EXPORT_OPTIONS_AVOID)
 # define NxOgrePublicClass
 # define NxOgrePublicFunction
 # define NxOgrePublicTemplateClass
 #endif


#endif

#if (NxOgreCompiler == NxOgreCompilerGNUC)
# define NxOgreForceInline __inline
# define NxOgrePublicClass
# define NxOgrePublicFunction
#endif

#if defined(_DEBUG) || defined(DEBUG)
# ifndef NXOGRE_DEBUG
#  define NXOGRE_DEBUG
# endif
#endif

#endif
