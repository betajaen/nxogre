/** File: NxOgreCharacterController.h
    Created on: 02-Dec-09
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

#ifndef NXOGREADDONCHARACTERCONTROLLER_COMMON_H
#define NXOGREADDONCHARACTERCONTROLLER_COMMON_H

#include "NxOgre.h"

                                                                                       

#   ifdef NXOGRE_ADDON_CHARACTER_CONTROLLER
#     define NxOgreCCExportClass
#     define NxOgreCCExportFunction
#   else
#     define NxOgreCCExportClass
#     define NxOgreCCExportFunction
#   endif

class NxController;
class NxControllerManager;

namespace NxOgre
{

namespace Enums
{
 enum ControllerType
 {
  ControllerType_Box,
  ControllerType_Sphere
 };
 
 enum ControllerInteractionFlag
 {
  ControllerInteractionFlag_Include,
  ControllerInteractionFlag_Exclude,
  ControllerInteractionFlag_UseFilter
 };
 
 enum ControllerAction
 {
  ControllerAction_None,
  ControllerAction_Push
 };
 
 enum ControlerFlag
 {
  ControllerFlag_Sides = (1<<0),
  ControllerFlag_Up    = (1<<1),
  ControllerFlag_Down  = (1<<2)
 };
 
}

class  ControllerDescription;
class  Controller;
class  ControllerAllocator;
struct ControllerShapeHit;
class  ControllerCallback;
class  ControllerManager;
class  PhysXControllerCallback;

}

                                                                                       

#endif
