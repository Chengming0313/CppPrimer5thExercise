//
//  ex10_06.cpp
//  cpp primer 5th exercise 10.6
//
//  Created by Tang Chengming on 04/25/2021
//
//  @Brief 使用 fill_n 将一个序列中的 int 值都设为 0

#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> ivec(10, 1);

    fill_n(ivec.begin(), ivec.size(), 0);

    for (auto n : ivec) {
        std::cout << n << " ";
    }
    cout << "\n";

    return 0;
}
