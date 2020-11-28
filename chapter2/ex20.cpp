#include <iostream>

/* i = i * i */
int main()
{
    int   i  = 42;
    int * p1 = &i; /* 除了decltype，其它地方的引用都是指的它引用的对象 */
    *p1      = *p1 * *p1;

    std::cout << "i: " << i << std::endl;

    return 0;
}