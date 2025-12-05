//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__MEDICALRESCUEMISSION_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <MedicalRescueMission.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <MedicalRescueMission.h>
#include <InternalMission.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
MedicalRescueMission::MedicalRescueMission(const string aDescription, const int aDifficulty, const int aDuration, Shelter* aShelter, const string aPriority, Facility* aTargetFacility, const int aCasualties):InternalMission(aDescription, aDifficulty, aDuration, aShelter, aPriority, aTargetFacility){
  this->casualties= aCasualties;
  if(!(casualties > 0)){  
    throw "Please provide valid casualties";
  }  
}

MedicalRescueMission::MedicalRescueMission(MedicalRescueMission& other):InternalMission(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void MedicalRescueMission::toOstream(ostream& os) const{
  InternalMission::toOstream(os);
  MedicalRescueMission* thisptr = const_cast<MedicalRescueMission*>(this);
  os << "[" << "casualties:" << thisptr->getCasualties() << "]";  
}

ostream& operator<<(ostream& os, const MedicalRescueMission& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (MedicalRescueMission& Right, MedicalRescueMission& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.casualties!= Left.casualties){
     return false;
  }  
}

MedicalRescueMission& MedicalRescueMission::operator=(MedicalRescueMission& other){
  internalCopy(other);
  return *this;  
}

void MedicalRescueMission::internalCopy(MedicalRescueMission& other){
  this->casualties= other.casualties;  
}

bool MedicalRescueMission::setCasualties(const int aNewCasualties){
  bool wasSet= false;
  if(casualties > 0){  
    this->casualties = aNewCasualties;
    wasSet= true;
  }
  return wasSet;  
}

int MedicalRescueMission::getCasualties(void){
  return this->casualties;  
}

size_t MedicalRescueMission::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
MedicalRescueMission::~MedicalRescueMission(){
  //InternalMission::~InternalMission();
  this->deleteAssociatedObjects();  
}

void MedicalRescueMission::deleteAssociatedObjects(void){
  InternalMission::deleteAssociatedObjects();  
}
;

