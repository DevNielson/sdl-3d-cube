cmake_minimum_required(VERSION 4.2.3)

project("sdl-3d-cube" LANGUAGES CXX)

# set(CMAKE_MAKE_PROGRAM "C:/msys64/usr/bin/make.exe")
# set(CMAKE_C_COMPILER "C:/msys64/ucrt64/bin/gcc.exe")
# set(CMAKE_CXX_COMPILER "C:/msys64/ucrt64/bin/g++.exe")
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

add_executable(${PROJECT_NAME} src/test.cpp)
