cmake_minimum_required(VERSION 3.20)
project(Automate_Welding_Program C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_definitions(-DAUTOMATE_WELDING_SIMULATE -DAUTOMATE_WELDING_DEBUG)

add_executable(Automate_Welding_Program main.c fsm_welding.c fsm_welding.h)
