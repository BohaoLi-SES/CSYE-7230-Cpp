//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#ifndef DEF__SUPPLYBAY_H
#define DEF__SUPPLYBAY_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "SupplyBay.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <SupplyBay.h>
#include <Facility.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>
#include <vector>

class Facility;
class Resource;
// line 461 "model.ump"
// line 1247 "model.ump"
class SupplyBay : public Facility{
	
	private:
		
		//SupplyBay Associations
		/*
		 * Association
		 */
		// line 465 "model.ump"
		vector<Resource*>* heldResources;
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
		SupplyBay(const string aFacilityName, const int aCapacity, const int aLevel, const double aCondition, const int aPowerConsumption, Shelter* aShelter);
		SupplyBay(SupplyBay& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const SupplyBay& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (SupplyBay& Right, SupplyBay& Left);
		friend bool operator != (SupplyBay& Right, SupplyBay& Left){
		  return !( Right == Left);  
		}
		bool operator == (const SupplyBay& Right) const{
		  return this == &Right;  
		}
		bool operator != (const SupplyBay& Right) const{
		  return this != &Right;  
		}
		SupplyBay& operator=(SupplyBay& other);
		
		void internalCopy(SupplyBay& other);
		vector<Resource*>* getHeldResources(void);
		Resource* getHeldResource(int index);
		unsigned int numberOfHeldResources(void);
		bool hasHeldResource(void);
		int indexOfHeldResource(Resource* aHeldResource);
		bool removeHeldResource(Resource* aHeldResource);
		bool removeHeldResourceAt(int index);
		bool addHeldResource(Resource* aNewHeldResource);
		bool addHeldResourceAt(Resource* aNewHeldResource, int index);
		bool addOrMoveHeldResourceAt(Resource* aNewHeldResource, int index);
		Resource* addHeldResource(const string aResourceId, const int aQuantity, const int aMaxCapacity, const string aUnit);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~SupplyBay();
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
    template<> struct hash<SupplyBay *> {
        size_t operator()(SupplyBay* ptr ) const {
            return ptr->hashCode();
        }
    };
}
#endif