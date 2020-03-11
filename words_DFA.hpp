//
//  words_DFA.hpp
//  Compiler
//
//  Created by 张恩智 on 2020/03/08.
//  Copyright © 2020 张恩智. All rights reserved.
//

#ifndef words_DFA_hpp
#define words_DFA_hpp

#include <stdio.h>
#include "DFA.hpp"

struct words_DFA : public DFA
{
    DFARoot * root;
    
    words_DFA(std::vector<std::string> words){DFARoot r;r.Build(words);root=&r;};
    
    void checkState(std::string s);
};

#endif /* words_DFA_hpp */
