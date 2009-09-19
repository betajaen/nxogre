/** File: NxOgreMaterial.cpp
    Created on: 13-Nov-08
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
  SharedStringStream message(SharedStringStream::_LARGE); 
  
  message << "An error occured whilst creating a Material.\nThe reason(s) and cause(s) could be:\n\n";
   
  if (mScene == 0)
   message << " - Scene is not created.\n";

  message << Reason::whyAsStream(description).get();
  
  NxOgre_ThrowError(message.get());
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

                                                                                       
