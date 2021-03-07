//
// Created by absox on 3/6/21.
//

#include "Board.h"

/**
 * Constructs a board from Forsyth-Edwards notation
 * @param fen Forsyth-Edwards notation representation of board state
 */
Board::Board(const std::string &fen) {

}

/**
 * Default constructor initializes board from starting position.
 */
Board::Board() : Board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1") {

}
