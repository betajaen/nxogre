/** File: NxOgrePrototypeFunctions.h
    Created on: 4-Nov-08
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

#ifndef NXOGRE_PROTOTYPE_FUNCTIONS_H
#define NXOGRE_PROTOTYPE_FUNCTIONS_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#ifdef NXOGRE_SDK
class NxPhysicsSDKDesc;
#endif

                                                                                       

namespace NxOgre
{

                                                                                       

namespace Functions
{

                                                                                       

class NxOgrePublicClass PrototypeFunctions
{
 public:

#ifdef NXOGRE_SDK
  /** \brief Copies all relevant WorldPrototype properties to a NxPhysicsSDKDesc
  */
  static void WorldPrototypeToNxPhysicsSDKDesc(WorldPrototype*, NxPhysicsSDKDesc&);
#endif

#ifdef NXOGRE_SDK
  /** \brief Copies all relevant ScenePrototype properties to a NxSceneDesc
  */
  static void ScenePrototypeToNxSceneDesc(ScenePrototype*, NxSceneDesc&);
#endif

#ifdef NXOGRE_SDK
  /** \brief Copies all relevant SceneDescription properties to a ScenePrototype
  */
  static void SceneDescriptionToScenePrototype(const SceneDescription&, ScenePrototype*);
#endif

  /** \brief
  */
  static void RigidBodyDescriptionToRigidBodyPrototype(const RigidBodyDescription&, RigidBodyPrototype*);

#ifdef NXOGRE_SDK
  /** \brief Copies all relevant RigidBodyPrototype properties to a NxActorDesc and NxBodyDesc.
             NxBodyDesc will be tied to the NxActorDesc if a mass is more than 1, otherwise it is ignored
             as well as coping it's properties from the prototype.
  */
  static void RigidBodyPrototypeToNxActorAndNxBodyDesc(RigidBodyPrototype*, NxActorDesc&, NxBodyDesc&);
#endif

  /** \brief Copies all relevant MaterialDescription properties to a MaterialPrototype.
  */
  static void MaterialDescriptionToMaterialPrototype(const MaterialDescription&, MaterialPrototype*);

#ifdef NXOGRE_SDK
  /** \brief Copies all relevant MaterialPrototype properties to a NxMaterialDesc.
  */
  static void MaterialPrototypeToNxMaterialDesc(MaterialPrototype*, NxMaterialDesc&);
#endif

#ifdef NXOGRE_SDK
  /** \brief Copies all relevant Joint properties to a NxJointDesc.
  */
  static void JointDescriptionToNxJointDescription(const JointDescription&, NxJointDesc&);
#endif

#ifdef NXOGRE_SDK
  /** \brief Copies all relevant SphericalJoint properties to a NxSphericalJointDesc.
  */
  static void SphericalJointDescriptionToNxSphericalJointDescription(const SphericalJointDescription&, NxSphericalJointDesc&);
#endif

#ifdef NXOGRE_SDK
  /** \brief Copies all relevant RevoluteJoint properties to a NxRevoluteJointDesc.
  */
  static void RevoluteJointDescriptionToNxRevoluteJointDescription(const RevoluteJointDescription&, NxRevoluteJointDesc&);
#endif

#ifdef NXOGRE_SDK
  /** \brief Copies all relevant Spring properties to a NxSpringDesc.
  */
  static void SpringDescriptionToNxSpringDesc(const SpringDescription&, NxSpringDesc&);
#endif

#ifdef NXOGRE_SDK
  /** \brief Copies all relevant Limit properties to a NxLimitDesc.
  */
  static void JointLimitDescriptionToNxJointLimitDesc(const JointLimitDescription&, NxJointLimitDesc&);
#endif


#ifdef NXOGRE_SDK
  /** \brief Copies all relevant Motor properties to a NxMotorDesc.
  */
  static void MotorDescriptionToNxMotorDesc(const MotorDescription&, NxMotorDesc&);
#endif


#ifdef NXOGRE_SDK
  /** \brief Copies all relevant D6 joint properties to a NxD6JointDesc.
  */
  static void D6JointDescriptionToNxD6JointDescription(const D6JointDescription&, NxD6JointDesc&);
#endif


#ifdef NXOGRE_SDK
  /** \brief Copies all relevant D6 joint properties to a NxD6JointDesc.
  */
  static void ClothDescriptionToNxClothDesc(const ClothDescription& source, NxClothDesc& desc);
#endif

#ifdef NXOGRE_SDK
  /** \brief Copies all relevant SoftBody properties to a NxSoftBodyDesc.
  */
  static void SoftBodyDescriptionToNxSoftBodyDesc(const SoftBodyDescription& source, NxSoftBodyDesc& desc);
#endif



}; // class ClassName


                                                                                       

} // namespace Functions
                                                                                       

} // namespace NxOgre

                                                                                       

#endif
