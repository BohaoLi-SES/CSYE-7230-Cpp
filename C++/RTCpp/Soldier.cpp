//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__SOLDIER_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <Soldier.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Soldier.h>
#include <Survivor.h>
#include <Weapon.h>
#include <DefensePost.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
Soldier::Soldier(const string aName, Shelter* aShelter, Facility* aFacility, LivingQuarters* aLivingQuarters, MedicalBay* aMedicalBay, Mission* aMission, const int aCombatSkill, DefensePost* aDefensePost):
		equippedWeapon(NULL),
		defensePost(NULL),
    Survivor(aName, aShelter, aFacility, aLivingQuarters, aMedicalBay, aMission){
  this->combatSkill= aCombatSkill;
  this->equippedWeapon= NULL;
  if (!setDefensePost(aDefensePost)){
    throw "Unable to create Soldier due to aDefensePost";
  }
  if(!(combatSkill >= 1 && combatSkill <= 100)){  
    throw "Please provide a valid combatSkill";
  }  
}

Soldier::Soldier(Soldier& other):
		equippedWeapon(NULL),
		defensePost(NULL),
    Survivor(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void Soldier::toOstream(ostream& os) const{
  Survivor::toOstream(os);
  Soldier* thisptr = const_cast<Soldier*>(this);
  os << "[" << "combatSkill:" << thisptr->getCombatSkill() << "]" << endl;
  (thisptr->getEquippedWeapon()!= NULL ?  os << "equippedWeapon:" << thisptr->getEquippedWeapon() : os << "equippedWeapon:" << "NULL")<< endl;
      (thisptr->getDefensePost()!= NULL ?  os << "defensePost:" << thisptr->getDefensePost() : os << "defensePost:" << "NULL");  
}

ostream& operator<<(ostream& os, const Soldier& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (Soldier& Right, Soldier& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.combatSkill!= Left.combatSkill){
     return false;
  }
  if(!compare(Right.equippedWeapon, Left.equippedWeapon, sizeof Right.equippedWeapon)){
    return false;
  }
  if(!compare(Right.defensePost, Left.defensePost, sizeof Right.defensePost)){
    return false;
  }  
}

Soldier& Soldier::operator=(Soldier& other){
  internalCopy(other);
  return *this;  
}

void Soldier::internalCopy(Soldier& other){
  this->combatSkill= other.combatSkill;
  copyObject(other.equippedWeapon, this->equippedWeapon, sizeof other.equippedWeapon);
  copyObject(other.defensePost, this->defensePost, sizeof other.defensePost);  
}

bool Soldier::setCombatSkill(const int aNewCombatSkill){
  bool wasSet= false;
  if(combatSkill >= 1){  
    this->combatSkill = aNewCombatSkill;
    wasSet= true;
  }
  return wasSet;  
}

bool Soldier::setEquippedWeapon(Weapon* aNewEquippedWeapon){
  bool wasSet= false;
  if (aNewEquippedWeapon == NULL){
    Weapon* existingEquippedWeapon = this->equippedWeapon;
    this->equippedWeapon = NULL;
    
    if (existingEquippedWeapon != NULL && existingEquippedWeapon->getSoldier() != NULL){
      existingEquippedWeapon->setSoldier(NULL);
    }
    wasSet = true;
    return wasSet;
  }
  
  Weapon* currentEquippedWeapon = getEquippedWeapon();
  if (currentEquippedWeapon != NULL && currentEquippedWeapon!= aNewEquippedWeapon){
    currentEquippedWeapon->setSoldier(NULL);
  }
  
  this->equippedWeapon = aNewEquippedWeapon;
  Soldier* existingSoldier = aNewEquippedWeapon->getSoldier();
  
  if (this!=existingSoldier){
    aNewEquippedWeapon->setSoldier(this);
  }
  wasSet= true;
  return wasSet;  
}

bool Soldier::setDefensePost(DefensePost* aNewDefensePost){
  bool wasSet= false;
  if(aNewDefensePost == NULL){
    //Must provide defensePost to Soldier
    return wasSet;
  }
  
  if(aNewDefensePost->numberOfGuards() >= aNewDefensePost->maximumNumberOfGuards()){
    return wasSet;
  }
  
  DefensePost* existingDefensePost = this->defensePost;
  this->defensePost = aNewDefensePost;
  if (existingDefensePost != NULL && existingDefensePost!= aNewDefensePost){
    bool didRemove = existingDefensePost->removeGuard(this);
    if(!didRemove){
      this->defensePost = existingDefensePost;
      return wasSet;
    }
  }
  this->defensePost->addGuard(this);
  wasSet = true;
  
  return wasSet;  
}

int Soldier::getCombatSkill(void){
  return this->combatSkill;  
}

Weapon* Soldier::getEquippedWeapon(void){
  return this->equippedWeapon;  
}

DefensePost* Soldier::getDefensePost(void){
  return this->defensePost;  
}

size_t Soldier::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
Soldier::~Soldier(){
  //Survivor::~Survivor();
  this->deleteAssociatedObjects();
  delete equippedWeapon;
  delete defensePost;  
}

void Soldier::deleteAssociatedObjects(void){
  if(this->equippedWeapon!= NULL){
    this->equippedWeapon->setSoldier(NULL);
  }
  DefensePost* placeholderDefensePost = this->defensePost;
  this->defensePost = NULL;
  placeholderDefensePost->removeGuard(this);  
}
;

