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

                                                                                       

#ifndef NXOGRE_MACHINE_H
#define NXOGRE_MACHINE_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreActorMachinePart.h"
#include "NxOgreCommonMachineParts.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. Machine
    desc. A machine is a dynamic RigidBody, which has many parts that may be "rendered" or controlled seperatly. A vehicle
          is a type of machine. All Machines inherit from ActorMachinePart, so they have an Actor and PointRenderable as
          a basis. Further MachineParts then can be created and added to this Machine.
*/
class NxOgrePublicClass Machine : public ActorMachinePart
{
  
  public: // Functions
  
  typedef vector<MachinePart*>           MachineParts;
  typedef vector_iterator<MachinePart*>  MachinePartIterator;
  
  /*! constructor. Machine
  */
  Machine();
  
  /*! destructor. Machine
  */
 ~Machine();
  
  /*! function. createWheelMachinePart
      desc.
          Create a machine wheel part (add add it to this machine), based on an existing Wheel and PointRenderable.
  */
  WheelMachinePart* createWheelMachinePart(Wheel*, PointRenderable*);
  
  /*! function. createMoverMachinePart
      desc.
          Create a machine wheel part (add add it to this machine), based on an existing Wheel and PointRenderable.
      note.
          If interval is 0, then it is fired every TimeStep.
  */
  MoverMachinePart* createMoverMachinePart(const Vec3& force, float interval = 0, Enums::ForceMode = Enums::ForceMode_Impulse);
  
  /*! function. createRotatorMachinePart
      desc.
          Create a machine wheel part (add add it to this machine), based on an existing Wheel and PointRenderable.
      note.
          If interval is 0, then it is fired every TimeStep.
  */
  RotatorMachinePart* createRotatorMachinePart(const Vec3& torque, float interval = 0, Enums::ForceMode = Enums::ForceMode_Impulse);
  
  /*! function. addMachinePart
      desc.
          Add a machine part.
      note.
          The MachinePart pointer is garbaged collected automatically by the Machine destructor.
  */
  void addMachinePart(MachinePart*);
  
  /*! function. addMachinePart
      desc.
          Add a machine part.
      note.
          The MachinePart pointer is garbaged collected automatically by the Machine destructor.
  */
  void removeMachinePart(MachinePart*);
  
  /*! function. getMachineParts
      desc.
          Get machine parts attached this machine
  */
  MachinePartIterator getMachineParts();
  
  /*! function. simulate
      desc.
       User code to process logic, and physics before the scene state is updated.
      args.
       float userDeltaTime -- Time passed since last timestep.
      note.
       This is automatically called (by the Scene), once TimeController::advance is called.
  */
  void simulate(float userDeltaTime);
  
  /*! function. render
      desc.
       User code to commit changes to the render system, after the scene state was updated.
      args.
       float userDeltaTime -- Time passed since last timestep.
      note.
       This is automatically called (by the Scene), once TimeController::advance is called.
  */
  void render(float userDeltaTime);

  /*! function. to_s
      desc.
          Returns the pointer and class type as string.
  */
  String to_s() const;
  
  protected: // Variables
   
   MachineParts         mMachineParts;
   
   MachinePartIterator  mMachinePartIterator;
   
}; // class Machine

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
