//
//  ex12_22_test.cpp
//
//  Created by Tang Chengming on 05/20/2021
//
//  @Brief

#include "ex12_22.h"

#include <iostream>

int main() {
    StrBlob const csb{ "111", "222", "333" };

    for (auto csbp = csb.cbegin(); csbp != csb.cend(); csbp.incr()) {
        // csbp.deref() = "xxx"; compile error
        std::cout << csbp.deref() << std::endl;
    }

    return 0;
}
