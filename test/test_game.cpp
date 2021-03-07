//
// Created by absox on 3/7/21.
//

#include "gtest/gtest.h"
#include <iostream>
#include <game/Piece.h>

using std::cout;
using std::endl;

TEST(test_game, test_piece) {
    Piece p(WHITE_ROOK);
    EXPECT_EQ(p.str(), "♖");
}