//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__DEFENSEPOST_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <DefensePost.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <DefensePost.h>
#include <Facility.h>
#include <Soldier.h>
#include <Shelter.h>
#include <LivingQuarters.h>
#include <MedicalBay.h>
#include <Mission.h>
#include <Weapon.h>
#include <SupplyBay.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>
#include <vector>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
DefensePost::DefensePost(const string aFacilityName, const int aCapacity, const int aLevel, const double aCondition, const int aPowerConsumption, Shelter* aShelter, const int aDefenseRating):Facility(aFacilityName, aCapacity, aLevel, aCondition, aPowerConsumption, aShelter){
  this->defenseRating= aDefenseRating;
  this->guards= new vector<Soldier*>();
  this->weapons= new vector<Weapon*>();
  if(!(defenseRating >= 0)){  
    throw "Please provide a valid defenseRating";
  }  
}

DefensePost::DefensePost(DefensePost& other):Facility(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void DefensePost::toOstream(ostream& os) const{
  Facility::toOstream(os);
  DefensePost* thisptr = const_cast<DefensePost*>(this);
  os << "[" << "defenseRating:" << thisptr->getDefenseRating() << "]" << endl;
  (thisptr->getGuards()!= NULL ?  os << "guards:" << thisptr->getGuards() : os << "guards:" << "NULL")<< endl;
      (thisptr->getWeapons()!= NULL ?  os << "weapons:" << thisptr->getWeapons() : os << "weapons:" << "NULL");  
}

ostream& operator<<(ostream& os, const DefensePost& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (DefensePost& Right, DefensePost& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.defenseRating!= Left.defenseRating){
     return false;
  }
  if(!std::equal(Right.guards->begin(), Right.guards->end(), Left.guards->begin())){
     return false;
  }
  if(!std::equal(Right.weapons->begin(), Right.weapons->end(), Left.weapons->begin())){
     return false;
  }  
}

DefensePost& DefensePost::operator=(DefensePost& other){
  internalCopy(other);
  return *this;  
}

void DefensePost::internalCopy(DefensePost& other){
  this->defenseRating= other.defenseRating;
  this->guards = new vector<Soldier*>();
  vector<Soldier*>::iterator guardsBeginIterator(other.guards->begin());
  vector<Soldier*>::iterator guardsEndIterator(other.guards->end());
  copyVector(guardsBeginIterator, guardsEndIterator, this->guards);
  this->weapons = new vector<Weapon*>();
  vector<Weapon*>::iterator weaponsBeginIterator(other.weapons->begin());
  vector<Weapon*>::iterator weaponsEndIterator(other.weapons->end());
  copyVector(weaponsBeginIterator, weaponsEndIterator, this->weapons);  
}

bool DefensePost::setDefenseRating(const int aNewDefenseRating){
  bool wasSet= false;
  if(defenseRating >= 0){  
    this->defenseRating = aNewDefenseRating;
    wasSet= true;
  }
  return wasSet;  
}

int DefensePost::getDefenseRating(void){
  return this->defenseRating;  
}

vector<Soldier*>* DefensePost::getGuards(void){
  vector<Soldier*>* copyOfGuards = new vector<Soldier*>();
  vector<Soldier*>::iterator guardsBeginIterator(this->guards->begin());
  vector<Soldier*>::iterator guardsEndIterator(this->guards->end());
  copyVector(guardsBeginIterator, guardsEndIterator, copyOfGuards);
  return copyOfGuards;  
}

Soldier* DefensePost::getGuard(int index){
  Soldier* aGuard= (*(this->guards))[index];
  return aGuard;  
}

unsigned int DefensePost::numberOfGuards(void){
  int number=this->guards->size();
  return number;  
}

bool DefensePost::hasGuard(void){
  return this->numberOfGuards()>0;  
}

int DefensePost::indexOfGuard(Soldier* aGuard){
  return IndexOf(this->guards->begin(), this->guards->end(), aGuard);  
}

bool DefensePost::removeGuard(Soldier* aGuard){
  bool wasRemoved= false;
  int index= IndexOf(this->guards->begin(), this->guards->end(), aGuard);
  if(index<0){ 
    return wasRemoved;
  }
  //Unable to remove aGuard, as it must always have a DefensePost
  if (this== aGuard->getDefensePost()){
      return wasRemoved;
  }
  wasRemoved= this->removeGuardAt(index);
  return wasRemoved;  
}

bool DefensePost::removeGuardAt(int index){
  bool wasRemoved= false;
  if(index<0){
      return wasRemoved;
  }
  
  int size= this->numberOfGuards();
  if(index> size){
      return false;
  }
  this->guards->erase(this->guards->begin()+index);
  wasRemoved= size== this->numberOfGuards()+1;
  return wasRemoved;  
}

bool DefensePost::addGuard(Soldier* aNewGuard){
  bool wasAdded= false;
  if (IndexOf(this->guards->begin(), this->guards->end(), aNewGuard)> -1) {
    return wasAdded;
  }
  if (this->numberOfGuards() >= this->maximumNumberOfGuards()){
    return wasAdded;
  }
  DefensePost* existingDefensePost = aNewGuard->getDefensePost();
  bool isNewDefensePost= existingDefensePost != NULL && this!=existingDefensePost;
  if(isNewDefensePost){
    aNewGuard->setDefensePost(this);
  }else{
    this->guards->push_back(aNewGuard);
  }
  wasAdded= true;
  return wasAdded;  
}

bool DefensePost::addGuardAt(Soldier* aNewGuard, int index){
  bool wasAdded= false;
  if(addGuard(aNewGuard)){
      int newIndex= index;
      if(index < 0 ) { 
          newIndex = 0; 
      }
    
      int size= this->numberOfGuards();
      if(size>0){
          this->guards->erase(this->guards->begin()+IndexOf(this->guards->begin(), this->guards->end(),aNewGuard));    
      }
    
      size= this->numberOfGuards();
      if(newIndex > size) { 
          newIndex = size; 
      }
    
     this->guards->insert(this->guards->begin()+ newIndex, aNewGuard);
      wasAdded = true;
  }
  return wasAdded;  
}

bool DefensePost::addOrMoveGuardAt(Soldier* aNewGuard, int index){
  bool wasAdded= false;
  if(IndexOf(this->guards->begin(), this->guards->end(), aNewGuard) > -1) {
    if (index < 0) {
      index = 0;
    }
  
    int size= this->numberOfGuards();
    if (index > size) {
      index = size - 1;
    }
    
    wasAdded= this->removeGuard(aNewGuard)| this->addGuardAt(aNewGuard, index);
  }else{
    wasAdded= this->addGuardAt(aNewGuard, index);
  }
  
  return wasAdded;  
}

Soldier* DefensePost::addGuard(const string aName, Shelter* aShelter, Facility* aFacility, LivingQuarters* aLivingQuarters, MedicalBay* aMedicalBay, Mission* aMission, const int aCombatSkill){
  if (this->numberOfGuards() >= this->maximumNumberOfGuards()){
    return NULL;
  }
  return new Soldier(aName, aShelter, aFacility, aLivingQuarters, aMedicalBay, aMission, aCombatSkill, this);  
}

vector<Weapon*>* DefensePost::getWeapons(void){
  vector<Weapon*>* copyOfWeapons = new vector<Weapon*>();
  vector<Weapon*>::iterator weaponsBeginIterator(this->weapons->begin());
  vector<Weapon*>::iterator weaponsEndIterator(this->weapons->end());
  copyVector(weaponsBeginIterator, weaponsEndIterator, copyOfWeapons);
  return copyOfWeapons;  
}

Weapon* DefensePost::getWeapon(int index){
  Weapon* aWeapon= (*(this->weapons))[index];
  return aWeapon;  
}

unsigned int DefensePost::numberOfWeapons(void){
  int number=this->weapons->size();
  return number;  
}

bool DefensePost::hasWeapon(void){
  return this->numberOfWeapons()>0;  
}

int DefensePost::indexOfWeapon(Weapon* aWeapon){
  return IndexOf(this->weapons->begin(), this->weapons->end(), aWeapon);  
}

bool DefensePost::removeWeapon(Weapon* aWeapon){
  bool wasRemoved= false;
  int index= IndexOf(this->weapons->begin(), this->weapons->end(), aWeapon);
  if(index<0){ 
    return wasRemoved;
  }
  //Unable to remove aWeapon, as it must always have a DefensePost
  if (this== aWeapon->getDefensePost()){
      return wasRemoved;
  }
  wasRemoved= this->removeWeaponAt(index);
  return wasRemoved;  
}

bool DefensePost::removeWeaponAt(int index){
  bool wasRemoved= false;
  if(index<0){
      return wasRemoved;
  }
  
  int size= this->numberOfWeapons();
  if(index> size){
      return false;
  }
  this->weapons->erase(this->weapons->begin()+index);
  wasRemoved= size== this->numberOfWeapons()+1;
  return wasRemoved;  
}

bool DefensePost::addWeapon(Weapon* aNewWeapon){
  bool wasAdded= false;
  if (IndexOf(this->weapons->begin(), this->weapons->end(), aNewWeapon)> -1) {
    return wasAdded;
  }
  DefensePost* existingDefensePost = aNewWeapon->getDefensePost();
  bool isNewDefensePost= existingDefensePost != NULL && this!=existingDefensePost;
  if(isNewDefensePost){
    aNewWeapon->setDefensePost(this);
  }else{
    this->weapons->push_back(aNewWeapon);
  }
  wasAdded= true;
  return wasAdded;  
}

bool DefensePost::addWeaponAt(Weapon* aNewWeapon, int index){
  bool wasAdded= false;
  if(addWeapon(aNewWeapon)){
      int newIndex= index;
      if(index < 0 ) { 
          newIndex = 0; 
      }
    
      int size= this->numberOfWeapons();
      if(size>0){
          this->weapons->erase(this->weapons->begin()+IndexOf(this->weapons->begin(), this->weapons->end(),aNewWeapon));    
      }
    
      size= this->numberOfWeapons();
      if(newIndex > size) { 
          newIndex = size; 
      }
    
     this->weapons->insert(this->weapons->begin()+ newIndex, aNewWeapon);
      wasAdded = true;
  }
  return wasAdded;  
}

bool DefensePost::addOrMoveWeaponAt(Weapon* aNewWeapon, int index){
  bool wasAdded= false;
  if(IndexOf(this->weapons->begin(), this->weapons->end(), aNewWeapon) > -1) {
    if (index < 0) {
      index = 0;
    }
  
    int size= this->numberOfWeapons();
    if (index > size) {
      index = size - 1;
    }
    
    wasAdded= this->removeWeapon(aNewWeapon)| this->addWeaponAt(aNewWeapon, index);
  }else{
    wasAdded= this->addWeaponAt(aNewWeapon, index);
  }
  
  return wasAdded;  
}

Weapon* DefensePost::addWeapon(const string aResourceId, const int aQuantity, const int aMaxCapacity, const string aUnit, SupplyBay* aSupplyBay, const int aDamageValue, const int aAmmunition, const int aMaxAmmunition){
  return new Weapon(aResourceId, aQuantity, aMaxCapacity, aUnit, aSupplyBay, aDamageValue, aAmmunition, aMaxAmmunition, this);  
}

size_t DefensePost::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
DefensePost::~DefensePost(){
  //Facility::~Facility();
  this->deleteAssociatedObjects();
  
  std::for_each(guards->begin(), guards->end(), /*std::default_delete<Soldier>*/ deleteElement());
  guards->clear();
  delete guards;
  
  std::for_each(weapons->begin(), weapons->end(), /*std::default_delete<Weapon>*/ deleteElement());
  weapons->clear();
  delete weapons;  
}

void DefensePost::deleteAssociatedObjects(void){
  for(unsigned int index = guards->size(); index > 0 ; index--){
    Soldier* aSoldier= (*(this->guards))[index-1];
    aSoldier->deleteAssociatedObjects();
  }
  for(unsigned int index = weapons->size(); index > 0 ; index--){
    Weapon* aWeapon= (*(this->weapons))[index-1];
    aWeapon->deleteAssociatedObjects();
  }  
}
;

