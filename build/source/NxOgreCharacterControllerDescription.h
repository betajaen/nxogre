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

                                                                                       

#ifndef NXOGRE_CHARACTERCONTOLLERDESCRIPTION_H
#define NXOGRE_CHARACTERCONTOLLERDESCRIPTION_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#if NxOgreHasCharacterController == 1

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. BoxCharacterControllerDescription
*/
class NxOgrePublicClass CharacterControllerDescription
{
  
  public:
  
  /*! constructor. BoxDescription
      desc.
       Constructor, and resets the member variables to their default values according to the PhysX SDK.
  */
  CharacterControllerDescription();

  /*! function. reset
      desc.
          Resets the member variables to their default values according to the PhysX SDK.
  */
  void reset();
  
  /*! function. isValid
      desc. 
          Returns true if the description is valid.
  */
  bool isValid() const;

  /*! variable. mName
  */
  String        mName;

  /*! variable. mUpDirection.
      desc.
          Which is "up" to the character.
      default.
          Enums::Y
  */
  Enums::Axis   mUpDirection;

  /*! variable. mSlopeLimit
      desc.
          Maximum angle of a slope that the character controller can walk against.
      note.
          A value of 0 disables this feature.
      default.
          0.707 (Radians)
  */
  Radian mSlopeLimit;

  /*! variable. mSkinWidth
      desc.
          Skin around the character to avoid preceision issues.
      note.
          Must be small and positive value.
      default.
          0.1
  */
  Real mSkinWidth;

  /*! variable. mCallback
      desc.
          Pointer to a callback to alert when collision events occur.
      default.
          null, which is assumed to be World::getNullCallback() when the character controller is created.
  */
  Callback* mCallback;
  
  /*! variable. mInteractionFlag
      desc.
          Controls if a character controller collides with other controllers.
      default.
          Enums::CharacterControllerInteractionFlag_Include
  */
  Enums::CharacterControllerInteractionFlag  mInteractionFlag;
  
  /*! variable. mStepOffset
      desc.
          Maximum height of an obstacle which the character can climb.
      default.
          0.5
  */
  Real mStepOffset;
  
  /*! variable. mCapsuleEasyClimbing
      desc.
          If the controller is an capsule one, when climbing should it let
          the capsule climb over surfaces according to the impact normal (easy),
          or try to limit climbing according to the step offset (constrained)
      default.
          **false* -- Constrained climbing
  */
  bool mCapsuleEasyClimbing;
  
}; // class CharacterControllerDescription

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
#endif
