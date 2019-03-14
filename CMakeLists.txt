cmake_minimum_required(VERSION 3.13)
project(AeroTracker C)

set(CMAKE_C_STANDARD 99)

set(PROJECT_SOURCES core/Aeroporto/Aeroporto.c core/Aeronave/Aeronave.c main.c input/string.c core/Usuario/Usuario.c)
set(UI_SOURCES ui/Menu/Main/MenuMain.c ui/Menu/Main/Cadastros/MenuCadastros.c ui/Menu/Main/Cadastros/VooCadastro/VooCadastros.c ui/Menu/Main/Cadastros/VooCadastro/VooInserir/VooInserir.c core/Voo/VooInfo.c)
add_executable(AeroTracker ${PROJECT_SOURCES} ${UI_SOURCES})
