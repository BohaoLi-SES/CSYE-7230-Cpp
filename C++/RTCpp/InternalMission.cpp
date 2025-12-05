//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__INTERNALMISSION_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <InternalMission.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <InternalMission.h>
#include <Mission.h>
#include <Facility.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
InternalMission::InternalMission(const string aDescription, const int aDifficulty, const int aDuration, Shelter* aShelter, const string aPriority, Facility* aTargetFacility):
		targetFacility(NULL),
    Mission(aDescription, aDifficulty, aDuration, aShelter){
  this->priority= aPriority;
  if (!setTargetFacility(aTargetFacility)){
    throw "Unable to create InternalMission due to aTargetFacility";
  }  
}

InternalMission::InternalMission(InternalMission& other):
		targetFacility(NULL),
    Mission(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void InternalMission::toOstream(ostream& os) const{
  Mission::toOstream(os);
  InternalMission* thisptr = const_cast<InternalMission*>(this);
  os << "[" << "priority:" << thisptr->getPriority() << "]" << endl;
  (thisptr->getTargetFacility()!= NULL ?  os << "targetFacility:" << thisptr->getTargetFacility() : os << "targetFacility:" << "NULL");  
}

ostream& operator<<(ostream& os, const InternalMission& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (InternalMission& Right, InternalMission& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.priority.compare(Left.priority) != 0){
     return false;
  }
  if(!compare(Right.targetFacility, Left.targetFacility, sizeof Right.targetFacility)){
    return false;
  }  
}

InternalMission& InternalMission::operator=(InternalMission& other){
  internalCopy(other);
  return *this;  
}

void InternalMission::internalCopy(InternalMission& other){
  this->priority.assign(other.priority);
  copyObject(other.targetFacility, this->targetFacility, sizeof other.targetFacility);  
}

bool InternalMission::setPriority(const string aNewPriority){
  bool wasSet= false;
  this->priority = aNewPriority;
  wasSet= true;
  return wasSet;  
}

bool InternalMission::setTargetFacility(Facility* aNewTargetFacility){
  bool wasSet= false;
  if (aNewTargetFacility == NULL){
    return wasSet;
  }
  
  Facility* existingTargetFacility = this->targetFacility;
  this->targetFacility = aNewTargetFacility;
  
  if (existingTargetFacility != NULL && existingTargetFacility != aNewTargetFacility){
      existingTargetFacility->removeInternalMission(this);
  }
  this->targetFacility->addInternalMission(this);
  wasSet = true;
  return wasSet;  
}

string InternalMission::getPriority(void){
  return this->priority;  
}

Facility* InternalMission::getTargetFacility(void){
  return this->targetFacility;  
}

size_t InternalMission::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
InternalMission::~InternalMission(){
  //Mission::~Mission();
  this->deleteAssociatedObjects();
  delete targetFacility;  
}

void InternalMission::deleteAssociatedObjects(void){
  Facility* placeholderTargetFacility = this->targetFacility;
  this->targetFacility = NULL;
  placeholderTargetFacility->removeInternalMission(this);  
}
;

