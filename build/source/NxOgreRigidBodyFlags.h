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

                                                                                       

#ifndef NXOGRE_RIGIDBODYFLAGS_H
#define NXOGRE_RIGIDBODYFLAGS_H

                                                                                       

namespace NxOgre
{

                                                                                       

/*! flags. RigidbodyFlags
    desc.
        Flags
    enums.
        DisableCollision:(1<<0)       -- Do not collide with other RigidBodies. Note this excludes from overlap tests.
        DisableResponse:(1<<1)        -- Disable collision response
        LockCOM:(1<<2)                -- Disable COM (Center of Mass) update when computing inertial properties at creation.
        DisableFluidCollision:(1<<3)  -- Disable Collision with fluids.
        ContactModification:(1<<4)    -- Turn on contact modification for the RigidBody.
        ForceConeFriction:(1<<5)      -- Force cone friction to be used with this RigidBody.
        UserActorPairFiltering:(1<<6) -- Enable custom contact filering.
    default. 0
*/
struct RigidbodyFlags
{

  // BEGIN - Serialisation
  // The following code is computer generated. Please do not modify.
  public:


   enum Flags
   {
    // Do not collide with other RigidBodies. Note this excludes from overlap tests.
    DisableCollision = (1<<0),
    // Disable collision response
    DisableResponse = (1<<1),
    // Disable COM (Center of Mass) update when computing inertial properties at creation.
    LockCOM = (1<<2),
    // Disable Collision with fluids.
    DisableFluidCollision = (1<<3),
    // Turn on contact modification for the RigidBody.
    ContactModification = (1<<4),
    // Force cone friction to be used with this RigidBody.
    ForceConeFriction = (1<<5),
    // Enable custom contact filering.
    UserActorPairFiltering = (1<<6),
    // Default
    DefaultFlags = 0
   };

   RigidbodyFlags() : flags(DefaultFlags) {}

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

   inline friend std::ostream& operator << (std::ostream& o, const RigidbodyFlags& flags)
   {
    o << flags.flags;
    return o;
   }

   private: int flags;


  // END - Serialisation. "RigidbodyFlags-b02b4929a6d29b617b373bfb4b680bfe"

};


                                                                                       

} // namespace NxOgre

                                                                                       

#endif
