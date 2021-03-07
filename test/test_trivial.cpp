//
// Created by absox on 3/6/21.
//

#include "gtest/gtest.h"
#include <iostream>
using std::cout;
using std::endl;

TEST(test_trivial, test_main) {
    ASSERT_EQ(1, 1); // Trivial assertion to make sure that our test library is importing/linking correctly.
}