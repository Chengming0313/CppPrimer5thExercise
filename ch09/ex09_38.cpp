//
//  ex09_38.cpp
//
//  Created by aozy on 04/15/2021
//
//  @Brief  Write a program to explore how vectors grow in the library you use.

#include <iostream>
#include <vector>

int main() {

    std::vector<int> v;
    for (auto s = v.size(), c = v.capacity(); s <= c; ++s)
        v.push_back(999);
    std::cout << "size: " << v.size() << ", capacity: " << v.capacity() << "\n";

    for (auto s = v.size(), c = v.capacity(); s <= c; ++s)
        v.push_back(999);
    std::cout << "size: " << v.size() << ", capacity: " << v.capacity() << "\n";

    for (auto s = v.size(), c = v.capacity(); s <= c; ++s)
        v.push_back(999);
    std::cout << "size: " << v.size() << ", capacity: " << v.capacity() << "\n";

    for (auto s = v.size(), c = v.capacity(); s <= c; ++s)
        v.push_back(999);
    std::cout << "size: " << v.size() << ", capacity: " << v.capacity() << "\n";

    return 0;
}
