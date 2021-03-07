//
// Created by absox on 3/7/21.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <string>
#include <iostream>

enum PieceType {
    WHITE_PAWN, WHITE_ROOK, WHITE_KNIGHT, WHITE_BISHOP, WHITE_QUEEN, WHITE_KING,
    BLACK_PAWN, BLACK_ROOK, BLACK_KNIGHT, BLACK_BISHOP, BLACK_QUEEN, BLACK_KING,
    EMPTY, INVALID
};

class Piece {
public:
    Piece(const std::string& name);
    std::string fen();
    friend std::ostream &operator<<(std::ostream &os, const Piece &p);
    PieceType type;
};


#endif //CHESS_PIECE_H
