//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__MAINTENANCEMISSION_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <MaintenanceMission.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <MaintenanceMission.h>
#include <InternalMission.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
MaintenanceMission::MaintenanceMission(const string aDescription, const int aDifficulty, const int aDuration, Shelter* aShelter, const string aPriority, Facility* aTargetFacility, const int aRepairComplexity):InternalMission(aDescription, aDifficulty, aDuration, aShelter, aPriority, aTargetFacility){
  this->repairComplexity= aRepairComplexity;
  if(!(repairComplexity >= 1 && repairComplexity <= 10)){  
    throw "Please provide a valid repairComplexity";
  }  
}

MaintenanceMission::MaintenanceMission(MaintenanceMission& other):InternalMission(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void MaintenanceMission::toOstream(ostream& os) const{
  InternalMission::toOstream(os);
  MaintenanceMission* thisptr = const_cast<MaintenanceMission*>(this);
  os << "[" << "repairComplexity:" << thisptr->getRepairComplexity() << "]";  
}

ostream& operator<<(ostream& os, const MaintenanceMission& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (MaintenanceMission& Right, MaintenanceMission& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.repairComplexity!= Left.repairComplexity){
     return false;
  }  
}

MaintenanceMission& MaintenanceMission::operator=(MaintenanceMission& other){
  internalCopy(other);
  return *this;  
}

void MaintenanceMission::internalCopy(MaintenanceMission& other){
  this->repairComplexity= other.repairComplexity;  
}

bool MaintenanceMission::setRepairComplexity(const int aNewRepairComplexity){
  bool wasSet= false;
  if(repairComplexity >= 1){  
    this->repairComplexity = aNewRepairComplexity;
    wasSet= true;
  }
  return wasSet;  
}

int MaintenanceMission::getRepairComplexity(void){
  return this->repairComplexity;  
}

size_t MaintenanceMission::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
MaintenanceMission::~MaintenanceMission(){
  //InternalMission::~InternalMission();
  this->deleteAssociatedObjects();  
}

void MaintenanceMission::deleteAssociatedObjects(void){
  InternalMission::deleteAssociatedObjects();  
}
;

