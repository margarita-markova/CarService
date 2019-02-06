cmake_minimum_required(VERSION 3.13)
project(AutoService)

set(CMAKE_CXX_STANDARD 11)

add_executable(AutoService main.cpp Headers/Auto.h Auto.cpp Headers/Wheel.h AutoParts/Wheel.cpp Headers/Steering.h AutoParts/Steering.cpp Headers/Brake.h AutoParts/Brake.cpp Headers/FuelSystem.h AutoParts/FuelSystem.cpp Headers/Headlights.h AutoParts/Headlights.cpp Tools/Utils.cpp Headers/Utils.h AutoService.cpp Headers/AutoService.h)