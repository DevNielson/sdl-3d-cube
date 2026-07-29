cmake_minimum_required(VERSION 3.12)
project("sdl-3d-cube" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "./src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        "./include"
        "./external/SDL3/x86_64-w64-mingw32/include"
)

target_link_directories(${PROJECT_NAME} PRIVATE "./external/SDL3/x86_64-w64-mingw32/lib")

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        SDL3
        stdc++exp
)