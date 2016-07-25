cmake_minimum_required (VERSION 2.8)

project(MyProject)

# ${CMAKE_CURRENT_SOURCE_DIR} and ${CMAKE_CURRENT_BINARY_DIR} added to the include path for this directory.
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

# INCLUDE_DIRECTORIES Add the given directories to those the compiler uses to search for include files.
include_directories(${Qt5Widgets_INCLUDE_DIRS})

add_definitions(${Qt5Widgets_DEFINITIONS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
set(QT_LIBRARIES ${Qt5Widgets_LIBRARIES})


find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

# Add repertory src/
include_directories(src)
add_subdirectory(src)




