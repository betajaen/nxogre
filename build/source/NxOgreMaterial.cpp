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
#include "NxOgreMaterialPrototype.h"
#include "NxOgrePrototypeFunctions.h"
#include "NxOgreReason.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

Material::Material(NxMaterial* material, Scene* scene)
: mMaterial(material), mScene(scene)
{
}

Material::Material(MaterialPrototype* prototype, Scene* scene)
: mMaterial(0), mScene(scene)
{
 create(prototype);
}

Material::~Material(void)
{
}

void Material::create(MaterialPrototype* prototype)
{
 if (mScene == 0)
 {
  NxOgre_ThrowError("Tried to create a Material without a valid Scene");
  return;
 }

 NxMaterialDesc description;
 Functions::PrototypeFunctions::MaterialPrototypeToNxMaterialDesc(prototype, description);

 if (description.isValid() == false)
 {
  NxOgre_ThrowException(DescriptionInvalidException, Reason::Exceptionise(description), Classes::_Material);
  return;
 }

 mMaterial = mScene->getScene()->createMaterial(description);
}

void Material::destroy(void)
{
 mScene->getScene()->releaseMaterial(*mMaterial);
 mMaterial = 0;
}

MaterialIdentifier Material::getIdentifier(void) const
{
 return mMaterial->getMaterialIndex();
}

Real Material::getRestitution(void) const
{
 return mMaterial->getRestitution();
}

Real Material::getStaticFriction(void) const
{
 return mMaterial->getStaticFriction();
}

Real Material::getDynamicFriction(void) const
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

                                                                                       

} // namespace NxOgre

                                                                                       
