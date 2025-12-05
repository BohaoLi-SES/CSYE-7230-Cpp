//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__FACILITY_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <Facility.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Facility.h>
#include <Survivor.h>
#include <Shelter.h>
#include <LivingQuarters.h>
#include <MedicalBay.h>
#include <Mission.h>
#include <InternalMission.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>
#include <vector>
#include <cassert>
#include <string>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
Facility::Facility(const string aFacilityName, const int aCapacity, const int aLevel, const double aCondition, const int aPowerConsumption, Shelter* aShelter):
		shelter(NULL){
  this->facilityName= aFacilityName;
  this->capacity= aCapacity;
  this->level= aLevel;
  this->condition= aCondition;
  this->powerConsumption= aPowerConsumption;
  this->workers= new vector<Survivor*>();
  if (!setShelter(aShelter)){
    throw "Unable to create Facility due to aShelter";
  }
  this->survivors= new vector<Survivor*>();
  this->internalMissions= new vector<InternalMission*>();
  if(!(capacity > 0 && level >= 1 && condition >= 0 && condition <= 100 && powerConsumption >= 0)){  
    throw "Please provide valid capacity, level, condition, and powerConsumption";
  }
  setFacilityState(FacilityState::FC_Inactive);
  setFC_Active(FacilityStateFC_Active::NIL);
  setActiveState(FacilityStateFC_ActiveActiveState::NIL);  
}

Facility::Facility(Facility& other):
		shelter(NULL){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void Facility::toOstream(ostream& os) const{
  Facility* thisptr = const_cast<Facility*>(this);
  os << "[" << "facilityName:" << thisptr->getFacilityName()<< ", " <<
      "capacity:" << thisptr->getCapacity()<< ", " <<
      "level:" << thisptr->getLevel()<< ", " <<
      "condition:" << thisptr->getCondition()<< ", " <<
      "powerConsumption:" << thisptr->getPowerConsumption() << "]" << endl;
  (thisptr->getWorkers()!= NULL ?  os << "workers:" << thisptr->getWorkers() : os << "workers:" << "NULL")<< endl;
      (thisptr->getShelter()!= NULL ?  os << "shelter:" << thisptr->getShelter() : os << "shelter:" << "NULL")<< endl;
      (thisptr->getSurvivors()!= NULL ?  os << "survivors:" << thisptr->getSurvivors() : os << "survivors:" << "NULL")<< endl;
      (thisptr->getInternalMissions()!= NULL ?  os << "internalMissions:" << thisptr->getInternalMissions() : os << "internalMissions:" << "NULL");  
}

ostream& operator<<(ostream& os, const Facility& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (Facility& Right, Facility& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.facilityName.compare(Left.facilityName) != 0){
     return false;
  }
  if(Right.capacity!= Left.capacity){
     return false;
  }
  if(Right.level!= Left.level){
     return false;
  }
  if(Right.condition!= Left.condition){
     return false;
  }
  if(Right.powerConsumption!= Left.powerConsumption){
     return false;
  }
  if(!std::equal(Right.workers->begin(), Right.workers->end(), Left.workers->begin())){
     return false;
  }
  if(!compare(Right.shelter, Left.shelter, sizeof Right.shelter)){
    return false;
  }
  if(!std::equal(Right.survivors->begin(), Right.survivors->end(), Left.survivors->begin())){
     return false;
  }
  if(!std::equal(Right.internalMissions->begin(), Right.internalMissions->end(), Left.internalMissions->begin())){
     return false;
  }  
}

Facility& Facility::operator=(Facility& other){
  internalCopy(other);
  return *this;  
}

void Facility::internalCopy(Facility& other){
  this->facilityName.assign(other.facilityName);
  this->capacity= other.capacity;
  this->level= other.level;
  this->condition= other.condition;
  this->powerConsumption= other.powerConsumption;
  this->workers = new vector<Survivor*>();
  vector<Survivor*>::iterator workersBeginIterator(other.workers->begin());
  vector<Survivor*>::iterator workersEndIterator(other.workers->end());
  copyVector(workersBeginIterator, workersEndIterator, this->workers);
  copyObject(other.shelter, this->shelter, sizeof other.shelter);
  this->survivors = new vector<Survivor*>();
  vector<Survivor*>::iterator survivorsBeginIterator(other.survivors->begin());
  vector<Survivor*>::iterator survivorsEndIterator(other.survivors->end());
  copyVector(survivorsBeginIterator, survivorsEndIterator, this->survivors);
  this->internalMissions = new vector<InternalMission*>();
  vector<InternalMission*>::iterator internalMissionsBeginIterator(other.internalMissions->begin());
  vector<InternalMission*>::iterator internalMissionsEndIterator(other.internalMissions->end());
  copyVector(internalMissionsBeginIterator, internalMissionsEndIterator, this->internalMissions);  
}

bool Facility::setFacilityName(const string aNewFacilityName){
  bool wasSet= false;
  this->facilityName = aNewFacilityName;
  wasSet= true;
  return wasSet;  
}

bool Facility::setCapacity(const int aNewCapacity){
  bool wasSet= false;
  if(capacity > 0){  
    this->capacity = aNewCapacity;
    wasSet= true;
  }
  return wasSet;  
}

bool Facility::setLevel(const int aNewLevel){
  bool wasSet= false;
  if(level >= 1){  
    this->level = aNewLevel;
    wasSet= true;
  }
  return wasSet;  
}

bool Facility::setCondition(double aNewCondition){
  bool wasSet= false;
  if(condition >= 0){  
    this->condition = aNewCondition;
    wasSet= true;
  }
  return wasSet;  
}

bool Facility::setPowerConsumption(const int aNewPowerConsumption){
  bool wasSet= false;
  if(powerConsumption >= 0){  
    this->powerConsumption = aNewPowerConsumption;
    wasSet= true;
  }
  return wasSet;  
}

bool Facility::setShelter(Shelter* aNewShelter){
  bool wasSet= false;
  if(aNewShelter == NULL){
    //Must provide shelter to Facility
    return wasSet;
  }
  
  if(aNewShelter->numberOfFacilities() >= aNewShelter->maximumNumberOfFacilities()){
    return wasSet;
  }
  
  Shelter* existingShelter = this->shelter;
  this->shelter = aNewShelter;
  if (existingShelter != NULL && existingShelter!= aNewShelter){
    bool didRemove = existingShelter->removeFacility(this);
    if(!didRemove){
      this->shelter = existingShelter;
      return wasSet;
    }
  }
  this->shelter->addFacility(this);
  wasSet = true;
  
  return wasSet;  
}

string Facility::getFacilityName(void){
  return this->facilityName;  
}

int Facility::getCapacity(void){
  return this->capacity;  
}

int Facility::getLevel(void){
  return this->level;  
}

double Facility::getCondition(void){
  return this->condition;  
}

int Facility::getPowerConsumption(void){
  return this->powerConsumption;  
}

vector<Survivor*>* Facility::getWorkers(void){
  vector<Survivor*>* copyOfWorkers = new vector<Survivor*>();
  vector<Survivor*>::iterator workersBeginIterator(this->workers->begin());
  vector<Survivor*>::iterator workersEndIterator(this->workers->end());
  copyVector(workersBeginIterator, workersEndIterator, copyOfWorkers);
  return copyOfWorkers;  
}

Survivor* Facility::getWorker(int index){
  Survivor* aWorker= (*(this->workers))[index];
  return aWorker;  
}

unsigned int Facility::numberOfWorkers(void){
  int number=this->workers->size();
  return number;  
}

bool Facility::hasWorker(void){
  return this->numberOfWorkers()>0;  
}

int Facility::indexOfWorker(Survivor* aWorker){
  return IndexOf(this->workers->begin(), this->workers->end(), aWorker);  
}

bool Facility::removeWorker(Survivor* aWorker){
  bool wasRemoved= false;
  int index= IndexOf(this->workers->begin(), this->workers->end(), aWorker);
  if(index<0){ 
    return wasRemoved;
  }
  //Unable to remove aWorker, as it must always have a Facility
  if (this== aWorker->getFacility()){
      return wasRemoved;
  }
  wasRemoved= this->removeWorkerAt(index);
  return wasRemoved;  
}

bool Facility::removeWorkerAt(int index){
  bool wasRemoved= false;
  if(index<0){
      return wasRemoved;
  }
  
  int size= this->numberOfWorkers();
  if(index> size){
      return false;
  }
  this->workers->erase(this->workers->begin()+index);
  wasRemoved= size== this->numberOfWorkers()+1;
  return wasRemoved;  
}

bool Facility::addWorker(Survivor* aNewWorker){
  bool wasAdded= false;
  if (IndexOf(this->workers->begin(), this->workers->end(), aNewWorker)> -1) {
    return wasAdded;
  }
  if (this->numberOfWorkers() >= this->maximumNumberOfWorkers()){
    return wasAdded;
  }
  Facility* existingFacility = aNewWorker->getFacility();
  bool isNewFacility= existingFacility != NULL && this!=existingFacility;
  if(isNewFacility){
    aNewWorker->setFacility(this);
  }else{
    this->workers->push_back(aNewWorker);
  }
  wasAdded= true;
  return wasAdded;  
}

bool Facility::addWorkerAt(Survivor* aNewWorker, int index){
  bool wasAdded= false;
  if(addWorker(aNewWorker)){
      int newIndex= index;
      if(index < 0 ) { 
          newIndex = 0; 
      }
    
      int size= this->numberOfWorkers();
      if(size>0){
          this->workers->erase(this->workers->begin()+IndexOf(this->workers->begin(), this->workers->end(),aNewWorker));    
      }
    
      size= this->numberOfWorkers();
      if(newIndex > size) { 
          newIndex = size; 
      }
    
     this->workers->insert(this->workers->begin()+ newIndex, aNewWorker);
      wasAdded = true;
  }
  return wasAdded;  
}

bool Facility::addOrMoveWorkerAt(Survivor* aNewWorker, int index){
  bool wasAdded= false;
  if(IndexOf(this->workers->begin(), this->workers->end(), aNewWorker) > -1) {
    if (index < 0) {
      index = 0;
    }
  
    int size= this->numberOfWorkers();
    if (index > size) {
      index = size - 1;
    }
    
    wasAdded= this->removeWorker(aNewWorker)| this->addWorkerAt(aNewWorker, index);
  }else{
    wasAdded= this->addWorkerAt(aNewWorker, index);
  }
  
  return wasAdded;  
}

Survivor* Facility::addWorker(const string aName, Shelter* aShelter, LivingQuarters* aLivingQuarters, MedicalBay* aMedicalBay, Mission* aMission){
  if (this->numberOfWorkers() >= this->maximumNumberOfWorkers()){
    return NULL;
  }
  return new Survivor(aName, aShelter, this, aLivingQuarters, aMedicalBay, aMission);  
}

Shelter* Facility::getShelter(void){
  return this->shelter;  
}

vector<Survivor*>* Facility::getSurvivors(void){
  vector<Survivor*>* copyOfSurvivors = new vector<Survivor*>();
  vector<Survivor*>::iterator survivorsBeginIterator(this->survivors->begin());
  vector<Survivor*>::iterator survivorsEndIterator(this->survivors->end());
  copyVector(survivorsBeginIterator, survivorsEndIterator, copyOfSurvivors);
  return copyOfSurvivors;  
}

Survivor* Facility::getSurvivor(int index){
  Survivor* aSurvivor= (*(this->survivors))[index];
  return aSurvivor;  
}

unsigned int Facility::numberOfSurvivors(void){
  int number=this->survivors->size();
  return number;  
}

bool Facility::hasSurvivor(void){
  return this->numberOfSurvivors()>0;  
}

int Facility::indexOfSurvivor(Survivor* aSurvivor){
  return IndexOf(this->survivors->begin(), this->survivors->end(), aSurvivor);  
}

bool Facility::removeSurvivor(Survivor* aSurvivor){
  bool wasRemoved= false;
  int index= IndexOf(this->survivors->begin(), this->survivors->end(), aSurvivor);
  if(index<0){ 
    return wasRemoved;
  }
  wasRemoved= this->removeSurvivorAt(index);aSurvivor->setCurrentLocation(NULL);
  return wasRemoved;  
}

bool Facility::removeSurvivorAt(int index){
  bool wasRemoved= false;
  if(index<0){
      return wasRemoved;
  }
  
  int size= this->numberOfSurvivors();
  if(index> size){
      return false;
  }
  this->survivors->erase(this->survivors->begin()+index);
  wasRemoved= size== this->numberOfSurvivors()+1;
  return wasRemoved;  
}

bool Facility::addSurvivor(Survivor* aNewSurvivor){
  bool wasAdded= false;
  if (IndexOf(this->survivors->begin(), this->survivors->end(), aNewSurvivor)> -1) {
    return wasAdded;
  }
  Facility* existingCurrentLocation = aNewSurvivor->getCurrentLocation();
  if (existingCurrentLocation == NULL){
    aNewSurvivor->setCurrentLocation(this);
  }else if(this!= existingCurrentLocation){
    existingCurrentLocation->removeSurvivor(aNewSurvivor);
    this->addSurvivor(aNewSurvivor);
  }else{
    this->survivors->push_back(aNewSurvivor);
  }
  wasAdded = true;
  return wasAdded;  
}

bool Facility::addSurvivorAt(Survivor* aNewSurvivor, int index){
  bool wasAdded= false;
  if(addSurvivor(aNewSurvivor)){
      int newIndex= index;
      if(index < 0 ) { 
          newIndex = 0; 
      }
    
      int size= this->numberOfSurvivors();
      if(size>0){
          this->survivors->erase(this->survivors->begin()+IndexOf(this->survivors->begin(), this->survivors->end(),aNewSurvivor));    
      }
    
      size= this->numberOfSurvivors();
      if(newIndex > size) { 
          newIndex = size; 
      }
    
     this->survivors->insert(this->survivors->begin()+ newIndex, aNewSurvivor);
      wasAdded = true;
  }
  return wasAdded;  
}

bool Facility::addOrMoveSurvivorAt(Survivor* aNewSurvivor, int index){
  bool wasAdded= false;
  if(IndexOf(this->survivors->begin(), this->survivors->end(), aNewSurvivor) > -1) {
    if (index < 0) {
      index = 0;
    }
  
    int size= this->numberOfSurvivors();
    if (index > size) {
      index = size - 1;
    }
    
    wasAdded= this->removeSurvivor(aNewSurvivor)| this->addSurvivorAt(aNewSurvivor, index);
  }else{
    wasAdded= this->addSurvivorAt(aNewSurvivor, index);
  }
  
  return wasAdded;  
}

vector<InternalMission*>* Facility::getInternalMissions(void){
  vector<InternalMission*>* copyOfInternalMissions = new vector<InternalMission*>();
  vector<InternalMission*>::iterator internalMissionsBeginIterator(this->internalMissions->begin());
  vector<InternalMission*>::iterator internalMissionsEndIterator(this->internalMissions->end());
  copyVector(internalMissionsBeginIterator, internalMissionsEndIterator, copyOfInternalMissions);
  return copyOfInternalMissions;  
}

InternalMission* Facility::getInternalMission(int index){
  InternalMission* aInternalMission= (*(this->internalMissions))[index];
  return aInternalMission;  
}

unsigned int Facility::numberOfInternalMissions(void){
  int number=this->internalMissions->size();
  return number;  
}

bool Facility::hasInternalMission(void){
  return this->numberOfInternalMissions()>0;  
}

int Facility::indexOfInternalMission(InternalMission* aInternalMission){
  return IndexOf(this->internalMissions->begin(), this->internalMissions->end(), aInternalMission);  
}

bool Facility::removeInternalMission(InternalMission* aInternalMission){
  bool wasRemoved= false;
  int index= IndexOf(this->internalMissions->begin(), this->internalMissions->end(), aInternalMission);
  if(index<0){ 
    return wasRemoved;
  }
  //Unable to remove aInternalMission, as it must always have a Facility
  if (this== aInternalMission->getTargetFacility()){
      return wasRemoved;
  }
  wasRemoved= this->removeInternalMissionAt(index);
  return wasRemoved;  
}

bool Facility::removeInternalMissionAt(int index){
  bool wasRemoved= false;
  if(index<0){
      return wasRemoved;
  }
  
  int size= this->numberOfInternalMissions();
  if(index> size){
      return false;
  }
  this->internalMissions->erase(this->internalMissions->begin()+index);
  wasRemoved= size== this->numberOfInternalMissions()+1;
  return wasRemoved;  
}

bool Facility::addInternalMission(InternalMission* aNewInternalMission){
  bool wasAdded= false;
  if (IndexOf(this->internalMissions->begin(), this->internalMissions->end(), aNewInternalMission)> -1) {
    return wasAdded;
  }
  Facility* existingTargetFacility = aNewInternalMission->getTargetFacility();
  bool isNewTargetFacility= existingTargetFacility != NULL && this!=existingTargetFacility;
  if(isNewTargetFacility){
    aNewInternalMission->setTargetFacility(this);
  }else{
    this->internalMissions->push_back(aNewInternalMission);
  }
  wasAdded= true;
  return wasAdded;  
}

bool Facility::addInternalMissionAt(InternalMission* aNewInternalMission, int index){
  bool wasAdded= false;
  if(addInternalMission(aNewInternalMission)){
      int newIndex= index;
      if(index < 0 ) { 
          newIndex = 0; 
      }
    
      int size= this->numberOfInternalMissions();
      if(size>0){
          this->internalMissions->erase(this->internalMissions->begin()+IndexOf(this->internalMissions->begin(), this->internalMissions->end(),aNewInternalMission));    
      }
    
      size= this->numberOfInternalMissions();
      if(newIndex > size) { 
          newIndex = size; 
      }
    
     this->internalMissions->insert(this->internalMissions->begin()+ newIndex, aNewInternalMission);
      wasAdded = true;
  }
  return wasAdded;  
}

bool Facility::addOrMoveInternalMissionAt(InternalMission* aNewInternalMission, int index){
  bool wasAdded= false;
  if(IndexOf(this->internalMissions->begin(), this->internalMissions->end(), aNewInternalMission) > -1) {
    if (index < 0) {
      index = 0;
    }
  
    int size= this->numberOfInternalMissions();
    if (index > size) {
      index = size - 1;
    }
    
    wasAdded= this->removeInternalMission(aNewInternalMission)| this->addInternalMissionAt(aNewInternalMission, index);
  }else{
    wasAdded= this->addInternalMissionAt(aNewInternalMission, index);
  }
  
  return wasAdded;  
}

InternalMission* Facility::addInternalMission(const string aDescription, const int aDifficulty, const int aDuration, Shelter* aShelter, const string aPriority){
  return new InternalMission(aDescription, aDifficulty, aDuration, aShelter, aPriority, this);  
}

bool Facility::activateWithPower(){
  bool wasEventProcessed= false;
  FacilityState aFacilityState= facilityState;
    
  switch((int)aFacilityState){	
  	case FacilityState::FC_Inactive:
  		setFacilityState(FacilityState::FC_Active);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Facility::upgrade(){
  bool wasEventProcessed= false;
  FacilityState aFacilityState= facilityState;
    
  switch((int)aFacilityState){	
  	case FacilityState::FC_Inactive:
  		setFacilityState(FacilityState::FC_Upgrading);
  		wasEventProcessed = true;
  	    break;
  	
  	
  	case FacilityState::FC_Active:
  		exitFacilityState();
  		
  		setFacilityState(FacilityState::FC_Upgrading);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Facility::deactivateOrPowerLost(){
  bool wasEventProcessed= false;
  FacilityState aFacilityState= facilityState;
    
  switch((int)aFacilityState){	
  	case FacilityState::FC_Active:
  		exitFacilityState();
  		
  		setFacilityState(FacilityState::FC_Inactive);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Facility::conditionBelow50(){
  bool wasEventProcessed= false;
  FacilityState aFacilityState= facilityState;
    
  switch((int)aFacilityState){	
  	case FacilityState::FC_Active:
  		exitFacilityState();
  		
  		setFacilityState(FacilityState::FC_Degraded);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Facility::attackOrAccident(){
  bool wasEventProcessed= false;
  FacilityState aFacilityState= facilityState;
    
  switch((int)aFacilityState){	
  	case FacilityState::FC_Active:
  		exitFacilityState();
  		
  		setFacilityState(FacilityState::FC_Damaged);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Facility::repairAbove50(){
  bool wasEventProcessed= false;
  FacilityState aFacilityState= facilityState;
    
  switch((int)aFacilityState){	
  	case FacilityState::FC_Degraded:
  		setFacilityState(FacilityState::FC_Active);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Facility::conditionBelow20(){
  bool wasEventProcessed= false;
  FacilityState aFacilityState= facilityState;
    
  switch((int)aFacilityState){	
  	case FacilityState::FC_Degraded:
  		setFacilityState(FacilityState::FC_Damaged);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Facility::powerLost(){
  bool wasEventProcessed= false;
  FacilityState aFacilityState= facilityState;
    
  switch((int)aFacilityState){	
  	case FacilityState::FC_Degraded:
  		setFacilityState(FacilityState::FC_Inactive);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Facility::repair(){
  bool wasEventProcessed= false;
  FacilityState aFacilityState= facilityState;
    
  switch((int)aFacilityState){	
  	case FacilityState::FC_Damaged:
  		setFacilityState(FacilityState::FC_UnderRepair);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Facility::conditionZero(){
  bool wasEventProcessed= false;
  FacilityState aFacilityState= facilityState;
    
  switch((int)aFacilityState){	
  	case FacilityState::FC_Damaged:
  		setFacilityState(FacilityState::FC_Destroyed);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Facility::partialRepair(){
  bool wasEventProcessed= false;
  FacilityState aFacilityState= facilityState;
    
  switch((int)aFacilityState){	
  	case FacilityState::FC_UnderRepair:
  		setFacilityState(FacilityState::FC_Degraded);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Facility::repairCompleteAbove80(){
  bool wasEventProcessed= false;
  FacilityState aFacilityState= facilityState;
    
  switch((int)aFacilityState){	
  	case FacilityState::FC_UnderRepair:
  		setFacilityState(FacilityState::FC_Active);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Facility::upgradeComplete(){
  bool wasEventProcessed= false;
  FacilityState aFacilityState= facilityState;
    
  switch((int)aFacilityState){	
  	case FacilityState::FC_Upgrading:
  		setFacilityState(FacilityState::FC_Active);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Facility::abort(){
  bool wasEventProcessed= false;
  FacilityState aFacilityState= facilityState;
    
  switch((int)aFacilityState){	
  	case FacilityState::FC_Upgrading:
  		setFacilityState(FacilityState::FC_Inactive);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Facility::assignWorkerAndOperate(){
  bool wasEventProcessed= false;
  FacilityStateFC_ActiveActiveState aFacilityStateFC_ActiveActiveState= facilityStateFC_ActiveActiveState;
    
  switch((int)aFacilityStateFC_ActiveActiveState){	
  	case FacilityStateFC_ActiveActiveState::AC_Idle:
  		setFacilityStateFC_ActiveActiveState(FacilityStateFC_ActiveActiveState::AC_Operating);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Facility::productionCycle(){
  bool wasEventProcessed= false;
  FacilityStateFC_ActiveActiveState aFacilityStateFC_ActiveActiveState= facilityStateFC_ActiveActiveState;
    
  switch((int)aFacilityStateFC_ActiveActiveState){	
  	case FacilityStateFC_ActiveActiveState::AC_Operating:
  		setFacilityStateFC_ActiveActiveState(FacilityStateFC_ActiveActiveState::AC_Producing);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Facility::removeWorker(){
  bool wasEventProcessed= false;
  FacilityStateFC_ActiveActiveState aFacilityStateFC_ActiveActiveState= facilityStateFC_ActiveActiveState;
    
  switch((int)aFacilityStateFC_ActiveActiveState){	
  	case FacilityStateFC_ActiveActiveState::AC_Operating:
  		setFacilityStateFC_ActiveActiveState(FacilityStateFC_ActiveActiveState::AC_Idle);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Facility::cycleComplete(){
  bool wasEventProcessed= false;
  FacilityStateFC_ActiveActiveState aFacilityStateFC_ActiveActiveState= facilityStateFC_ActiveActiveState;
    
  switch((int)aFacilityStateFC_ActiveActiveState){	
  	case FacilityStateFC_ActiveActiveState::AC_Producing:
  		setFacilityStateFC_ActiveActiveState(FacilityStateFC_ActiveActiveState::AC_Operating);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Facility::exitFC_Active(void){
  bool wasEventProcessed= false;
  FacilityStateFC_Active aFacilityStateFC_Active= facilityStateFC_Active;
  FacilityStateFC_ActiveActiveState aFacilityStateFC_ActiveActiveState= facilityStateFC_ActiveActiveState;
    
  switch((int)aFacilityStateFC_Active){	
  	case FacilityStateFC_Active::activeState:
  		
  		setFacilityStateFC_Active(FacilityStateFC_Active::NIL);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
    
  switch((int)aFacilityStateFC_ActiveActiveState){	
  	case FacilityStateFC_ActiveActiveState::AC_Idle:
  		
  		setFacilityStateFC_ActiveActiveState(FacilityStateFC_ActiveActiveState::NIL);
  		wasEventProcessed = true;
  	    break;
  	
  	
  	case FacilityStateFC_ActiveActiveState::AC_Operating:
  		
  		setFacilityStateFC_ActiveActiveState(FacilityStateFC_ActiveActiveState::NIL);
  		wasEventProcessed = true;
  	    break;
  	
  	
  	case FacilityStateFC_ActiveActiveState::AC_Producing:
  		
  		setFacilityStateFC_ActiveActiveState(FacilityStateFC_ActiveActiveState::NIL);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

string Facility::getFacilityStateFullName(void){
  string answer = facilityState;
  
  if (facilityStateFC_Active != FacilityStateFC_Active::NIL) { 
  answer += "." + facilityStateFC_Active; 
  }
  
  
  if (facilityStateFC_ActiveActiveState != FacilityStateFC_ActiveActiveState::NIL) { 
  answer += "." + facilityStateFC_ActiveActiveState; 
  }
  
  return answer;
    
}

FacilityState Facility::getFacilityState(void){
  return this->facilityState;  
}

FacilityStateFC_Active Facility::getFC_Active(void){
  return this->facilityStateFC_Active;  
}

FacilityStateFC_ActiveActiveState Facility::getActiveState(void){
  return this->facilityStateFC_ActiveActiveState;  
}

void Facility::setFacilityState(FacilityState aFacilityState){
  facilityState= aFacilityState;
  
  // entry actions and do activities  
  switch((int)facilityState){	
  	case FacilityState::FC_Active:
  		{
  			if(facilityStateFC_Active== FacilityStateFC_Active::NIL){
  			setFacilityStateFC_Active(FacilityStateFC_Active::activeState);
  			}
  		}
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
    
}

void Facility::setFC_Active(FacilityStateFC_Active aFC_Active){
  fC_Active= aFC_Active;
  if(facilityState != FacilityState::FC_Active && aFC_Active != FacilityStateFC_Active::NIL){	
  	setFacilityState(FacilityState::FC_Active);
  }
  
  // entry actions and do activities  
  switch((int)facilityStateFC_Active){	
  	case FacilityStateFC_Active::activeState:
  		{
  			if(facilityStateFC_ActiveActiveState== FacilityStateFC_ActiveActiveState::NIL){
  			setFacilityStateFC_ActiveActiveState(FacilityStateFC_ActiveActiveState::AC_Idle);
  			}
  		}
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
    
}

void Facility::setActiveState(FacilityStateFC_ActiveActiveState aActiveState){
  activeState= aActiveState;
  if(facilityStateFC_Active != FacilityStateFC_Active::activeState && aActiveState != FacilityStateFC_ActiveActiveState::NIL){	
  	setFacilityStateFC_Active(FacilityStateFC_Active::activeState);
  }
    
}

bool Facility::exitFacilityState(void){
  bool wasEventProcessed = false;
  
    
  switch((int)facilityState){	
  	case FacilityState::FC_Inactive:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case FacilityState::FC_Active:
  		wasEventProcessed= exitFC_Active();
  	    break;
  	
  	
  	case FacilityState::FC_Degraded:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case FacilityState::FC_Damaged:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case FacilityState::FC_UnderRepair:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case FacilityState::FC_Upgrading:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case FacilityState::FC_Destroyed:
  		wasEventProcessed= true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;
    
}

bool Facility::exitFacilityStateFC_Active(void){
  bool wasEventProcessed = false;
  
    
  switch((int)facilityStateFC_Active){	
  	case FC_Active::activeState:
  		wasEventProcessed= exitFC_Active();
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;
    
}

bool Facility::exitFacilityStateFC_ActiveActiveState(void){
  bool wasEventProcessed = false;
  
    
  switch((int)facilityStateFC_ActiveActiveState){	
  	case ActiveState::AC_Idle:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case ActiveState::AC_Operating:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case ActiveState::AC_Producing:
  		wasEventProcessed= true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;
    
}

bool Facility::enterFC_Active(void){
  bool wasEventProcessed = false;
  FacilityStateFC_Active aFacilityStateFC_Active= facilityStateFC_Active;
  FacilityStateFC_ActiveActiveState aFacilityStateFC_ActiveActiveState= facilityStateFC_ActiveActiveState;  
  switch((int)aFacilityStateFC_Active){	
  	case FacilityStateFC_Active::NIL:
  		
  		setFacilityStateFC_Active(FacilityStateFC_Active::activeState);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
    
  switch((int)aFacilityStateFC_ActiveActiveState){	
  	case FacilityStateFC_ActiveActiveState::NIL:
  		
  		setFacilityStateFC_ActiveActiveState(FacilityStateFC_ActiveActiveState::AC_Idle);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;
    
}

size_t Facility::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
Facility::~Facility(){
  this->deleteAssociatedObjects();
  
  std::for_each(workers->begin(), workers->end(), /*std::default_delete<Survivor>*/ deleteElement());
  workers->clear();
  delete workers;
  delete shelter;
  
  std::for_each(survivors->begin(), survivors->end(), /*std::default_delete<Survivor>*/ deleteElement());
  survivors->clear();
  delete survivors;
  
  std::for_each(internalMissions->begin(), internalMissions->end(), /*std::default_delete<InternalMission>*/ deleteElement());
  internalMissions->clear();
  delete internalMissions;  
}

void Facility::deleteAssociatedObjects(void){
  for(unsigned int index = workers->size(); index > 0 ; index--){
    Survivor* aSurvivor= (*(this->workers))[index-1];
    aSurvivor->deleteAssociatedObjects();
  }
  Shelter* placeholderShelter = this->shelter;
  this->shelter = NULL;
  placeholderShelter->removeFacility(this);
  while(this->survivors->size()>0){
    Survivor* aSurvivor= (*(this->survivors))[0];
    aSurvivor->setCurrentLocation(NULL);
  }
  for(unsigned int index = internalMissions->size(); index > 0 ; index--){
    InternalMission* aInternalMission= (*(this->internalMissions))[index-1];
    aInternalMission->deleteAssociatedObjects();
  }  
}
;

