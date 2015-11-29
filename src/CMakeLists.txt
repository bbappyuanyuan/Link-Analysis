include_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(SALSA_m1 SALSA_m1.cpp)
target_link_libraries(SALSA_m1 lib)
add_executable(SALSA_m2 SALSA_m2.cpp)
target_link_libraries(SALSA_m2 lib)

add_executable(HITS HITS.cpp)
target_link_libraries(HITS lib)