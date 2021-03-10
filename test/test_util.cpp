//
// Created by absox on 3/7/21.
//

#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <util/FENParser.h>
using std::cout;
using std::endl;
using std::string;

TEST(test_util, test_tokenize) {
    string x = "a,b,c,d";
    auto result = FENParser::tokenize(x, ",");
    EXPECT_EQ(result.size(), 4);
    EXPECT_EQ(result[0], "a");
    EXPECT_EQ(result[1], "b");
    EXPECT_EQ(result[2], "c");
    EXPECT_EQ(result[3], "d");
}

TEST(test_util, test_trim) {
    string x = " asdf r eee";
    auto result_x = FENParser::trim(x);
    EXPECT_EQ(result_x, "asdf r eee");
    string y = "  asdf r eee  ";
    auto result_y = FENParser::trim(y);
    EXPECT_EQ(result_y, "asdf r eee");
}

TEST(test_util, test_fen_validate) {
    string x = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    EXPECT_EQ(FENParser::validate(x), true);
}