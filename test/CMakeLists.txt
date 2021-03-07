add_executable(run_tests test_trivial.cpp test_data.cpp test_omp.cpp test_game.cpp test_util.cpp)
target_link_libraries(run_tests data game util gtest gtest_main pthread)