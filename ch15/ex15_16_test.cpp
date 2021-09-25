//
//  ex15_16_test.cpp
//
//  Created by Tang Chengming on 2021/9/11.
//
//  @Brief  
//

#include "ex15_16_Limited_quote.h"

int main() {
    Limited_quote lq("我的第一本书", 30.0, 5, 0.8);
    print_total(std::cout, lq, 4);
    print_total(std::cout, lq, 6);
    return 0;
}