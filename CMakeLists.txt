cmake_minimum_required(VERSION 3.3)
project(link_analysis)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(LIB_FILES lib/UnionSet.cpp lib/UnionSet.h lib/Graph.cpp lib/Graph.h)

add_executable(SALSA_m1 ${LIB_FILES} SALSA/main_m1.cpp)
add_executable(SALSA_m2 ${LIB_FILES} SALSA/main_m2.cpp)

add_executable(HITS ${LIB_FILES} HITS/main.cpp)