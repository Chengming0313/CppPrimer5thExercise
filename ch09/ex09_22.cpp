//
//  ex09_22.cpp
//  cpp primer 5th exercise 9.22
//
//  Created by aozy on 04/14/2021
//
//  @Brief insert double target before the target for the mid of the vector<int>

#include <iostream>
#include <vector>

void InsertDoubleVal(std::vector<int> &iv, int target) {
    auto cursor = iv.size() / 2;
    for (auto iter = iv.cbegin(), mid = iv.cbegin() + cursor; iter != mid;
         ++iter, mid = iv.begin() + cursor) {
        if (*iter == target) {
            iter = iv.insert(iter, target * 2);
            ++iter;
            ++cursor;
        }
    }
}

int main() {
    std::vector<int> iv{ 1, 2, 1, 2, 2, 2, 3, 1, 2 };
    InsertDoubleVal(iv, 2);

    for (auto n : iv) {
        std::cout << n << " ";
    }
    std::cout << '\n';
    return 0;
}
