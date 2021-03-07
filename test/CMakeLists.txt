#set(CMAKE_CXX_FLAGS -fopenmp)
add_executable(run_tests test_trivial.cpp test_data.cpp test_omp.cpp)
target_link_libraries(run_tests gtest gtest_main pthread)