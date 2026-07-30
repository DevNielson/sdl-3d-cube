# Cubo 3D com SDL3

Este repositório é usado para salvar o meu aprendizado em desenvolvimento de jogos 3D. Acredito que o projeto não será atualizado com devida frequência por falta de tempo, mas futuramente será mais que um simples cubo.

## O que foi usado?

- Linguagem Principal: [C++ (MSYS2)](https://www.msys2.org)
- Biblioteca Externa: [SDL3](https://github.com/libsdl-org/SDL)
- Gerador de Sistemas de Compilação: [CMake](https://cmake.org)

## Requisitos
- C++23 ou superior
- CMake 3.12 ou superior
- Makefile

## Build
Estando dentro do diretório **sdl-3d-cube**, execute os seguintes comandos no seu Terminal:

1. Executando o CMake

Se estiver usando o MSYS2

```
cmake -G "MSYS Makefiles" -S . -B ./build
```
Se estiver usando o MinGW

```
cmake -G "MinGW Makefiles" -S . -B ./build
```

2. Compilando o código fonte

```
cd ./build
make
```

3. Rodando o programa

```
.\sdl-3d-cube.exe
```