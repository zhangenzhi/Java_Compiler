//
//  words_DFA.cpp
//  Compiler
//
//  Created by 张恩智 on 2020/03/08.
//  Copyright © 2020 张恩智. All rights reserved.
//

#include "words_DFA.hpp"
#include <algorithm>
using namespace std;



string words_DFA::checkState(std::string s)
{
    Node* current_node = root->root;
    string state = current_node->State;
    
    for(int i=0;i!=s.size();i++){
        char c = s[i];
        cout<<state<<endl;
        cout<<"check："<<c<<endl;
        state = current_node->node_list[c]->State;
        
        if (state == "INVALID") {
            cout<<"INVALID"<<endl;
            return state;
        }
        current_node = current_node->node_list[c];
    }
    cout<<"VALID or TOUCHED:"<<state<<endl;
    
    if(state == "VALID"){
        if (s == "abstruct") {
            Token* T = new Token(TYPE::ABSTRUCT,state);
            tokens.push_back(T);
        }
        if (s == "externs") {
            Token* T = new Token(TYPE::EXTERN,state);
            tokens.push_back(T);
        }
        if (s == "class") {
            Token* T = new Token(TYPE::CLASS,state);
            tokens.push_back(T);
        }
        if (s == "final") {
            Token* T = new Token(TYPE::FINAL,state);
            tokens.push_back(T);
        }
        if (s == "implement") {
            Token* T = new Token(TYPE::IMPLEMENT,state);
            tokens.push_back(T);
        }
        if (s == "import") {
            Token* T = new Token(TYPE::IMPORT,state);
            tokens.push_back(T);
        }
        if (s == "package") {
            Token* T = new Token(TYPE::PACKAGE,state);
            tokens.push_back(T);
        }
        if (s == "protected") {
            Token* T = new Token(TYPE::PROTECTED,state);
            tokens.push_back(T);
        }
        if (s == "public") {
            Token* T = new Token(TYPE::PUBLIC,state);
            tokens.push_back(T);
        }
        if (s == "static") {
            Token* T = new Token(TYPE::STATIC,state);
            tokens.push_back(T);
        }
        if (s == "main") {
            Token* T = new Token(TYPE::MAIN,state);
            tokens.push_back(T);
        }
        if (s == "int") {
            Token* T = new Token(TYPE::INT,state);
            tokens.push_back(T);
        }
        if (s == "boolean") {
            Token* T = new Token(TYPE::BOOLEAN,state);
            tokens.push_back(T);
        }
        if (s == "byte") {
            Token* T = new Token(TYPE::BYTE,state);
            tokens.push_back(T);
        }
        if (s == "char") {
            Token* T = new Token(TYPE::CHAR,state);
            tokens.push_back(T);
        }
        if (s == "else") {
            Token* T = new Token(TYPE::ELSE,state);
            tokens.push_back(T);
        }
        if (s == "if") {
            Token* T = new Token(TYPE::IF,state);
            tokens.push_back(T);
        }
        if (s == "null") {
            Token* T = new Token(TYPE::NuLL,state);
            tokens.push_back(T);
        }
        if (s == "retrun") {
            Token* T = new Token(TYPE::RETURN,state);
            tokens.push_back(T);
        }
        if (s == "short") {
            Token* T = new Token(TYPE::SHORT,state);
            tokens.push_back(T);
        }
        if (s == "true") {
            Token* T = new Token(TYPE::TrUE,state);
            tokens.push_back(T);
        }
        if (s == "this") {
            Token* T = new Token(TYPE::THIS,state);
            tokens.push_back(T);
        }
        if (s == "false") {
            Token* T = new Token(TYPE::FaLSE,state);
            tokens.push_back(T);
        }
        if (s == "while") {
            Token* T = new Token(TYPE::WHILE,state);
            tokens.push_back(T);
        }
    }
    return state;
}
