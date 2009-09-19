/** File: NxOgreCloth.h
    Created on: 31-May-09
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

#ifndef NXOGRE_CLOTH_H
#define NXOGRE_CLOTH_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreTimeListener.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass Cloth : public PointerClass<Classes::_Cloth>, public TimeListener
{
  
  friend class Scene;
  friend class Functions::ArrayFunctions<Cloth*>::Write;
  
  public:
  
    /** \brief Get the renderable.
    */
    Renderable*                                 getRenderable();
  
    /** \brief Get the mesh shared by the cloth.
    */
    Mesh*                                       getMesh();
    
    /** \internal
    */
    NxCloth*                                    getPhysXCloth();

    /** \internal
    */
    PhysXMeshData*                              getPhysXMeshData();

    /** \brief Get the cloth's name.
    */
    String                                      getName();

    /** \brief Sets the cloth bending stiffness in the range from 0 to 1.
    */
    void                                        setBendingStiffness(Real stiffness);

    /** \brief Gets the cloth bending stiffness.
    */
    Real                                        getBendingStiffness() const;

    /** \brief Sets the cloth stretching stiffness in the range from 0 to 1.
    */
    void                                        setStretchingStiffness(Real stiffness);

    /** \brief Gets the cloth stretching stiffness.
    */
    Real                                        getStretchingStiffness() const;

    /** \brief Sets the damping coefficient in the range from 0 to 1.
    */
    void                                        setDampingCoefficient(Real damping);

    /** \brief Gets the damping coefficient.
    */
    Real                                        getDampingCoefficient() const;

    /** \brief Sets the cloth friction coefficient in the range from 0 to 1.
    */
    void                                        setFriction(Real friction);

    /** \brief Gets the cloth friction coefficient.
    */
    Real                                        getFriction() const;

    /** \brief Sets the cloth pressure coefficient (must be non negative).
    */
    void                                        setPressure(Real pressure);

    /** \brief Retrieves the cloth pressure coefficient.
    */
    Real                                        getPressure() const;

    /** \brief Sets the cloth tear factor (must be larger than one).
    */
    void                                        setTearFactor(Real factor);

    /** \brief Retrieves the cloth tear factor.
    */
    Real                                        getTearFactor() const;

    /** \brief Sets the cloth attachment tear factor (must be larger than one).
    */
    void                                        setAttachmentTearFactor(Real factor);

    /** \brief Retrieves the attachment cloth tear factor.
    */
    Real                                        getAttachmentTearFactor() const;

    /** \brief Sets the cloth thickness (must be positive).
    */
    void                                        setThickness(Real thickness);

    /** \brief Gets the cloth thickness.
    */
    Real                                        getThickness() const;

    /** \brief Gets the cloth density.
    */
    Real                                        getDensity() const;

    /** \brief Gets the relative grid spacing.
    */
    Real                                        getRelativeGridSpacing() const;

    /** \brief Retrieves the cloth solver iterations.
    */
    unsigned int                                getSolverIterations() const;

    /** \brief Sets the cloth solver iterations.
    */
    void                                        setSolverIterations(unsigned int solverIterations);

    /** \brief Retrieves the cloth solver iterations.
    */
    Bounds3                                     getWorldBounds() const;

    /** \brief Attaches the cloth to a shape (Cube, Sphere, Capsule and Convex only)
    */
    void                                        attachToShape(Shape*, unsigned int attachmentFlags);

    /** \brief Attaches the cloth to all shapes (Cube, Sphere, Capsule and Convex only), currently colliding. 
    */
    void                                        attachToCollidingShapes(unsigned int attachmentFlags);

    /** \brief Attaches the cloth to all shapes (Cube, Sphere, Capsule and Convex only), currently colliding. 
    */
    void                                        attachVertexToShape(unsigned int vertexId, Shape*, const Vec3& localPos, unsigned int attachmentFlags);

    /** \brief Attaches the cloth to all shapes (Cube, Sphere, Capsule and Convex only), currently colliding. 
    */
    void                                        attachVertexToGlobalPosition(unsigned int vertexId, const Vec3& globalPos);

    /** \brief Detaches the cloth from a shape it has been attached to before. 
    */
    void                                        detachFromShape(Shape*);

    /** \brief Frees a previously attached cloth point.
    */
    void                                        freeVertex(unsigned int vertexId);

    /** \brief Changes the weight of a vertex in the cloth solver for a period of time.
    */
    void                                        dominateVertex(unsigned int vertexId, Real expirationTime, Real dominanceWeight);

    /** \brief Return the attachment status of the given vertex.
    */
    Enums::ClothVertexAttachmentStatus          getVertexAttachmentStatus(unsigned int vertexId) const;

    /** \brief Return the shape of the given vertex.
    */
    Shape*                                      getVertexAttachmentShape(unsigned int vertexId) const;

    /** \brief Return the attachment position of the given vertex.
    */
    Vec3                                        getVertexAttachmentPosition(unsigned int vertexId) const;

    /** \brief Attaches the cloth to an rigidbody.
        \see NxCloth::attachToCore
    */
    void                                        attachToCore(RigidBody*, Real impulseThreshold, Real penetrationDepth = Real(0), Real maxDeformationDistance = Real(0));

    /** \brief Tears a vertex
    */
    void                                        tearVertex(const unsigned int vertexId, const Vec3& normal);

    /** \brief Executes a raycast against the cloth.
    */
    ClothRaycastHit                              raycast(const Ray&);

    /** \brief Gets the collision group the cloth belongs to.
    */
    unsigned short                               getGroup();

    /** \brief Sets the collision mask for filtering
    */
    void                                         setGroupsMask(const int4&);

    /** \brief Gets the collision mask for filtering
    */
    int4                                         getGroupsMask() const;

    /** \brief Sets the valid bounds.
    */
    void                                         setValidBounds(const Bounds3&);

    /** \brief Gets the valid bounds.
    */
    Bounds3                                      getValidBounds() const;

    /** \brief
    */
    void                                         setPosition(const Vec3&, unsigned int vertexId);

    /** \brief
    */
    void                                         setPositions(Buffer<Vec3>& positions);

    /** \brief
    */
    Vec3                                         getPosition(unsigned int vertexId);

    /** \brief
    */
    void                                         getPositions(Buffer<Vec3>& positions);


    /** \brief
    */
    void                                         setVelocity(const Vec3&, unsigned int vertexId);

    /** \brief
    */
    void                                         setVelocities(Buffer<Vec3>& v);

    /** \brief Gets the velocity of a particular vertex of the cloth.
    */
    Vec3                                         getVelocity(unsigned int vertexId);

    /** \brief Gets the velocities of the cloth.
    */
    void                                         getVelocities(Buffer<Vec3>& v);

    /** \brief Gets the number of cloth particles.
    */
    unsigned int                                 getNumberOfParticles();

   /** \brief Sets the collision response coefficient.
   */
   void                                          setCollisionResponseCoefficient(Real coefficient);

   /** \brief Retrieves the collision response coefficient.
   */
   Real                                          getCollisionResponseCoefficient() const;

   /** \brief Sets the attachment response coefficient (range 0 to 1)
   */
   void                                          setAttachmentResponseCoefficient(Real coefficient);

   /** \brief Retrieves the attachment response coefficient.
   */
   Real                                          getAttachmentResponseCoefficient() const;

   /** \brief Sets the response coefficient for collisions from fluids to this cloth
   */
   void                                          setFromFluidResponseCoefficient(Real coefficient);

   /** \brief Retrieves response coefficient for collisions from fluids to this cloth
   */
   Real                                          getFromFluidResponseCoefficient() const;

   /** \brief Sets the response coefficient for collisions from this cloth to fluids
   */
   void                                          setToFluidResponseCoefficient(Real coefficient);

  /** \brief Retrieves response coefficient for collisions from this cloth to fluids.
  */
  Real                                           getToFluidResponseCoefficient() const;

  /** \brief Sets an external acceleration which affects all non attached particles of the cloth
  */
  void                                           setExternalAcceleration(const Vec3& acceleration);

  /** \brief Retrieves the external acceleration which affects all non attached particles of the cloth
  */
  Vec3                                           getExternalAcceleration() const;

  /** \brief If the Enums::ClothFlags_Adhere flag is set the cloth moves partially in the frame  of the attached rigid body. 
  */
  void                                           setMinAdhereVelocity(Real velocity);

  /** \brief If the  Enums::ClothFlags_Adhere flag is set the cloth moves partially in the frame of the attached actor. 
  */
  Real                                           getMinAdhereVelocity() const;

  /** \brief Sets an acceleration acting normal to the cloth surface at each vertex.
  */
  void                                           setWindAcceleration(const Vec3& acceleration);

  /** \brief Retrieves the acceleration acting normal to the cloth surface at each vertex.
  */
  Vec3                                           getWindAcceleration() const;

  /** \brief Returns true if this cloth is sleeping.
  */
  bool                                           isSleeping() const;

  /** \brief Returns the linear velocity below which a cloth may go to sleep.
  */
  Real                                           getSleepLinearVelocity() const;

  /** \brief Sets the linear velocity below which a cloth may go to sleep.
  */
  void                                           setSleepLinearVelocity(Real threshold);

  /** \brief Wakes up the cloth if it is sleeping.
  */
  void                                           wakeUp(Real wakeCounterValue = 20.0f*0.02f);

  /** \brief Forces the cloth to sleep. 
  */
  void                                            putToSleep();

  /** \brief Sets the flags, a combination of the bits defined by the enum Enums::ClothFlags.
  */
  void                                            setFlags(unsigned int flags);

  /** \brief Retrieves the flags.
  */
  unsigned int                                    getFlags() const;

  /** \brief Sets a name string for the object that can be retrieved with getName().
  */
  void                                            setName(const String& name);

  /** \brief Applies a force (or impulse) defined in the global coordinate frame, to a particular vertex of the cloth. 
  */
  void                                            addForceAtVertex(const Vec3& force, unsigned int vertexId, Enums::ForceMode mode = Enums::ForceMode_Force);

  /** \brief Applies a radial force (or impulse) at a particular position. All vertices within radius will be affected with a quadratic drop-off. 
  */
  void                                            addForceAtPos(const Vec3& position, Real magnitude, Real radius, Enums::ForceMode mode = Enums::ForceMode_Force);

  /**  \brief Applies a directed force (or impulse) at a particular position. All vertices within radius will be affected with a quadratic drop-off.
  */
  void                                            addDirectedForceAtPos(const Vec3& position, const Vec3& force, Real radius, Enums::ForceMode mode = Enums::ForceMode_Force);

  /** \brief Finds triangles touching the input bounds.
  */
  bool                                            overlapAABBTriangles(const Bounds3& bounds, unsigned int& nbIndices, const unsigned int*& indices) const;

  /** \brief Retrieves the scene which this cloth belongs to.
  */
  Scene*                                          getScene();

  /** \brief Get the PPU simulation time.
  */
  unsigned int                                    getPPUTime() const;

  /** \brief Retrieves the actor's force field material index, default index is 0
  */
  MaterialIdentifier                              getForceFieldMaterial() const;

  /** \brief Sets the actor's force field material index, default index is 0
  */
  void                                            setForceFieldMaterial(MaterialIdentifier);

  protected: // Functions
  
  /** \brief Use Scene::createCloth
  */
                                                  Cloth(const ClothDescription&, Renderable*, Enums::Priority, Scene*);
  
  /** \brief Use Scene::destroyCloth
  */
  virtual                                        ~Cloth(void);
  
  /** \brief
  */
  bool                                            advance(float deltaTime, const Enums::Priority&);
  
  
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
  PhysXMeshData*                                mMeshData;
  
  /** \brief Possible name of the mesh.
  */
  String                                        mName;
  
  /** \brief Current render priority.
  */
  Enums::Priority                               mPriority;
  
  bool                                          mDrawnAtLeastOnce;
}; // class Cloth

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
