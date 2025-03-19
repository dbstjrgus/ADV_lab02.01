cmake_minimum_required(VERSION 3.30)
project(ADV_Lab02_01)

set(CMAKE_CXX_STANDARD 20)

add_executable(ADV_Lab02_01 main.cpp
        MorseBST.h
        MorseBST.cpp
        MorseTreeNode.h
        MorseTreeNode.cpp)
