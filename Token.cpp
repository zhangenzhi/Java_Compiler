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


using namespace std;

ostream &operator<<(ostream &os, const Token & token){
    string type;
    if (token.type == ID) type = "ID";
    else if (token.type == NUM) type = "NUM";
    else if (token.type == INSTANCEOF) type = "INSTANCEOF";
    else if (token.type == RCOMMENT) type = "RCOMMENT";
    else if (token.type == LCOMMENT) type = "LCOMMENT";
    else if (token.type == RBRACE) type = "RBRACE";
    else if (token.type == LBRACE) type = "LBRACE";
    else if (token.type == RPAREN) type = "RPAREN";
    else if (token.type == LPAREN) type = "LPAREN";
    else if (token.type == PLUS) type = "PLUS";
    else if (token.type == MINUS) type = "MINUS";
    else if (token.type == STAR) type = "STAR";
    else if (token.type == PRECENT) type = "PRECENT";
    else if (token.type == COMMENT) type = "COMMENT";
    else if (token.type == DOUBLEPLUS) type = "DOUBLEPLUS";
    else if (token.type == DOUBLEMINUS) type = "DOUBLEMINUS";
    else if (token.type == ARROW) type = "ARROW";
    else if (token.type == RAREACOMMENT) type = "RAREACOMMENT";
    else if (token.type == LAREACOMMENT) type = "LAREACOMMENT";
    else if (token.type == SLASHEQUAL) type = "SLASHEQUAL";
    else if (token.type == PRECENTEQYUAL) type = "PRECENTEQYUAL";
    else if (token.type == STAREQUAL) type = "STAREQUAL";
    else if (token.type == EQ)  type = "EQ";
    else if (token.type == GE) type = "GE";
    else if (token.type == LE) type = "LE";
    else if (token.type == NE) type = "NE";
    else if (token.type == GT) type = "GT";
    else if (token.type == LT) type = "LT";
    else if (token.type == BOOLEAN) type = "BOOLEAN";
    else if (token.type == BYTE) type = "BYTE";
    else if (token.type == CHAR) type = "CHAR";
    else if (token.type == ELSE) type = "ELSE";
    else if (token.type == FaLSE) type = "FaLSE";
    else if (token.type == FOR) type = "FOR";
    else if (token.type == INT) type = "INT";
    else if (token.type == IF) type = "IF";
    else if (token.type == NuLL) type = "NuLL";
    else if (token.type == RETURN) type = "RETURN";
    else if (token.type == SHORT) type = "SHORT";
    else if (token.type == TrUE) type = "TrUE";
    else if (token.type == THIS) type = "THIS";
    else if (token.type == WHILE) type = "WHILE";
    else if (token.type == TILDE) type = "TILDE";
    else if (token.type == DOUBLEQUOTE) type = "DOUBLEQUOTE";
    else if (token.type == AMP) type = "AMP";
    else if (token.type == VERBAR) type = "VERBAR";
    else if (token.type == AND) type = "AND";
    else if (token.type == OR) type = "OR";
    else if (token.type == LSQUAREBASKET) type = "LSQUAREBASKET";
    else if (token.type == RSQUAREBASKET) type = "RSQUAREBASKET";
    else if (token.type == ASSIGNMENT) type = "ASSIGNMENT";
    
    os << "( " << type << ", " << token.lexeme << " )" << endl;
    return os;
    
}

// (JAVADOC, /**) this is not implemented
