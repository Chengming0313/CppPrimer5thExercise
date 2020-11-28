#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int ia[ 3 ][ 4 ] = {};
    /* 这里p的类型是 int (*p)[4] */
    for ( auto p = ia; p != ia + 3; ++p )
    {
        /* q的类型是int *q */
        for ( auto q = *p; q != *p + 4; ++q )
        {
            cout << *q << " ";
        }
        cout << endl;
    }
    cout << "--------------------" << endl;
    for ( const auto &row : ia )
    {
        for ( auto col : row )
        {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}