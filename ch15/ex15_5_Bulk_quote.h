//
//  ex15_5_Bulk_quote.h
//
//  Created by Tang Chengming on 2021/9/10.
//
//  @Brief  
//

#ifndef CPP_PRIMER5_EX15_5_BULK_QUOTE_H
#define CPP_PRIMER5_EX15_5_BULK_QUOTE_H

#include "ex15_3_Quote.h"

class Bulk_quote : public Quote {
public:
    Bulk_quote() : min_qty_(0), discount_(1.0) {}

    Bulk_quote(std::string bookNo, double price, std::size_t qty, double discount)
            : Quote(std::move(bookNo), price), min_qty_(qty), discount_(discount) {}

    double net_price(std::size_t n) const override{
        if (n >= min_qty_) {
            return n * price_ * discount_;
        }
        return n * price_;
    }

private:
    std::size_t min_qty_;
    double discount_;
};

#endif //CPP_PRIMER5_EX15_5_BULK_QUOTE_H
