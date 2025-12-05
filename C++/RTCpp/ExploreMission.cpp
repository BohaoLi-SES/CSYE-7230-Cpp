//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__EXPLOREMISSION_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <ExploreMission.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <ExploreMission.h>
#include <ExternalMission.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
ExploreMission::ExploreMission(const string aDescription, const int aDifficulty, const int aDuration, Shelter* aShelter, const string aDestination, const double aTravelDistance, const double aExplorationRadius):ExternalMission(aDescription, aDifficulty, aDuration, aShelter, aDestination, aTravelDistance){
  this->explorationRadius= aExplorationRadius;
  if(!(explorationRadius > 0)){  
    throw "Please provide a valid explorationRadius";
  }  
}

ExploreMission::ExploreMission(ExploreMission& other):ExternalMission(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void ExploreMission::toOstream(ostream& os) const{
  ExternalMission::toOstream(os);
  ExploreMission* thisptr = const_cast<ExploreMission*>(this);
  os << "[" << "explorationRadius:" << thisptr->getExplorationRadius() << "]";  
}

ostream& operator<<(ostream& os, const ExploreMission& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (ExploreMission& Right, ExploreMission& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.explorationRadius!= Left.explorationRadius){
     return false;
  }  
}

ExploreMission& ExploreMission::operator=(ExploreMission& other){
  internalCopy(other);
  return *this;  
}

void ExploreMission::internalCopy(ExploreMission& other){
  this->explorationRadius= other.explorationRadius;  
}

bool ExploreMission::setExplorationRadius(double aNewExplorationRadius){
  bool wasSet= false;
  if(explorationRadius > 0){  
    this->explorationRadius = aNewExplorationRadius;
    wasSet= true;
  }
  return wasSet;  
}

double ExploreMission::getExplorationRadius(void){
  return this->explorationRadius;  
}

size_t ExploreMission::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
ExploreMission::~ExploreMission(){
  //ExternalMission::~ExternalMission();
  this->deleteAssociatedObjects();  
}

void ExploreMission::deleteAssociatedObjects(void){
  ExternalMission::deleteAssociatedObjects();  
}
;

