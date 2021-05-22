//
//  ex10_20.cpp
//
//  Created by Tang Chengming on 05/03/2021
//
//  @Brief  使用 count_if 统计有多少单词长度超过 6.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> svec{ "1234",       "1234", "1234",       "1234455",
                                   "he52525llo", "hgkg", "5235236sdg", "6365634634" };

    int cnt =
        count_if(svec.cbegin(), svec.cend(), [](std::string const &str) { return str.size() > 6; });

    std::cout << cnt << std::endl;

    return 0;
}
