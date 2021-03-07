//
// Created by absox on 3/6/21.
//

#include <omp.h>
#include "gtest/gtest.h"
#include <iostream>
using std::cout;
using std::endl;

TEST(test_omp, test_parallel) {
//    cout << omp_get_num_procs() << endl;
    omp_lock_t lock;
    omp_init_lock(&lock);
    #pragma omp parallel for default(none) shared(cout, lock)
    for (int c = 0; c < 100; c++) {
        omp_set_lock(&lock);
        cout << c << endl;
//        cout << omp_get_thread_num() << endl;
        omp_unset_lock(&lock);
    }
    cout << endl;
}