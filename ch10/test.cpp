//
//  test.cpp
//
//  Created by Tang Chengming on 04/25/2021
//
//  @Brief

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> ivec1(4, 1), ivec2(3, 1);

    cout << boolalpha << equal(ivec1.cbegin(), ivec1.cend(), ivec2.cbegin()) << endl;

    return 0;
}
