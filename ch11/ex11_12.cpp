//
//  ex11_12.cpp
//
//  Created by Tang Chengming on 05/11/2021
//
//  @Brief  编写程序, 读入 string 和 int 的序列, 将每个 string 和 int 存入一个 pair.
//          pair 保存在一个 vector 中.

#include <iostream>
#include <string>
#include <utility>
#include <vector>

template <typename Pv>
void printPv(Pv pv) {
    for (auto p : pv) {
        std::cout << p.first << " " << p.second << std::endl;
    }
}

int main() {
    std::string                              str;
    int                                      i = 0;
    std::vector<std::pair<std::string, int>> res;
    while (std::cin >> str >> i) {
        std::pair<std::string, int> p{ str, i };
        res.push_back(p);
    }

    printPv(res);

    return 0;
}
