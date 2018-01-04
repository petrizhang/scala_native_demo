cmake_minimum_required(VERSION 3.5)
project(demo_cpp)

set(CMAKE_CXX_STANDARD 11)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

include_directories($ENV{JAVA_HOME}/include
        $ENV{JAVA_HOME}/include/darwin
        $ENV{JAVA_HOME}/include/win32
        $ENV{JAVA_HOME}/include/linux)

set(NativeDemo_SOURCE_FILES NativeDemo.h NativeDemo.cpp)
add_library(NativeDemo SHARED ${NativeDemo_SOURCE_FILES})
