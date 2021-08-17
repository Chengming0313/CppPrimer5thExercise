//
//  ex12_02_test.cpp
//
//  Created by Tang Chengming on 05/20/2021
//
//  @Brief

#include "ex12_02_StrBlob.h"

#include <iostream>

int main() {
    {
        std::cout << "size, front, back, pushBack, popBack: " << std::endl;
        StrBlob sb, sb2{"1", "2", "3", "4", "5"};
        std::cout << "sb2.size: " << sb2.size() << std::endl;
        std::cout << "sb2.front: " << sb2.front() << std::endl;
        std::cout << "sb2.back: " << sb2.back() << std::endl;
        sb2.pushBack("6");
        std::cout << "after pushBack 6, sb2.back: " << sb2.back() << std::endl;
        sb2.popBack();
        std::cout << "after popBack 6, sb2.back: " << sb2.back() << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "const 版本的 front, back: " << std::endl;
        StrBlob const sb3{"1", "2", "3"};
        std::cout << "sb3.front: " << sb3.front() << std::endl;
        std::cout << "sb3.back: " << sb3.back() << std::endl;
    }

    return 0;
}
