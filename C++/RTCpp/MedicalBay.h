//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#ifndef DEF__MEDICALBAY_H
#define DEF__MEDICALBAY_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "MedicalBay.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <MedicalBay.h>
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
class LivingQuarters;
class Mission;
// line 386 "model.ump"
// line 1237 "model.ump"
class MedicalBay : public Facility{
	
	private:
		
		//MedicalBay Attributes
		int treatmentCapacity;
		//MedicalBay Associations
		/*
		 * Association
		 */
		// line 391 "model.ump"
		vector<Survivor*>* patients;
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
		MedicalBay(const string aFacilityName, const int aCapacity, const int aLevel, const double aCondition, const int aPowerConsumption, Shelter* aShelter, const int aTreatmentCapacity);
		MedicalBay(MedicalBay& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const MedicalBay& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (MedicalBay& Right, MedicalBay& Left);
		friend bool operator != (MedicalBay& Right, MedicalBay& Left){
		  return !( Right == Left);  
		}
		bool operator == (const MedicalBay& Right) const{
		  return this == &Right;  
		}
		bool operator != (const MedicalBay& Right) const{
		  return this != &Right;  
		}
		MedicalBay& operator=(MedicalBay& other);
		
		void internalCopy(MedicalBay& other);
		bool setTreatmentCapacity(const int aNewTreatmentCapacity);
		inline unsigned int minimumNumberOfPatients(void){
		  return 5;  
		}
		inline unsigned int maximumNumberOfPatients(void){
		  return 0;  
		}
		int getTreatmentCapacity(void);
		vector<Survivor*>* getPatients(void);
		Survivor* getPatient(int index);
		unsigned int numberOfPatients(void);
		bool hasPatient(void);
		int indexOfPatient(Survivor* aPatient);
		bool removePatient(Survivor* aPatient);
		bool removePatientAt(int index);
		bool addPatient(Survivor* aNewPatient);
		bool addPatientAt(Survivor* aNewPatient, int index);
		bool addOrMovePatientAt(Survivor* aNewPatient, int index);
		Survivor* addPatient(const string aName, Shelter* aShelter, Facility* aFacility, LivingQuarters* aLivingQuarters, Mission* aMission);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~MedicalBay();
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
    template<> struct hash<MedicalBay *> {
        size_t operator()(MedicalBay* ptr ) const {
            return ptr->hashCode();
        }
    };
}
#endif