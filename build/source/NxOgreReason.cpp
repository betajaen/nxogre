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

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreReason.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

#define NXOGRE_CASE_STRING_RETURN(VAL, STR) case VAL: return STR; break;

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

const char* Reason::Exceptionise(int error)
{
 switch (error)
 {
  NXOGRE_CASE_STRING_RETURN(NXCE_NO_ERROR, " - No errors occurred when creating the Physics SDK.\n");
  NXOGRE_CASE_STRING_RETURN(NXCE_PHYSX_NOT_FOUND, " - Unable to find the PhysX libraries. The PhysX drivers are not installed correctly.\n");
  NXOGRE_CASE_STRING_RETURN(NXCE_WRONG_VERSION, " - The application supplied a version number that does not match with the libraries.\n");
  NXOGRE_CASE_STRING_RETURN(NXCE_DESCRIPTOR_INVALID, " - The supplied SDK descriptor is invalid.\n");
  NXOGRE_CASE_STRING_RETURN(NXCE_CONNECTION_ERROR, " - A PhysX card was found, but there are problems when communicating with the card.\n");
  NXOGRE_CASE_STRING_RETURN(NXCE_RESET_ERROR, " - A PhysX card was found, but it did not reset (or initialize) properly.\n");
  NXOGRE_CASE_STRING_RETURN(NXCE_IN_USE_ERROR, " - A PhysX card was found, but it is already in use by another application.\n");
  NXOGRE_CASE_STRING_RETURN(NXCE_BUNDLE_ERROR, " - A PhysX card was found, but there are issues with loading the firmware.\n");
 }
 return " - Unknown NxSDKCreateError\n";
}

const char* Reason::toCStr(int error)
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

String Reason::Exceptionise(const NxPhysicsSDKDesc& description, bool isSDKNull, int errorCode)
{
  
  StringStream stream;
  
  if (isSDKNull)
   stream << "The PhysX SDK is a null pointer. The reason(s) could be:\n";
  else
   stream << "Could not initialise the PhysX SDK. The reason(s) could be:\n";

  if (errorCode != NXE_NO_ERROR)
   stream << Exceptionise(errorCode);

  bool hasReason = false;

  if (description.hwPageSize != 65536)
  {
   stream << " - Hardware page size (WorldDescription::mHardwarePageSize) is not 65536\n"
             "   You have " << description.hwPageSize << "\n";
   hasReason = true;
  }

  if (description.hwConvexMax & (description.hwConvexMax - 1) )
  {
   stream << " - Hardware maximum convex (WorldDescription::mHardwareMaximumConvex) is not a power of two integer.\n"
             "   You have '" << description.hwConvexMax << "'\n";
   hasReason = true;
  }

  if (description.hwPageMax & (description.hwPageMax - 1) )
  {
   stream << " - Hardware maximum page (WorldDescription::mHardwareMaximumPage)\n"
              "   is not a power of two integer. You have '" << description.hwPageMax << "'\n";
   hasReason = true;
  }

  if (hasReason == false)
  {
   stream << " - The PhysX System Software may not be installed, or is installed incorrectly.\n";
  }

  return stream.str();
};

String Reason::Exceptionise(const NxSceneDesc& description, bool isSDKNull, const String& sceneName)
{
  StringStream message;
  
  message << "Could not create Scene. Reasons could be are:\n";
  
  if(description.bpType==NX_BP_TYPE_SAP_MULTI)
  {
   if(!description.nbGridCellsX || !NxIsPowerOfTwo(description.nbGridCellsX) || description.nbGridCellsX>8)
   {          //12345678901234567890123456789012345678901234567890123456789012345
    message << " - Broadphase grid cells X is not a power or two number or higher than 8.\n"
               "   You have '" << description.nbGridCellsX << "'.\n";
   }

   if(!description.nbGridCellsY || !NxIsPowerOfTwo(description.nbGridCellsY) || description.nbGridCellsY>8)
   {
      message << " - Broadphase grid cells Y is not a power of two number or higher than 8\n"
                 "   You have '" << description.nbGridCellsY << "'.\n";
   }

   if(!description.maxBounds)
    message <<  " - With a SAP multi broadphase type, MaxBounds is invalid\n";
  }

  if(description.maxTimestep <= 0)
  {
   message << " - Maximum time-step is less than zero.\n"
              "   You have '" << description.maxTimestep << "'\n";
  }

  if (description.maxIter < 1)
  {
   message << " - Maximum substeps is less than one.\n"
              "   You have '" << description.maxIter << "'\n";
  }

  if (description.timeStepMethod > NX_NUM_TIMESTEP_METHODS)
  {
   message << " - Time step method is invalid.\n"
              "   You have '" << description.timeStepMethod << "'\n";
  }

  if(description.boundsPlanes && !description.maxBounds)
   message << " - Has bounds planes but no max bounds\n";


  if(description.staticStructure!=NX_PRUNING_STATIC_AABB_TREE && description.staticStructure!=NX_PRUNING_DYNAMIC_AABB_TREE)
  {
   message << " - Static structure is not Static AABB or Dynamic AABB.\n"
              "   You have '" << description.staticStructure << "'\n";
  }

  if(description.dynamicStructure==NX_PRUNING_OCTREE || description.dynamicStructure==NX_PRUNING_QUADTREE)
  {
   if(!description.maxBounds)
   {
    message << " - Scene has dynamic structure of a Pruning Octree or Quatree but has no maximum bounds.\n";
   }

   if(description.dynamicStructure==NX_PRUNING_QUADTREE)
    if(description.upAxis!=1 && description.upAxis!=2)
     message << " - Wrong up axis used with a pruning quadtree dynamic structure\n";
  }

  if (description.dynamicTreeRebuildRateHint < 5)
  {
   message << " - Dynamic Tree rebuild rate hint is less than five.\n"
              "   You have '" << description.dynamicTreeRebuildRateHint << "'\n";
  }

  if ((description.customScheduler!=NULL)&&(description.internalThreadCount>0))
  {
   message << " - Scene is using a custom scheduler but the internal thread count is not zero.\n"
              "   You have '" << description.internalThreadCount << "'\n";
  }

  if ((description.customScheduler!=NULL)&&(description.backgroundThreadCount>0))
  {
   message << " - Scene is using a custom scheduler but the background thread count is not zero.\n"
              "   You have '" << description.backgroundThreadCount << "'\n";
  }
  
  return message.str();

}

String Reason::Exceptionise(const NxActorDesc& description)
{
  StringStream message;
  
  message << "Could not create RigidBody. Reasons could be are:\n";
  
  if (description.density < 0.0f)
   message << " - Density is less than zero.\n"
              "   You have " << description.density << "\n";
  
  if (description.globalPose.isFinite() == false)
   message << " - Global Pose is not finite or malformed.\n";
  
  if (description.body == 0 && description.dominanceGroup)
   message << " - RigidBody has a dominance group, when it should not have one.\n";

  if (description.body == 0 && description.shapes.size())
   return message.str(); // Bail out early. Everything else is related to body stuff, which static actors do not have.

  if (description.body->mass < 0.0f)
   message << " - Mass is less than zero.\n   You have " << description.body->mass << "\n";
  
  if (description.body->wakeUpCounter < 0.0f)
   message << " - Wake up counter is less than zero.\n   You have " << description.body->wakeUpCounter << "\n";

  if (description.body->linearDamping < 0.0f)
   message << " - Linear damping is less than zero.\n   You have " << description.body->linearDamping << "\n";

  if (description.body->angularDamping < 0.0f)
   message << " - Angular damping is less than zero.\n   You have " << description.body->angularDamping << "\n";

  if (description.body->CCDMotionThreshold < 0.0f)
   message << " - CCD Motion threshold is less than zero.\n   You have " << description.body->CCDMotionThreshold  << "\n";

  if (description.body->solverIterationCount < 1)
   message << " - Solver iteration count must be more than zero.\n   You have " << description.body->solverIterationCount << "\n";

  if (description.body->solverIterationCount > 255)
   message << " - Solver iteration count must be less than 255.\n   You have " << description.body->solverIterationCount << "\n";

  if (description.body->contactReportThreshold < 0.0f)
   message << " - Contact report threshold is less than zero.\n   You have " << description.body->contactReportThreshold  << "\n";

  if (description.body->massLocalPose.isFinite() == false)
   message << " - Mass local pose is not finite or malformed.\n";

  unsigned int nonTriggerShapes = 0;

  for (unsigned int i=0;i < description.shapes.size(); i++)
  {
   if (description.shapes[i]->isValid() == false)
   {
    message << " - Shape #" << i << " is not valid. It is a " << sNxShapeEnumToString[description.getType()] << "\n.";
   }
   if ((description.shapes[i]->shapeFlags & NX_TRIGGER_ENABLE) == 0)
    nonTriggerShapes++;
  }
  
  if (nonTriggerShapes == 0 && (!(description.body->flags & NX_BF_KINEMATIC)) && (description.body->mass < 0 || description.body->massSpaceInertia.isZero()))
   message << " - RigidBody is dynamic but has no non-trigger shapes.\n   You have " << description.shapes.size() << " shapes of " << (description.shapes.size()-nonTriggerShapes) << " are trigger shapes.";

  bool isSolid = nonTriggerShapes > 0;
  bool hasDensity = description.density != 0.0f;
  bool hasMass = description.body->mass != 0.0f;


  if (hasMass && hasDensity)
   message << " - RigidBody has mass and density.\n";

  if (!hasMass && !hasDensity)
   message << " - RigidBody has no mass and no density.\n";

  return message.str();
}

String Reason::Exceptionise(const NxHeightFieldDesc& description)
{
  StringStream message;
  
 message << "Could not create HeightField. Reasons could be are:\n";
 
  if (description.nbColumns < 2)
   message << " - Number of columns is less than 2. You have '" << description.nbColumns << "'\n";
  
  if (description.nbRows < 2)
   message << " - Number of rows is less than 2. You have '" << description.nbRows << "'\n";
  
  if (description.format == NX_HF_S16_TM)
   if (description.sampleStride < 4)
    message << " - Stride is less than 4 bytes with a NX_HF_S16_TM format\n";
  
  if (description.convexEdgeThreshold < 0)
   message << " - Convex edge threshold is less than 0. You have '" << description.convexEdgeThreshold << "'\n";
  
  if ((description.flags & NX_HF_NO_BOUNDARY_EDGES) != description.flags)
   message << " - Something about NX_HF_NO_BOUNDARY_EDGES'\n";
  
  if (description.verticalExtent !=0 && description.thickness != 0)
   message << " - VerticalExtent and Thickness are both not zero. You have '" << description.verticalExtent << "' and '" << description.thickness << "'\n";
  
 return message.str();
}


String Reason::Exceptionise(const NxJointLimitDesc& description, const char* sourceName)
{
 StringStream message;
 
 if (description.restitution < 0 || description.restitution > 1)
  message << " - " << sourceName << " restitution is not in range\n";

 if (description.hardness < 0 || description.hardness > 1)
  message << " - " << sourceName << " hardness is not in range\n";

 return message.str();
}

String Reason::Exceptionise(const NxSpringDesc& description, const char* sourceName)
{
 StringStream message;

 if (description.spring < 0)
  message << " - " << sourceName << " spring value is negative.\n";

 if (description.damper < 0)
  message << " - " << sourceName << " damper is negative.\n";

 return message.str();
}

String Reason::Exceptionise(const NxJointDesc& description)
{
 StringStream message;
 
 if (description.actor[0] == description.actor[1])
  message << " - RigidBody0 is the same as RigidBody1\n";

 if (description.actor[0] && ! description.actor[0]->isDynamic())
  message << " - RigidBody0 must be dynamic\n";

 if (description.actor[1] && ! description.actor[1]->isDynamic())
  message << " - RigidBody1 must be dynamic\n";

 for (unsigned int i=0; i<2;i++)
 {
  if (Math::abs(description.localAxis[i].magnitudeSquared() - 1.0f) > 0.1f)
   message << " - LocalAxis " << i << "\n";
  if (Math::abs(description.localNormal[i].magnitudeSquared() - 1.0f) > 0.1f)
   message << " - LocalNormal " << i << "\n";
  if (Math::abs(description.localAxis[i].dot(description.localNormal[i])) > 0.1f)
   message << " - Orthogonal pairs " << i << "\n";
 }

 if (description.maxForce <= 0)
  message << " - Max Force is zero or negative\n   You have '" << description.maxForce << "'.\n";

 if (description.maxTorque <= 0)
  message << " - Max Force is zero or negative\n   You have '" << description.maxTorque << "'.\n";

 if (description.solverExtrapolationFactor < 0.5 || description.solverExtrapolationFactor > 1.0f)
  message << " - Solver Extrapolation Factor should be between 0.5 and 1.0\n   You have '" << description.solverExtrapolationFactor << "'.\n";

 return message.str();
}

String Reason::Exceptionise(const NxRevoluteJointDesc& description)
{
 StringStream message;
 
 message << "Could not create RevoluteJoint. Reasons could be are:\n";
 
 message << Exceptionise((const NxJointDesc&) description);

 if (description.projectionDistance < 0.0f)
  message << " - Projection distance is negative\n";
 
 if (description.projectionAngle < 0.02f)
  message << " - Projection angle is to small\n";
 
 message << Exceptionise(description.limit.low, "Limit low");
 
 message << Exceptionise(description.limit.high, "Limit high");
 
 /// message << Exceptionise(description.motor, "Motor");
 
 message << Exceptionise(description.spring, "Spring");
 
 return message.str();
}

String Reason::Exceptionise(const NxSphericalJointDesc& description)
{
 StringStream message;
 
 message << "Could not create SphericalJoint. Reasons could be are:\n";
 
 message << Exceptionise((const NxJointDesc&) description);
 
 if (description.swingAxis.magnitudeSquared() < 0.9f)
  message << " - Swing axis magnitude < 0.9\n";
 
 if (description.projectionDistance < 0.0f)
  message << " - Projection distance is negative\n";
 
 message << Exceptionise(description.twistLimit.low, "Twist limit low");
 
 message << Exceptionise(description.twistLimit.low, "Twist limit high");
 
 message << Exceptionise(description.swingLimit, "Swing limit");
 
 message << Exceptionise(description.swingSpring, "Swing spring");
 
 message << Exceptionise(description.twistSpring, "Twist spring");
 
 message << Exceptionise(description.jointSpring, "Joint spring");
 
 return message.str();
}

String Reason::Exceptionise(const NxClothDesc& desc)
{
 StringStream message;
 
 message << "Could not create Cloth. Reasons could be are:\n";
 
 if (desc.clothMesh == 0)
  message << " - Mesh has not been assigned to the cloth\n";

 if(desc.globalPose.isFinite() == false)
  message << " - Global pose is malformed\n";

 if(desc.thickness < 0.0f)
  message << " - Thickness is negative.\n";

 if(desc.density <= 0.0f)
  message << " - Density is zero or negative.\n";

 if(desc.bendingStiffness < 0.0f || desc.bendingStiffness > 1.0f)
  message << " - Bending stiffness is not between 0 and 1.\n";

 if(desc.stretchingStiffness <= 0.0f || desc.stretchingStiffness > 1.0f)
  message << " - Streching stiffness is not between 0 and 1.\n";

 if(desc.pressure < 0.0f)
  message << " - Pressure is negative.\n";

 if(desc.tearFactor <= 1.0f)
  message << " - Tear factor is less than 1.\n";

 if(desc.attachmentTearFactor <= 1.0f)
  message << " - Attachment Tear factor is less than 1.\n";

 if(desc.solverIterations < 1)
  message << " - Solver iterations is less than 1.\n";

 if(desc.friction < 0.0f || desc.friction > 1.0f)
  message << " - Friction is not between 0 and 1.\n";

 if(desc.meshData.isValid() == false)
  message << " - Mesh data is invalid";

 if(desc.dampingCoefficient < 0.0f || desc.dampingCoefficient > 1.0f)
  message << " - Damping coefficient is not between 0 and 1.\n";

 if(desc.collisionResponseCoefficient < 0.0f)
  message << " - Collision response coefficient is negative.\n";

 if(desc.wakeUpCounter < 0.0f)
  message << " - Wakeup counter is negative.\n";

 if(desc.attachmentResponseCoefficient < 0.0f || desc.attachmentResponseCoefficient > 1.0f)
  message << " - Attachment response coefficient is between 0 and 1.\n";

 if(desc.toFluidResponseCoefficient < 0.0f)
  message << " - toFluidResponseCoefficient is negative.\n";

 if(desc.fromFluidResponseCoefficient < 0.0f)
  message << " - fromFluidResponseCoefficient is negative.\n";

 if(desc.minAdhereVelocity < 0.0f)
  message << " - minAdhereVelocity is negative.\n";

 if(desc.relativeGridSpacing < 0.01f)
  message << " - minAdhereVelocity is less than 0.01\n";

 if(desc.collisionGroup >= 32)
  message << " - collision group identifier is more than 31.\n";

 return message.str();
}


String Reason::Exceptionise(const NxSoftBodyDesc& desc)
{
 
 StringStream message;
 
 message << "Could not create SoftBody. Reasons could be are:\n";
 
 if (desc.softBodyMesh == 0)
  message << " - Mesh has not been assigned to the cloth\n";

 if(desc.globalPose.isFinite() == false)
  message << " - Global pose is malformed\n";

 if(desc.particleRadius < 0.0f)
  message << " - Particle Radius is negative.\n";

 if(desc.density <= 0.0f)
  message << " - Density is zero or negative.\n";

 if(desc.volumeStiffness < 0.0f || desc.volumeStiffness > 1.0f)
  message << " - Volume stiffness is not between 0 and 1.\n";

 if(desc.stretchingStiffness <= 0.0f || desc.stretchingStiffness > 1.0f)
  message << " - Streching stiffness is not between 0 and 1.\n";

 if(desc.tearFactor <= 1.0f)
  message << " - Tear factor is less than 1.\n";

 if(desc.attachmentTearFactor <= 1.0f)
  message << " - Attachment Tear factor is less than 1.\n";

 if(desc.solverIterations < 1)
  message << " - Solver iterations is less than 1.\n";

 if(desc.friction < 0.0f || desc.friction > 1.0f)
  message << " - Friction is not between 0 and 1.\n";

 if(desc.meshData.isValid() == false)
  message << " - Mesh data is invalid";

 if(desc.dampingCoefficient < 0.0f || desc.dampingCoefficient > 1.0f)
  message << " - Damping coefficient is not between 0 and 1.\n";

 if(desc.collisionResponseCoefficient < 0.0f)
  message << " - Collision response coefficient is negative.\n";

 if(desc.wakeUpCounter < 0.0f)
  message << " - Wakeup counter is negative.\n";

 if(desc.attachmentResponseCoefficient < 0.0f || desc.attachmentResponseCoefficient > 1.0f)
  message << " - Attachment response coefficient is between 0 and 1.\n";

 if(desc.toFluidResponseCoefficient < 0.0f)
  message << " - toFluidResponseCoefficient is negative.\n";

 if(desc.fromFluidResponseCoefficient < 0.0f)
  message << " - fromFluidResponseCoefficient is negative.\n";

 if(desc.minAdhereVelocity < 0.0f)
  message << " - minAdhereVelocity is negative.\n";

 if(desc.relativeGridSpacing < 0.01f)
  message << " - minAdhereVelocity is less than 0.01\n";

 if(desc.collisionGroup >= 32)
  message << " - collision group identifier is more than 31.\n";

 return message.str();
}



String Reason::Exceptionise(const NxMaterialDesc& desc)
{
 StringStream message;
 
 message << "Could not create Material. Reasons could be are:\n";
 
 if(desc.dynamicFriction < 0.0f) 
  message << " - Dynamic friction is negative\n";

 if(desc.staticFriction < 0.0f) 
  message << " - Static friction is negative\n";

 if(desc.restitution < 0.0f || desc.restitution > 1.0f) 
  message << " - Restitution is not in range of (0..1)\n";

 if (desc.flags & NX_MF_ANISOTROPIC)
 {
  NxReal ad = desc.dirOfAnisotropy.magnitudeSquared();
  if (ad < 0.98f || ad > 1.03f)
   message << " - Direction of anistropy is invalid\n";

  if(desc.dynamicFrictionV < 0.0f) 
   message << " - Dynamic frictionV is negative\n";

  if(desc.staticFrictionV < 0.0f) 
   message << " - Static friction V is negative\n";
 }

 if (desc.frictionCombineMode >= NX_CM_N_VALUES)
  message << " - Incorrect flag for Friction combine mode\n";
 
 if (desc.restitutionCombineMode >= NX_CM_N_VALUES)
  message << " - Incorrect flag for restitution combine mode\n";

 return message.str();
}

String Reason::Exceptionise(const Path& path, Enums::ResourceStatus status)
{
 
 return String();
}

#undef NXOGRE_CASE_STRING_RETURN

                                                                                       

} // namespace NxOgre

                                                                                       
