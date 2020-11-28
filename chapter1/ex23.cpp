#include "Sales_item.h"
#include <iostream>

/* 读取多个具有相同ISBN的销售记录，统计每本书(ISBN)有几条销售记录 */
/* Get-Content ./data/book_sales | ./ex23 */
int main()
{
    /* currItem保存正在统计的记录，item保存下一次应该读入的记录 */
    Sales_item currItem, item;
    int        cnt = 0; /* 计数器 */
    /* 读取第一个数，并确保确实有数据可以处理 */
    if ( std::cin >> currItem )
    {
        cnt = 1;                   /* 初始化sumItem位currItem */
        while ( std::cin >> item ) /* 读取剩余的记录 */
        {
            if ( item.isbn() == currItem.isbn() ) /* 判断下一个记录的ISBN是否与当前的记录相同 */
            {
                ++cnt;
            }
            else /* 否则打印sumItem */
            {
                std::cout << currItem.isbn() << " " << cnt << std::endl;
                currItem = item; /* 记住新值 */
                cnt      = 1;    /* 重置计数器 */
            }
        }
        /* 打印最后一个sumItem */
        std::cout << currItem.isbn() << " " << cnt << std::endl;
    }

    return 0;
}