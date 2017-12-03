cmake_minimum_required(VERSION 3.8)
project(SampleSubc)

set(CMAKE_CXX_STANDARD 11)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../../bin)

include_directories($ENV{JAVA_HOME}/include
        $ENV{JAVA_HOME}/include/darwin
        $ENV{JAVA_HOME}/include/win32
        $ENV{JAVA_HOME}/include/linux)


set(MutiMatrix_SOURCE_FILES MutiMatrix.h MutiMatrix.cpp)
add_library(MutiMatrix SHARED ${MutiMatrix_SOURCE_FILES})

set(OwnMath_SOURCE_FILES OwnMath.h OwnMath.cpp)
add_library(OwnMath SHARED ${OwnMath_SOURCE_FILES})