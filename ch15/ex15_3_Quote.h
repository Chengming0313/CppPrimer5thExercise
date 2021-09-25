//
//  ex15_3_Quote.h
//
//  Created by Tang Chengming on 2021/9/10.
//
//  @Brief  15.3 定义 Quote
//          15.11 添加 debug 虚函数
//

#ifndef CPP_PRIMER5_EX15_3_QUOTE_H
#define CPP_PRIMER5_EX15_3_QUOTE_H

#include <string>
#include <iostream>

class Quote {
public:
    Quote() : price_(0.0) {}

    Quote(std::string bookNo, double price) :bookNo_(std::move(bookNo)), price_(price) {}

    virtual double net_price(std::size_t n) const;

    std::string const &isbn() const {
        return bookNo_;
    }

    virtual ~Quote() = default;

    virtual void debug() const {
        std::cout << "isbn: " << bookNo_ << " price: " << price_ << "\n";
    }

private:
    std::string bookNo_;

protected:
    double price_;
};

double Quote::net_price(std::size_t n) const {
    return n * price_;
}

inline double print_total(std::ostream &os, Quote const &item, std::size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << "\n";
    return ret;
}

#endif //CPP_PRIMER5_EX15_3_QUOTE_H
