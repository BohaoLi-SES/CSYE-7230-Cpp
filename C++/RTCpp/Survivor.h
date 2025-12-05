//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#ifndef DEF__SURVIVOR_H
#define DEF__SURVIVOR_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "Survivor.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Survivor.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>
#include <vector>
#include <cassert>
#include <string>

Survivor_ENUM_BEGIN
class PhysicalState_{

  public:
    typedef enum{PH_Healthy=0, PH_Wounded=1, PH_Severe=2, PH_Critical=3, PH_Dead=4} enum_type;
    
    PhysicalState_(enum_type val = PH_Healthy): _val(val){
        assert(val <= PH_Dead);
        }
    
        operator enum_type() const {
            return _val;
        }
        
        operator int() { 
              return static_cast<int>(_val); 
      }
      
      operator string() { 
        switch (_val){
          case PH_Healthy: return "PH_Healthy";
          case PH_Wounded: return "PH_Wounded";
          case PH_Severe: return "PH_Severe";
          case PH_Critical: return "PH_Critical";
          case PH_Dead: return "PH_Dead";        
          default:  return "[Unknown ENUM Type]";
      }
    }
    
  private:
      enum_type _val;
};
Survivor_ENUM_END

Survivor_ENUM_BEGIN
class RadiationState_{

  public:
    typedef enum{RD_Clean=0, RD_Low=1, RD_High=2, RD_Severe=3, RD_Dead=4} enum_type;
    
    RadiationState_(enum_type val = RD_Clean): _val(val){
        assert(val <= RD_Dead);
        }
    
        operator enum_type() const {
            return _val;
        }
        
        operator int() { 
              return static_cast<int>(_val); 
      }
      
      operator string() { 
        switch (_val){
          case RD_Clean: return "RD_Clean";
          case RD_Low: return "RD_Low";
          case RD_High: return "RD_High";
          case RD_Severe: return "RD_Severe";
          case RD_Dead: return "RD_Dead";        
          default:  return "[Unknown ENUM Type]";
      }
    }
    
  private:
      enum_type _val;
};
Survivor_ENUM_END

Survivor_ENUM_BEGIN
class MentalState_{

  public:
    typedef enum{MH_Stable=0, MH_Stressed=1, MH_Depressed=2, MH_Breakdown=3, MH_Exile=4} enum_type;
    
    MentalState_(enum_type val = MH_Stable): _val(val){
        assert(val <= MH_Exile);
        }
    
        operator enum_type() const {
            return _val;
        }
        
        operator int() { 
              return static_cast<int>(_val); 
      }
      
      operator string() { 
        switch (_val){
          case MH_Stable: return "MH_Stable";
          case MH_Stressed: return "MH_Stressed";
          case MH_Depressed: return "MH_Depressed";
          case MH_Breakdown: return "MH_Breakdown";
          case MH_Exile: return "MH_Exile";        
          default:  return "[Unknown ENUM Type]";
      }
    }
    
  private:
      enum_type _val;
};
Survivor_ENUM_END

Survivor_ENUM_BEGIN
class BehaviorState_{

  public:
    typedef enum{BH_Idle=0, BH_Working=1, BH_OnMission=2, BH_Resting=3, BH_ForcedRest=4, BH_Healing=5, BH_Recovering=6} enum_type;
    
    BehaviorState_(enum_type val = BH_Idle): _val(val){
        assert(val <= BH_Recovering);
        }
    
        operator enum_type() const {
            return _val;
        }
        
        operator int() { 
              return static_cast<int>(_val); 
      }
      
      operator string() { 
        switch (_val){
          case BH_Idle: return "BH_Idle";
          case BH_Working: return "BH_Working";
          case BH_OnMission: return "BH_OnMission";
          case BH_Resting: return "BH_Resting";
          case BH_ForcedRest: return "BH_ForcedRest";
          case BH_Healing: return "BH_Healing";
          case BH_Recovering: return "BH_Recovering";        
          default:  return "[Unknown ENUM Type]";
      }
    }
    
  private:
      enum_type _val;
};
Survivor_ENUM_END
class Facility;
class Mission;
class Shelter;
class Children;
class LivingQuarters;
class MedicalBay;
/*
 * ==================== Survivor Management ====================
 */
// line 83 "model.ump"
// line 930 "model.ump"
// line 1173 "model.ump"
class Survivor{
	
	private:
		
		//Survivor Attributes
		string name;
		int health;
		int radiationLevel;
		//Survivor Associations
		/*
		 * Associations
		 */
		// line 89 "model.ump"
		Facility* currentLocation;
		// line 90 "model.ump"
		vector<Mission*>* assignedMissions;
		// line 9 "model.ump"
		Shelter* shelter;
		// line 268 "model.ump"
		vector<Children*>* childrens;
		// line 89 "model.ump"
		Facility* facility;
		// line 360 "model.ump"
		LivingQuarters* livingQuarters;
		// line 391 "model.ump"
		MedicalBay* medicalBay;
		// line 90 "model.ump"
		Mission* mission;
		//Survivor State Machines
		PhysicalState physicalState;
		RadiationState radiationState;
		MentalState mentalState;
		BehaviorState behaviorState;
		
		void setPhysicalState(PhysicalState aPhysicalState);
		void setRadiationState(RadiationState aRadiationState);
		void setMentalState(MentalState aMentalState);
		void setBehaviorState(BehaviorState aBehaviorState);
		bool exitPhysicalState(void);
		bool exitRadiationState(void);
		bool exitMentalState(void);
		bool exitBehaviorState(void);
	
	public:
		
		//------------------------
		//CONSTRUCTOR
		//------------------------
		Survivor(const string aName, Shelter* aShelter, Facility* aFacility, LivingQuarters* aLivingQuarters, MedicalBay* aMedicalBay, Mission* aMission);
		Survivor(Survivor& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const Survivor& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (Survivor& Right, Survivor& Left);
		friend bool operator != (Survivor& Right, Survivor& Left){
		  return !( Right == Left);  
		}
		bool operator == (const Survivor& Right) const{
		  return this == &Right;  
		}
		bool operator != (const Survivor& Right) const{
		  return this != &Right;  
		}
		Survivor& operator=(Survivor& other);
		
		void internalCopy(Survivor& other);
		bool setName(const string aNewName);
		bool setHealth(const int aNewHealth);
		bool setRadiationLevel(const int aNewRadiationLevel);
		bool setCurrentLocation(Facility* aNewCurrentLocation);
		bool setShelter(Shelter* aNewShelter);
		inline unsigned int minimumNumberOfShelters(void){
		  return 1;  
		}
		bool setFacility(Facility* aNewFacility);
		inline unsigned int minimumNumberOfFacilities(void){
		  return 1;  
		}
		bool setLivingQuarter(LivingQuarters* aNewLivingQuarter);
		inline unsigned int minimumNumberOfLivingQuarters(void){
		  return 1;  
		}
		bool setMedicalBay(MedicalBay* aNewMedicalBay);
		inline unsigned int minimumNumberOfMedicalBaies(void){
		  return 1;  
		}
		bool setMission(Mission* aNewMission);
		inline unsigned int minimumNumberOfMissions(void){
		  return 1;  
		}
		string getName(void);
		int getHealth(void);
		int getRadiationLevel(void);
		Facility* getCurrentLocation(void);
		vector<Mission*>* getAssignedMissions(void);
		Mission* getAssignedMission(int index);
		unsigned int numberOfAssignedMissions(void);
		bool hasAssignedMission(void);
		int indexOfAssignedMission(Mission* aAssignedMission);
		bool removeAssignedMission(Mission* aAssignedMission);
		bool removeAssignedMissionAt(int index);
		bool addAssignedMission(Mission* aNewAssignedMission);
		bool addAssignedMissionAt(Mission* aNewAssignedMission, int index);
		bool addOrMoveAssignedMissionAt(Mission* aNewAssignedMission, int index);
		Shelter* getShelter(void);
		vector<Children*>* getChildrens(void);
		Children* getChildren(int index);
		unsigned int numberOfChildrens(void);
		bool hasChildren(void);
		int indexOfChildren(Children* aChildren);
		bool removeChildren(Children* aChildren);
		bool removeChildrenAt(int index);
		bool addChildren(Children* aNewChildren);
		bool addChildrenAt(Children* aNewChildren, int index);
		bool addOrMoveChildrenAt(Children* aNewChildren, int index);
		Facility* getFacility(void);
		LivingQuarters* getLivingQuarter(void);
		MedicalBay* getMedicalBay(void);
		Mission* getMission(void);
		bool takeDamageAbove50();
		bool takeDamageBelow50();
		bool healAndRestAbove80();
		bool treatmentAbove50();
		bool healthBelow20();
		bool emergencySurgery();
		bool healthZero();
		bool increaseRadiation();
		bool treatRadiationToZero();
		bool radiationAbove30();
		bool radAwayBelow30();
		bool radiationAbove70();
		bool untreatedTick();
		bool intensiveTreatment();
		bool radiationFull();
		bool moraleLowOrTrauma();
		bool restAndPositiveEvent();
		bool moraleVeryLowOrRepeatedTrauma();
		bool therapyAndTime();
		bool moraleCritical();
		bool forceIntervention();
		bool noIntervention24h();
		bool assignToFacility();
		bool assignToMission();
		bool manualRest();
		bool cannotWork();
		bool removeFromFacility();
		bool urgentMissionCall();
		bool healthStateWorsened();
		bool missionComplete();
		bool injuredDuringMission();
		bool restComplete();
		bool enterMedicalBay();
		bool enterLivingQuarters();
		bool healingComplete();
		bool recoveryComplete();
		string getPhysicalStateFullName(void);
		PhysicalState getPhysicalState(void);
		string getRadiationStateFullName(void);
		RadiationState getRadiationState(void);
		string getMentalStateFullName(void);
		MentalState getMentalState(void);
		string getBehaviorStateFullName(void);
		BehaviorState getBehaviorState(void);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~Survivor();
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
    template<> struct hash<Survivor *> {
        size_t operator()(Survivor* ptr ) const {
            return ptr->hashCode();
        }
    };
}
#endif