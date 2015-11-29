cmake_minimum_required(VERSION 3.3)
project(link_analysis)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(LIB_FILES lib/UnionSet.cpp lib/UnionSet.h lib/Graph.cpp lib/Graph.h)

set(SALSA_FILES ${LIB_FILES} SALSA/main.cpp)
add_executable(SALSA ${SALSA_FILES} SALSA/main.cpp)

set(HITS_FILES ${LIB_FILES} HITS/main.cpp)
add_executable(HITS ${HITS_FILES} HITS/main.cpp)