//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#ifndef DEF__EXTERNALMISSION_H
#define DEF__EXTERNALMISSION_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "ExternalMission.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <ExternalMission.h>
#include <Mission.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>

class Mission;
// line 788 "model.ump"
// line 1297 "model.ump"
class ExternalMission : public Mission{
	
	private:
		
		//ExternalMission Attributes
		string destination;
		double travelDistance;
	
	public:
		
		//------------------------
		//CONSTRUCTOR
		//------------------------
		ExternalMission(const string aDescription, const int aDifficulty, const int aDuration, Shelter* aShelter, const string aDestination, const double aTravelDistance);
		ExternalMission(ExternalMission& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const ExternalMission& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (ExternalMission& Right, ExternalMission& Left);
		friend bool operator != (ExternalMission& Right, ExternalMission& Left){
		  return !( Right == Left);  
		}
		bool operator == (const ExternalMission& Right) const{
		  return this == &Right;  
		}
		bool operator != (const ExternalMission& Right) const{
		  return this != &Right;  
		}
		ExternalMission& operator=(ExternalMission& other);
		
		void internalCopy(ExternalMission& other);
		bool setDestination(const string aNewDestination);
		bool setTravelDistance(double aNewTravelDistance);
		string getDestination(void);
		double getTravelDistance(void);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~ExternalMission();
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
    template<> struct hash<ExternalMission *> {
        size_t operator()(ExternalMission* ptr ) const {
            return ptr->hashCode();
        }
    };
}
#endif