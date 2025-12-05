//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__SUPPLYBAY_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <SupplyBay.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <SupplyBay.h>
#include <Facility.h>
#include <Resource.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>
#include <vector>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
SupplyBay::SupplyBay(const string aFacilityName, const int aCapacity, const int aLevel, const double aCondition, const int aPowerConsumption, Shelter* aShelter):Facility(aFacilityName, aCapacity, aLevel, aCondition, aPowerConsumption, aShelter){
  this->heldResources= new vector<Resource*>();  
}

SupplyBay::SupplyBay(SupplyBay& other):Facility(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void SupplyBay::toOstream(ostream& os) const{
  Facility::toOstream(os);
  SupplyBay* thisptr = const_cast<SupplyBay*>(this);
  (thisptr->getHeldResources()!= NULL ?  os << "heldResources:" << thisptr->getHeldResources() : os << "heldResources:" << "NULL");  
}

ostream& operator<<(ostream& os, const SupplyBay& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (SupplyBay& Right, SupplyBay& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(!std::equal(Right.heldResources->begin(), Right.heldResources->end(), Left.heldResources->begin())){
     return false;
  }  
}

SupplyBay& SupplyBay::operator=(SupplyBay& other){
  internalCopy(other);
  return *this;  
}

void SupplyBay::internalCopy(SupplyBay& other){
  this->heldResources = new vector<Resource*>();
  vector<Resource*>::iterator heldResourcesBeginIterator(other.heldResources->begin());
  vector<Resource*>::iterator heldResourcesEndIterator(other.heldResources->end());
  copyVector(heldResourcesBeginIterator, heldResourcesEndIterator, this->heldResources);  
}

vector<Resource*>* SupplyBay::getHeldResources(void){
  vector<Resource*>* copyOfHeldResources = new vector<Resource*>();
  vector<Resource*>::iterator heldResourcesBeginIterator(this->heldResources->begin());
  vector<Resource*>::iterator heldResourcesEndIterator(this->heldResources->end());
  copyVector(heldResourcesBeginIterator, heldResourcesEndIterator, copyOfHeldResources);
  return copyOfHeldResources;  
}

Resource* SupplyBay::getHeldResource(int index){
  Resource* aHeldResource= (*(this->heldResources))[index];
  return aHeldResource;  
}

unsigned int SupplyBay::numberOfHeldResources(void){
  int number=this->heldResources->size();
  return number;  
}

bool SupplyBay::hasHeldResource(void){
  return this->numberOfHeldResources()>0;  
}

int SupplyBay::indexOfHeldResource(Resource* aHeldResource){
  return IndexOf(this->heldResources->begin(), this->heldResources->end(), aHeldResource);  
}

bool SupplyBay::removeHeldResource(Resource* aHeldResource){
  bool wasRemoved= false;
  int index= IndexOf(this->heldResources->begin(), this->heldResources->end(), aHeldResource);
  if(index<0){ 
    return wasRemoved;
  }
  //Unable to remove aHeldResource, as it must always have a SupplyBay
  if (this== aHeldResource->getSupplyBay()){
      return wasRemoved;
  }
  wasRemoved= this->removeHeldResourceAt(index);
  return wasRemoved;  
}

bool SupplyBay::removeHeldResourceAt(int index){
  bool wasRemoved= false;
  if(index<0){
      return wasRemoved;
  }
  
  int size= this->numberOfHeldResources();
  if(index> size){
      return false;
  }
  this->heldResources->erase(this->heldResources->begin()+index);
  wasRemoved= size== this->numberOfHeldResources()+1;
  return wasRemoved;  
}

bool SupplyBay::addHeldResource(Resource* aNewHeldResource){
  bool wasAdded= false;
  if (IndexOf(this->heldResources->begin(), this->heldResources->end(), aNewHeldResource)> -1) {
    return wasAdded;
  }
  SupplyBay* existingSupplyBay = aNewHeldResource->getSupplyBay();
  bool isNewSupplyBay= existingSupplyBay != NULL && this!=existingSupplyBay;
  if(isNewSupplyBay){
    aNewHeldResource->setSupplyBay(this);
  }else{
    this->heldResources->push_back(aNewHeldResource);
  }
  wasAdded= true;
  return wasAdded;  
}

bool SupplyBay::addHeldResourceAt(Resource* aNewHeldResource, int index){
  bool wasAdded= false;
  if(addHeldResource(aNewHeldResource)){
      int newIndex= index;
      if(index < 0 ) { 
          newIndex = 0; 
      }
    
      int size= this->numberOfHeldResources();
      if(size>0){
          this->heldResources->erase(this->heldResources->begin()+IndexOf(this->heldResources->begin(), this->heldResources->end(),aNewHeldResource));    
      }
    
      size= this->numberOfHeldResources();
      if(newIndex > size) { 
          newIndex = size; 
      }
    
     this->heldResources->insert(this->heldResources->begin()+ newIndex, aNewHeldResource);
      wasAdded = true;
  }
  return wasAdded;  
}

bool SupplyBay::addOrMoveHeldResourceAt(Resource* aNewHeldResource, int index){
  bool wasAdded= false;
  if(IndexOf(this->heldResources->begin(), this->heldResources->end(), aNewHeldResource) > -1) {
    if (index < 0) {
      index = 0;
    }
  
    int size= this->numberOfHeldResources();
    if (index > size) {
      index = size - 1;
    }
    
    wasAdded= this->removeHeldResource(aNewHeldResource)| this->addHeldResourceAt(aNewHeldResource, index);
  }else{
    wasAdded= this->addHeldResourceAt(aNewHeldResource, index);
  }
  
  return wasAdded;  
}

Resource* SupplyBay::addHeldResource(const string aResourceId, const int aQuantity, const int aMaxCapacity, const string aUnit){
  return new Resource(aResourceId, aQuantity, aMaxCapacity, aUnit, this);  
}

size_t SupplyBay::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
SupplyBay::~SupplyBay(){
  //Facility::~Facility();
  this->deleteAssociatedObjects();
  
  std::for_each(heldResources->begin(), heldResources->end(), /*std::default_delete<Resource>*/ deleteElement());
  heldResources->clear();
  delete heldResources;  
}

void SupplyBay::deleteAssociatedObjects(void){
  for(unsigned int index = heldResources->size(); index > 0 ; index--){
    Resource* aResource= (*(this->heldResources))[index-1];
    aResource->deleteAssociatedObjects();
  }  
}
;

