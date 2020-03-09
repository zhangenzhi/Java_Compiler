# JAVAComplier
The implementation of a compilers for Java-like languages (Joos 1w)
* [PART I: Scanning, Parsing, Weeding, AST Building ](https://github.com/bochendong/JAVAComplier#part-i-scanning-parsing-weeding-ast-building)
* [PART II: Name Resolution](https://github.com/bochendong/JAVAComplier#part-ii-name-resolution)
* [PART III: Type Checking](https://github.com/bochendong/JAVAComplier#part-iii-type-checking)
* [PART IV: Static Analysis](https://github.com/bochendong/JAVAComplier#part-iv-static-analysis)
* [PART V: Code Generation](https://github.com/bochendong/JAVAComplier#part-v-code-generation)
* [APPENDIX](https://github.com/bochendong/JAVAComplier#appendix)
* [SCHEDULE](https://github.com/bochendong/JAVAComplier#schedule)
## PART I: Scanning, Parsing, Weeding, AST Building 

#### Part I is consisted by 4 parts:
* [Scanning](https://github.com/bochendong/JAVAComplier#--scanning)
* [Parsing](https://github.com/bochendong/JAVAComplier#--parsing)
* [Weeding](https://github.com/bochendong/JAVAComplier#--weeding)
* [AST Building](https://github.com/bochendong/JAVAComplier#--ast-building)

#### After this part, the following restrictions of the Joos 1W language can be checked:
* All characters in the input program must be in the range of 7-bit ASCII (0 to 127).
* Literal is within the range of a Java int.
* A class cannot be both abstract and final.
* A method has a body if and only if it is neither abstract nor native.
* An abstract method cannot be static or final.
* A static method cannot be final.
* A native method must be static.
* The type void may only be used as the return type of a method.
* A formal parameter of a method must not have an initializer.
* A class/interface must be declared in a .java file with the same base name as the class/interface.
* An interface cannot contain fields or constructors.
* An interface method cannot be static, final, or native.
* An interface method cannot have a body.
* Every class must contain at least one explicit constructor.
* No field can be final.
* No multidimensional array types or multidimensional array creation expressions are allowed.
* A method or constructor must not contain explicit this() or super() calls.

### - Scanning
#### 1. Token
The Token struct is defined as:
```cpp
struct Token{
    TOKEN_TYPE type;
    string lexeme;
};
```
Where TYPE is enumerated in this table:
[TOKEN TYPE](https://github.com/bochendong/JAVAComplier/blob/master/README.md#token-type)

And a overide output function is implemented, for example:
```cpp
Token * t = new Token(AMP,"&");
cout << *t <<endl;

// Output: ( AMP, & )
```
#### 2. Prefix tire
A prefix tire is created which contians all keywords in joos1w, it has the following structure:
```cpp
struct Node{
    std::vector <Node *> node_list;
    std::string State;
    
    Node(std::string state){ State = state;}
    void insert_Node(char c, std::string state);
};

struct Root{
    Node * root;
    
    Root(){
        root = new Node ("START");
        for (int i = 0; i < 128; i ++) root->node_list.push_back(new Node("INVAILD"));
    }
    void Build(std::vector <std::string> words);
};
```
And this prefix tire contains any vaild path leads to a vaild keyword.
#### 3. DFA
THE DFA graph is showed in this link:[DFA GRAPH](https://github.com/bochendong/JAVAComplier/blob/master/dfa.drawio)

### - Parsing

### - Weeding

### - AST Building

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

### 1.0.0.1 - Create token MARCH 6, 2020
Create token structure and tokentype
### 1.0.0.2 - Create DFA structure MARCH 7, 2020
Create superclass and add previate field and public function for DFA.

Create a prefix tire structure
### 1.0.0.4 - Create OperatorDFA structure MARCH 8, 2020
Create a subclass of DFA which is called opreate_DFA, this DFA can recognize tokens as follows:
```cpp
/*
1. Separators
    ( ) { } [ ] ; , .  ::
2. Operator:
    ~ : =  >  <  !  +  -  *  /  &  |   %
        == >= <= != += -= *= /= &= |=  %= \
                ++ --           && ||
                   ->
3. " '
4. \* \\ * /
5. Identifiers:
    Has pattern {&,_,A-Z,a-z}.* + {&,_,A-Z,a-z,0-9}.*
6. Integer Numbers:
    Has pattern {0-9}.*
*/
```
### 1.0.0.3 - Add overide output function for token MARCH 9, 2020
