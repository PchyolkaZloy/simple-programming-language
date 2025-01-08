#pragma once

#include <exception>
#include <string>

namespace bytecode {
    class ParserException : public std::exception {
    public:
        explicit ParserException(const std::string &message) : std::exception(message.c_str()) {}
    };

    struct TokenPosition {
        TokenPosition(const size_t &line, const size_t &symbol) : line(line), symbol(symbol) {}

    public:
        size_t line;
        size_t symbol;

        bool operator<(const TokenPosition &other) {
            if (this == &other)
                return false;
            return this->line < other.line || (this->line == other.line && this->symbol < other.symbol);
        }

        bool operator<=(const TokenPosition &other) {
            if (this == &other)
                return true;
            return this->line < other.line || (this->line == other.line && this->symbol <= other.symbol);
        }

        bool operator>(const TokenPosition &other) {
            return !(this->operator<=(other));
        };

        bool operator>=(const TokenPosition &other) {
            return !(this->operator<(other));
        };
    }
}