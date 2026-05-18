add_executable(rpn_lib_tests test_rpn.cpp)
target_link_libraries(rpn_lib_tests PRIVATE rpn_lib rpn_warnings)
add_test(NAME lib_gmp_tests COMMAND rpn_lib_tests)
