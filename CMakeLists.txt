cmake_minimum_required(VERSION 3.29)
project(testCase)

set(CMAKE_CXX_STANDARD 20)
file(GLOB SOURCES "*.cpp" "*.h")

add_executable(testCase ${SOURCES})