//
//  ex14_37_Equal.h
//
//  Created by Tang Chengming on 2021/9/4.
//
//  @Brief  
//

#ifndef CPP_PRIMER5_EX14_37_EQUAL_H
#define CPP_PRIMER5_EX14_37_EQUAL_H

class Equal {
public:
    bool operator()(int a, int b) {
        return a == b;
    }
};

#endif //CPP_PRIMER5_EX14_37_EQUAL_H
