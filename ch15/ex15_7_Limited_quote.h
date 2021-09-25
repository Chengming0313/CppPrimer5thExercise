//
//  ex15_7_Limited_quote.h
//
//  Created by Tang Chengming on 2021/9/10.
//
//  @Brief  
//

#ifndef CPP_PRIMER5_EX15_7_LIMITED_QUOTE_H
#define CPP_PRIMER5_EX15_7_LIMITED_QUOTE_H

#include "ex15_3_Quote.h"

class Limited_quote : public Quote {
public:
    Limited_quote() : limited_num_(0), discount_(1.0) {}

    Limited_quote(std::string bookNo, double price, std::size_t limited_num, double discount)
        : Quote(bookNo, price), limited_num_(limited_num), discount_(discount) {}

    double net_price(std::size_t n) const override{
        if (n <= limited_num_) {
            return n * price_ * discount_;
        }
        return limited_num_ * price_ * discount_ + (n - limited_num_) * price_;
    }
private:
    std::size_t limited_num_;
    double discount_;
};

#endif //CPP_PRIMER5_EX15_7_LIMITED_QUOTE_H
