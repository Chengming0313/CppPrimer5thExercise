//
//  ex14_43_test.cpp
//
//  Created by Tang Chengming on 2021/9/5.
//
//  @Brief  
//

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Aliquot {
    int divisor;
    explicit Aliquot(int divisor) : divisor(divisor) {}
    bool operator()(int dividend) const {
        return dividend % divisor == 0;
    }
};

int main() {
    vector<int> ivec{2, 4, 6, 8, 10};
    if (partition(ivec.begin(), ivec.end(), Aliquot{2}) == ivec.end()) {
        cout << "能被2整除\n";
    } else {
        cout << "不能被2整除\n";
    }
    if (partition(ivec.begin(), ivec.end(), Aliquot{3}) == ivec.end()) {
        cout << "能被3整除\n";
    } else {
        cout << "不能被3整除\n";
    }
}