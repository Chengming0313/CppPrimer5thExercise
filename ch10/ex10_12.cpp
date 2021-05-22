//
//  ex10_12.cpp
//  cpp primer 5th exercise 10.12
//
//  Created by Tang Chengming on 04/28/2021
//
//  @Brief  编写名为 compareIsbn 的函数, 比较两个 Sales_data 对象的 isbn() 成员.
//          使用这个函数排序一个保存 Sales_data 对象的 vector.

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

bool compareIsbn(Sales_data const &lhs, Sales_data const &rhs) {
    return lhs.isbn() < rhs.isbn();
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

    std::vector<Sales_data> vec{ { "111", "book_01" }, { "999", "book_09" }, { "333", "book_03" } };

    std::sort(vec.begin(), vec.end(), compareIsbn);

    print(vec);

    return 0;
}
