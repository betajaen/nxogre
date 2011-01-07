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

                                                                                       

#ifndef NXOGRE_DISTANCEJOINT_H
#define NXOGRE_DISTANCEJOINT_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreJoint.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. DistanceJoint
    desc.
        The distance joint tries to maintain a certain minimum and/or maximum distance between two points
        attached to a pair of actors. It can be set to springy in order to behave like a rubber band.
*/
class NxOgrePublicClass DistanceJoint : public Joint
{
  
  NXOGRE_GC_FRIEND_NEW3
  NXOGRE_GC_FRIEND_DELETE
  
  public: // Functions
  
  
  protected: // Functions
  
  /** \internal Private Constructor. Use Scene::createDistanceJoint.
  */
                                              DistanceJoint(RigidBody* first, RigidBody* second, const DistanceJointDescription&);
  
  /** \internal Private Destructor. Use Scene::destroyJoint.
  */
                                             ~DistanceJoint();
  
  protected: // Protected
  
                         NxDistanceJoint*     mDistanceJoint;
  
}; // class DistanceJoint

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
