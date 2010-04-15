/** 
    
    This file is part of NxOgre.
    
    Copyright (c) 2009 Robin Southern, http://www.nxogre.org
    
    This file is under public domain and may be modified by the user.
    
*/

/* page. NxOgreAllocatables_h
   
   NxOgreAllocatables.h is a set of typedefs allowing the user to specify an alternate preferred
   way of allocating memory for NxOgre and PhysX classes. By default the MallocAllocator provided
   in the NxOgre is the default allocator, but by bringing in extra code or modifying the MallocAllocator
   the user can change the behaviour of memory allocation.
   
   Example:
   
   bc. typedef Allocator<MallocAllocator>                  GenericBasedAllocator;
   
   The GenericBasedAllocatable which uses the GenericBasedAllocator (which is the MallocAllocator)
   to allocate memory when the class is new'd or deleted.
   
   This can be changed by altering the typedef to the preferred allocator.
   
   bc. typedef Allocator<MyAllocator>                  GenericBasedAllocator;
   
   Now all classes that inherit GenericBasedAllocatable now use the MyAllocator to allocate
   memory. As you can probably see this has more advantages than personally altering each
   NxOgre class to handle memory allocation behaviour in the way you want it to be.
*/

                                                                                       

#ifndef NXOGRE_ALLOCATABLES_H
#define NXOGRE_ALLOCATABLES_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreAllocator.h"

#include "NxOgreMallocAllocator.h"

                                                                                       

namespace NxOgre
{

                                                                                       

// Anything that doesn't fit in the other allocators.
typedef Allocator<MallocAllocator>                  GenericBasedAllocator;
typedef Allocatable<GenericBasedAllocator>          GenericBasedAllocatable;

// All PhysX classes and memory
typedef Allocator<MallocAllocator>                  PhysXClassAllocator;
typedef Allocatable<PhysXClassAllocator>            PhysXClassAllocatable;

// Worlds, Singletons and Scenes
typedef Allocator<MallocAllocator>                  BigClassAllocator;
typedef Allocatable<BigClassAllocator>              BigClassAllocatable;

// Archives, Resources, Meshes and HeightFields
typedef Allocator<MallocAllocator>                  ResourceAllocator;
typedef Allocatable<ResourceAllocator>              ResourceAllocatable;

// All Shapes.
typedef Allocator<MallocAllocator>                  ShapeAllocator;
typedef Allocatable<ShapeAllocator>                 ShapeAllocatable;

// RigidBodies and inherited classes.
typedef Allocator<MallocAllocator>                  RigidBodyBasedAllocator;
typedef Allocatable<RigidBodyBasedAllocator>        RigidBodyBasedAllocatable;

// Big RigidBody-like classes: Forcefields, SoftBodies, Cloths and Fluids
typedef Allocator<MallocAllocator>                  NonRigidBodyBasedAllocator;
typedef Allocatable<NonRigidBodyBasedAllocator>     NonRigidBodyBasedAllocatable;

// Joints
typedef Allocator<MallocAllocator>                  JointBasedAllocator;
typedef Allocatable<JointBasedAllocator>            JointBasedAllocatable;

// Classes that frequency create, resize or delete memory of fixed sizes, i.e. the Buffer.
typedef Allocator<MallocAllocator>                  FrequentOperationsAllocator;
typedef Allocatable<FrequentOperationsAllocator>    FrequentOperationsAllocatable;

// Classes/Memory that is exactly 16 bytes in size.
typedef Allocator<MallocAllocator>                  SixteenBytesAllocator;
typedef Allocatable<SixteenBytesAllocator>          SixteenBytesAllocatable;

// Classes/Memory that is exactly 4 bytes in size.
typedef Allocator<MallocAllocator>                  FourByteAllocator;
typedef Allocatable<FourByteAllocator>              FourByteAllocatable;

// STL classes, or classes that wrap them.
typedef Allocator<MallocAllocator>                  STLBasedAllocator;
typedef Allocatable<STLBasedAllocator>              STLBasedAllocatable;

// Classes outside of the NxOgre namespace may wish to inherit from this.
typedef Allocator<MallocAllocator>                  UserExtendedClassAllocator;
typedef Allocatable<UserExtendedClassAllocator>     UserExtendedClassAllocatable;

// Classes outside of the NxOgre namespace that manage NxOgre classes may want to use this.
typedef Allocator<MallocAllocator>                  UserBigClassAllocator;
typedef Allocatable<UserExtendedClassAllocator>     UserBigClassAllocatable;

// ForceFields and related/inherited classes.
typedef Allocator<MallocAllocator>                  ForceFieldBasedAllocator;
typedef Allocatable<RigidBodyBasedAllocator>        ForceFieldBasedAllocatable;


                                                                                       

} // namespace NxOgre

                                                                                       

#endif
