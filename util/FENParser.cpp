//
// Created by absox on 3/6/21.
//

#include "FENParser.h"
#include <algorithm>
#include <stdexcept>
#include <game/Board.h>

/**
 * Validates FEN string
 * @param fen string to validate
 * @return true if valid, false if not.
 */
bool FEN::validate(const std::string &fen) {
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
std::vector<std::string> FEN::tokenize(const std::string &input, const std::string &delimiter) {
    auto result = std::vector<std::string>();
    // Working copy of the input that we can modify
    auto working = input;
    int position;
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
std::string FEN::trim(const std::string &input) {
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

/**
 * Parses a FEN string into a board state
 * @param fen String to parse
 * @return Board object, initialized to state represented in FEN
 */
Board FEN::parse(const std::string &fen) {
    Board result;

    auto fields = tokenize(fen, " ");
    auto ranks = tokenize(fields[0], "/");

    // Field 1: pieces on board
    for (int c = 0; c < 8; c++) {
        // We begin on the 8th rank, and work our way back
        int rank = 7 - c;
        // We begin on the a file, and work our way to the right.
        int file = 0;
        for (const char& piece : ranks[c]) {
            // If it's numeric, it symbolizes the number of spaces we skip
            if (std::isdigit(piece)) {
                auto num_spaces = piece - '0';
                file += num_spaces;
            } else {
                switch(piece) {
                    case 'K':
                        result.pieces.set(std::tuple<int, int>{file, rank}, WHITE_KING);
                        break;
                    case 'Q':
                        result.pieces.set(std::tuple<int, int>{file, rank}, WHITE_QUEEN);
                        break;
                    case 'R':
                        result.pieces.set(std::tuple<int, int>{file, rank}, WHITE_ROOK);
                        break;
                    case 'B':
                        result.pieces.set(std::tuple<int, int>{file, rank}, WHITE_BISHOP);
                        break;
                    case 'N':
                        result.pieces.set(std::tuple<int, int>{file, rank}, WHITE_KNIGHT);
                        break;
                    case 'P':
                        result.pieces.set(std::tuple<int, int>{file, rank}, WHITE_PAWN);
                        break;
                    case 'k':
                        result.pieces.set(std::tuple<int, int>{file, rank}, BLACK_KING);
                        break;
                    case 'q':
                        result.pieces.set(std::tuple<int, int>{file, rank}, BLACK_QUEEN);
                        break;
                    case 'r':
                        result.pieces.set(std::tuple<int, int>{file, rank}, BLACK_ROOK);
                        break;
                    case 'b':
                        result.pieces.set(std::tuple<int, int>{file, rank}, BLACK_BISHOP);
                        break;
                    case 'n':
                        result.pieces.set(std::tuple<int, int>{file, rank}, BLACK_KNIGHT);
                        break;
                    case 'p':
                        result.pieces.set(std::tuple<int, int>{file, rank}, BLACK_PAWN);
                        break;
                    default:
                        break;
                }
                file++;
            }
        }
    }
    // Field 2: active color
    if (fields[1] == "w") result.active = WHITE;
    if (fields[1] == "b") result.active = BLACK;

    // Field 3: castling availability
    for (const char& c : fields[2]) {
        switch(c) {
            case 'K':
                result.white_castle_kingside = true;
                break;
            case 'Q':
                result.white_castle_queenside = true;
                break;
            case 'k':
                result.black_castle_kingside = true;
                break;
            case 'q':
                result.black_castle_queenside = true;
            default:
                break;
        }
    }
    // Field 4: en passant target
    // TODO
    // Field 5: halfmove clock
    // TODO
    // Field 6: fullmove clock
    // TODO

    return result;
}

