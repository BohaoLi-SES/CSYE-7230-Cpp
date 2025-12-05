//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#ifndef DEF__ENERGY_H
#define DEF__ENERGY_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "Energy.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Energy.h>
#include <Resource.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>

class Resource;
// line 582 "model.ump"
// line 1267 "model.ump"
class Energy : public Resource{
	
	private:
		
		//Energy Attributes
		int powerOutput;
		bool exitResourceState(void);
		void setResourceState(ResourceState aResourceState);
	
	public:
		
		//------------------------
		//CONSTRUCTOR
		//------------------------
		Energy(const string aResourceId, const int aQuantity, const int aMaxCapacity, const string aUnit, SupplyBay* aSupplyBay, const int aPowerOutput);
		Energy(Energy& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const Energy& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (Energy& Right, Energy& Left);
		friend bool operator != (Energy& Right, Energy& Left){
		  return !( Right == Left);  
		}
		bool operator == (const Energy& Right) const{
		  return this == &Right;  
		}
		bool operator != (const Energy& Right) const{
		  return this != &Right;  
		}
		Energy& operator=(Energy& other);
		
		void internalCopy(Energy& other);
		bool setPowerOutput(const int aNewPowerOutput);
		int getPowerOutput(void);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~Energy();
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
    template<> struct hash<Energy *> {
        size_t operator()(Energy* ptr ) const {
            return ptr->hashCode();
        }
    };
}
#endif