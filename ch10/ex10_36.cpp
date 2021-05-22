//
//  ex10_36.cpp
//
//  Created by Tang Chengming on 05/04/2021
//
//  @Brief  使用 find 在 list<int> 中查找最后一个值为 0 的元素.

#include <algorithm>
#include <iostream>
#include <iterator>  // distance
#include <list>

int main() {
    std::list<int> lst{ 0, 1, 2, 3, 0, 5 };

    auto item = std::find(lst.crbegin(), lst.crend(), 0);

    if (item == lst.crend()) {
        std::cerr << "no item equal to zero." << std::endl;
    }
    else {
        std::cout << "index: " << std::distance(item, lst.crend()) - 1 << " value: " << *item
                  << std::endl;
    }

    return 0;
}
