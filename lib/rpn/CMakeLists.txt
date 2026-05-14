add_library(rpn_lib STATIC src/rpn.cpp)
target_include_directories(rpn_lib PUBLIC include)
target_link_libraries(rpn_lib PRIVATE gmp::gmpxx rpn_warnings)
