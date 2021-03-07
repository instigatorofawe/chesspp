//
// Created by absox on 3/6/21.
//

#include "gtest/gtest.h"
#include <tuple>
#include <iostream>
using std::tuple;
using std::cout;
using std::endl;

TEST(test_trivial, test_main) {
    ASSERT_EQ(1, 1); // Trivial assertion to make sure that our test library is importing/linking correctly.
}

TEST(test_trivial, test_tuple) {
    tuple<int, int> pos = {1, 1};
    EXPECT_EQ(std::get<0>(pos), 1);
    EXPECT_EQ(std::get<1>(pos), 1);
    auto [x, y] = pos;
    cout << x << "," << y << endl;
    EXPECT_EQ(x, 1);
    EXPECT_EQ(y, 1);
}