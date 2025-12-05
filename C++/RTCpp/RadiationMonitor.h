//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#ifndef DEF__RADIATIONMONITOR_H
#define DEF__RADIATIONMONITOR_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "RadiationMonitor.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <RadiationMonitor.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>

class Shelter;
// line 45 "model.ump"
// line 1202 "model.ump"
class RadiationMonitor{
	
	private:
		
		//RadiationMonitor Attributes
		int externalLevel;
		int internalLevel;
		double threshold;
		bool isAlertActive;
		string status;
		//RadiationMonitor Associations
		// line 12 "model.ump"
		Shelter* shelter;
	
	public:
		
		//------------------------
		//CONSTRUCTOR
		//------------------------
		RadiationMonitor(const int aExternalLevel, const int aInternalLevel, const double aThreshold, const bool aIsAlertActive, Shelter* aShelter);
		RadiationMonitor(RadiationMonitor& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const RadiationMonitor& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (RadiationMonitor& Right, RadiationMonitor& Left);
		friend bool operator != (RadiationMonitor& Right, RadiationMonitor& Left){
		  return !( Right == Left);  
		}
		bool operator == (const RadiationMonitor& Right) const{
		  return this == &Right;  
		}
		bool operator != (const RadiationMonitor& Right) const{
		  return this != &Right;  
		}
		RadiationMonitor& operator=(RadiationMonitor& other);
		
		void internalCopy(RadiationMonitor& other);
		bool setExternalLevel(const int aNewExternalLevel);
		bool setInternalLevel(const int aNewInternalLevel);
		bool setThreshold(double aNewThreshold);
		bool setIsAlertActive(bool aNewIsAlertActive);
		bool setStatus(const string aNewStatus);
		inline unsigned int minimumNumberOfShelters(void){
		  return 1;  
		}
		int getExternalLevel(void);
		int getInternalLevel(void);
		double getThreshold(void);
		bool getIsAlertActive(void);
		bool isIsAlertActive(void);
		string getStatus(void);
		Shelter* getShelter(void);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~RadiationMonitor();
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
    template<> struct hash<RadiationMonitor *> {
        size_t operator()(RadiationMonitor* ptr ) const {
            return ptr->hashCode();
        }
    };
}
#endif