//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__FOOD_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <Food.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Food.h>
#include <Resource.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
Food::Food(const string aResourceId, const int aQuantity, const int aMaxCapacity, const string aUnit, SupplyBay* aSupplyBay, const int aExpirationDays):Resource(aResourceId, aQuantity, aMaxCapacity, aUnit, aSupplyBay){
  this->expirationDays= aExpirationDays;
  if(!(expirationDays >= 0)){  
    throw "Please provide valid expirationDays";
  }  
}

Food::Food(Food& other):Resource(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void Food::toOstream(ostream& os) const{
  Resource::toOstream(os);
  Food* thisptr = const_cast<Food*>(this);
  os << "[" << "expirationDays:" << thisptr->getExpirationDays() << "]";  
}

ostream& operator<<(ostream& os, const Food& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (Food& Right, Food& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.expirationDays!= Left.expirationDays){
     return false;
  }  
}

Food& Food::operator=(Food& other){
  internalCopy(other);
  return *this;  
}

void Food::internalCopy(Food& other){
  this->expirationDays= other.expirationDays;  
}

bool Food::setExpirationDays(const int aNewExpirationDays){
  bool wasSet= false;
  if(expirationDays >= 0){  
    this->expirationDays = aNewExpirationDays;
    wasSet= true;
  }
  return wasSet;  
}

int Food::getExpirationDays(void){
  return this->expirationDays;  
}

size_t Food::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
Food::~Food(){
  //Resource::~Resource();
  this->deleteAssociatedObjects();  
}

void Food::deleteAssociatedObjects(void){
  Resource::deleteAssociatedObjects();  
}
;

