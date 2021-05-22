//
//  ex09_28.cpp
//  cpp primer 5th exercise 9.28
//
//  Created by Tang Chengming on 04/14/2021
//
//  @Brief  Write a function that takes a forward_list and two additional string arguments.The
//          function should find the first string and insert the second immediately following the
//          first. lf the first string is not found, then insert the second string atthe end of the
//          list.

#include <forward_list>
#include <iostream>

void InsertString(std::forward_list<std::string> &flst, std::string const &str1,
                  std::string const &str2) {
    auto prev = flst.cbefore_begin();
    for (auto curr = flst.cbegin(); curr != flst.cend(); ++prev, ++curr) {
        if ((*curr) == str1) {
            flst.insert_after(curr, str2);
            return;
        }
    }
    flst.insert_after(prev, str2);
}

int main() {
    std::forward_list<std::string> flst{ "123", "456", "789" };

    InsertString(flst, "456", "xxx");
    for (auto s : flst)
        std::cout << s << " ";
    std::cout << "\n";

    InsertString(flst, "yyy", "...");
    for (auto s : flst)
        std::cout << s << " ";
    std::cout << "\n";

    return 0;
}
