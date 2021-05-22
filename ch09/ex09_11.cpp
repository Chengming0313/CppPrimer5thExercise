//
//  ex09_11.cpp
//
//  Created by Tang Chengming on 04/17/2021
//
//  @Brief  Show an example of each of the six ways to create
//          and initialize a vector. Explain what values each
//          vector contains.

#include <iostream>
#include <vector>

int main() {
    std::vector<int> c1;  // 空

    std::vector<int> t1{ 1, 2, 3 };
    std::vector<int> c2(t1);   // 1, 2, 3
    std::vector<int> c3 = t1;  // 1, 2, 3

    // c4 与 c5 差别？
    // 直接初始化与拷贝初始化？
    std::vector<int> c4{ 4, 5, 6 };     // 4, 5, 6
    std::vector<int> c5 = { 4, 5, 6 };  // 4, 5, 6

    std::vector<int> t2{ 7, 8, 9 };
    std::vector<int> c6(t2.cbegin(), t2.cend() - 1);  // 7, 8

    std::vector<int> c7(5);  // 0, 0, 0, 0, 0

    std::vector<int> c8(3, 9);  // 9, 9, 9

    std::cout << "C1: ";
    for (auto n : c1) {
        std::cout << n << " ";
    }
    std::cout << '\n';
    std::cout << "C2: ";
    for (auto n : c2) {
        std::cout << n << " ";
    }
    std::cout << '\n';
    std::cout << "C3: ";
    for (auto n : c3) {
        std::cout << n << " ";
    }
    std::cout << '\n';
    std::cout << "C4: ";
    for (auto n : c4) {
        std::cout << n << " ";
    }
    std::cout << '\n';
    std::cout << "C5: ";
    for (auto n : c5) {
        std::cout << n << " ";
    }
    std::cout << '\n';
    std::cout << "C6: ";
    for (auto n : c6) {
        std::cout << n << " ";
    }
    std::cout << '\n';
    std::cout << "C6: ";
    for (auto n : c6) {
        std::cout << n << " ";
    }
    std::cout << '\n';
    std::cout << "C7: ";
    for (auto n : c7) {
        std::cout << n << " ";
    }
    std::cout << '\n';
    std::cout << "C8: ";
    for (auto n : c8) {
        std::cout << n << " ";
    }
    std::cout << '\n';

    return 0;
}