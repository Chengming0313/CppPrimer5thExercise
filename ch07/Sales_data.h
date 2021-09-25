//
//  Sales_data.h
//
//  Created by Tang Chengming on 2021/9/8.
//
//  @Brief  chapter 2 添加数据成员
//          exercise 7.2 添加 combine 以及 isbn 成员
//          exercise 7.6 添加 add, read, print
//          exercise 7.11 添加构造函数
//
//

#ifndef CPP_PRIMER5_SALES_DATA_H
#define CPP_PRIMER5_SALES_DATA_H

#include <string>
#include <iostream>
#include <utility>

struct Sales_data {
    // ------------------------ 构造函数 ------------------------
    Sales_data(std::string bookNo = std::string(), unsigned unit_sold = 0, double price = 0.0)
        : bookNo_(std::move(bookNo)), unit_sold_(unit_sold), revenue_(unit_sold * price) {}

    Sales_data& combine(Sales_data const &);

    std::string isbn() const;

    double avg_price() const;

    std::string bookNo_;

    unsigned unit_sold_ = 0;

    double revenue_ = 0.0;
};

Sales_data add(Sales_data const &lhs, Sales_data const &rhs) {
    Sales_data sum;
    sum.bookNo_ = lhs.bookNo_;
    sum.unit_sold_ = lhs.unit_sold_ + rhs.unit_sold_;
    sum.revenue_ = lhs.revenue_ + rhs.revenue_;
    return sum;
}

std::ostream &print(std::ostream &os, Sales_data const &x) {
    return os << x.bookNo_ << " " << x.unit_sold_ << " " << x.avg_price();
}

std::istream &read(std::istream &is, Sales_data &x) {
    double price = 0.0;
    is >> x.bookNo_ >> x.unit_sold_ >> price;
    x.revenue_ = x.unit_sold_ * price;
    return is;
}

inline
Sales_data& Sales_data::combine(Sales_data const &rhs) {
    unit_sold_ += rhs.unit_sold_;
    revenue_ += rhs.revenue_;
    return *this;
}

inline
std::string Sales_data::isbn() const {
    return bookNo_;
}

inline
double Sales_data::avg_price() const {
    return unit_sold_ > 0 ? revenue_ / unit_sold_ : 0.0;
}

#endif //CPP_PRIMER5_SALES_DATA_H
