//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__LIVINGQUARTERS_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <LivingQuarters.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <LivingQuarters.h>
#include <Facility.h>
#include <Survivor.h>
#include <Shelter.h>
#include <MedicalBay.h>
#include <Mission.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>
#include <vector>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
LivingQuarters::LivingQuarters(const string aFacilityName, const int aCapacity, const int aLevel, const double aCondition, const int aPowerConsumption, Shelter* aShelter, const int aComfortLevel):Facility(aFacilityName, aCapacity, aLevel, aCondition, aPowerConsumption, aShelter){
  this->comfortLevel= aComfortLevel;
  this->residents= new vector<Survivor*>();
  if(!(comfortLevel >= 0 && comfortLevel <= 100)){  
    throw "Please provide a valid comfortLevel";
  }  
}

LivingQuarters::LivingQuarters(LivingQuarters& other):Facility(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void LivingQuarters::toOstream(ostream& os) const{
  Facility::toOstream(os);
  LivingQuarters* thisptr = const_cast<LivingQuarters*>(this);
  os << "[" << "comfortLevel:" << thisptr->getComfortLevel() << "]" << endl;
  (thisptr->getResidents()!= NULL ?  os << "residents:" << thisptr->getResidents() : os << "residents:" << "NULL");  
}

ostream& operator<<(ostream& os, const LivingQuarters& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (LivingQuarters& Right, LivingQuarters& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.comfortLevel!= Left.comfortLevel){
     return false;
  }
  if(!std::equal(Right.residents->begin(), Right.residents->end(), Left.residents->begin())){
     return false;
  }  
}

LivingQuarters& LivingQuarters::operator=(LivingQuarters& other){
  internalCopy(other);
  return *this;  
}

void LivingQuarters::internalCopy(LivingQuarters& other){
  this->comfortLevel= other.comfortLevel;
  this->residents = new vector<Survivor*>();
  vector<Survivor*>::iterator residentsBeginIterator(other.residents->begin());
  vector<Survivor*>::iterator residentsEndIterator(other.residents->end());
  copyVector(residentsBeginIterator, residentsEndIterator, this->residents);  
}

bool LivingQuarters::setComfortLevel(const int aNewComfortLevel){
  bool wasSet= false;
  if(comfortLevel >= 0){  
    this->comfortLevel = aNewComfortLevel;
    wasSet= true;
  }
  return wasSet;  
}

int LivingQuarters::getComfortLevel(void){
  return this->comfortLevel;  
}

vector<Survivor*>* LivingQuarters::getResidents(void){
  vector<Survivor*>* copyOfResidents = new vector<Survivor*>();
  vector<Survivor*>::iterator residentsBeginIterator(this->residents->begin());
  vector<Survivor*>::iterator residentsEndIterator(this->residents->end());
  copyVector(residentsBeginIterator, residentsEndIterator, copyOfResidents);
  return copyOfResidents;  
}

Survivor* LivingQuarters::getResident(int index){
  Survivor* aResident= (*(this->residents))[index];
  return aResident;  
}

unsigned int LivingQuarters::numberOfResidents(void){
  int number=this->residents->size();
  return number;  
}

bool LivingQuarters::hasResident(void){
  return this->numberOfResidents()>0;  
}

int LivingQuarters::indexOfResident(Survivor* aResident){
  return IndexOf(this->residents->begin(), this->residents->end(), aResident);  
}

bool LivingQuarters::removeResident(Survivor* aResident){
  bool wasRemoved= false;
  int index= IndexOf(this->residents->begin(), this->residents->end(), aResident);
  if(index<0){ 
    return wasRemoved;
  }
  //Unable to remove aResident, as it must always have a LivingQuarters
  if (this== aResident->getLivingQuarter()){
      return wasRemoved;
  }
  wasRemoved= this->removeResidentAt(index);
  return wasRemoved;  
}

bool LivingQuarters::removeResidentAt(int index){
  bool wasRemoved= false;
  if(index<0){
      return wasRemoved;
  }
  
  int size= this->numberOfResidents();
  if(index> size){
      return false;
  }
  this->residents->erase(this->residents->begin()+index);
  wasRemoved= size== this->numberOfResidents()+1;
  return wasRemoved;  
}

bool LivingQuarters::addResident(Survivor* aNewResident){
  bool wasAdded= false;
  if (IndexOf(this->residents->begin(), this->residents->end(), aNewResident)> -1) {
    return wasAdded;
  }
  if (this->numberOfResidents() >= this->maximumNumberOfResidents()){
    return wasAdded;
  }
  LivingQuarters* existingLivingQuarter = aNewResident->getLivingQuarter();
  bool isNewLivingQuarter= existingLivingQuarter != NULL && this!=existingLivingQuarter;
  if(isNewLivingQuarter){
    aNewResident->setLivingQuarter(this);
  }else{
    this->residents->push_back(aNewResident);
  }
  wasAdded= true;
  return wasAdded;  
}

bool LivingQuarters::addResidentAt(Survivor* aNewResident, int index){
  bool wasAdded= false;
  if(addResident(aNewResident)){
      int newIndex= index;
      if(index < 0 ) { 
          newIndex = 0; 
      }
    
      int size= this->numberOfResidents();
      if(size>0){
          this->residents->erase(this->residents->begin()+IndexOf(this->residents->begin(), this->residents->end(),aNewResident));    
      }
    
      size= this->numberOfResidents();
      if(newIndex > size) { 
          newIndex = size; 
      }
    
     this->residents->insert(this->residents->begin()+ newIndex, aNewResident);
      wasAdded = true;
  }
  return wasAdded;  
}

bool LivingQuarters::addOrMoveResidentAt(Survivor* aNewResident, int index){
  bool wasAdded= false;
  if(IndexOf(this->residents->begin(), this->residents->end(), aNewResident) > -1) {
    if (index < 0) {
      index = 0;
    }
  
    int size= this->numberOfResidents();
    if (index > size) {
      index = size - 1;
    }
    
    wasAdded= this->removeResident(aNewResident)| this->addResidentAt(aNewResident, index);
  }else{
    wasAdded= this->addResidentAt(aNewResident, index);
  }
  
  return wasAdded;  
}

Survivor* LivingQuarters::addResident(const string aName, Shelter* aShelter, Facility* aFacility, MedicalBay* aMedicalBay, Mission* aMission){
  if (this->numberOfResidents() >= this->maximumNumberOfResidents()){
    return NULL;
  }
  return new Survivor(aName, aShelter, aFacility, this, aMedicalBay, aMission);  
}

size_t LivingQuarters::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
LivingQuarters::~LivingQuarters(){
  //Facility::~Facility();
  this->deleteAssociatedObjects();
  
  std::for_each(residents->begin(), residents->end(), /*std::default_delete<Survivor>*/ deleteElement());
  residents->clear();
  delete residents;  
}

void LivingQuarters::deleteAssociatedObjects(void){
  for(unsigned int index = residents->size(); index > 0 ; index--){
    Survivor* aSurvivor= (*(this->residents))[index-1];
    aSurvivor->deleteAssociatedObjects();
  }  
}
;

