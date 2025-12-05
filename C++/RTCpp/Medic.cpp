//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__MEDIC_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <Medic.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Medic.h>
#include <Survivor.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
Medic::Medic(const string aName, Shelter* aShelter, Facility* aFacility, LivingQuarters* aLivingQuarters, MedicalBay* aMedicalBay, Mission* aMission, const int aMedicalSkill):Survivor(aName, aShelter, aFacility, aLivingQuarters, aMedicalBay, aMission){
  this->medicalSkill= aMedicalSkill;
  if(!(medicalSkill >= 1 && medicalSkill <= 100 && medicalSkill >= 30)){  
    throw "Please provide a valid medicalSkill";
  }  
}

Medic::Medic(Medic& other):Survivor(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void Medic::toOstream(ostream& os) const{
  Survivor::toOstream(os);
  Medic* thisptr = const_cast<Medic*>(this);
  os << "[" << "medicalSkill:" << thisptr->getMedicalSkill() << "]";  
}

ostream& operator<<(ostream& os, const Medic& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (Medic& Right, Medic& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.medicalSkill!= Left.medicalSkill){
     return false;
  }  
}

Medic& Medic::operator=(Medic& other){
  internalCopy(other);
  return *this;  
}

void Medic::internalCopy(Medic& other){
  this->medicalSkill= other.medicalSkill;  
}

bool Medic::setMedicalSkill(const int aNewMedicalSkill){
  bool wasSet= false;
  if(medicalSkill >= 1 && medicalSkill >= 30){  
    this->medicalSkill = aNewMedicalSkill;
    wasSet= true;
  }
  return wasSet;  
}

int Medic::getMedicalSkill(void){
  return this->medicalSkill;  
}

size_t Medic::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
Medic::~Medic(){
  //Survivor::~Survivor();
  this->deleteAssociatedObjects();  
}

void Medic::deleteAssociatedObjects(void){
  Survivor::deleteAssociatedObjects();  
}
;

