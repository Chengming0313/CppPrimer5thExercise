#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>

struct Sales_data
{
    std::string bookId;
    unsigned unitsSold;
    double price;
};
#endif