//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#ifndef DEF__FACILITY_H
#define DEF__FACILITY_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "Facility.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Facility.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>
#include <vector>
#include <cassert>
#include <string>

Facility_ENUM_BEGIN
class FacilityState_{

  public:
    typedef enum{FC_Inactive=0, FC_Active=1, FC_Degraded=2, FC_Damaged=3, FC_UnderRepair=4, FC_Upgrading=5, FC_Destroyed=6} enum_type;
    
    FacilityState_(enum_type val = FC_Inactive): _val(val){
        assert(val <= FC_Destroyed);
        }
    
        operator enum_type() const {
            return _val;
        }
        
        operator int() { 
              return static_cast<int>(_val); 
      }
      
      operator string() { 
        switch (_val){
          case FC_Inactive: return "FC_Inactive";
          case FC_Active: return "FC_Active";
          case FC_Degraded: return "FC_Degraded";
          case FC_Damaged: return "FC_Damaged";
          case FC_UnderRepair: return "FC_UnderRepair";
          case FC_Upgrading: return "FC_Upgrading";
          case FC_Destroyed: return "FC_Destroyed";        
          default:  return "[Unknown ENUM Type]";
      }
    }
    
  private:
      enum_type _val;
};
Facility_ENUM_END

Facility_ENUM_BEGIN
class FacilityStateFC_Active_{

  public:
    typedef enum{NIL=0, activeState=1} enum_type;
    
    FacilityStateFC_Active_(enum_type val = NIL): _val(val){
        assert(val <= activeState);
        }
    
        operator enum_type() const {
            return _val;
        }
        
        operator int() { 
              return static_cast<int>(_val); 
      }
      
      operator string() { 
        switch (_val){
          case NIL: return "NIL";
          case activeState: return "activeState";        
          default:  return "[Unknown ENUM Type]";
      }
    }
    
  private:
      enum_type _val;
};
Facility_ENUM_END

Facility_ENUM_BEGIN
class FacilityStateFC_ActiveActiveState_{

  public:
    typedef enum{NIL=0, AC_Idle=1, AC_Operating=2, AC_Producing=3} enum_type;
    
    FacilityStateFC_ActiveActiveState_(enum_type val = NIL): _val(val){
        assert(val <= AC_Producing);
        }
    
        operator enum_type() const {
            return _val;
        }
        
        operator int() { 
              return static_cast<int>(_val); 
      }
      
      operator string() { 
        switch (_val){
          case NIL: return "NIL";
          case AC_Idle: return "AC_Idle";
          case AC_Operating: return "AC_Operating";
          case AC_Producing: return "AC_Producing";        
          default:  return "[Unknown ENUM Type]";
      }
    }
    
  private:
      enum_type _val;
};
Facility_ENUM_END
class Survivor;
class Shelter;
class LivingQuarters;
class MedicalBay;
class Mission;
class InternalMission;
/*
 * ==================== Facility Management ====================
 */
// line 299 "model.ump"
// line 1073 "model.ump"
// line 1180 "model.ump"
class Facility{
	
	private:
		
		//Facility Attributes
		string facilityName;
		int capacity;
		int level;
		double condition;
		int powerConsumption;
		//Facility Associations
		/*
		 * Associations
		 */
		// line 308 "model.ump"
		vector<Survivor*>* workers;
		// line 10 "model.ump"
		Shelter* shelter;
		// line 308 "model.ump"
		vector<Survivor*>* survivors;
		// line 691 "model.ump"
		vector<InternalMission*>* internalMissions;
		//Facility State Machines
		FacilityState facilityState;
		FacilityStateFC_Active facilityStateFC_Active;
		FacilityStateFC_ActiveActiveState facilityStateFC_ActiveActiveState;
		
		bool exitFC_Active(void);
		void setFacilityState(FacilityState aFacilityState);
		void setFC_Active(FacilityStateFC_Active aFC_Active);
		void setActiveState(FacilityStateFC_ActiveActiveState aActiveState);
		bool exitFacilityState(void);
		bool exitFacilityStateFC_Active(void);
		bool exitFacilityStateFC_ActiveActiveState(void);
		bool enterFC_Active(void);
	
	public:
		
		//------------------------
		//CONSTRUCTOR
		//------------------------
		Facility(const string aFacilityName, const int aCapacity, const int aLevel, const double aCondition, const int aPowerConsumption, Shelter* aShelter);
		Facility(Facility& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const Facility& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (Facility& Right, Facility& Left);
		friend bool operator != (Facility& Right, Facility& Left){
		  return !( Right == Left);  
		}
		bool operator == (const Facility& Right) const{
		  return this == &Right;  
		}
		bool operator != (const Facility& Right) const{
		  return this != &Right;  
		}
		Facility& operator=(Facility& other);
		
		void internalCopy(Facility& other);
		bool setFacilityName(const string aNewFacilityName);
		bool setCapacity(const int aNewCapacity);
		bool setLevel(const int aNewLevel);
		bool setCondition(double aNewCondition);
		bool setPowerConsumption(const int aNewPowerConsumption);
		inline unsigned int minimumNumberOfWorkers(void){
		  return 6;  
		}
		inline unsigned int maximumNumberOfWorkers(void){
		  return 0;  
		}
		bool setShelter(Shelter* aNewShelter);
		inline unsigned int minimumNumberOfShelters(void){
		  return 1;  
		}
		string getFacilityName(void);
		int getCapacity(void);
		int getLevel(void);
		double getCondition(void);
		int getPowerConsumption(void);
		vector<Survivor*>* getWorkers(void);
		Survivor* getWorker(int index);
		unsigned int numberOfWorkers(void);
		bool hasWorker(void);
		int indexOfWorker(Survivor* aWorker);
		bool removeWorker(Survivor* aWorker);
		bool removeWorkerAt(int index);
		bool addWorker(Survivor* aNewWorker);
		bool addWorkerAt(Survivor* aNewWorker, int index);
		bool addOrMoveWorkerAt(Survivor* aNewWorker, int index);
		Survivor* addWorker(const string aName, Shelter* aShelter, LivingQuarters* aLivingQuarters, MedicalBay* aMedicalBay, Mission* aMission);
		Shelter* getShelter(void);
		vector<Survivor*>* getSurvivors(void);
		Survivor* getSurvivor(int index);
		unsigned int numberOfSurvivors(void);
		bool hasSurvivor(void);
		int indexOfSurvivor(Survivor* aSurvivor);
		bool removeSurvivor(Survivor* aSurvivor);
		bool removeSurvivorAt(int index);
		bool addSurvivor(Survivor* aNewSurvivor);
		bool addSurvivorAt(Survivor* aNewSurvivor, int index);
		bool addOrMoveSurvivorAt(Survivor* aNewSurvivor, int index);
		vector<InternalMission*>* getInternalMissions(void);
		InternalMission* getInternalMission(int index);
		unsigned int numberOfInternalMissions(void);
		bool hasInternalMission(void);
		int indexOfInternalMission(InternalMission* aInternalMission);
		bool removeInternalMission(InternalMission* aInternalMission);
		bool removeInternalMissionAt(int index);
		bool addInternalMission(InternalMission* aNewInternalMission);
		bool addInternalMissionAt(InternalMission* aNewInternalMission, int index);
		bool addOrMoveInternalMissionAt(InternalMission* aNewInternalMission, int index);
		InternalMission* addInternalMission(const string aDescription, const int aDifficulty, const int aDuration, Shelter* aShelter, const string aPriority);
		bool activateWithPower();
		bool upgrade();
		bool deactivateOrPowerLost();
		bool conditionBelow50();
		bool attackOrAccident();
		bool repairAbove50();
		bool conditionBelow20();
		bool powerLost();
		bool repair();
		bool conditionZero();
		bool partialRepair();
		bool repairCompleteAbove80();
		bool upgradeComplete();
		bool abort();
		bool assignWorkerAndOperate();
		bool productionCycle();
		bool removeWorker();
		bool cycleComplete();
		string getFacilityStateFullName(void);
		FacilityState getFacilityState(void);
		FacilityStateFC_Active getFC_Active(void);
		FacilityStateFC_ActiveActiveState getActiveState(void);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~Facility();
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
    template<> struct hash<Facility *> {
        size_t operator()(Facility* ptr ) const {
            return ptr->hashCode();
        }
    };
}
#endif