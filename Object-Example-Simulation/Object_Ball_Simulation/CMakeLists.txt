cmake_minimum_required(VERSION 2.8.9)
project(ObjectExample)

include_directories(Include)
 
file(GLOB SOURCES "src/*.cpp")
 
add_executable(ObjectExample ${SOURCES})  
