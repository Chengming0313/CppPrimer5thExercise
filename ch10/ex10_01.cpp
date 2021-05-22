//
//  ex10_01.cpp
//  cpp primer 5th exercise 10.1
//
//  Created by Tang Chengming on 04/19/2021
//
//  @Brief  The algorithm header defines a function named count that, like find,
//          takes a pair of iterators and a value.count returns a count of how
//          often that value appears.
//          Read a sequence of ints into a vector and print the count of how many
//          elements have a given value.

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{ 1, 2, 2, 4, 2, 5 };
    int              target1 = 2, target2 = 3;

    int nums1 = std::count(vec.cbegin(), vec.cend(), target1);
    int nums2 = std::count(vec.cbegin(), vec.cend(), target2);

    std::cout << "{ 1, 2, 2, 4, 2, 5 }\n";
    std::cout << target1 << " : " << nums1 << " times\n";
    std::cout << target2 << " : " << nums2 << " times\n";

    return 0;
}
