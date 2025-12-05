//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#ifndef DEF__MEDIC_H
#define DEF__MEDIC_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "Medic.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Medic.h>
#include <Survivor.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>

class Survivor;
// line 191 "model.ump"
// line 1217 "model.ump"
class Medic : public Survivor{
	
	private:
		
		//Medic Attributes
		int medicalSkill;
		bool exitBehaviorState(void);
		bool exitMentalState(void);
		bool exitRadiationState(void);
		bool exitPhysicalState(void);
		void setBehaviorState(BehaviorState aBehaviorState);
		void setMentalState(MentalState aMentalState);
		void setRadiationState(RadiationState aRadiationState);
		void setPhysicalState(PhysicalState aPhysicalState);
	
	public:
		
		//------------------------
		//CONSTRUCTOR
		//------------------------
		Medic(const string aName, Shelter* aShelter, Facility* aFacility, LivingQuarters* aLivingQuarters, MedicalBay* aMedicalBay, Mission* aMission, const int aMedicalSkill);
		Medic(Medic& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const Medic& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (Medic& Right, Medic& Left);
		friend bool operator != (Medic& Right, Medic& Left){
		  return !( Right == Left);  
		}
		bool operator == (const Medic& Right) const{
		  return this == &Right;  
		}
		bool operator != (const Medic& Right) const{
		  return this != &Right;  
		}
		Medic& operator=(Medic& other);
		
		void internalCopy(Medic& other);
		bool setMedicalSkill(const int aNewMedicalSkill);
		int getMedicalSkill(void);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~Medic();
		void deleteAssociatedObjects(void);
		BehaviorState getBehaviorState(void);
		string getBehaviorStateFullName(void);
		MentalState getMentalState(void);
		string getMentalStateFullName(void);
		RadiationState getRadiationState(void);
		string getRadiationStateFullName(void);
		PhysicalState getPhysicalState(void);
		string getPhysicalStateFullName(void);
		bool recoveryComplete();
		bool healingComplete();
		bool enterLivingQuarters();
		bool enterMedicalBay();
		bool restComplete();
		bool injuredDuringMission();
		bool missionComplete();
		bool healthStateWorsened();
		bool urgentMissionCall();
		bool removeFromFacility();
		bool cannotWork();
		bool manualRest();
		bool assignToMission();
		bool assignToFacility();
		bool noIntervention24h();
		bool forceIntervention();
		bool moraleCritical();
		bool therapyAndTime();
		bool moraleVeryLowOrRepeatedTrauma();
		bool restAndPositiveEvent();
		bool moraleLowOrTrauma();
		bool radiationFull();
		bool intensiveTreatment();
		bool untreatedTick();
		bool radiationAbove70();
		bool radAwayBelow30();
		bool radiationAbove30();
		bool treatRadiationToZero();
		bool increaseRadiation();
		bool healthZero();
		bool emergencySurgery();
		bool healthBelow20();
		bool treatmentAbove50();
		bool healAndRestAbove80();
		bool takeDamageBelow50();
		bool takeDamageAbove50();
		Mission* getMission(void);
		MedicalBay* getMedicalBay(void);
		LivingQuarters* getLivingQuarter(void);
		Facility* getFacility(void);
		bool addOrMoveChildrenAt(Children* aNewChildren, int index);
		bool addChildrenAt(Children* aNewChildren, int index);
		bool addChildren(Children* aNewChildren);
		bool removeChildrenAt(int index);
		bool removeChildren(Children* aChildren);
		int indexOfChildren(Children* aChildren);
		bool hasChildren(void);
		unsigned int numberOfChildrens(void);
		Children* getChildren(int index);
		vector<Children*>* getChildrens(void);
		Shelter* getShelter(void);
		bool addOrMoveAssignedMissionAt(Mission* aNewAssignedMission, int index);
		bool addAssignedMissionAt(Mission* aNewAssignedMission, int index);
		bool addAssignedMission(Mission* aNewAssignedMission);
		bool removeAssignedMissionAt(int index);
		bool removeAssignedMission(Mission* aAssignedMission);
		int indexOfAssignedMission(Mission* aAssignedMission);
		bool hasAssignedMission(void);
		unsigned int numberOfAssignedMissions(void);
		Mission* getAssignedMission(int index);
		vector<Mission*>* getAssignedMissions(void);
		Facility* getCurrentLocation(void);
		int getRadiationLevel(void);
		int getHealth(void);
		string getName(void);
		bool setMission(Mission* aNewMission);
		bool setMedicalBay(MedicalBay* aNewMedicalBay);
		bool setLivingQuarter(LivingQuarters* aNewLivingQuarter);
		bool setFacility(Facility* aNewFacility);
		bool setShelter(Shelter* aNewShelter);
		bool setCurrentLocation(Facility* aNewCurrentLocation);
		bool setRadiationLevel(const int aNewRadiationLevel);
		bool setHealth(const int aNewHealth);
		bool setName(const string aNewName);
	
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
    template<> struct hash<Medic *> {
        size_t operator()(Medic* ptr ) const {
            return ptr->hashCode();
        }
    };
}
#endif