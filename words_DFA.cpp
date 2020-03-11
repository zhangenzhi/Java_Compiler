//
//  words_DFA.cpp
//  Compiler
//
//  Created by 张恩智 on 2020/03/08.
//  Copyright © 2020 张恩智. All rights reserved.
//

#include "words_DFA.hpp"
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
    return state;
}
