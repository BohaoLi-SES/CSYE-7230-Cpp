cmake_minimum_required(VERSION 3.0)
project(model)

set(CMAKE_CXX_STANDARD 11)
include_directories(${CMAKE_SOURCE_DIR})


set(SOURCE_FILES
model_Model.h
model_Main.cpp
Shelter.h
Shelter.cpp
RadiationMonitor.h
RadiationMonitor.cpp
Survivor.h
Survivor.cpp
Leader.h
Leader.cpp
Engineer.h
Engineer.cpp
Medic.h
Medic.cpp
Soldier.h
Soldier.cpp
Children.h
Children.cpp
Facility.h
Facility.cpp
LivingQuarters.h
LivingQuarters.cpp
MedicalBay.h
MedicalBay.cpp
DefensePost.h
DefensePost.cpp
SupplyBay.h
SupplyBay.cpp
Resource.h
Resource.cpp
Food.h
Food.cpp
Water.h
Water.cpp
Medicine.h
Medicine.cpp
Energy.h
Energy.cpp
Weapon.h
Weapon.cpp
Mission.h
Mission.cpp
InternalMission.h
InternalMission.cpp
ProtectionMission.h
ProtectionMission.cpp
MaintenanceMission.h
MaintenanceMission.cpp
MedicalRescueMission.h
MedicalRescueMission.cpp
ExternalMission.h
ExternalMission.cpp
TradeMission.h
TradeMission.cpp
ExploreMission.h
ExploreMission.cpp
BattleMission.h
BattleMission.cpp
GameEventHandler.h
GameEventHandler.cpp)

add_executable(model ${SOURCE_FILES})
if (NOT MSVC)
  target_link_libraries(model pthread)
endif()