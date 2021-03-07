add_executable(run_tests test_trivial.cpp test_data.cpp)
target_link_libraries(run_tests gtest gtest_main pthread)