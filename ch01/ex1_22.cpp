#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item sum_item, item;
    if (std::cin >> item)
    {
        sum_item = item;
        while (std::cin >> item)
        {
            sum_item += item;
        }
    }
    std::cout << sum_item << std::endl;
    return 0;
}