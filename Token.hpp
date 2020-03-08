#ifndef Token_hpp
#define Token_hpp

#include <stdio.h>
#include <sstream>
#include "Token_Type.hpp"

typedef TOKEN_TYPE TYPE;

struct Token{
    private:
        TYPE type;
        std::string lexeme;
        // std::pair <unsigned int, unsigned int> location;
    public:
        int64_t toInt();
        TYPE getType();
        std::string getString();
        // std::pair <unsigned int, unsigned int> getLocation();
    
    Token(TYPE type, std::string lexeme): type(type), lexeme(std::move(lexeme)) {}
};

#endif /* Token_hpp */
