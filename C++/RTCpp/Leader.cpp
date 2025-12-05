//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__LEADER_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <Leader.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Leader.h>
#include <Survivor.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
Leader::Leader(const string aName, Shelter* aShelter, Facility* aFacility, LivingQuarters* aLivingQuarters, MedicalBay* aMedicalBay, Mission* aMission, const int aCharisma):Survivor(aName, aShelter, aFacility, aLivingQuarters, aMedicalBay, aMission){
  this->charisma= aCharisma;
  if(!(charisma > 0)){  
    throw "Please provide a valid charisma";
  }  
}

Leader::Leader(Leader& other):Survivor(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void Leader::toOstream(ostream& os) const{
  Survivor::toOstream(os);
  Leader* thisptr = const_cast<Leader*>(this);
  os << "[" << "charisma:" << thisptr->getCharisma() << "]";  
}

ostream& operator<<(ostream& os, const Leader& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (Leader& Right, Leader& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.charisma!= Left.charisma){
     return false;
  }  
}

Leader& Leader::operator=(Leader& other){
  internalCopy(other);
  return *this;  
}

void Leader::internalCopy(Leader& other){
  this->charisma= other.charisma;  
}

bool Leader::setCharisma(const int aNewCharisma){
  bool wasSet= false;
  if(charisma > 0){  
    this->charisma = aNewCharisma;
    wasSet= true;
  }
  return wasSet;  
}

int Leader::getCharisma(void){
  return this->charisma;  
}

size_t Leader::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
Leader::~Leader(){
  //Survivor::~Survivor();
  this->deleteAssociatedObjects();  
}

void Leader::deleteAssociatedObjects(void){
  Survivor::deleteAssociatedObjects();  
}
;

