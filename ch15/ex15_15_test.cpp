//
//  ex15_test.cpp
//
//  Created by Tang Chengming on 2021/9/11.
//
//  @Brief  
//

#include "ex15_15_Bulk_quote.h"
#include <iostream>

int main() {
    Bulk_quote bq("我的第一本书", 30.0, 5, 0.8);
    print_total(std::cout , bq, 6);
    print_total(std::cout, bq, 4);
    return 0;
}