#ifndef DFA_hpp
#define DFA_hpp

#include <stdio.h>
#include <vector>
#include <sstream>
#include "Token.hpp"
#include <iostream>

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

struct DFA{
    Root * root;
    
    void Build(std::vector <std::string> words);
    
    virtual std::vector<TOKEN_TYPE> checkState (std::string s); // this could return a vector as: <num,minus,num>
};

#endif /* DFA_hpp */
