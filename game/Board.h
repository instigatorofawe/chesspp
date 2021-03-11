//
// Board class; uses piece-centric bitboard approach, as this representation is suitable for convolutional neural nets.
// See https://www.chessprogramming.org/Board_Representation for further information.
// Created by absox on 3/6/21.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <vector>
#include <string>
#include <tuple>
#include "Player.h"
#include <util/FENParser.h>
#include "data/BoardBitmap.h"

class Board {
public:
    // Default constructor initializes board from starting position
    Board() = default;
    static Board starting_position();

    std::string fen();
    bool valid(const std::string &move);
    Board do_move(const std::string &move);
    Board do_move(const std::tuple<int, int> &origin, const std::tuple<int, int> &destination);
    std::vector<std::string> moves();

    friend Board FEN::parse(const std::string &fen);

    // Bitmap representation of pieces
    BoardBitmap pieces{};
    // Whether castling is legal
    bool white_castle_queenside;
    bool white_castle_kingside;
    bool black_castle_queenside;
    bool black_castle_kingside;
    std::tuple<int, int> en_passant; // En passant target, if one exists
    int half_counter; // Counts # of half moves since last pawn push or capture
    int full_counter; // Counts # of full moves since beginning of game
    Player active; // Whose turn it is
};


#endif //CHESS_BOARD_H
