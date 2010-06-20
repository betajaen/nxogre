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



#ifndef NXOGRE_FUNCTIONS_H
#define NXOGRE_FUNCTIONS_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreDynamicRigidBodyFlags.h"

                                                                                       

namespace NxOgre
{

/*! class. VolumePhysicsFunction
    desc.
        A bunch of pre-made callbacks to be used with a Volume for common needs.
    note.
        You can use one PhysicsFunction for one Volume or shared with many, but it uses
        a reference counting system to automatically delete when it is no longer used.
    usage.
        bc. mScene->createVolume(..., VolumePhysicsFunction::raise_clear_flag(NxOgre::DynamicRigidbodyFlags::IgnoreGravity));
*/
class NxOgrePublicFunction VolumePhysicsFunction
{
   
  public:
   
  /*! function. raise_clear_flag
      desc.
          Raises or clears a flag of an Actor, under two events in the Volume.
      example.
          Set the no gravity flag when the Actor enters the volume and clears it when it leaves.
  */
  static Callback* raise_clear_flag(NxOgre::DynamicRigidbodyFlags::Flags flag, 
           NxOgre::Enums::VolumeCollisionType volume_raise_event = NxOgre::Enums::VolumeCollisionType_OnEnter,
           NxOgre::Enums::VolumeCollisionType volume_clear_event = NxOgre::Enums::VolumeCollisionType_OnExit);
   
  /*! function. move_to
      desc.
          Moves the actor towards a global position, whilst the actor is within side the volume
      example.
          Set the no gravity flag when the Actor enters the volume and clears it when it leaves.
  */
  static Callback* move_to(const Vec3& globalPosition, Real acceleration = Real(1.0));
  
  /*! function. teleport_to
      desc.
          Teleports the actor to a global position
      example.
          This could be used to teleport actors that leave a playing area, or something that goes out of bounds.
  */
  static Callback* teleport_to(const Vec3& globalPosition,
                               NxOgre::Enums::VolumeCollisionType teleport_event = NxOgre::Enums::VolumeCollisionType_OnEnter);
};

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
