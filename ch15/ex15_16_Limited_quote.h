//
//  ex15_16_Limited_quote.h
//
//  Created by Tang Chengming on 2021/9/11.
//
//  @Brief  
//

#ifndef CPP_PRIMER5_EX15_16_LIMITED_QUOTE_H
#define CPP_PRIMER5_EX15_16_LIMITED_QUOTE_H

#include "ex15_15_Disc_quote.h"

class Limited_quote : public Disc_quote {
public:
    Limited_quote() = default;

    Limited_quote(std::string bookNo, double price, int maxNum, double discount)
        : Disc_quote(std::move(bookNo), price, maxNum, discount) {}

    double net_price(std::size_t n) const override {
        if (n > num_) {
            return num_ * price_ * discount_ + (n - num_) * price_;
        }
        return n * price_ * discount_;
    }
};

#endif //CPP_PRIMER5_EX15_16_LIMITED_QUOTE_H
