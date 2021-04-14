#include <iostream>

struct Sales_data
{
    std::string bookId;
    unsigned unitsSold = 0;
    double revenue     = 0.0;
};

int main()
{
    Sales_data record1, record2;
    double price1, price2;
    std::cin >> record1.bookId >> record1.unitsSold >> price1;
    std::cin >> record2.bookId >> record2.unitsSold >> price2;
    record1.revenue = record1.unitsSold * price1;
    record2.revenue = record2.unitsSold * price2;

    if (record1.bookId == record2.bookId)
    {
        Sales_data record;
        record.bookId    = record1.bookId;
        record.revenue   = record1.revenue + record2.revenue;
        record.unitsSold = record1.unitsSold + record2.unitsSold;
        std::cout << record.bookId << " " << record.unitsSold << " " << record.revenue << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "Data must refer to same ISBN" << std::endl;
        return -1;
    }
}