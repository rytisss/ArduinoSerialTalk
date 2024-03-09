cmake_minimum_required(VERSION 3.17.0)

project(SerialCommander)
set(CMAKE_BUILD_PARALLEL_LEVEL)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions( -DSERIALCOMMANDER_EXPORT )
if (APPLE)
	add_definitions( -DCMAKE_APPLE_SILICON_PROCESSOR=arm64 )
endif(APPLE)
# boost
set(Boost_USE_STATIC_LIBS   ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.79.0 COMPONENTS system REQUIRED)

include_directories(
	${OpenCV_INCLUDE_DIRS}
	${Boost_INCLUDE_DIR}
 )

add_library(SerialCommander SHARED 
	SerialCommander.h
	SerialCommander.cpp)

target_link_libraries(SerialCommander PRIVATE
	${Boost_LIBRARIES})
