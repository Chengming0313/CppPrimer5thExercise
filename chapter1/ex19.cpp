#include <iostream>

int main()
{
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    int i = 0, j = 0;
    if ( v1 <= v2 )
    {
        i = v1;
        j = v2;
    }
    else
    {
        i = v2;
        j = v1;
    }
    for ( ; i <= j; ++i )
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}