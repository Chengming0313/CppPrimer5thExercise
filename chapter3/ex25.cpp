#include <cctype>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/* 这里空vector有bug */
int main()
{
    vector< unsigned > scores( 11, 0 );

    unsigned grade;
    auto     begin = scores.begin();
    while ( cin >> grade )
    {
        if ( grade <= 100 )
        {
            ++*( begin + grade / 10 );
        }
    }

    for ( auto cnt : scores )
    {
        cout << cnt << " ";
    }
    cout << endl;

    return 0;
}