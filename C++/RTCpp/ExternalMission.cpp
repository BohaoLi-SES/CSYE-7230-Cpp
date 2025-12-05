//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__EXTERNALMISSION_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <ExternalMission.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <ExternalMission.h>
#include <Mission.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
ExternalMission::ExternalMission(const string aDescription, const int aDifficulty, const int aDuration, Shelter* aShelter, const string aDestination, const double aTravelDistance):Mission(aDescription, aDifficulty, aDuration, aShelter){
  this->destination= aDestination;
  this->travelDistance= aTravelDistance;
  if(!(travelDistance > 0)){  
    throw "Please provide a valid travelDistance";
  }  
}

ExternalMission::ExternalMission(ExternalMission& other):Mission(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void ExternalMission::toOstream(ostream& os) const{
  Mission::toOstream(os);
  ExternalMission* thisptr = const_cast<ExternalMission*>(this);
  os << "[" << "destination:" << thisptr->getDestination()<< ", " <<
      "travelDistance:" << thisptr->getTravelDistance() << "]";  
}

ostream& operator<<(ostream& os, const ExternalMission& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (ExternalMission& Right, ExternalMission& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.destination.compare(Left.destination) != 0){
     return false;
  }
  if(Right.travelDistance!= Left.travelDistance){
     return false;
  }  
}

ExternalMission& ExternalMission::operator=(ExternalMission& other){
  internalCopy(other);
  return *this;  
}

void ExternalMission::internalCopy(ExternalMission& other){
  this->destination.assign(other.destination);
  this->travelDistance= other.travelDistance;  
}

bool ExternalMission::setDestination(const string aNewDestination){
  bool wasSet= false;
  this->destination = aNewDestination;
  wasSet= true;
  return wasSet;  
}

bool ExternalMission::setTravelDistance(double aNewTravelDistance){
  bool wasSet= false;
  if(travelDistance > 0){  
    this->travelDistance = aNewTravelDistance;
    wasSet= true;
  }
  return wasSet;  
}

string ExternalMission::getDestination(void){
  return this->destination;  
}

double ExternalMission::getTravelDistance(void){
  return this->travelDistance;  
}

size_t ExternalMission::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
ExternalMission::~ExternalMission(){
  //Mission::~Mission();
  this->deleteAssociatedObjects();  
}

void ExternalMission::deleteAssociatedObjects(void){
  Mission::deleteAssociatedObjects();  
}
;

