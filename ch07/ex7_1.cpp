#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo;
    std::string bookName;
    unsigned    units_sold;
    double      revenue;
};

int main() {
    Sales_data total;
    if (std::cin >> total.bookNo >> total.units_sold >> total.revenue) {
        Sales_data trans;
        while (std::cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }
            else {
                std::cout << total.bookNo << " " << total.units_sold << " "
                          << total.revenue / total.units_sold << '\n';
                total = trans;
            }
        }
        std::cout << total.bookNo << " " << total.units_sold << " "
                  << total.revenue / total.units_sold << '\n';
    }
    else {
        std::cerr << "No data!\n";
    }
    return 0;
}