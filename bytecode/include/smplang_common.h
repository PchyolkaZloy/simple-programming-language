#pragma once

#include <exception>
#include <string>

class ParserException : public std::exception {
public:
    explicit ParserException(const std::string &message) : std::exception(message.c_str()) {}
};

inline char* intToCharArray(int number) {
    return reinterpret_cast<char*>(number);
}