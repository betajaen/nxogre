

// New interface between RenderSystem/Streams
// With options of what to request notification of
// rigidbodies, cloth, fluids, etc.
// 
// perhaps that could be an interface of what
// the scene should render. i.e. sum of notifications
// would set what the scene should render in the
// next frame.
 
/*
  
  Assumed that all objects by the RenderSystem are already known about:
  - Use pointers instead of IDs.
  - All can have userData, and transform streamUser (for stream)
  - Perhaps, there could be a TransformObject, which contains a userData field and type
    and can be downcasted.
  - Actor, KinematicActor can inherit from TransformObject.
  - TransformObjects use a ID/ClassType struct.



*/