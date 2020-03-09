#ifndef Token_Type_hpp
#define Token_Type_hpp
#include <stdio.h>
enum TOKEN_TYPE{
    
    // word
    
    ABSTRUCT,          // abstruct
    CLASS,             // class
    EXTERN,            // extern
    FINAL,             // final
    IMPLEMENT,         // implement
    IMPORT,            // import
    PACKAGE,           // package
    PROTECTED,         // proctected
    PUBLIC,            // public
    STATIC,            // static
    
    // punctuation marks
    
    COMMA,              // ,
    DOT,                // .
    EXCLAMATION,        // !
    
    COLON,              // :
    SEMICOLON,          // ;
        
    QUOTATION,          // '
    
    SLASH,              // /
    RIGHT_SLANTING_BAR, // \
    
    //brackets
    
    
    // Bochen Added
    ARRAY,              // int[]
    BOOLEAN,            // boolean
    BYTE,               // byte
    CHAR,               // char
    ELSE,               // else
    FaLSE,              // false
    FOR,                // for
    INT,                // int
    IF,                 // if
    NuLL,               // null
    RETURN,             // return
    SHORT,              // short
    TrUE,               // true
    THIS,               // this
    WHILE,              // while
    TILDE,              // ~
    DOUBLEQUOTE,        // "
    AMP,                // &
    VERBAR,             // |
    AND,                // &&
    OR,                 // ||
    LSQUAREBASKET,      // [
    RSQUAREBASKET,      // ]
    ASSIGNMENT,         // =
    LT,                 // <
    GT,                 // >
    NE,                 // !=
    LE,                 // <=
    GE,                 // >=
    EQ,                 // ==
    
    MINUSEQUAL,         // -=
    PLUSEQUAL,          // +=
    STAREQUAL,          // *=
    PRECENTEQYUAL,      // %=
    SLASHEQUAL,         // /=
    LAREACOMMENT,       // /*
    RAREACOMMENT,       // */
    ARROW,              // ->
    DOUBLEPLUS,         // ++
    DOUBLEMINUS,        // --
    COMMENT,            // //
    
    
    PLUS,               // +
    MINUS,              // -
    STAR,               // *
    PRECENT,            // %
    
    LPAREN,             // (
    RPAREN,             // )
    LBRACE,             // {
    RBRACE,             // }
    
    LCOMMENT,           // /*
    RCOMMENT,           // */
    
    JAVADOC,            // /**
    INSTANCEOF,         // instanceof
    
    NUM,                // a number
    ID                  // a variable
};
#endif /* Token_Type_hpp */
