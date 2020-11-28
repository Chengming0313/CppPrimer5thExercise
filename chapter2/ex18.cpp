#include <iostream>

int main()
{
    int   i = 10, j = 20;
    int * p = &i;
    *p      = 100;
    p       = &j;
    *p      = 200;
    std::cout << i << " " << j << std::endl;

    return 0;
}