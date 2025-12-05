//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#ifndef DEF__MEDICALRESCUEMISSION_H
#define DEF__MEDICALRESCUEMISSION_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "MedicalRescueMission.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <MedicalRescueMission.h>
#include <InternalMission.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>

class InternalMission;
// line 760 "model.ump"
// line 1292 "model.ump"
class MedicalRescueMission : public InternalMission{
	
	private:
		
		//MedicalRescueMission Attributes
		int casualties;
		bool enterMS_InProgress(void);
		bool exitMissionStateMS_InProgressInProgressState(void);
		bool exitMissionStateMS_InProgress(void);
		bool exitMissionState(void);
		void setInProgressState(MissionStateMS_InProgressInProgressState aInProgressState);
		void setMS_InProgress(MissionStateMS_InProgress aMS_InProgress);
		void setMissionState(MissionState aMissionState);
		bool exitMS_InProgress(void);
	
	public:
		
		//------------------------
		//CONSTRUCTOR
		//------------------------
		MedicalRescueMission(const string aDescription, const int aDifficulty, const int aDuration, Shelter* aShelter, const string aPriority, Facility* aTargetFacility, const int aCasualties);
		MedicalRescueMission(MedicalRescueMission& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const MedicalRescueMission& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (MedicalRescueMission& Right, MedicalRescueMission& Left);
		friend bool operator != (MedicalRescueMission& Right, MedicalRescueMission& Left){
		  return !( Right == Left);  
		}
		bool operator == (const MedicalRescueMission& Right) const{
		  return this == &Right;  
		}
		bool operator != (const MedicalRescueMission& Right) const{
		  return this != &Right;  
		}
		MedicalRescueMission& operator=(MedicalRescueMission& other);
		
		void internalCopy(MedicalRescueMission& other);
		bool setCasualties(const int aNewCasualties);
		int getCasualties(void);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~MedicalRescueMission();
		void deleteAssociatedObjects(void);
		MissionStateMS_InProgressInProgressState getInProgressState(void);
		MissionStateMS_InProgress getMS_InProgress(void);
		MissionState getMissionState(void);
		string getMissionStateFullName(void);
		bool arriveHome();
		bool executionComplete();
		bool abortOrDanger();
		bool reachDestination();
		bool teamWipedOrTimeout();
		bool success();
		bool abort();
		bool start();
		bool removeMember();
		bool validateTeamSuccess();
		bool abortOrInsufficientResources();
		bool assignSurvivor();
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
		Survivor* addTeam(const string aName, Shelter* aShelter, Facility* aFacility, LivingQuarters* aLivingQuarters, MedicalBay* aMedicalBay);
		bool addOrMoveTeamAt(Survivor* aNewTeam, int index);
		bool addTeamAt(Survivor* aNewTeam, int index);
		bool addTeam(Survivor* aNewTeam);
		bool removeTeamAt(int index);
		bool removeTeam(Survivor* aTeam);
		int indexOfTeam(Survivor* aTeam);
		bool hasTeam(void);
		unsigned int numberOfTeams(void);
		Survivor* getTeam(int index);
		vector<Survivor*>* getTeams(void);
		int getDuration(void);
		int getDifficulty(void);
		string getDescription(void);
		bool setShelter(Shelter* aNewShelter);
		bool setDuration(const int aNewDuration);
		bool setDifficulty(const int aNewDifficulty);
		bool setDescription(const string aNewDescription);
		Facility* getTargetFacility(void);
		string getPriority(void);
		bool setTargetFacility(Facility* aNewTargetFacility);
		bool setPriority(const string aNewPriority);
	
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
    template<> struct hash<MedicalRescueMission *> {
        size_t operator()(MedicalRescueMission* ptr ) const {
            return ptr->hashCode();
        }
    };
}
#endif