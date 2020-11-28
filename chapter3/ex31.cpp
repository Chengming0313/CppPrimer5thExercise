#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int a[ 10 ];
    for ( int i = 0; i < 10; ++i )
    {
        a[ i ] = i;
    }
    for ( auto i : a )
    {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}