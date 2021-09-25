//
//  ex15_Bulk_quote.h
//
//  Created by Tang Chengming on 2021/9/11.
//
//  @Brief  
//

#ifndef CPP_PRIMER5_EX15_BULK_QUOTE_H
#define CPP_PRIMER5_EX15_BULK_QUOTE_H

#include "ex15_15_Disc_quote.h"

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;

    Bulk_quote(std::string bookNo, double price, std::size_t num, double discount)
        : Disc_quote(std::move(bookNo), price, num, discount) {}

    double net_price(std::size_t n) const override {
        if (n >= num_) {
            return n * price_ * discount_;
        }
        return n * price_;
    }
};

#endif //CPP_PRIMER5_EX15_BULK_QUOTE_H
