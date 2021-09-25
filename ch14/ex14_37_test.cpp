//
//  ex14_37_test.cpp
//
//  Created by Tang Chengming on 2021/9/4.
//
//  @Brief  
//

#include "ex14_37_Equal.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using std::placeholders::_1;

int main() {
    vector<int> ivec{1, 2, 2, 3, 3, 4, 4, 5};
    // 替换 ivec 中所有的 2 为 999
    Equal equal;
    auto end = partition(ivec.begin(), ivec.end(), bind(equal, _1, 2));
    fill(ivec.begin(), end, 999);

    for (auto i : ivec) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}