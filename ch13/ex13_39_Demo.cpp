//
//  StrVectorDemo.cpp
//
//  Created by Tang Chengming on 2021/8/4.
//
//  @Brief  
//

#include "ex13_39_StrVector.h"
#include <string>
#include <iostream>

int main() {
    StrVector sVec;
    for (int i = 0; i < 10; ++i) {
        sVec.pushBack(std::to_string(i));
    }

    std::cout << "size: " << sVec.size() << " capacity: " << sVec.capacity() << std::endl;

    for (auto cur = sVec.begin(); cur != sVec.end(); ++cur) {
        std::cout << *cur << " ";
    }
    std::cout << std::endl;

    sVec.reserve(30);
    std::cout << "size: " << sVec.size() << " capacity: " << sVec.capacity() << std::endl;

    sVec.resize(5);
    std::cout << "size: " << sVec.size() << " capacity: " << sVec.capacity() << std::endl;

    sVec.resize(8);
    std::cout << "size: " << sVec.size() << " capacity: " << sVec.capacity() << std::endl;

    return 0;
}