//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#ifndef DEF__GAMEEVENTHANDLER_H
#define DEF__GAMEEVENTHANDLER_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "GameEventHandler.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <GameEventHandler.h>


// line 1144 "model.ump"
// line 1197 "model.ump"
class GameEventHandler{
	
	public:
		
		//------------------------
		//CONSTRUCTOR
		//------------------------
		GameEventHandler();
		GameEventHandler(GameEventHandler& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const GameEventHandler& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (GameEventHandler& Right, GameEventHandler& Left);
		friend bool operator != (GameEventHandler& Right, GameEventHandler& Left){
		  return !( Right == Left);  
		}
		bool operator == (const GameEventHandler& Right) const{
		  return this == &Right;  
		}
		bool operator != (const GameEventHandler& Right) const{
		  return this != &Right;  
		}
		GameEventHandler& operator=(GameEventHandler& other);
		
		void internalCopy(GameEventHandler& other);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~GameEventHandler();
		void deleteAssociatedObjects(void);
	
	protected:
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		virtual void toOstream(ostream& os) const;
};


//------------------------
//HASH FUNCTION USE
//------------------------
#include <unordered_map>
namespace std{
    template<> struct hash<GameEventHandler *> {
        size_t operator()(GameEventHandler* ptr ) const {
            return ptr->hashCode();
        }
    };
}
#endif