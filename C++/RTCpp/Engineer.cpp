//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__ENGINEER_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <Engineer.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Engineer.h>
#include <Survivor.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
Engineer::Engineer(const string aName, Shelter* aShelter, Facility* aFacility, LivingQuarters* aLivingQuarters, MedicalBay* aMedicalBay, Mission* aMission, const int aRepairSkill):Survivor(aName, aShelter, aFacility, aLivingQuarters, aMedicalBay, aMission){
  this->repairSkill= aRepairSkill;
  if(!(repairSkill >= 1 && repairSkill <= 100)){  
    throw "Please provide a valid repairSkill";
  }  
}

Engineer::Engineer(Engineer& other):Survivor(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void Engineer::toOstream(ostream& os) const{
  Survivor::toOstream(os);
  Engineer* thisptr = const_cast<Engineer*>(this);
  os << "[" << "repairSkill:" << thisptr->getRepairSkill() << "]";  
}

ostream& operator<<(ostream& os, const Engineer& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (Engineer& Right, Engineer& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.repairSkill!= Left.repairSkill){
     return false;
  }  
}

Engineer& Engineer::operator=(Engineer& other){
  internalCopy(other);
  return *this;  
}

void Engineer::internalCopy(Engineer& other){
  this->repairSkill= other.repairSkill;  
}

bool Engineer::setRepairSkill(const int aNewRepairSkill){
  bool wasSet= false;
  if(repairSkill >= 1){  
    this->repairSkill = aNewRepairSkill;
    wasSet= true;
  }
  return wasSet;  
}

int Engineer::getRepairSkill(void){
  return this->repairSkill;  
}

size_t Engineer::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
Engineer::~Engineer(){
  //Survivor::~Survivor();
  this->deleteAssociatedObjects();  
}

void Engineer::deleteAssociatedObjects(void){
  Survivor::deleteAssociatedObjects();  
}
;

