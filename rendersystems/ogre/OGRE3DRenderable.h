/** File: OGRE3DRenderable.h
    Created on: 25-Nov-08
    Author: Robin Southern "betajaen"
    

    Copyright (c) 2008-2009 Robin Southern

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
    
    Please Note:
    
    This code and the class known as "OGRE3DRenderable" was derived from the DynamicRenderable class
    posted on the Ogre3D Wiki http://www.ogre3d.org/wiki/index.php/DynamicGrowingBuffers
*/

#ifndef OGRE3D_RENDERABLE_H
#define OGRE3D_RENDERABLE_H

                                                                                       

#include "NxOgre.h"
#include "OGRE3DCommon.h"
#include <OgreSimpleRenderable.h>

                                                                                       


/** \brief A OGRE3DBody is just an Actor that is "rendered" on the screen. Not only containing
           the standard physics properties and functions of an Actor. It also contains some
           information describing the object visually; what shape it is, it's dimensions and
           it's colour. Once combined that with the getPose() function from Actor. It's pretty
           easy to use all of that information to draw something on the screen. Of course in
           different types of RenderSystems available; the render information would be different.
           Ogre's for example wouldn't be as low-level, and would only contain a pointer to a node
           on a scenegraph, as well as reference to the mesh it is using.

*/
class OGRE3DExportClass OGRE3DRenderable : public NxOgre::PointerClass<_OGRE3DRenderable>, public NxOgre::Renderable, public Ogre::SimpleRenderable
{
  
  public:
  
   /** \brief Required since Actor is also a "PointerClass".
   */
   using ::NxOgre::PointerClass<_OGRE3DRenderable>::operator new;
   
    /** \brief Required since Actor is also a "PointerClass".
    */
   using ::NxOgre::PointerClass<_OGRE3DRenderable>::operator delete;
   
    
  public:
     
     enum VertexDeclaration
     {
      VertexDeclaration_Position           = 0,
      VertexDeclaration_TextureCoordinates = 1,
      VertexDeclaration_Normal             = 2,
      VertexDeclaration_Colour             = 3,
     };

     struct RenderProfile
     {
      RenderProfile();
      // operation, normals, colour, indexes, texture-coords, 16bit indexes.
      RenderProfile(Ogre::RenderOperation::OperationType op, bool n, bool c, bool i, bool t, bool _16);
      bool usesNormals;
      bool usesColourVertices;
      bool usesIndexes;
      bool uses16BitIndexes;
      bool usesTextureCoordinates;
      Ogre::RenderOperation::OperationType mRenderOperation;
     };
     
     static RenderProfile NXOGRE_VISUALDEBUGGER;
     static RenderProfile NXOGRE_PHYSXMESH;
     static RenderProfile NXOGRE_PARTICLEPOINTS;
     static RenderProfile NXOGRE_SOFTBODY;
     
     /** \brief
     */
     OGRE3DRenderable(NxOgre::Enums::RenderableType);
     
     /** \brief
     */
    ~OGRE3DRenderable(void);
          
     /** \brief Text
     */
     void                                      drawSoftBodySimple(NxOgre::PhysXMeshData*, const NxOgre::Bounds3&);
     
     /** \brief Text
     */
     void                                      drawCloth(NxOgre::PhysXMeshData*, NxOgre::Buffer<float>& textureCoords, const NxOgre::Bounds3&);
     
     /** \brief Text
     */
     void                                      drawClothFast(NxOgre::PhysXMeshData*, const NxOgre::Bounds3&);
     
     /** \brief Text
     */
     void                                      drawVisualDebugger(NxOgre::VisualDebuggerMeshData*);
     
     /** \brief
     */
     Ogre::Real                                getBoundingRadius(void) const;
     
     /** \brief
     */
     Ogre::Real                                getSquaredViewDepth(const Ogre::Camera* cam) const;
     
  protected: // functions
     
     inline void _createProfile(NxOgre::Enums::RenderableType);
     inline void _initialise();
     inline void _resize(size_t vertexCount = 0, size_t indexCount = 0);
     
  protected: // functions
     
     RenderProfile                        mProfile;
     
     /** \brief Maximum capacity of the currently allocated vertex buffer.
     */
     size_t                               mVertexBufferCapacity;
     
     /** \brief Maximum capacity of the currently allocated index buffer.
     */
     size_t                               mIndexBufferCapacity;
     
     //
     Ogre::HardwareVertexBufferSharedPtr  mVertexBuffer;
     
     //
     Ogre::HardwareVertexBufferSharedPtr  mVertexColourBuffer;
     
     //
     Ogre::HardwareVertexBufferSharedPtr  mNormalBuffer;
     
     //
     Ogre::HardwareVertexBufferSharedPtr  mTextureCoordsBuffer;
     
     //
     Ogre::HardwareIndexBufferSharedPtr   mIndexBuffer;


};

                                                                                       

#endif
