cmake_minimum_required(VERSION 3.1)

#set the project name
project(hanoichronolibray)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(../../include)

#add the executable
add_executable(asg1 asg1part2hanoirecursion.cpp)

add_executable(asg1It asg1part2hanoiiterative.cpp)


