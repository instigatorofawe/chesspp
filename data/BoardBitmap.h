//
// Created by absox on 3/6/21.
//

#ifndef CHESS_BOARDBITMAP_H
#define CHESS_BOARDBITMAP_H

#include <vector>
#include <iostream>
#include <tuple>
#include <game/Piece.h>

class BoardBitmap {
public:
    std::vector<bool> occupancy();
    std::vector<Piece> pieces();
    void set(const std::tuple<int, int> &location, const std::string& piece);
    void set(const std::tuple<int, int> &location, const Piece& piece);
    friend std::ostream& operator<<(std::ostream& os, const BoardBitmap& b);
    static int index(const std::tuple<int, int> &position);
    static int index(const std::string &position);
private:
    bool state[8][8][13];
};


#endif //CHESS_BOARDBITMAP_H
