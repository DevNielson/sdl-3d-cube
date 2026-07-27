cmake_minimum_required(VERSION 4.2.3)

project("sdl-3d-cube" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
    "src/game.cpp"
    "src/main.cpp"
    "src/object.cpp"
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_include_directories(${PROJECT_NAME} PRIVATE "external/SDL3/x86_64-w64-mingw32/include")
# target_link_directories(${PROJECT_NAME} PRIVATE "external/SDL3/x86_64-w64-mingw32/lib")
find_package(SDL3)
target_link_libraries(project_target PRIVATE SDL3::SDL3)
