/** Description: Configuration file for NxOgre for a Windows compiler.
    File: NxOgreConfiguration.h
    Created on: 3-Nov-03
    Author: Robin Southern "betajaen"
    
    
    © Copyright, 2008-2009 by Robin Southern, http://www.nxogre.org
    
    This file may be modified by the user and does not fall under the terms of the LGPL
*/

#ifndef NXOGRE_MSWINDOWS_CONFIGURATION_H
#define NXOGRE_MSWINDOWS_CONFIGURATION_H

#include "NxOgreCompiler.h"

/// Possible values of configuration.

#define NxOgreMemoryAllocatorMalloc    1
#define NxOgreMemoryAllocatorNedmalloc 2

#define NxOgreFloatingPointFloat      1
#define NxOgreFloatingPointDouble     2

/// Configuration

/** \brief What memory allocator to use.
    \default NxOgreMemoryAllocatorNedmalloc (Nedmalloc)
*/
#define NxOgreMemoryAllocator NxOgreMemoryAllocatorMalloc

/** \brief Precision of a real number.
    \default NxOgreMemoryAllocatorFloat (float)
*/
#define NxOgreFloatingPointAccuracy NxOgreFloatingPointFloat

/** \brief Allow reports of leaking memory.
    \note  When your application is in "release" mode; it is best to turn off the MemoryDebugger to be
           more professional and gain some minor speed increase and and some gain of some memory.
    \default 1 (yes)
*/
#define NxOgreMemoryDebugger 1

/** \brief Reserve a size of memory for the MemoryDebugger in bytes. The value set can gain a slightly faster startup, but
           a very high value could waste memory.
    \default 4080
    \note  The actual value will be rounded DOWN to the nearest 20. 
*/
#define NxOgreMemoryDebuggerInitialAllocationSize 4080

/** \brief MSWindowsFileResourceProtocol is the default protocol for "file", otherwise overridden by the user's app.
*/
#define NxOgreFileResourceProtocol MSWindowsFileResourceProtocol

/** \brief The header file for the default protocol for "file", otherwise overridden by the user's app.
*/
#define NxOgreFileResourceProtocolHeader "NxOgreMSWindowsFileResourceProtocol.h"

/** \brief Microsoft Windows is the platform is intended for.
*/
#define NxOgrePlatform NxOgrePlatformWindows

// Windows, Microsoft Visual C++ auto-config
#ifdef _MSC_VER
# ifndef NxOgreCompiler
#  define NxOgreCompiler NxOgreCompilerMSVC
# endif
# ifndef NxOgreArchitecture
#  ifdef _WIN64
#   define NxOgreArchitecture NxOgreArchitecture64Bit
#  else
#   define NxOgreArchitecture NxOgreArchitecture32Bit
#  endif
# endif
#endif

#ifndef NxOgreForceInline
# if (_MSC_VER>=1000)
#  define NxOgreForceInline __forceinline
# endif
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
  
  #define NXOGRE_DECLSPEC_OPTIONS_EXPORT 1
  #define NXOGRE_DECLSPEC_OPTIONS_IMPORT 2
  #define NXOGRE_DECLSPEC_OPTIONS_AVOID  3
  
  #ifdef NXOGRE_OPTIONS_DYNAMIC_LIBRARY
  #  define NXOGRE_DECLSPEC_OPTIONS NXOGRE_DECLSPEC_OPTIONS_EXPORT
  #endif
  
  #ifdef NXOGRE_OPTIONS_STATIC_LIBRARY
  #  define NXOGRE_DECLSPEC_OPTIONS NXOGRE_DECLSPEC_OPTIONS_AVOID
  #endif
  
  #ifndef NXOGRE_DECLSPEC_OPTIONS
  #  define NXOGRE_DECLSPEC_OPTIONS NXOGRE_DECLSPEC_OPTIONS_IMPORT
  #endif

  #if (NXOGRE_DECLSPEC_OPTIONS == NXOGRE_DECLSPEC_OPTIONS_EXPORT)
  #  define NxOgrePublicClass    __declspec(dllexport)
  #  define NxOgrePublicFunction __declspec(dllexport)
  #endif
  
  #if (NXOGRE_DECLSPEC_OPTIONS == NXOGRE_DECLSPEC_OPTIONS_IMPORT)
  #  define NxOgrePublicClass    __declspec(dllimport)
  #  define NxOgrePublicFunction __declspec(dllimport)
  #endif
  
  #if (NXOGRE_DECLSPEC_OPTIONS == NXOGRE_DECLSPEC_OPTIONS_AVOID)
  #  define NxOgrePublicClass
  #  define NxOgrePublicFunction
  #endif
  
#endif

                                                                                       

#define NXOGRE_HAS_CONFIGURATION

#endif
