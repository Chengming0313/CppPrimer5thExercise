#include <cstring>
#include <iostream>

const char cstr1[] = "Hello";
const char cstr2[] = "world!";

int main()
{

    /* 这里使用strlen函数给constexpr变量赋值，必须保证实参是const变量并且实参是全局变量 */
    constexpr size_t new_size = strlen( cstr1 ) + strlen( " " ) + strlen( cstr2 ) + 1;
    char             cstr3[ new_size ];

    strcpy( cstr3, cstr1 );
    strcat( cstr3, " " );
    strcat( cstr3, cstr2 );

    std::cout << cstr3 << std::endl;

    return 0;
}