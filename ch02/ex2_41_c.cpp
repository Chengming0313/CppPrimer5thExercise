#include <iostream>

struct Sales_data
{
    std::string bookId;
    unsigned unitsSold;
    double revenue;
};

int main()
{
    Sales_data total;
    double price;
    if (std::cin >> total.bookId >> total.unitsSold >> price)
    {
        Sales_data record;
        total.revenue = total.unitsSold * price;
        while (std::cin >> record.bookId >> record.unitsSold >> price)
        {
            record.revenue = record.unitsSold * price;
            if (record.bookId == total.bookId)
            {
                total.unitsSold += record.unitsSold;
                total.revenue += total.revenue;
            }
            else
            {
                std::cout << total.bookId << " " << total.unitsSold << " " << total.revenue
                          << std::endl;
                total.bookId    = record.bookId;
                total.unitsSold = record.unitsSold;
                total.revenue   = record.revenue;
            }
        }
        std::cout << total.bookId << " " << total.unitsSold << " " << total.revenue << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "No data?" << std::endl;
        return -1;
    }
}