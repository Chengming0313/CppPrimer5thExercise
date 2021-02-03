#include <iostream>

int main()
{

    int money = 10;
    int a     = 0;
    int b     = 0;
    int cnt   = 0;

    while ( money >= 2 || a >= 2 || b >= 4 )
    {
        if ( money >= 2 )
        {
            cnt += money / 2;
            a += money / 2;
            b += money / 2;
            money %= 2;
        }
        if ( a >= 2 )
        {
            cnt += a / 2;
            int temp = a % 2;
            b += a / 2;
            a = temp + a / 2;
        }
        if ( b >= 4 )
        {
            cnt += b / 4;
            int temp = b % 4;
            a += b / 4;
            b = temp + b / 4;
        }
    }

    std::cout << cnt;

    return 0;
}