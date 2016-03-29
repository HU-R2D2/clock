cmake_minimum_required(VERSION 2.8.9)
project(clock)
find_package (Threads)

file(GLOB SOURCES "source/src/*.cpp" "source/include/*.hpp")
file(GLOB SOURCES_GTEST "source/src/*.cpp" "source/include/*.hpp" "test/*.cpp" "test/*.hpp")
list(REMOVE_ITEM SOURCES_GTEST ${CMAKE_CURRENT_SOURCE_DIR}/source/src/clock.cpp)

include_directories(
  source/googletest/include
  source/googletest)

link_directories(source/googletest/src)
ADD_LIBRARY(gtest source/googletest/src/gtest-all.cc)
ADD_LIBRARY(gtest_main source/googletest/src/gtest_main.cc)

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11" )

add_executable(clock_test ${GTEST} ${SOURCES_GTEST} ${SOURCES})
target_link_libraries(clock_test gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})