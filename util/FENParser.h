//
// Created by absox on 3/6/21.
//

#ifndef CHESS_FENPARSER_H
#define CHESS_FENPARSER_H

#include <string>
#include <vector>
#include <game/Player.h>

class Board; // Forward declared here

namespace FEN {
    Board parse(const std::string &fen);
    bool validate(const std::string &fen);
    std::string trim(const std::string &input);
    std::vector<std::string> tokenize(const std::string &input, const std::string &delimiter);
}

#endif //CHESS_FENPARSER_H
