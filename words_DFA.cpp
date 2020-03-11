//
//  words_DFA.cpp
//  Compiler
//
//  Created by 张恩智 on 2020/03/08.
//  Copyright © 2020 张恩智. All rights reserved.
//

#include "words_DFA.hpp"
using namespace std;



void words_DFA::checkState(std::string s)
{
    Node* current_node = root->root;
    
    for(int i=0;i!=s.size();i++){
        char c = s[i];
        cout<<"check："<<c<<endl;
        
        if (current_node->node_list[c]->State == "INVALID") {
            cout<<"INVALID"<<endl;
            break;
        }
        current_node = current_node->node_list[c];
    }
    cout<<"VALID"<<endl;
}
