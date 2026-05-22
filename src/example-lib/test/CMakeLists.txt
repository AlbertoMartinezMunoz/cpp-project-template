add_executable(test-example-lib test-example-lib.cpp)
target_link_libraries(test-example-lib gtest gmock fff)
add_test(NAME test-example-lib COMMAND test-example-lib)
set_target_properties(test-example-lib PROPERTIES FOLDER test)
