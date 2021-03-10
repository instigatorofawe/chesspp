//
// Created by absox on 3/6/21.
//

#include "FENParser.h"
#include <algorithm>
#include <stdexcept>

/**
 * Builds a parser for a FEN string.
 * @param fen string to parse.
 */
FENParser::FENParser(const std::string &fen) {
    // TODO
}

/**
 * Validates FEN string
 * @param fen string to validate
 * @return true if valid, false if not.
 */
bool FENParser::validate(const std::string &fen) {
    // Components: board, turn, castling, en passant, halfmove, fullmove
    static std::array<char, 12> pieces{'K', 'Q', 'R', 'B', 'N', 'P', 'k', 'q', 'r', 'b', 'n', 'p'};
    static std::array<char, 4> castle{'K','Q','k','q'};
    static std::array<char, 8> file_chars{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    static std::array<char, 8> rank_chars{'1','2','3','4','5','6','7','8'};
    auto input = trim(fen);
    // 6 fields in total delimited by spaces
    auto fields = tokenize(input, " ");
    if (fields.size() != 6) return false;
    auto ranks = tokenize(fields[0], "/");
    // Board needs to have 8 ranks
    if (ranks.size() != 8) return false;
    for (const auto& r : ranks) {
        int rank_value = 0;
        for (auto c : r) {
            if (isdigit(c)) {
                rank_value += c - '0';
            }  else {
                rank_value++;
                // Only characters specified in pieces are permitted when specifying board
                if (std::find(pieces.begin(), pieces.end(), c) == pieces.end()) return false;
            }
        }
        // Each rank needs to have 8 pieces or spaces
        if (rank_value != 8) return false;
    }
    // Player turn should be either w or b
    if (fields[1] != "w" && fields[1] != "b") return false;
    // Castling availability should be - if neither player can castle; otherwise containing 'K', 'Q', 'k', 'q'
    if (fields[2] != "-") {
        if (fields[2].empty() || fields[2].size() > 4) return false;
        for (auto c : fields[2]) {
            if (std::find(castle.begin(), castle.end(), c) == castle.end()) return false;
        }
    }
    // En passant target square in algebraic notation
    if (fields[3] != "-" && (fields[3].size() != 2 ||
    (std::find(file_chars.begin(), file_chars.end(), fields[3][0]) == file_chars.end() ||
    std::find(rank_chars.begin(), rank_chars.end(), fields[3][1]) == rank_chars.end()))) return false;

    // Halfmove clock should be a number equal to or greater than zero
    // Fullmove clock should be a number equal to or greater than 1
    try {
        if (std::stoi(fields[4]) < 0) return false;
        if (std::stoi(fields[5]) < 1) return false;
    } catch (std::invalid_argument &e) {
        return false;
    }

    // If all tests are passed, then the string is valid
    return true;
}

/**
 * Tokenizes a string
 * @param input String to tokenize
 * @param delimiter Delimiter
 * @return Vector of tokens
 */
std::vector<std::string> FENParser::tokenize(const std::string &input, const std::string &delimiter) {
    auto result = std::vector<std::string>();
    // Working copy of the input that we can modify
    auto working = input;
    int position = 0;
    while ((position = working.find(delimiter)) != std::string::npos) {
        result.push_back(working.substr(0, position));
        working.erase(0, position + delimiter.length());
    }
    result.push_back(working);
    return result;
}

// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void inline_trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

/**
 * Trims a string of leading and trailing whitespace
 * @param input string to trim
 * @return Trimmed string
 */
std::string FENParser::trim(const std::string &input) {
    auto result = input;

    auto start_index = std::find_if(result.begin(), result.end(), [](unsigned char c) {
        return !std::isspace(c);
    });
    // If any non-whitespace is found, we should compute the substring
    if (start_index != result.end()) {
        inline_trim(result);
        return result;
    }
    // If only whitespace is in the string, return an empty string
    return std::string();
}

