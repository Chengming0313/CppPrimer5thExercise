//
//  ex09_27.cpp
//  cpp primer 5th exercise 9.27
//
//  Created by Tang Chengming on 04/14/2021
//
//  @Brief  Write a program to find and remove the odd-valued
//          elements in a forward_list<int>.

#include <forward_list>
#include <iostream>

int main() {
    std::forward_list<int> flst{ 1, 2, 3, 4, 5, 6, 7, 8 };
    for (auto prev = flst.cbefore_begin(), curr = flst.cbegin(); curr != flst.cend();) {
        if ((*curr & 0x1) == 1) {
            curr = flst.erase_after(prev);
        }
        else {
            prev = curr;
            ++curr;
        }
    }

    for (auto i : flst)
        std::cout << i << " ";
    std::cout << "\n";

    return 0;
}
