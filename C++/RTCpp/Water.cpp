//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__WATER_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <Water.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Water.h>
#include <Resource.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
Water::Water(const string aResourceId, const int aQuantity, const int aMaxCapacity, const string aUnit, SupplyBay* aSupplyBay, const double aPurityLevel):Resource(aResourceId, aQuantity, aMaxCapacity, aUnit, aSupplyBay){
  this->purityLevel= aPurityLevel;
  if(!(purityLevel >= 0 && purityLevel <= 100 && purityLevel >= 70)){  
    throw "Please provide a valid purityLevel";
  }  
}

Water::Water(Water& other):Resource(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void Water::toOstream(ostream& os) const{
  Resource::toOstream(os);
  Water* thisptr = const_cast<Water*>(this);
  os << "[" << "purityLevel:" << thisptr->getPurityLevel() << "]";  
}

ostream& operator<<(ostream& os, const Water& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (Water& Right, Water& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.purityLevel!= Left.purityLevel){
     return false;
  }  
}

Water& Water::operator=(Water& other){
  internalCopy(other);
  return *this;  
}

void Water::internalCopy(Water& other){
  this->purityLevel= other.purityLevel;  
}

bool Water::setPurityLevel(double aNewPurityLevel){
  bool wasSet= false;
  if(purityLevel >= 0 && purityLevel >= 70){  
    this->purityLevel = aNewPurityLevel;
    wasSet= true;
  }
  return wasSet;  
}

double Water::getPurityLevel(void){
  return this->purityLevel;  
}

size_t Water::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
Water::~Water(){
  //Resource::~Resource();
  this->deleteAssociatedObjects();  
}

void Water::deleteAssociatedObjects(void){
  Resource::deleteAssociatedObjects();  
}
;

