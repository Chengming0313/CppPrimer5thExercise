//
//  ex14_38_teset.cpp
//
//  Created by Tang Chengming on 2021/9/4.
//
//  @Brief  
//

#include "ex14_38_IsInRange.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>


using namespace std;
using std::placeholders::_1;

int main() {
    vector<string> svec{
        "1", "2", "3", "4", "5",
        "12", "34", "56",
        "123", "456",
        "12345", "67890",
        "123456", "456789",
        "1234567", "2345678", "0123456",
        "12345678", "23456789", "34567890",
        "1234567890"
    };

    vector<int> cnt;
    cnt.resize(10, 0);
    for (int i = 1; i < 11;  ++i) {
        int times = count_if(svec.cbegin(), svec.cend(), bind(IsInRange(), _1, i, i + 1));
        cnt[i - 1] = times;
    }

    for (int i = 0; i < cnt.size(); ++i) {
        cout << "长度为" << i + 1 << "的字符串出现" << cnt[i] << "次\n";
    }

    return 0;
}