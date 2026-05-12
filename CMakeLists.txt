cmake_minimum_required(VERSION 3.20)

project(rpn VERSION 0.1.0 DESCRIPTION "Reverse Polish Notation calculator" LANGUAGES CXX)

add_executable(rpn)

target_sources(rpn PRIVATE src/main.cpp src/rpn/rpn.cpp)
target_include_directories(rpn PRIVATE include)
target_compile_features(rpn PRIVATE cxx_std_20)
target_compile_options(rpn PRIVATE -Wall -Wextra -Wpedantic)

