//
//  ex09_26.cpp
// cpp primer 5th exercise 9.26
//
//  Created by Tang Chengming on 04/14/2021
//
//  @Brief  Using the following definition of ia, copy ia into a vector and into a list.
//          Use the single-iterator form of erase to remove the elements with odd values from your
//          list and the even values from your vector.

#include <iostream>
#include <list>
#include <vector>

int main() {
    int              ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    std::vector<int> iv;
    std::vector<int> ilst;

    iv.assign(std::begin(ia), std::end(ia));
    ilst.assign(std::begin(ia), std::end(ia));

    for (auto iter = iv.cbegin(); iter != iv.cend();) {
        if ((*iter & 0x1) == 0)
            iter = iv.erase(iter);
        else
            ++iter;
    }

    for (auto iter = ilst.cbegin(); iter != ilst.cend();) {
        if ((*iter & 0x1) == 1)
            iter = ilst.erase(iter);
        else
            ++iter;
    }

    for (auto n : iv)
        std::cout << n << " ";
    std::cout << "\n";

    for (auto n : ilst)
        std::cout << n << " ";
    std::cout << "\n";

    return 0;
}
