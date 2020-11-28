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
    int           a[ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector< int > ivec( begin( a ), end( a ) );
    for ( auto i : ivec )
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}