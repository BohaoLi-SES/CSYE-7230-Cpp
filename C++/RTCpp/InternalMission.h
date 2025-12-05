//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#ifndef DEF__INTERNALMISSION_H
#define DEF__INTERNALMISSION_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "InternalMission.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <InternalMission.h>
#include <Mission.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>

class Mission;
class Facility;
// line 685 "model.ump"
// line 1277 "model.ump"
class InternalMission : public Mission{
	
	private:
		
		//InternalMission Attributes
		string priority;
		//InternalMission Associations
		/*
		 * Association
		 */
		// line 691 "model.ump"
		Facility* targetFacility;
	
	public:
		
		//------------------------
		//CONSTRUCTOR
		//------------------------
		InternalMission(const string aDescription, const int aDifficulty, const int aDuration, Shelter* aShelter, const string aPriority, Facility* aTargetFacility);
		InternalMission(InternalMission& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const InternalMission& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (InternalMission& Right, InternalMission& Left);
		friend bool operator != (InternalMission& Right, InternalMission& Left){
		  return !( Right == Left);  
		}
		bool operator == (const InternalMission& Right) const{
		  return this == &Right;  
		}
		bool operator != (const InternalMission& Right) const{
		  return this != &Right;  
		}
		InternalMission& operator=(InternalMission& other);
		
		void internalCopy(InternalMission& other);
		bool setPriority(const string aNewPriority);
		bool setTargetFacility(Facility* aNewTargetFacility);
		inline unsigned int minimumNumberOfTargetFacilities(void){
		  return 1;  
		}
		string getPriority(void);
		Facility* getTargetFacility(void);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~InternalMission();
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
    template<> struct hash<InternalMission *> {
        size_t operator()(InternalMission* ptr ) const {
            return ptr->hashCode();
        }
    };
}
#endif