//
// Created by absox on 3/6/21.
//

#include "gtest/gtest.h"
#include <bitset>
#include <iostream>
#include <data/BoardBitmap.h>

using std::bitset;
using std::cout;
using std::endl;
using std::tuple;

TEST(test_data, test_bitarray) {
    std::bitset<8> x;
    cout << x << endl;
}

TEST(test_data, test_index) {
    EXPECT_EQ(BoardBitmap::index("a1"), 0);
    EXPECT_EQ(BoardBitmap::index("A1"), 0);
    EXPECT_EQ(BoardBitmap::index("B1"), 8);
}
