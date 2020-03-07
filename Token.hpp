#ifndef Token_hpp
#define Token_hpp

#include <stdio.h>
#include <sstream>
#include "Token_Type.hpp"

typedef TOKEN_TYPE TYPE;

struct Token{
    TYPE type;
    std::string lexeme;
    
    int64_t toInt();
    Token(TYPE type, std::string lexeme): type(type), lexeme(std::move(lexeme)) {}
};

#endif /* Token_hpp */
