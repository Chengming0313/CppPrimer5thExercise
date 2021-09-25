//
//  ex14_39_test.cpp
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
    cnt.resize(2, 0);
    cnt[0] = count_if(svec.cbegin(), svec.cend(), bind(IsInRange(), _1, 1, 10));
    cnt[1] = count_if(svec.cbegin(), svec.cend(), bind(IsInRange(), _1, 11, -1));



    cout << "长度在1至9之间的字符串出现" << cnt[0] << "次\n";
    cout << "长度在10以上的字符串出现" << cnt[1] << "次\n";


    return 0;
}