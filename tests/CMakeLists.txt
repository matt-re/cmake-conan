add_executable(rpn_lib_tests test_rpn.cpp)
target_link_libraries(rpn_lib_tests PRIVATE rpn_lib rpn_warnings)
add_test(NAME lib_gmp_tests COMMAND rpn_lib_tests)

add_test(NAME add COMMAND $<TARGET_FILE:rpn> 1 2 +)
set_tests_properties(add PROPERTIES PASS_REGULAR_EXPRESSION "^3")

add_test(NAME sub COMMAND $<TARGET_FILE:rpn> 5 3 -)
set_tests_properties(sub PROPERTIES PASS_REGULAR_EXPRESSION "^2")

add_test(NAME mul COMMAND $<TARGET_FILE:rpn> 4 3 *)
set_tests_properties(mul PROPERTIES PASS_REGULAR_EXPRESSION "^12")

add_test(NAME div COMMAND $<TARGET_FILE:rpn> 10 2 /)
set_tests_properties(div PROPERTIES PASS_REGULAR_EXPRESSION "^5")
