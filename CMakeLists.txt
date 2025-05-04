cmake_minimum_required(VERSION 3.10)

project(xgreety VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable debug symbols by default
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Add compiler flags for warnings and debugging
add_compile_options(-Wall -Wextra -Wpedantic -g)

# Find required packages
find_package(Curses REQUIRED)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CURSES_INCLUDE_DIR})

# Source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Define executable
add_executable(xgreety ${SOURCES})

# Link libraries
target_link_libraries(xgreety ${CURSES_LIBRARIES})

# Installation support
install(TARGETS xgreety DESTINATION bin)

# Optionally, set installation directory for AUR packages (if needed)
set(CMAKE_INSTALL_PREFIX "/usr/local")

