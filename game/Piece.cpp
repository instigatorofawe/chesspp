//
// Created by absox on 3/7/21.
//

#include "Piece.h"

/**
 * String representation of piece
 * @param p Piece to get string representation of
 * @return Unicode string representing piece
 */
std::string str(const Piece& p) {
    switch (p) {
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

Piece piece_from_name (const std::string &name) {
    if (name == "K") return WHITE_KING;
    if (name == "Q") return WHITE_QUEEN;
    if (name == "R") return WHITE_ROOK;
    if (name == "N") return WHITE_KNIGHT;
    if (name == "B") return WHITE_BISHOP;
    if (name == "P") return WHITE_PAWN;
    if (name == "k") return BLACK_KING;
    if (name == "q") return BLACK_QUEEN;
    if (name == "r") return BLACK_ROOK;
    if (name == "b") return BLACK_BISHOP;
    if (name == "n") return BLACK_KNIGHT;
    if (name == "p") return BLACK_PAWN;
    return INVALID;
}

Piece piece_index(const int &index) {
    switch (index) {
        case WHITE_KING:
            return WHITE_KING;
        case WHITE_QUEEN:
            return WHITE_QUEEN;
        case WHITE_ROOK:
            return WHITE_ROOK;
        case WHITE_BISHOP:
            return WHITE_BISHOP;
        case WHITE_KNIGHT:
            return WHITE_KNIGHT;
        case WHITE_PAWN:
            return WHITE_PAWN;
        case BLACK_KING:
            return BLACK_KING;
        case BLACK_QUEEN:
            return BLACK_QUEEN;
        case BLACK_ROOK:
            return BLACK_ROOK;
        case BLACK_BISHOP:
            return BLACK_BISHOP;
        case BLACK_KNIGHT:
            return BLACK_KNIGHT;
        case BLACK_PAWN:
            return BLACK_PAWN;
        case EMPTY:
            return EMPTY;
        default:
            return INVALID;
    }
}

std::ostream &operator<<(std::ostream &os, const Piece &p) {
    os << str(p);
    return os;
}




