//
// Created by absox on 3/6/21.
//

#ifndef CHESS_BOARDBITMAP_H
#define CHESS_BOARDBITMAP_H

#include <bitset>
#include <iostream>
#include <tuple>
#include <game/Piece.h>

class BoardBitmap {
public:
    std::bitset<64> occupancy();
    void set(const std::tuple<int, int> &location, const std::string& piece);
    void set(const std::tuple<int, int> &location, const Piece& piece);
    friend std::ostream& operator<<(std::ostream& os, const BoardBitmap& b);
    static int index(const std::tuple<int, int> &position);
private:
    std::bitset<64> white_pawn;
    std::bitset<64> white_rook;
    std::bitset<64> white_knight;
    std::bitset<64> white_bishop;
    std::bitset<64> white_queen;
    std::bitset<64> white_king;
    std::bitset<64> black_pawn;
    std::bitset<64> black_rook;
    std::bitset<64> black_knight;
    std::bitset<64> black_bishop;
    std::bitset<64> black_queen;
    std::bitset<64> black_king;
};


#endif //CHESS_BOARDBITMAP_H
