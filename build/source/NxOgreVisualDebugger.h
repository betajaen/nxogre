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

                                                                                       

#ifndef NXOGRE_VISUALDEBUGGER_H
#define NXOGRE_VISUALDEBUGGER_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. VisualDebuggerDescription
    desc.
         Description to describe the VisualDebuggerDescription
*/
class NxOgrePublicClass VisualDebuggerDescription
{
  
  friend class RigidBody;
  
  public:
  
  VisualDebuggerDescription();
  
  void showMinimal();

  void showLight();

  void showDebug();
  
  void showAll();
  
  struct World
  {
   bool axes;
  } mWorld;

  struct RigidBody
  {
   bool actorAxes, bodyAxes, massAxes, linearVelocity, angularVelocity, jointGroups;
  } mRigidBody;

  struct Joint
  {
   bool worldAxes, limits;
  } mJoint;

  struct Contact
  {
   bool point, normal, error, force;
  } mContact;

  struct Collision
  {
   bool AABB, shapes, axes, compound, vNormals, fNormals, edges, spheres, staticPruning, dynamicPruning, freePruning, CCD, skeletons; 
  } mCollision;

  struct Fluid
  {
   bool emitters, position, kernelRadius, bounds, packets, motionLimit, dynamicCollision, staticCollision, meshPackets, drains, packetData;
  } mFluid;

  struct Cloth
  {
   bool mesh, collisions, selfCollisions, workPackets, sleeping, sleepVertex, tearableVertices, tearing, attachment, validBounds, hierarchy, hardStretchingLimitation;
  } mCloth;

  struct SoftBody
  {
   bool mesh, collisions, workPackets, sleeping, sleepVertex, tearableVertices, tearing, attachment, validBounds;
  } mSoftBody;
  
}; // class VisualDebuggerDescription


/** \brief VisualDebugger is an NxOgre implementation of the PhysX NxDebugRenderable and NX_VISUALIZE properties.
*/
class NxOgrePublicClass VisualDebugger
{
  
  public: // Functions
  
                                              VisualDebugger(World*);
  
                                             ~VisualDebugger();
  
  void                                        setRenderable(Renderable*);
  
  Renderable*                                 getRenderable();
  
  void                                        enable();
  
  void                                        disable();
  
  void                                        draw();
  
  void                                        loadFromDescription(const VisualDebuggerDescription&);
  
  void                                        saveToDescription(VisualDebuggerDescription&);

  protected: // Variables
  
  Renderable*                                 mRenderable;
  
  World*                                      mWorld;
  
  VisualDebuggerMeshData*                     mMeshData;

}; // class ClassName

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
