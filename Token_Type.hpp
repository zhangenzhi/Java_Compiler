#ifndef Token_Type_hpp
#define Token_Type_hpp
#include <stdio.h>
enum TOKEN_TYPE{
    
    // word
    
    ABSTRUCT,          // abstruct
    CLASS,             // class
    EXTERNS,           // extern
    FINAL,             // final
    IMPLEMENTS,        // implements
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
    SWITCH,             // swith
    SHORT,              // short
    TrUE,               // true
    THIS,               // this
    WHILE,              // while

    AMPERSAND,          // &
    VERTICAL_BAR,       // |
    AND,                // &&
    OR,                 // ||
    
    LT,                 // <
    GT,                 // >
    NE,                 // !=
    LE,                 // <=
    GE,                 // >=
    EQ,                 // ==
    
    PLUS,               // +
    MINUS,              // -
    STAR,               // *
    PRECENT,            // %
    
    
    LBRACE,             // {
    RBRACE,             // }
    
    LCOMMENT,           // /*
    RCOMMENT,           // */
    
    JAVADOC,            // /**
    INSTANCEOF,         // instanceof
    
    NUM,                // a number
    ID,                 // a variable
};
#endif /* Token_Type_hpp */
