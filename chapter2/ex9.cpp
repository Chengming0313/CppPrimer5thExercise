#include <iostream>

int main()
{
    /* expected primary-expression before 'int' */
    // std::cin >> int input_value;

    /* narrowing conversion of '3.1400000000000001e+0' from 'double' to 'int' [-Wnarrowing] */
    // int    i      = { 3.14 };

    /* 'wage' was not declared in this scope */
    // double salary = wage = 9999.99;

    int j = 3.14;

    return 0;
}