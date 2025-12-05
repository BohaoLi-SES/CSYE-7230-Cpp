//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#ifndef DEF__MEDICINE_H
#define DEF__MEDICINE_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "Medicine.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Medicine.h>
#include <Resource.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>

class Resource;
// line 565 "model.ump"
// line 1262 "model.ump"
class Medicine : public Resource{
	
	private:
		
		//Medicine Attributes
		string medicineType;
		bool exitResourceState(void);
		void setResourceState(ResourceState aResourceState);
	
	public:
		
		//------------------------
		//CONSTRUCTOR
		//------------------------
		Medicine(const string aResourceId, const int aQuantity, const int aMaxCapacity, const string aUnit, SupplyBay* aSupplyBay, const string aMedicineType);
		Medicine(Medicine& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const Medicine& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (Medicine& Right, Medicine& Left);
		friend bool operator != (Medicine& Right, Medicine& Left){
		  return !( Right == Left);  
		}
		bool operator == (const Medicine& Right) const{
		  return this == &Right;  
		}
		bool operator != (const Medicine& Right) const{
		  return this != &Right;  
		}
		Medicine& operator=(Medicine& other);
		
		void internalCopy(Medicine& other);
		bool setMedicineType(const string aNewMedicineType);
		string getMedicineType(void);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~Medicine();
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
    template<> struct hash<Medicine *> {
        size_t operator()(Medicine* ptr ) const {
            return ptr->hashCode();
        }
    };
}
#endif