#pragma once

#include <exception>
#include <string>
#include <format>

namespace bytecode {
    class ParserException : public std::exception {
    public:
        explicit ParserException(const std::string &message) : std::exception(message.c_str()) {}
    };

    struct TokenPosition {
        TokenPosition(const size_t &line, const size_t &symbol) : line(line), symbol(symbol) {}

        TokenPosition(const TokenPosition &other) = default;

        TokenPosition() = default;

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

        std::string toString() {
            return std::format("line {0} position {1}", line, symbol);
        }

    };

    class ValidatorException : public std::exception {
    public:
        explicit ValidatorException(const std::string &message) : std::exception(message.c_str()) {}

        static ValidatorException doubleDefinition(const TokenPosition &position, const std::string &name) {
            return ValidatorException(
                    std::format("name {0} redefined at line {1}, symbol {2}", name, position.line, position.symbol));
        }

        static ValidatorException unknownName(const TokenPosition &position, const std::string &name) {
            return ValidatorException(
                    std::format("name {0} unknown at line {1}, symbol {2}", name, position.line, position.symbol));
        }
    };
}