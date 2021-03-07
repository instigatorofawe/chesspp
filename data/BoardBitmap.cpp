//
// Created by absox on 3/6/21.
//

#include "BoardBitmap.h"
#include <algorithm>
using std::get;

/**
 * Converts board position in algebraic notation (e.g. a1 through h8) to an index on the 1D state array
 * @param position String to convert into an index
 * @return Integer index
 */
int BoardBitmap::index(const std::string &position) {
    // Convert position to lowercase
    std::string lower = std::string(position);
    std::transform(lower.begin(), lower.end(), lower.begin(), [](unsigned char c) -> unsigned char {
        return std::tolower(c);
    });

    int x = lower[0] - 'a';
    int y = lower[1] - '0' - 1;
    return index(std::tuple<int, int>{x, y});
}

/**
 * Converts a tuple into a position
 * @param position
 * @return
 */
int BoardBitmap::index(const std::tuple<int, int> &position) {
    // Row ordering
    return get<0>(position) * 8 + get<1>(position);
}
