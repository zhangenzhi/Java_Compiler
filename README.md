# JAVAComplier
The implementation a compilers for Java-like languages (Joos 1w)
* [PART I: Scanning, Parsing, Weeding, AST Building ](https://github.com/bochendong/JAVAComplier#part-i-scanning-parsing-weeding-ast-building)
* [PART II: Name Resolution](https://github.com/bochendong/JAVAComplier#part-ii-name-resolution)
* [PART III: Type Checking](https://github.com/bochendong/JAVAComplier#part-iii-type-checking)
* [PART IV: Static Analysis](https://github.com/bochendong/JAVAComplier#part-iv-static-analysis)
* [PART V: Code Generation](https://github.com/bochendong/JAVAComplier#part-v-code-generation)
* [APPENDIX](https://github.com/bochendong/JAVAComplier#appendix)
* [Schedule](https://github.com/bochendong/JAVAComplier#schedule)
## PART I: Scanning, Parsing, Weeding, AST Building 

The Token struct is defined as:
```cpp
struct Token{
    TOKEN_TYPE type;
    std::string lexeme;
}
```
Where TYPE is enumerated in this table:
[TOKEN TYPE](https://github.com/bochendong/JAVAComplier/blob/master/README.md#token-type)

## PART II: Name Resolution

## PART III: Type Checking

## PART IV: Static Analysis

## PART V: Code Generation 

## APPENDIX:
#### TOKEN TYPE:
```cpp
enum TOKEN_TYPE{
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
    COMMA,              // ,
    DOT,                // .
    EXCLAMATION,        // !
    COLON,              // :
    SEMICOLON,          // ;  
    QUOTATION,          // '
    SLASH,              // /
    RIGHT_SLANTING_BAR, // \
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
    ID                  // a variable
};
```
## SCHEDULE
|                | Start date      | Due Date       |
| :------------- | :-------------: | -------------: |
| PART I         | March 6         | April 4        |
| PART II        | April 5         | April 23       |
| PART III       | April 24        | May 1          |
| PART IV        | May 2           | May 9          |
| PART V         | May 9           | June 1         |

#### 1.0.0.1 MARCH 6, 2020
Create token structure and tokentype

