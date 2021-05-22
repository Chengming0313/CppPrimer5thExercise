//
//  ex10_21.cpp
//
//  Created by Tang Chengming on 05/03/2021
//
//  @Brief

#include <iostream>

int main() {
    int  i = 10;
    auto decrease = [&i]() -> bool {
        if (i) {
            while (--i) {
            }
            return false;
        }
        return true;
    };

    std::cout << std::boolalpha << decrease() << " " << decrease() << std::endl;

    return 0;
}
