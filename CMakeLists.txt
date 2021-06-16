cmake_minimum_required(VERSION 3.20)
project(SV VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -fexceptions")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "${CMAKE_CXX_FLAGS} -pg")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall -Wextra")
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME} main.cc src/sortvis.cc)
target_include_directories(${PROJECT_NAME} PRIVATE includes)
target_link_libraries(${PROJECT_NAME} SDL2::SDL2main SDL2::SDL2)
