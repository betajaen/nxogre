/** File: NxOgreJointDescription.h
    Created on: 15-Apr-09
    Author: Robin Southern "betajaen"
    

    © Copyright, 2008-2009 by Robin Southern, http://www.nxogre.org

    This file is part of NxOgre.

    NxOgre is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    NxOgre is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with NxOgre.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NXOGRE_JOINTDESCRIPTION_H
#define NXOGRE_JOINTDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass JointDescription
{
  
  public: // Functions
  
  /** \brief Text
  */
                                              JointDescription(void);
  
  /** \brief Text
  */
  virtual                                    ~JointDescription(void);
  
  /** \brief Text
  */
  virtual void                                reset(void);
  
  /** \brief
  */
  virtual bool                                isValid(void) const;

  /** \brief
  */
  Vec3                                       mLocalNormal[2];
  
  
  /** \brief
  */
  Vec3                                       mLocalAxis[2];
  
  
  /** \brief
  */
  Vec3                                       mLocalAnchor[2];
  
  
  /** \brief
  */
  Real                                        mMaxForce;
  
  
  /** \brief
  */
  Real                                        mMaxTorque;
  
  /** \brief
  */
  Real                                        mSolverExtrapolationFactor;
  
  /** \brief
      \see NxJointDesc::useAccelerationSpring
      \default JointSpringType_Force
  */
  Enums::JointSpringType                      mSpringType;
  
  /** \brief Joint Flags, see Enums::JointFlag
      \note As with most flags, use the OR | operator to join flags together.
      \default Enums::JointFlag_Visualisation
      \see Enums::JointFlag
  */
  int                                         mJointFlags;
  
}; // class JointDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
