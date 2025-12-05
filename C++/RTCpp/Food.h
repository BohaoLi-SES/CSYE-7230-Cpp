//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#ifndef DEF__FOOD_H
#define DEF__FOOD_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "Food.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Food.h>
#include <Resource.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>

class Resource;
// line 524 "model.ump"
// line 1252 "model.ump"
class Food : public Resource{
	
	private:
		
		//Food Attributes
		int expirationDays;
		bool exitResourceState(void);
		void setResourceState(ResourceState aResourceState);
	
	public:
		
		//------------------------
		//CONSTRUCTOR
		//------------------------
		Food(const string aResourceId, const int aQuantity, const int aMaxCapacity, const string aUnit, SupplyBay* aSupplyBay, const int aExpirationDays);
		Food(Food& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const Food& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (Food& Right, Food& Left);
		friend bool operator != (Food& Right, Food& Left){
		  return !( Right == Left);  
		}
		bool operator == (const Food& Right) const{
		  return this == &Right;  
		}
		bool operator != (const Food& Right) const{
		  return this != &Right;  
		}
		Food& operator=(Food& other);
		
		void internalCopy(Food& other);
		bool setExpirationDays(const int aNewExpirationDays);
		int getExpirationDays(void);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~Food();
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
    template<> struct hash<Food *> {
        size_t operator()(Food* ptr ) const {
            return ptr->hashCode();
        }
    };
}
#endif