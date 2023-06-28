cmake_minimum_required(VERSION 3.25)
project(LRParser)

set(CMAKE_CXX_STANDARD 17)

add_executable(LRParser main.cpp src/include/SLRParser.h src/parser/SLRParser.cpp src/include/LR1Parser.h src/parser/LR1Parser.cpp)
