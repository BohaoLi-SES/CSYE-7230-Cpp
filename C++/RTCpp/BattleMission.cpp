//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__BATTLEMISSION_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <BattleMission.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <BattleMission.h>
#include <ExternalMission.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
BattleMission::BattleMission(const string aDescription, const int aDifficulty, const int aDuration, Shelter* aShelter, const string aDestination, const double aTravelDistance, const int aEnemyForce):ExternalMission(aDescription, aDifficulty, aDuration, aShelter, aDestination, aTravelDistance){
  this->enemyForce= aEnemyForce;
  if(!(enemyForce > 0)){  
    throw "Please provide a valid enemyForce";
  }  
}

BattleMission::BattleMission(BattleMission& other):ExternalMission(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void BattleMission::toOstream(ostream& os) const{
  ExternalMission::toOstream(os);
  BattleMission* thisptr = const_cast<BattleMission*>(this);
  os << "[" << "enemyForce:" << thisptr->getEnemyForce() << "]";  
}

ostream& operator<<(ostream& os, const BattleMission& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (BattleMission& Right, BattleMission& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.enemyForce!= Left.enemyForce){
     return false;
  }  
}

BattleMission& BattleMission::operator=(BattleMission& other){
  internalCopy(other);
  return *this;  
}

void BattleMission::internalCopy(BattleMission& other){
  this->enemyForce= other.enemyForce;  
}

bool BattleMission::setEnemyForce(const int aNewEnemyForce){
  bool wasSet= false;
  if(enemyForce > 0){  
    this->enemyForce = aNewEnemyForce;
    wasSet= true;
  }
  return wasSet;  
}

int BattleMission::getEnemyForce(void){
  return this->enemyForce;  
}

size_t BattleMission::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
BattleMission::~BattleMission(){
  //ExternalMission::~ExternalMission();
  this->deleteAssociatedObjects();  
}

void BattleMission::deleteAssociatedObjects(void){
  ExternalMission::deleteAssociatedObjects();  
}
;

