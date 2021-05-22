//
//  ex10_22.cpp
//
//  Created by Tang Chengming on 05/03/2021
//
//  @Brief  重写程序统计长度超过 6 的单词, 使用函数替代 lambda.

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std::placeholders;

bool check_size(std::string const &str, int size) {
    return static_cast<int>(str.size()) > size;
}

int main() {

    std::vector<std::string> svec{ "1234",       "1234", "1234",       "1234455",
                                   "he52525llo", "hgkg", "5235236sdg", "6365634634" };

    int cnt = std::count_if(svec.cbegin(), svec.cend(), std::bind(check_size, _1, 6));

    std::cout << cnt << std::endl;

    return 0;
}
