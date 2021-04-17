//
//  ex09_40.cpp
//  cpp primer 5th exercise 9.40
//
//  Created by aozy on 04/15/2021
//
//  @Brief  If the program in the previous exercise reads 256 words, what is its likely capacity
//          after it is resized? What if it reads 512? 1, 000? 1, 048?

#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> svec;
    svec.reserve(1024);
    std::cout << "capacity: " << svec.capacity() << "\n";

    // 256 512 1000 1024
    for (int i = 0; i < 1000; ++i)
        svec.push_back("aozy!!!");

    svec.resize(svec.size() + svec.size() / 2);

    std::cout << "capacity: " << svec.capacity() << "\n";

    return 0;
}
