//
// Created by absox on 3/7/21.
//

#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <util/FENParser.h>
#include <game/Board.h>

using std::cout;
using std::endl;
using std::string;

TEST(test_util, test_tokenize) {
    string x = "a,b,c,d";
    auto result = FEN::tokenize(x, ",");
    EXPECT_EQ(result.size(), 4);
    EXPECT_EQ(result[0], "a");
    EXPECT_EQ(result[1], "b");
    EXPECT_EQ(result[2], "c");
    EXPECT_EQ(result[3], "d");
}

TEST(test_util, test_trim) {
    string x = " asdf r eee";
    auto result_x = FEN::trim(x);
    EXPECT_EQ(result_x, "asdf r eee");
    string y = "  asdf r eee  ";
    auto result_y = FEN::trim(y);
    EXPECT_EQ(result_y, "asdf r eee");
}

TEST(test_util, test_fen_validate) {
    string x = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    EXPECT_EQ(FEN::validate(x), true);
}

TEST(test_util, test_fen_parse) {
    Board b = FEN::parse("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    EXPECT_TRUE(b.black_castle_queenside);
    EXPECT_TRUE(b.black_castle_kingside);
    EXPECT_TRUE(b.white_castle_queenside);
    EXPECT_TRUE(b.white_castle_kingside);
    EXPECT_EQ(b.active, WHITE);

    Board c = FEN::parse("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b - - 0 1");
    EXPECT_FALSE(c.black_castle_kingside);
    EXPECT_FALSE(c.black_castle_queenside);
    EXPECT_FALSE(c.white_castle_kingside);
    EXPECT_FALSE(c.white_castle_queenside);
    EXPECT_EQ(c.active, BLACK);

    cout << c.pieces << endl;
}