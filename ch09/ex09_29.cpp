//
//  ex09_29.cpp
//
//  Created by aozy on 04/15/2021
//
//  @Brief  Given that vec holds 25 elements, what does vec.resize(100) do?
//          What if we next wrote vec.resize(10)?

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec(25, 1);
    std::cout << "vec(25, 1)...\n";
    std::cout << "capacity : " << vec.capacity() << ", size : " << vec.size() << '\n';
    vec.resize(100);
    std::cout << "\nvec.resize(100)...\n";
    std::cout << "capacity : " << vec.capacity() << ", size : " << vec.size() << '\n';
    vec.resize(10);
    std::cout << "\nvec.resize(10)...\n";
    std::cout << "capacity : " << vec.capacity() << ", size : " << vec.size() << '\n';

    return 0;
}
