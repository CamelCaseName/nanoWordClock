# CMakeList.txt : CMake project for nanoWordClock, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("nanoWordClock")

# Add source to this project's executable.
add_executable (nanoWordClock "nanoWordClock.cpp" "nanoWordClock.h")

# TODO: Add tests and install targets if needed.
