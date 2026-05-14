cmake_minimum_required(VERSION 3.20)

project(rpn VERSION 0.1.0 DESCRIPTION "Reverse Polish Notation calculator" LANGUAGES CXX)

find_package(gmp REQUIRED)

add_library(rpn_lib STATIC src/rpn/rpn.cpp)
target_include_directories(rpn_lib PUBLIC include)
target_link_libraries(rpn_lib PRIVATE gmp::gmpxx)
target_compile_features(rpn_lib PRIVATE cxx_std_20)
target_compile_options(rpn_lib PRIVATE -Wall -Wextra -Wpedantic -Wunused-includes)

add_executable(rpn app/main.cpp)
target_link_libraries(rpn PRIVATE rpn_lib)
target_compile_features(rpn PRIVATE cxx_std_20)
target_compile_options(rpn PRIVATE -Wall -Wextra -Wpedantic -Wunused-includes)

