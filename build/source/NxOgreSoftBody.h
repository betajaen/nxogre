/** File: NxOgreSoftBody.h
    Created on: 23-Jun-09
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

#ifndef NXOGRE_SOFTBODY_H
#define NXOGRE_SOFTBODY_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreTimeListener.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass SoftBody : public PointerClass<Classes::_SoftBody>, public TimeListener
{
 
 friend class Scene;
 friend class Functions::ArrayFunctions<SoftBody*>::Write;

 public:
  
    /** \brief Get the renderable.
    */
    Renderable*                                 getRenderable();
  
    /** \brief Get the mesh shared by the cloth.
    */
    Mesh*                                       getMesh();
    
    /** \internal
    */
    NxSoftBody*                                 getPhysXSoftBody();

    /** \internal
    */
    PhysXMeshData*                              getPhysXMeshData();

    /** \brief Get the cloth's name.
    */
    String                                      getName();
  
 protected:
  
  /** \brief Use Scene::createSoftBody
  */
                                                  SoftBody(const SoftBodyDescription&, Renderable*, Enums::Priority, Scene*);
  
  /** \brief Use Scene::destroySoftBody
  */
  virtual                                        ~SoftBody(void);
  
  /** \brief
  */
  bool                                            advance(float deltaTime, const Enums::Priority&);
  
  /** \brief
  */
  void                                            updateSoftBodyMesh();
  
 protected:
  
  /** \brief Scene that the cloth belongs to.
  */
  Scene*                                        mScene;
  
  /** \brief Actual cloth.
  */
  NxSoftBody*                                   mSoftBody;
  
  /** \brief Mesh being shared by the soft body.
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

}; // class Cloth

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
