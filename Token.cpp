#include "Token.hpp"

int64_t Token::toInt(){
    std::istringstream iss;
    int64_t result;
    
    if (type == TYPE::NUM) {
        iss.str(lexeme);
        iss >> result;
        
        if (lexeme[0] == '-'){
            if (result < -2147483648) throw "ERROR: OVERFLOW, numeric literal out of range" ;
        } else {
            if (result > 2147483647) throw "ERROR: OVERFLOW, numeric literal out of range";
        }
        return result;
    } else {
        throw "ERROR: not an integer token" + lexeme;
    }
}

TOKEN_TYPE Token::getType()
{
    return this->type;
}

std::string Token::getString()
{
    return this->lexeme;
}

