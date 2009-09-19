/** File: NxOgreReason.h
    Created on: 06-Nov-08
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

#ifndef NXOGRE_REASON_H
#define NXOGRE_REASON_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#ifdef NXOGRE_SDK
# include "NxPhysics.h"
#endif

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief Reason is a collection of static functions that turns descriptions and error codes
           into why they could be invalid.
*/
class NxOgrePublicClass Reason
{
public:

#if NXOGRE_SDK
  static const char* why(NxSDKCreateError);
#endif

#if NXOGRE_SDK
  static const char* toCStr(NxErrorCode);
#endif

#if NXOGRE_SDK
  static SharedStringStream whyAsStream(const NxPhysicsSDKDesc&);
#endif

#if NXOGRE_SDK
  static SharedStringStream whyAsStream(const NxSceneDesc&);
#endif

#if NXOGRE_SDK
  static SharedStringStream whyAsStream(const NxActorDesc&);
#endif

#if NXOGRE_SDK
  static SharedStringStream whyAsStream(const NxMaterialDesc&);
#endif

#if NXOGRE_SDK
  static SharedStringStream whyAsStream(const NxHeightFieldDesc&);
#endif

#if NXOGRE_SDK
  static SharedStringStream whyAsStream(const NxJointLimitDesc&, const char* sourceName);
#endif

#if NXOGRE_SDK
  static SharedStringStream whyAsStream(const NxSpringDesc&, const char* sourceName);
#endif

#if NXOGRE_SDK
  static SharedStringStream whyAsStream(const NxJointDesc&);
#endif

#if NXOGRE_SDK
  static SharedStringStream whyAsStream(const NxSphericalJointDesc&);
#endif

#if NXOGRE_SDK
  static SharedStringStream whyAsStream(const NxClothDesc&);
#endif

#if NXOGRE_SDK
  static SharedStringStream whyAsStream(const NxSoftBodyDesc&);
#endif

}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
