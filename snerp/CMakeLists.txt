# CMakeList.txt : CMake project for snerp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (snerp WIN32 
  "console.cpp" "console.h" 
  "snerp.cpp" "snerp.h")
target_link_libraries(snerp SDL2main SDL2-static)

# TODO: Add tests and install targets if needed.
