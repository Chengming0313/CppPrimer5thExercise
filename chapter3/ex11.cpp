#include <iostream>
#include <string>

using namespace std;

int main()
{
    const string s = "keep out!";
    /* ch的类型是const char &，看是不是要改变ch的值，例如给ch赋值就会报错 */
    /* error: assignment of read-only reference 'ch' */
    for ( auto &ch : s )
    {
        // ch = 'X';
    }
    return 0;
}