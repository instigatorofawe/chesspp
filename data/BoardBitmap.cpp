//
// Created by absox on 3/6/21.
//

#include "BoardBitmap.h"
using std::get;

std::ostream &operator<<(std::ostream &os, const BoardBitmap &b) {
    // TODO
    return os;
}

void BoardBitmap::set(const std::tuple<int, int> &location, const std::string &piece) {
    Piece current_piece(piece);
    this->set(location, current_piece);
}

void BoardBitmap::set(const std::tuple<int, int> &location, const Piece &piece) {

}

std::bitset<64> BoardBitmap::occupancy() {
    std::bitset<64> result;

    for (int c = 0; c < 64; c++) {
        result[c] = white_pawn[c] || white_rook[c] || white_knight[c] || white_bishop[c] || white_king[c] ||
                white_queen[c] || black_pawn[c] || black_rook[c] || black_knight[c] || black_bishop[c] ||
                black_king[c] || black_queen[c];
    }

    return result;
}

int BoardBitmap::index(const std::tuple<int, int> &position) {
    return get<0>(position) * 8 + get<1>(position);
}



