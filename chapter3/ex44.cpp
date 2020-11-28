#include <iostream>

using std::cout;
using std::endl;

typedef int ( &type_row )[ 4 ];
typedef int type_int;
typedef int ( *type_int4_p )[ 4 ];
typedef int *type_int_p;

int main()
{
    int ia[ 3 ][ 4 ] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
    /* 范围for循环遍历多维数组 */
    cout << "范围for循环遍历多维数组" << endl;
    for ( type_row row : ia ) /* 这里必须使用引用类型，不能使用指针类型 */
    {
        for ( int col : row )
        {
            cout << col << " ";
        }
        cout << endl;
    }
    /* 下标运算符遍历多维数组 */
    cout << "下标运算符遍历多维数组" << endl;
    for ( type_int i = 0; i < 3; ++i )
    {
        for ( type_int j = 0; j < 4; ++j )
        {
            cout << ia[ i ][ j ] << " ";
        }
        cout << endl;
    }
    /* 指针遍历多维数组 */
    cout << "指针遍历多维数组" << endl;
    for ( type_int4_p p = ia; p != ia + 3; ++p )
    {
        for ( type_int_p q = *p; q != *p + 4; ++q )
        {
            cout << *q << " ";
        }
        cout << endl;
    }
    return 0;
}