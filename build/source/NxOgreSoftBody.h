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

                                                                                       

#ifndef NXOGRE_SOFTBODY_H
#define NXOGRE_SOFTBODY_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"
#include "NxOgreTimeListener.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief
*/
class NxOgrePublicClass SoftBody : public NonRigidBodyBasedAllocatable, public TimeListener
{
  
  NXOGRE_GC_FRIEND_NEW4
  NXOGRE_GC_FRIEND_DELETE
  
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
    MeshRenderable*                             getMeshRenderable();

    /** \brief Get the cloth's name.
    */
    String                                      getName();
  
 protected:
  
  /** \brief Use Scene::createSoftBody
  */
                                                  SoftBody(const SoftBodyDescription&, Renderable*, Enums::Priority, Scene*);
  
  /** \brief Use Scene::destroySoftBody
  */
  virtual                                        ~SoftBody();
  
  /** \brief
  */
  bool                                            advance(float deltaTime, const Enums::Priority&, const Enums::SceneFunction&);
  
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
  MeshRenderable*                               mMeshData;

  /** \brief Possible name of the mesh.
  */
  String                                        mName;
  
  /** \brief Current render priority.
  */
  Enums::Priority                               mPriority;

}; // class Cloth

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
