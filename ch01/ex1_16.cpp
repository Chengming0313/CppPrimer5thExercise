#include <iostream>

int main()
{
    int sum = 0, x = 0;
    while (std::cin >> x)
    {
        sum += x;
    }
    std::cout << sum << std::endl;
    return 0;
}