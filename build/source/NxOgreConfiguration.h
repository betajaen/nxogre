#ifndef NXOGRE_MSWINDOWS_CONFIGURATION_H
#define NXOGRE_MSWINDOWS_CONFIGURATION_H
#define NXOGRE_HAS_CONFIGURATION

#include "NxOgreAutoConfiguration.h"

/*
  Debug options
  ===========================
  
  - Set to 0 to disable
  - Set to 1 to enable
  
*/
// Enable Memory Debugging.
#define NXOGRE_DEBUG_MEMORY 0
// File to write to.
#define NXOGRE_DEBUG_MEMORY_FILE nxogre.allocations.html
// Debug cooking processes
#define NXOGRE_DEBUG_COOKING 0
// Debug reading and writing to resources.
#define NXOGRE_DEBUG_RESOURCES 0
// Debug NxOgre Core. Constructor/Destruction of key classes.
#define NXOGRE_DEBUG_CORE 0
// Debug buffer<T> class.
#define NXOGRE_DEBUG_BUFFER 0
// Debug Meshes
#define NXOGRE_DEBUG_MESHES 0
// Debug HeightFields
#define NXOGRE_DEBUG_HEIGHTFIELDS 0
// Debug Cloth
#define NXOGRE_DEBUG_CLOTH 0
// Debug FlatYAML
#define NXOGRE_DEBUG_FLATYAML 0


/*
  NxOgreHasCharacterController
  ============================
  
  Enable use of the PhysX Character Controller.
   - Requires use of the NxCharacter.lib/NxCharacter.dll
*/
#define NxOgreHasCharacterController 0

/*
  NxOgreFloatingPointAccuracy
  ===========================
  
  Precision of a real number. This must be the same type as PhysX's NxReal.
  
  options:
   - NxOgreFloatingPointFloat
   - NxOgreFloatingPointDouble
   
*/
#define NxOgreFloatingPointAccuracy NxOgreFloatingPointFloat

/*
  NxOgreHasFluids
  ===============
  
  Enable (or disable) fluids.
  options
    - 1
    - 0
  note:
      This should be disabled in Linux.
*/
#define NxOgreHasFluids 1


#if NxOgrePlatform == NxOgrePlatformLinux
 // Linux PhysX does not have Fluids, it must be disabled.
 #define NxOgreHasFluids 0
#endif

/* 
  Minimal PhysX Version
  =====================

  Minimal PhysX version that NxOgre should adhere to, any features known
  not to exist before that will be disabled.
*/

#if NxOgrePlatform == NxOgrePlatformWindows
 // Public version for Windows on the Ageia website is at least 2.8.1
 #define NxOgreMinimalPhysXVersion 281
#elif NxOgrePlatform == NxOgrePlatformLinux
 // Public version for Linux on the NVidia website is PhysX 2.8.0 
 #define NxOgrePhysXVersion 280
#endif

#endif
