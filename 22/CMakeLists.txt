cmake_minimum_required (VERSION 3.8)

project (problem_22)
add_executable(problem_22 problem_22.cpp)

# GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Boost
find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS}) 

target_link_libraries(problem_22
    ${GTEST_BOTH_LIBRARIES}
    ${Boost_SYSTEM_LIBRARY}
)

set_property(TARGET problem_22 PROPERTY CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
