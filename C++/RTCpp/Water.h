//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#ifndef DEF__WATER_H
#define DEF__WATER_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "Water.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Water.h>
#include <Resource.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>

class Resource;
// line 544 "model.ump"
// line 1257 "model.ump"
class Water : public Resource{
	
	private:
		
		//Water Attributes
		double purityLevel;
		bool exitResourceState(void);
		void setResourceState(ResourceState aResourceState);
	
	public:
		
		//------------------------
		//CONSTRUCTOR
		//------------------------
		Water(const string aResourceId, const int aQuantity, const int aMaxCapacity, const string aUnit, SupplyBay* aSupplyBay, const double aPurityLevel);
		Water(Water& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const Water& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (Water& Right, Water& Left);
		friend bool operator != (Water& Right, Water& Left){
		  return !( Right == Left);  
		}
		bool operator == (const Water& Right) const{
		  return this == &Right;  
		}
		bool operator != (const Water& Right) const{
		  return this != &Right;  
		}
		Water& operator=(Water& other);
		
		void internalCopy(Water& other);
		bool setPurityLevel(double aNewPurityLevel);
		double getPurityLevel(void);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~Water();
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
    template<> struct hash<Water *> {
        size_t operator()(Water* ptr ) const {
            return ptr->hashCode();
        }
    };
}
#endif