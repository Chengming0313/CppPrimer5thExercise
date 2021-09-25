//
//  ex15_5_test.cpp
//
//  Created by Tang Chengming on 2021/9/10.
//
//  @Brief  
//

#include "ex15_5_Bulk_quote.h"
#include <iostream>

int main() {
    Bulk_quote bq("我的第一本书", 30.0, 3, 0.8);
    Quote &qr = bq;
    print_total(std::cout, qr, 3);
    print_total(std::cout, qr, 2);

    return 0;
}