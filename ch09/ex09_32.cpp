//
//  p316.cpp
//  cpp primer 5th page 316
//
//  Created by aozy on 04/14/2021
//
//  @Brief  In the program on page 354 would it be legal to write the call to insert as follows?
//          If not, why not?
//          iter = vi.insert(iter, *iter++);
//
//  @answer 不合法，

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vi{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto             iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2) {
            // iter = vi.insert(iter, *iter);
            iter = vi.insert(iter, *iter++);
            iter += 2;
        }
        else {
            iter = vi.erase(iter);
        }
    }

    for (auto n : vi)
        std::cout << n << " ";
    std::cout << "\n";

    return 0;
}
