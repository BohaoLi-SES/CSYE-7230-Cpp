//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__MEDICALBAY_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <MedicalBay.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <MedicalBay.h>
#include <Facility.h>
#include <Survivor.h>
#include <Shelter.h>
#include <LivingQuarters.h>
#include <Mission.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>
#include <vector>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
MedicalBay::MedicalBay(const string aFacilityName, const int aCapacity, const int aLevel, const double aCondition, const int aPowerConsumption, Shelter* aShelter, const int aTreatmentCapacity):Facility(aFacilityName, aCapacity, aLevel, aCondition, aPowerConsumption, aShelter){
  this->treatmentCapacity= aTreatmentCapacity;
  this->patients= new vector<Survivor*>();
  if(!(treatmentCapacity > 0)){  
    throw "Please provide a valid treatmentCapacity";
  }  
}

MedicalBay::MedicalBay(MedicalBay& other):Facility(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void MedicalBay::toOstream(ostream& os) const{
  Facility::toOstream(os);
  MedicalBay* thisptr = const_cast<MedicalBay*>(this);
  os << "[" << "treatmentCapacity:" << thisptr->getTreatmentCapacity() << "]" << endl;
  (thisptr->getPatients()!= NULL ?  os << "patients:" << thisptr->getPatients() : os << "patients:" << "NULL");  
}

ostream& operator<<(ostream& os, const MedicalBay& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (MedicalBay& Right, MedicalBay& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.treatmentCapacity!= Left.treatmentCapacity){
     return false;
  }
  if(!std::equal(Right.patients->begin(), Right.patients->end(), Left.patients->begin())){
     return false;
  }  
}

MedicalBay& MedicalBay::operator=(MedicalBay& other){
  internalCopy(other);
  return *this;  
}

void MedicalBay::internalCopy(MedicalBay& other){
  this->treatmentCapacity= other.treatmentCapacity;
  this->patients = new vector<Survivor*>();
  vector<Survivor*>::iterator patientsBeginIterator(other.patients->begin());
  vector<Survivor*>::iterator patientsEndIterator(other.patients->end());
  copyVector(patientsBeginIterator, patientsEndIterator, this->patients);  
}

bool MedicalBay::setTreatmentCapacity(const int aNewTreatmentCapacity){
  bool wasSet= false;
  if(treatmentCapacity > 0){  
    this->treatmentCapacity = aNewTreatmentCapacity;
    wasSet= true;
  }
  return wasSet;  
}

int MedicalBay::getTreatmentCapacity(void){
  return this->treatmentCapacity;  
}

vector<Survivor*>* MedicalBay::getPatients(void){
  vector<Survivor*>* copyOfPatients = new vector<Survivor*>();
  vector<Survivor*>::iterator patientsBeginIterator(this->patients->begin());
  vector<Survivor*>::iterator patientsEndIterator(this->patients->end());
  copyVector(patientsBeginIterator, patientsEndIterator, copyOfPatients);
  return copyOfPatients;  
}

Survivor* MedicalBay::getPatient(int index){
  Survivor* aPatient= (*(this->patients))[index];
  return aPatient;  
}

unsigned int MedicalBay::numberOfPatients(void){
  int number=this->patients->size();
  return number;  
}

bool MedicalBay::hasPatient(void){
  return this->numberOfPatients()>0;  
}

int MedicalBay::indexOfPatient(Survivor* aPatient){
  return IndexOf(this->patients->begin(), this->patients->end(), aPatient);  
}

bool MedicalBay::removePatient(Survivor* aPatient){
  bool wasRemoved= false;
  int index= IndexOf(this->patients->begin(), this->patients->end(), aPatient);
  if(index<0){ 
    return wasRemoved;
  }
  //Unable to remove aPatient, as it must always have a MedicalBay
  if (this== aPatient->getMedicalBay()){
      return wasRemoved;
  }
  wasRemoved= this->removePatientAt(index);
  return wasRemoved;  
}

bool MedicalBay::removePatientAt(int index){
  bool wasRemoved= false;
  if(index<0){
      return wasRemoved;
  }
  
  int size= this->numberOfPatients();
  if(index> size){
      return false;
  }
  this->patients->erase(this->patients->begin()+index);
  wasRemoved= size== this->numberOfPatients()+1;
  return wasRemoved;  
}

bool MedicalBay::addPatient(Survivor* aNewPatient){
  bool wasAdded= false;
  if (IndexOf(this->patients->begin(), this->patients->end(), aNewPatient)> -1) {
    return wasAdded;
  }
  if (this->numberOfPatients() >= this->maximumNumberOfPatients()){
    return wasAdded;
  }
  MedicalBay* existingMedicalBay = aNewPatient->getMedicalBay();
  bool isNewMedicalBay= existingMedicalBay != NULL && this!=existingMedicalBay;
  if(isNewMedicalBay){
    aNewPatient->setMedicalBay(this);
  }else{
    this->patients->push_back(aNewPatient);
  }
  wasAdded= true;
  return wasAdded;  
}

bool MedicalBay::addPatientAt(Survivor* aNewPatient, int index){
  bool wasAdded= false;
  if(addPatient(aNewPatient)){
      int newIndex= index;
      if(index < 0 ) { 
          newIndex = 0; 
      }
    
      int size= this->numberOfPatients();
      if(size>0){
          this->patients->erase(this->patients->begin()+IndexOf(this->patients->begin(), this->patients->end(),aNewPatient));    
      }
    
      size= this->numberOfPatients();
      if(newIndex > size) { 
          newIndex = size; 
      }
    
     this->patients->insert(this->patients->begin()+ newIndex, aNewPatient);
      wasAdded = true;
  }
  return wasAdded;  
}

bool MedicalBay::addOrMovePatientAt(Survivor* aNewPatient, int index){
  bool wasAdded= false;
  if(IndexOf(this->patients->begin(), this->patients->end(), aNewPatient) > -1) {
    if (index < 0) {
      index = 0;
    }
  
    int size= this->numberOfPatients();
    if (index > size) {
      index = size - 1;
    }
    
    wasAdded= this->removePatient(aNewPatient)| this->addPatientAt(aNewPatient, index);
  }else{
    wasAdded= this->addPatientAt(aNewPatient, index);
  }
  
  return wasAdded;  
}

Survivor* MedicalBay::addPatient(const string aName, Shelter* aShelter, Facility* aFacility, LivingQuarters* aLivingQuarters, Mission* aMission){
  if (this->numberOfPatients() >= this->maximumNumberOfPatients()){
    return NULL;
  }
  return new Survivor(aName, aShelter, aFacility, aLivingQuarters, this, aMission);  
}

size_t MedicalBay::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
MedicalBay::~MedicalBay(){
  //Facility::~Facility();
  this->deleteAssociatedObjects();
  
  std::for_each(patients->begin(), patients->end(), /*std::default_delete<Survivor>*/ deleteElement());
  patients->clear();
  delete patients;  
}

void MedicalBay::deleteAssociatedObjects(void){
  for(unsigned int index = patients->size(); index > 0 ; index--){
    Survivor* aSurvivor= (*(this->patients))[index-1];
    aSurvivor->deleteAssociatedObjects();
  }  
}
;

