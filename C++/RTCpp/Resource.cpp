//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__RESOURCE_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <Resource.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Resource.h>
#include <SupplyBay.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>
#include <cassert>
#include <string>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
Resource::Resource(const string aResourceId, const int aQuantity, const int aMaxCapacity, const string aUnit, SupplyBay* aSupplyBay):
		supplyBay(NULL){
  this->resourceId= aResourceId;
  this->quantity= aQuantity;
  this->maxCapacity= aMaxCapacity;
  this->unit= aUnit;
  if (!setSupplyBay(aSupplyBay)){
    throw "Unable to create Resource due to aSupplyBay";
  }
  if(!(quantity >= 0 && quantity <= maxCapacity && maxCapacity > 0)){  
    throw "Please provide valid quantity and maxCapacity";
  }
  setResourceState(ResourceState::RS_Sufficient);  
}

Resource::Resource(Resource& other):
		supplyBay(NULL){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void Resource::toOstream(ostream& os) const{
  Resource* thisptr = const_cast<Resource*>(this);
  os << "[" << "resourceId:" << thisptr->getResourceId()<< ", " <<
      "quantity:" << thisptr->getQuantity()<< ", " <<
      "maxCapacity:" << thisptr->getMaxCapacity()<< ", " <<
      "unit:" << thisptr->getUnit() << "]" << endl;
  (thisptr->getSupplyBay()!= NULL ?  os << "supplyBay:" << thisptr->getSupplyBay() : os << "supplyBay:" << "NULL");  
}

ostream& operator<<(ostream& os, const Resource& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (Resource& Right, Resource& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.resourceId.compare(Left.resourceId) != 0){
     return false;
  }
  if(Right.quantity!= Left.quantity){
     return false;
  }
  if(Right.maxCapacity!= Left.maxCapacity){
     return false;
  }
  if(Right.unit.compare(Left.unit) != 0){
     return false;
  }
  if(!compare(Right.supplyBay, Left.supplyBay, sizeof Right.supplyBay)){
    return false;
  }  
}

Resource& Resource::operator=(Resource& other){
  internalCopy(other);
  return *this;  
}

void Resource::internalCopy(Resource& other){
  this->resourceId.assign(other.resourceId);
  this->quantity= other.quantity;
  this->maxCapacity= other.maxCapacity;
  this->unit.assign(other.unit);
  copyObject(other.supplyBay, this->supplyBay, sizeof other.supplyBay);  
}

bool Resource::setResourceId(const string aNewResourceId){
  bool wasSet= false;
  this->resourceId = aNewResourceId;
  wasSet= true;
  return wasSet;  
}

bool Resource::setQuantity(const int aNewQuantity){
  bool wasSet= false;
  if(quantity >= 0 && quantity <= maxCapacity){  
    this->quantity = aNewQuantity;
    wasSet= true;
  }
  return wasSet;  
}

bool Resource::setMaxCapacity(const int aNewMaxCapacity){
  bool wasSet= false;
  if(quantity <= maxCapacity && maxCapacity > 0){  
    this->maxCapacity = aNewMaxCapacity;
    wasSet= true;
  }
  return wasSet;  
}

bool Resource::setUnit(const string aNewUnit){
  bool wasSet= false;
  this->unit = aNewUnit;
  wasSet= true;
  return wasSet;  
}

bool Resource::setSupplyBay(SupplyBay* aNewSupplyBay){
  bool wasSet= false;
  if (aNewSupplyBay == NULL){
    return wasSet;
  }
  
  SupplyBay* existingSupplyBay = this->supplyBay;
  this->supplyBay = aNewSupplyBay;
  
  if (existingSupplyBay != NULL && existingSupplyBay != aNewSupplyBay){
      existingSupplyBay->removeHeldResource(this);
  }
  this->supplyBay->addHeldResource(this);
  wasSet = true;
  return wasSet;  
}

string Resource::getResourceId(void){
  return this->resourceId;  
}

int Resource::getQuantity(void){
  return this->quantity;  
}

int Resource::getMaxCapacity(void){
  return this->maxCapacity;  
}

string Resource::getUnit(void){
  return this->unit;  
}

SupplyBay* Resource::getSupplyBay(void){
  return this->supplyBay;  
}

bool Resource::quantityBelow30(){
  bool wasEventProcessed= false;
  ResourceState aResourceState= resourceState;
    
  switch((int)aResourceState){	
  	case ResourceState::RS_Sufficient:
  		setResourceState(ResourceState::RS_Low);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Resource::quantityFull(){
  bool wasEventProcessed= false;
  ResourceState aResourceState= resourceState;
    
  switch((int)aResourceState){	
  	case ResourceState::RS_Sufficient:
  		setResourceState(ResourceState::RS_Full);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Resource::consume(){
  bool wasEventProcessed= false;
  ResourceState aResourceState= resourceState;
    
  switch((int)aResourceState){	
  	case ResourceState::RS_Full:
  		setResourceState(ResourceState::RS_Sufficient);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Resource::addAbove30(){
  bool wasEventProcessed= false;
  ResourceState aResourceState= resourceState;
    
  switch((int)aResourceState){	
  	case ResourceState::RS_Low:
  		setResourceState(ResourceState::RS_Sufficient);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Resource::quantityBelow10(){
  bool wasEventProcessed= false;
  ResourceState aResourceState= resourceState;
    
  switch((int)aResourceState){	
  	case ResourceState::RS_Low:
  		setResourceState(ResourceState::RS_Critical);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Resource::addAbove10(){
  bool wasEventProcessed= false;
  ResourceState aResourceState= resourceState;
    
  switch((int)aResourceState){	
  	case ResourceState::RS_Critical:
  		setResourceState(ResourceState::RS_Low);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Resource::quantityZero(){
  bool wasEventProcessed= false;
  ResourceState aResourceState= resourceState;
    
  switch((int)aResourceState){	
  	case ResourceState::RS_Critical:
  		setResourceState(ResourceState::RS_Depleted);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Resource::addSmall(){
  bool wasEventProcessed= false;
  ResourceState aResourceState= resourceState;
    
  switch((int)aResourceState){	
  	case ResourceState::RS_Depleted:
  		setResourceState(ResourceState::RS_Critical);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Resource::addLarge(){
  bool wasEventProcessed= false;
  ResourceState aResourceState= resourceState;
    
  switch((int)aResourceState){	
  	case ResourceState::RS_Depleted:
  		setResourceState(ResourceState::RS_Low);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

string Resource::getResourceStateFullName(void){
  string answer = resourceState;
  return answer;
    
}

ResourceState Resource::getResourceState(void){
  return this->resourceState;  
}

void Resource::setResourceState(ResourceState aResourceState){
  resourceState= aResourceState;
    
}

bool Resource::exitResourceState(void){
  bool wasEventProcessed = false;
  
    
  switch((int)resourceState){	
  	case ResourceState::RS_Sufficient:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case ResourceState::RS_Full:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case ResourceState::RS_Low:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case ResourceState::RS_Critical:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case ResourceState::RS_Depleted:
  		wasEventProcessed= true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;
    
}

size_t Resource::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
Resource::~Resource(){
  this->deleteAssociatedObjects();
  delete supplyBay;  
}

void Resource::deleteAssociatedObjects(void){
  SupplyBay* placeholderSupplyBay = this->supplyBay;
  this->supplyBay = NULL;
  placeholderSupplyBay->removeHeldResource(this);  
}
;

