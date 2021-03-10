//
// Created by absox on 3/6/21.
//

#ifndef CHESS_FENPARSER_H
#define CHESS_FENPARSER_H

#include <string>
#include <vector>
#include <game/Player.h>
#include <game/Board.h>

class FENParser {
public:
    explicit FENParser(const std::string &fen);
    std::string pieces;
    bool white_castle_queenside;
    bool white_castle_kingside;
    bool black_castle_queenside;
    bool black_castle_kingside;
    std::tuple<int, int> en_passant; // En passant target, if one exists
    int half_counter; // Counts # of half moves since last pawn push or capture
    int full_counter; // Counts # of full moves since beginning of game
    Player active; // Whose turn it is

    static bool validate(const std::string &fen);
    static std::string trim(const std::string &input);
    static std::vector<std::string> tokenize(const std::string &input, const std::string &delimiter);
};

#endif //CHESS_FENPARSER_H
