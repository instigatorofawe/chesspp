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

Piece::Piece(const std::string &name) {
    piece_type = INVALID;
    if (name == "K") piece_type = WHITE_KING;
    if (name == "Q") piece_type = WHITE_QUEEN;
    if (name == "R") piece_type = WHITE_ROOK;
    if (name == "N") piece_type = WHITE_KNIGHT;
    if (name == "B") piece_type = WHITE_BISHOP;
    if (name == "P") piece_type = WHITE_PAWN;
    if (name == "k") piece_type = BLACK_KING;
    if (name == "q") piece_type = BLACK_QUEEN;
    if (name == "r") piece_type = BLACK_ROOK;
    if (name == "b") piece_type = BLACK_BISHOP;
    if (name == "n") piece_type = BLACK_KNIGHT;
    if (name == "p") piece_type = BLACK_PAWN;
}

Piece::Piece() {
    piece_type = EMPTY;
}




