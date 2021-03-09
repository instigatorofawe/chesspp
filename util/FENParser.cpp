//
// Created by absox on 3/6/21.
//

#include "FENParser.h"
#include <algorithm>

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
    // TODO
    return false;
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
        auto end_index = std::find_if(result.rbegin(), result.rend(), [](unsigned char c) {
            return !std::isspace(c);
        });
        return result.substr(std::distance(result.begin(), start_index),
                             result.length() - std::distance(result.rbegin(), end_index) - 1);
    }
    // If only whitespace is in the string, return an empty string
    return std::string();
}
