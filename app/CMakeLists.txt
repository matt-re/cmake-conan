add_executable(rpn main.cpp)
target_link_libraries(rpn PRIVATE rpn_lib rpn_warnings)
set_target_properties(rpn PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

add_test(NAME add COMMAND rpn 1 2 +)
set_tests_properties(add PROPERTIES PASS_REGULAR_EXPRESSION "^3")

add_test(NAME sub COMMAND rpn 5 3 -)
set_tests_properties(sub PROPERTIES PASS_REGULAR_EXPRESSION "^2")

add_test(NAME mul COMMAND rpn 4 3 *)
set_tests_properties(mul PROPERTIES PASS_REGULAR_EXPRESSION "^12")

add_test(NAME div COMMAND rpn 10 2 /)
set_tests_properties(div PROPERTIES PASS_REGULAR_EXPRESSION "^5")
