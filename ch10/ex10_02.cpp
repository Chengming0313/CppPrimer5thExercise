//
//  ex10_02.cpp
//  cpp primer 5th exercise 10.2
//
//  Created by Tang Chengming on 04/19/2021
//
//  @Brief  Repeat the previous program, but read values into a list of strings.

#include <algorithm>
#include <iostream>
#include <list>
#include <string>

int main() {
    std::list<std::string> lst{ "111", "222", "222", "444", "222", "555" };

    std::string target1{ "222" };
    std::string target2{ "333" };

    int nums1 = std::count(lst.cbegin(), lst.cend(), target1);
    int nums2 = std::count(lst.cbegin(), lst.cend(), target2);

    std::cout << "";
    std::cout << target1 << ": " << nums1 << " times\n";
    std::cout << target2 << ": " << nums2 << " times\n";

    return 0;
}
