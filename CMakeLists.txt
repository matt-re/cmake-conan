cmake_minimum_required(VERSION 3.20)

project(rpn VERSION 0.1.0 DESCRIPTION "Reverse Polish Notation calculator" LANGUAGES CXX)

find_package(gmp REQUIRED)

add_library(rpn_warnings INTERFACE)
target_compile_features(rpn_warnings INTERFACE cxx_std_20)
target_compile_options(rpn_warnings INTERFACE -Wall -Wextra -Wpedantic)

enable_testing()
add_subdirectory(lib/rpn)
add_subdirectory(app)
add_subdirectory(tests)
