cmake_minimum_required(VERSION 3.3)
project(link_analysis)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Boost Library
set(BOOST_ROOT "/usr/local/Cellar/boost/1.59.0")
find_package(Boost COMPONENTS system filesystem REQUIRED)
if (NOT Boost_FOUND)
    message(FATAL_ERROR "Boost not found")
endif ()
include_directories(${Boost_INCLUDE_DIRS})

# My Library
include_directories(lib)

# Executable
add_executable(HITS src/HITS.cpp)
target_link_libraries(HITS ${Boost_LIBRARIES})

add_executable(SALSA src/SALSA.cpp)
target_link_libraries(SALSA ${Boost_LIBRARIES})
