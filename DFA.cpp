//
//  DFA.cpp
//  Complier
//
//  Created by 董泊辰 on 2020-03-07.
//  Copyright © 2020 董泊辰. All rights reserved.
//

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

void Root::Build(vector<string> words){
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

