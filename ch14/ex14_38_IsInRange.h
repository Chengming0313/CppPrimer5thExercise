//
//  ex14_38_IsInRange.h
//
//  Created by Tang Chengming on 2021/9/4.
//
//  @Brief  
//

#ifndef CPP_PRIMER5_EX14_38_ISINRANGE_H
#define CPP_PRIMER5_EX14_38_ISINRANGE_H

#include <string>

class IsInRange{
public:
    bool operator()(std::string const &str, int lower, int upper) {
        if (upper < 0) {
            return str.size() >= lower;
        }
        return str.size() >= lower && str.size() < upper;
    }
};

#endif //CPP_PRIMER5_EX14_38_ISINRANGE_H
