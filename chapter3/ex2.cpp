#include <iostream>
#include <string>

using namespace std;

int main()
{

    string str1;
    /* 一次读入一行 */
    // getline( cin, str1 );
    /* 一次读入一个词 */
    cin >> str1;
    cout << "str1: " << str1 << endl;

    return 0;
}