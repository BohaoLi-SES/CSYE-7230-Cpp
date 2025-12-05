//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__CHILDREN_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <Children.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Children.h>
#include <Survivor.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
Children::Children(const string aName, Shelter* aShelter, Facility* aFacility, LivingQuarters* aLivingQuarters, MedicalBay* aMedicalBay, Mission* aMission, const int aEducationLevel):
		guardian(NULL),
    Survivor(aName, aShelter, aFacility, aLivingQuarters, aMedicalBay, aMission){
  this->educationLevel= aEducationLevel;
  this->guardian= NULL;
  if(!(educationLevel >= 0 && educationLevel <= 100)){  
    throw "Please provide a valid educationLevel";
  }  
}

Children::Children(Children& other):
		guardian(NULL),
    Survivor(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void Children::toOstream(ostream& os) const{
  Survivor::toOstream(os);
  Children* thisptr = const_cast<Children*>(this);
  os << "[" << "educationLevel:" << thisptr->getEducationLevel() << "]" << endl;
  (thisptr->getGuardian()!= NULL ?  os << "guardian:" << thisptr->getGuardian() : os << "guardian:" << "NULL");  
}

ostream& operator<<(ostream& os, const Children& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (Children& Right, Children& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.educationLevel!= Left.educationLevel){
     return false;
  }
  if(!compare(Right.guardian, Left.guardian, sizeof Right.guardian)){
    return false;
  }  
}

Children& Children::operator=(Children& other){
  internalCopy(other);
  return *this;  
}

void Children::internalCopy(Children& other){
  this->educationLevel= other.educationLevel;
  copyObject(other.guardian, this->guardian, sizeof other.guardian);  
}

bool Children::setEducationLevel(const int aNewEducationLevel){
  bool wasSet= false;
  if(educationLevel >= 0){  
    this->educationLevel = aNewEducationLevel;
    wasSet= true;
  }
  return wasSet;  
}

bool Children::setGuardian(Survivor* aNewGuardian){
  bool wasSet= false;
  Survivor* existingGuardian = this->guardian;
  this->guardian = aNewGuardian;
  if (existingGuardian != NULL && existingGuardian !=aNewGuardian){
    existingGuardian->removeChildren(this);
  }
  
  if (aNewGuardian != NULL){
    aNewGuardian->addChildren(this);
  }
  wasSet= true;
  return wasSet;  
}

int Children::getEducationLevel(void){
  return this->educationLevel;  
}

Survivor* Children::getGuardian(void){
  return this->guardian;  
}

size_t Children::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
Children::~Children(){
  //Survivor::~Survivor();
  this->deleteAssociatedObjects();
  delete guardian;  
}

void Children::deleteAssociatedObjects(void){
  if(this->guardian != NULL){
    Survivor* placeholderGuardian = this->guardian;
    this->guardian = NULL;
    placeholderGuardian->removeChildren(this);
  }  
}
;

