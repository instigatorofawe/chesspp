//
// Created by absox on 3/7/21.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <string>
#include <iostream>

enum PieceType {
    WHITE_PAWN = 0, WHITE_ROOK = 1, WHITE_KNIGHT = 2, WHITE_BISHOP = 3, WHITE_QUEEN = 4, WHITE_KING = 5,
    BLACK_PAWN = 6, BLACK_ROOK = 7, BLACK_KNIGHT = 8, BLACK_BISHOP = 9, BLACK_QUEEN = 10, BLACK_KING = 11,
    EMPTY = -1, INVALID = -2
};

class Piece {
public:
    Piece();
    explicit Piece(const std::string &name);
    explicit Piece(PieceType piece_type);
    [[nodiscard]] std::string str() const;

    PieceType piece_type;
    friend std::ostream &operator<<(std::ostream &os, const Piece &p);
};


#endif //CHESS_PIECE_H
