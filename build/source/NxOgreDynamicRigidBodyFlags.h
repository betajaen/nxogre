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

                                                                                       

#ifndef NXOGRE_DYNAMICRIGIDBODYFLAGS_H
#define NXOGRE_DYNAMICRIGIDBODYFLAGS_H

                                                                                       

namespace NxOgre
{

                                                                                       

/*! flags. DynamicRigidbodyFlags
    desc.
        Flags
    enums.
         DisableGravity:1 -- Gravity should not be applied to this RigidBody.
         FreezePositionX:2 -- Freeze movement in the X axis.
         FreezePositionY:4 -- Freeze movement in the Y axis.
         FreezePositionZ:8 -- Freeze movement in the Z axis.
         FreezePosition:14 -- Freeze position in all axes.
         FreezeRotationX:16 -- Freeze rotation in the X axis.
         FreezeRotationY:32 -- Freeze rotation in the Y axis.
         FreezeRotationZ:64 -- Freeze rotation in the Z axis.
         FreezeRotation:112 -- Freeze rotation in all axis.
         Frozen:126 -- Freeze position and rotation, in a sense pretend to be like a KinematicActor or StaticGeometry for a period of time.
         Visualisation:256 -- Visualise the body component in the VisualDebugger.
         FilterSleepVelocity:1024 -- Filter sleep velocity.
         EnergySleepTest:2048 -- Enable energy-based sleepig algorithm.
    default. Visualisation
*/
struct DynamicRigidbodyFlags
{


  // BEGIN - Serialisation
  // The following code is computer generated. Please do not modify.
  public:


   enum Flags
   {
    // Gravity should not be applied to this RigidBody.
    DisableGravity = 1,
    // Freeze movement in the X axis.
    FreezePositionX = 2,
    // Freeze movement in the Y axis.
    FreezePositionY = 4,
    // Freeze movement in the Z axis.
    FreezePositionZ = 8,
    // Freeze position in all axes.
    FreezePosition = 14,
    // Freeze rotation in the X axis.
    FreezeRotationX = 16,
    // Freeze rotation in the Y axis.
    FreezeRotationY = 32,
    // Freeze rotation in the Z axis.
    FreezeRotationZ = 64,
    // Freeze rotation in all axis.
    FreezeRotation = 112,
    // Freeze position and rotation, in a sense pretend to be like a KinematicActor or StaticGeometry for a period of time.
    Frozen = 126,
    // Visualise the body component in the VisualDebugger.
    Visualisation = 256,
    // Filter sleep velocity.
    FilterSleepVelocity = 1024,
    // Enable energy-based sleepig algorithm.
    EnergySleepTest = 2048,
    // Default
    DefaultFlags = Visualisation
   };

   DynamicRigidbodyFlags() : flags(DefaultFlags) {}

   inline void reset() {flags = DefaultFlags;}

   inline void add(int flag) {flags |= flag;}

   inline void operator |=(int flag) {flags |= flag;}

   inline void operator +=(int flag) {flags |= flag;}

   inline void remove(int flag) {flags &= ~flag;}

   inline void operator -=(int flag) {flags &= ~flag;}

   inline bool has(int flag) const { return (flags & flag) == flag; }

   inline void from_i(int flag) { flags = flag; }

   inline int to_i() const { return flags; }

   inline operator int() { return flags; }

   inline String to_s() const
   {
    std::ostringstream o;
    o << flags;
    return o.str();
   }

   inline friend std::ostream& operator << (std::ostream& o, const DynamicRigidbodyFlags& flags)
   {
    o << flags.flags;
    return o;
   }

   private: int flags;


  // END - Serialisation. "DynamicRigidbodyFlags-fa9c0f5a753dc26237d41e2f9f75f1df"

};


                                                                                       

} // namespace NxOgre

                                                                                       

#endif
