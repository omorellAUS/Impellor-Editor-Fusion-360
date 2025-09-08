cmake_minimum_required(VERSION 3.15)
project(Impellor VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_executable(Impellor main.cpp)

target_link_libraries(Impellor PRIVATE fmt::fmt spdlog::spdlog)