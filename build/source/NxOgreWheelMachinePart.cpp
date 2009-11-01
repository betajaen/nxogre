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

                                                                                       
