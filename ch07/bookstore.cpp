#include "SalesData.h"

#include <iostream>
#include <string>

int main() {
    SalesData total;
    if (read(std::cin, total)) {
        SalesData trans;
        while (read(std::cin, trans)) {
            if (total._bookNo == trans._bookNo) {
                total.combine(trans);
            }
            else {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    }
    else {
        std::cout << "No data!" << std::endl;
    }
    return 0;
}