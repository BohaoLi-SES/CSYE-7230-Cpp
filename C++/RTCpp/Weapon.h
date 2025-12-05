//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#ifndef DEF__WEAPON_H
#define DEF__WEAPON_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "Weapon.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Weapon.h>
#include <Resource.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>

class Resource;
class Soldier;
class DefensePost;
// line 606 "model.ump"
// line 1272 "model.ump"
class Weapon : public Resource{
	
	private:
		
		//Weapon Attributes
		int damageValue;
		int ammunition;
		int maxAmmunition;
		//Weapon Associations
		// line 229 "model.ump"
		Soldier* soldier;
		// line 427 "model.ump"
		DefensePost* defensePost;
		bool exitResourceState(void);
		void setResourceState(ResourceState aResourceState);
	
	public:
		
		//------------------------
		//CONSTRUCTOR
		//------------------------
		Weapon(const string aResourceId, const int aQuantity, const int aMaxCapacity, const string aUnit, SupplyBay* aSupplyBay, const int aDamageValue, const int aAmmunition, const int aMaxAmmunition, DefensePost* aDefensePost);
		Weapon(Weapon& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const Weapon& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (Weapon& Right, Weapon& Left);
		friend bool operator != (Weapon& Right, Weapon& Left){
		  return !( Right == Left);  
		}
		bool operator == (const Weapon& Right) const{
		  return this == &Right;  
		}
		bool operator != (const Weapon& Right) const{
		  return this != &Right;  
		}
		Weapon& operator=(Weapon& other);
		
		void internalCopy(Weapon& other);
		bool setDamageValue(const int aNewDamageValue);
		bool setAmmunition(const int aNewAmmunition);
		bool setMaxAmmunition(const int aNewMaxAmmunition);
		bool setSoldier(Soldier* aNewSoldier);
		bool setDefensePost(DefensePost* aNewDefensePost);
		inline unsigned int minimumNumberOfDefensePosts(void){
		  return 1;  
		}
		int getDamageValue(void);
		int getAmmunition(void);
		int getMaxAmmunition(void);
		Soldier* getSoldier(void);
		DefensePost* getDefensePost(void);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~Weapon();
		void deleteAssociatedObjects(void);
		ResourceState getResourceState(void);
		string getResourceStateFullName(void);
		bool addLarge();
		bool addSmall();
		bool quantityZero();
		bool addAbove10();
		bool quantityBelow10();
		bool addAbove30();
		bool consume();
		bool quantityFull();
		bool quantityBelow30();
		SupplyBay* getSupplyBay(void);
		string getUnit(void);
		int getMaxCapacity(void);
		int getQuantity(void);
		string getResourceId(void);
		bool setSupplyBay(SupplyBay* aNewSupplyBay);
		bool setUnit(const string aNewUnit);
		bool setMaxCapacity(const int aNewMaxCapacity);
		bool setQuantity(const int aNewQuantity);
		bool setResourceId(const string aNewResourceId);
	
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
    template<> struct hash<Weapon *> {
        size_t operator()(Weapon* ptr ) const {
            return ptr->hashCode();
        }
    };
}
#endif