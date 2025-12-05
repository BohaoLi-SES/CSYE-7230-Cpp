//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__WEAPON_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <Weapon.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Weapon.h>
#include <Resource.h>
#include <Soldier.h>
#include <DefensePost.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
Weapon::Weapon(const string aResourceId, const int aQuantity, const int aMaxCapacity, const string aUnit, SupplyBay* aSupplyBay, const int aDamageValue, const int aAmmunition, const int aMaxAmmunition, DefensePost* aDefensePost):
		soldier(NULL),
		defensePost(NULL),
    Resource(aResourceId, aQuantity, aMaxCapacity, aUnit, aSupplyBay){
  this->damageValue= aDamageValue;
  this->ammunition= aAmmunition;
  this->maxAmmunition= aMaxAmmunition;
  this->soldier= NULL;
  if (!setDefensePost(aDefensePost)){
    throw "Unable to create Weapon due to aDefensePost";
  }
  if(!(damageValue > 0 && ammunition >= 0 && ammunition <= maxAmmunition && maxAmmunition > 0)){  
    throw "Please provide valid damageValue, ammunition, and maxAmmunition";
  }  
}

Weapon::Weapon(Weapon& other):
		soldier(NULL),
		defensePost(NULL),
    Resource(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void Weapon::toOstream(ostream& os) const{
  Resource::toOstream(os);
  Weapon* thisptr = const_cast<Weapon*>(this);
  os << "[" << "damageValue:" << thisptr->getDamageValue()<< ", " <<
      "ammunition:" << thisptr->getAmmunition()<< ", " <<
      "maxAmmunition:" << thisptr->getMaxAmmunition() << "]" << endl;
  (thisptr->getSoldier()!= NULL ?  os << "soldier:" << thisptr->getSoldier() : os << "soldier:" << "NULL")<< endl;
      (thisptr->getDefensePost()!= NULL ?  os << "defensePost:" << thisptr->getDefensePost() : os << "defensePost:" << "NULL");  
}

ostream& operator<<(ostream& os, const Weapon& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (Weapon& Right, Weapon& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.damageValue!= Left.damageValue){
     return false;
  }
  if(Right.ammunition!= Left.ammunition){
     return false;
  }
  if(Right.maxAmmunition!= Left.maxAmmunition){
     return false;
  }
  if(!compare(Right.soldier, Left.soldier, sizeof Right.soldier)){
    return false;
  }
  if(!compare(Right.defensePost, Left.defensePost, sizeof Right.defensePost)){
    return false;
  }  
}

Weapon& Weapon::operator=(Weapon& other){
  internalCopy(other);
  return *this;  
}

void Weapon::internalCopy(Weapon& other){
  this->damageValue= other.damageValue;
  this->ammunition= other.ammunition;
  this->maxAmmunition= other.maxAmmunition;
  copyObject(other.soldier, this->soldier, sizeof other.soldier);
  copyObject(other.defensePost, this->defensePost, sizeof other.defensePost);  
}

bool Weapon::setDamageValue(const int aNewDamageValue){
  bool wasSet= false;
  if(damageValue > 0){  
    this->damageValue = aNewDamageValue;
    wasSet= true;
  }
  return wasSet;  
}

bool Weapon::setAmmunition(const int aNewAmmunition){
  bool wasSet= false;
  if(ammunition >= 0){  
    this->ammunition = aNewAmmunition;
    wasSet= true;
  }
  return wasSet;  
}

bool Weapon::setMaxAmmunition(const int aNewMaxAmmunition){
  bool wasSet= false;
  if(ammunition <= maxAmmunition && maxAmmunition > 0){  
    this->maxAmmunition = aNewMaxAmmunition;
    wasSet= true;
  }
  return wasSet;  
}

bool Weapon::setSoldier(Soldier* aNewSoldier){
  bool wasSet= false;
  if (aNewSoldier == NULL){
    Soldier* existingSoldier = this->soldier;
    this->soldier = NULL;
    
    if (existingSoldier != NULL && existingSoldier->getEquippedWeapon() != NULL){
      existingSoldier->setEquippedWeapon(NULL);
    }
    wasSet = true;
    return wasSet;
  }
  
  Soldier* currentSoldier = getSoldier();
  if (currentSoldier != NULL && currentSoldier!= aNewSoldier){
    currentSoldier->setEquippedWeapon(NULL);
  }
  
  this->soldier = aNewSoldier;
  Weapon* existingEquippedWeapon = aNewSoldier->getEquippedWeapon();
  
  if (this!=existingEquippedWeapon){
    aNewSoldier->setEquippedWeapon(this);
  }
  wasSet= true;
  return wasSet;  
}

bool Weapon::setDefensePost(DefensePost* aNewDefensePost){
  bool wasSet= false;
  if (aNewDefensePost == NULL){
    return wasSet;
  }
  
  DefensePost* existingDefensePost = this->defensePost;
  this->defensePost = aNewDefensePost;
  
  if (existingDefensePost != NULL && existingDefensePost != aNewDefensePost){
      existingDefensePost->removeWeapon(this);
  }
  this->defensePost->addWeapon(this);
  wasSet = true;
  return wasSet;  
}

int Weapon::getDamageValue(void){
  return this->damageValue;  
}

int Weapon::getAmmunition(void){
  return this->ammunition;  
}

int Weapon::getMaxAmmunition(void){
  return this->maxAmmunition;  
}

Soldier* Weapon::getSoldier(void){
  return this->soldier;  
}

DefensePost* Weapon::getDefensePost(void){
  return this->defensePost;  
}

size_t Weapon::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
Weapon::~Weapon(){
  //Resource::~Resource();
  this->deleteAssociatedObjects();
  delete soldier;
  delete defensePost;  
}

void Weapon::deleteAssociatedObjects(void){
  if(this->soldier!= NULL){
    this->soldier->setEquippedWeapon(NULL);
  }
  DefensePost* placeholderDefensePost = this->defensePost;
  this->defensePost = NULL;
  placeholderDefensePost->removeWeapon(this);  
}
;

