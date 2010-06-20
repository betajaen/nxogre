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

                                                                                       

#ifndef NXOGRE_SCENEFLAGS_H
#define NXOGRE_SCENEFLAGS_H

                                                                                       

namespace NxOgre
{

                                                                                       

/*! flags. SceneFlags
    desc.
        Flags
    enums.
        DisableSSE:0x1 -- Used to disable use of SSE in the solver.
        DisableCollisions:0x2 -- Disable all collisions in a scene.
        SimulateSeperateThread:0x4 -- Perform the simulation in a separate thread.
        EnableMultithread:0x8 -- Enable internal multi threading.
        EnableActiveTransforms:0x10 -- Enable Active Transform Notification.
        RestrictedScene:0x20 -- Enable Restricted Scene for Hardware scenes.
        DisableSceneMutex:0x40 -- Disable the mutex which serializes scene execution.
        ForceConeFriction:0x80 -- Force the friction model to cone friction
        SequentialPrimary:0x80*2 -- When enabled the compartments are all executed before the primary scene is executed.
        FluidPerformanceHint:0x80*4 -- Enables faster but less accurate fluid collision with static geometry.
        AlternativeFluidTriangleCollision:0x80*8 -- Enables an alternative fluid triangle-mesh collision CUDA kernel which could be signicantly faster in some scenarios.
        MultithreadedForcefield:0x80*16 -- Enables multi-threaded version of force field for fluids.
    default. SimulateSeperateThread|DisableSceneMutex
*/
struct SceneFlags
{

  // BEGIN - Serialisation
  // The following code is computer generated. Please do not modify.
  public:


   enum Flags
   {
    // Used to disable use of SSE in the solver.
    DisableSSE = 0x1,
    // Disable all collisions in a scene.
    DisableCollisions = 0x2,
    // Perform the simulation in a separate thread.
    SimulateSeperateThread = 0x4,
    // Enable internal multi threading.
    EnableMultithread = 0x8,
    // Enable Active Transform Notification.
    EnableActiveTransforms = 0x10,
    // Enable Restricted Scene for Hardware scenes.
    RestrictedScene = 0x20,
    // Disable the mutex which serializes scene execution.
    DisableSceneMutex = 0x40,
    // Force the friction model to cone friction
    ForceConeFriction = 0x80,
    // When enabled the compartments are all executed before the primary scene is executed.
    SequentialPrimary = 0x80*2,
    // Enables faster but less accurate fluid collision with static geometry.
    FluidPerformanceHint = 0x80*4,
    // Enables an alternative fluid triangle-mesh collision CUDA kernel which could be signicantly faster in some scenarios.
    AlternativeFluidTriangleCollision = 0x80*8,
    // Enables multi-threaded version of force field for fluids.
    MultithreadedForcefield = 0x80*16,
    // Default
    DefaultFlags = SimulateSeperateThread
   };

   SceneFlags() : flags(DefaultFlags) {}

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

   inline friend std::ostream& operator << (std::ostream& o, const SceneFlags& flags)
   {
    o << flags.flags;
    return o;
   }

   private: int flags;


  // END - Serialisation. "SceneFlags-b27cf62ed5103142581b487bcc8290cb"

};


                                                                                       

} // namespace NxOgre

                                                                                       

#endif
