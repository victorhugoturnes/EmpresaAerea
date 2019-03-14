cmake_minimum_required(VERSION 3.13)
project(AeroTracker C)

set(CMAKE_C_STANDARD 99)

set(PROJECT_SOURCES core/Aeroporto.c core/Aeronave.c main.c input/string.c core/Usuario.c)
set(UI_SOURCES ui/mainMenuUI.c ui/cadastrosMenuUI.c ui/cadastrosVooUI.c ui/inserirVooUI.c ui/VooInfo.c)
add_executable(AeroTracker ${PROJECT_SOURCES} ${UI_SOURCES})
