cmake_minimum_required(VERSION 3.16)
project(.)

set(CMAKE_CXX_STANDARD 14)

add_executable(OSLab2 Server.cpp
        RequestParser.cpp
        main.cpp
        MainController.cpp)