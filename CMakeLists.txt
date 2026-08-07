cmake_minimum_required(VERSION 3.16)

project(Pong)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(pong
    src/main.cpp
    src/Game.cpp
)

target_include_directories(pong PRIVATE include)

target_link_libraries(pong PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)