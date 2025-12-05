//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#ifndef DEF__MISSION_H
#define DEF__MISSION_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "Mission.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Mission.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>
#include <vector>
#include <cassert>
#include <string>

Mission_ENUM_BEGIN
class MissionState_{

  public:
    typedef enum{MS_Created=0, MS_Preparing=1, MS_Ready=2, MS_InProgress=3, MS_Completed=4, MS_Failed=5, MS_Aborted=6, MS_Cancelled=7} enum_type;
    
    MissionState_(enum_type val = MS_Created): _val(val){
        assert(val <= MS_Cancelled);
        }
    
        operator enum_type() const {
            return _val;
        }
        
        operator int() { 
              return static_cast<int>(_val); 
      }
      
      operator string() { 
        switch (_val){
          case MS_Created: return "MS_Created";
          case MS_Preparing: return "MS_Preparing";
          case MS_Ready: return "MS_Ready";
          case MS_InProgress: return "MS_InProgress";
          case MS_Completed: return "MS_Completed";
          case MS_Failed: return "MS_Failed";
          case MS_Aborted: return "MS_Aborted";
          case MS_Cancelled: return "MS_Cancelled";        
          default:  return "[Unknown ENUM Type]";
      }
    }
    
  private:
      enum_type _val;
};
Mission_ENUM_END

Mission_ENUM_BEGIN
class MissionStateMS_InProgress_{

  public:
    typedef enum{NIL=0, inProgressState=1} enum_type;
    
    MissionStateMS_InProgress_(enum_type val = NIL): _val(val){
        assert(val <= inProgressState);
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
          case inProgressState: return "inProgressState";        
          default:  return "[Unknown ENUM Type]";
      }
    }
    
  private:
      enum_type _val;
};
Mission_ENUM_END

Mission_ENUM_BEGIN
class MissionStateMS_InProgressInProgressState_{

  public:
    typedef enum{NIL=0, IP_Traveling=1, IP_Executing=2, IP_Returning=3, IP_Complete=4} enum_type;
    
    MissionStateMS_InProgressInProgressState_(enum_type val = NIL): _val(val){
        assert(val <= IP_Complete);
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
          case IP_Traveling: return "IP_Traveling";
          case IP_Executing: return "IP_Executing";
          case IP_Returning: return "IP_Returning";
          case IP_Complete: return "IP_Complete";        
          default:  return "[Unknown ENUM Type]";
      }
    }
    
  private:
      enum_type _val;
};
Mission_ENUM_END
class Survivor;
class Shelter;
class Facility;
class LivingQuarters;
class MedicalBay;
/*
 * ==================== Mission System ====================
 */
// line 639 "model.ump"
// line 1028 "model.ump"
// line 1191 "model.ump"
class Mission{
	
	private:
		
		//Mission Attributes
		string description;
		int difficulty;
		int duration;
		//Mission Associations
		/*
		 * Association
		 */
		// line 646 "model.ump"
		vector<Survivor*>* team;
		// line 11 "model.ump"
		Shelter* shelter;
		// line 646 "model.ump"
		vector<Survivor*>* survivors;
		//Mission State Machines
		MissionState missionState;
		MissionStateMS_InProgress missionStateMS_InProgress;
		MissionStateMS_InProgressInProgressState missionStateMS_InProgressInProgressState;
		
		bool exitMS_InProgress(void);
		void setMissionState(MissionState aMissionState);
		void setMS_InProgress(MissionStateMS_InProgress aMS_InProgress);
		void setInProgressState(MissionStateMS_InProgressInProgressState aInProgressState);
		bool exitMissionState(void);
		bool exitMissionStateMS_InProgress(void);
		bool exitMissionStateMS_InProgressInProgressState(void);
		bool enterMS_InProgress(void);
	
	public:
		
		//------------------------
		//CONSTRUCTOR
		//------------------------
		Mission(const string aDescription, const int aDifficulty, const int aDuration, Shelter* aShelter);
		Mission(Mission& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const Mission& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (Mission& Right, Mission& Left);
		friend bool operator != (Mission& Right, Mission& Left){
		  return !( Right == Left);  
		}
		bool operator == (const Mission& Right) const{
		  return this == &Right;  
		}
		bool operator != (const Mission& Right) const{
		  return this != &Right;  
		}
		Mission& operator=(Mission& other);
		
		void internalCopy(Mission& other);
		bool setDescription(const string aNewDescription);
		bool setDifficulty(const int aNewDifficulty);
		bool setDuration(const int aNewDuration);
		bool setShelter(Shelter* aNewShelter);
		inline unsigned int minimumNumberOfShelters(void){
		  return 1;  
		}
		string getDescription(void);
		int getDifficulty(void);
		int getDuration(void);
		vector<Survivor*>* getTeams(void);
		Survivor* getTeam(int index);
		unsigned int numberOfTeams(void);
		bool hasTeam(void);
		int indexOfTeam(Survivor* aTeam);
		bool removeTeam(Survivor* aTeam);
		bool removeTeamAt(int index);
		bool addTeam(Survivor* aNewTeam);
		bool addTeamAt(Survivor* aNewTeam, int index);
		bool addOrMoveTeamAt(Survivor* aNewTeam, int index);
		Survivor* addTeam(const string aName, Shelter* aShelter, Facility* aFacility, LivingQuarters* aLivingQuarters, MedicalBay* aMedicalBay);
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
		bool assignSurvivor();
		bool abortOrInsufficientResources();
		bool validateTeamSuccess();
		bool removeMember();
		bool start();
		bool abort();
		bool success();
		bool teamWipedOrTimeout();
		bool reachDestination();
		bool abortOrDanger();
		bool executionComplete();
		bool arriveHome();
		string getMissionStateFullName(void);
		MissionState getMissionState(void);
		MissionStateMS_InProgress getMS_InProgress(void);
		MissionStateMS_InProgressInProgressState getInProgressState(void);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~Mission();
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
    template<> struct hash<Mission *> {
        size_t operator()(Mission* ptr ) const {
            return ptr->hashCode();
        }
    };
}
#endif