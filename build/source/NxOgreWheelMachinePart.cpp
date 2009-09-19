/** File: NxOgreWheelMachinePart.cpp
    Created on: 19-May-09
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
#include "NxOgreWheelMachinePart.h"
#include "NxOgrePointRenderable.h"
#include "NxOgreWheel.h"

#include "NxPhysics.h"

                                                                                       

namespace NxOgre
{

                                                                                       

WheelMachinePart::WheelMachinePart()
: mWheel(0), mPointRenderable(0), mWheelRollAngle(0)
{
}

WheelMachinePart::WheelMachinePart(Wheel* wheel, PointRenderable* pointRenderable)
: mWheel(wheel), mPointRenderable(pointRenderable), mWheelRollAngle(0)
{
}

WheelMachinePart::~WheelMachinePart()
{
}

void WheelMachinePart::simulate(float time)
{
 NxWheelShape* wheel = mWheel->getWheelShape();

 mWheelRollAngle += wheel->getAxleSpeed() * time;
	
	while (mWheelRollAngle > NxTwoPi)	//normally just 1x
		mWheelRollAngle -= NxTwoPi;
	while (mWheelRollAngle < -NxTwoPi)	//normally just 1x
		mWheelRollAngle += NxTwoPi;

	NxMat34 wheelPose = wheel->getGlobalPose();

	NxWheelContactData wcd;
	wcd.contactPosition = 0;

	NxShape* s = wheel->getContact(wcd);

	NxReal  stravel = wheel->getSuspensionTravel(), radius = wheel->getRadius();

	if(s) {
		wheelPose.t += wheel->getLocalOrientation() * wheelPose.M * NxVec3( 0.0, radius - wcd.contactPosition, 0.0);
	} else {
		wheelPose.t += wheelPose.M * NxVec3( 0.0, -stravel , 0.0 );
	}

	NxMat33 Heading, Pitch;
	Heading.rotY( wheel->getSteerAngle() );
	Pitch.rotX( mWheelRollAngle );

	wheelPose.M = wheelPose.M * Heading * Pitch; 	


  NxQuat quat;wheelPose.M.toQuat(quat);
  mPointRenderable->render(wheelPose.t, quat);
}

                                                                                       

} // namespace NxOgre

                                                                                       
