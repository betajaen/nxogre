/** File: NxOgreMaterialDescription.h
    Created on: 13-Nov-08
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

#ifndef NXOGRE_MATERIALDESCRIPTION_H
#define NXOGRE_MATERIALDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{
                                                                                       

/** \brief
*/
class NxOgrePublicClass MaterialDescription
{ 
  
  public: // Functions
  
  /** \brief MaterialDescription constructor, all it does is call MaterialDescription::reset.
  */
                                              MaterialDescription(void);
  
  /** \brief Resets everything to their default values, and pointers are set to NULL.
  */
  void                                        reset(void);
  
  /** \brief Returns if the variables are in a valid range or not.
  */
                        bool                  valid(void);

  /** \brief Coefficient of dynamic friction
      \range [0, inf].
      \note If set to greater than staticFriction, the effective value of
            staticFriction will be increased to match.
      \default 0
  */
                        Real                  mDynamicFriction;
  
  /** \brief Coefficient of dynamic friction
      \range [0, inf].
      \default 0
  */
                        Real                  mStaticFriction;
  
  /** \brief Coefficient of restitution (bounce)
      \range [0, 1].
      \default 0
  */
                        Real                  mRestitution;

  
  /** \brief Coefficient of dynamic friction
      \range [0, inf].
      \default 0
      \note If set to greater than staticFriction, the effective value of
            staticFriction will be increased to match.
  */
                        Real                  mVDynamicFriction;
  
  /** \brief Coefficient of dynamic friction
      \range [0, inf].
      \default 0
  */
                        Real                  mVStaticFriction;
  
  /** \brief Shape space direction (unit vector) of anisotropy.
             This is only used if flags & ANISOTROPIC is set.
      \default 1 0 0
  */
                        Vec3                 mDirectionOfAnisotropy;

  /** \brief
      \default 0
  */
                        unsigned int          mFlags;

  /** \brief
      \default CombineMode_Average
  */
                        Enums::CombineMode    mFrictionCombineMode;

  /** \brief
      \default CombineMode_Average
  */
                        Enums::CombineMode    mResitutionCombineMode;

 
 
}; // class ShapeDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
