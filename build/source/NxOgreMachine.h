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

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief A machine is a dynamic RigidBody, which has many parts that may be "rendered" or controlled seperatly. A vehicle
           is a type of machine.
*/
class NxOgrePublicClass Machine : public ActorMachinePart
{
  
  friend class Scene;
  template<class T> friend inline void Functions::safe_delete(T*);
  
  public: // Functions
  
  /** \brief Text
  */
                                              Machine(void);
  
  /** \brief Text
  */
                                             ~Machine(void);
  
  /** \brief Text
  */
  MachinePart*                                createWheelMachinePart(Wheel*, PointRenderable*);
  
  /** \brief
  */
  virtual void                                simulate(float user_deltaTime);
  
  
  /*! function. to_s
      desc.
          Returns the pointer and class type as string.
  */
  String to_s() const;
  
  struct MachinePartLambda
  {
   MachinePartLambda(float dt);
   void operator()(MachinePart*);
   float mDt;
  };

  struct MachineLambda
  {
   MachineLambda(float);
   void operator()(Machine*);
   float mDt;
  };

  protected: // Variables
  
  ptr_vector<MachinePart> mMachineParts;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
