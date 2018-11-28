# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("snerp")

include_directories ("third-party/SDL-mirror/include/${CMAKE_CURRENT_SOURCE_DIR}")

# Include sub-projects.
add_subdirectory ("third-party/SDL-mirror")
add_subdirectory ("snerp")