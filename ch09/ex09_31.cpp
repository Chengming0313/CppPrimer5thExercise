//
//  ex09_31.cpp
//  cpp primer 5th exercise 9.31
//
//  Created by aozy on 04/15/2021
//
//  @Brief  The program on page 354 to remove even-valued elements and
//          duplicate odd ones will not work on a list or forward_list. Why?
//          Revise the program so that it works on these types as well.

#include <forward_list>
#include <iostream>
#include <list>

int main() {
    std::list<int> lst{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto           iter = lst.begin();
    while (iter != lst.end()) {
        if (*iter & 1) {
            iter = lst.insert(iter, *iter);
            ++iter;
            ++iter;
        }
        else {
            iter = lst.erase(iter);
        }
    }

    for (auto n : lst)
        std::cout << n << " ";
    std::cout << "\n";

    std::forward_list<int> flst{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto                   prev = flst.before_begin();
    auto                   iter2 = flst.begin();
    while (iter2 != flst.end()) {
        if (*iter2 & 1) {
            iter2 = flst.insert_after(prev, *iter2);
            ++iter2;
            prev = iter2;
            ++iter2;
        }
        else {
            iter2 = flst.erase_after(prev);
        }
    }

    for (auto n : flst)
        std::cout << n << " ";
    std::cout << "\n";

    return 0;
}
