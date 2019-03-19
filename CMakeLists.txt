cmake_minimum_required(VERSION 3.13)
project(AeroTracker C)

set(CMAKE_C_STANDARD 99)

set(PROJECT_SOURCES core/Aeroporto/Aeroporto.c core/Aeronave/Aeronave.c main.c input/string.c core/Usuario/Usuario.c)
set(UI_SOURCES ui/Menu/Main/mainMenuUI.c ui/Menu/Main/Cadastros/cadastrosMenuUI.c ui/Menu/Voos/cadastrosVooUI.c ui/Menu/Voos/inserirVooUI.c core/Voo/VooInfo.c)

add_executable(AeroTracker ${PROJECT_SOURCES} ${UI_SOURCES})
