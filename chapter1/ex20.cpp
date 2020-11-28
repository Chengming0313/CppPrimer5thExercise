#include "Sales_item.h"
#include <iostream>

/* Get-Content ./data/book_sales | ./ex20 */
int main()
{
    Sales_item item;
    while ( std::cin >> item )
    {
        std::cout << item << std::endl;
    }
    return 0;
}