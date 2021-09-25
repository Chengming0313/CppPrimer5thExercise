//
//  ex14_35_GetLine.h
//
//  Created by Tang Chengming on 2021/9/4.
//
//  @Brief  
//

#ifndef CPP_PRIMER5_EX14_35_GETLINE_H
#define CPP_PRIMER5_EX14_35_GETLINE_H

#include <string>
#include <iostream>

class GetLine {
public:
    std::string operator()() {
        std::string ans;
        if (std::getline(std::cin, ans)) {
            return ans;
        }
        ans.clear();
        return ans;
    }
};

#endif //CPP_PRIMER5_EX14_35_GETLINE_H
