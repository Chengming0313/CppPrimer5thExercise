#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector< int > ivec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for ( auto begin = ivec.begin(); begin != ivec.end(); ++begin )
    {
        ( *begin ) *= 2;
    }
    cout << "size : " << ivec.size() << " [";
    for ( auto begin = ivec.cbegin(); begin != ivec.cend(); ++begin )
    {
        cout << *begin << ( begin == ivec.cend() - 1 ? "]" : ", " );
    }
    cout << endl;
    return 0;
}