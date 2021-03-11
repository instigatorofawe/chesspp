//
// Created by absox on 3/6/21.
//

#include "Board.h"
#include "util/FENParser.h"

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
    // TODO
    return false;
}

/**
 * Initializes a board to the standard starting position.
 * @return Board initialized to the standard starting position.
 */
Board Board::starting_position() {
    return FEN::parse("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}

/**
 * Gets list of legal moves in the current position
 * @return Vector of strings of legal moves in algebraic notation
 */
std::vector<std::string> Board::moves() {
    // TODO
    return std::vector<std::string>();
}

/**
 * Returns the board which results from doing a move
 * @param origin Square to move from
 * @param destination Square to move to
 * @return Resulting board
 */
Board Board::do_move(const std::tuple<int, int> &origin, const std::tuple<int, int> &destination) {
    // TODO
    return Board();
}

