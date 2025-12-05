//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.35.0.7523.c616a4dce modeling language
#ifndef DEF__RESOURCE_H
#define DEF__RESOURCE_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "Resource.h"
#endif
#endif

//------------------------
//FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <Resource.h>

//------------------------
//LIBRARY INCLUDES
//------------------------
using namespace std;
#include <ostream>
#include <cassert>
#include <string>

Resource_ENUM_BEGIN
class ResourceState_{

  public:
    typedef enum{RS_Sufficient=0, RS_Full=1, RS_Low=2, RS_Critical=3, RS_Depleted=4} enum_type;
    
    ResourceState_(enum_type val = RS_Sufficient): _val(val){
        assert(val <= RS_Depleted);
        }
    
        operator enum_type() const {
            return _val;
        }
        
        operator int() { 
              return static_cast<int>(_val); 
      }
      
      operator string() { 
        switch (_val){
          case RS_Sufficient: return "RS_Sufficient";
          case RS_Full: return "RS_Full";
          case RS_Low: return "RS_Low";
          case RS_Critical: return "RS_Critical";
          case RS_Depleted: return "RS_Depleted";        
          default:  return "[Unknown ENUM Type]";
      }
    }
    
  private:
      enum_type _val;
};
Resource_ENUM_END
class SupplyBay;
/*
 * ==================== Resource Management ====================
 */
// line 489 "model.ump"
// line 1120 "model.ump"
// line 1186 "model.ump"
class Resource{
	
	private:
		
		//Resource Attributes
		string resourceId;
		int quantity;
		int maxCapacity;
		string unit;
		//Resource Associations
		// line 465 "model.ump"
		SupplyBay* supplyBay;
		//Resource State Machines
		ResourceState resourceState;
		
		void setResourceState(ResourceState aResourceState);
		bool exitResourceState(void);
	
	public:
		
		//------------------------
		//CONSTRUCTOR
		//------------------------
		Resource(const string aResourceId, const int aQuantity, const int aMaxCapacity, const string aUnit, SupplyBay* aSupplyBay);
		Resource(Resource& other);
		
		//------------------------
		//STREAM HELPER GROUPDECLARATION
		//------------------------
		friend ostream& operator<<(ostream& os, const Resource& dt);
		
		//------------------------
		//PREDEFINED OPERATORS
		//------------------------
		friend bool operator == (Resource& Right, Resource& Left);
		friend bool operator != (Resource& Right, Resource& Left){
		  return !( Right == Left);  
		}
		bool operator == (const Resource& Right) const{
		  return this == &Right;  
		}
		bool operator != (const Resource& Right) const{
		  return this != &Right;  
		}
		Resource& operator=(Resource& other);
		
		void internalCopy(Resource& other);
		bool setResourceId(const string aNewResourceId);
		bool setQuantity(const int aNewQuantity);
		bool setMaxCapacity(const int aNewMaxCapacity);
		bool setUnit(const string aNewUnit);
		bool setSupplyBay(SupplyBay* aNewSupplyBay);
		inline unsigned int minimumNumberOfSupplyBaies(void){
		  return 1;  
		}
		string getResourceId(void);
		int getQuantity(void);
		int getMaxCapacity(void);
		string getUnit(void);
		SupplyBay* getSupplyBay(void);
		bool quantityBelow30();
		bool quantityFull();
		bool consume();
		bool addAbove30();
		bool quantityBelow10();
		bool addAbove10();
		bool quantityZero();
		bool addSmall();
		bool addLarge();
		string getResourceStateFullName(void);
		ResourceState getResourceState(void);
		virtual size_t hashCode(void);
		
		//------------------------
		//DESTRUCTOR
		//------------------------
		virtual ~Resource();
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
    template<> struct hash<Resource *> {
        size_t operator()(Resource* ptr ) const {
            return ptr->hashCode();
        }
    };
}
#endif