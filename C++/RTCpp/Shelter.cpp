//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__SHELTER_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <Shelter.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Shelter.h>
#include <Survivor.h>
#include <Facility.h>
#include <LivingQuarters.h>
#include <MedicalBay.h>
#include <Mission.h>
#include <RadiationMonitor.h>

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
Shelter::Shelter(const string aName, const int aMaxCapacity, const int aCurrentPopulation, RadiationMonitor* aRadiationMonitor):
		radiationMonitor(NULL){
  this->name= aName;
  this->maxCapacity= aMaxCapacity;
  this->currentPopulation= aCurrentPopulation;
  this->occupants= new vector<Survivor*>();
  this->facilities= new vector<Facility*>();
  this->missions= new vector<Mission*>();
  if (aRadiationMonitor == NULL || aRadiationMonitor->getShelter() != NULL){
    throw "Unable to create Shelter due to aRadiationMonitor";
  }
  this->radiationMonitor = aRadiationMonitor;
  if(!(currentPopulation >= 0 && currentPopulation <= maxCapacity && maxCapacity > 0)){  
    throw "Please provide valid currentPopulation and maxCapacity";
  }
  setShelterState(ShelterState::SH_Normal);  
}

Shelter::Shelter(Shelter& other):
		radiationMonitor(NULL){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void Shelter::toOstream(ostream& os) const{
  Shelter* thisptr = const_cast<Shelter*>(this);
  os << "[" << "name:" << thisptr->getName()<< ", " <<
      "maxCapacity:" << thisptr->getMaxCapacity()<< ", " <<
      "currentPopulation:" << thisptr->getCurrentPopulation() << "]" << endl;
  (thisptr->getOccupants()!= NULL ?  os << "occupants:" << thisptr->getOccupants() : os << "occupants:" << "NULL")<< endl;
      (thisptr->getFacilities()!= NULL ?  os << "facilities:" << thisptr->getFacilities() : os << "facilities:" << "NULL")<< endl;
      (thisptr->getMissions()!= NULL ?  os << "missions:" << thisptr->getMissions() : os << "missions:" << "NULL")<< endl;
      (thisptr->getRadiationMonitor()!= NULL ?  os << "radiationMonitor:" << thisptr->getRadiationMonitor() : os << "radiationMonitor:" << "NULL");  
}

ostream& operator<<(ostream& os, const Shelter& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (Shelter& Right, Shelter& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.name.compare(Left.name) != 0){
     return false;
  }
  if(Right.maxCapacity!= Left.maxCapacity){
     return false;
  }
  if(Right.currentPopulation!= Left.currentPopulation){
     return false;
  }
  if(!std::equal(Right.occupants->begin(), Right.occupants->end(), Left.occupants->begin())){
     return false;
  }
  if(!std::equal(Right.facilities->begin(), Right.facilities->end(), Left.facilities->begin())){
     return false;
  }
  if(!std::equal(Right.missions->begin(), Right.missions->end(), Left.missions->begin())){
     return false;
  }
  if(!compare(Right.radiationMonitor, Left.radiationMonitor, sizeof Right.radiationMonitor)){
    return false;
  }  
}

Shelter& Shelter::operator=(Shelter& other){
  internalCopy(other);
  return *this;  
}

void Shelter::internalCopy(Shelter& other){
  this->name.assign(other.name);
  this->maxCapacity= other.maxCapacity;
  this->currentPopulation= other.currentPopulation;
  this->occupants = new vector<Survivor*>();
  vector<Survivor*>::iterator occupantsBeginIterator(other.occupants->begin());
  vector<Survivor*>::iterator occupantsEndIterator(other.occupants->end());
  copyVector(occupantsBeginIterator, occupantsEndIterator, this->occupants);
  this->facilities = new vector<Facility*>();
  vector<Facility*>::iterator facilitiesBeginIterator(other.facilities->begin());
  vector<Facility*>::iterator facilitiesEndIterator(other.facilities->end());
  copyVector(facilitiesBeginIterator, facilitiesEndIterator, this->facilities);
  this->missions = new vector<Mission*>();
  vector<Mission*>::iterator missionsBeginIterator(other.missions->begin());
  vector<Mission*>::iterator missionsEndIterator(other.missions->end());
  copyVector(missionsBeginIterator, missionsEndIterator, this->missions);
  copyObject(other.radiationMonitor, this->radiationMonitor, sizeof other.radiationMonitor);  
}

bool Shelter::setName(const string aNewName){
  bool wasSet= false;
  this->name = aNewName;
  wasSet= true;
  return wasSet;  
}

bool Shelter::setMaxCapacity(const int aNewMaxCapacity){
  bool wasSet= false;
  if(currentPopulation <= maxCapacity && maxCapacity > 0){  
    this->maxCapacity = aNewMaxCapacity;
    wasSet= true;
  }
  return wasSet;  
}

bool Shelter::setCurrentPopulation(const int aNewCurrentPopulation){
  bool wasSet= false;
  if(currentPopulation >= 0 && currentPopulation <= maxCapacity){  
    this->currentPopulation = aNewCurrentPopulation;
    wasSet= true;
  }
  return wasSet;  
}

string Shelter::getName(void){
  return this->name;  
}

int Shelter::getMaxCapacity(void){
  return this->maxCapacity;  
}

int Shelter::getCurrentPopulation(void){
  return this->currentPopulation;  
}

vector<Survivor*>* Shelter::getOccupants(void){
  vector<Survivor*>* copyOfOccupants = new vector<Survivor*>();
  vector<Survivor*>::iterator occupantsBeginIterator(this->occupants->begin());
  vector<Survivor*>::iterator occupantsEndIterator(this->occupants->end());
  copyVector(occupantsBeginIterator, occupantsEndIterator, copyOfOccupants);
  return copyOfOccupants;  
}

Survivor* Shelter::getOccupant(int index){
  Survivor* aOccupant= (*(this->occupants))[index];
  return aOccupant;  
}

unsigned int Shelter::numberOfOccupants(void){
  int number=this->occupants->size();
  return number;  
}

bool Shelter::hasOccupant(void){
  return this->numberOfOccupants()>0;  
}

int Shelter::indexOfOccupant(Survivor* aOccupant){
  return IndexOf(this->occupants->begin(), this->occupants->end(), aOccupant);  
}

bool Shelter::removeOccupant(Survivor* aOccupant){
  bool wasRemoved= false;
  int index= IndexOf(this->occupants->begin(), this->occupants->end(), aOccupant);
  if(index<0){ 
    return wasRemoved;
  }
  //Unable to remove aOccupant, as it must always have a Shelter
  if (this== aOccupant->getShelter()){
      return wasRemoved;
  }
  wasRemoved= this->removeOccupantAt(index);
  return wasRemoved;  
}

bool Shelter::removeOccupantAt(int index){
  bool wasRemoved= false;
  if(index<0){
      return wasRemoved;
  }
  
  int size= this->numberOfOccupants();
  if(index> size){
      return false;
  }
  this->occupants->erase(this->occupants->begin()+index);
  wasRemoved= size== this->numberOfOccupants()+1;
  return wasRemoved;  
}

bool Shelter::addOccupant(Survivor* aNewOccupant){
  bool wasAdded= false;
  if (IndexOf(this->occupants->begin(), this->occupants->end(), aNewOccupant)> -1) {
    return wasAdded;
  }
  if (this->numberOfOccupants() >= this->maximumNumberOfOccupants()){
    return wasAdded;
  }
  Shelter* existingShelter = aNewOccupant->getShelter();
  bool isNewShelter= existingShelter != NULL && this!=existingShelter;
  if(isNewShelter){
    aNewOccupant->setShelter(this);
  }else{
    this->occupants->push_back(aNewOccupant);
  }
  wasAdded= true;
  return wasAdded;  
}

bool Shelter::addOccupantAt(Survivor* aNewOccupant, int index){
  bool wasAdded= false;
  if(addOccupant(aNewOccupant)){
      int newIndex= index;
      if(index < 0 ) { 
          newIndex = 0; 
      }
    
      int size= this->numberOfOccupants();
      if(size>0){
          this->occupants->erase(this->occupants->begin()+IndexOf(this->occupants->begin(), this->occupants->end(),aNewOccupant));    
      }
    
      size= this->numberOfOccupants();
      if(newIndex > size) { 
          newIndex = size; 
      }
    
     this->occupants->insert(this->occupants->begin()+ newIndex, aNewOccupant);
      wasAdded = true;
  }
  return wasAdded;  
}

bool Shelter::addOrMoveOccupantAt(Survivor* aNewOccupant, int index){
  bool wasAdded= false;
  if(IndexOf(this->occupants->begin(), this->occupants->end(), aNewOccupant) > -1) {
    if (index < 0) {
      index = 0;
    }
  
    int size= this->numberOfOccupants();
    if (index > size) {
      index = size - 1;
    }
    
    wasAdded= this->removeOccupant(aNewOccupant)| this->addOccupantAt(aNewOccupant, index);
  }else{
    wasAdded= this->addOccupantAt(aNewOccupant, index);
  }
  
  return wasAdded;  
}

Survivor* Shelter::addOccupant(const string aName, Facility* aFacility, LivingQuarters* aLivingQuarters, MedicalBay* aMedicalBay, Mission* aMission){
  if (this->numberOfOccupants() >= this->maximumNumberOfOccupants()){
    return NULL;
  }
  return new Survivor(aName, this, aFacility, aLivingQuarters, aMedicalBay, aMission);  
}

vector<Facility*>* Shelter::getFacilities(void){
  vector<Facility*>* copyOfFacilities = new vector<Facility*>();
  vector<Facility*>::iterator facilitiesBeginIterator(this->facilities->begin());
  vector<Facility*>::iterator facilitiesEndIterator(this->facilities->end());
  copyVector(facilitiesBeginIterator, facilitiesEndIterator, copyOfFacilities);
  return copyOfFacilities;  
}

Facility* Shelter::getFacility(int index){
  Facility* aFacility= (*(this->facilities))[index];
  return aFacility;  
}

unsigned int Shelter::numberOfFacilities(void){
  int number=this->facilities->size();
  return number;  
}

bool Shelter::hasFacility(void){
  return this->numberOfFacilities()>0;  
}

int Shelter::indexOfFacility(Facility* aFacility){
  return IndexOf(this->facilities->begin(), this->facilities->end(), aFacility);  
}

bool Shelter::removeFacility(Facility* aFacility){
  bool wasRemoved= false;
  int index= IndexOf(this->facilities->begin(), this->facilities->end(), aFacility);
  if(index<0){ 
    return wasRemoved;
  }
  //Unable to remove aFacility, as it must always have a Shelter
  if (this== aFacility->getShelter()){
      return wasRemoved;
  }
  wasRemoved= this->removeFacilityAt(index);
  return wasRemoved;  
}

bool Shelter::removeFacilityAt(int index){
  bool wasRemoved= false;
  if(index<0){
      return wasRemoved;
  }
  
  int size= this->numberOfFacilities();
  if(index> size){
      return false;
  }
  this->facilities->erase(this->facilities->begin()+index);
  wasRemoved= size== this->numberOfFacilities()+1;
  return wasRemoved;  
}

bool Shelter::addFacility(Facility* aNewFacility){
  bool wasAdded= false;
  if (IndexOf(this->facilities->begin(), this->facilities->end(), aNewFacility)> -1) {
    return wasAdded;
  }
  if (this->numberOfFacilities() >= this->maximumNumberOfFacilities()){
    return wasAdded;
  }
  Shelter* existingShelter = aNewFacility->getShelter();
  bool isNewShelter= existingShelter != NULL && this!=existingShelter;
  if(isNewShelter){
    aNewFacility->setShelter(this);
  }else{
    this->facilities->push_back(aNewFacility);
  }
  wasAdded= true;
  return wasAdded;  
}

bool Shelter::addFacilityAt(Facility* aNewFacility, int index){
  bool wasAdded= false;
  if(addFacility(aNewFacility)){
      int newIndex= index;
      if(index < 0 ) { 
          newIndex = 0; 
      }
    
      int size= this->numberOfFacilities();
      if(size>0){
          this->facilities->erase(this->facilities->begin()+IndexOf(this->facilities->begin(), this->facilities->end(),aNewFacility));    
      }
    
      size= this->numberOfFacilities();
      if(newIndex > size) { 
          newIndex = size; 
      }
    
     this->facilities->insert(this->facilities->begin()+ newIndex, aNewFacility);
      wasAdded = true;
  }
  return wasAdded;  
}

bool Shelter::addOrMoveFacilityAt(Facility* aNewFacility, int index){
  bool wasAdded= false;
  if(IndexOf(this->facilities->begin(), this->facilities->end(), aNewFacility) > -1) {
    if (index < 0) {
      index = 0;
    }
  
    int size= this->numberOfFacilities();
    if (index > size) {
      index = size - 1;
    }
    
    wasAdded= this->removeFacility(aNewFacility)| this->addFacilityAt(aNewFacility, index);
  }else{
    wasAdded= this->addFacilityAt(aNewFacility, index);
  }
  
  return wasAdded;  
}

Facility* Shelter::addFacility(const string aFacilityName, const int aCapacity, const int aLevel, double aCondition, const int aPowerConsumption){
  if (this->numberOfFacilities() >= this->maximumNumberOfFacilities()){
    return NULL;
  }
  return new Facility(aFacilityName, aCapacity, aLevel, aCondition, aPowerConsumption, this);  
}

vector<Mission*>* Shelter::getMissions(void){
  vector<Mission*>* copyOfMissions = new vector<Mission*>();
  vector<Mission*>::iterator missionsBeginIterator(this->missions->begin());
  vector<Mission*>::iterator missionsEndIterator(this->missions->end());
  copyVector(missionsBeginIterator, missionsEndIterator, copyOfMissions);
  return copyOfMissions;  
}

Mission* Shelter::getMission(int index){
  Mission* aMission= (*(this->missions))[index];
  return aMission;  
}

unsigned int Shelter::numberOfMissions(void){
  int number=this->missions->size();
  return number;  
}

bool Shelter::hasMission(void){
  return this->numberOfMissions()>0;  
}

int Shelter::indexOfMission(Mission* aMission){
  return IndexOf(this->missions->begin(), this->missions->end(), aMission);  
}

bool Shelter::removeMission(Mission* aMission){
  bool wasRemoved= false;
  int index= IndexOf(this->missions->begin(), this->missions->end(), aMission);
  if(index<0){ 
    return wasRemoved;
  }
  //Unable to remove aMission, as it must always have a Shelter
  if (this== aMission->getShelter()){
      return wasRemoved;
  }
  wasRemoved= this->removeMissionAt(index);
  return wasRemoved;  
}

bool Shelter::removeMissionAt(int index){
  bool wasRemoved= false;
  if(index<0){
      return wasRemoved;
  }
  
  int size= this->numberOfMissions();
  if(index> size){
      return false;
  }
  this->missions->erase(this->missions->begin()+index);
  wasRemoved= size== this->numberOfMissions()+1;
  return wasRemoved;  
}

bool Shelter::addMission(Mission* aNewMission){
  bool wasAdded= false;
  if (IndexOf(this->missions->begin(), this->missions->end(), aNewMission)> -1) {
    return wasAdded;
  }
  Shelter* existingShelter = aNewMission->getShelter();
  bool isNewShelter= existingShelter != NULL && this!=existingShelter;
  if(isNewShelter){
    aNewMission->setShelter(this);
  }else{
    this->missions->push_back(aNewMission);
  }
  wasAdded= true;
  return wasAdded;  
}

bool Shelter::addMissionAt(Mission* aNewMission, int index){
  bool wasAdded= false;
  if(addMission(aNewMission)){
      int newIndex= index;
      if(index < 0 ) { 
          newIndex = 0; 
      }
    
      int size= this->numberOfMissions();
      if(size>0){
          this->missions->erase(this->missions->begin()+IndexOf(this->missions->begin(), this->missions->end(),aNewMission));    
      }
    
      size= this->numberOfMissions();
      if(newIndex > size) { 
          newIndex = size; 
      }
    
     this->missions->insert(this->missions->begin()+ newIndex, aNewMission);
      wasAdded = true;
  }
  return wasAdded;  
}

bool Shelter::addOrMoveMissionAt(Mission* aNewMission, int index){
  bool wasAdded= false;
  if(IndexOf(this->missions->begin(), this->missions->end(), aNewMission) > -1) {
    if (index < 0) {
      index = 0;
    }
  
    int size= this->numberOfMissions();
    if (index > size) {
      index = size - 1;
    }
    
    wasAdded= this->removeMission(aNewMission)| this->addMissionAt(aNewMission, index);
  }else{
    wasAdded= this->addMissionAt(aNewMission, index);
  }
  
  return wasAdded;  
}

Mission* Shelter::addMission(const string aDescription, const int aDifficulty, const int aDuration){
  return new Mission(aDescription, aDifficulty, aDuration, this);  
}

RadiationMonitor* Shelter::getRadiationMonitor(void){
  return this->radiationMonitor;  
}

bool Shelter::radiationLevelUp(){
  bool wasEventProcessed= false;
  ShelterState aShelterState= shelterState;
    
  switch((int)aShelterState){	
  	case ShelterState::SH_Normal:
  		setShelterState(ShelterState::SH_Alert);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Shelter::detectThreat(){
  bool wasEventProcessed= false;
  ShelterState aShelterState= shelterState;
    
  switch((int)aShelterState){	
  	case ShelterState::SH_Normal:
  		setShelterState(ShelterState::SH_UnderAttack);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Shelter::energyDepleted(){
  bool wasEventProcessed= false;
  ShelterState aShelterState= shelterState;
    
  switch((int)aShelterState){	
  	case ShelterState::SH_Normal:
  		setShelterState(ShelterState::SH_PowerOutage);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Shelter::multipleResourcesCritical(){
  bool wasEventProcessed= false;
  ShelterState aShelterState= shelterState;
    
  switch((int)aShelterState){	
  	case ShelterState::SH_Normal:
  		setShelterState(ShelterState::SH_Crisis);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Shelter::radiationRecovered(){
  bool wasEventProcessed= false;
  ShelterState aShelterState= shelterState;
    
  switch((int)aShelterState){	
  	case ShelterState::SH_Alert:
  		setShelterState(ShelterState::SH_Normal);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Shelter::radiationDangerLevel(){
  bool wasEventProcessed= false;
  ShelterState aShelterState= shelterState;
    
  switch((int)aShelterState){	
  	case ShelterState::SH_Alert:
  		setShelterState(ShelterState::SH_Lockdown);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Shelter::intrusion(){
  bool wasEventProcessed= false;
  ShelterState aShelterState= shelterState;
    
  switch((int)aShelterState){	
  	case ShelterState::SH_Alert:
  		setShelterState(ShelterState::SH_UnderAttack);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Shelter::radiationDecreased(){
  bool wasEventProcessed= false;
  ShelterState aShelterState= shelterState;
    
  switch((int)aShelterState){	
  	case ShelterState::SH_Lockdown:
  		setShelterState(ShelterState::SH_Alert);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Shelter::fullyCleared(){
  bool wasEventProcessed= false;
  ShelterState aShelterState= shelterState;
    
  switch((int)aShelterState){	
  	case ShelterState::SH_Lockdown:
  		setShelterState(ShelterState::SH_Normal);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Shelter::threatRepelled(){
  bool wasEventProcessed= false;
  ShelterState aShelterState= shelterState;
    
  switch((int)aShelterState){	
  	case ShelterState::SH_UnderAttack:
  		setShelterState(ShelterState::SH_Normal);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Shelter::defenseFailed(){
  bool wasEventProcessed= false;
  ShelterState aShelterState= shelterState;
    
  switch((int)aShelterState){	
  	case ShelterState::SH_UnderAttack:
  		setShelterState(ShelterState::SH_Damaged);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Shelter::powerRestored(){
  bool wasEventProcessed= false;
  ShelterState aShelterState= shelterState;
    
  switch((int)aShelterState){	
  	case ShelterState::SH_PowerOutage:
  		setShelterState(ShelterState::SH_Normal);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Shelter::prolongedOutage(){
  bool wasEventProcessed= false;
  ShelterState aShelterState= shelterState;
    
  switch((int)aShelterState){	
  	case ShelterState::SH_PowerOutage:
  		setShelterState(ShelterState::SH_Crisis);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Shelter::repairComplete(){
  bool wasEventProcessed= false;
  ShelterState aShelterState= shelterState;
    
  switch((int)aShelterState){	
  	case ShelterState::SH_Damaged:
  		setShelterState(ShelterState::SH_Normal);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Shelter::cascadingDamage(){
  bool wasEventProcessed= false;
  ShelterState aShelterState= shelterState;
    
  switch((int)aShelterState){	
  	case ShelterState::SH_Damaged:
  		setShelterState(ShelterState::SH_Crisis);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Shelter::recovered(){
  bool wasEventProcessed= false;
  ShelterState aShelterState= shelterState;
    
  switch((int)aShelterState){	
  	case ShelterState::SH_Crisis:
  		setShelterState(ShelterState::SH_Normal);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Shelter::populationZero(){
  bool wasEventProcessed= false;
  ShelterState aShelterState= shelterState;
    
  switch((int)aShelterState){	
  	case ShelterState::SH_Crisis:
  		setShelterState(ShelterState::SH_Abandoned);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

string Shelter::getShelterStateFullName(void){
  string answer = shelterState;
  return answer;
    
}

ShelterState Shelter::getShelterState(void){
  return this->shelterState;  
}

void Shelter::setShelterState(ShelterState aShelterState){
  shelterState= aShelterState;
    
}

bool Shelter::exitShelterState(void){
  bool wasEventProcessed = false;
  
    
  switch((int)shelterState){	
  	case ShelterState::SH_Normal:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case ShelterState::SH_Alert:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case ShelterState::SH_Lockdown:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case ShelterState::SH_UnderAttack:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case ShelterState::SH_PowerOutage:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case ShelterState::SH_Damaged:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case ShelterState::SH_Crisis:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case ShelterState::SH_Abandoned:
  		wasEventProcessed= true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;
    
}

size_t Shelter::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
Shelter::~Shelter(){
  this->deleteAssociatedObjects();
  
  std::for_each(occupants->begin(), occupants->end(), /*std::default_delete<Survivor>*/ deleteElement());
  occupants->clear();
  delete occupants;
  
  std::for_each(facilities->begin(), facilities->end(), /*std::default_delete<Facility>*/ deleteElement());
  facilities->clear();
  delete facilities;
  
  std::for_each(missions->begin(), missions->end(), /*std::default_delete<Mission>*/ deleteElement());
  missions->clear();
  delete missions;
  delete radiationMonitor;  
}

void Shelter::deleteAssociatedObjects(void){
  for(unsigned int index = occupants->size(); index > 0 ; index--){
    Survivor* aSurvivor= (*(this->occupants))[index-1];
    aSurvivor->deleteAssociatedObjects();
  }
  for(unsigned int index = facilities->size(); index > 0 ; index--){
    Facility* aFacility= (*(this->facilities))[index-1];
    aFacility->deleteAssociatedObjects();
  }
  for(unsigned int index = missions->size(); index > 0 ; index--){
    Mission* aMission= (*(this->missions))[index-1];
    aMission->deleteAssociatedObjects();
  }
  if(this->radiationMonitor!= NULL){
    RadiationMonitor* existingRadiationMonitor= this->radiationMonitor;
    this->radiationMonitor= NULL;
    existingRadiationMonitor->deleteAssociatedObjects();
  }  
}
;

