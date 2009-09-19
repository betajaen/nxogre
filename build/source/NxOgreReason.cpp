/** File: NxOgreReason.cpp
    Created on: 6-Nov-08
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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreReason.h"

                                                                                       

namespace NxOgre
{

                                                                                       

#define NXOGRE_CASE_STRING_RETURN(VAL, STR) case VAL: return STR; break;

const char* Reason::why(NxSDKCreateError error)
{
 switch (error)
 {
  NXOGRE_CASE_STRING_RETURN(NXCE_NO_ERROR, " - No errors occurred when creating the Physics SDK.\n");
  NXOGRE_CASE_STRING_RETURN(NXCE_PHYSX_NOT_FOUND, " - Unable to find the PhysX libraries. The PhysX drivers are not installed correctly.\n");
  NXOGRE_CASE_STRING_RETURN(NXCE_WRONG_VERSION, " - The application supplied a version number that does not match with the libraries.\n");
  NXOGRE_CASE_STRING_RETURN(NXCE_DESCRIPTOR_INVALID, "- The supplied SDK descriptor is invalid.\n");
  NXOGRE_CASE_STRING_RETURN(NXCE_CONNECTION_ERROR, " - A PhysX card was found, but there are problems when communicating with the card.\n");
  NXOGRE_CASE_STRING_RETURN(NXCE_RESET_ERROR, " - A PhysX card was found, but it did not reset (or initialize) properly.\n");
  NXOGRE_CASE_STRING_RETURN(NXCE_IN_USE_ERROR, " - A PhysX card was found, but it is already in use by another application.\n");
  NXOGRE_CASE_STRING_RETURN(NXCE_BUNDLE_ERROR, " - A PhysX card was found, but there are issues with loading the firmware.\n");
 }
 return " - Unknown NxSDKCreateError\n";
}

const char* Reason::toCStr(NxErrorCode error)
{
 switch (error)
 {
  NXOGRE_CASE_STRING_RETURN(NXE_NO_ERROR, "No Error");
  NXOGRE_CASE_STRING_RETURN(NXE_INVALID_PARAMETER,"A method called with invalid parameter(s)");
  NXOGRE_CASE_STRING_RETURN(NXE_INVALID_OPERATION,"A method was called at a time when an operation is not possible");
  NXOGRE_CASE_STRING_RETURN(NXE_OUT_OF_MEMORY,"A method failed to allocate some memory");
  NXOGRE_CASE_STRING_RETURN(NXE_INTERNAL_ERROR,"The library failed for some reason");
  NXOGRE_CASE_STRING_RETURN(NXE_ASSERTION,"An assertion failed");
  NXOGRE_CASE_STRING_RETURN(NXE_DB_INFO,"Information");
  NXOGRE_CASE_STRING_RETURN(NXE_DB_WARNING,"Warning");
  NXOGRE_CASE_STRING_RETURN(NXE_DB_PRINT,"Print");
 }
 return "Unknown NxErrorCode\n";
}

static const char*  sNxShapeEnumToString[NX_SHAPE_COUNT] = {
 "PlaneGeometry",
 "Sphere",
 "Box",
 "Capsule",
 "Wheel",
 "Convex",
 "TriangleMeshGeomtry",
 "HeightFieldGeometry",
 "InternalRawMesh"
};

SharedStringStream Reason::whyAsStream(const NxPhysicsSDKDesc& description)
{
  SharedStringStream stream;

  if (description.hwPageSize != 65536)
            //12345678901234567890123456789012345678901234567890123456789012345678901
   stream << "- Hardware page size (WorldDescription::mHardwarePageSize) is not 65536\n\tYou have " << description.hwPageSize << "\n";

  if (description.hwConvexMax & (description.hwConvexMax - 1) )
            //1234567890123456789012345678901234567890123456789012345678901234567890
   stream << "- Hardware maximum convex (WorldDescription::mHardwareMaximumConvex)\n"
             "  is not a power of two integer. You have '" << description.hwConvexMax << "'\n";

  if (description.hwPageMax & (description.hwPageMax - 1) )
             //12345678901234567890123456789012345678901234567890123456789012345
    stream << "- Hardware maximum page (WorldDescription::mHardwareMaximumPage)\n"
              "  is not a power of two integer. You have '" << description.hwPageMax << "'\n";

  if (stream.get() == 0)
   stream << "- Nothing seems to be wrong the SDK description\n";

  return stream;
};

SharedStringStream Reason::whyAsStream(const NxSceneDesc& description)
{
  SharedStringStream message;

  if(description.bpType==NX_BP_TYPE_SAP_MULTI)
  {
   if(!description.nbGridCellsX || !NxIsPowerOfTwo(description.nbGridCellsX) || description.nbGridCellsX>8)
   {          //12345678901234567890123456789012345678901234567890123456789012345
    message << "- Broadphase grid cells X is not a power or two number or higher\n"
               "  than 8. You have '" << description.nbGridCellsX << "'.\n";
   }

   if(!description.nbGridCellsY || !NxIsPowerOfTwo(description.nbGridCellsY) || description.nbGridCellsY>8)
   {
      message << "- Broadphase grid cells Y is not a power of two number or higher\n"
                 "   than 8. You have '" << description.nbGridCellsY << "'.\n";
   }

   if(!description.maxBounds)
    message <<  "- With a SAP multi broadphase type, MaxBounds is invalid\n";
  }

  if(description.maxTimestep <= 0)
   message << "- Maximum time-step is less than zero. You have '" << description.maxTimestep << "'\n";

  if (description.maxIter < 1)
   message << "- Maximum substeps is less than one. You have '" << description.maxIter << "'\n";

  if (description.timeStepMethod > NX_NUM_TIMESTEP_METHODS)
   message << "- Time step method is invalid. You have '" << description.timeStepMethod << "'\n";

  if(description.boundsPlanes && !description.maxBounds)
   message << "- Has bounds planes but no max bounds\n";


  if(description.staticStructure!=NX_PRUNING_STATIC_AABB_TREE && description.staticStructure!=NX_PRUNING_DYNAMIC_AABB_TREE)
  {
   message << "- Static structure is not Static AABB or Dynamic AABB.\n"
              "  You have '" << description.staticStructure << "'\n";
  }

  if(description.dynamicStructure==NX_PRUNING_OCTREE || description.dynamicStructure==NX_PRUNING_QUADTREE)
  {
   if(!description.maxBounds)
   {
    message << "- Scene has dynamic structure of a Pruning Octree or Quatree but\n"
               "  has no maximum bounds.\n";
   }

   if(description.dynamicStructure==NX_PRUNING_QUADTREE)
    if(description.upAxis!=1 && description.upAxis!=2)
     message << "- Wrong up axis used with a pruning quadtree dynamic strucutre\n";
  }

  if (description.dynamicTreeRebuildRateHint < 5)
   message << "- Dynamic Tree rebuild rate hint is less than five. You have '" << description.dynamicTreeRebuildRateHint << "'\n";

  if ((description.customScheduler!=NULL)&&(description.internalThreadCount>0))
   message << "- Scene is using a custom scheduler but the internal thread count is"
              "  not zero. You have '" << description.internalThreadCount << "'\n";

  if ((description.customScheduler!=NULL)&&(description.backgroundThreadCount>0))
   message << "- Scene is using a custom scheduler but the background thread count is"
              "  not zero. You have '" << description.backgroundThreadCount << "'\n";

  return message;

}

SharedStringStream Reason::whyAsStream(const NxActorDesc& description)
{
 SharedStringStream message;
  
  if (description.density < 0.0f)
   message << "- Density is less than zero. You have " << description.density << "\n";
 
  if (description.globalPose.isFinite() == false)
   message << "- Global Pose is not finite or malformed.\n";

  if (description.body && description.dominanceGroup)
   message << "- RigidBody has a dominance group, when it should not have one.\n";

  if (description.body == 0 && description.shapes.size())
   return message; // Bail out early. Everything else is related to body stuff, which static actors do not have.

  if (description.body->mass < 0.0f)
   message << "- Mass is less than zero. You have " << description.body->mass << "\n";
  
  if (description.body->wakeUpCounter < 0.0f)
   message << "- Wake up counter is less than zero. You have " << description.body->wakeUpCounter << "\n";

  if (description.body->linearDamping < 0.0f)
   message << "- Linear damping is less than zero. You have " << description.body->linearDamping << "\n";

  if (description.body->angularDamping < 0.0f)
   message << "- Angular damping is less than zero. You have " << description.body->angularDamping << "\n";

  if (description.body->CCDMotionThreshold < 0.0f)
   message << "- CCD Motion threshold is less than zero. You have " << description.body->CCDMotionThreshold  << "\n";

  if (description.body->solverIterationCount < 1)
   message << "- Solver iteration count must be more than zero. You have " << description.body->solverIterationCount << "\n";

  if (description.body->solverIterationCount > 255)
   message << "- Solver iteration count must be less than 255. You have " << description.body->solverIterationCount << "\n";

  if (description.body->contactReportThreshold < 0.0f)
   message << "- Contact report threshold is less than zero. You have " << description.body->contactReportThreshold  << "\n";

  if (description.body->massLocalPose.isFinite() == false)
   message << "- Mass local pose is not finite or malformed.\n";

  unsigned int nonTriggerShapes = 0;

  for (unsigned int i=0;i < description.shapes.size(); i++)
  {
   if (description.shapes[i]->isValid() == false)
   {
    message << "- Shape #" << i << " is not valid. It is a " << sNxShapeEnumToString[description.getType()] << "\n.";
   }
   if ((description.shapes[i]->shapeFlags & NX_TRIGGER_ENABLE) == 0)
    nonTriggerShapes++;
  }
  
  if (nonTriggerShapes == 0 && (!(description.body->flags & NX_BF_KINEMATIC)) && (description.body->mass < 0 || description.body->massSpaceInertia.isZero()))
   message << "- RigidBody is dynamic but has no non-trigger shapes. You have " << description.shapes.size() << " shapes of " << (description.shapes.size()-nonTriggerShapes) << " are trigger shapes.";

  bool isSolid = nonTriggerShapes > 0;
  bool hasDensity = description.density != 0.0f;
  bool hasMass = description.body->mass != 0.0f;


  if (hasMass && hasDensity)
   message << "- RigidBody has mass and density.\n";

  if (!hasMass && !hasDensity)
   message << "- RigidBody has no mass and density.\n";

  return message;
}

SharedStringStream Reason::whyAsStream(const NxHeightFieldDesc& description)
{
  SharedStringStream message;
  
  if (description.nbColumns < 2)
   message << "- Number of columns is less than 2. You have '" << description.nbColumns << "'\n";
  
  if (description.nbRows < 2)
   message << "- Number of rows is less than 2. You have '" << description.nbRows << "'\n";
  
  if (description.format == NX_HF_S16_TM)
   if (description.sampleStride < 4)
    message << "- Stride is less than 4 bytes with a NX_HF_S16_TM format\n";
  
  if (description.convexEdgeThreshold < 0)
   message << "- Convex edge threshold is less than 0. You have '" << description.convexEdgeThreshold << "'\n";
  
  if ((description.flags & NX_HF_NO_BOUNDARY_EDGES) != description.flags)
   message << "- Something about NX_HF_NO_BOUNDARY_EDGES'\n";
  
  if (description.verticalExtent !=0 && description.thickness != 0)
   message << "- VerticalExtent and Thickness are both not zero. You have '" << description.verticalExtent << "' and '" << description.thickness << "'\n";
  
 return message;
}


SharedStringStream Reason::whyAsStream(const NxJointLimitDesc& description, const char* sourceName)
{
 SharedStringStream message;
 
 if (description.restitution < 0 || description.restitution > 1)
  message << "- " << sourceName << " restitution is not in range\n";

 if (description.hardness < 0 || description.hardness > 1)
  message << "- " << sourceName << " hardness is not in range\n";

 return message;
}

SharedStringStream Reason::whyAsStream(const NxSpringDesc& description, const char* sourceName)
{
 SharedStringStream message;

 if (description.spring < 0)
  message << "- " << sourceName << " spring value is negative.\n";

 if (description.damper < 0)
  message << "- " << sourceName << " damper is negative.\n";

 return message;
}

SharedStringStream Reason::whyAsStream(const NxJointDesc& description)
{
 SharedStringStream message;
 
 if (description.actor[0] == description.actor[1])
  message << "- (NxJointDesc:1) RigidBody0 is the same as RigidBody1\n";

 if (description.actor[0] && ! description.actor[0]->isDynamic())
  message << "- (NxJointDesc:3) RigidBody0 must be dynamic\n";

 if (description.actor[1] && ! description.actor[1]->isDynamic())
  message << "- (NxJointDesc:4) RigidBody1 must be dynamic\n";

 for (unsigned int i=0; i<2;i++)
 {
  if (Math::abs(description.localAxis[i].magnitudeSquared() - 1.0f) > 0.1f)
   message << "- (NxJointDesc:7) LocalAxis " << i << "\n";
  if (Math::abs(description.localNormal[i].magnitudeSquared() - 1.0f) > 0.1f)
   message << "- (NxJointDesc:8) LocalNormal " << i << "\n";
  if (Math::abs(description.localAxis[i].dot(description.localNormal[i])) > 0.1f)
   message << "- (NxJointDesc:9) Orthogonal pairs " << i << "\n";
 }

 if (description.maxForce <= 0)
  message << "- (NxJointDesc:10) Max Force is zero or negative\n";

 if (description.maxTorque <= 0)
  message << "- (NxJointDesc:11) Max Force is zero or negative\n";

 if (description.solverExtrapolationFactor < 0.5 || description.solverExtrapolationFactor > 1.0f)
  message << "- (NxJointDesc:12) Solver Extrapolation Factor is not in range\n";

 return message;
}

SharedStringStream Reason::whyAsStream(const NxSphericalJointDesc& description)
{
 SharedStringStream message;
 
 message << whyAsStream((const NxJointDesc&) description).get();

 if (description.swingAxis.magnitudeSquared() < 0.9f)
  message << "- (NxSphericalJoint:1) Swing axis magnitude < 0.9\n";

 if (description.projectionDistance < 0.0f)
  message << "- (NxSphericalJoint:2) Projection distance is negative\n";

 message << whyAsStream(description.twistLimit.low, "Twist limit low");

 message << whyAsStream(description.twistLimit.low, "Twist limit high");

 message << whyAsStream(description.swingLimit, "Swing limit");

 message << whyAsStream(description.swingSpring, "Swing spring");

 message << whyAsStream(description.twistSpring, "Twist spring");

 message << whyAsStream(description.jointSpring, "Joint spring");

 return message;
}

SharedStringStream Reason::whyAsStream(const NxClothDesc& desc)
{
 SharedStringStream message;
 
 if (desc.clothMesh == 0)
  message << "- Mesh has not been assigned to the cloth\n";

 if(desc.globalPose.isFinite() == false)
  message << "- Global pose is malformed\n";

 if(desc.thickness < 0.0f)
  message << "- Thickness is negative.\n";

 if(desc.density <= 0.0f)
  message << "- Density is zero or negative.\n";

 if(desc.bendingStiffness < 0.0f || desc.bendingStiffness > 1.0f)
  message << "- Bending stiffness is not between 0 and 1.\n";

 if(desc.stretchingStiffness <= 0.0f || desc.stretchingStiffness > 1.0f)
  message << "- Streching stiffness is not between 0 and 1.\n";

 if(desc.pressure < 0.0f)
  message << "- Pressure is negative.\n";

 if(desc.tearFactor <= 1.0f)
  message << "- Tear factor is less than 1.\n";

 if(desc.attachmentTearFactor <= 1.0f)
  message << "- Attachment Tear factor is less than 1.\n";

 if(desc.solverIterations < 1)
  message << "- Solver iterations is less than 1.\n";

 if(desc.friction < 0.0f || desc.friction > 1.0f)
  message << "- Friction is not between 0 and 1.\n";

 if(desc.meshData.isValid() == false)
  message << "- Mesh data is invalid";

 if(desc.dampingCoefficient < 0.0f || desc.dampingCoefficient > 1.0f)
  message << "- Damping coefficient is not between 0 and 1.\n";

 if(desc.collisionResponseCoefficient < 0.0f)
  message << "- Collision response coefficient is negative.\n";

 if(desc.wakeUpCounter < 0.0f)
  message << "- Wakeup counter is negative.\n";

 if(desc.attachmentResponseCoefficient < 0.0f || desc.attachmentResponseCoefficient > 1.0f)
  message << "- Attachment response coefficient is between 0 and 1.\n";

 if(desc.toFluidResponseCoefficient < 0.0f)
  message << "- toFluidResponseCoefficient is negative.\n";

 if(desc.fromFluidResponseCoefficient < 0.0f)
  message << "- fromFluidResponseCoefficient is negative.\n";

 if(desc.minAdhereVelocity < 0.0f)
  message << "- minAdhereVelocity is negative.\n";

 if(desc.relativeGridSpacing < 0.01f)
  message << "- minAdhereVelocity is less than 0.01\n";

 if(desc.collisionGroup >= 32)
  message << "- collision group identifier is more than 31.\n";

 return message;
}


SharedStringStream Reason::whyAsStream(const NxSoftBodyDesc& desc)
{
 SharedStringStream message;
 
 if (desc.softBodyMesh == 0)
  message << "- Mesh has not been assigned to the cloth\n";

 if(desc.globalPose.isFinite() == false)
  message << "- Global pose is malformed\n";

 if(desc.particleRadius < 0.0f)
  message << "- Particle Radius is negative.\n";

 if(desc.density <= 0.0f)
  message << "- Density is zero or negative.\n";

 if(desc.volumeStiffness < 0.0f || desc.volumeStiffness > 1.0f)
  message << "- Volume stiffness is not between 0 and 1.\n";

 if(desc.stretchingStiffness <= 0.0f || desc.stretchingStiffness > 1.0f)
  message << "- Streching stiffness is not between 0 and 1.\n";

 if(desc.tearFactor <= 1.0f)
  message << "- Tear factor is less than 1.\n";

 if(desc.attachmentTearFactor <= 1.0f)
  message << "- Attachment Tear factor is less than 1.\n";

 if(desc.solverIterations < 1)
  message << "- Solver iterations is less than 1.\n";

 if(desc.friction < 0.0f || desc.friction > 1.0f)
  message << "- Friction is not between 0 and 1.\n";

 if(desc.meshData.isValid() == false)
  message << "- Mesh data is invalid";

 if(desc.dampingCoefficient < 0.0f || desc.dampingCoefficient > 1.0f)
  message << "- Damping coefficient is not between 0 and 1.\n";

 if(desc.collisionResponseCoefficient < 0.0f)
  message << "- Collision response coefficient is negative.\n";

 if(desc.wakeUpCounter < 0.0f)
  message << "- Wakeup counter is negative.\n";

 if(desc.attachmentResponseCoefficient < 0.0f || desc.attachmentResponseCoefficient > 1.0f)
  message << "- Attachment response coefficient is between 0 and 1.\n";

 if(desc.toFluidResponseCoefficient < 0.0f)
  message << "- toFluidResponseCoefficient is negative.\n";

 if(desc.fromFluidResponseCoefficient < 0.0f)
  message << "- fromFluidResponseCoefficient is negative.\n";

 if(desc.minAdhereVelocity < 0.0f)
  message << "- minAdhereVelocity is negative.\n";

 if(desc.relativeGridSpacing < 0.01f)
  message << "- minAdhereVelocity is less than 0.01\n";

 if(desc.collisionGroup >= 32)
  message << "- collision group identifier is more than 31.\n";

 return message;
}



SharedStringStream Reason::whyAsStream(const NxMaterialDesc& desc)
{
 SharedStringStream message;
 
 if(desc.dynamicFriction < 0.0f) 
  message << "- Dynamic friction is negative\n";

 if(desc.staticFriction < 0.0f) 
  message << "- Static friction is negative\n";

 if(desc.restitution < 0.0f || desc.restitution > 1.0f) 
  message << "- Restitution is not in range of (0..1)\n";

 if (desc.flags & NX_MF_ANISOTROPIC)
 {
  NxReal ad = desc.dirOfAnisotropy.magnitudeSquared();
  if (ad < 0.98f || ad > 1.03f)
    message << "- Direction of anistropy is invalid\n";

  if(desc.dynamicFrictionV < 0.0f) 
	  message << "- Dynamic frictionV is negative\n";

  if(desc.staticFrictionV < 0.0f) 
	  message << "- Static friction V is negative\n";

 }

 if (desc.frictionCombineMode >= NX_CM_N_VALUES)
  message << "- Incorrect flag for Friction combine mode\n";
 
 if (desc.restitutionCombineMode >= NX_CM_N_VALUES)
  message << "- Incorrect flag for restitution combine mode\n";

 return message;
}

#undef NXOGRE_CASE_STRING_RETURN

                                                                                       

} // namespace NxOgre

                                                                                       
