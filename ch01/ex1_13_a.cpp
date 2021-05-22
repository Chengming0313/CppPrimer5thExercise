// for循环重写练习1.9
#include <iostream>

int main()
{
    int sum = 0;
    for (int i = 50; i <= 100; ++i)
    {
        sum += i;
    }
    std::cout << "The sum from 50 to 100 inclusive is " << sum << std::endl;
}