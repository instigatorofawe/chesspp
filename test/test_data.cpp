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
    map.set("h1", WHITE_ROOK);
    map.set(tuple<int, int>(1, 0), "N");
    map.set(tuple<int, int>(6, 0), WHITE_KNIGHT);
    map.set("a2", WHITE_PAWN);
    map.set("b2", WHITE_PAWN);
    map.set("c2", WHITE_PAWN);
    map.set("d2", WHITE_PAWN);
    map.set("e2", WHITE_PAWN);
    map.set("f2", WHITE_PAWN);
    map.set("g2", WHITE_PAWN);
    map.set("h2", WHITE_PAWN);
    map.set("c1", WHITE_BISHOP);
    map.set("f1", WHITE_BISHOP);
    map.set("d1", WHITE_QUEEN);
    map.set("e1", WHITE_KING);

    map.set("h8", BLACK_ROOK);
    map.set("a8", "r");
    map.set("b8", "n");
    map.set("g8", "n");
    map.set("c8", "b");
    map.set("f8", "b");
    map.set("e8", "k");
    map.set("d8", "q");
    map.set(tuple<int, int>{0, 6}, BLACK_PAWN);
    map.set(tuple<int, int>{1, 6}, BLACK_PAWN);
    map.set(tuple<int, int>{2, 6}, BLACK_PAWN);
    map.set(tuple<int, int>{3, 6}, BLACK_PAWN);
    map.set(tuple<int, int>{4, 6}, BLACK_PAWN);
    map.set(tuple<int, int>{5, 6}, BLACK_PAWN);
    map.set(tuple<int, int>{6, 6}, BLACK_PAWN);
    map.set(tuple<int, int>{7, 6}, BLACK_PAWN);

    auto pieces = map.pieces();
    EXPECT_EQ(pieces[0][0], WHITE_ROOK);
    EXPECT_EQ(pieces[7][0], WHITE_ROOK);
    EXPECT_EQ(pieces[7][7], BLACK_ROOK);
    EXPECT_EQ(pieces[0][7], BLACK_ROOK);
    cout << map << endl;
}