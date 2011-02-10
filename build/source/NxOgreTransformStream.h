

// Like a Transform Notification but instead of using a callback,
// the changes are sent as data.

/*
 
 Use the TransformNotification class as a basis, and Stream wraps around it (like a mini-RenderSystem)

 Assumptions
 ===========

  -- everything needs an id.
      numerical? IDs can't be reused.

  -- everything needs a type.
      numerical, enum?

  -- everything uses TransformObject
      solves the id/type problem with TransformID

  -- every action needs a type/id?
      numerical, enum?

  -- each action or new state contains;
      - object id
      - object action
      - object data
  
  -- each property name of object data, needs an id.
      numerical, enum?

  -- each property value of object data, needs to be serialised.
      NxOgre::Value, Copying data exactly. What about endian?

  -- each property name, has an expected type.
      - reduces the need to describe the data.
      - less need to markup the data into something more generic; i.e. string, value

  -- each action id, won't have the same length.
      - some actions require more data than the other.
      - include action length? have an action terminator - null byte?

  -- what about data loss?
      - object creation/deletion may be missed
      - transform or change_property to objects that have not been "created"/"destroyed" yet.
      - Client can request packets, of objects with out ids?
   
  -- what about receiving data in the wrong order?
      - id or time system? to reorganise packets by id/time? Each ID is unique.

 Examples
 ========

    test_object_id: {1, 100}
    action_ids:
              - describe;        Describe an object, but don't create it, acts like a property_change. Descriptions last some time after creating.
              - new;             Create one instance of the object
              - delete           Delete instance of the object.
              - transform        Transform an object
              - property_change  Change property/properties of an object.

    property_ids:
              - id
              - type
              - transform
              - mass
              - shape
              - 
    
    sample_data_packets:
     
     [0]    {action} describe, <id>, {shape} <shape_data>, {transform} <transform> {user} userData_int
     [1]    {action} transform, <id> <transform>
     [100]  {action} delete, <id> {property_id, id} 100
  
*/
