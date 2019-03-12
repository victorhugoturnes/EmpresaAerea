cmake_minimum_required(VERSION 3.13)
project(untitled C)

set(CMAKE_C_STANDARD 99)

set(PROJECT_SOURCES core/Aeroporto.c core/Aeronave.c "main.c" "input/string.c")
add_executable(untitled ${PROJECT_SOURCES})
