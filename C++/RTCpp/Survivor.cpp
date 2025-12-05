//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__SURVIVOR_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <Survivor.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Survivor.h>
#include <Facility.h>
#include <Mission.h>
#include <Shelter.h>
#include <Children.h>
#include <LivingQuarters.h>
#include <MedicalBay.h>

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
Survivor::Survivor(const string aName, Shelter* aShelter, Facility* aFacility, LivingQuarters* aLivingQuarters, MedicalBay* aMedicalBay, Mission* aMission):
		currentLocation(NULL),
		shelter(NULL),
		facility(NULL),
		livingQuarters(NULL),
		medicalBay(NULL),
		mission(NULL){
  this->name= aName;
  this->health= 100;
  this->radiationLevel= 0;
  this->currentLocation= NULL;
  this->assignedMissions= new vector<Mission*>();
  if (!setShelter(aShelter)){
    throw "Unable to create Survivor due to aShelter";
  }
  this->childrens= new vector<Children*>();
  if (!setFacility(aFacility)){
    throw "Unable to create Survivor due to aFacility";
  }
  if (!setLivingQuarter(aLivingQuarter)){
    throw "Unable to create Survivor due to aLivingQuarter";
  }
  if (!setMedicalBay(aMedicalBay)){
    throw "Unable to create Survivor due to aMedicalBay";
  }
  if (!setMission(aMission)){
    throw "Unable to create Survivor due to aMission";
  }
  if(!(health >= 0 && health <= 100 && radiationLevel >= 0)){  
    throw "Please provide valid health and radiationLevel";
  }
  setPhysicalState(PhysicalState::PH_Healthy);
  setRadiationState(RadiationState::RD_Clean);
  setMentalState(MentalState::MH_Stable);
  setBehaviorState(BehaviorState::BH_Idle);  
}

Survivor::Survivor(Survivor& other):
		currentLocation(NULL),
		shelter(NULL),
		facility(NULL),
		livingQuarters(NULL),
		medicalBay(NULL),
		mission(NULL){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void Survivor::toOstream(ostream& os) const{
  Survivor* thisptr = const_cast<Survivor*>(this);
  os << "[" << "name:" << thisptr->getName()<< ", " <<
      "health:" << thisptr->getHealth()<< ", " <<
      "radiationLevel:" << thisptr->getRadiationLevel() << "]" << endl;
  (thisptr->getCurrentLocation()!= NULL ?  os << "currentLocation:" << thisptr->getCurrentLocation() : os << "currentLocation:" << "NULL")<< endl;
      (thisptr->getAssignedMissions()!= NULL ?  os << "assignedMissions:" << thisptr->getAssignedMissions() : os << "assignedMissions:" << "NULL")<< endl;
      (thisptr->getShelter()!= NULL ?  os << "shelter:" << thisptr->getShelter() : os << "shelter:" << "NULL")<< endl;
      (thisptr->getChildrens()!= NULL ?  os << "childrens:" << thisptr->getChildrens() : os << "childrens:" << "NULL")<< endl;
      (thisptr->getFacility()!= NULL ?  os << "facility:" << thisptr->getFacility() : os << "facility:" << "NULL")<< endl;
      (thisptr->getLivingQuarter()!= NULL ?  os << "livingQuarters:" << thisptr->getLivingQuarter() : os << "livingQuarters:" << "NULL")<< endl;
      (thisptr->getMedicalBay()!= NULL ?  os << "medicalBay:" << thisptr->getMedicalBay() : os << "medicalBay:" << "NULL")<< endl;
      (thisptr->getMission()!= NULL ?  os << "mission:" << thisptr->getMission() : os << "mission:" << "NULL");  
}

ostream& operator<<(ostream& os, const Survivor& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (Survivor& Right, Survivor& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.name.compare(Left.name) != 0){
     return false;
  }
  if(Right.health!= Left.health){
     return false;
  }
  if(Right.radiationLevel!= Left.radiationLevel){
     return false;
  }
  if(!compare(Right.currentLocation, Left.currentLocation, sizeof Right.currentLocation)){
    return false;
  }
  if(!std::equal(Right.assignedMissions->begin(), Right.assignedMissions->end(), Left.assignedMissions->begin())){
     return false;
  }
  if(!compare(Right.shelter, Left.shelter, sizeof Right.shelter)){
    return false;
  }
  if(!std::equal(Right.childrens->begin(), Right.childrens->end(), Left.childrens->begin())){
     return false;
  }
  if(!compare(Right.facility, Left.facility, sizeof Right.facility)){
    return false;
  }
  if(!compare(Right.livingQuarters, Left.livingQuarters, sizeof Right.livingQuarters)){
    return false;
  }
  if(!compare(Right.medicalBay, Left.medicalBay, sizeof Right.medicalBay)){
    return false;
  }
  if(!compare(Right.mission, Left.mission, sizeof Right.mission)){
    return false;
  }  
}

Survivor& Survivor::operator=(Survivor& other){
  internalCopy(other);
  return *this;  
}

void Survivor::internalCopy(Survivor& other){
  this->name.assign(other.name);
  this->health= other.health;
  this->radiationLevel= other.radiationLevel;
  copyObject(other.currentLocation, this->currentLocation, sizeof other.currentLocation);
  this->assignedMissions = new vector<Mission*>();
  vector<Mission*>::iterator assignedMissionsBeginIterator(other.assignedMissions->begin());
  vector<Mission*>::iterator assignedMissionsEndIterator(other.assignedMissions->end());
  copyVector(assignedMissionsBeginIterator, assignedMissionsEndIterator, this->assignedMissions);
  copyObject(other.shelter, this->shelter, sizeof other.shelter);
  this->childrens = new vector<Children*>();
  vector<Children*>::iterator childrensBeginIterator(other.childrens->begin());
  vector<Children*>::iterator childrensEndIterator(other.childrens->end());
  copyVector(childrensBeginIterator, childrensEndIterator, this->childrens);
  copyObject(other.facility, this->facility, sizeof other.facility);
  copyObject(other.livingQuarters, this->livingQuarters, sizeof other.livingQuarters);
  copyObject(other.medicalBay, this->medicalBay, sizeof other.medicalBay);
  copyObject(other.mission, this->mission, sizeof other.mission);  
}

bool Survivor::setName(const string aNewName){
  bool wasSet= false;
  this->name = aNewName;
  wasSet= true;
  return wasSet;  
}

bool Survivor::setHealth(const int aNewHealth){
  bool wasSet= false;
  if(health >= 0){  
    this->health = aNewHealth;
    wasSet= true;
  }
  return wasSet;  
}

bool Survivor::setRadiationLevel(const int aNewRadiationLevel){
  bool wasSet= false;
  if(radiationLevel >= 0){  
    this->radiationLevel = aNewRadiationLevel;
    wasSet= true;
  }
  return wasSet;  
}

bool Survivor::setCurrentLocation(Facility* aNewCurrentLocation){
  bool wasSet= false;
  Facility* existingCurrentLocation = this->currentLocation;
  this->currentLocation = aNewCurrentLocation;
  if (existingCurrentLocation != NULL && existingCurrentLocation !=aNewCurrentLocation){
    existingCurrentLocation->removeSurvivor(this);
  }
  
  if (aNewCurrentLocation != NULL){
    aNewCurrentLocation->addSurvivor(this);
  }
  wasSet= true;
  return wasSet;  
}

bool Survivor::setShelter(Shelter* aNewShelter){
  bool wasSet= false;
  if(aNewShelter == NULL){
    //Must provide shelter to Survivor
    return wasSet;
  }
  
  if(aNewShelter->numberOfOccupants() >= aNewShelter->maximumNumberOfOccupants()){
    return wasSet;
  }
  
  Shelter* existingShelter = this->shelter;
  this->shelter = aNewShelter;
  if (existingShelter != NULL && existingShelter!= aNewShelter){
    bool didRemove = existingShelter->removeOccupant(this);
    if(!didRemove){
      this->shelter = existingShelter;
      return wasSet;
    }
  }
  this->shelter->addOccupant(this);
  wasSet = true;
  
  return wasSet;  
}

bool Survivor::setFacility(Facility* aNewFacility){
  bool wasSet= false;
  if(aNewFacility == NULL){
    //Must provide facility to Survivor
    return wasSet;
  }
  
  if(aNewFacility->numberOfWorkers() >= aNewFacility->maximumNumberOfWorkers()){
    return wasSet;
  }
  
  Facility* existingFacility = this->facility;
  this->facility = aNewFacility;
  if (existingFacility != NULL && existingFacility!= aNewFacility){
    bool didRemove = existingFacility->removeWorker(this);
    if(!didRemove){
      this->facility = existingFacility;
      return wasSet;
    }
  }
  this->facility->addWorker(this);
  wasSet = true;
  
  return wasSet;  
}

bool Survivor::setLivingQuarter(LivingQuarters* aNewLivingQuarter){
  bool wasSet= false;
  if(aNewLivingQuarter == NULL){
    //Must provide livingQuarters to Survivor
    return wasSet;
  }
  
  if(aNewLivingQuarter->numberOfResidents() >= aNewLivingQuarter->maximumNumberOfResidents()){
    return wasSet;
  }
  
  LivingQuarters* existingLivingQuarters = this->livingQuarters;
  this->livingQuarters = aNewLivingQuarter;
  if (existingLivingQuarters != NULL && existingLivingQuarters!= aNewLivingQuarter){
    bool didRemove = existingLivingQuarters->removeResident(this);
    if(!didRemove){
      this->livingQuarters = existingLivingQuarters;
      return wasSet;
    }
  }
  this->livingQuarters->addResident(this);
  wasSet = true;
  
  return wasSet;  
}

bool Survivor::setMedicalBay(MedicalBay* aNewMedicalBay){
  bool wasSet= false;
  if(aNewMedicalBay == NULL){
    //Must provide medicalBay to Survivor
    return wasSet;
  }
  
  if(aNewMedicalBay->numberOfPatients() >= aNewMedicalBay->maximumNumberOfPatients()){
    return wasSet;
  }
  
  MedicalBay* existingMedicalBay = this->medicalBay;
  this->medicalBay = aNewMedicalBay;
  if (existingMedicalBay != NULL && existingMedicalBay!= aNewMedicalBay){
    bool didRemove = existingMedicalBay->removePatient(this);
    if(!didRemove){
      this->medicalBay = existingMedicalBay;
      return wasSet;
    }
  }
  this->medicalBay->addPatient(this);
  wasSet = true;
  
  return wasSet;  
}

bool Survivor::setMission(Mission* aNewMission){
  bool wasSet= false;
  if (aNewMission == NULL){
    return wasSet;
  }
  
  Mission* existingMission = this->mission;
  this->mission = aNewMission;
  
  if (existingMission != NULL && existingMission != aNewMission){
      existingMission->removeTeam(this);
  }
  this->mission->addTeam(this);
  wasSet = true;
  return wasSet;  
}

string Survivor::getName(void){
  return this->name;  
}

int Survivor::getHealth(void){
  return this->health;  
}

int Survivor::getRadiationLevel(void){
  return this->radiationLevel;  
}

Facility* Survivor::getCurrentLocation(void){
  return this->currentLocation;  
}

vector<Mission*>* Survivor::getAssignedMissions(void){
  vector<Mission*>* copyOfAssignedMissions = new vector<Mission*>();
  vector<Mission*>::iterator assignedMissionsBeginIterator(this->assignedMissions->begin());
  vector<Mission*>::iterator assignedMissionsEndIterator(this->assignedMissions->end());
  copyVector(assignedMissionsBeginIterator, assignedMissionsEndIterator, copyOfAssignedMissions);
  return copyOfAssignedMissions;  
}

Mission* Survivor::getAssignedMission(int index){
  Mission* aAssignedMission= (*(this->assignedMissions))[index];
  return aAssignedMission;  
}

unsigned int Survivor::numberOfAssignedMissions(void){
  int number=this->assignedMissions->size();
  return number;  
}

bool Survivor::hasAssignedMission(void){
  return this->numberOfAssignedMissions()>0;  
}

int Survivor::indexOfAssignedMission(Mission* aAssignedMission){
  return IndexOf(this->assignedMissions->begin(), this->assignedMissions->end(), aAssignedMission);  
}

bool Survivor::removeAssignedMission(Mission* aAssignedMission){
  bool wasRemoved= false;
  int index= IndexOf(this->assignedMissions->begin(), this->assignedMissions->end(), aAssignedMission);
  if(index<0){ 
    return wasRemoved;
  }
  wasRemoved= this->removeAssignedMissionAt(index);
  if (aAssignedMission->indexOfSurvivor(this) == -1){
    wasRemoved = true;
  }else{
    wasRemoved = aAssignedMission->removeSurvivor(this);
    if (!wasRemoved){
      this->assignedMissions->insert(this->assignedMissions->begin()+ index, aAssignedMission);
    }
  }
  return wasRemoved;  
}

bool Survivor::removeAssignedMissionAt(int index){
  bool wasRemoved= false;
  if(index<0){
      return wasRemoved;
  }
  
  int size= this->numberOfAssignedMissions();
  if(index> size){
      return false;
  }
  this->assignedMissions->erase(this->assignedMissions->begin()+index);
  wasRemoved= size== this->numberOfAssignedMissions()+1;
  return wasRemoved;  
}

bool Survivor::addAssignedMission(Mission* aNewAssignedMission){
  bool wasAdded= false;
  if (IndexOf(this->assignedMissions->begin(), this->assignedMissions->end(), aNewAssignedMission)> -1) {
    return wasAdded;
  }
  this->assignedMissions->push_back(aNewAssignedMission);
  if (aNewAssignedMission->indexOfSurvivor(this)!= -1) {
    wasAdded = true;
  }else{
    wasAdded = aNewAssignedMission->addSurvivor(this);
    if(!wasAdded){
      int currentIndex= this->indexOfAssignedMission(aNewAssignedMission);
      this->assignedMissions->erase(this->assignedMissions->begin()+currentIndex);
    }
  }
  return wasAdded;  
}

bool Survivor::addAssignedMissionAt(Mission* aNewAssignedMission, int index){
  bool wasAdded= false;
  if(addAssignedMission(aNewAssignedMission)){
      int newIndex= index;
      if(index < 0 ) { 
          newIndex = 0; 
      }
    
      int size= this->numberOfAssignedMissions();
      if(size>0){
          this->assignedMissions->erase(this->assignedMissions->begin()+IndexOf(this->assignedMissions->begin(), this->assignedMissions->end(),aNewAssignedMission));    
      }
    
      size= this->numberOfAssignedMissions();
      if(newIndex > size) { 
          newIndex = size; 
      }
    
     this->assignedMissions->insert(this->assignedMissions->begin()+ newIndex, aNewAssignedMission);
      wasAdded = true;
  }
  return wasAdded;  
}

bool Survivor::addOrMoveAssignedMissionAt(Mission* aNewAssignedMission, int index){
  bool wasAdded= false;
  if(IndexOf(this->assignedMissions->begin(), this->assignedMissions->end(), aNewAssignedMission) > -1) {
    if (index < 0) {
      index = 0;
    }
  
    int size= this->numberOfAssignedMissions();
    if (index > size) {
      index = size - 1;
    }
    
    wasAdded= this->removeAssignedMission(aNewAssignedMission)| this->addAssignedMissionAt(aNewAssignedMission, index);
  }else{
    wasAdded= this->addAssignedMissionAt(aNewAssignedMission, index);
  }
  
  return wasAdded;  
}

Shelter* Survivor::getShelter(void){
  return this->shelter;  
}

vector<Children*>* Survivor::getChildrens(void){
  vector<Children*>* copyOfChildrens = new vector<Children*>();
  vector<Children*>::iterator childrensBeginIterator(this->childrens->begin());
  vector<Children*>::iterator childrensEndIterator(this->childrens->end());
  copyVector(childrensBeginIterator, childrensEndIterator, copyOfChildrens);
  return copyOfChildrens;  
}

Children* Survivor::getChildren(int index){
  Children* aChildren= (*(this->childrens))[index];
  return aChildren;  
}

unsigned int Survivor::numberOfChildrens(void){
  int number=this->childrens->size();
  return number;  
}

bool Survivor::hasChildren(void){
  return this->numberOfChildrens()>0;  
}

int Survivor::indexOfChildren(Children* aChildren){
  return IndexOf(this->childrens->begin(), this->childrens->end(), aChildren);  
}

bool Survivor::removeChildren(Children* aChildren){
  bool wasRemoved= false;
  int index= IndexOf(this->childrens->begin(), this->childrens->end(), aChildren);
  if(index<0){ 
    return wasRemoved;
  }
  wasRemoved= this->removeChildrenAt(index);aChildren->setGuardian(NULL);
  return wasRemoved;  
}

bool Survivor::removeChildrenAt(int index){
  bool wasRemoved= false;
  if(index<0){
      return wasRemoved;
  }
  
  int size= this->numberOfChildrens();
  if(index> size){
      return false;
  }
  this->childrens->erase(this->childrens->begin()+index);
  wasRemoved= size== this->numberOfChildrens()+1;
  return wasRemoved;  
}

bool Survivor::addChildren(Children* aNewChildren){
  bool wasAdded= false;
  if (IndexOf(this->childrens->begin(), this->childrens->end(), aNewChildren)> -1) {
    return wasAdded;
  }
  Survivor* existingGuardian = aNewChildren->getGuardian();
  if (existingGuardian == NULL){
    aNewChildren->setGuardian(this);
  }else if(this!= existingGuardian){
    existingGuardian->removeChildren(aNewChildren);
    this->addChildren(aNewChildren);
  }else{
    this->childrens->push_back(aNewChildren);
  }
  wasAdded = true;
  return wasAdded;  
}

bool Survivor::addChildrenAt(Children* aNewChildren, int index){
  bool wasAdded= false;
  if(addChildren(aNewChildren)){
      int newIndex= index;
      if(index < 0 ) { 
          newIndex = 0; 
      }
    
      int size= this->numberOfChildrens();
      if(size>0){
          this->childrens->erase(this->childrens->begin()+IndexOf(this->childrens->begin(), this->childrens->end(),aNewChildren));    
      }
    
      size= this->numberOfChildrens();
      if(newIndex > size) { 
          newIndex = size; 
      }
    
     this->childrens->insert(this->childrens->begin()+ newIndex, aNewChildren);
      wasAdded = true;
  }
  return wasAdded;  
}

bool Survivor::addOrMoveChildrenAt(Children* aNewChildren, int index){
  bool wasAdded= false;
  if(IndexOf(this->childrens->begin(), this->childrens->end(), aNewChildren) > -1) {
    if (index < 0) {
      index = 0;
    }
  
    int size= this->numberOfChildrens();
    if (index > size) {
      index = size - 1;
    }
    
    wasAdded= this->removeChildren(aNewChildren)| this->addChildrenAt(aNewChildren, index);
  }else{
    wasAdded= this->addChildrenAt(aNewChildren, index);
  }
  
  return wasAdded;  
}

Facility* Survivor::getFacility(void){
  return this->facility;  
}

LivingQuarters* Survivor::getLivingQuarter(void){
  return this->livingQuarters;  
}

MedicalBay* Survivor::getMedicalBay(void){
  return this->medicalBay;  
}

Mission* Survivor::getMission(void){
  return this->mission;  
}

bool Survivor::takeDamageAbove50(){
  bool wasEventProcessed= false;
  PhysicalState aPhysicalState= physicalState;
    
  switch((int)aPhysicalState){	
  	case PhysicalState::PH_Healthy:
  		setPhysicalState(PhysicalState::PH_Wounded);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::takeDamageBelow50(){
  bool wasEventProcessed= false;
  PhysicalState aPhysicalState= physicalState;
    
  switch((int)aPhysicalState){	
  	case PhysicalState::PH_Healthy:
  		setPhysicalState(PhysicalState::PH_Severe);
  		wasEventProcessed = true;
  	    break;
  	
  	
  	case PhysicalState::PH_Wounded:
  		setPhysicalState(PhysicalState::PH_Severe);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::healAndRestAbove80(){
  bool wasEventProcessed= false;
  PhysicalState aPhysicalState= physicalState;
    
  switch((int)aPhysicalState){	
  	case PhysicalState::PH_Wounded:
  		setPhysicalState(PhysicalState::PH_Healthy);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::treatmentAbove50(){
  bool wasEventProcessed= false;
  PhysicalState aPhysicalState= physicalState;
    
  switch((int)aPhysicalState){	
  	case PhysicalState::PH_Severe:
  		setPhysicalState(PhysicalState::PH_Wounded);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::healthBelow20(){
  bool wasEventProcessed= false;
  PhysicalState aPhysicalState= physicalState;
    
  switch((int)aPhysicalState){	
  	case PhysicalState::PH_Severe:
  		setPhysicalState(PhysicalState::PH_Critical);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::emergencySurgery(){
  bool wasEventProcessed= false;
  PhysicalState aPhysicalState= physicalState;
    
  switch((int)aPhysicalState){	
  	case PhysicalState::PH_Critical:
  		setPhysicalState(PhysicalState::PH_Severe);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::healthZero(){
  bool wasEventProcessed= false;
  PhysicalState aPhysicalState= physicalState;
    
  switch((int)aPhysicalState){	
  	case PhysicalState::PH_Critical:
  		setPhysicalState(PhysicalState::PH_Dead);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::increaseRadiation(){
  bool wasEventProcessed= false;
  RadiationState aRadiationState= radiationState;
    
  switch((int)aRadiationState){	
  	case RadiationState::RD_Clean:
  		setRadiationState(RadiationState::RD_Low);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::treatRadiationToZero(){
  bool wasEventProcessed= false;
  RadiationState aRadiationState= radiationState;
    
  switch((int)aRadiationState){	
  	case RadiationState::RD_Low:
  		setRadiationState(RadiationState::RD_Clean);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::radiationAbove30(){
  bool wasEventProcessed= false;
  RadiationState aRadiationState= radiationState;
    
  switch((int)aRadiationState){	
  	case RadiationState::RD_Low:
  		setRadiationState(RadiationState::RD_High);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::radAwayBelow30(){
  bool wasEventProcessed= false;
  RadiationState aRadiationState= radiationState;
    
  switch((int)aRadiationState){	
  	case RadiationState::RD_High:
  		setRadiationState(RadiationState::RD_Low);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::radiationAbove70(){
  bool wasEventProcessed= false;
  RadiationState aRadiationState= radiationState;
    
  switch((int)aRadiationState){	
  	case RadiationState::RD_High:
  		setRadiationState(RadiationState::RD_Severe);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::untreatedTick(){
  bool wasEventProcessed= false;
  RadiationState aRadiationState= radiationState;
    
  switch((int)aRadiationState){	
  	case RadiationState::RD_High:
  		setRadiationState(RadiationState::RD_High);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::intensiveTreatment(){
  bool wasEventProcessed= false;
  RadiationState aRadiationState= radiationState;
    
  switch((int)aRadiationState){	
  	case RadiationState::RD_Severe:
  		setRadiationState(RadiationState::RD_High);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::radiationFull(){
  bool wasEventProcessed= false;
  RadiationState aRadiationState= radiationState;
    
  switch((int)aRadiationState){	
  	case RadiationState::RD_Severe:
  		setRadiationState(RadiationState::RD_Dead);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::moraleLowOrTrauma(){
  bool wasEventProcessed= false;
  MentalState aMentalState= mentalState;
    
  switch((int)aMentalState){	
  	case MentalState::MH_Stable:
  		setMentalState(MentalState::MH_Stressed);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::restAndPositiveEvent(){
  bool wasEventProcessed= false;
  MentalState aMentalState= mentalState;
    
  switch((int)aMentalState){	
  	case MentalState::MH_Stressed:
  		setMentalState(MentalState::MH_Stable);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::moraleVeryLowOrRepeatedTrauma(){
  bool wasEventProcessed= false;
  MentalState aMentalState= mentalState;
    
  switch((int)aMentalState){	
  	case MentalState::MH_Stressed:
  		setMentalState(MentalState::MH_Depressed);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::therapyAndTime(){
  bool wasEventProcessed= false;
  MentalState aMentalState= mentalState;
    
  switch((int)aMentalState){	
  	case MentalState::MH_Depressed:
  		setMentalState(MentalState::MH_Stressed);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::moraleCritical(){
  bool wasEventProcessed= false;
  MentalState aMentalState= mentalState;
    
  switch((int)aMentalState){	
  	case MentalState::MH_Depressed:
  		setMentalState(MentalState::MH_Breakdown);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::forceIntervention(){
  bool wasEventProcessed= false;
  MentalState aMentalState= mentalState;
    
  switch((int)aMentalState){	
  	case MentalState::MH_Breakdown:
  		setMentalState(MentalState::MH_Depressed);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::noIntervention24h(){
  bool wasEventProcessed= false;
  MentalState aMentalState= mentalState;
    
  switch((int)aMentalState){	
  	case MentalState::MH_Breakdown:
  		setMentalState(MentalState::MH_Exile);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::assignToFacility(){
  bool wasEventProcessed= false;
  BehaviorState aBehaviorState= behaviorState;
    
  switch((int)aBehaviorState){	
  	case BehaviorState::BH_Idle:
  		if(canWork()){	
  			setBehaviorState(BehaviorState::BH_Working);
  			wasEventProcessed = true;
  		}
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::assignToMission(){
  bool wasEventProcessed= false;
  BehaviorState aBehaviorState= behaviorState;
    
  switch((int)aBehaviorState){	
  	case BehaviorState::BH_Idle:
  		if(canParticipate()){	
  			setBehaviorState(BehaviorState::BH_OnMission);
  			wasEventProcessed = true;
  		}
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::manualRest(){
  bool wasEventProcessed= false;
  BehaviorState aBehaviorState= behaviorState;
    
  switch((int)aBehaviorState){	
  	case BehaviorState::BH_Idle:
  		setBehaviorState(BehaviorState::BH_Resting);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::cannotWork(){
  bool wasEventProcessed= false;
  BehaviorState aBehaviorState= behaviorState;
    
  switch((int)aBehaviorState){	
  	case BehaviorState::BH_Idle:
  		setBehaviorState(BehaviorState::BH_ForcedRest);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::removeFromFacility(){
  bool wasEventProcessed= false;
  BehaviorState aBehaviorState= behaviorState;
    
  switch((int)aBehaviorState){	
  	case BehaviorState::BH_Working:
  		setBehaviorState(BehaviorState::BH_Idle);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::urgentMissionCall(){
  bool wasEventProcessed= false;
  BehaviorState aBehaviorState= behaviorState;
    
  switch((int)aBehaviorState){	
  	case BehaviorState::BH_Working:
  		setBehaviorState(BehaviorState::BH_OnMission);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::healthStateWorsened(){
  bool wasEventProcessed= false;
  BehaviorState aBehaviorState= behaviorState;
    
  switch((int)aBehaviorState){	
  	case BehaviorState::BH_Working:
  		setBehaviorState(BehaviorState::BH_ForcedRest);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::missionComplete(){
  bool wasEventProcessed= false;
  BehaviorState aBehaviorState= behaviorState;
    
  switch((int)aBehaviorState){	
  	case BehaviorState::BH_OnMission:
  		setBehaviorState(BehaviorState::BH_Idle);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::injuredDuringMission(){
  bool wasEventProcessed= false;
  BehaviorState aBehaviorState= behaviorState;
    
  switch((int)aBehaviorState){	
  	case BehaviorState::BH_OnMission:
  		setBehaviorState(BehaviorState::BH_ForcedRest);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::restComplete(){
  bool wasEventProcessed= false;
  BehaviorState aBehaviorState= behaviorState;
    
  switch((int)aBehaviorState){	
  	case BehaviorState::BH_Resting:
  		setBehaviorState(BehaviorState::BH_Idle);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::enterMedicalBay(){
  bool wasEventProcessed= false;
  BehaviorState aBehaviorState= behaviorState;
    
  switch((int)aBehaviorState){	
  	case BehaviorState::BH_ForcedRest:
  		setBehaviorState(BehaviorState::BH_Healing);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::enterLivingQuarters(){
  bool wasEventProcessed= false;
  BehaviorState aBehaviorState= behaviorState;
    
  switch((int)aBehaviorState){	
  	case BehaviorState::BH_ForcedRest:
  		setBehaviorState(BehaviorState::BH_Recovering);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::healingComplete(){
  bool wasEventProcessed= false;
  BehaviorState aBehaviorState= behaviorState;
    
  switch((int)aBehaviorState){	
  	case BehaviorState::BH_Healing:
  		setBehaviorState(BehaviorState::BH_Idle);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Survivor::recoveryComplete(){
  bool wasEventProcessed= false;
  BehaviorState aBehaviorState= behaviorState;
    
  switch((int)aBehaviorState){	
  	case BehaviorState::BH_Recovering:
  		setBehaviorState(BehaviorState::BH_Idle);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

string Survivor::getPhysicalStateFullName(void){
  string answer = physicalState;
  return answer;
    
}

PhysicalState Survivor::getPhysicalState(void){
  return this->physicalState;  
}

string Survivor::getRadiationStateFullName(void){
  string answer = radiationState;
  return answer;
    
}

RadiationState Survivor::getRadiationState(void){
  return this->radiationState;  
}

string Survivor::getMentalStateFullName(void){
  string answer = mentalState;
  return answer;
    
}

MentalState Survivor::getMentalState(void){
  return this->mentalState;  
}

string Survivor::getBehaviorStateFullName(void){
  string answer = behaviorState;
  return answer;
    
}

BehaviorState Survivor::getBehaviorState(void){
  return this->behaviorState;  
}

void Survivor::setPhysicalState(PhysicalState aPhysicalState){
  physicalState= aPhysicalState;
    
}

void Survivor::setRadiationState(RadiationState aRadiationState){
  radiationState= aRadiationState;
    
}

void Survivor::setMentalState(MentalState aMentalState){
  mentalState= aMentalState;
    
}

void Survivor::setBehaviorState(BehaviorState aBehaviorState){
  behaviorState= aBehaviorState;
    
}

bool Survivor::exitPhysicalState(void){
  bool wasEventProcessed = false;
  
    
  switch((int)physicalState){	
  	case PhysicalState::PH_Healthy:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case PhysicalState::PH_Wounded:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case PhysicalState::PH_Severe:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case PhysicalState::PH_Critical:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case PhysicalState::PH_Dead:
  		wasEventProcessed= true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;
    
}

bool Survivor::exitRadiationState(void){
  bool wasEventProcessed = false;
  
    
  switch((int)radiationState){	
  	case RadiationState::RD_Clean:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case RadiationState::RD_Low:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case RadiationState::RD_High:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case RadiationState::RD_Severe:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case RadiationState::RD_Dead:
  		wasEventProcessed= true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;
    
}

bool Survivor::exitMentalState(void){
  bool wasEventProcessed = false;
  
    
  switch((int)mentalState){	
  	case MentalState::MH_Stable:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case MentalState::MH_Stressed:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case MentalState::MH_Depressed:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case MentalState::MH_Breakdown:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case MentalState::MH_Exile:
  		wasEventProcessed= true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;
    
}

bool Survivor::exitBehaviorState(void){
  bool wasEventProcessed = false;
  
    
  switch((int)behaviorState){	
  	case BehaviorState::BH_Idle:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case BehaviorState::BH_Working:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case BehaviorState::BH_OnMission:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case BehaviorState::BH_Resting:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case BehaviorState::BH_ForcedRest:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case BehaviorState::BH_Healing:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case BehaviorState::BH_Recovering:
  		wasEventProcessed= true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;
    
}

size_t Survivor::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
Survivor::~Survivor(){
  this->deleteAssociatedObjects();
  delete currentLocation;
  
  std::for_each(assignedMissions->begin(), assignedMissions->end(), /*std::default_delete<Mission>*/ deleteElement());
  assignedMissions->clear();
  delete assignedMissions;
  delete shelter;
  
  std::for_each(childrens->begin(), childrens->end(), /*std::default_delete<Children>*/ deleteElement());
  childrens->clear();
  delete childrens;
  delete facility;
  delete livingQuarters;
  delete medicalBay;
  delete mission;  
}

void Survivor::deleteAssociatedObjects(void){
  if(this->currentLocation != NULL){
    Facility* placeholderCurrentLocation = this->currentLocation;
    this->currentLocation = NULL;
    placeholderCurrentLocation->removeSurvivor(this);
  }
  vector<Mission*>* copyOfAssignedMissions = new vector<Mission*>();
  vector<Mission*>::iterator assignedMissionsBeginIterator(this->assignedMissions->begin());
  vector<Mission*>::iterator assignedMissionsEndIterator(this->assignedMissions->end());
  copyVector(assignedMissionsBeginIterator, assignedMissionsEndIterator, copyOfAssignedMissions);
  this->assignedMissions->clear();
  
  while(this->assignedMissions->size()>0){
    Mission* aMission= (*(copyOfAssignedMissions))[0];
    aMission->removeSurvivor(this);
  }
  Shelter* placeholderShelter = this->shelter;
  this->shelter = NULL;
  placeholderShelter->removeOccupant(this);
  while(this->childrens->size()>0){
    Children* aChildren= (*(this->childrens))[0];
    aChildren->setGuardian(NULL);
  }
  Facility* placeholderFacility = this->facility;
  this->facility = NULL;
  placeholderFacility->removeWorker(this);
  LivingQuarters* placeholderLivingQuarters = this->livingQuarters;
  this->livingQuarters = NULL;
  placeholderLivingQuarters->removeResident(this);
  MedicalBay* placeholderMedicalBay = this->medicalBay;
  this->medicalBay = NULL;
  placeholderMedicalBay->removePatient(this);
  Mission* placeholderMission = this->mission;
  this->mission = NULL;
  placeholderMission->removeTeam(this);  
}
;

