//
// Created by absox on 3/6/21.
//

#include "BoardBitmap.h"
#include <algorithm>
using std::get;

/**
 * Converts board position in algebraic notation (e.g. a1 through h8) to a tuple that indexes
 * @param position String to convert into an index
 * @return Position of
 */
std::tuple<int, int> BoardBitmap::index(const std::string &position) {
    // Convert position to lowercase
    std::string lower = std::string(position);
    std::transform(lower.begin(), lower.end(), lower.begin(), [](unsigned char c) -> unsigned char {
        return std::tolower(c);
    });

    int x = lower[0] - 'a';
    int y = lower[1] - '0' - 1;
    return {x,y};
}

std::array<std::array<bool, 8>, 8> BoardBitmap::occupancy() {
    auto result = std::array<std::array<bool, 8>, 8>();
    #pragma omp parallel for collapse(2) default(none) shared(result)
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            bool occupied = false;

            #pragma omp simd reduction(||:occupied)
            for (int k = 0; k < 12; k++) {
                occupied = occupied || state[i][j][k];
            }

            result[i][j] = occupied;
        }
    }
    return result;
}

std::array<std::array<Piece, 8>, 8> BoardBitmap::pieces() {
    return std::array<std::array<Piece, 8>, 8>();
}

void BoardBitmap::set(const std::tuple<int, int> &location, const std::string &piece) {
    // TODO
}

void BoardBitmap::set(const std::tuple<int, int> &location, const Piece &piece) {
    // TODO
}
