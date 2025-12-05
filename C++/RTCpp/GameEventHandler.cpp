//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#define DEF__GAMEEVENTHANDLER_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <GameEventHandler.h>
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <GameEventHandler.h>



//------------------------
//CONSTRUCTOR IMPLEMENTATION
//------------------------
GameEventHandler::GameEventHandler(){
  //No Implementation in this context  
}

GameEventHandler::GameEventHandler(GameEventHandler& other){
  internalCopy(other);  
}

//------------------------
//STREAM HELPER GROUP IMPLEMENTATION
//------------------------
void GameEventHandler::toOstream(ostream& os) const{
  //No Implementation in this context  
}

ostream& operator<<(ostream& os, const GameEventHandler& dt){
  dt.toOstream(os);
  return os;  
}

//------------------------
//PREDEFINED OPERATORS IMPLEMENTATION
//------------------------
bool operator == (GameEventHandler& Right, GameEventHandler& Left){
  //if (typeid(Right) != typeid(Left)) {
  //  return false;
  //}
  
  if(Right.hashCode() != Left.hashCode()) {
    return false;
  }  
}

GameEventHandler& GameEventHandler::operator=(GameEventHandler& other){
  internalCopy(other);
  return *this;  
}

void GameEventHandler::internalCopy(GameEventHandler& other){
  //No Implementation in this context  
}

size_t GameEventHandler::hashCode(void){
  return reinterpret_cast<size_t>(this);  
}

//------------------------
//DESTRUCTOR IMPLEMENTATION
//------------------------
GameEventHandler::~GameEventHandler(){
  this->deleteAssociatedObjects();  
}

void GameEventHandler::deleteAssociatedObjects(void){
  //No Implementation in this context  
}
;

