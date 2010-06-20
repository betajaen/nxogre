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

                                                                                       

#ifndef NXOGRE_CLOTH_H
#define NXOGRE_CLOTH_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreTimeListener.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/*! class. Cloth
    desc.
         Cloth is an instance of a **Mesh** containg a Cloth.
         
         p. Generally speaking a Cloth is "rendered" through a RenderSystem which
            may or may not have a specific function for creating and setting up
            the cloth for you -- You should refer to that.
*/
class NxOgrePublicClass Cloth : public NonRigidBodyBasedAllocatable, public TimeListener
{
  
  NXOGRE_GC_FRIEND_NEW4
  NXOGRE_GC_FRIEND_DELETE
  
  public:
  
  /*! function. getRenderable
      desc.
           Get the renderable that the cloth is rendering to.
      return.
           **Renderable** * -- The renderable the cloth is rendering to.
      see. Renderable
  */
  Renderable*                                 getRenderable();

  /*! function. getMesh
      desc.
           Get the mesh that the cloth is using.
      note.
           This mesh is owned by the MeshManager, and may be shared by other cloths, do
           not delete the pointer or change the mesh.
      return.
           **Mesh** * -- Mesh that the cloth is using.
      see. Mesh
  */
  Mesh*                                       getMesh();
  
  /*! function. getPhysXCloth
      desc.
           Get the NxCloth instance.
      !physx
      return.
           **NxCloth** * -- NxCloth instance of this Cloth.
  */
  NxCloth*                                    getPhysXCloth();

  /*! function. getMeshRenderable
      desc.
           Get the MeshRenderable instance.
      note.
           This mesh is owned by the Cloth; do not delete the pointer.
      return.
           **MeshRenderable** * -- MeshRenderable used by the cloth.
      see. MeshRenderable
  */
  MeshRenderable*                              getMeshRenderable();

  /*! function. getName
      desc.
           Get the name of the cloth or BLANK_STRING
      return.
           **String** -- The name of the cloth.
  */
  String                                      getName() const;

  /*! function. getName
      desc.
           Get the name of the cloth or BLANK_STRING
      return.
           **String** -- The name of the cloth.
  */
  StringHash                                   getNameHash() const;

  /*! function. setBendingStiffness
      desc.
           Sets the cloth bending stiffness.
      args.
          Real __stiffness__ -- Bending stiffness; [0, 1].
      see. Cloth::getBendingStiffness
  */
  void                                        setBendingStiffness(Real stiffness);

  /*! function. getBendingStiffness
      desc.
           Gets the cloth bending stiffness.
      return.
           Bending stiffness of the Cloth
      see. Cloth::setBendingStiffness
  */
  Real                                        getBendingStiffness() const;

  /*! function. setStretchingStiffness
      desc.
           Sets the cloth stretching stiffness in the range from 0 to 1.
      args.
           Real __stiffness__ -- Stretching stiffness; (0, 1].
      see. Cloth::setStretchingStiffness
  */
  void                                        setStretchingStiffness(Real stiffness);

  /*! function. getStretchingStiffness
      desc. 
           Gets the cloth stretching stiffness.
      return.
           **Real** -- Stretching stiffness
      see. Cloth::getStretchingStiffness
  */
  Real                                        getStretchingStiffness() const;

  /*! function. setDampingCoefficient
      desc.
           Sets the damping coefficient.
      args.
           Real __damping__ -- Damping coefficent; [0..1].
  */
  void                                        setDampingCoefficient(Real damping);

  /*! function. getDampingCoefficient
      desc.
           Gets the damping coefficient.
      return.
           **Real** -- Damping coefficient
  */
  Real                                        getDampingCoefficient() const;

  /*! function. setFriction
      desc.
           Sets the cloth friction coefficient.
      args.
           Real __friction__ -- Friction coefficient; [0 to 1].
      see. Cloth::getFriction
  */
  void                                        setFriction(Real friction);

  /*! function. getFriction
      desc. 
           Gets the cloth friction coefficient.
      return. 
           **Real** -- Friction coefficient
      see. Cloth::setFriction
  */
  Real                                        getFriction() const;

  /*! function. setPressure
      desc.
           Sets the cloth pressure coefficient.
      args.
           Real __pressure__ --  Pressure coefficient; [0, inf).
      see.
           Cloth::getPressure
  */
  void                                        setPressure(Real pressure);

  /*! function. getPressure
      desc.
           Retrieves the cloth pressure coefficient.
      return.
           **Real** -- Pressure coefficient
  */
  Real                                        getPressure() const;

  /*! function. setTearFactor
      desc.
           Sets the cloth tear factor.
      args.
           Real __factor__ -- Tear factor; (1, inf).
  */
  void                                        setTearFactor(Real factor);

  /*! function. getTearFactor
      desc.
           Retrieves the cloth tear factor.
      return.
           **Real** -- Tear factor.
  */
  Real                                        getTearFactor() const;

  /*! function. setAttachmentTearFactor
      desc.
           Sets the cloth attachment tear factor
      args.
           Real __factor__ -- attachment tear factor; (1, inf).
      see. Cloth::getAttachmentTearFactor
  */
  void                                        setAttachmentTearFactor(Real factor);

  /*! function. getAttachmentTearFactor
      desc.
           Retrieves the attachment cloth tear factor.
      args.
           **Real** -- attachment tear factor.
      see. Cloth::setAttachmentTearFactor
  */
  Real                                        getAttachmentTearFactor() const;

  /*! function. setThickness
      desc.
           Sets the cloth thickness.
      args.
           Real __thickness__ -- Thickness; [0, inf).
      see. Cloth::getThickness
  */
  void                                        setThickness(Real thickness);

  /*! function. getThickness
      desc.
          Gets the cloth thickness.
      return.
          **Real** -- Cloth thickness
      see. Cloth::setThickness
  */
  Real                                        getThickness() const;

  /*! function. getDensity
      desc.
           Gets the cloth density.
      return.
           **Real** -- Cloth density.
  */
  Real                                        getDensity() const;

  /*! function. getRelativeGridSpacing
      desc.
           The cloth is represented by a set of world aligned cubical
           cells in broad phase. The size of these cells is determined
           by multiplying the length of the diagonal of the AABB of the
           initial cloth size with this constant.
      return.
           **Real** -- Relative grid spacing
  */
  Real                                        getRelativeGridSpacing() const;

  /*! function. getSolverIterations
      desc.
           Retrieves the cloth solver iterations.
      return.
           **unsigned int** -- Cloth solver iterations
      see.
           Cloth::getSolverIterations
  */
  unsigned int                                getSolverIterations() const;

  /*! function. setSolverIterations
      desc.
           Sets the cloth solver iterations.
      args.
           unsigned int __solverIterations__ -- Number of iterations; (0, inf].
     see.
           Cloth::setSolverIterations
  */
  void                                        setSolverIterations(unsigned int solverIterations);

  /*! function. getWorldBounds
      desc.
           Returns a world space AABB enclosing all cloth points.
      return.
           **Bounds3** -- World bounds
  */
  Bounds3                                     getWorldBounds() const;

  /*! function. attachToShape
      desc.
           Attaches the cloth to a shape. All cloth points currently inside the shape are attached.
      note.
           Cube, Sphere, Capsule and Convex are only valid shapes to attach to.
      args.
           Shape* __shape__ -- Shape for which the cloth to be attached to.
           unsigned int __attachmentFlags__ -- Attachment flags
      example.
           cloth->attachToShape(box_shape, Enums::ClothAttachmentFlags_Twoway | ClothAttachmentFlags_Tearable);
      see.
           Enums::ClothAttachmentFlags
  */
  void                                        attachToShape(Shape* shape, unsigned int attachmentFlags);

  /*! function. attachToCollidingShapes
      desc.
           Attaches the cloth to all shapes, currently colliding.
      note.
           Cube, Sphere, Capsule and Convex are only valid shapes to attach to.
      args.
           unsigned int __attachmentFlags__ -- Attachment flags
      example.
           cloth->attachToCollidingShapes(Enums::ClothAttachmentFlags_Twoway);
      see.
           Enums::ClothAttachmentFlags
  */
  void                                        attachToCollidingShapes(unsigned int attachmentFlags);

  /*! function. attachVertexToShape
      desc.
           Attaches a cloth vertex to a local position within a shape.
      note.
           Cube, Sphere, Capsule and Convex are only valid shapes to attach to.
      args.
           unsigned int __vertexID__ -- Vertex ID to attach
           Shape* __shape__ -- Shape to attach the verex to
           const Vec3& __localPos__ -- Local position relative to the pose of the shape 
           unsigned int __attachmentFlags__ -- Attachment flags
      example.
           cloth->attachVertexToShape(33, box_shape, Vec3(0, 1, 0), Enums::ClothAttachmentFlags_Twoway | ClothAttachmentFlags_Tearable);
      see.
           Enums::ClothAttachmentFlags
  */
  void                                        attachVertexToShape(unsigned int vertexId, Shape* shape, const Vec3& localPos, unsigned int attachmentFlags);

  /*! function. attachVertexToGlobalPosition
      desc.
            Attaches a cloth vertex to a position in world space
      args.
           unsigned int __vertexID__ -- Vertex ID to attach
           const Vec3& __globalPos__ -- Global position in world space. 
      example.
           cloth->attachVertexToGlobalPosition(33, Vec3(0, 10, 0));
  */
  void                                        attachVertexToGlobalPosition(unsigned int vertexId, const Vec3& globalPos);

  /*! function. detachFromShape
      desc.
           Detaches the cloth from a shape it has been attached to before.
      args.
           Shape* __shape__ -- Shape to detach the cloth from.
  */
  void                                        detachFromShape(Shape* shape);

  /*! function. freeVertex
      desc.
           Frees a previously attached cloth point.
      args.
           unsigned int __vertexId__ -- Vertex to free
  */
  void                                        freeVertex(unsigned int vertexId);

  /*! function. dominateVertex
      desc.
          Changes the weight of a vertex in the cloth solver for a period of time.
          
          p. If this method is called for some vertex, the cloth solver will, during a time
          period of length expirationTime, assign a different weight to the vertex
          while internal cloth constraints (i.e. bending & stretching) are being resolved.
          
          p. With a high dominanceWeight, the modified vertex will force neighboring vertices
          to strongly accommodate their positions while its own is kept fairly constant. 
          The reverse holds for smaller dominanceWeights. 
          
          p. Using a dominanceWeight of +infinity has a similar effect as temporarily attaching 
          the vertex to a global position. However, unlike using attachments, the velocity 
          of the vertex is kept intact when using this method.
          
      note.
           * The current implementation will not support the full range of dominanceWeights. All dominanceWeights > 0.0 are treated equally as being +infinity.
           * An expiration time of 0.0 is legal and will result in dominance being applied throughout one substep before being discarded immediately.
           * Having a large number of vertices dominant at once may result in a performance penalty.
           
      args.
           unsigned int __vertexId__ -- Index of the vertex
           Real __expirationTime__ -- Time period where dominance will be active for this vertex.
           Real __dominanceWeight__ -- Dominance weight for this vertex.
  */
  void                                        dominateVertex(unsigned int vertexId, Real expirationTime, Real dominanceWeight);
  
  /*! function. getVertexAttachmentStatus
      desc.
           Return the attachment status of the given vertex.
      args.
           unsigned int __vertexId__ -- Index of the vertex.
      return.
           **Enums::ClothVertexAttachmentStatus** -- Attachment status.
  */
  Enums::ClothVertexAttachmentStatus          getVertexAttachmentStatus(unsigned int vertexId) const;
  
  /*! function. getVertexAttachmentShape
      desc.
           Returns the pointer to an attached shape pointer of the given vertex.
      args.
           unsigned int __vertexId__ -- Index of the vertex.
      return.
           **Shape** * -- Attachment status.
  */
  Shape*                                      getVertexAttachmentShape(unsigned int vertexId) const;

  /*! function. getVertexAttachmentPosition
      desc.
           Return the attachment position of the given vertex.
      args.
           unsigned int __vertexId__ -- Index of the vertex.
      return.
           **Vec3** -- Attachment position.
  */
  Vec3                                        getVertexAttachmentPosition(unsigned int vertexId) const;

  /*! function. attachToCore
      desc.
           After this call, the cloth is infinitely stiff between collisions and simply 
           moves with the actor. At impacts with an impact impulse greater than impulseThreshold, 
           the cloth is plastically deformed. Thus, a cloth with a core behaves like a piece of metal.
           
           p. The core actor's geometry is adjusted automatically. Its size also depends on the 
           cloth thickness. Thus, it is recommended to choose small values for the thickness.
           At impacts, colliding objects are moved closer to the cloth by the value provided in 
           penetrationDepth which causes a more dramatic collision result.
           
           p. The core actor must have at least one shape, and currently supported shapes are 
           spheres, capsules, boxes and compounds of spheres.
           It is recommended to specify the density rather than the mass of the core body. 
           This way the mass and inertia tensor are updated when the core deforms.
           
           p. The maximal deviation of cloth particles from their initial positions
           (modulo the global rigid body transforms translation and rotation) can be
           specified via the parameter maxDeformationDistance. Setting this parameter to
           zero means that the deformation is not limited.  
           
      args.
           RigidBody* __rigidBody__ -- The core actor to attach the cloth to.
           Real __impulseThreshold__ -- Threshold for when deformation is allowed.
           Real __penetrationDepth__ -- Amount by which colliding objects are brought closer to the cloth.
           Real __maxDeformationDistance__ -- Maximum deviation of cloth particles from initial position.
           
      note.
           * Call this function only once right after the cloth is created. Turning cloth into metal and vice versa during the simulation is not recommended.
           * This feature is well suited for volumetric objects like barrels. It cannot handle two dimensional flat pieces well.
  */
  void                                        attachToCore(RigidBody* rigidBody, Real impulseThreshold, Real penetrationDepth = 0.0f, Real maxDeformationDistance = 0.0f);
  
/*! function. tearVertex
    desc.
         First the vertex is duplicated. The triangles on one side of the split plane keep 
         the original vertex. For all triangles on the opposite side the original vertex is 
         replaced by the new one. The split plane is defined by the world location of the 
         vertex and the normal provided by the user.
    note.
         * TearVertex performs a user defined vertex split in contrast to an automatic split
           that is performed when the flag Enums::ClothAttachmentFlags_Tearable is set.
           Therefore, tearVertex works even if Enums::ClothAttachmentFlags_Tearable is not 
           set in ClothDescription::mFlags.
         * For tearVertex to work, the clothMesh has to be cooked with the flag
           Enums::ClothAttachmentFlags_Tearable set in NxClothMeshDesc.flags.
    args.
         const unsigned int __vertexId__ -- Index of the vertex.
         const Vec3& __normal__ --  The normal of the split plane.
    return.
          **bool** -- True if the split had an effect
*/
bool                                        tearVertex(const unsigned int vertexId, const Vec3& normal);

  /*! function. raycast
      desc.
           Executes a raycast against the cloth.
      args.
           const Ray& ray -- The ray in world space.
      return.
            **ClothRaycastHit** -- Hit position and index to the vertex hit by the ray.
  */
  ClothRaycastHit                             raycast(const Ray&);

  /*! function. getGroup
      desc.
           Gets the collision group the cloth belongs to.
      return.
           **GroupIdentifier** -- Collision group for the cloth
  */
  GroupIdentifier                             getGroup();

  /*! function. setGroupsMask
      desc.
           Sets 128-bit mask used for collision filtering.
      args.
           const int4& __groupsMask__ -- The group mask to set for the cloth.
  */
  void                                        setGroupsMask(const int4&);

  /*! function. getGroupsMask
      desc.
           Gets the collision mask for filtering
      return.
           **int4** -- The group mask for the cloth.
  */
  int4                                        getGroupsMask() const;

  /*! functions. setValidBounds
      desc.
           Sets the valid bounds of the cloth in world space.
           
           p. If the flag Enums::ClothFlags_ValidBounds is set, these bounds defines the volume
           outside of which cloth particle are automatically removed from the simulation.
     args.
          const Bounds3& __bounds__ -- Valid bounds.
  */
  void                                        setValidBounds(const Bounds3& bounds);
  
  /*! functions. getValidBounds
      desc.
           Gets the valid bounds.
      return.
           **Bounds3** -- The bounds.
  */
  Bounds3                                     getValidBounds() const;

  /*! function. setPosition
      desc.
           Sets the position of a particular vertex of the cloth.
      args.
           const Vec3& __position__ -- New position of the vertex
           unsigned int __vertexId__ -- Index of the vertex
  */
  void                                        setPosition(const Vec3& position, unsigned int vertexId);

  /*! function. setPositions
      desc.
           Set the position for _all_ of the particles at once.
      args.
           buffer<Vec3>& __positions__ -- All the new positions of the vertices as a Buffer of Vec3s.
  */
  void                                        setPositions(buffer<Vec3>& positions);

  /*! function. getPosition
      desc.
           Gets the position of a particular vertex of the cloth.
      args.
           unsigned int __vertexId__ -- Index of the vertex
      return.
           **Vec3** -- The vertex position.
  */
  Vec3                                        getPosition(unsigned int vertexId);

  /*! function. getPositions
      desc.
           Get the position for _all_ of the particles at once.
      args.
           buffer<Vec3>& __outPositions__ -- Returns all the positions of the vertices as a Buffer of Vec3s.
  */
  void                                        getPositions(buffer<Vec3>& outPositions);

  /*! function. setVelocity
      desc.
           Sets the velocity of a particular vertex of the cloth.
      args.
           const Vec3& __velocity__ -- New velocity of the vertex
           unsigned int __vertexId__ -- Vertex index to apply the velocity to.
  */
  void                                        setVelocity(const Vec3& velocity, unsigned int vertexId);

  /*! function. setVelocities
      desc.
           Set the velocities of all the vertices at once.
      args.
           buffer<Vec3>& __velocities__ -- All the new velocities of the vertices as a Buffer of Vec3s.
  */
  void                                        setVelocities(buffer<Vec3>& velocities);

  /*! function. getVelocity
      desc.
          Gets the velocity of a particular vertex of the cloth.
      args.
           unsigned int __vertexId__ -- Vertex index to apply the velocity to.
      return.
           Vec3 -- Velocity of the vertex
  */
  Vec3                                        getVelocity(unsigned int vertexId);

  /*! function. getVelocities
      desc.
           Get the velocities for _all_ of the particles at once.
      args.
           buffer<Vec3>& __outVelocities__ -- Returns all the velocities of the vertices as a Buffer of Vec3s.
  */
  void                                        getVelocities(buffer<Vec3>& outVelocities);

  /*! function. getNumberOfParticles
      desc.
           Gets the number of cloth particles.
      return.
           **unsigned int** -- The number of particles in the cloth.
  */
  unsigned int                                getNumberOfParticles();

  /*! function. setCollisionResponseCoefficient
      desc.
           Sets the collision response coefficient.
      args.
           Real __coefficient__ -- Collision response coefficient
  */
  void                                         setCollisionResponseCoefficient(Real coefficient);

  /*! function. getCollisionResponseCoefficient
      desc.
           Retrieves the collision response coefficient.
      return.
           **Real** -- response coefficient
  */
  Real                                         getCollisionResponseCoefficient() const;

  /*! function. setAttachmentResponseCoefficient
      desc.
           Sets the attachment response coefficient
      args.
           Real __coefficient__ -- Response coefficient; [0, 1].
  */
  void                                         setAttachmentResponseCoefficient(Real coefficient);

  /*! function. getAttachmentResponseCoefficient
      desc.
           Gets the attachment response coefficient
      return.
           **Real** -- Response coefficient.
  */
  Real                                         getAttachmentResponseCoefficient() const;

  /*! function. setFromFluidResponseCoefficient
      desc.
           Sets the response coefficient for collisions from fluids to this cloth
      args.
           Real __coefficient__ -- Response coefficient.
  */
  void                                         setFromFluidResponseCoefficient(Real coefficient);

  /*! function. getFromFluidResponseCoefficient
      desc.
           Gets the response coefficient for collisions from fluids to this cloth
      return.
           **Real** -- Response coefficient.
  */
  Real                                         getFromFluidResponseCoefficient() const;

  /*! function. setToFluidResponseCoefficient
      desc.
           Sets the response coefficient for collisions from this cloth to fluids
      args.
           Real __coefficient__ -- response coefficient
  */
  void                                         setToFluidResponseCoefficient(Real coefficient);

  /*! function. getToFluidResponseCoefficient
      desc.
           Retrieves response coefficient for collisions from this cloth to fluids.
      return.
           **Real** -- response coefficient
  */
  Real                                         getToFluidResponseCoefficient() const;

  /*! function. setExternalAcceleration
      desc.
           Sets an external acceleration (@unit length / s^2@) which affects all non attached particles of the cloth
      args.
           const Vec3& __acceleration__ -- The acceleration vector.
  */
  void                                         setExternalAcceleration(const Vec3& acceleration);

  /*! function. getExternalAcceleration
      desc.
           Retrieves the external acceleration which affects all non attached particles of the cloth.
      return.
           **Vec3** -- Acceleration vector (@unit length / s^2@).
  */
  Vec3                                         getExternalAcceleration() const;

  /*! function. setMinAdhereVelocity
      desc.
           If the Enums::ClothFlags_Adhere flag is set the cloth moves partially in the frame of the attached rigid body.
           
           p. This feature is useful when the cloth is attached to a fast moving character.
           In that case the cloth adheres to the shape it is attached to while only 
           velocities below the parameter minAdhereVelocity are used for secondary effects.
      args.
           Real __velocity__ -- The minimal velocity for cloth to adhere (@unit length / s@)
     see. Cloth::getMinAdhereVelocity
  */
  void                                         setMinAdhereVelocity(Real velocity);
  
  /*! function. getMinAdhereVelocity
      desc.
           If the Enums::ClothFlags_Adhere flag is set the cloth moves partially in the frame of the attached rigid body.
           
           p. This feature is useful when the cloth is attached to a fast moving character.
           In that case the cloth adheres to the shape it is attached to while only 
           velocities below the parameter minAdhereVelocity are used for secondary effects.
     return.
           **Real** -- The minimal velocity for cloth to adhere (@unit length / s@)
     see. Cloth::setMinAdhereVelocity
  */
  Real                                         getMinAdhereVelocity() const;

  /*! function. setWindAcceleration
      desc.
           Sets an acceleration acting normal to the cloth surface at each vertex.
      args.
           const Vec3& __acceleration__ -- The acceleration vector (@unit length / s^2@)
  */
  void                                         setWindAcceleration(const Vec3& acceleration);

  /*! function. getWindAcceleration
      desc.
           Retrieves the acceleration acting normal to the cloth surface at each vertex.
      return.
           **Vec3** -- The acceleration vector (@unit length / s^2@)
  */
  Vec3                                         getWindAcceleration() const;

  /*! functions. isSleeping
      desc.
           Is the cloth sleeping?
      return.
           **bool** -- Returns true if this cloth is sleeping.
  */
  bool                                         isSleeping() const;

  /*! functions. getSleepLinearVelocity
      desc.
           Returns the linear velocity below which a cloth may go to sleep.
      return.
           **Real** -- The linear velocity threshold of when the cloth will go to sleep.
  */
  Real                                         getSleepLinearVelocity() const;

  /*! functions. setSleepLinearVelocity
      desc.
           Returns the linear velocity below which a cloth may go to sleep.
      args.
           Real __threshold__ -- The linear velocity threshold of when the cloth will go to sleep.
  */
  void                                         setSleepLinearVelocity(Real threshold);

  /*! function. wakeUp
      desc.
           Wakes up the cloth if it is sleeping.
      args.
           Real __wakeCounterValue__ -- New sleep counter value; [0, inf]
  */
  void                                         wakeUp(Real wakeCounterValue = 20.0f*0.02f);

  /*! function. putToSleep
      desc.
           Forces the cloth to sleep.
  */
  void                                         putToSleep();

  /*! function. setFlags
      desc.
           Sets the flags, a combination of the bits defined by the enum Enums::ClothFlags.
      args.
           unsigned int __flags__ -- Combination of the Enums::ClothFlags using the @|@ operator.
  */
  void                                         setFlags(unsigned int flags);

  /*! function. getFlags
      desc.
           Retrieves the flags.
      return.
           **unsigned int** -- The cloth flags.
  */
  unsigned int                                 getFlags() const;

  /*! function. setName
      desc.
           Sets a name string for the object that can be retrieved with Cloth::getName()
      args.
           const String& __name__ -- New name for the Cloth.
  */
  void                                         setName(const String& name);

  /*! function. addForceAtVertex
      desc.
           Applies a force (or impulse) defined in the global coordinate frame, to a particular 
           vertex of the cloth. 
           
           p. Because forces are reset at the end of every timestep, you can maintain
           a total external force on an object by calling this once every frame.
           
           p. Enums::ForceMode determines if the force is to be conventional or impulsive.
           
      args.
           const Vec3& __force__ -- Force/impulse to add, defined in the global frame.
           unsigned int __vertexId__ -- Number of the vertex to add the force at.
           Enums::ForceMode __mode__ -- mode The mode to use when applying the force/impulse. Default: Enums::ForceMode_Force
           
      note.
           Supported modes are ForceMode_Force, ForceMode_Impulse, ForceMode_Acceleration, ForceMode_Velocity)
  */
  void                                         addForceAtVertex(const Vec3& force, unsigned int vertexId, Enums::ForceMode mode = Enums::ForceMode_Force);
  
  /*! function. addForceAtPos
      desc.
           Applies a radial force (or impulse) at a particular position. All vertices
           within radius will be affected with a quadratic drop-off. 
           
           p. Because forces are reset at the end of every timestep, you can maintain
           a total external force on an object by calling this once every frame.
           
           p. Enums::ForceMode determines if the force is to be conventional or impulsive.
           
      args.
           const Vec3& __position__ -- Position to apply force at.
           Real __magnitude__ -- Magnitude of the force/impulse to apply.
           Real __radius__ -- The sphere radius in which particles will be affected. <b>Range:</b> position vector
           Enums::ForceMode __mode__ -- mode The mode to use when applying the force/impulse. Default: Enums::ForceMode_Force
           
      note.
           Supported modes are ForceMode_Force, ForceMode_Impulse, ForceMode_Acceleration, ForceMode_Velocity)
  */
  void                                         addForceAtPos(const Vec3& position, Real magnitude, Real radius, Enums::ForceMode mode = Enums::ForceMode_Force);
  
  /*! function. addDirectedForceAtPos
      desc.
           Applies a radial force (or impulse) at a particular position. All vertices
           within radius will be affected with a quadratic drop-off. 
           
           p. Because forces are reset at the end of every timestep, you can maintain
           a total external force on an object by calling this once every frame.
           
           p. Enums::ForceMode determines if the force is to be conventional or impulsive.
           
      args.
           const Vec3& __position__ -- Position to apply force at.
           const Vec3& __force__ -- Force/impulse to add, defined in the global frame.
           Real __magnitude__ -- Magnitude of the force/impulse to apply.
           Real __radius__ -- The sphere radius in which particles will be affected. <b>Range:</b> position vector
           Enums::ForceMode __mode__ -- mode The mode to use when applying the force/impulse. Default: Enums::ForceMode_Force
           
      note.
           Supported modes are ForceMode_Force, ForceMode_Impulse, ForceMode_Acceleration, ForceMode_Velocity)
  */
  void                                         addDirectedForceAtPos(const Vec3& position, const Vec3& force, Real radius, Enums::ForceMode mode = Enums::ForceMode_Force);
  
  /*! function. overlapAABBTriangles
      desc.
          Finds triangles touching the input bounds.
      note. This method returns a pointer to an internal structure using the indices member. Hence the
            user should use or copy the indices before calling any other API function.
      args.
           const Bounds3& __bounds__ -- Bounds to test against in world space.
           unsigned int __nbIndices__ -- Retrieves the number of triangle indices touching the AABB
           const unsigned int*& __indicies__ -- Returns an array of touching triangle indices. 
      return.
            **bool** -- True if there is an overlap.
  */
  bool                                         overlapAABBTriangles(const Bounds3& bounds, unsigned int& nbIndices, const unsigned int*& indices) const;
  
  /*! function. getScene
      desc.
           Retrieves the scene which this cloth belongs to.
      return.
           **Scene** * -- The scene that the cloth belongs to.
  */
  Scene*                                       getScene();
  
  /*! function. getPPUTime
      desc.
           Get the PPU simulation time.
      return.
           **unsigned int** -- Simulation time.
  */
  unsigned int                                 getPPUTime() const;
  
  /*! function. getForceFieldMaterial
      desc.
           Retrieves the actor's force field material index
      return.
           **MaterialIdentifier** -- Forcefield material.
  */
  MaterialIdentifier                           getForceFieldMaterial() const;

  /*! function. setForceFieldMaterial
      desc.
           Sets the actor's force field material index
      args.
           MaterialIdentifier __material__ -- New forcefield material.
  */
  void                                         setForceFieldMaterial(MaterialIdentifier material);
    
  /*! function. to_s
      desc.
          Returns the pointer and name as string.
  */
  String to_s() const;
  
  protected: // Functions
  
  /*! constructor. Cloth
      note.
           * Use createScene(...) to create a non-rendered cloth
           * Use RenderSystem to create a rendered cloth.
      !private
  */
                                               Cloth(const ClothDescription&, Renderable*, Enums::Priority, Scene*);
  
  /*! destructor. Cloth
      !private
  */
  virtual                                     ~Cloth();
  
  /*! advance
      desc.
           Time advancing function, called by TimeController
      !private
      args.
           float __deltaTime__ -- Time passed
           const Enums::Priority& priority -- Priority of the cloth
  */
  bool                                         advance(float deltaTime, const Enums::Priority& priority, const Enums::SceneFunction&);
  
  protected: // Variables
  
  /** \brief Scene that the cloth belongs to.
  */
  Scene*                                        mScene;
  
  /** \brief Actual cloth.
  */
  NxCloth*                                      mCloth;
  
  /** \brief Mesh being shared by the cloth.
  */
  Mesh*                                         mMesh;

  /** \brief
  */
  Renderable*                                   mRenderable;

  /** \brief
  */
  MeshRenderable*                               mMeshRenderable;
  
  /** \brief Possible name of the mesh.
  */
  String                                        mName;
  
  /** \brief Possible name of the mesh.
  */
  StringHash                                    mNameHash;

  /** \brief Current render priority.
  */
  Enums::Priority                               mPriority;
  
  bool                                          mDrawnAtLeastOnce;
  
}; // class Cloth

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
