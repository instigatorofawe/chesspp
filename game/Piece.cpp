//
// Created by absox on 3/7/21.
//

#include "Piece.h"

/**
 * Constructs a piece object
 * @param piece_type Type of piece
 */
Piece::Piece(PieceType piece_type) {
    this->piece_type = piece_type;
}

/**
 * Writes string representation to an output stream
 * @param os Stream to write to
 * @param p Piece to write
 * @return Stream written to
 */
std::ostream &operator<<(std::ostream &os, const Piece &p) {
    os << p.str();
    return os;
}

/**
 * String representation of piece
 * @return Unicode string representing piece
 */
std::string Piece::str() const {
    switch (this->piece_type) {
        case WHITE_KING:
            return "♔";
        case WHITE_QUEEN:
            return "♕";
        case WHITE_ROOK:
            return "♖";
        case WHITE_BISHOP:
            return "♗";
        case WHITE_KNIGHT:
            return "♘";
        case WHITE_PAWN:
            return "♙";
        case BLACK_KING:
            return "♚";
        case BLACK_QUEEN:
            return "♛";
        case BLACK_ROOK:
            return "♜";
        case BLACK_BISHOP:
            return "♝";
        case BLACK_KNIGHT:
            return "♞";
        case BLACK_PAWN:
            return "♟";
        case EMPTY:
            return " ";
        default:
            return "";
    }
}




