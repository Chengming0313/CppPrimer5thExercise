#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string sa[ 10 ];
int    ia[ 10 ];
int    main()
{
    string sa2[ 10 ];
    int    ia2[ 10 ];

    cout << "sa: ";
    for ( auto s : sa )
    {
        cout << s << " ";
    }
    cout << endl;

    cout << "ia: ";
    for ( auto i : ia )
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "sa2: ";
    for ( auto s : sa2 )
    {
        cout << s << " ";
    }
    cout << endl;

    cout << "ia2: ";
    for ( auto i : ia2 )
    {
        cout << i << " ";
    }
    cout << endl;

    unsigned scores[ 11 ] = { 1 };
    for ( auto i : scores )
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}