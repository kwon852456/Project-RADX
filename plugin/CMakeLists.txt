cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
#gazebo package
find_package(gazebo REQUIRED)

# Ros package
find_package(roscpp REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(${GAZEBO_INCLUDE_DIRS})

#Ros directories
include_directories(${roscpp_INCLUDE_DIRS})
include_directories(${std_msgs_INCLUDE_DIRS})

link_directories(${GAZEBO_LIBRARY_DIRS})
list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

add_library(rad_plugin SHARED rad_plugin.cc)

target_link_libraries(rad_plugin ${GAZEBO_LIBRARIES})

#Ros publisher lib
target_link_libraries(rad_plugin ${GAZEBO_LIBRARIES} ${roscpp_LIBRARIES})



#for application with gazebo publisher
#target_link_libraries(vel ${GAZEBO_LIBRARIES})












