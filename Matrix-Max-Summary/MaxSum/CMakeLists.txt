cmake_minimum_required(VERSION 2.8.9)
project(MaxSum)

include_directories(Include)
 
file(GLOB SOURCES "src/*.c")
 
add_executable(MaxSum ${SOURCES})  



