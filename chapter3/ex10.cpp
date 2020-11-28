#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, res;
    cin >> s1;

    for ( auto ch : s1 )
    {
        if ( !ispunct( ch ) )
        {
            res += ch;
        }
    }
    cout << res << endl;

    return 0;
}