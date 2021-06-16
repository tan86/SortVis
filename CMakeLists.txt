cmake_minimum_required(VERSION 3.20)
project(AV VERSION 0.0.1)

find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME} main.cc)
target_link_libraries(${PROJECT_NAME} SDL2::SDL2main SDL2::SDL2)
