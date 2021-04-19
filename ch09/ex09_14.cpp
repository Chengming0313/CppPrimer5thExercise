//
//  ex09_14.cpp
//
//  Created by Tang Chengming on 04/17/2021
//
//  @Brief  Write a program to assign the elements from a list of char* pointers
//          to C-style character strings

#include <iostream>
#include <list>
#include <string>
#include <vector>

int main() {
    std::list<const char *>  lst{ "123", "456", "789" };
    std::vector<std::string> v;
    v.assign(lst.cbegin(), lst.cend());

    for (auto s : v)
        std::cout << s << " ";
    std::cout << '\n';

    return 0;
}