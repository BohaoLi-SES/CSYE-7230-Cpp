//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__PROTECTIONMISSION_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <ProtectionMission.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <ProtectionMission.h>
#include <InternalMission.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
ProtectionMission::ProtectionMission(const string aDescription, const int aDifficulty, const int aDuration, Shelter* aShelter, const string aPriority, Facility* aTargetFacility, const int aThreatLevel, const int aEnemyCount):InternalMission(aDescription, aDifficulty, aDuration, aShelter, aPriority, aTargetFacility){
  this->threatLevel= aThreatLevel;
  this->enemyCount= aEnemyCount;
  if(!(threatLevel >= 1 && threatLevel <= 10 && enemyCount > 0)){  
    throw "Please provide valid threatLevel and enemyCount";
  }  
}

ProtectionMission::ProtectionMission(ProtectionMission& other):InternalMission(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void ProtectionMission::toOstream(ostream& os) const{
  InternalMission::toOstream(os);
  ProtectionMission* thisptr = const_cast<ProtectionMission*>(this);
  os << "[" << "threatLevel:" << thisptr->getThreatLevel()<< ", " <<
      "enemyCount:" << thisptr->getEnemyCount() << "]";  
}

ostream& operator<<(ostream& os, const ProtectionMission& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (ProtectionMission& Right, ProtectionMission& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.threatLevel!= Left.threatLevel){
     return false;
  }
  if(Right.enemyCount!= Left.enemyCount){
     return false;
  }  
}

ProtectionMission& ProtectionMission::operator=(ProtectionMission& other){
  internalCopy(other);
  return *this;  
}

void ProtectionMission::internalCopy(ProtectionMission& other){
  this->threatLevel= other.threatLevel;
  this->enemyCount= other.enemyCount;  
}

bool ProtectionMission::setThreatLevel(const int aNewThreatLevel){
  bool wasSet= false;
  if(threatLevel >= 1){  
    this->threatLevel = aNewThreatLevel;
    wasSet= true;
  }
  return wasSet;  
}

bool ProtectionMission::setEnemyCount(const int aNewEnemyCount){
  bool wasSet= false;
  if(enemyCount > 0){  
    this->enemyCount = aNewEnemyCount;
    wasSet= true;
  }
  return wasSet;  
}

int ProtectionMission::getThreatLevel(void){
  return this->threatLevel;  
}

int ProtectionMission::getEnemyCount(void){
  return this->enemyCount;  
}

size_t ProtectionMission::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
ProtectionMission::~ProtectionMission(){
  //InternalMission::~InternalMission();
  this->deleteAssociatedObjects();  
}

void ProtectionMission::deleteAssociatedObjects(void){
  InternalMission::deleteAssociatedObjects();  
}
;

