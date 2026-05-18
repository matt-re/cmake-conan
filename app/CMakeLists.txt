add_executable(rpn main.cpp)
target_link_libraries(rpn PRIVATE rpn_lib rpn_warnings)
set_target_properties(rpn PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
