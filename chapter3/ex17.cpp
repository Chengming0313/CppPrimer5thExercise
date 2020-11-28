#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector< string > svec;
    string           s;
    while ( cin >> s )
    {
        svec.push_back( s );
    }
    for ( auto s : svec )
    {
        for ( auto &c : s )
        {
            c = toupper( c );
        }
        cout << s << endl;
    }

    return 0;
}