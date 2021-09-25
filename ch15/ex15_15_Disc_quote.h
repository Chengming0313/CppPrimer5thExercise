//
//  ex15_15_Disc_quote.h
//
//  Created by Tang Chengming on 2021/9/11.
//
//  @Brief  
//

#ifndef CPP_PRIMER5_EX15_15_DISC_QUOTE_H
#define CPP_PRIMER5_EX15_15_DISC_QUOTE_H

#include <utility>

#include "ex15_3_Quote.h"

class Disc_quote : public Quote{
public:
    Disc_quote() : num_(0), discount_(0.0) {}

    Disc_quote(std::string bookNo, double price, std::size_t n, double discount)
        : Quote(std::move(bookNo), price), num_(n), discount_(discount) {}

    double net_price(std::size_t n) const override = 0;

    ~Disc_quote() override = default;

protected:
    std::size_t num_;
    double discount_;
};

#endif //CPP_PRIMER5_EX15_15_DISC_QUOTE_H
