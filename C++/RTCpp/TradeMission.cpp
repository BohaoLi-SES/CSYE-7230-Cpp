//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__TRADEMISSION_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <TradeMission.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <TradeMission.h>
#include <ExternalMission.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
TradeMission::TradeMission(const string aDescription, const int aDifficulty, const int aDuration, Shelter* aShelter, const string aDestination, const double aTravelDistance, const string aTradingPartner):ExternalMission(aDescription, aDifficulty, aDuration, aShelter, aDestination, aTravelDistance){
  this->tradingPartner= aTradingPartner;  
}

TradeMission::TradeMission(TradeMission& other):ExternalMission(other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void TradeMission::toOstream(ostream& os) const{
  ExternalMission::toOstream(os);
  TradeMission* thisptr = const_cast<TradeMission*>(this);
  os << "[" << "tradingPartner:" << thisptr->getTradingPartner() << "]";  
}

ostream& operator<<(ostream& os, const TradeMission& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (TradeMission& Right, TradeMission& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }
  if(Right.tradingPartner.compare(Left.tradingPartner) != 0){
     return false;
  }  
}

TradeMission& TradeMission::operator=(TradeMission& other){
  internalCopy(other);
  return *this;  
}

void TradeMission::internalCopy(TradeMission& other){
  this->tradingPartner.assign(other.tradingPartner);  
}

bool TradeMission::setTradingPartner(const string aNewTradingPartner){
  bool wasSet= false;
  this->tradingPartner = aNewTradingPartner;
  wasSet= true;
  return wasSet;  
}

string TradeMission::getTradingPartner(void){
  return this->tradingPartner;  
}

size_t TradeMission::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
TradeMission::~TradeMission(){
  //ExternalMission::~ExternalMission();
  this->deleteAssociatedObjects();  
}

void TradeMission::deleteAssociatedObjects(void){
  ExternalMission::deleteAssociatedObjects();  
}
;

