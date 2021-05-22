// 计算50到100的整数和
#include <iostream>

int main()
{
    int i = 50, sum = 0;
    while (i <= 100)
    {
        sum += i;
        ++i;
    }
    std::cout << "The sum from 50 to 100 is " << sum << std::endl;
    return 0;
}