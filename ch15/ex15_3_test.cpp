//
//  ex15_3_test.cpp
//
//  Created by Tang Chengming on 2021/9/10.
//
//  @Brief  
//

#include "ex15_3_Quote.h"
#include <string>
#include <iostream>

int main() {
    Quote q1("我的第一本书", 30.0);
    print_total(std::cout, q1, 3) << std::endl;
    return 0;
}
