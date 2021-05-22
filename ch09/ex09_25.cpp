//
//  ex09_25.cpp
//
//  Created by Tang Chengming on 04/14/2021
//
//  @Brief  In the program on page 349 that erased a range of elements,
//          what happens ifelem1 and elem2 are equal?
//          What if elem2 or both elem1 and elem2 are theoff-the-end iterator?

#include <iostream>
#include <vector>

int main() {
    std::vector<int> iv{ 1, 2, 3, 4, 5 };

    // elem1 与 elem2 相等
    iv.erase(iv.cbegin(), iv.cbegin());
    // elem2 等于 cend()
    iv.erase(iv.cend(), iv.cend());

    for (auto n : iv) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    return 0;
}
