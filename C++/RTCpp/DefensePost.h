//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#ifndef DEF__DEFENSEPOST_H
#define DEF__DEFENSEPOST_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "DefensePost.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <DefensePost.h>
#include <Facility.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>
#include <vector>

class Facility;
class Soldier;
class Shelter;
class LivingQuarters;
class MedicalBay;
class Mission;
class Weapon;
class SupplyBay;
// line 421 "model.ump"
// line 1242 "model.ump"
class DefensePost : public Facility{
	
	private:
		
		//DefensePost Attributes
		int defenseRating;
		//DefensePost Associations
		/*
		 * Associations
		 */
		// line 426 "model.ump"
		vector<Soldier*>* guards;
		// line 427 "model.ump"
		vector<Weapon*>* weapons;
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
		DefensePost(const string aFacilityName, const int aCapacity, const int aLevel, const double aCondition, const int aPowerConsumption, Shelter* aShelter, const int aDefenseRating);
		DefensePost(DefensePost& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const DefensePost& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (DefensePost& Right, DefensePost& Left);
		friend bool operator != (DefensePost& Right, DefensePost& Left){
		  return !( Right == Left);  
		}
		bool operator == (const DefensePost& Right) const{
		  return this == &Right;  
		}
		bool operator != (const DefensePost& Right) const{
		  return this != &Right;  
		}
		DefensePost& operator=(DefensePost& other);
		
		void internalCopy(DefensePost& other);
		bool setDefenseRating(const int aNewDefenseRating);
		inline unsigned int minimumNumberOfGuards(void){
		  return 4;  
		}
		inline unsigned int maximumNumberOfGuards(void){
		  return 0;  
		}
		int getDefenseRating(void);
		vector<Soldier*>* getGuards(void);
		Soldier* getGuard(int index);
		unsigned int numberOfGuards(void);
		bool hasGuard(void);
		int indexOfGuard(Soldier* aGuard);
		bool removeGuard(Soldier* aGuard);
		bool removeGuardAt(int index);
		bool addGuard(Soldier* aNewGuard);
		bool addGuardAt(Soldier* aNewGuard, int index);
		bool addOrMoveGuardAt(Soldier* aNewGuard, int index);
		Soldier* addGuard(const string aName, Shelter* aShelter, Facility* aFacility, LivingQuarters* aLivingQuarters, MedicalBay* aMedicalBay, Mission* aMission, const int aCombatSkill);
		vector<Weapon*>* getWeapons(void);
		Weapon* getWeapon(int index);
		unsigned int numberOfWeapons(void);
		bool hasWeapon(void);
		int indexOfWeapon(Weapon* aWeapon);
		bool removeWeapon(Weapon* aWeapon);
		bool removeWeaponAt(int index);
		bool addWeapon(Weapon* aNewWeapon);
		bool addWeaponAt(Weapon* aNewWeapon, int index);
		bool addOrMoveWeaponAt(Weapon* aNewWeapon, int index);
		Weapon* addWeapon(const string aResourceId, const int aQuantity, const int aMaxCapacity, const string aUnit, SupplyBay* aSupplyBay, const int aDamageValue, const int aAmmunition, const int aMaxAmmunition);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~DefensePost();
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
    template<> struct hash<DefensePost *> {
        size_t operator()(DefensePost* ptr ) const {
            return ptr->hashCode();
        }
    };
}
#endif