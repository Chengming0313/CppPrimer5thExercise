#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
#if 0
    if ( str1 != str2 )
    {
        // 输出较大的字符串
        cout << ( str1 < str2 ? str2 : str1 ) << endl;
    }
#endif
    if ( str1.size() != str2.size() )
    {
        // 输出较长的字符串
        cout << ( str1.size() < str2.size() ? str2 : str1 ) << endl;
    }

    return 0;
}