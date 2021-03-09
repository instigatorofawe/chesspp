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

TEST(test_data, test_set) {
    BoardBitmap map;
    map.set("a1", WHITE_ROOK);
    map.set(tuple<int, int>(1, 0), WHITE_KNIGHT);
    map.set(tuple<int, int>(6, 0), WHITE_KNIGHT);
    map.set("h8", BLACK_ROOK);
    map.set("a2", WHITE_PAWN);
    map.set("d1", WHITE_QUEEN);
    auto pieces = map.pieces();
    EXPECT_EQ(pieces[0][0].piece_type, WHITE_ROOK);
    EXPECT_EQ(pieces[7][7].piece_type, BLACK_ROOK);
    cout << map << endl;
}