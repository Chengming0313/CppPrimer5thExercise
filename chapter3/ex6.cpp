#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1;
    cin >> s1;
    for ( auto &ch : s1 )
    {
        ch = 'X';
    }
    cout << s1 << endl;

    return 0;
}