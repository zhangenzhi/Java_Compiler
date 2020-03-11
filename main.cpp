//
//  main.cpp
//  Compiler
//
//  Created by 张恩智 on 2020/03/08.
//  Copyright © 2020 张恩智. All rights reserved.
//

#include <iostream>
#include "DFA.hpp"
#include "words_DFA.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    vector<string> words_table = {
        //words
        "abstruct","externs","class","final","implement","import",
        "package","protected","public","static"
//        //punctuation mark
//        ",",".","!",":",";","'","/","\\",
//        //data type
//        "int","boolean","byte","char","else","if","null","return",
//        "short","true","this","while",
//        //logic ops
//        "&","|","&&","||",
//        //inequality
//        "<",">","!=","<=",">=","==",
//        //numerical
//        "+","-","*","%",
//        //others
//        "{","}","/*","*/","/**","instanceof",
    };
    
    words_DFA w_dfa(words_table);
    cout<<"----------"<<endl;
    w_dfa.checkState("abstruct");
//    w_dfa.Build(words_table);
    
//    DFA dfa;
//    dfa.Build(words_table);
    
    return 0;
}
