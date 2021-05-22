#include <iostream>

struct Sales_data
{
    std::string bookId;
    unsigned unitsSold = 0;
    double revenue     = 0.0;
};

int main()
{
    Sales_data record;
    double price;
    std::cin >> record.bookId >> record.unitsSold >> price;
    record.revenue = record.unitsSold * price;
    std::cout << record.bookId << " " << record.unitsSold << " " << record.revenue << std::endl;
    return 0;
}