//
//  ex14_2_Sales_data.h
//
//  Created by Tang Chengming on 2021/9/4.
//
//  @Brief  exercise 14.2 添加输入、输出、加法、复合赋值运算符。
//          exercise 14.6 重新编写重载的输出运算符
//          exercise 14.9 重新编写重载的输入运算符
//          exercise 14.13 添加减法运算符与对应的复合赋值运算符
//          exercise 14.20 为它定义加法和复合赋值运算符
//          exercise 14.22 为它添加一个赋值运算符，把 isbn 赋给它
//          exercise 14.45 add operator double and operator string
//

#ifndef CPP_PRIMER5_EX14_2_SALES_DATA_H
#define CPP_PRIMER5_EX14_2_SALES_DATA_H

#include <string>
#include <iostream>

using namespace std;

class Sales_data {
    friend istream &operator>>(istream &is, Sales_data &);

    friend ostream &operator<<(ostream &os, Sales_data const &);

    friend Sales_data operator+(Sales_data const &, Sales_data const &);

    friend Sales_data operator-(Sales_data const &, Sales_data const &);

public:
    // ------------------- other -------------------

    explicit Sales_data(string bookNo = string(), unsigned units_sold = 0, double revenue = 0.0)
            : bookNo(std::move(bookNo)), units_sold(units_sold), revenue(revenue) {}

    double avg_price() const {
        return units_sold ? revenue / units_sold : 0;
    }

    // ------------------- end other

    Sales_data &operator+=(Sales_data const &);

    Sales_data &operator-=(Sales_data const &);

    Sales_data &operator=(std::string const &);

    explicit operator double() const {return avg_price();}

    explicit operator string() const {return bookNo;}

private:
    string bookNo;
    unsigned units_sold;
    double revenue;
};

Sales_data &Sales_data::operator+=(Sales_data const &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data &Sales_data::operator-=(Sales_data const &rhs) {
    units_sold -= rhs.units_sold;
    revenue -= rhs.revenue;
    return *this;
}

Sales_data &Sales_data::operator=(std::string const &isbn) {
    this->bookNo = isbn;
}

istream &operator>>(istream &is, Sales_data &rhs) {
    double price;
    is >> rhs.bookNo >> rhs.units_sold >> price;
    if (is) {
        rhs.revenue = price * rhs.units_sold;
    } else {
        rhs = Sales_data(); // 输入错误时，输入对象被赋予默认的状态
    }
    return is >> rhs.bookNo >> rhs.units_sold >> rhs.revenue;
}

ostream &operator<<(ostream &os, Sales_data const &rhs) {
    return os << rhs.bookNo << " " << rhs.units_sold << " "
              << rhs.revenue << " " << rhs.avg_price();
}

Sales_data operator+(Sales_data const &lhs, Sales_data const &rhs) {
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

Sales_data operator-(Sales_data const &lhs, Sales_data const &rhs) {
    Sales_data difference = lhs;
    difference -= rhs;
    return difference;
}

#endif //CPP_PRIMER5_EX14_2_SALES_DATA_H
