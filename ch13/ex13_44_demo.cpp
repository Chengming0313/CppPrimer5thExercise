//
//  ex13_44_demo.cpp
//
//  Created by Tang Chengming on 2021/8/5.
//
//  @Brief  
//

#include "ex13_44_String.h"
#include <iostream>

int main() {
    String s1, s2("123456");

    for (int i = 0; i < 10; ++i) {
        std::cout << "size: " << s1.size() << " capacity: " << s1.capacity() << std::endl;
        s1.pushBack(i + '0');
    }

    for (auto begin = s1.begin(); begin != s1.end(); ++begin) {
        std::cout << *begin << " ";
    }
    std::cout << std::endl;

    for (auto begin = s2.begin(); begin != s2.end(); ++begin) {
        std::cout << *begin << " ";
    }
    std::cout << std::endl;

    return 0;
}
