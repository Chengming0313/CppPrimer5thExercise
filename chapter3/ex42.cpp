#include <iostream>
#include <iterator>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::vector;

int main()
{
    int           a[ 10 ];
    vector< int > ivec( 10, 1 );

    for ( int i = 0; i < 10; ++i )
    {
        a[ i ] = ivec[ i ];
    }
    for ( auto i : a )
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}