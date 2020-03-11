#include "DFA.hpp"

using namespace std;
void Node::insert_Node(char c, std::string state){
       if (node_list.empty()){
           for (int i = 0; i < 128; i ++) node_list.push_back(new Node("INVAILD"));
       } else {
           if (node_list[c]->State == "INVAILD"){
               node_list[c] = new Node(state);
           }
       }
   }
//std::string Node::check_node_list(std::string s){
//    std::string checked_state;
//    
//}

void DFARoot::Build(vector<string> words){
    while (!words.empty()){
        Node * curnode = root;
        string word = words.back();
        words.pop_back();
        
        unsigned long int len = word.length();
        for (unsigned long int i = 0; i < len ; i++){
            char c = word[i];
            cout << "insert " << c << endl;
            curnode->insert_Node(c, "Touched");
            curnode = curnode->node_list[c];
        }
    }
}


bool is_NUM (char c){
    return '0' <= c && c <= '9';
}

bool is_ALPHA (char c){
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}
bool single_char_op (char c){
    if ( c == '(' || c == ')' || c == '{' || c == '}' || c == ',' || c == ';' || c == '~' ||
         c == '"' || c == 39  || c == '[' || c == ']'){ // 39 is '
        return true;
    } else {
        return false;
    }
}

/*
 This DFA should be able to recoginize tokens as follow:
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


void opreate_DFA::update_token (std::string s){
    unsigned long int len = s.length();
    Token * t = nullptr;
    int curState = INVAILD;
    
    for (unsigned long int i = 0; i < len ; i++){
        char c = s[i];
        /* Handle the first character */
        if ( i == 0 ){
            if( is_ALPHA(c) || c == '_' || c == '$' ) curState = STATE_ID;
            else if ( is_NUM(c) ) curState = STATE_NUM;
            else {
                curState = STATE_OP;
                if (single_char_op(c)){
                    if (c == '(') t = new Token(TOKEN_TYPE::LPAREN, "(");
                    else if (c == ')') t = new Token(TOKEN_TYPE::RPAREN, ")");
                    else if (c == '{') t = new Token(TOKEN_TYPE::LBRACE, "{");
                    else if (c == '}') t = new Token(TOKEN_TYPE::RBRACE, "}");
                    else if (c == ',') t = new Token(TOKEN_TYPE::COMMA, ",");
                    else if (c == '.') t = new Token(TOKEN_TYPE::DOT, ".");
                    else if (c == ';') t = new Token(TOKEN_TYPE::SEMICOLON, ";");
                    else if (c == '~') t = new Token(TOKEN_TYPE::TILDE, "~");
                    else if (c == '[') t = new Token(TOKEN_TYPE::LSQUAREBASKET, "[");
                    else if (c == ']') t = new Token(TOKEN_TYPE::RSQUAREBASKET, "]");
                    else if (c == '"') t = new Token(TOKEN_TYPE::DOUBLEQUOTE, "\"");
                    else if (c == ':') t = new Token(TOKEN_TYPE::COLON, ":");
                    tokens.push_back(t);
                    
                    if (len >= 1) {
                        opreate_DFA::update_token(s.substr(1));
                        return ;
                    }
                }
            }
        }
        /* Handle the rest of the string */
        else {
            if ( curState == STATE_ID ){
                if ( is_NUM(c) || is_ALPHA(c) || c == '_' || c == '$' ) continue;
                else {
                    string Readed = s.substr(0, i);
                    t = new Token(TOKEN_TYPE::ID, Readed);
                    tokens.push_back(t);
                        
                    if (len >= i + 1) opreate_DFA::update_token(s.substr(i + 1));
                    return ;
                }
            } else if (curState == STATE_NUM){
                if ( is_NUM(c) ) continue;
                else {
                    // this case handle some thing like 89abc_, which is an invaild token
                    if ( is_ALPHA(c) || c == '_' || c == '$' ) {
                        curState = INVAILD;
                        break;
                    } else {
                        string Readed = s.substr(0, i);
                        t = new Token(TOKEN_TYPE::ID, Readed);
                        tokens.push_back(t);
                        
                        if (len >= i + 1) opreate_DFA::update_token(s.substr(i + 1));
                        return ;
                    }
                }
            } else if (curState == STATE_OP){
                if (c == '='){
                    if (s[i - 1] == '+') t = new Token(TOKEN_TYPE::PLUSEQUAL, "+=");
                    else if (s[i - 1] == '-') t = new Token(TOKEN_TYPE::MINUSEQUAL, "-=");
                    else if (s[i - 1] == '*') t = new Token(TOKEN_TYPE::STAREQUAL, "*=");
                    else if (s[i - 1] == '%') t = new Token(TOKEN_TYPE::PRECENTEQYUAL, "%=");
                    else if (s[i - 1] == '/') t = new Token(TOKEN_TYPE::SLASHEQUAL, "/=");
                    else if (s[i - 1] == '>') t = new Token(TOKEN_TYPE::GE, ">=");
                    else if (s[i - 1] == '<') t = new Token(TOKEN_TYPE::LE, "<=");
                    else if (s[i - 1] == '!') t = new Token(TOKEN_TYPE::NE, "!=");
                    else if (s[i - 1] == '=') t = new Token(TOKEN_TYPE::EQ, "==");
                    else {
                        curState = INVAILD;
                        break;
                    }
                }
                else if (c == '&' && s[i - 1] == '&') t = new Token(TOKEN_TYPE::AND, "&&");
                else if (c == '|' && s[i - 1] == '|') t = new Token(TOKEN_TYPE::OR, "||");
                else if (c == '*' && s[i - 1] == '/') t = new Token(TOKEN_TYPE::LAREACOMMENT, "/*");
                else if (c == '/' && s[i - 1] == '*') t = new Token(TOKEN_TYPE::RAREACOMMENT, "*/");
                else if (c == '>' && s[i - 1] == '-') t = new Token(TOKEN_TYPE::ARROW, "->");
                else if (c == '+' && s[i - 1] == '+') t = new Token(TOKEN_TYPE::DOUBLEPLUS, "++");
                else if (c == '-' && s[i - 1] == '-') t = new Token(TOKEN_TYPE::DOUBLEMINUS, "--");
                else if (c == '/'&& s[i - 1] == '/') t = new Token(TOKEN_TYPE::COMMENT, "//");
                else if (is_ALPHA(c) || c == '_' || c == '$' || is_NUM(c)){
                    if (s[i - 1] == '+') t = new Token(TOKEN_TYPE::PLUS, "+");
                    else if (s[i - 1] == '-') t = new Token(TOKEN_TYPE::MINUS, "-");
                    else if (s[i - 1] == '*') t = new Token(TOKEN_TYPE::STAR, "*");
                    else if (s[i - 1] == '%') t = new Token(TOKEN_TYPE::PRECENT, "%");
                    else if (s[i - 1] == '/') t = new Token(TOKEN_TYPE::SLASH, "/");
                    else if (s[i - 1] == '>') t = new Token(TOKEN_TYPE::GT, ">");
                    else if (s[i - 1] == '<') t = new Token(TOKEN_TYPE::LT, "<");
                    else if (s[i - 1] == '!') t = new Token(TOKEN_TYPE::EXCLAMATION, "!");
                    else if (s[i - 1] == '=') t = new Token(TOKEN_TYPE::ASSIGNMENT, "=");
                    else if (s[i - 1] == '&') t = new Token(TOKEN_TYPE::AMP, "&");
                    else if (s[i - 1] == '|') t = new Token(TOKEN_TYPE::VERBAR, "|");
                    else {
                        curState = INVAILD;
                        break;
                    }
                    
                    
                    tokens.push_back(t);
                    opreate_DFA::update_token(s.substr(i));
                    return ;
                } else {
                    curState = INVAILD;
                    break;
                }
                if (curState != INVAILD){
                    tokens.push_back(t);
                    if (len >= i + 1) opreate_DFA::update_token(s.substr(i + 1));
                    return ;
                }
            }
        }
    }
    
    if (curState == STATE_NUM) t = new Token(TOKEN_TYPE::NUM, s);
    else if (curState == STATE_ID) t = new Token(TOKEN_TYPE::ID, s);
    else if (curState == STATE_OP){
        if (s[len - 1] == '+') t = new Token(TOKEN_TYPE::PLUS, "+");
        else if (s[len - 1] == '-') t = new Token(TOKEN_TYPE::MINUS, "-");
        else if (s[len - 1] == '*') t = new Token(TOKEN_TYPE::STAR, "*");
        else if (s[len - 1] == '%') t = new Token(TOKEN_TYPE::PRECENT, "%");
        else if (s[len - 1] == '/') t = new Token(TOKEN_TYPE::SLASH, "/");
        else if (s[len - 1] == '>') t = new Token(TOKEN_TYPE::GT, ">");
        else if (s[len - 1] == '<') t = new Token(TOKEN_TYPE::LT, "<");
        else if (s[len - 1] == '!') t = new Token(TOKEN_TYPE::EXCLAMATION, "!");
        else if (s[len - 1] == '=') t = new Token(TOKEN_TYPE::ASSIGNMENT, "=");
        else if (s[len - 1] == '&') t = new Token(TOKEN_TYPE::AMP, "&");
        else if (s[len - 1] == '|') t = new Token(TOKEN_TYPE::VERBAR, "|");
    } else {
        cerr << "i don't know how to handle this, i will just die, the error string is : " << s << endl;
        return ;
    }
    tokens.push_back(t);
}

