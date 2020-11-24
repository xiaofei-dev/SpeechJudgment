cmake_minimum_required(VERSION 3.17)
project(Pitch)

file(GLOB SOURCES
        *.h						//*号对应具体的文件名
        *.cpp
        *.cc
        *.c
        )

set(CMAKE_CXX_STANDARD 14)

add_executable(
        Pitch
        main.cpp
        pitch.cpp
        pitch.h
        complex_defines.h
        support_functions.cpp
        support_functions.h
        resample.cpp resample.h)