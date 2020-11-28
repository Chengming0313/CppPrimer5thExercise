#include "Sales_item.h"
#include <iostream>

/*
 * 读取多个具有相同ISBN的销售记录，输出所有记录的和
 * 这是书上的实现，注意跟自己实现的ex22.cpp进行对比
 * 重定向标准输入：Get-Content ./data/book_sales | ./ex25
 * 测试没有输入：Get-Content ./data/no_data | ./ex25
 */
int main()
{
    Sales_item total;
    /* 读取第一个数，并确保确实有数据可以处理 */
    if ( std::cin >> total )
    {
        Sales_item trans;
        while ( std::cin >> trans ) /* 读取剩余的记录 */
        {
            if ( total.isbn() == trans.isbn() ) /* 判断下一个记录的ISBN是否与当前的记录相同 */
            {
                total += trans;
            }
            else /* 否则打印total */
            {
                std::cout << total << std::endl;
                total = trans; /* 记住新值 */
            }
        }
        /* 打印最后一个total */
        std::cout << total << std::endl;
    }
    else
    {
        std::cerr << "No data!" << std::endl;
        return -1;
    }

    return 0;
}