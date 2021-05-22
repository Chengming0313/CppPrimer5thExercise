#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total, item;
    if (std::cin >> item)
    {
        total = item;
        while (std::cin >> item)
        {
            if (item.isbn() == total.isbn())
            {
                total += item;
                continue;
            }
            std::cout << total << std::endl;
            total = item;
        }
        std::cout << total << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "No data" << std::endl;
        return -1;
    }
}