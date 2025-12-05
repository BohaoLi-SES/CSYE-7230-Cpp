//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__MEDICINE_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <Medicine.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Medicine.h>
#include <Resource.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
Medicine::Medicine(const string aResourceId, const int aQuantity, const int aMaxCapacity, const string aUnit, SupplyBay* aSupplyBay, const string aMedicineType):Resource(aResourceId, aQuantity, aMaxCapacity, aUnit, aSupplyBay){
  this->medicineType= aMedicineType;  
}

Medicine::Medicine(Medicine& other):Resource(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void Medicine::toOstream(ostream& os) const{
  Resource::toOstream(os);
  Medicine* thisptr = const_cast<Medicine*>(this);
  os << "[" << "medicineType:" << thisptr->getMedicineType() << "]";  
}

ostream& operator<<(ostream& os, const Medicine& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (Medicine& Right, Medicine& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.medicineType.compare(Left.medicineType) != 0){
     return false;
  }  
}

Medicine& Medicine::operator=(Medicine& other){
  internalCopy(other);
  return *this;  
}

void Medicine::internalCopy(Medicine& other){
  this->medicineType.assign(other.medicineType);  
}

bool Medicine::setMedicineType(const string aNewMedicineType){
  bool wasSet= false;
  this->medicineType = aNewMedicineType;
  wasSet= true;
  return wasSet;  
}

string Medicine::getMedicineType(void){
  return this->medicineType;  
}

size_t Medicine::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
Medicine::~Medicine(){
  //Resource::~Resource();
  this->deleteAssociatedObjects();  
}

void Medicine::deleteAssociatedObjects(void){
  Resource::deleteAssociatedObjects();  
}
;

