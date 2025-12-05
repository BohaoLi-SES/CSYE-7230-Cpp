//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__RADIATIONMONITOR_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <RadiationMonitor.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <RadiationMonitor.h>
#include <Shelter.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
RadiationMonitor::RadiationMonitor(const int aExternalLevel, const int aInternalLevel, const double aThreshold, const bool aIsAlertActive, Shelter* aShelter):
		shelter(NULL){
  this->externalLevel= aExternalLevel;
  this->internalLevel= aInternalLevel;
  this->threshold= aThreshold;
  this->isAlertActive= aIsAlertActive;
  if (aShelter == NULL || aShelter->getRadiationMonitor() != NULL){
    throw "Unable to create RadiationMonitor due to aShelter";
  }
  this->shelter = aShelter;
  if(!(externalLevel >= 0 && internalLevel >= 0 && threshold > 0)){  
    throw "Please provide valid externalLevel, internalLevel, and threshold";
  }  
}

RadiationMonitor::RadiationMonitor(RadiationMonitor& other):
		shelter(NULL){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void RadiationMonitor::toOstream(ostream& os) const{
  RadiationMonitor* thisptr = const_cast<RadiationMonitor*>(this);
  os << "[" << "externalLevel:" << thisptr->getExternalLevel()<< ", " <<
      "internalLevel:" << thisptr->getInternalLevel()<< ", " <<
      "threshold:" << thisptr->getThreshold()<< ", " <<
      "isAlertActive:" << thisptr->getIsAlertActive()<< ", " <<
      "status:" << thisptr->getStatus() << "]" << endl;
  (thisptr->getShelter()!= NULL ?  os << "shelter:" << thisptr->getShelter() : os << "shelter:" << "NULL");  
}

ostream& operator<<(ostream& os, const RadiationMonitor& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (RadiationMonitor& Right, RadiationMonitor& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.externalLevel!= Left.externalLevel){
     return false;
  }
  if(Right.internalLevel!= Left.internalLevel){
     return false;
  }
  if(Right.threshold!= Left.threshold){
     return false;
  }
  if(Right.isAlertActive!= Left.isAlertActive){
     return false;
  }
  if(Right.status.compare(Left.status) != 0){
     return false;
  }
  if(!compare(Right.shelter, Left.shelter, sizeof Right.shelter)){
    return false;
  }  
}

RadiationMonitor& RadiationMonitor::operator=(RadiationMonitor& other){
  internalCopy(other);
  return *this;  
}

void RadiationMonitor::internalCopy(RadiationMonitor& other){
  this->externalLevel= other.externalLevel;
  this->internalLevel= other.internalLevel;
  this->threshold= other.threshold;
  this->isAlertActive= other.isAlertActive;
  this->status.assign(other.status);
  copyObject(other.shelter, this->shelter, sizeof other.shelter);  
}

bool RadiationMonitor::setExternalLevel(const int aNewExternalLevel){
  bool wasSet= false;
  if(externalLevel >= 0){  
    this->externalLevel = aNewExternalLevel;
    wasSet= true;
  }
  return wasSet;  
}

bool RadiationMonitor::setInternalLevel(const int aNewInternalLevel){
  bool wasSet= false;
  if(internalLevel >= 0){  
    this->internalLevel = aNewInternalLevel;
    wasSet= true;
  }
  return wasSet;  
}

bool RadiationMonitor::setThreshold(double aNewThreshold){
  bool wasSet= false;
  if(threshold > 0){  
    this->threshold = aNewThreshold;
    wasSet= true;
  }
  return wasSet;  
}

bool RadiationMonitor::setIsAlertActive(bool aNewIsAlertActive){
  bool wasSet= false;
  this->isAlertActive = aNewIsAlertActive;
  wasSet= true;
  return wasSet;  
}

bool RadiationMonitor::setStatus(const string aNewStatus){
  bool wasSet= false;
  this->status = aNewStatus;
  wasSet= true;
  return wasSet;  
}

int RadiationMonitor::getExternalLevel(void){
  return this->externalLevel;  
}

int RadiationMonitor::getInternalLevel(void){
  return this->internalLevel;  
}

double RadiationMonitor::getThreshold(void){
  return this->threshold;  
}

bool RadiationMonitor::getIsAlertActive(void){
  return this->isAlertActive;  
}

bool RadiationMonitor::isIsAlertActive(void){
  return this->isAlertActive;  
}

string RadiationMonitor::getStatus(void){
  return this->status;  
}

Shelter* RadiationMonitor::getShelter(void){
  return this->shelter;  
}

size_t RadiationMonitor::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
RadiationMonitor::~RadiationMonitor(){
  this->deleteAssociatedObjects();
  delete shelter;  
}

void RadiationMonitor::deleteAssociatedObjects(void){
  if(this->shelter!= NULL){
    Shelter* existingShelter= this->shelter;
    this->shelter= NULL;
    existingShelter->deleteAssociatedObjects();
  }  
}
;

