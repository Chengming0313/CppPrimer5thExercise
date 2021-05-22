//
//  ex09_44.cpp
//  cpp primer 5th exercise 9.44
//
//  Created by Tang Chengming on 04/16/2021
//
//  @Brief  Rewrite the previous function using an index and replace.

#include <cstddef>
#include <iostream>
#include <string>

void ReplaceStr(std::string &s, std::string const &oldVal, std::string const &newVal) {
    auto size = s.size(), oldSize = oldVal.size(), newSize = newVal.size();
    if (size == 0 || oldSize == 0 || size < oldSize) return;
    for (std::size_t i = 0u; i <= s.size() - oldSize;) {
        if (oldVal == s.substr(i, oldSize)) {
            s.replace(i, oldSize, newVal);
            i += newSize;
        }
        else {
            ++i;
        }
    }
}

int main() {

    std::string str{ "To drive straight thru is a foolish, tho courageous act." };
    ReplaceStr(str, "tho", "though");
    std::cout << str << "\n";

    ReplaceStr(str, "thru", "through");
    std::cout << str << "\n";

    return 0;
}
