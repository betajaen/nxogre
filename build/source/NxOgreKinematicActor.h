/** File: NxOgreKinematicActor.h
    Created on: 20-Nov-08
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

#ifndef NXOGRE_KINEMATICACTOR_H
#define NXOGRE_KINEMATICACTOR_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

#include "NxOgrePointerClass.h"
#include "NxOgreRigidBody.h"
#include "NxOgreString.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief A kinematic actor is used mostly with the Character class. However it can be used for moving platforms,
           sliding doors and anything else that requires precise and predictable movement.
           
           NxOgre Kinematic Actors are more than an NxActor with a raised NX_BF_KINEMATIC flag, it has
           much more support functions and provides actual collision responses and callbacks. However if you
           just want an Actor with kinematic properties with no NxOgre powered callbacks or collisions then
           use a DynamicActor with a kinematic flag; but NxOgre will treat it as a dynamic actor and may
           or may not assume certain things about it.
    \example
     <code>
      mScene->createKinematicActor(new Box(4,1,4));
     </code>
*/
class NxOgrePublicClass KinematicActor : public PointerClass<Classes::_KinematicActor>, public RigidBody
{
  
  friend class Scene;
  friend class Functions::ArrayFunctions<KinematicActor*>::Write;
  
  public:
  
  using ::NxOgre::PointerClass<Classes::_KinematicActor>::operator new;

  using ::NxOgre::PointerClass<Classes::_KinematicActor>::operator delete;

  using ::NxOgre::PointerClass<Classes::_KinematicActor>::getClassType;

  /** \brief
  */
  virtual                             unsigned int           getClassType() const;

  /** \brief Assigns the actor to a user defined group of rigid bodies. 
  */
                                      void                   setGroup(GroupIdentifier actorGroup); 
  
  /** \brief Retrieves the value set with setGroup(). 
  */
                                      GroupIdentifier        getGroup(void) const;
  
  /** \brief Assigns dynamic actors a dominance group identifier. 
  */
                                      void                   setDominanceGroup(GroupIdentifier dominanceGroup); 
  
  /** \brief Retrieves the value set with setDominanceGroup(). 
  */
                                      GroupIdentifier        getDominanceGroup(void) const;
  
  /**  \brief Reset the user actor pair filtering state for this actor. This will cause filtering callbacks
       to be called again for any pairs involving this actor. Use this method when you wish to change
       the filtering policy of an actor that may already be in contact with other actors. 
  */
                                      void                   resetPairFiltering(void); 
  
  /** \brief Returns true if the actor is dynamic. 
  */
                                      bool                   isDynamic(void) const; 
  
  /** \brief Computes the total kinetic (rotational and translational) energy of the object.
  */
                                      Real                   computeKineticEnergy(void) const;
  
  /** \brief Sets the solver iteration count for the body. 
  */
                                      void                   setSolverIterationCount(unsigned int iterCount);
  
  /** \brief Retrieves the solver iteration count.
  */
                                      unsigned int           getSolverIterationCount(void) const; 
  
  /** \brief Retrieves the force threshold for contact reports. 
  */
                                      Real                   getContactReportThreshold(void) const;
  
  /** \brief Sets the force threshold for contact reports. 
  */
                                      void                   setContactReportThreshold(Real threshold);
  
  /** \brief Retrieves the actor's contact report flags. 
  */
                                      unsigned int           getContactReportFlags(void) const;
  
  /** \brief Sets the actor's contact report flags.
  */
                                      void                   setContactReportFlags(unsigned int flags);
  
  /// /** \brief Performs a linear sweep through space with the actor. 
  /// */
  ///                   NxU32                  linearSweep (const Vec3& motion, NxU32 flags, void *userData, NxU32 nbShapes, NxSweepQueryHit *shapes, NxUserEntityReport< NxSweepQueryHit > *callback, const NxSweepCache *sweepCache=NULL)=0 
  
  /// /** \brief  Retrieves the actor's simulation compartment, if any. 
  /// */
  ///                   NxCompartment*         getCompartment(void) const;
  
  /** \brief Retrieves the actor's force field material index, default index is 0. 
  */
                                      unsigned short         getForceFieldMaterial(void) const; 
  
  /** \brief Sets the actor's force field material index, default index is 0. 
  */
                                      void                   setForceFieldMaterial(unsigned short); 
  
  /** \brief Methods for setting a dynamic actor's pose in the world. 
  */
                                      void                   setGlobalPose(const Matrix44&);
 
  /** \brief Sets a dynamic actor's position in the world.
   */
                                      void                   setGlobalPosition (const Vec3&);
  
  /** \brief Sets a dynamic actor's orientation in the world.
  */
                                      void                   setGlobalOrientation(const Matrix33&);
  
  /** \brief Sets a dynamic actor's orientation in the world.
  */
                                      void                   setGlobalOrientationQuat(const Quat&);
  
  /** \brief Retrieves the actors world space transform.
  */
                                      Matrix44               getGlobalPose(void) const;
  
  /** \brief Retrieves the actors world space position.
  */
                                      Vec3                  getGlobalPosition(void) const;
  
  /** \brief Retrieves the actors world space orientation.
  */
                                      Matrix33               getGlobalOrientation(void) const;
  
  /** \brief Retrieves the actors world space orientation.
  */
                                      Quat                  getGlobalOrientationQuat(void) const;
  
  /** \brief The moveGlobal* calls serve to move kinematically controlled dynamic actors through the game world. 
  */
                                      void                   moveGlobalPose(const Matrix44&);
  
  /** \brief The moveGlobal* calls serve to move kinematically controlled dynamic actors through the game world. 
  */
                                      void                   moveGlobalPosition(const Vec3&);
  
  /** \brief The moveGlobal* calls serve to move kinematically controlled dynamic actors through the game world. 
  */
                                      void                   moveGlobalOrientation (const Matrix33&);
  
  /** \brief The moveGlobal* calls serve to move kinematically controlled dynamic actors through the game world. 
  */
                                      void                   moveGlobalOrientationQuat (const Quat&);

  /** \brief Creates a new shape and adds it to the list of shapes of this actor. 
  */
                                      void                   createShape(Shape*);
  
  /** \brief Deletes the specified shape.
  */
                                      void                   releaseShape(Shape*);
  
  /** \brief Returns the number of shapes assigned to the actor.
  */
                                      unsigned int           getNbShapes(void) const;
  
  
  protected: // Functions
  
  /** \internal Classes that inherit from KinematicActor should use this constructor.
  */
                                              KinematicActor(Scene*);
  
  /** \internal Use Scene::createKinematicActor
  */
                                              KinematicActor(RigidBodyPrototype*, Scene*);
  
  /** \internal Use Scene::destroyKinematicActor
  */
  virtual                                    ~KinematicActor(void);

  protected: // Variables
  
  /** \brief Name of the KinematicActor, otherwise a blank string.
  */
                       String          mName;
  
  /** \brief KinematicActor's parent Scene
  */
                       Scene*                mScene;
  
                       Shapes                mShapes;
  
}; // class KinematicActor

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
