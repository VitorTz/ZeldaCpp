cmake_minimum_required(VERSION 3.27)
project(ZeldaCpp)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5.1 COMPONENTS graphics audio)

add_executable(ZeldaCpp src/main.cpp)

target_link_libraries(ZeldaCpp sfml-graphics sfml-audio)
