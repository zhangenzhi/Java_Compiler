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
};

struct Root{
    Node * root;
    
    Root(){
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
    Root * root;
    std::vector <Token *> tokens;
    
    void Build(std::vector <std::string> words);
    
    virtual void checkState (std::string s); // this could return a vector as: <num,minus,num>
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
