cmake_minimum_required(VERSION 3.29)
project(testCase)

set(CMAKE_CXX_STANDARD 20)

add_executable(testCase
        Process.h
        Process.cpp
        Scheduler.h
        Scheduler.cpp)
