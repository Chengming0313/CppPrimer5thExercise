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
        cout << s << endl;
    }

    return 0;
}