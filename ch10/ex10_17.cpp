//
//  ex10_17.cpp
//  cpp primer 5th exercise 10.17
//
//  Created by Tang Chengming on 05/03/2021
//
//  @Brief  重写 exercise 10.12 中的程序, 在对 sort 的调用中使用 lambda 来代替 compareIsbn.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Sales_data {
    std::string bookNo;
    std::string bookName;
    std::string isbn() const { return bookNo; }
};

std::ostream &operator<<(std::ostream &os, Sales_data const &x) {
    return os << x.bookNo << ": " << x.bookName;
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

    std::vector<Sales_data> items{ { "111", "book_01" },
                                   { "999", "book_09" },
                                   { "333", "book_03" } };

    std::sort(items.begin(), items.end(),
              [](Sales_data const &lhs, Sales_data const &rhs) { return lhs.isbn() < rhs.isbn(); });

    print(items);

    return 0;
}
