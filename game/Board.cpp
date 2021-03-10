//
// Created by absox on 3/6/21.
//

#include "Board.h"
#include "util/FENParser.h"

/**
 * Constructs a board from Forsyth-Edwards notation
 * @param fen Forsyth-Edwards notation representation of board state
 */
Board::Board(const std::string &fen) {
    FENParser parser(fen);
}

/**
 * Generates FEN string representation of board state.
 * @return
 */
std::string Board::fen() {
    // TODO
    return std::string();
}

/**
 * Returns the board which results from doing a move.
 * @param move String representation of move to do.
 * @return Board which results.
 */
Board Board::do_move(const std::string &move) {
    // TODO
    return Board();
}

/**
 * Determines whether or not a move is valid
 * @param move String representation of move to check.
 * @return true if valid, false if not.
 */
bool Board::valid(const std::string &move) {
    return false;
}

