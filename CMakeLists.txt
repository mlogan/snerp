# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("snerp")

# Include sub-projects.
add_subdirectory ("snerp")
add_subdirectory ("third-party/SDL-mirror")
