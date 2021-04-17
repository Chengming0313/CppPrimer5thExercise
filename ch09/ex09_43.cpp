//
//  ex09_43.cpp
//  cpp primer 5th exercise 9.43
//
//  Created by aozy on 04/16/2021
//
//  @Brief  Write a function that takes three strings, s, oldVal, and newVal.
//          Using iterators, and the insert and erase functions replace
//          all instances of oldVal that appear in s by newVal.
//	        Test your function by using it to replace common abbreviations,
//          such as “tho” by “though” and “thru” by “through”.

#include <iostream>
#include <string>

void ReplaceStr(std::string &s, std::string const &oldVal, std::string const &newVal) {
    auto oldSize = oldVal.size(), newSize = newVal.size(), size = s.size();
    // 保证 s 以及 oldVal 不为空， 且 s 至少与　oldVal 等长
    if (size == 0 || oldSize == 0 || size < oldSize) return;
    for (auto cur = s.begin(); cur <= s.end() - oldSize;) {
        if (oldVal == std::string{ cur, cur + oldSize }) {
            cur = s.erase(cur, cur + oldSize);
            cur = s.insert(cur, newVal.cbegin(), newVal.cend());
            cur += newSize;
        }
        else {
            ++cur;
        }
    }
}

int main() {
    std::string str{ "To drive straight thru is a foolish, tho courageous act." };
    ReplaceStr(str, "tho", "though");
    ReplaceStr(str, "thru", "through");
    std::cout << str << "\n";

    return 0;
}
