//
//  ex09_20.cpp
//
//  Created by aozy on 04/14/2021
//
//  @Brief  Write a program to copy elements from a list<int> into two deques.
//          The even-valued elements should go into one deque and the odd ones into the other.

#include <deque>
#include <iostream>
#include <list>

int main() {
    std::list<int>  lst{ 1, 2, 3, 4, 5, 6, 7 };
    std::deque<int> dq1, dq2;
    for (auto n : lst) {
        // even-valued elements to dq1
        if ((n & 1) == 0) {
            dq1.push_back(n);
        }
        else {
            dq2.push_back(n);
        }
    }

    for (auto i : dq1) {
        std::cout << i << " ";
    }
    std::cout << '\n';

    for (auto i : dq2) {
        std::cout << i << " ";
    }
    std::cout << '\n';

    return 0;
}
