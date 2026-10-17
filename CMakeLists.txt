cmake_minimum_required(VERSION 3.28)
project(APS)

set(CMAKE_CXX_STANDARD 20)

add_executable(APS main.cpp
        Vaje/Starosti.cpp
        Vaje/Inverzije/Inverzije.cpp
        Pred/Pred3/Pred3.cpp
)
