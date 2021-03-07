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
    explicit Piece(PieceType piece_type);
    [[nodiscard]] std::string str() const;

    PieceType piece_type;
    friend std::ostream &operator<<(std::ostream &os, const Piece &p);
};


#endif //CHESS_PIECE_H
