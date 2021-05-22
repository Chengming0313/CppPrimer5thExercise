#ifndef CPP_PRIMER_SALES_DATA_H
#define CPP_PRIMER_SALES_DATA_H

#include <iostream>
#include <string>

struct SalesData {
    // 成员函数
    std::string isbn() const { return _bookNo; }
    SalesData & combine(SalesData const &x);
    double      avgPrice() const;
    // 成员变量
    std::string _bookNo;
    unsigned    _unitSold = 0;
    double      _revenue = 0;
};

SalesData &SalesData::combine(SalesData const &x) {
    _unitSold += x._unitSold;
    _revenue += x._revenue;
    return *this;
}

double SalesData::avgPrice() const {
    if (_unitSold != 0)
        return _revenue / _unitSold;
    else
        return 0;
}

SalesData add(SalesData const &a, SalesData const &b) {
    SalesData data;
    data._bookNo = a._bookNo;
    data._unitSold = a._unitSold + b._unitSold;
    data._revenue = a._revenue + b._revenue;
    return data;
}

std::ostream &print(std::ostream &os, SalesData const &x) {
    return os << x._bookNo << ": " << x._unitSold << ", " << x._revenue << ", " << x.avgPrice();
}

std::istream &read(std::istream &is, SalesData &x) {
    double price;
    is >> x._bookNo >> x._unitSold >> price;
    x._revenue = x._unitSold * price;
    return is;
}

#endif