cmake_minimum_required(VERSION 3.22.0)

project(Backend)
set(CMAKE_BUILD_PARALLEL_LEVEL)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions( -DBACKEND_EXPORT )
if (APPLE)
	add_definitions(-DCMAKE_APPLE_SILICON_PROCESSOR=arm64)
endif (APPLE)
#set(CMAKE_POSITION_INDEPENDENT_CODE ON)
find_package(OpenGL REQUIRED)
# boost
set(Boost_USE_STATIC_LIBS   ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost COMPONENTS system REQUIRED)

include_directories(
	${Boost_INCLUDE_DIR}
	..//imgui//
	..//Core//
	..//Base//
	..//Utilities//
	..//SerialCommander//
	..//imgui//
	..//imgui//imgui//
	..//imgui//imgui//examples//
	..//imgui//third_party/glfw/include
	..//imgui//third_party/gl3w/
	..//imgui//third_party/glm-0.9.9.6/
	${OPENGL_INCLUDE_DIRS}
 )

add_library(Backend SHARED 
	GraphicalBackend.h
	GraphicalBackend.cpp
	GraphicalBackendImpl.h
	GraphicalBackendImpl.cpp
	ContextWindow.h
	ContextWindow.cpp
	ArduinoSerialWindow.h
	ArduinoSerialWindow.cpp
	..//Base//GraphicalElement.h
	..//Base//GraphicalElement.cpp
	)

target_link_libraries(Backend PRIVATE
	Utilities
	Core
	imgui
	SerialCommander
	${OPENGL_LIBRARIES}
	${Boost_LIBRARIES}
	)

add_dependencies(Backend
	Utilities
	Core
	SerialCommander
	)
