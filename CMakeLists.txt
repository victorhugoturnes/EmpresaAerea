cmake_minimum_required(VERSION 3.13)
project(AeroTracker C)

set(CMAKE_C_STANDARD 99)

set(PROJECT_SOURCES core/Aeroporto/Aeroporto.c core/Aeronave/Aeronave.c main.c input/string.c core/Cliente/Cliente.c)
set(UI_SOURCES ui/Menu/Main/mainMenuUI.c ui/Menu/Main/Cadastros/cadastrosMenuUI.c ui/Menu/Main/Cadastros/Voo/cadastrosVooUI.c ui/Menu/Main/Cadastros/Voo/inserirVooUI.c core/Voo/VooInfo.c ui/Menu/Main/Cadastros/Cliente/cadastrosClienteUI.c ui/Menu/Main/Cadastros/Cliente/cadastrosClienteUI.h ui/Menu/Main/Cadastros/Cliente/inserirClienteUI.c ui/Menu/Main/Cadastros/Cliente/inserirClienteUI.h)

add_executable(AeroTracker ${PROJECT_SOURCES} ${UI_SOURCES})
