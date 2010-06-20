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

                                                                                       

#ifndef NXOGRE_SHAPEFLAGS_H
#define NXOGRE_SHAPEFLAGS_H

                                                                                       

namespace NxOgre
{

                                                                                       

/*! flags. ShapeFlags
    desc.
        Flags
    enums.
        Visualisation:8 -- Allow a visualation of this shape in the VisualDebugger.
        NoCollision:16 -- Used only with Compound Shapes, otherwise raise ActorFlags_DisableCollision.
        FeatureIndices:32 -- Enable feature indices in the contact stream.
        DisableRaycasting:64 -- Disable raycasting for this shape.
        PointContactForce:128 -- Enable contact force reporting per contact point in contact stream.
        IsFluidDrain:256 -- Sets the shape to be a fluid drain.
        NoFluids:1024 -- Disable collision with fluids.
        TwoWayFluid:2048 -- Enables the reaction of the shapes rigidbody on fluid collision.
        DisableResponse:4096 -- Disable collision response for this shape.
        DynamicDynamicCCD:8192 -- Enable dynamic-dynamic CCD for this shape.
        DisableSceneQueries:16384 -- Diable participation in raycasts, overlap tests and sweeps.
        IsClothDrain:32768 -- Sets the shape to be a cloth drain.
        NoCloth:65536 -- Disable Collision with Cloth.
        TwoWayCloth:131072 -- Enables the reaction of the shapes rigidbody on cloth collision.
        IsSoftBodyDrain:262144 -- Sets the shape to be a SoftBody drain.
        NoSoftBody:524288 -- Disable Collision with SoftBody.
        TwoWaySoftBody:1048576 -- Enables the reaction of the shapes rigidbody on SoftBody collision.
    default.
        Visualisation | TwoWayCloth | TwoWaySoftBody
*/
struct ShapeFlags
{


  // BEGIN - Serialisation
  // The following code is computer generated. Please do not modify.
  public:


   enum Flags
   {
    // Allow a visualation of this shape in the VisualDebugger.
    Visualisation = 8,
    // Used only with Compound Shapes, otherwise raise ActorFlags_DisableCollision.
    NoCollision = 16,
    // Enable feature indices in the contact stream.
    FeatureIndices = 32,
    // Disable raycasting for this shape.
    DisableRaycasting = 64,
    // Enable contact force reporting per contact point in contact stream.
    PointContactForce = 128,
    // Sets the shape to be a fluid drain.
    IsFluidDrain = 256,
    // Disable collision with fluids.
    NoFluids = 1024,
    // Enables the reaction of the shapes rigidbody on fluid collision.
    TwoWayFluid = 2048,
    // Disable collision response for this shape.
    DisableResponse = 4096,
    // Enable dynamic-dynamic CCD for this shape.
    DynamicDynamicCCD = 8192,
    // Diable participation in raycasts, overlap tests and sweeps.
    DisableSceneQueries = 16384,
    // Sets the shape to be a cloth drain.
    IsClothDrain = 32768,
    // Disable Collision with Cloth.
    NoCloth = 65536,
    // Enables the reaction of the shapes rigidbody on cloth collision.
    TwoWayCloth = 131072,
    // Sets the shape to be a SoftBody drain.
    IsSoftBodyDrain = 262144,
    // Disable Collision with SoftBody.
    NoSoftBody = 524288,
    // Enables the reaction of the shapes rigidbody on SoftBody collision.
    TwoWaySoftBody = 1048576,
    // Default
    DefaultFlags = Visualisation
   };

   ShapeFlags() : flags(DefaultFlags) {}

   inline void reset() {flags = DefaultFlags;}

   inline void add(int flag) {flags |= flag;}

   inline void operator |=(int flag) {flags |= flag;}

   inline void operator +=(int flag) {flags |= flag;}

   inline void remove(int flag) {flags &= ~flag;}

   inline void operator -=(int flag) {flags &= ~flag;}

   inline bool has(int flag) const { return (flags & flag) == flag; }

   inline void from_i(int flag) { flags = flag; }

   inline int to_i() const { return flags; }

   inline operator int() { return flags; }

   inline String to_s() const
   {
    std::ostringstream o;
    o << flags;
    return o.str();
   }

   inline friend std::ostream& operator << (std::ostream& o, const ShapeFlags& flags)
   {
    o << flags.flags;
    return o;
   }

   private: int flags;


  // END - Serialisation. "ShapeFlags-617b368a83842a809bc2daa6ad5a47a3"

};


                                                                                       

} // namespace NxOgre

                                                                                       

#endif
