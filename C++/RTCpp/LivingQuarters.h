//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#ifndef DEF__LIVINGQUARTERS_H
#define DEF__LIVINGQUARTERS_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "LivingQuarters.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <LivingQuarters.h>
#include <Facility.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>
#include <vector>

class Facility;
class Survivor;
class Shelter;
class MedicalBay;
class Mission;
// line 355 "model.ump"
// line 1232 "model.ump"
class LivingQuarters : public Facility{
	
	private:
		
		//LivingQuarters Attributes
		int comfortLevel;
		//LivingQuarters Associations
		/*
		 * Association
		 */
		// line 360 "model.ump"
		vector<Survivor*>* residents;
		bool enterFC_Active(void);
		bool exitFacilityStateFC_ActiveActiveState(void);
		bool exitFacilityStateFC_Active(void);
		bool exitFacilityState(void);
		void setActiveState(FacilityStateFC_ActiveActiveState aActiveState);
		void setFC_Active(FacilityStateFC_Active aFC_Active);
		void setFacilityState(FacilityState aFacilityState);
		bool exitFC_Active(void);
	
	public:
		
		//------------------------
		//CONSTRUCTOR
		//------------------------
		LivingQuarters(const string aFacilityName, const int aCapacity, const int aLevel, const double aCondition, const int aPowerConsumption, Shelter* aShelter, const int aComfortLevel);
		LivingQuarters(LivingQuarters& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const LivingQuarters& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (LivingQuarters& Right, LivingQuarters& Left);
		friend bool operator != (LivingQuarters& Right, LivingQuarters& Left){
		  return !( Right == Left);  
		}
		bool operator == (const LivingQuarters& Right) const{
		  return this == &Right;  
		}
		bool operator != (const LivingQuarters& Right) const{
		  return this != &Right;  
		}
		LivingQuarters& operator=(LivingQuarters& other);
		
		void internalCopy(LivingQuarters& other);
		bool setComfortLevel(const int aNewComfortLevel);
		inline unsigned int minimumNumberOfResidents(void){
		  return 10;  
		}
		inline unsigned int maximumNumberOfResidents(void){
		  return 0;  
		}
		int getComfortLevel(void);
		vector<Survivor*>* getResidents(void);
		Survivor* getResident(int index);
		unsigned int numberOfResidents(void);
		bool hasResident(void);
		int indexOfResident(Survivor* aResident);
		bool removeResident(Survivor* aResident);
		bool removeResidentAt(int index);
		bool addResident(Survivor* aNewResident);
		bool addResidentAt(Survivor* aNewResident, int index);
		bool addOrMoveResidentAt(Survivor* aNewResident, int index);
		Survivor* addResident(const string aName, Shelter* aShelter, Facility* aFacility, MedicalBay* aMedicalBay, Mission* aMission);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~LivingQuarters();
		void deleteAssociatedObjects(void);
		FacilityStateFC_ActiveActiveState getActiveState(void);
		FacilityStateFC_Active getFC_Active(void);
		FacilityState getFacilityState(void);
		string getFacilityStateFullName(void);
		bool cycleComplete();
		bool removeWorker();
		bool productionCycle();
		bool assignWorkerAndOperate();
		bool abort();
		bool upgradeComplete();
		bool repairCompleteAbove80();
		bool partialRepair();
		bool conditionZero();
		bool repair();
		bool powerLost();
		bool conditionBelow20();
		bool repairAbove50();
		bool attackOrAccident();
		bool conditionBelow50();
		bool deactivateOrPowerLost();
		bool upgrade();
		bool activateWithPower();
		InternalMission* addInternalMission(const string aDescription, const int aDifficulty, const int aDuration, Shelter* aShelter, const string aPriority);
		bool addOrMoveInternalMissionAt(InternalMission* aNewInternalMission, int index);
		bool addInternalMissionAt(InternalMission* aNewInternalMission, int index);
		bool addInternalMission(InternalMission* aNewInternalMission);
		bool removeInternalMissionAt(int index);
		bool removeInternalMission(InternalMission* aInternalMission);
		int indexOfInternalMission(InternalMission* aInternalMission);
		bool hasInternalMission(void);
		unsigned int numberOfInternalMissions(void);
		InternalMission* getInternalMission(int index);
		vector<InternalMission*>* getInternalMissions(void);
		bool addOrMoveSurvivorAt(Survivor* aNewSurvivor, int index);
		bool addSurvivorAt(Survivor* aNewSurvivor, int index);
		bool addSurvivor(Survivor* aNewSurvivor);
		bool removeSurvivorAt(int index);
		bool removeSurvivor(Survivor* aSurvivor);
		int indexOfSurvivor(Survivor* aSurvivor);
		bool hasSurvivor(void);
		unsigned int numberOfSurvivors(void);
		Survivor* getSurvivor(int index);
		vector<Survivor*>* getSurvivors(void);
		Shelter* getShelter(void);
		Survivor* addWorker(const string aName, Shelter* aShelter, LivingQuarters* aLivingQuarters, MedicalBay* aMedicalBay, Mission* aMission);
		bool addOrMoveWorkerAt(Survivor* aNewWorker, int index);
		bool addWorkerAt(Survivor* aNewWorker, int index);
		bool addWorker(Survivor* aNewWorker);
		bool removeWorkerAt(int index);
		bool removeWorker(Survivor* aWorker);
		int indexOfWorker(Survivor* aWorker);
		bool hasWorker(void);
		unsigned int numberOfWorkers(void);
		Survivor* getWorker(int index);
		vector<Survivor*>* getWorkers(void);
		int getPowerConsumption(void);
		double getCondition(void);
		int getLevel(void);
		int getCapacity(void);
		string getFacilityName(void);
		bool setShelter(Shelter* aNewShelter);
		bool setPowerConsumption(const int aNewPowerConsumption);
		bool setCondition(double aNewCondition);
		bool setLevel(const int aNewLevel);
		bool setCapacity(const int aNewCapacity);
		bool setFacilityName(const string aNewFacilityName);
	
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
    template<> struct hash<LivingQuarters *> {
        size_t operator()(LivingQuarters* ptr ) const {
            return ptr->hashCode();
        }
    };
}
#endif