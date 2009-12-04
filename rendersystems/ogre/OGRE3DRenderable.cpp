/** File: OGRE3DRenderable.cpp
    Created on: 13-Feb-09
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

*/

                                                                                       

#include "OGRE3DRenderable.h"
#include "OGRE3DRenderSystem.h"
#include "Ogre.h"

                                                                                       

// operation, normals, colour, indexes, texture-coords, 16bit indexes.
OGRE3DRenderable::RenderProfile OGRE3DRenderable::NXOGRE_VISUALDEBUGGER =
                  OGRE3DRenderable::RenderProfile (Ogre::RenderOperation::OT_LINE_LIST, false, true, false, false, false);

OGRE3DRenderable::RenderProfile OGRE3DRenderable::NXOGRE_PHYSXMESH =
                  OGRE3DRenderable::RenderProfile (Ogre::RenderOperation::OT_TRIANGLE_LIST, true, false, true, true, false);

OGRE3DRenderable::RenderProfile OGRE3DRenderable::NXOGRE_PARTICLEPOINTS =
                  OGRE3DRenderable::RenderProfile (Ogre::RenderOperation::OT_POINT_LIST, false, false, false, false, false);

OGRE3DRenderable::RenderProfile OGRE3DRenderable::NXOGRE_SOFTBODY =
                  OGRE3DRenderable::RenderProfile (Ogre::RenderOperation::OT_TRIANGLE_LIST, false, false, true, false, false);

                                        

OGRE3DRenderable::RenderProfile::RenderProfile()
: mRenderOperation(Ogre::RenderOperation::OT_POINT_LIST),
  usesNormals(false),
  usesColourVertices(false),
  usesIndexes(false),
  uses16BitIndexes(false),
  usesTextureCoordinates(false)
{
}

OGRE3DRenderable::RenderProfile::RenderProfile(Ogre::RenderOperation::OperationType op, bool n, bool c, bool i, bool t, bool _16)
: mRenderOperation(op),
  usesNormals(n),
  usesColourVertices(c),
  usesIndexes(i),
  uses16BitIndexes(_16),
  usesTextureCoordinates(t)
{
}

OGRE3DRenderable::OGRE3DRenderable(NxOgre::Enums::RenderableType type)
: NxOgre::Renderable(type)
{
 _createProfile(mType);
 _initialise();
}

OGRE3DRenderable::~OGRE3DRenderable()
{
 NxOgre_Delete(mRenderOp.vertexData);
 NxOgre_Delete(mRenderOp.indexData);
}

void OGRE3DRenderable::drawSoftBodySimple(NxOgre::PhysXMeshData* data, const NxOgre::Bounds3& bounds)
{
 // Early escape.
 if (data->getNbVertices() < 3)
 {
  mBox.setExtents(Ogre::Vector3::ZERO, Ogre::Vector3::ZERO);
  return;
 }
 
 // Resize buffers if necessary.
 _resize(data->getNbVertices(), data->getNbIndices());
 
 // Write the vertices.
 mVertexBuffer->writeData(0, 3 * data->getNbVertices() * sizeof(float), data->getVertices() );
 
 // Write the indices.
 mRenderOp.indexData->indexBuffer->writeData(0, data->getNbIndices() * sizeof(unsigned int), data->getIndices() );
 
 // Set the extents.
 mBox.setExtents(bounds.min.as<Ogre::Vector3>(), bounds.max.as<Ogre::Vector3>());
 
 // Done.
}

void OGRE3DRenderable::drawCloth(NxOgre::PhysXMeshData* data, NxOgre::Buffer<float>& textureCoords, const NxOgre::Bounds3& bounds)
{
 // Early escape.
 if (data->getNbVertices() < 3)
 {
  mBox.setExtents(Ogre::Vector3::ZERO, Ogre::Vector3::ZERO);
  return;
 }
 
 // Resize buffers if necessary.
 _resize(data->getNbVertices(), data->getNbIndices());
 
 // Write the vertices.
 mVertexBuffer->writeData(0, 3 * data->getNbVertices() * sizeof(float), data->getVertices() );
 
 // Write the normals.
 mNormalBuffer->writeData(0, 3 * data->getNbVertices() * sizeof(float), data->getNormals() );

 // Write the texture coords.
 mTextureCoordsBuffer->writeData(0, textureCoords.size() * sizeof(float), textureCoords.first() );

 // Write the indices.
 mRenderOp.indexData->indexBuffer->writeData(0, data->getNbIndices() * sizeof(unsigned int), data->getIndices() );
 
 // Set the extents.
 mBox.setExtents(bounds.min.as<Ogre::Vector3>(), bounds.max.as<Ogre::Vector3>());
 
 // Done.
}

void OGRE3DRenderable::drawClothFast(NxOgre::PhysXMeshData* data, const NxOgre::Bounds3& bounds)
{
 
 // Resize buffers if necessary.
 _resize(data->getNbVertices(), data->getNbIndices());

 // Write the vertices.
 mVertexBuffer->writeData(0, 3 * data->getNbVertices() * sizeof(float), data->getVertices() );
 
 // Write the normals.
 mNormalBuffer->writeData(0, 3 * data->getNbVertices() * sizeof(float), data->getNormals() );

 // Set the extents.
 mBox.setExtents(bounds.min.as<Ogre::Vector3>(), bounds.max.as<Ogre::Vector3>());
 
 // Done.
}
void OGRE3DRenderable::drawVisualDebugger(NxOgre::VisualDebuggerMeshData* data)
{
 _resize(data->getNbLines() * 2, 0);

 // Write the vertices.
 mVertexBuffer->writeData(0, 3 * data->getNbLines() * 2 * sizeof(float), data->getLines() );

 mVertexColourBuffer->writeData(0, data->getNbLines() * 2 * sizeof(unsigned int), data->getColours() );

 mBox.setInfinite();
 
}

void OGRE3DRenderable::_createProfile(NxOgre::Enums::RenderableType type)
{
 switch(type)
 {
  case NxOgre::Enums::RenderableType_VisualDebugger:
   mProfile = OGRE3DRenderable::NXOGRE_VISUALDEBUGGER;
  break;
  
  case NxOgre::Enums::RenderableType_PhysXMesh:
   mProfile = OGRE3DRenderable::NXOGRE_PHYSXMESH;
  break;
  
  case NxOgre::Enums::RenderableType_ParticlePoints:
   mProfile = OGRE3DRenderable::NXOGRE_PARTICLEPOINTS;
  break;
  
  case NxOgre::Enums::RenderableType_SoftBody:
   mProfile = OGRE3DRenderable::NXOGRE_SOFTBODY;
  break;
  
 }
}

void OGRE3DRenderable::_initialise()
{
 // Op.
 mRenderOp.operationType = mProfile.mRenderOperation;

 // Vertices and other vertex bits.
 mRenderOp.vertexData  = new Ogre::VertexData;

 // Main vertex declartion. It is assumed that a Renderable has vertices.
 Ogre::VertexDeclaration* vDecl = mRenderOp.vertexData->vertexDeclaration;
 vDecl->addElement(VertexDeclaration_Position, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION);
 
 // Normals.
 if (mProfile.usesNormals)
  vDecl->addElement(VertexDeclaration_Normal, 0, Ogre::VET_FLOAT3, Ogre::VES_NORMAL);
 
 // Vertex Colours.
 if (mProfile.usesColourVertices)
  vDecl->addElement(VertexDeclaration_Colour, 0, Ogre::VET_COLOUR, Ogre::VES_DIFFUSE);
 
 if (mProfile.usesTextureCoordinates)
  vDecl->addElement(VertexDeclaration_TextureCoordinates, 0, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES);

 // Vertex buffer capacity is zero.
 mVertexBufferCapacity = 0;


 // Do the indexes. If it has one.
 if (mRenderOp.useIndexes = mProfile.usesIndexes)
  mRenderOp.indexData = new Ogre::IndexData;


 mIndexBufferCapacity = 0;
}

void OGRE3DRenderable::_resize(size_t vertexCount, size_t indexCount)
{
  // Prepare vertex buffer
  size_t newVertCapacity = mVertexBufferCapacity;
  if ((vertexCount > mVertexBufferCapacity) ||
      (!mVertexBufferCapacity))
  {
    // vertexCount exceeds current capacity!
    // It is necessary to reallocate the buffer.

    // Check if this is the first call
    if (!newVertCapacity)
      newVertCapacity = 1;

    // Make capacity the next power of two
    while (newVertCapacity < vertexCount)
      newVertCapacity <<= 1;
  }
  else if (vertexCount < mVertexBufferCapacity>>1) {
    // Make capacity the previous power of two
    while (vertexCount < newVertCapacity>>1)
      newVertCapacity >>= 1;
  }
  
  if (newVertCapacity != mVertexBufferCapacity) 
  {
    mVertexBufferCapacity = newVertCapacity;
    
    // Create new vertex buffer
    mVertexBuffer = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
        mRenderOp.vertexData->vertexDeclaration->getVertexSize(VertexDeclaration_Position),
        mVertexBufferCapacity,
        Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY); // TODO: Custom HBU_?
    
    // Bind buffer
    mRenderOp.vertexData->vertexBufferBinding->setBinding(VertexDeclaration_Position, mVertexBuffer);
    
    // Colour vertices.
    if (this->mProfile.usesColourVertices)
    {
     // Create new vertexColour buffer
     mVertexColourBuffer = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
         mRenderOp.vertexData->vertexDeclaration->getVertexSize(VertexDeclaration_Colour),
         mVertexBufferCapacity,
         Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY); // TODO: Custom HBU_?
     
     // Bind buffer
     mRenderOp.vertexData->vertexBufferBinding->setBinding(VertexDeclaration_Colour, mVertexColourBuffer);
    }

    // Normals.
    if (this->mProfile.usesNormals)
    {
     // Create new vertexColour buffer
     mNormalBuffer = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
         mRenderOp.vertexData->vertexDeclaration->getVertexSize(VertexDeclaration_Normal),
         mVertexBufferCapacity,
         Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY); // TODO: Custom HBU_?
     
     // Bind buffer
     mRenderOp.vertexData->vertexBufferBinding->setBinding(VertexDeclaration_Normal, mNormalBuffer);
    }

    // Texture coords.
    if (this->mProfile.usesTextureCoordinates)
    {
     // Create new vertexColour buffer
     mTextureCoordsBuffer = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(
         mRenderOp.vertexData->vertexDeclaration->getVertexSize(VertexDeclaration_TextureCoordinates),
         mVertexBufferCapacity,
         Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY); // TODO: Custom HBU_?
     
     // Bind buffer
     mRenderOp.vertexData->vertexBufferBinding->setBinding(VertexDeclaration_TextureCoordinates, mTextureCoordsBuffer);
    }

  }
  // Update vertex count in the render operation
  mRenderOp.vertexData->vertexCount = vertexCount;

  if (mProfile.usesIndexes)
  {
    OgreAssert(indexCount <= std::numeric_limits<unsigned short>::max(), "indexCount exceeds 16 bit");

    size_t newIndexCapacity = mIndexBufferCapacity;
    // Prepare index buffer
    if ((indexCount > newIndexCapacity) || (!newIndexCapacity))
    {
      // indexCount exceeds current capacity!
      // It is necessary to reallocate the buffer.
      // Check if this is the first call
      if (!newIndexCapacity)
        newIndexCapacity = 1;
      // Make capacity the next power of two
      while (newIndexCapacity < indexCount)
        newIndexCapacity <<= 1;
    }
    else if (indexCount < newIndexCapacity>>1) 
    {
      // Make capacity the previous power of two
      while (indexCount < newIndexCapacity>>1)
        newIndexCapacity >>= 1;
    }
    
    if (newIndexCapacity != mIndexBufferCapacity)
    {
      mIndexBufferCapacity = newIndexCapacity;
      // Create new index buffer
      mIndexBuffer = mRenderOp.indexData->indexBuffer =
        Ogre::HardwareBufferManager::getSingleton().createIndexBuffer(
          Ogre::HardwareIndexBuffer::IndexType(!mProfile.uses16BitIndexes),
          mIndexBufferCapacity,
          Ogre::HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY); // TODO: Custom HBU_?
    }
    
    // Update index count in the render operation
    mRenderOp.indexData->indexCount = indexCount;
  }
}

float OGRE3DRenderable::getBoundingRadius(void) const
{
 return Ogre::Math::Sqrt(std::max(mBox.getMaximum().squaredLength(), mBox.getMinimum().squaredLength()));
}

float OGRE3DRenderable::getSquaredViewDepth(const Ogre::Camera* cam) const
{
 Ogre::Vector3 vMin, vMax, vMid, vDist;
 vMin = mBox.getMinimum();
 vMax = mBox.getMaximum();
 vMid = ((vMax - vMin) * 0.5) + vMin;
 vDist = cam->getDerivedPosition() - vMid;
 return vDist.squaredLength();
}
