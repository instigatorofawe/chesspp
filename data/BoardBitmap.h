//
// Created by absox on 3/6/21.
//

#ifndef CHESS_BOARDBITMAP_H
#define CHESS_BOARDBITMAP_H

#include <array>
#include <iostream>
#include <tuple>
#include <game/Piece.h>

class BoardBitmap {
public:
    BoardBitmap() = default;
    explicit BoardBitmap(const std::string& fen);
    [[nodiscard]] std::array<std::array<bool, 8>, 8> occupancy() const;
    [[nodiscard]] std::array<std::array<Piece, 8>, 8> pieces() const;
    void set(const std::string& location, const std::string& piece);
    void set(const std::string& location, const Piece& piece);
    void set(const std::tuple<int, int> &location, const std::string& piece);
    void set(const std::tuple<int, int> &location, const Piece& piece);
    void remove(const std::string& location);
    void remove(const std::tuple<int, int> &location);
    friend std::ostream& operator<<(std::ostream& os, const BoardBitmap& b);
    static std::tuple<int, int> index(const std::string &position);
    static std::string file_name(int index);
private:
    bool state[8][8][12]{};
};


#endif //CHESS_BOARDBITMAP_H
