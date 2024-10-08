cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

# cmake package manager
include(CMake/CPM.cmake)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS YES)
set(CMAKE_FIND_PACKAGE_REDIRECTS_DIR ${CMAKE_BINARY_DIR})

# set the project name and version
project(BNS VERSION 1.0)

# add compile caching if ccache is installed on the system
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  set(CXX_COMPILER_LAUNCHER  "${CCACHE_PROGRAM}" CACHE INTERNAL "")
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
  message("Enable compiler caching")
endif()

# catch for testing
# https://github.com/catchorg/Catch2
CPMAddPackage("gh:catchorg/Catch2@3.7.1")

# Uncomment this to see how it breaks when building with Ninja
#add_subdirectory(submodules/corrade EXCLUDE_FROM_ALL)

# Uncomment this to see how it breaks when using CPM
#CPMAddPackage(NAME corrade
#  GITHUB_REPOSITORY mosra/corrade
#  GIT_TAG master
#  EXCLUDE_FROM_ALL YES)

################################################################################
# our C++ sub directories
add_subdirectory(Modules/A)
add_subdirectory(Modules/B)
