//
// Created by absox on 3/6/21.
//

#include "BoardBitmap.h"
#include <algorithm>
#include <util/FENParser.h>

using std::get;

/**
 * Converts board position in algebraic notation (e.g. a1 through h8) to a tuple that indexes
 * @param position String to convert into a tuple
 * @return Position Tuple position
 */
std::tuple<int, int> BoardBitmap::index(const std::string &position) {
    // Convert position to lowercase
    std::string lower = std::string(position);
    std::transform(lower.begin(), lower.end(), lower.begin(), [](unsigned char c) -> unsigned char {
        return std::tolower(c);
    });
    // Somewhat dangerous as we have no range checking at all.
    int x = lower[0] - 'a';
    int y = lower[1] - '0' - 1;
    return {x,y};
}

/**
 * Computes occupancy matrix of board
 * @return 8 by 8 array of booleans, true if space is occupied, false if empty
 */
std::array<std::array<bool, 8>, 8> BoardBitmap::occupancy() const {
    auto result = std::array<std::array<bool, 8>, 8>();
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            bool occupied = false;

            #pragma omp simd reduction(||:occupied)
            for (int k = 0; k < 12; k++) occupied = occupied || state[i][j][k];

            result[i][j] = occupied;
        }
    }
    return result;
}

/**
 * Computes 2d array of pieces on board
 * @return 8 by 8 array of Pieces
 */
std::array<std::array<Piece, 8>, 8> BoardBitmap::pieces() const {
    // Apparently the best way to initialize an array to a single nonzero value requires template metaprogramming
    std::array<std::array<Piece, 8>, 8> result{};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // This doesn't require templates, but we lose a bit of performance unless the compiler is smart
            result[i][j] = EMPTY;
            for (int k = 0; k < 12; k++) {
                if (state[i][j][k]) {
                    result[i][j] = piece_index(k);
                }
            }
        }
    }
    return result;
}

/**
 * Sets piece on location
 * @param location Location on board to set
 * @param piece FEN string representation of piece to set
 */
void BoardBitmap::set(const std::tuple<int, int> &location, const std::string &piece) {
    set(location, piece_from_name(piece));
}

/**
 * Sets piece on location
 * @param location Location on board to set
 * @param piece Piece to set
 */
void BoardBitmap::set(const std::tuple<int, int> &location, const Piece &piece) {
    int x = get<0>(location);
    int y = get<1>(location);
    #pragma omp simd
    for (int c = 0; c < 12; c++) state[x][y][c] = false;
    state[x][y][piece] = true;
}

void BoardBitmap::set(const std::string &location, const std::string &piece) {
    set(index(location), piece_from_name(piece));
}

void BoardBitmap::set(const std::string &location, const Piece &piece) {
    set(index(location), piece);
}

/**
 * Prints the board to an output stream
 * @param os Output stream to print to
 * @param b Board to print
 * @return Output stream that was printed to
 */
std::ostream &operator<<(std::ostream &os, const BoardBitmap &b) {
    auto pieces = b.pieces();
    os << "  ";
    for (int j = 0; j < 8; j++) os << BoardBitmap::file_name(j);
    os << std::endl;
    os << "  --------" << std::endl;
    for (int i = 7; i >= 0; i--) {
        os << i+1 << "|";
        for (int j = 0; j < 8; j++) {
            os << pieces[j][i];
        }
        os << "|" << i+1;
        os << std::endl;
    }
    os << "  --------" << std::endl;
    os << "  ";
    for (int j = 0; j < 8; j++) os << BoardBitmap::file_name(j);
    os << std::endl;
    return os;
}

/**
 * Returns the letter name of a file (column on the board)
 * @param index Index of file
 * @return Name of file
 */
std::string BoardBitmap::file_name(int index) {
    return std::string(1, 'a' + index);
}

void BoardBitmap::remove(const std::string &location) {
    remove(index(location));
}

void BoardBitmap::remove(const std::tuple<int, int> &location) {
    int x = get<0>(location);
    int y = get<1>(location);
    #pragma omp simd
    for (int c = 0; c < 12; c++) state[x][y][c] = false;
}

