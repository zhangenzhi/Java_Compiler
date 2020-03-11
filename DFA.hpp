#ifndef DFA_hpp
#define DFA_hpp

#include <stdio.h>
#include <vector>
#include <sstream>
#include "Token.hpp"
#include <iostream>
#include <unordered_map>
#include <map>

struct Node{
    std::vector <Node *> node_list;
    std::string State;
    
    Node(std::string state){
        State = state;
    }
    
    void insert_Node(char c, std::string state);
    std::string check_node_list(char c);
};

struct DFARoot{
    Node * root;
    
    DFARoot(){
        root = new Node ("START");
        for (int i = 0; i < 128; i ++) {
            root->node_list.push_back(new Node("INVAILD"));
        }
    }
    void Build(std::vector <std::string> words);
};


bool is_NUM (char c);
bool is_ALPHA (char c);
bool single_char_op (char c);

struct DFA{
    
    DFARoot * root;
    std::vector <Token *> tokens;
    
    DFA(){};
    DFA(std::vector<std::string> words){Build(words);};
    
    void Build(std::vector <std::string> words){DFARoot r;r.Build(words);root = &r;};

};

struct opreate_DFA : public DFA{
    std::vector <Token *> tokens;
    
    const int STATE_OP = 0;
    const int STATE_NUM = 1;
    const int STATE_ID = 2;
    const int INVAILD = 3;
    
    void update_token (std::string s);
};
#endif /* DFA_hpp */
