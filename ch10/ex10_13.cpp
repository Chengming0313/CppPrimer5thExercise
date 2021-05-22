//
//  ex10_13.cpp
//  cpp primer 5th exercise 10.13
//
//  Created by Tang Chengming on 04/28/2021
//
//  @Brief  使用 std::partition 对 std::vector<std::string> 进行划分. 打印长度大于等于 5 的元素.

#include <algorithm>
#include <iostream>
#include <vector>

bool moreThan5Words(std::string const &str) {
    if (str.size() >= 5) return true;
    return false;
}

template <typename Sequence>
void print(Sequence seq) {
    for (auto n : seq) {
        std::cout << "\"" << n << "\""
                  << " ";
    }
    std::cout << std::endl;
}

int main() {

    std::vector<std::string> svec{ "abcd", "bdfsf", "fahogd", "faggjaigjh", "", "heasoif" };

    auto endTrue = std::partition(svec.begin(), svec.end(), moreThan5Words);

    svec.erase(endTrue, svec.end());
    print(svec);
    return 0;
}
