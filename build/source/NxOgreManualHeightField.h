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

                                                                                       

#ifndef NXOGRE_MANUAL_HEIGHTFIELD_H
#define NXOGRE_MANUAL_HEIGHTFIELD_H

                                                                                       

#include "NxOgreStable.h"
#include "NxOgreCommon.h"

                                                                                       

namespace NxOgre
{

                                                                                       

/** \brief ManualHeightField is a class of functions designed to create PhysX heightfields.
           ManualHeightField can also be used to convert any heightfield file-format to a PhysX one.
    \example
     <code>
      ManualHeightField m;
      m.begin(NxOgre::Enums::HeightFieldType_Convex, 4);
       m.vertex(-1,-1);
       m.vertex(-1, 1);
       m.vertex( 1,-1);
       m.vertex( 1, 1);
      HeightField* heightfield = m.end();
     </code>
     To modify an existing heightfield.
     ManualHeightField m(myHeightField->getHeightFieldData());
     for (unsigned int i=0;i < m.nbVertices();i++)
      m.scaleVertex(i, Vec3(2,2,2) );
     HeightField* myNewScaledHeightField = m.end();
*/
class NxOgrePublicClass ManualHeightField : public GenericBasedAllocatable
{
  
  public: // Functions
  
  enum
  {
   AUTO_CALCULATE_TRIANGLES = -1
  };
  
  /** \brief ManualHeightField constructor.
  */
  ManualHeightField();
  
  /** \brief ManualHeightField copy constructor.
  */
  ManualHeightField(const ManualHeightField& other);
  
  /** \brief Alternative constructor using HeightFieldData.
  */
  ManualHeightField(HeightFieldData* other);
  
  /** \brief ManualHeightField destructor.
  */
 ~ManualHeightField();
  
  /** \brief Assignment operator
  */
  ManualHeightField&  operator=(ManualHeightField& other);
  
  /** \brief Begin a definition of a heightfield using type.
      \param estimatedVerticesSize Rough estimate of how many vertices there are. ManualHeightField will auto-resize if needed.
      \param estimatedTriangleSize Rough estimate of how many triangles there are. If value is "AUTO_CALCULATE_TRIANGLES" then it will
             use the indexCount * 3, if it is a heightfield that uses Triangles, otherwise 0.
      \note If using with an existing HeightFieldData, this function may corrupt the existing data!
  */
  void  begin(unsigned int nbRows, unsigned int nbColumns);
  
  /** \brief Set the name of the heightfield.
  */
  void  name(const String& name);
  
  /** \brief Set the name of the heightfield.
  */
  void  name(const char*);
  
  /** \brief Get the name of the heightfield.
  */
  String  name() const;
  
  /** \brief Clean the heightfielddata
  */
  void  clean();

  /** \brief Use the current heightfield data and deallocate/unreference the existing heightfield data.
      \note Do not use the heightfield data from an existing ManualHeightField as the heightfield data may be unexpectedly deleted!
  */
  void  acquire(HeightFieldData*);

  /** \brief Add a vertex
      \for   Triangle, Convex, Cloth, Tetrahedra.
  */
  void  sample(HeightFieldSample);
  
  /** \brief Set a vertex value
  */
  void  sample(short height, MaterialIdentifier mat0 = 0, MaterialIdentifier mat1 = 0, Enums::HeightFieldTesselation = Enums::HeightFieldTesselation_NE_SW);
  
  /** \brief Does the heightfield meet the criteria for the heightfield type?
  */
  bool isValid() const;
  
  /** \brief Cook the heightfield to a ResourceIdentifier target (default is memory) and return a HeightField to use. HeightField is automatically registered
             by the HeightFieldManager. HeightField name is automatically generated unless HeightFieldManager::name() is used.
      \param cleanUp  Clear the buffers after cooking.
      \param cookingTarget  Tell PhysX to save to a target, in other words. Save the heightfield to a file, save in memory, or to something else.
  */
  HeightField* end(bool cleanUp = true, const Path& cookingPath = MEMORY_PATH);
  
  /** \brief Cook the heightfield to a ResourceIdentifier target (default is memory).
      \param cleanUp  Clear the buffers after cooking.
      \param cookingTarget  Tell PhysX to save to a target, in other words. Save the heightfield to a file, save in memory, or to something else.
  */
  void endCookOnly(bool cleanUp = true, const Path& cookingPath = MEMORY_PATH);
  
  protected: // Variables
  
  NxOgre::SharedPointer<HeightFieldData>             mHeightField;
  
  
}; // class ManualHeightField

                                                                                       

} // namespace NxOgre

                                                                                       

#endif
