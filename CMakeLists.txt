cmake_minimum_required(VERSION 3.22.1)
project(ex-nihilo VERSION 1.0 LANGUAGES CXX)

include_directories(include)

add_executable(program src/main.cpp src/Canal.cpp src/CanalTexto.cpp src/CanalVoz.cpp src/Mensagem.cpp src/Servidor.cpp src/Sistema.cpp src/Usuario.cpp)