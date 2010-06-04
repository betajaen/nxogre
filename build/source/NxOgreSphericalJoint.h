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

                                                                                       

#ifndef NXOGRE_SPHERICALJOINT_H
#define NXOGRE_SPHERICALJOINT_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreJoint.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass SphericalJoint : public Joint
{
  
  NXOGRE_GC_FRIEND_DELETE
  NXOGRE_GC_FRIEND_NEW3
  
  public: // Functions
  
  /** \brief Returns the current flag settings.
  */
  void                                        setProjectionMode(Enums::JointProjectionMode);
  
  /** \brief Sets the joint projection mode. 
  */
  Enums::JointProjectionMode                  getProjectionMode() const;

  /** \brief Get the type of joint
  */
  Enums::JointFunctionType                    getJointType();

  
  protected: // Functions
  
  /** \internal Private Constructor. Use Scene::createSphericalJoint.
  */
                                              SphericalJoint(RigidBody* first, RigidBody* second, const SphericalJointDescription&);
  
  /** \internal Private Destructor. Use Scene::destroyJoint.
  */
                                             ~SphericalJoint();
  
  protected: // Spherical
  
                         NxSphericalJoint*    mSphericalJoint;
  
}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
