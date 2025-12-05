//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#ifndef DEF__SHELTER_H
#define DEF__SHELTER_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "Shelter.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Shelter.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>
#include <vector>
#include <cassert>
#include <string>

Shelter_ENUM_BEGIN
class ShelterState_{

  public:
    typedef enum{SH_Normal=0, SH_Alert=1, SH_Lockdown=2, SH_UnderAttack=3, SH_PowerOutage=4, SH_Damaged=5, SH_Crisis=6, SH_Abandoned=7} enum_type;
    
    ShelterState_(enum_type val = SH_Normal): _val(val){
        assert(val <= SH_Abandoned);
        }
    
        operator enum_type() const {
            return _val;
        }
        
        operator int() { 
              return static_cast<int>(_val); 
      }
      
      operator string() { 
        switch (_val){
          case SH_Normal: return "SH_Normal";
          case SH_Alert: return "SH_Alert";
          case SH_Lockdown: return "SH_Lockdown";
          case SH_UnderAttack: return "SH_UnderAttack";
          case SH_PowerOutage: return "SH_PowerOutage";
          case SH_Damaged: return "SH_Damaged";
          case SH_Crisis: return "SH_Crisis";
          case SH_Abandoned: return "SH_Abandoned";        
          default:  return "[Unknown ENUM Type]";
      }
    }
    
  private:
      enum_type _val;
};
Shelter_ENUM_END
class Survivor;
class Facility;
class LivingQuarters;
class MedicalBay;
class Mission;
class RadiationMonitor;
/*
 * ==================== Central Shelter Class ====================
 * ==================== STATE MACHINES ====================
 */
// line 3 "model.ump"
// line 892 "model.ump"
// line 1164 "model.ump"
class Shelter{
	
	private:
		
		//Shelter Attributes
		string name;
		int maxCapacity;
		int currentPopulation;
		//Shelter Associations
		/*
		 * Associations
		 */
		// line 9 "model.ump"
		vector<Survivor*>* occupants;
		// line 10 "model.ump"
		vector<Facility*>* facilities;
		// line 11 "model.ump"
		vector<Mission*>* missions;
		// line 12 "model.ump"
		RadiationMonitor* radiationMonitor;
		//Shelter State Machines
		ShelterState shelterState;
		
		void setShelterState(ShelterState aShelterState);
		bool exitShelterState(void);
	
	public:
		
		//------------------------
		//CONSTRUCTOR
		//------------------------
		Shelter(const string aName, const int aMaxCapacity, const int aCurrentPopulation, RadiationMonitor* aRadiationMonitor);
		Shelter(Shelter& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const Shelter& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (Shelter& Right, Shelter& Left);
		friend bool operator != (Shelter& Right, Shelter& Left){
		  return !( Right == Left);  
		}
		bool operator == (const Shelter& Right) const{
		  return this == &Right;  
		}
		bool operator != (const Shelter& Right) const{
		  return this != &Right;  
		}
		Shelter& operator=(Shelter& other);
		
		void internalCopy(Shelter& other);
		bool setName(const string aNewName);
		bool setMaxCapacity(const int aNewMaxCapacity);
		bool setCurrentPopulation(const int aNewCurrentPopulation);
		inline unsigned int minimumNumberOfOccupants(void){
		  return 100;  
		}
		inline unsigned int maximumNumberOfOccupants(void){
		  return 0;  
		}
		inline unsigned int minimumNumberOfFacilities(void){
		  return 20;  
		}
		inline unsigned int maximumNumberOfFacilities(void){
		  return 0;  
		}
		inline unsigned int minimumNumberOfRadiationMonitors(void){
		  return 1;  
		}
		string getName(void);
		int getMaxCapacity(void);
		int getCurrentPopulation(void);
		vector<Survivor*>* getOccupants(void);
		Survivor* getOccupant(int index);
		unsigned int numberOfOccupants(void);
		bool hasOccupant(void);
		int indexOfOccupant(Survivor* aOccupant);
		bool removeOccupant(Survivor* aOccupant);
		bool removeOccupantAt(int index);
		bool addOccupant(Survivor* aNewOccupant);
		bool addOccupantAt(Survivor* aNewOccupant, int index);
		bool addOrMoveOccupantAt(Survivor* aNewOccupant, int index);
		Survivor* addOccupant(const string aName, Facility* aFacility, LivingQuarters* aLivingQuarters, MedicalBay* aMedicalBay, Mission* aMission);
		vector<Facility*>* getFacilities(void);
		Facility* getFacility(int index);
		unsigned int numberOfFacilities(void);
		bool hasFacility(void);
		int indexOfFacility(Facility* aFacility);
		bool removeFacility(Facility* aFacility);
		bool removeFacilityAt(int index);
		bool addFacility(Facility* aNewFacility);
		bool addFacilityAt(Facility* aNewFacility, int index);
		bool addOrMoveFacilityAt(Facility* aNewFacility, int index);
		Facility* addFacility(const string aFacilityName, const int aCapacity, const int aLevel, double aCondition, const int aPowerConsumption);
		vector<Mission*>* getMissions(void);
		Mission* getMission(int index);
		unsigned int numberOfMissions(void);
		bool hasMission(void);
		int indexOfMission(Mission* aMission);
		bool removeMission(Mission* aMission);
		bool removeMissionAt(int index);
		bool addMission(Mission* aNewMission);
		bool addMissionAt(Mission* aNewMission, int index);
		bool addOrMoveMissionAt(Mission* aNewMission, int index);
		Mission* addMission(const string aDescription, const int aDifficulty, const int aDuration);
		RadiationMonitor* getRadiationMonitor(void);
		bool radiationLevelUp();
		bool detectThreat();
		bool energyDepleted();
		bool multipleResourcesCritical();
		bool radiationRecovered();
		bool radiationDangerLevel();
		bool intrusion();
		bool radiationDecreased();
		bool fullyCleared();
		bool threatRepelled();
		bool defenseFailed();
		bool powerRestored();
		bool prolongedOutage();
		bool repairComplete();
		bool cascadingDamage();
		bool recovered();
		bool populationZero();
		string getShelterStateFullName(void);
		ShelterState getShelterState(void);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~Shelter();
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
    template<> struct hash<Shelter *> {
        size_t operator()(Shelter* ptr ) const {
            return ptr->hashCode();
        }
    };
}
#endif