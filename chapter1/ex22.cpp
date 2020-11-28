#include "Sales_item.h"
#include <iostream>

/* 读取多个具有相同ISBN的销售记录，输出所有记录的和 */
/* Get-Content ./data/book_sales | ./ex22 */
int main()
{
    /* currItem保存正在统计的记录，item保存下一次应该读入的记录，sumItem保存ISBN相同的记录的和 */
    Sales_item currItem, item, sumItem;
    /* 读取第一个数，并确保确实有数据可以处理 */
    if ( std::cin >> currItem )
    {
        sumItem = currItem;        /* 初始化sumItem位currItem */
        while ( std::cin >> item ) /* 读取剩余的记录 */
        {
            if ( item.isbn() == currItem.isbn() ) /* 判断下一个记录的ISBN是否与当前的记录相同 */
            {
                sumItem += item;
            }
            else /* 否则打印sumItem */
            {
                std::cout << sumItem << std::endl;
                currItem = item;     /* 记住新值 */
                sumItem  = currItem; /* 重置sumItem */
            }
        }
        /* 打印最后一个sumItem */
        std::cout << sumItem << std::endl;
    }
    return 0;
}