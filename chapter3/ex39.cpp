#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s1 = "hello", s2 = "heyl";
    char   cs1[] = "hello", cs2[] = "heyl";
    /* 比较string */
    if ( s1 == s2 )
    {
        cout << "s1 = s2" << endl;
    }
    else if ( s1 < s2 )
    {
        cout << "s1 < s2" << endl;
    }
    else
    {
        cout << "s1 > s2" << endl;
    }
    /* 比较c风格字符串 */
    int flag = strcmp( cs1, cs2 );
    if ( flag == 0 )
    {
        cout << "cs1 = cs2" << endl;
    }
    else if ( flag < 0 )
    {
        cout << "cs1 < cs2" << endl;
    }
    else
    {
        cout << "cs1 > cs2" << endl;
    }

    return 0;
}