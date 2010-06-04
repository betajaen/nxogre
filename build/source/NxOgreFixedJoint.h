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

                                                                                       

#ifndef NXOGRE_FIXEDJOINT_H
#define NXOGRE_FIXEDJOINT_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreJoint.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. FixedJoint
    desc.
        A FixedJoint is a constraint between two actors with no angular or linear degrees of freedom.
*/
class NxOgrePublicClass FixedJoint : public Joint
{
  
  NXOGRE_GC_FRIEND_DELETE
  NXOGRE_GC_FRIEND_NEW3
  
  public: // Functions
  
  /*! function. getJointType
      desc.
          Get the type of joint.
      return.
          **Enums::JointFunctionType** -- Always returns Enums::JointFunctionType_Fixed
  */
  Enums::JointFunctionType                    getJointType();
  
  protected: // Functions
  
  /*! constructor. FixedJoint
      desc.
           Fixed Joint constructor.
      note.
          Use Scene::createFixedJoint.
      args.
          RigidBody* __first__ -- First RigidBody
          RigidBody* __second__ -- First RigidBody
          const FixedJointDescription& __description__ -- Initial joint properties
      !protected
  */
                                              FixedJoint(RigidBody* first, RigidBody* second, const FixedJointDescription&);
  
  /*! destructor. FixedJoint
      desc.
           Fixed Joint destructor.
      note.
           Use Scene::destroyJoint.
  */
                                             ~FixedJoint();
  
  protected: // Fixed
  
  NxFixedJoint*  mFixedJoint;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
