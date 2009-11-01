/** 
    
    This file is part of NxOgre.
    
    Copyright (c) 2009 Robin Southern, http://www.nxogre.org
    
    
*/

                                                                                       

#ifndef NXOGRE_MSWINDOWS_CONFIGURATION_H
#define NXOGRE_MSWINDOWS_CONFIGURATION_H
#define NXOGRE_HAS_CONFIGURATION

/******************************************************************************************
 *                                                                                        *
 *                                                                                        *
 *                            USER CONFIGURATION                                          *
 *                                                                                        *
 *                                                                                        *
 ******************************************************************************************/

/** \brief What memory allocator to use.
    \default NxOgreMemoryAllocatorNedmalloc (Nedmalloc)
*/
#define NxOgreMemoryAllocator NxOgreMemoryAllocatorNedmalloc

/** \brief Precision of a real number, much match PhysX's NxReal
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

                                                                                       


#endif
