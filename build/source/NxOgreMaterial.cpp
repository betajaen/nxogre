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
#include "NxOgreMaterial.h"
#include "NxOgreErrorStream.h"
#include "NxOgreScene.h"
#include "NxOgrePrototypeFunctions.h"
#include "NxOgreReason.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Material::Material(NxMaterial* material, Scene* scene)
: mMaterial(material), mScene(scene), mName(BLANK_STRING), mNameHash(BLANK_HASH)
{
}

Material::Material(const MaterialDescription& description, Scene* scene)
: mMaterial(0), mScene(scene), mName(description.mName)
{
 mNameHash = Strings::hash(mName);
 create(description);
}

Material::~Material()
{
}

String Material::getName() const
{
 return mName;
}

StringHash Material::getNameHash() const
{
 return mNameHash;
}

void Material::create(const MaterialDescription& desc)
{
 
 NxOgre_ThrowExceptionIfNull(mScene, Classes::_Scene);
 
 NxMaterialDesc description;
 
 description.dirOfAnisotropy = desc.mDirectionOfAnisotropy.as<NxVec3>();
 description.dynamicFriction = desc.mDynamicFriction;
 description.dynamicFrictionV = desc.mVDynamicFriction;
 description.flags = desc.mFlags;
 description.frictionCombineMode = NxCombineMode(int(desc.mFrictionCombineMode));
 description.restitution = desc.mRestitution;
 description.restitutionCombineMode = NxCombineMode(int(desc.mResitutionCombineMode));
 description.staticFriction = desc.mStaticFriction;
 description.staticFrictionV = desc.mVStaticFriction;
 
 if (description.isValid() == false)
 {
  NxOgre_ThrowException(DescriptionInvalidException, Reason::Exceptionise(description), Classes::_Material);
  return;
 }

 mMaterial = mScene->getScene()->createMaterial(description);
}

void Material::destroy()
{
 mScene->getScene()->releaseMaterial(*mMaterial);
 mMaterial = 0;
}

MaterialIdentifier Material::getIdentifier() const
{
 return mMaterial->getMaterialIndex();
}

Real Material::getRestitution() const
{
 return mMaterial->getRestitution();
}

Real Material::getStaticFriction() const
{
 return mMaterial->getStaticFriction();
}

Real Material::getDynamicFriction() const
{
 return mMaterial->getDynamicFriction();
}

void Material::setRestitution(Real rest)
{
 mMaterial->setRestitution(rest);
}

void Material::setStaticFriction(Real coef)
{
 mMaterial->setStaticFriction(coef);
}

void Material::setDynamicFriction(Real coef)
{
 mMaterial->setDynamicFriction(coef);
}

void Material::setAll(Real restitution, Real staticFriction, Real dynamicFriction)
{
 mMaterial->setRestitution(restitution);
 mMaterial->setStaticFriction(staticFriction);
 mMaterial->setDynamicFriction(dynamicFriction);

}

                                                                                       

} // namespace NxOgre

                                                                                       
