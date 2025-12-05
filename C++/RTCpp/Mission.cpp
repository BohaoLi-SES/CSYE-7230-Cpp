//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__MISSION_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <Mission.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Mission.h>
#include <Survivor.h>
#include <Shelter.h>
#include <Facility.h>
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
Mission::Mission(const string aDescription, const int aDifficulty, const int aDuration, Shelter* aShelter):
		shelter(NULL){
  this->description= aDescription;
  this->difficulty= aDifficulty;
  this->duration= aDuration;
  this->team= new vector<Survivor*>();
  if (!setShelter(aShelter)){
    throw "Unable to create Mission due to aShelter";
  }
  this->survivors= new vector<Survivor*>();
  if(!(difficulty >= 1 && difficulty <= 10 && duration > 0)){  
    throw "Please provide valid difficulty and duration";
  }
  setMissionState(MissionState::MS_Created);
  setMS_InProgress(MissionStateMS_InProgress::NIL);
  setInProgressState(MissionStateMS_InProgressInProgressState::NIL);  
}

Mission::Mission(Mission& other):
		shelter(NULL){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void Mission::toOstream(ostream& os) const{
  Mission* thisptr = const_cast<Mission*>(this);
  os << "[" << "description:" << thisptr->getDescription()<< ", " <<
      "difficulty:" << thisptr->getDifficulty()<< ", " <<
      "duration:" << thisptr->getDuration() << "]" << endl;
  (thisptr->getTeams()!= NULL ?  os << "team:" << thisptr->getTeams() : os << "team:" << "NULL")<< endl;
      (thisptr->getShelter()!= NULL ?  os << "shelter:" << thisptr->getShelter() : os << "shelter:" << "NULL")<< endl;
      (thisptr->getSurvivors()!= NULL ?  os << "survivors:" << thisptr->getSurvivors() : os << "survivors:" << "NULL");  
}

ostream& operator<<(ostream& os, const Mission& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (Mission& Right, Mission& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.description.compare(Left.description) != 0){
     return false;
  }
  if(Right.difficulty!= Left.difficulty){
     return false;
  }
  if(Right.duration!= Left.duration){
     return false;
  }
  if(!std::equal(Right.team->begin(), Right.team->end(), Left.team->begin())){
     return false;
  }
  if(!compare(Right.shelter, Left.shelter, sizeof Right.shelter)){
    return false;
  }
  if(!std::equal(Right.survivors->begin(), Right.survivors->end(), Left.survivors->begin())){
     return false;
  }  
}

Mission& Mission::operator=(Mission& other){
  internalCopy(other);
  return *this;  
}

void Mission::internalCopy(Mission& other){
  this->description.assign(other.description);
  this->difficulty= other.difficulty;
  this->duration= other.duration;
  this->team = new vector<Survivor*>();
  vector<Survivor*>::iterator teamBeginIterator(other.team->begin());
  vector<Survivor*>::iterator teamEndIterator(other.team->end());
  copyVector(teamBeginIterator, teamEndIterator, this->team);
  copyObject(other.shelter, this->shelter, sizeof other.shelter);
  this->survivors = new vector<Survivor*>();
  vector<Survivor*>::iterator survivorsBeginIterator(other.survivors->begin());
  vector<Survivor*>::iterator survivorsEndIterator(other.survivors->end());
  copyVector(survivorsBeginIterator, survivorsEndIterator, this->survivors);  
}

bool Mission::setDescription(const string aNewDescription){
  bool wasSet= false;
  this->description = aNewDescription;
  wasSet= true;
  return wasSet;  
}

bool Mission::setDifficulty(const int aNewDifficulty){
  bool wasSet= false;
  if(difficulty >= 1){  
    this->difficulty = aNewDifficulty;
    wasSet= true;
  }
  return wasSet;  
}

bool Mission::setDuration(const int aNewDuration){
  bool wasSet= false;
  if(duration > 0){  
    this->duration = aNewDuration;
    wasSet= true;
  }
  return wasSet;  
}

bool Mission::setShelter(Shelter* aNewShelter){
  bool wasSet= false;
  if (aNewShelter == NULL){
    return wasSet;
  }
  
  Shelter* existingShelter = this->shelter;
  this->shelter = aNewShelter;
  
  if (existingShelter != NULL && existingShelter != aNewShelter){
      existingShelter->removeMission(this);
  }
  this->shelter->addMission(this);
  wasSet = true;
  return wasSet;  
}

string Mission::getDescription(void){
  return this->description;  
}

int Mission::getDifficulty(void){
  return this->difficulty;  
}

int Mission::getDuration(void){
  return this->duration;  
}

vector<Survivor*>* Mission::getTeams(void){
  vector<Survivor*>* copyOfTeams = new vector<Survivor*>();
  vector<Survivor*>::iterator teamBeginIterator(this->team->begin());
  vector<Survivor*>::iterator teamEndIterator(this->team->end());
  copyVector(teamBeginIterator, teamEndIterator, copyOfTeams);
  return copyOfTeams;  
}

Survivor* Mission::getTeam(int index){
  Survivor* aTeam= (*(this->team))[index];
  return aTeam;  
}

unsigned int Mission::numberOfTeams(void){
  int number=this->team->size();
  return number;  
}

bool Mission::hasTeam(void){
  return this->numberOfTeams()>0;  
}

int Mission::indexOfTeam(Survivor* aTeam){
  return IndexOf(this->team->begin(), this->team->end(), aTeam);  
}

bool Mission::removeTeam(Survivor* aTeam){
  bool wasRemoved= false;
  int index= IndexOf(this->team->begin(), this->team->end(), aTeam);
  if(index<0){ 
    return wasRemoved;
  }
  //Unable to remove aTeam, as it must always have a Mission
  if (this== aTeam->getMission()){
      return wasRemoved;
  }
  wasRemoved= this->removeTeamAt(index);
  return wasRemoved;  
}

bool Mission::removeTeamAt(int index){
  bool wasRemoved= false;
  if(index<0){
      return wasRemoved;
  }
  
  int size= this->numberOfTeams();
  if(index> size){
      return false;
  }
  this->team->erase(this->team->begin()+index);
  wasRemoved= size== this->numberOfTeams()+1;
  return wasRemoved;  
}

bool Mission::addTeam(Survivor* aNewTeam){
  bool wasAdded= false;
  if (IndexOf(this->team->begin(), this->team->end(), aNewTeam)> -1) {
    return wasAdded;
  }
  Mission* existingMission = aNewTeam->getMission();
  bool isNewMission= existingMission != NULL && this!=existingMission;
  if(isNewMission){
    aNewTeam->setMission(this);
  }else{
    this->team->push_back(aNewTeam);
  }
  wasAdded= true;
  return wasAdded;  
}

bool Mission::addTeamAt(Survivor* aNewTeam, int index){
  bool wasAdded= false;
  if(addTeam(aNewTeam)){
      int newIndex= index;
      if(index < 0 ) { 
          newIndex = 0; 
      }
    
      int size= this->numberOfTeams();
      if(size>0){
          this->team->erase(this->team->begin()+IndexOf(this->team->begin(), this->team->end(),aNewTeam));    
      }
    
      size= this->numberOfTeams();
      if(newIndex > size) { 
          newIndex = size; 
      }
    
     this->team->insert(this->team->begin()+ newIndex, aNewTeam);
      wasAdded = true;
  }
  return wasAdded;  
}

bool Mission::addOrMoveTeamAt(Survivor* aNewTeam, int index){
  bool wasAdded= false;
  if(IndexOf(this->team->begin(), this->team->end(), aNewTeam) > -1) {
    if (index < 0) {
      index = 0;
    }
  
    int size= this->numberOfTeams();
    if (index > size) {
      index = size - 1;
    }
    
    wasAdded= this->removeTeam(aNewTeam)| this->addTeamAt(aNewTeam, index);
  }else{
    wasAdded= this->addTeamAt(aNewTeam, index);
  }
  
  return wasAdded;  
}

Survivor* Mission::addTeam(const string aName, Shelter* aShelter, Facility* aFacility, LivingQuarters* aLivingQuarters, MedicalBay* aMedicalBay){
  return new Survivor(aName, aShelter, aFacility, aLivingQuarters, aMedicalBay, this);  
}

Shelter* Mission::getShelter(void){
  return this->shelter;  
}

vector<Survivor*>* Mission::getSurvivors(void){
  vector<Survivor*>* copyOfSurvivors = new vector<Survivor*>();
  vector<Survivor*>::iterator survivorsBeginIterator(this->survivors->begin());
  vector<Survivor*>::iterator survivorsEndIterator(this->survivors->end());
  copyVector(survivorsBeginIterator, survivorsEndIterator, copyOfSurvivors);
  return copyOfSurvivors;  
}

Survivor* Mission::getSurvivor(int index){
  Survivor* aSurvivor= (*(this->survivors))[index];
  return aSurvivor;  
}

unsigned int Mission::numberOfSurvivors(void){
  int number=this->survivors->size();
  return number;  
}

bool Mission::hasSurvivor(void){
  return this->numberOfSurvivors()>0;  
}

int Mission::indexOfSurvivor(Survivor* aSurvivor){
  return IndexOf(this->survivors->begin(), this->survivors->end(), aSurvivor);  
}

bool Mission::removeSurvivor(Survivor* aSurvivor){
  bool wasRemoved= false;
  int index= IndexOf(this->survivors->begin(), this->survivors->end(), aSurvivor);
  if(index<0){ 
    return wasRemoved;
  }
  wasRemoved= this->removeSurvivorAt(index);
  if (aSurvivor->indexOfAssignedMission(this) == -1){
    wasRemoved = true;
  }else{
    wasRemoved = aSurvivor->removeAssignedMission(this);
    if (!wasRemoved){
      this->survivors->insert(this->survivors->begin()+ index, aSurvivor);
    }
  }
  return wasRemoved;  
}

bool Mission::removeSurvivorAt(int index){
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

bool Mission::addSurvivor(Survivor* aNewSurvivor){
  bool wasAdded= false;
  if (IndexOf(this->survivors->begin(), this->survivors->end(), aNewSurvivor)> -1) {
    return wasAdded;
  }
  this->survivors->push_back(aNewSurvivor);
  if (aNewSurvivor->indexOfAssignedMission(this)!= -1) {
    wasAdded = true;
  }else{
    wasAdded = aNewSurvivor->addAssignedMission(this);
    if(!wasAdded){
      int currentIndex= this->indexOfSurvivor(aNewSurvivor);
      this->survivors->erase(this->survivors->begin()+currentIndex);
    }
  }
  return wasAdded;  
}

bool Mission::addSurvivorAt(Survivor* aNewSurvivor, int index){
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

bool Mission::addOrMoveSurvivorAt(Survivor* aNewSurvivor, int index){
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

bool Mission::assignSurvivor(){
  bool wasEventProcessed= false;
  MissionState aMissionState= missionState;
    
  switch((int)aMissionState){	
  	case MissionState::MS_Created:
  		setMissionState(MissionState::MS_Preparing);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Mission::abortOrInsufficientResources(){
  bool wasEventProcessed= false;
  MissionState aMissionState= missionState;
    
  switch((int)aMissionState){	
  	case MissionState::MS_Created:
  		setMissionState(MissionState::MS_Cancelled);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Mission::validateTeamSuccess(){
  bool wasEventProcessed= false;
  MissionState aMissionState= missionState;
    
  switch((int)aMissionState){	
  	case MissionState::MS_Preparing:
  		setMissionState(MissionState::MS_Ready);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Mission::removeMember(){
  bool wasEventProcessed= false;
  MissionState aMissionState= missionState;
    
  switch((int)aMissionState){	
  	case MissionState::MS_Preparing:
  		setMissionState(MissionState::MS_Created);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Mission::start(){
  bool wasEventProcessed= false;
  MissionState aMissionState= missionState;
    
  switch((int)aMissionState){	
  	case MissionState::MS_Ready:
  		setMissionState(MissionState::MS_InProgress);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Mission::abort(){
  bool wasEventProcessed= false;
  MissionState aMissionState= missionState;
    
  switch((int)aMissionState){	
  	case MissionState::MS_Ready:
  		setMissionState(MissionState::MS_Cancelled);
  		wasEventProcessed = true;
  	    break;
  	
  	
  	case MissionState::MS_InProgress:
  		exitMissionState();
  		
  		setMissionState(MissionState::MS_Aborted);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Mission::success(){
  bool wasEventProcessed= false;
  MissionState aMissionState= missionState;
    
  switch((int)aMissionState){	
  	case MissionState::MS_InProgress:
  		exitMissionState();
  		
  		setMissionState(MissionState::MS_Completed);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Mission::teamWipedOrTimeout(){
  bool wasEventProcessed= false;
  MissionState aMissionState= missionState;
    
  switch((int)aMissionState){	
  	case MissionState::MS_InProgress:
  		exitMissionState();
  		
  		setMissionState(MissionState::MS_Failed);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Mission::reachDestination(){
  bool wasEventProcessed= false;
  MissionStateMS_InProgressInProgressState aMissionStateMS_InProgressInProgressState= missionStateMS_InProgressInProgressState;
    
  switch((int)aMissionStateMS_InProgressInProgressState){	
  	case MissionStateMS_InProgressInProgressState::IP_Traveling:
  		setMissionStateMS_InProgressInProgressState(MissionStateMS_InProgressInProgressState::IP_Executing);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Mission::abortOrDanger(){
  bool wasEventProcessed= false;
  MissionStateMS_InProgressInProgressState aMissionStateMS_InProgressInProgressState= missionStateMS_InProgressInProgressState;
    
  switch((int)aMissionStateMS_InProgressInProgressState){	
  	case MissionStateMS_InProgressInProgressState::IP_Traveling:
  		setMissionStateMS_InProgressInProgressState(MissionStateMS_InProgressInProgressState::IP_Returning);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Mission::executionComplete(){
  bool wasEventProcessed= false;
  MissionStateMS_InProgressInProgressState aMissionStateMS_InProgressInProgressState= missionStateMS_InProgressInProgressState;
    
  switch((int)aMissionStateMS_InProgressInProgressState){	
  	case MissionStateMS_InProgressInProgressState::IP_Executing:
  		setMissionStateMS_InProgressInProgressState(MissionStateMS_InProgressInProgressState::IP_Returning);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Mission::arriveHome(){
  bool wasEventProcessed= false;
  MissionStateMS_InProgressInProgressState aMissionStateMS_InProgressInProgressState= missionStateMS_InProgressInProgressState;
    
  switch((int)aMissionStateMS_InProgressInProgressState){	
  	case MissionStateMS_InProgressInProgressState::IP_Returning:
  		setMissionStateMS_InProgressInProgressState(MissionStateMS_InProgressInProgressState::IP_Complete);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

bool Mission::exitMS_InProgress(void){
  bool wasEventProcessed= false;
  MissionStateMS_InProgress aMissionStateMS_InProgress= missionStateMS_InProgress;
  MissionStateMS_InProgressInProgressState aMissionStateMS_InProgressInProgressState= missionStateMS_InProgressInProgressState;
    
  switch((int)aMissionStateMS_InProgress){	
  	case MissionStateMS_InProgress::inProgressState:
  		
  		setMissionStateMS_InProgress(MissionStateMS_InProgress::NIL);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
    
  switch((int)aMissionStateMS_InProgressInProgressState){	
  	case MissionStateMS_InProgressInProgressState::IP_Traveling:
  		
  		setMissionStateMS_InProgressInProgressState(MissionStateMS_InProgressInProgressState::NIL);
  		wasEventProcessed = true;
  	    break;
  	
  	
  	case MissionStateMS_InProgressInProgressState::IP_Executing:
  		
  		setMissionStateMS_InProgressInProgressState(MissionStateMS_InProgressInProgressState::NIL);
  		wasEventProcessed = true;
  	    break;
  	
  	
  	case MissionStateMS_InProgressInProgressState::IP_Returning:
  		
  		setMissionStateMS_InProgressInProgressState(MissionStateMS_InProgressInProgressState::NIL);
  		wasEventProcessed = true;
  	    break;
  	
  	
  	case MissionStateMS_InProgressInProgressState::IP_Complete:
  		
  		setMissionStateMS_InProgressInProgressState(MissionStateMS_InProgressInProgressState::NIL);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;  
}

string Mission::getMissionStateFullName(void){
  string answer = missionState;
  
  if (missionStateMS_InProgress != MissionStateMS_InProgress::NIL) { 
  answer += "." + missionStateMS_InProgress; 
  }
  
  
  if (missionStateMS_InProgressInProgressState != MissionStateMS_InProgressInProgressState::NIL) { 
  answer += "." + missionStateMS_InProgressInProgressState; 
  }
  
  return answer;
    
}

MissionState Mission::getMissionState(void){
  return this->missionState;  
}

MissionStateMS_InProgress Mission::getMS_InProgress(void){
  return this->missionStateMS_InProgress;  
}

MissionStateMS_InProgressInProgressState Mission::getInProgressState(void){
  return this->missionStateMS_InProgressInProgressState;  
}

void Mission::setMissionState(MissionState aMissionState){
  missionState= aMissionState;
  
  // entry actions and do activities  
  switch((int)missionState){	
  	case MissionState::MS_InProgress:
  		{
  			if(missionStateMS_InProgress== MissionStateMS_InProgress::NIL){
  			setMissionStateMS_InProgress(MissionStateMS_InProgress::inProgressState);
  			}
  		}
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
    
}

void Mission::setMS_InProgress(MissionStateMS_InProgress aMS_InProgress){
  mS_InProgress= aMS_InProgress;
  if(missionState != MissionState::MS_InProgress && aMS_InProgress != MissionStateMS_InProgress::NIL){	
  	setMissionState(MissionState::MS_InProgress);
  }
  
  // entry actions and do activities  
  switch((int)missionStateMS_InProgress){	
  	case MissionStateMS_InProgress::inProgressState:
  		{
  			if(missionStateMS_InProgressInProgressState== MissionStateMS_InProgressInProgressState::NIL){
  			setMissionStateMS_InProgressInProgressState(MissionStateMS_InProgressInProgressState::IP_Traveling);
  			}
  		}
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
    
}

void Mission::setInProgressState(MissionStateMS_InProgressInProgressState aInProgressState){
  inProgressState= aInProgressState;
  if(missionStateMS_InProgress != MissionStateMS_InProgress::inProgressState && aInProgressState != MissionStateMS_InProgressInProgressState::NIL){	
  	setMissionStateMS_InProgress(MissionStateMS_InProgress::inProgressState);
  }
    
}

bool Mission::exitMissionState(void){
  bool wasEventProcessed = false;
  
    
  switch((int)missionState){	
  	case MissionState::MS_Created:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case MissionState::MS_Preparing:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case MissionState::MS_Ready:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case MissionState::MS_InProgress:
  		wasEventProcessed= exitMS_InProgress();
  	    break;
  	
  	
  	case MissionState::MS_Completed:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case MissionState::MS_Failed:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case MissionState::MS_Aborted:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case MissionState::MS_Cancelled:
  		wasEventProcessed= true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;
    
}

bool Mission::exitMissionStateMS_InProgress(void){
  bool wasEventProcessed = false;
  
    
  switch((int)missionStateMS_InProgress){	
  	case MS_InProgress::inProgressState:
  		wasEventProcessed= exitMS_InProgress();
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;
    
}

bool Mission::exitMissionStateMS_InProgressInProgressState(void){
  bool wasEventProcessed = false;
  
    
  switch((int)missionStateMS_InProgressInProgressState){	
  	case InProgressState::IP_Traveling:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case InProgressState::IP_Executing:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case InProgressState::IP_Returning:
  		wasEventProcessed= true;
  	    break;
  	
  	
  	case InProgressState::IP_Complete:
  		wasEventProcessed= true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;
    
}

bool Mission::enterMS_InProgress(void){
  bool wasEventProcessed = false;
  MissionStateMS_InProgress aMissionStateMS_InProgress= missionStateMS_InProgress;
  MissionStateMS_InProgressInProgressState aMissionStateMS_InProgressInProgressState= missionStateMS_InProgressInProgressState;  
  switch((int)aMissionStateMS_InProgress){	
  	case MissionStateMS_InProgress::NIL:
  		
  		setMissionStateMS_InProgress(MissionStateMS_InProgress::inProgressState);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
    
  switch((int)aMissionStateMS_InProgressInProgressState){	
  	case MissionStateMS_InProgressInProgressState::NIL:
  		
  		setMissionStateMS_InProgressInProgressState(MissionStateMS_InProgressInProgressState::IP_Traveling);
  		wasEventProcessed = true;
  	    break;
  
      default:
          // Other states do respond to this event
          break;
  }
  
  
  return wasEventProcessed;
    
}

size_t Mission::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
Mission::~Mission(){
  this->deleteAssociatedObjects();
  
  std::for_each(team->begin(), team->end(), /*std::default_delete<Survivor>*/ deleteElement());
  team->clear();
  delete team;
  delete shelter;
  
  std::for_each(survivors->begin(), survivors->end(), /*std::default_delete<Survivor>*/ deleteElement());
  survivors->clear();
  delete survivors;  
}

void Mission::deleteAssociatedObjects(void){
  for(unsigned int index = team->size(); index > 0 ; index--){
    Survivor* aSurvivor= (*(this->team))[index-1];
    aSurvivor->deleteAssociatedObjects();
  }
  Shelter* placeholderShelter = this->shelter;
  this->shelter = NULL;
  placeholderShelter->removeMission(this);
  vector<Survivor*>* copyOfSurvivors = new vector<Survivor*>();
  vector<Survivor*>::iterator survivorsBeginIterator(this->survivors->begin());
  vector<Survivor*>::iterator survivorsEndIterator(this->survivors->end());
  copyVector(survivorsBeginIterator, survivorsEndIterator, copyOfSurvivors);
  this->survivors->clear();
  
  while(this->survivors->size()>0){
    Survivor* aSurvivor= (*(copyOfSurvivors))[0];
    aSurvivor->removeAssignedMission(this);
  }  
}
;

