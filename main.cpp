#include <iostream>
#include "DFA.hpp"

using namespace std;



int main (){
    
    vector<string> words;
    words.push_back("aa");
    words.push_back("ac");
    words.push_back("aab");
    words.push_back("bb");
    
    
    Root * r = new Root();
    r->Build(words);
    
    Node * curnode = r->root;
    cout << "level 1" << endl;
    for (int i = 0; i < 128; i ++){
        string state = curnode->node_list[i]->State;
        if (state == "Touched"){
            char c = i;
            cout << "position " << c << " (" << i << ")"<< " is touched" << endl;
        }
    }
    cout << "level 2" << endl;
    
    curnode = curnode->node_list['a'];
    for (int i = 0; i < 128; i ++){
        string state = curnode->node_list[i]->State;
        if (state == "Touched"){
            char c = i;
            cout << "position " << c << " (" << i << ")"<< " is touched" << endl;
        }
    }
    
    
    return 0;
}
