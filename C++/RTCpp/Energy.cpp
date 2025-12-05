//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__ENERGY_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <Energy.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Energy.h>
#include <Resource.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
Energy::Energy(const string aResourceId, const int aQuantity, const int aMaxCapacity, const string aUnit, SupplyBay* aSupplyBay, const int aPowerOutput):Resource(aResourceId, aQuantity, aMaxCapacity, aUnit, aSupplyBay){
  this->powerOutput= aPowerOutput;
  if(!(powerOutput > 0)){  
    throw "Please provide a valid powerOutput";
  }  
}

Energy::Energy(Energy& other):Resource(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void Energy::toOstream(ostream& os) const{
  Resource::toOstream(os);
  Energy* thisptr = const_cast<Energy*>(this);
  os << "[" << "powerOutput:" << thisptr->getPowerOutput() << "]";  
}

ostream& operator<<(ostream& os, const Energy& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (Energy& Right, Energy& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.powerOutput!= Left.powerOutput){
     return false;
  }  
}

Energy& Energy::operator=(Energy& other){
  internalCopy(other);
  return *this;  
}

void Energy::internalCopy(Energy& other){
  this->powerOutput= other.powerOutput;  
}

bool Energy::setPowerOutput(const int aNewPowerOutput){
  bool wasSet= false;
  if(powerOutput > 0){  
    this->powerOutput = aNewPowerOutput;
    wasSet= true;
  }
  return wasSet;  
}

int Energy::getPowerOutput(void){
  return this->powerOutput;  
}

size_t Energy::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
Energy::~Energy(){
  //Resource::~Resource();
  this->deleteAssociatedObjects();  
}

void Energy::deleteAssociatedObjects(void){
  Resource::deleteAssociatedObjects();  
}
;

